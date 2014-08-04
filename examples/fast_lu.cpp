#include "common.hpp"
#include "fast_lu.hpp"
#include "linalg.hpp"

#include <vector>

int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);
  int m = GetIntOpt(opts, "m", 10000);
  int n = GetIntOpt(opts, "n", m);
  int blocksize = GetIntOpt(opts, "blocksize", 1600);
  std::cout << "Factoring " << m << " x " << n << " matrix with blocksize "
			<< blocksize << std::endl;

  Matrix<double> A = RandomMatrix<double>(m, n);
  Matrix<double> B = A;

  std::vector<int> pivots(A.m());
  Time([&] { LU(A, pivots, 0); }, "Classical LU");
  Time([&] { FastLU(B, blocksize, pivots); }, "Fast LU");
}
