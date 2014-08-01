#include "blas.hpp"
#include "common.hpp"
#include "linalg.hpp"
#include "mkl.h"
#include "fast424_26_257.hpp"
#include "strassen.hpp"
#include "timing.hpp"

#include <stdexcept>
#include <vector>

void Getrf(double *data, int m, int n, int lda, int *pivots) {
  int info;
  dgetrf_(&m, &n, data, &lda, pivots, &info);
  assert(info == 0);
}

void Getrf(float *data, int m, int n, int lda, int *pivots) {
  int info;
  sgetrf_(&m, &n, data, &lda, pivots, &info);
  assert(info == 0);
}

void Laswp(int num_cols, double *data, int lda, int piv_start, int piv_end,
		   int *pivots, int incx) {
  dlaswp_(&num_cols, data, &lda,  &piv_start, &piv_end, pivots, &incx);
}

void Laswp(int num_cols, float *data, int lda, int piv_start, int piv_end,
		   int *pivots, int incx) {
  slaswp_(&num_cols, data, &lda,  &piv_start, &piv_end, pivots, &incx);
}

void Trsm(char side, char uplo, char transa, char diag, int m, int n,
		  double alpha, double *A, int lda, double *B, int ldb) {
  dtrsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
}

void Trsm(char side, char uplo, char transa, char diag, int m, int n,
		  float alpha, float *A, int lda, float *B, int ldb) {
  strsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
}

template<typename Scalar>
void LU(Matrix<Scalar>& A, std::vector<int>& pivots, int pos) {
  assert(A.m() > 0 && A.n() > 0);
  int m = A.m();
  int n = A.n();
  int lda = A.stride();
  Scalar *data = A.data();
  Getrf(data, m, n, lda, &pivots[pos]);
}

template<typename Scalar>
void Pivot(Matrix<Scalar>& A, std::vector<int>& pivots, int start, int num_pivs) {
  int N = A.n();
  Scalar *data = A.data();
  int stride = A.stride();
  Laswp(N, data, stride, start, start + num_pivs, &pivots[0], 1);
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
  Trsm(side, uplo, transa, diag, M, N, alpha, data_A, lda, data_B, ldb);
}


template<typename Scalar>
void FastLU(Matrix<Scalar>& A, int blocksize) {
  if (A.m() < A.n()) {
	throw std::logic_error("Only supporting m >= n");
  }
  std::vector<int> pivots(A.m());
  
  for (int i = 0; i < A.m() && A.m() - i > blocksize; i += blocksize) {
	// Compute LU on the panel.
	Matrix<Scalar> Panel = A.Submatrix(i, i, A.m() - i, blocksize);
	LU(Panel, pivots, i);
	Pivot(A, pivots, i, blocksize);
	
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

  // Now deal with the leftovers
  int start_ind = (A.m() / blocksize) * blocksize;
  int num_left = A.m() - start_ind;
  assert(num_left >= A.m());
  if (num_left == 0) {
	return;
  }
  Matrix<Scalar> A_end = A.Submatrix(start_ind, start_ind, num_left, A.n() - start_ind);
  LU(A_end, pivots, start_ind);
  Pivot(A,  pivots, start_ind, num_left);
}


int main(int argc, char **argv) {
  int n = 10000;
  Matrix<double> A = RandomMatrix<double>(n, n);
  Matrix<double> B = A;

  omp_set_num_threads(7);

  std::vector<int> pivots(A.m());
  Time([&] { LU(A, pivots, 0); }, "Classical LU");
  Time([&] { FastLU(B, 2400); }, "Fast LU");
}
