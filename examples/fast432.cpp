#include "linalg.hpp"
#include "fast432_20_144.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 3600;
  int k = 2400;
  int n = 1200;
  int numsteps = 1;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);

  Time([&] { MatMul(A, B, C1); }, "Classical gemm");
  Time([&] { grey432_20_144::FastMatmul(A, B, C2, numsteps); }, "Fast (4, 3, 2)");

  // Test for correctness.
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

  return 0;
}
