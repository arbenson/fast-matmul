#ifndef _LINALG_HPP_
#define _LINALG_HPP_

#include <assert.h>

#include <cmath>
#include <iostream>

extern "C" {
  void dgemm_(char *transa, char *transb, int *m, int *n, int *k,
			  double *alpha, double *a, int *lda, double *b, int *ldb,
			  double *beta, double *c, int *ldc);
  void sgemm_(char *transa, char *transb, int *m, int *n, int *k,
			  float *alpha, float *a, int *lda, float *b, int *ldb,
			  float *beta, float *c, int *ldc);

  void daxpy_(int *n, double *alpha, double *A, int *incx, double *C, int *incy);
  void saxpy_(int *n, float *alpha, float *A, int *incx, float *C, int *incy);
}

// This is a basic templated matrix class.
// It stores the matrix data, the stride, and the dimensions.
// The variable is_view indicates whether or not the data is owned
// by this instance.
template <typename Scalar>
class Matrix {
public:
  // Copy constructor
  Matrix(Matrix<Scalar>& that) {
	m_ = that.m();
	n_ = that.n();
	stride_ = that.stride();
	multiplier_ = that.Multiplier();
	allocate();
	Scalar *that_data = that.data();
	for (int i = 0; i < m_ * n_; ++i) {
	  data_[i] = that_data[i];
	}
  }


  // Move constructor
  Matrix(Matrix<Scalar>&& that) : Matrix() {
	swap(*this, that);
  }


  // copy assignment
  Matrix<Scalar>& operator=(Matrix<Scalar> that) {
	swap(*this, that);
	return *this;
  }

  friend void swap(Matrix<Scalar>& first, Matrix<Scalar>& second) {
	std::swap(first.m_, second.m_);
	std::swap(first.n_, second.n_);
	std::swap(first.stride_, second.stride_);
	std::swap(first.is_view_, second.is_view_);
	std::swap(first.data_, second.data_);
	std::swap(first.multiplier_, second.multiplier_);
  }


  Matrix(Scalar *data, int stride, int m, int n, Scalar multiplier=Scalar(1)):
	data_(data), stride_(stride), m_(m), n_(n), is_view_(true), multiplier_(multiplier) {
	assert(stride > m);
  }


  Matrix(int n) : m_(n), n_(n), stride_(n), is_view_(false), multiplier_(Scalar(1)) {
	allocate();
  }


  Matrix(int m, int n) : m_(m), n_(n), stride_(m), is_view_(false), multiplier_(Scalar(1)) {
	allocate();
  }


  Matrix(int m, int n, Scalar multiplier) : m_(m), n_(n), stride_(m), is_view_(false), multiplier_(multiplier) {
	allocate();
  }


  // Get a view of a subblock of the matrix.
  // num_block_rows and num_block_cols are the number of block rows and columns
  // row_ind and col_ind are the indices (1-indexed) of the block
  Matrix<Scalar> Subblock(int num_block_rows, int num_block_cols, int row_ind, int col_ind) {
	std::pair<int, int> row_data = IndexData(m_, num_block_rows, row_ind);
	std::pair<int, int> col_data = IndexData(n_, num_block_cols, col_ind);
	return Submatrix(row_data.first, col_data.first, row_data.second, col_data.second);
  }


  Matrix<Scalar> Submatrix(int start_row, int start_col, int num_rows, int num_cols) {
	return Matrix<Scalar>(data(start_row, start_col), stride_, num_rows, num_cols, multiplier_);
  }


  ~Matrix() {
	if (data_ != NULL && !is_view_) {
	  deallocate();
	}
  }

  Scalar *data() { return data_; }
  Scalar *data(int i, int j) { return data_ + i + j * stride_; }
  int stride() { return stride_; }
  int m() { return m_; }
  int n() { return n_; }

  void allocate() {
	data_ = new Scalar[m_ * n_];
	assert(data_ != NULL);
  }

  void deallocate() {
	if (data_ != NULL) {
	  delete data_;
	  data_ = NULL;
	}
  }

  void UpdateMultiplier(Scalar multiplier) { multiplier_ *= multiplier; }
  Scalar multiplier() { return multiplier_; }

private:
  // Return pair of (starting index, number of indices)
  std::pair<int, int> IndexData(int total, int num_block, int ind) {
  	int step = total / num_block;
	// Determine starting index
	int start = step * (ind - 1);

	return std::pair<int, int>(start, step);
  }

  Scalar *data_;
  int stride_;
  int m_;
  int n_;
  bool is_view_;
  Scalar multiplier_;
};


template<typename Scalar>
void DynamicPeeling(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
					int dim1, int dim2, int dim3) {
  assert(A.m() == C.m() && A.n() == B.m() && B.n() == C.n());
  assert(A.m() > 0 && A.n() > 0);
  int extra_rows_A = A.m() - (A.m() / dim1) * dim1;
  int extra_cols_A = A.n() - (A.n() / dim2) * dim2;
  int extra_rows_B = B.m() - (B.m() / dim2) * dim2;
  int extra_cols_B = B.n() - (B.n() / dim3) * dim3;
  assert(extra_cols_A == extra_rows_B);

  // Adjust part handled by fast matrix multiplication.
  // Add far column of A outer product bottom row B
  if (extra_cols_A > 0) {
	// In Strassen, this looks like C([1, 2], [1, 2]) += A([1, 2], 3) * B(3, [1, 2])
	int row_dim = A.m() - extra_rows_A;
	int col_dim = B.n() - extra_cols_B;
	int inner_dim_start = A.n() - extra_cols_A;
	Matrix<Scalar> A_extra = A.Submatrix(0, inner_dim_start, row_dim, extra_cols_A);
	Matrix<Scalar> B_extra = B.Submatrix(inner_dim_start, 0, extra_rows_B, col_dim);
	Matrix<Scalar> C_extra = C.Submatrix(0, 0, row_dim, col_dim);
	Gemm(A_extra, B_extra, C_extra, Scalar(1.0));
  }

  // Adjust for far right columns of C
  if (extra_cols_B > 0) {
	// In Strassen, this looks like C(:, 3) = A * B(:, 3)
	int start_ind = B.n() - extra_cols_B;
	Matrix<Scalar> B_extra = B.Submatrix(0, start_ind, B.m(), extra_cols_B);
	Matrix<Scalar> C_extra = C.Submatrix(0, start_ind, C.m(), extra_cols_B);
	Gemm(A, B_extra, C_extra);
  }

  // Adjust for bottom rows of C
  if (extra_rows_A > 0) {
	// In Strassen, this looks like C(3, [1, 2]) = A(3, :) * B(:, [1, 2])
	int start_ind = A.m() - extra_rows_A;
	int num_cols = B.n() - extra_cols_B;
	Matrix<Scalar> A_extra = A.Submatrix(start_ind, 0, extra_rows_A, A.n());
	Matrix<Scalar> B_extra = B.Submatrix(0, 0, B.m(), num_cols);
	Matrix<Scalar> C_extra = C.Submatrix(start_ind, 0, extra_rows_A, num_cols);
	Gemm(A_extra, B_extra, C_extra);
  }
}

template <typename Scalar>
std::ostream& operator<<(std::ostream& os, Matrix<Scalar>& mat) {
  Scalar *data = mat.data();
  int stride = mat.stride();
  for (int i = 0; i < mat.m(); ++i) {
	for (int j = 0; j < mat.n(); ++j) {
	  os << data[i + j * stride] << " ";
	}
	os << std::endl;
  }
  return os;
}

// Wrapper for dgemm called by templated gemm.
void GemmWrap(int m, int n, int k, double *A, int lda, double *B, int ldb, double *C,
			  int ldc, double beta) {
  char transa = 'n';
  char transb = 'n';
  double alpha = 1;
  dgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
		 C, &ldc);
}

// Wrapper for sgemm called by templated gemm.
void GemmWrap(int m, int n, int k, float *A, int lda, float *B, int ldb,
			  float *C, int ldc, float beta) {
  char transa = 'n';
  char transb = 'n';
  float alpha = 1;
  sgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
		 C, &ldc);
}

// C <-- A * B + beta * C
template <typename Scalar>
void Gemm(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, Scalar beta=Scalar(0.0)) {
  assert(A.m() == C.m() && A.n() == B.m() && B.n() == C.n());
  assert(A.m() > 0 && A.n() > 0);
  GemmWrap(A.m(), B.n(), A.n(), A.data(), A.stride(), B.data(), B.stride(),
		   C.data(), C.stride(), beta);
}

// max_ij |a_ij - b_ij| / |a_ij|
template<typename Scalar>
double MaxRelativeDiff(Matrix<Scalar>& A, Matrix<Scalar>& B) {
  assert(A.m() == B.m() && A.n() == B.n());
  const int strideA = A.stride();
  const int strideB = B.stride();
  const Scalar *dataA = A.data();
  const Scalar *dataB = B.data();
  double max_rel_diff = 0;
  for (int j = 0; j < A.n(); ++j) {
	for (int i = 0; i < A.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  Scalar b = dataB[i + j * strideB];
	  Scalar curr_rel_diff = std::abs(a - b) / std::abs(a);
	  if (curr_rel_diff > max_rel_diff) {
		max_rel_diff = curr_rel_diff;
	  }
	}
  }
  return max_rel_diff;
}

// Frobenius norm difference: \| A - B \|_F
template<typename Scalar>
double FrobeniusDiff(Matrix<Scalar>& A, Matrix<Scalar>& B) {
  assert(A.m() == B.m() && A.n() == B.n());
  double diff = 0.0;
  const int strideA = A.stride();
  const int strideB = B.stride();
  const Scalar *dataA = A.data();
  const Scalar *dataB = B.data();
  for (int j = 0; j < A.n(); ++j) {
	for (int i = 0; i < A.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  Scalar b = dataB[i + j * strideB];
	  Scalar local_diff = (a - b);
	  diff += local_diff * local_diff;
	}
  }
  return sqrt(diff);
}

// Frobenius norm \| A \|_F
template<typename Scalar>
double FrobeniusNorm(Matrix<Scalar>& A) {
  double norm = 0.0;
  const int strideA = A.stride();
  const Scalar *dataA = A.data();
  for (int j = 0; j < A.n(); ++j) {
	for (int i = 0; i < A.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  norm += a * a;
	}
  }
  return sqrt(norm);
}


// C <-- -A
template<typename Scalar>
void Negate(Matrix<Scalar>& A, Matrix<Scalar>& C) {
  assert(A.m() == C.m() && A.n() == C.n());
  const int strideA = A.stride();
  const int strideC = C.stride();
  const Scalar *dataA = A.data();
  Scalar *dataC = C.data();
#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  dataC[i + j * strideC] = -a;
	}
  }
}

// C <-- alpha1 * A
template<typename Scalar>
void Add(Matrix<Scalar>& A1, Scalar alpha1, Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A1.n() == C.n());
  const int strideA1 = A1.stride();
  const int strideC = C.stride();
  const Scalar *dataA1 = A1.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = dataA1[i + j * strideA1];
	  dataC[i + j * strideC] = alpha1 * a1;
	}
  }
}

// C <-- alpha1 * A1 + alpha2 * A2
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Scalar alpha1, Scalar alpha2,
         Matrix<Scalar> &C) {
  assert(A1.m() == A2.m() && A2.m() == C.m() &&
		 A1.n() == A2.n() && A2.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  dataC[i + j * strideC] = a1 + a2;
	}
  }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Matrix<Scalar>& C) {
  assert(A1.m() == A2.m() && A2.m() == A3.m() && A3.m() == C.m() &&
		 A1.n() == A2.n() && A2.n() == A3.n() && A3.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  dataC[i + j * strideC] = a1 + a2 + a3;
	}
  }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Matrix<Scalar>& C) {
  assert(A1.m() == A2.m() && A2.m() == A3.m() && A3.m() == C.m() && A4.m() == C.m() &&
		 A1.n() == A2.n() && A2.n() == A3.n() && A3.n() == C.n() && A4.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4;
	}
  }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5;
	}
  }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
//     + alpha11 * A11
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10, Matrix<Scalar>& A11,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10, Scalar alpha11,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() && A11.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n() && A11.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideA11 = A11.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  const Scalar *dataA11 = A11.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  Scalar a11 = alpha11 * dataA11[i + j * strideA11];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
//     + alpha11 * A11 + alpha12 * A12
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10, Scalar alpha11, Scalar alpha12,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() && A11.m() == C.m() && A12.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n() && A11.n() == C.n() && A12.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideA11 = A11.stride();
  const int strideA12 = A12.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  const Scalar *dataA11 = A11.data();
  const Scalar *dataA12 = A12.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  Scalar a11 = alpha11 * dataA11[i + j * strideA11];
	  Scalar a12 = alpha12 * dataA12[i + j * strideA12];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
//     + alpha11 * A11 + alpha12 * A12 + alpha13 * A13
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
		 Matrix<Scalar>& A13,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10, Scalar alpha11, Scalar alpha12,
		 Scalar alpha13,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() && A11.m() == C.m() && A12.m() == C.m() &&
		 A13.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n() && A11.n() == C.n() && A12.n() == C.n() &&
		 A13.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideA11 = A11.stride();
  const int strideA12 = A12.stride();
  const int strideA13 = A13.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  const Scalar *dataA11 = A11.data();
  const Scalar *dataA12 = A12.data();
  const Scalar *dataA13 = A13.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  Scalar a11 = alpha11 * dataA11[i + j * strideA11];
	  Scalar a12 = alpha12 * dataA12[i + j * strideA12];
	  Scalar a13 = alpha13 * dataA13[i + j * strideA13];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
//     + alpha11 * A11 + alpha12 * A12 + alpha13 * A13 + alpha14 * A14
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
		 Matrix<Scalar>& A13, Matrix<Scalar>& A14,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10, Scalar alpha11, Scalar alpha12,
		 Scalar alpha13, Scalar alpha14,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() && A11.m() == C.m() && A12.m() == C.m() &&
		 A13.m() == C.m() && A14.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n() && A11.n() == C.n() && A12.n() == C.n() &&
		 A13.n() == C.n() && A14.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideA11 = A11.stride();
  const int strideA12 = A12.stride();
  const int strideA13 = A13.stride();
  const int strideA14 = A14.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  const Scalar *dataA11 = A11.data();
  const Scalar *dataA12 = A12.data();
  const Scalar *dataA13 = A13.data();
  const Scalar *dataA14 = A14.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  Scalar a11 = alpha11 * dataA11[i + j * strideA11];
	  Scalar a12 = alpha12 * dataA12[i + j * strideA12];
	  Scalar a13 = alpha13 * dataA13[i + j * strideA13];
	  Scalar a14 = alpha14 * dataA14[i + j * strideA14];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14;
	}
  }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4 + alpha5 * A5
//     + alpha6 * A6 + alpha7 * A7 + alpha8 * A8 + alpha9 * A9 + alpha10 * A10
//     + alpha11 * A11 + alpha12 * A12 + alpha13 * A13 + alpha14 * A14 + alpha15 * A15
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
		 Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
		 Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
		 Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
		 Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
		 Scalar alpha4, Scalar alpha5, Scalar alpha6,
		 Scalar alpha7, Scalar alpha8, Scalar alpha9,
		 Scalar alpha10, Scalar alpha11, Scalar alpha12,
		 Scalar alpha13, Scalar alpha14, Scalar alpha15,
		 Matrix<Scalar>& C) {
  assert(A1.m() == C.m() && A2.m() == C.m() && A3.m() == C.m() &&
		 A4.m() == C.m() && A5.m() == C.m() && A6.m() == C.m() &&
		 A7.m() == C.m() && A8.m() == C.m() && A9.m() == C.m() &&
		 A10.m() == C.m() && A11.m() == C.m() && A12.m() == C.m() &&
		 A13.m() == C.m() && A14.m() == C.m() && A15.m() == C.m() &&
		 A1.n() == C.n() && A2.n() == C.n() && A3.n() == C.n() &&
		 A4.n() == C.n() && A5.n() == C.n() && A6.n() == C.n() &&
		 A7.n() == C.n() && A8.n() == C.n() && A9.n() == C.n() &&
		 A10.n() == C.n() && A11.n() == C.n() && A12.n() == C.n() &&
		 A13.n() == C.n() && A14.n() == C.n() && A15.n() == C.n());

  const int strideA1 = A1.stride();
  const int strideA2 = A2.stride();
  const int strideA3 = A3.stride();
  const int strideA4 = A4.stride();
  const int strideA5 = A5.stride();
  const int strideA6 = A6.stride();
  const int strideA7 = A7.stride();
  const int strideA8 = A8.stride();
  const int strideA9 = A9.stride();
  const int strideA10 = A10.stride();
  const int strideA11 = A11.stride();
  const int strideA12 = A12.stride();
  const int strideA13 = A13.stride();
  const int strideA14 = A14.stride();
  const int strideA15 = A15.stride();
  const int strideC = C.stride();

  const Scalar *dataA1 = A1.data();
  const Scalar *dataA2 = A2.data();
  const Scalar *dataA3 = A3.data();
  const Scalar *dataA4 = A4.data();
  const Scalar *dataA5 = A5.data();
  const Scalar *dataA6 = A6.data();
  const Scalar *dataA7 = A7.data();
  const Scalar *dataA8 = A8.data();
  const Scalar *dataA9 = A9.data();
  const Scalar *dataA10 = A10.data();
  const Scalar *dataA11 = A11.data();
  const Scalar *dataA12 = A12.data();
  const Scalar *dataA13 = A13.data();
  const Scalar *dataA14 = A14.data();
  const Scalar *dataA15 = A15.data();
  Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a1 = alpha1 * dataA1[i + j * strideA1];
	  Scalar a2 = alpha2 * dataA2[i + j * strideA2];
	  Scalar a3 = alpha3 * dataA3[i + j * strideA3];
	  Scalar a4 = alpha4 * dataA4[i + j * strideA4];
	  Scalar a5 = alpha5 * dataA5[i + j * strideA5];
	  Scalar a6 = alpha6 * dataA6[i + j * strideA6];
	  Scalar a7 = alpha7 * dataA7[i + j * strideA7];
	  Scalar a8 = alpha8 * dataA8[i + j * strideA8];
	  Scalar a9 = alpha9 * dataA9[i + j * strideA9];
	  Scalar a10 = alpha10 * dataA10[i + j * strideA10];
	  Scalar a11 = alpha11 * dataA11[i + j * strideA11];
	  Scalar a12 = alpha12 * dataA12[i + j * strideA12];
	  Scalar a13 = alpha13 * dataA13[i + j * strideA13];
	  Scalar a14 = alpha14 * dataA14[i + j * strideA14];
	  Scalar a15 = alpha15 * dataA15[i + j * strideA15];
	  dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15;
	}
  }
}

// Template declarations
template void Gemm(Matrix<double>& A, Matrix<double>& B, Matrix<double>& C, double beta);
template void Gemm(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C, float beta);

template void Negate(Matrix<double>& A, Matrix<double>& C);
template void Negate(Matrix<float>& A, Matrix<float>& C);

template void Add(Matrix<double>& A1, Matrix<double>& A2, double alpha1,
                  double alpha2,  Matrix<double>& C);
template void Add(Matrix<float>& A1, Matrix<float>& A2, float alpha1,
                  float alpha2, Matrix<float>& C);

template void Add(Matrix<double>& A1, Matrix<double>& A2, Matrix<double>& A3,
                  double alpha1, double alpha2, double alpha3,
                  Matrix<double>& C);
template void Add(Matrix<float>& A1, Matrix<float>& A2, Matrix<float>& A3,
                  float alpha1, float alpha2, float alpha3, Matrix<float>& C);

template double FrobeniusDiff(Matrix<double>& A, Matrix<double>& B);
template double FrobeniusDiff(Matrix<float>& A, Matrix<float>& B);

#endif  // _LINALG_HPP_
