#ifndef _LINALG_HPP_
#define _LINALG_HPP_

#include "blas.hpp"

#ifdef _INTEL_MKL_
# include <mkl.h>
#endif

#include <assert.h>
#include <time.h>

#include <cmath>
#include <iostream>

// This is a basic templated matrix class.
// It stores the matrix data, the stride, and the dimensions.
// The variable is_view indicates whether or not the data is owned
// by this instance.
template <typename Scalar>
class Matrix {
public:
  // Default constructor
  Matrix(int n=0) : m_(n), n_(n), stride_(n), is_view_(false), multiplier_(Scalar(1)) {
	allocate();
  }

  // Copy constructor
  Matrix(Matrix<Scalar>& that) {
	m_ = that.m();
	n_ = that.n();
	stride_ = that.stride();
	multiplier_ = that.multiplier();
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

  Matrix(int m, int n) : m_(m), n_(n), stride_(m), is_view_(false), multiplier_(Scalar(1)) {
	allocate();
  }


  Matrix(int m, int n, Scalar multiplier) : m_(m), n_(n), stride_(m), is_view_(false), multiplier_(multiplier) {
	allocate();
  }


  // Get a view of a subblock of the matrix.
  // num_block_rows and num_block_cols are the number of block rows and columns
  // row_ind and col_ind are the indices (1-indexed) of the block
  Matrix<Scalar> Subblock(int num_block_rows, int num_block_cols, int row_ind,
						  int col_ind) {
	std::pair<int, int> row_data = IndexData(m_, num_block_rows, row_ind);
	std::pair<int, int> col_data = IndexData(n_, num_block_cols, col_ind);
	return Submatrix(row_data.first, col_data.first, row_data.second, col_data.second);
  }


  Matrix<Scalar> Submatrix(int start_row, int start_col, int num_rows,
						   int num_cols) {
	return Matrix<Scalar>(data(start_row, start_col), stride_, num_rows, num_cols, multiplier_);
  }


  ~Matrix() {
	if (data_ != NULL && !is_view_ && m_ > 0 & n_ > 0) {
	  deallocate();
	}
  }

  Scalar *data() { return data_; }
  Scalar *data(int i, int j) { return data_ + i + j * stride_; }
  int stride() { return stride_; }
  int m() { return m_; }
  int n() { return n_; }

  //  template <typename Scalar>
  void allocate() {
	if (n_ > 0 && m_ > 0) {
#ifdef _INTEL_MKL_
	  int alignment = 32;
	  data_ = static_cast<Scalar *>(mkl_malloc(sizeof(Scalar) * m_ * n_, alignment));
#else
	  data_ = new Scalar[m_ * n_];
#endif
	  assert(data_ != NULL);
	}
  }

  void deallocate() {
	if (data_ != NULL) {
#ifdef _INTEL_MKL_
	  mkl_free(data_);
#else
	  delete[] data_;
#endif
	  data_ = NULL;
	}
  }

  void UpdateMultiplier(Scalar multiplier) { multiplier_ *= multiplier; }
  void set_multiplier(Scalar multiplier) { multiplier_ = multiplier; }
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


// Perform one step of dynamic peeling in the multiplication
//            C = A * B + beta C
// This should be called once at the end of a recursive fast
// matrix multiplication function.
// dim1, dim2, and dim3 refer to the (M, K, N) dimensions of
// the fast algorithm (M x K times K x N base case).
template<typename Scalar>
void DynamicPeeling(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
					int dim1, int dim2, int dim3, Scalar beta) {
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
	Gemm(A, B_extra, C_extra, beta);
  }

  // Adjust for bottom rows of C
  if (extra_rows_A > 0) {
	// In Strassen, this looks like C(3, [1, 2]) = A(3, :) * B(:, [1, 2])
	int start_ind = A.m() - extra_rows_A;
	int num_cols = B.n() - extra_cols_B;
	Matrix<Scalar> A_extra = A.Submatrix(start_ind, 0, extra_rows_A, A.n());
	Matrix<Scalar> B_extra = B.Submatrix(0, 0, B.m(), num_cols);
	Matrix<Scalar> C_extra = C.Submatrix(start_ind, 0, extra_rows_A, num_cols);
	Gemm(A_extra, B_extra, C_extra, beta);
  }
}


// Streams out all entries in the matrix.
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
			  int ldc, double alpha, double beta) {
  char transa = 'n';
  char transb = 'n';
  dgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
		 C, &ldc);
}


// Wrapper for sgemm called by templated gemm.
void GemmWrap(int m, int n, int k, float *A, int lda, float *B, int ldb,
			  float *C, int ldc, float alpha, float beta) {
  char transa = 'n';
  char transb = 'n';
  sgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
		 C, &ldc);
}


// C <-- A * B + beta * C
template <typename Scalar>
void Gemm(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, Scalar beta=Scalar(0.0)) {
  assert(A.m() == C.m() && A.n() == B.m() && B.n() == C.n());
  assert(A.m() > 0 && A.n() > 0);
  Scalar alpha = C.multiplier();
  GemmWrap(A.m(), B.n(), A.n(), A.data(), A.stride(), B.data(), B.stride(),
		   C.data(), C.stride(), alpha, beta);
}


// C <-- alpha * A + C
void AxpyWrap(double *C, double *A, int n, double alpha) {
  int incx = 1;
  int incy = 1;
  daxpy_(&n, &alpha, A, &incx, C, &incy);
}


// C <-- alpha * A + C
void AxpyWrap(float *C, float *A, int n, float alpha) {
  int incx = 1;
  int incy = 1;
  saxpy_(&n, &alpha, A, &incx, C, &incy);
}


// C <-- alpha * A + C.  n is the number of entries.
template<typename Scalar>
void Axpy(Scalar *C, Scalar *A, int n, Scalar alpha) {
  AxpyWrap(C, A, n, alpha);
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
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  dataC[i + j * strideC] = -a;
	}
  }
}


// C <-- A
template<typename Scalar>
void Copy(Matrix<Scalar>& A, Matrix<Scalar>& C) {
  assert(A.m() == C.m() && A.n() == C.n());
  const int strideA = A.stride();
  const int strideC = C.stride();
  const Scalar *dataA = A.data();
  Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
  for (int j = 0; j < C.n(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	  Scalar a = dataA[i + j * strideA];
	  dataC[i + j * strideC] = a;
	}
  }
}


// C = alpha1 * A1
template <typename Scalar>
void Copy(Matrix<Scalar>& A1,
		  Scalar alpha1,
		  Matrix<Scalar>& C) {
    const int strideA1 = A1.stride();
    Scalar *dataA1 = A1.data();

    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        const Scalar *dataA_curr = dataA1 + j * strideA1;
		Scalar *dataC_curr = dataC + j * strideC;
        for (int i = 0; i < C.m(); ++i) {
            dataC_curr[i] = alpha1 * dataA_curr[i];
        }
    }
}


// C += alpha1 * A1
template <typename Scalar>
void UpdateAdd(Matrix<Scalar>& A1,
			   Scalar alpha1,
			   Matrix<Scalar>& C) {
    const int strideA1 = A1.stride();
    Scalar *dataA1 = A1.data();

    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        const Scalar *dataA_curr = dataA1 + j * strideA1;
		Scalar *dataC_curr = dataC + j * strideC;
        for (int i = 0; i < C.m(); ++i) {
            dataC_curr[i] += alpha1 * dataA_curr[i];
        }
    }
}

// C += A1
template <typename Scalar>
void UpdateAdd(Matrix<Scalar>& A1,
			   Matrix<Scalar>& C) {
    const int strideA1 = A1.stride();
    Scalar *dataA1 = A1.data();

    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        const Scalar *dataA_curr = dataA1 + j * strideA1;
		Scalar *dataC_curr = dataC + j * strideC;
        for (int i = 0; i < C.m(); ++i) {
            dataC_curr[i] += dataA_curr[i];
        }
    }
}

// C -= A1
template <typename Scalar>
void UpdateSub(Matrix<Scalar>& A1,
			   Matrix<Scalar>& C) {
    const int strideA1 = A1.stride();
    Scalar *dataA1 = A1.data();

    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        const Scalar *dataA_curr = dataA1 + j * strideA1;
		Scalar *dataC_curr = dataC + j * strideC;
        for (int i = 0; i < C.m(); ++i) {
            dataC_curr[i] -= dataA_curr[i];
        }
    }
}


// C += alpha1 * A1
template <typename Scalar>
void UpdateAddDaxpy(Matrix<Scalar>& A1,
					Scalar alpha1,
					Matrix<Scalar>& C) {
    const int strideA1 = A1.stride();
    Scalar *dataA1 = A1.data();

    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        Scalar *dataA_curr = dataA1 + j * strideA1;
		Scalar *dataC_curr = dataC + j * strideC;
		Axpy(dataC_curr, dataA_curr, C.m(), alpha1);
    }
}


// C := 0
template <typename Scalar>
void ZeroOut(Matrix<Scalar>& C) {
    const int strideC = C.stride();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
		    dataC[i + j * strideC] = Scalar(0);
        }
    }
}


// Generate a matrix with random uniform entries on [0, 1024]
template <typename Scalar>
Matrix<Scalar> RandomMatrix(int m, int n) {
  srand (time(NULL));
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
    }
  }  
  return A;
}


#endif  // _LINALG_HPP_
