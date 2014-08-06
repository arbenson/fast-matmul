#include "blas.hpp"
#include "common.hpp"
#include "lapack_wrap.hpp"
#include "linalg.hpp"
#include "mkl.h"
#include "fast424_26_257.hpp"
#include "strassen.hpp"
#include "timing.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

template<typename Scalar>
void LU(Matrix<Scalar>& A, std::vector<int>& pivots, int pos=0) {
  assert(A.m() > 0 && A.n() > 0);
  int m = A.m();
  int n = A.n();
  int lda = A.stride();
  Scalar *data = A.data();
  lapack::Getrf(data, m, n, lda, &pivots[pos]);
}


// Solve LX = B and store X in B.  L is lower triangular.
template<typename Scalar>
void TriangSolve(Matrix<Scalar>& L, Matrix<Scalar>& B) {
  char side = 'L';    // Solve with matrix on the left
  char uplo = 'L';    // lower triangular
  char transa = 'N';  // no transpose
  char diag = 'U';    // unit diagonal
  int M = B.m();
  int N = B.n();
  Scalar alpha = Scalar(1.0);
  Scalar *data_A = L.data();
  int lda = L.stride();
  Scalar *data_B = B.data();
  int ldb = B.stride();
  lapack::Trsm(side, uplo, transa, diag, M, N, alpha, data_A, lda, data_B, ldb);
}


template<typename Scalar>
void FastLU(Matrix<Scalar>& A, std::vector<int>& pivots, int blocksize) {
  if (A.m() != A.n()) {
	throw std::logic_error("Only supporting square matrices.");
  }
  pivots.resize(A.m(), -1);

  int j;
  for (j = 0; j + blocksize <= std::min(A.m(), A.n()); j += blocksize) {
	// Compute LU on the panel.
	Matrix<Scalar> Panel = A.Submatrix(j, j, A.m() - j, blocksize);
	LU(Panel, pivots, j);

	// Adjust the pivots, since our panel actually started at row j
	for (int i = j; i < j + blocksize; ++i) {
	  pivots[i] += j;
	}

	// Apply the pivots to the j columns
	lapack::Laswp(j, A.data(), A.stride(), j + 1, j + blocksize, &pivots[0], 1);

	if (j + blocksize < A.m()) {
	  // Apply pivots to the rest of the matrix.
	  int start = j + blocksize;
	  lapack::Laswp(A.m() - start, A.data() + start * A.stride(),
					A.stride(), j + 1, j + blocksize, &pivots[0], 1);

	  // Solve for L11U12 = A12
	  Matrix<Scalar> L11 = Panel.Submatrix(0, 0, blocksize, blocksize);
	  Matrix<Scalar> A12 = A.Submatrix(j, j + blocksize, blocksize, A.n() - j - blocksize);
	  TriangSolve(L11, A12);

	  // Update with schur complement using fast algorithm.
	  Matrix<Scalar> L21 = A.Submatrix(start, j, A.m() - start, blocksize);
	  Matrix<Scalar> A22 = A.Submatrix(start, start, A.m() - start, A.n() - start);

	  int num_steps = 1;
	  strassen::FastMatmul(L21, A12, A22, num_steps, 0, -1.0, 1.0);
	}
  }

  // Now deal with any leftovers
  if (j != std::min(A.m(), A.n())) {
	Matrix<Scalar> A_end = A.Submatrix(j, j, A.m() - j, A.n() - j);
	LU(A_end, pivots, j);

	// Adjust the pivots
	for (int i = j; i < std::min(A.m(), A.n()); ++i) {
	  pivots[i] += j;
	}

	// Apply the pivots to the first j columns
	lapack::Laswp(j, A.data(), A.stride(), j + 1, std::min(A.m(), A.n()),
				  &pivots[0], 1);
  }
}
