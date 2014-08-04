#include "common.hpp"
#include "fast_lu.hpp"
#include "lapack_wrap.hpp"
#include "linalg.hpp"

#include <vector>

void Compare(Matrix<double>& A, std::vector<int>& pivots_A,
			 Matrix<double>& B, std::vector<int>& pivots_B) {
  Matrix<double> rhs_A = RandomMatrix<double>(A.m(), 1);
  Matrix<double> rhs_B = rhs_A;
  lapack::Getrs('N', A.m(), 1, A.data(), A.stride(), &pivots_A[0],
				rhs_A.data(), rhs_A.stride());
  lapack::Getrs('N', B.m(), 1, B.data(), B.stride(), &pivots_B[0],
				rhs_B.data(), rhs_B.stride());
  std::cout << "Max. rel. diff. (solution): " << MaxRelativeDiff(rhs_A, rhs_B)
			<< std::endl;
}

void RunTest(int m, int n, int blocksize) {
  std::cout << "Factoring " << m << " x " << m << " matrix with blocksize="
			<< blocksize << std::endl;
  Matrix<double> A = RandomMatrix<double>(m, n);
  Matrix<double> B = A;
  LU(A, pivots_A);
  FastLU(B, blocksize, pivots_B);
  Compare(A, pivots_A, B, pivots_B);
}


int main(int argc, char **argv) {
  RunTest(4000, 800);
  RunTest(5000, 1000);
  RunTest(4301, 725);
  return 0;
}
