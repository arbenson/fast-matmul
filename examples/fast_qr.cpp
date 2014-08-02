#include "blas.hpp"
#include "lapack_wrap.hpp"
#include "linalg.hpp"
#include "mkl.h"
#include "strassen.hpp"
#include "timing.hpp"

#include <stdexcept>
#include <vector>


template <typename Scalar>
void QR (Matrix<Scalar>& A, std::vector<Scalar>& tau, int pos) {
  int m = A.m();
  int n = A.n();
  int lda = A.stride();
  Scalar *A_data = A.data();
  Scalar *curr_tau = &tau[pos];
  lapack::Geqrf(m, n, A_data, lda, curr_tau);
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
  Scalar *curr_tau = &tau[pos];

  // Triangular matrix for storing data.
  int ldt = N;
  Matrix<Scalar> T(ldt, N);
  Scalar *T_data = T.data();
  lapack::Larft(direct, storev, M, N, A_data, lda, curr_tau, T_data, ldt);

  return T;
}


template <typename Scalar>
void TriangMatmul(char side, char uplo, char transt, char diag,
				  Scalar alpha, Matrix<Scalar>& T, Matrix<Scalar>& B) {
  int m = B.m();
  int n = B.n();
  Scalar *T_data = T.data();
  int ldt = T.stride();
  Scalar *B_data = B.data();
  int ldb = B.stride();
  lapack::Trmm(side, uplo, transt, diag, m, n, alpha, T_data, ldt, B_data, ldb);
}


template <typename Scalar>
void UpdateTrailing(Matrix<Scalar>& V, Matrix<Scalar>& T, Matrix<Scalar>& A2) {
  // W := V^T
  Matrix<Scalar> Vt = TransposedCopy(V);

  // W := Vt * A2
  Matrix<Scalar> W(Vt.m(), A2.n());
  int num_steps = 1;
  strassen::FastMatmul(Vt, A2, W, num_steps);

  // W := T^T * W
  TriangMatmul('L', 'U', 'T', 'N', Scalar(1.0), T, W);

  // A2 := A2 - VW
  strassen::FastMatmul(V, W, A2, num_steps, 0.0, -1.0, 1.0);
}


template<typename Scalar>
void FastQR(Matrix<Scalar>& A, std::vector<Scalar>& tau, int blocksize) {
  if (A.m() != A.n()) {
	throw std::logic_error("Only supporting m == n for now.");
  }
  tau.resize(A.n());
  
  for (int i = 0; i < A.m() && A.m() - i > blocksize; i += blocksize) {
	// Split A as A = (A1 A2) and compute QR on A1.
	Matrix<Scalar> A1 = A.Submatrix(i, i, A.m() - i, blocksize);
	Matrix<Scalar> A2 = A.Submatrix(i, i + blocksize, A.m() - i, A.n() - i - blocksize);
	QR(A1, tau, i);

	// Form the triangular factor of the reflectors
	Matrix<Scalar> T = TriangFactor(A1, tau, i);

	// A2 := (I - VT'V')A2
	UpdateTrailing(A1, T, A2);
  }

  // Now deal with the leftovers
  int start_ind = (A.m() / blocksize) * blocksize;
  int num_left = A.m() - start_ind;
  if (num_left == 0) {
	return;
  }
  Matrix<Scalar> A_end = A.Submatrix(start_ind, start_ind, num_left, A.n() - start_ind);
  QR(A_end, tau, start_ind);
}


int main(int argc, char **argv) {
  int n = 8000;
  int blocksize = 4000;
  Matrix<double> A = RandomMatrix<double>(n, n);
  Matrix<double> B = A;

  std::vector<double> tau(A.n());
  Time([&] { QR(A, tau, 0); }, "Classical QR");
  Time([&] { FastQR(B, tau, blocksize); }, "Fast QR");

  return 0;
}
