#include "common.hpp"
#include "fast_qr.hpp"
#include "lapack_wrap.hpp"
#include "linalg.hpp"

#include <vector>

void QRSolve(Matrix<double>& A, std::vector<double>& tau, Matrix<double>& RHS) {
  assert(A.m() == RHS.m());
  char side = 'L';   // Apply Q' on left-hand-side
  char trans = 'T';  // Apply Q'
  // Apply Q' to RHS and store in RHS
  int M = RHS.m();
  int N = RHS.n();
  int K = A.n();
  assert(tau.size() <= K);
  lapack::Ormqr(side, trans, M, N, K, A.data(), A.stride(),
				&tau[0], RHS.data(), RHS.stride());

  // Solve with R and store in RHS
  side = 'L';         // Apply on left-hand-side
  char uplo = 'U';    // R is uppper triangular
  char transa = 'N';  // no transpose
  char diag = 'N';    // not unit triangular
  M = K;
  N = RHS.n();
  
  lapack::Trsm(side, uplo, transa, diag, M, N, 1.0,
			   A.data(), A.stride(), RHS.data(), RHS.stride());
}


void Compare(Matrix<double>& A, std::vector<double>& tau_A,
			 Matrix<double>& B, std::vector<double>& tau_B) {
  Matrix<double> rhs_A = RandomMatrix<double>(A.m(), 1);
  Matrix<double> rhs_B = rhs_A;

  QRSolve(A, tau_A, rhs_A);
  QRSolve(A, tau_A, rhs_B);
  std::cout << "Max. rel. diff. (solution): " << MaxRelativeDiff(rhs_A, rhs_B)
			<< std::endl;
}


void RunTest(int m, int n, int blocksize) {
  std::cout << "Factoring " << m << " x " << n << " matrix with blocksize="
			<< blocksize << std::endl;
  Matrix<double> A = RandomMatrix<double>(m, n);
  Matrix<double> B = A;
  std::vector<double> tau_A(A.n()), tau_B(B.n());
  QR(A, tau_A);
  FastQR(B, tau_B, blocksize);
  Compare(A, tau_A, B, tau_B);
}


int main(int argc, char **argv) {
  RunTest(4000, 3000, 800);
  RunTest(5000, 4000, 1000);
  RunTest(4301, 3407, 725);
  return 0;
}
