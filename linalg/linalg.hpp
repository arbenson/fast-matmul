#ifndef _LINALG_HPP_
#define _LINALG_HPP_

#include "lapack_wrap.hpp"

#ifdef _PARALLEL_
# include <omp.h>
#endif

#if defined(_PARALLEL_) || defined(__INTEL_MKL__)
# include "mkl.h"
#endif

#include <assert.h>
#include <cstddef>
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

  Matrix(Scalar *data, int stride, int m, int n, Scalar multiplier, bool is_view) :
	data_(data), stride_(stride), m_(m), n_(n), multiplier_(multiplier), is_view_(is_view) {
	if (!is_view) {
	  allocate();
	}
  }  

  Matrix(Scalar *data, int stride, int m, int n, Scalar multiplier) :
    Matrix(data, stride, m, n, multiplier, true) {}
  Matrix(Scalar *data, int stride, int m, int n) : Matrix(data, stride, m, n, Scalar(1)) {}

  Matrix(int m, int n, Scalar multiplier) : Matrix(NULL, m, m, n, multiplier, false) {}
  Matrix(int m, int n) : Matrix(m, n, Scalar(1)) {}
  Matrix(int n=0) : Matrix(n, n) {}

  // Copy constructor
  Matrix(Matrix<Scalar>& that) : Matrix(NULL, that.m(), that.m(), that.n(),
										that.multiplier(), false) {
	Scalar *that_data = that.data();
	int that_stride = that.stride();
	for (int j = 0; j < n_; ++j) {
	  for (int i = 0; i < m_; ++i) {
		data_[i + j * stride_] = that_data[i + j * that_stride];
	  }
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
	using std::swap;
	swap(first.m_, second.m_);
	swap(first.n_, second.n_);
	swap(first.stride_, second.stride_);
	swap(first.is_view_, second.is_view_);
	swap(first.data_, second.data_);
	swap(first.multiplier_, second.multiplier_);
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
	if (data_ != NULL && !is_view_ && m_ > 0 && n_ > 0) {
	  deallocate();
	}
  }

  Scalar *data() { return data_; }
  Scalar *data(int i, int j) { return data_ + i + j * stride_; }
  int stride() { return stride_; }
  int m() { return m_; }
  int n() { return n_; }


  void allocate() {
	if (n_ > 0 && m_ > 0) {
	  assert(stride_ >= m_);
#ifdef __INTEL_MKL__
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
#ifdef __INTEL_MKL__
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
	MatMul(A_extra, B_extra, C_extra, Scalar(1.0));
  }

  // Adjust for far right columns of C
  if (extra_cols_B > 0) {
	// In Strassen, this looks like C(:, 3) = A * B(:, 3)
	int start_ind = B.n() - extra_cols_B;
	Matrix<Scalar> B_extra = B.Submatrix(0, start_ind, B.m(), extra_cols_B);
	Matrix<Scalar> C_extra = C.Submatrix(0, start_ind, C.m(), extra_cols_B);
	MatMul(A, B_extra, C_extra, beta);
  }

  // Adjust for bottom rows of C
  if (extra_rows_A > 0) {
	// In Strassen, this looks like C(3, [1, 2]) = A(3, :) * B(:, [1, 2])
	int start_ind = A.m() - extra_rows_A;
	int num_cols = B.n() - extra_cols_B;
	Matrix<Scalar> A_extra = A.Submatrix(start_ind, 0, extra_rows_A, A.n());
	Matrix<Scalar> B_extra = B.Submatrix(0, 0, B.m(), num_cols);
	Matrix<Scalar> C_extra = C.Submatrix(start_ind, 0, extra_rows_A, num_cols);
	MatMul(A_extra, B_extra, C_extra, beta);
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


// C <-- A * B + beta * C
template <typename Scalar>
void MatMul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
			Scalar beta=Scalar(0.0)) {
  assert(A.m() == C.m() && A.n() == B.m() && B.n() == C.n());
  assert(A.m() > 0 && A.n() > 0);
  Scalar alpha = C.multiplier();
  lapack::Gemm('N', 'N', A.m(), B.n(), A.n(), A.data(), A.stride(), B.data(),
			   B.stride(), C.data(), C.stride(), alpha, beta);
}

// C <-- alpha * A + C.  n is the number of entries.
template<typename Scalar>
void AxpyWrap(Scalar *C, Scalar *A, int n, Scalar alpha) {
  lapack::Axpy(C, A, n, alpha, 1, 1);
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
		AxpyWrap(dataC_curr, dataA_curr, C.m(), alpha1);
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
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
	  double val = static_cast<double>(rand()) / RAND_MAX;
      A.data()[i + j * A.stride()] = val;
    }
  }  
  return A;
}


// Return A^T as a copy.
template <typename Scalar>
Matrix<Scalar> TransposedCopy(Matrix<Scalar>& A) {
  Matrix<Scalar> At(A.n(), A.m());
  Scalar *A_data = A.data();
  Scalar *At_data = At.data();
  int A_stride = A.stride();
  int At_stride = At.stride();
  for (int j = 0; j < A.n(); ++j) {
	for (int i = 0; i < A.m(); ++i) {
	  At_data[j + i * At_stride] = A_data[i + j * A_stride];
	}
  }
  return At;
}

#endif  // _LINALG_HPP_
