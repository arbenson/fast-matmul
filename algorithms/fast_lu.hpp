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


template<typename Scalar>
void Pivot(Matrix<Scalar>& A, std::vector<int>& pivots, int start,
		   int num_pivs) {
  int N = A.n();
  Scalar *data = A.data();
  int stride = A.stride();
  lapack::Laswp(N, data, stride, start, start + num_pivs, &pivots[0], 1);
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
void FastLU(Matrix<Scalar>& A, int blocksize, std::vector<int>& pivots) {
  if (A.m() != A.n()) {
	throw std::logic_error("Only supporting square matrices.");
  }
  pivots.resize(A.m());

  int i;
  for (int i = 0; i + blocksize <= std::min(A.m(), A.n()); i += blocksize) {
	// Compute LU on the panel.
	Matrix<Scalar> Panel = A.Submatrix(i, i, A.m() - i, blocksize);
	LU(Panel, pivots, i);
	Pivot(A, pivots, i, blocksize);
	
	if (i + blocksize < A.m()) {
	  // Solve for L11U12 = A12
	  Matrix<Scalar> L11 = Panel.Submatrix(0, 0, blocksize, blocksize);
	  Matrix<Scalar> A12 = A.Submatrix(i, i + blocksize, blocksize, A.n() - i - blocksize);
	  TriangSolve(L11, A12);

	  // Update with schur complement using fast algorithm.
	  Matrix<Scalar> L21 = Panel.Submatrix(i, 0, A.m() - i - blocksize, blocksize);
	  Matrix<Scalar> A22 = A.Submatrix(i, i, A.m() - i, A.n() - i);
	  int num_steps = 1;
	  strassen::FastMatmul(L21, A12, A22, num_steps, 0, 1.0, 1.0);
	}
  }

  // Now deal with any leftovers
  if (i != std::min(A.m(), A.n())) {
	Matrix<Scalar> A_end = A.Submatrix(i, i, A.m() - i, A.n() - i);
	LU(A_end, pivots, i);
	Pivot(A,  pivots, i, A.m() - i);
  }
}
