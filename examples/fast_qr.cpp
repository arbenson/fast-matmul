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
  
  // QR routine that does the work.
  sgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);  
  if (info != 0) {
	throw std::exception("Bad sgeqrf_ call");
  }
  delete [] work;
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

  // QR routine that does the work.
  dgeqrf_(&m, &n, A, &lda, tau, work, lwork, &info);  
  if (info != 0) {
	throw std::exception("Bad dgeqrf_ call");
  }
  delete [] work;
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

void Larft(char direct, char storev, int m, int n, double *V, int ldv,
		   double *tau, double *T, int ldt) {
  dlarft_(&direct, &storev, &m, &n, V, &ldv, tau, T, &ldt);
}

void Larft(char direct, char storev, int m, int n, float *V, int ldv,
		   float *tau, float *T, int ldt) {
  slarft_(&direct, &storev, &m, &n, V, &ldv, tau, T, &ldt);
}

template <typename Scalar>
Matrix<Scalar> TriangFactor(Matrix<Scalar>& A, std::vector<Scalar>& tau,
							int pos) {
  char direct = 'F';  // Forward direction of householder reflectors.
  char storev = 'C';  // Columns of V are stored columnwise.
  Scalar *A_data = A.data();
  int M = A.m();
  int N = A.n();
  int lda = A.stride();
  Scalar *tau = &tau[pos];

  // Triangular matrix for storing data.
  int ldt = N;
  Matrix<Scalar> T(ldt, N);
  Scalar *T_data = T.data();

  Larft(direct, storev, M, N, A_data, lda, tau, T_data, ldt);

  return T;
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
	Matrix<Scalar> A2 = A.Submatrix(i, i + blocksize, A.m() - i, A.n() - i - blocksize);
	QR(A1, tau, i);

	// Form the triangular factor of the reflectors
	Matrix<Scalar> T = TriangFactor(A1, tau, pos);

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
