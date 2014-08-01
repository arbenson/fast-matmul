#include "blas.hpp"
#include "linalg.hpp"
#include "mkl.h"
#include "strassen.hpp"
#include "timing.hpp"

#include <stdexcept>
#include <vector>

Geqrf(int m, int n, float *A, int lda, float *tau) {
  // First perform the workspace query.
  float *work = new float[1];
  int lwork = -1;
  int info;
  sgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);
  if (info != 0) {
	throw std::exception("Bad sgeqrf_ call");
  }
  
  // Now allocate the work array.
  lwork = static_cast<int>(work[0]);
  delete [] work;
  work = new float[lwork];
  
  sgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);  
  if (info != 0) {
	throw std::exception("Bad sgeqrf_ call");
  }
}


Geqrf(int m, int n, double *A, int lda, double *tau) {
  // First perform the workspace query.
  double *work = new double[1];
  int lwork = -1;
  int info;
  dgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);
  if (info != 0) {
	throw std::exception("Bad dgeqrf_ call");
  }
  
  // Now allocate the work array.
  lwork = static_cast<int>(work[0]);
  delete [] work;
  work = new double[lwork];
  
  dgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);  
  if (info != 0) {
	throw std::exception("Bad dgeqrf_ call");
  }
}


template <typename Scalar>
void QR (Matrix<Scalar>& A, std::vector<Scalar>& tau, int pos) {
  int m = A.m();
  int n = A.n();
  int lda = A.stride();
  Scalar *A_data = A.data();
  Scalar *curr_tau = &tau[pos];
  Geqrf(m, n, A_data, lda, curr_tau);
}


template<typename Scalar>
void FastQR(Matrix<Scalar>& A, std::vector<Scalar>& tau, int blocksize) {
  if (A.m() < A.n()) {
	throw std::logic_error("Only supporting m >= n");
  }
  tau.resize(A.n());
  
  for (int i = 0; i < A.m() && A.m() - i > blocksize; i += blocksize) {
	// Split A as
	//     A = (A1 A2)
	// and compute QR on A1
	Matrix<Scalar> A1 = A.Submatrix(i, i, A.m() - i, blocksize);
	QR(A1, tau, i);
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

  std::vector<double> tau(A.n());
  Time([&] { QR(A, pivots, 0); }, "Classical QR");
  Time([&] { FastQR(B, 2400); }, "Fast QR");

  return 0;
}
