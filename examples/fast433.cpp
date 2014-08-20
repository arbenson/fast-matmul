#include "linalg.hpp"
#include "fast433_29_234.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 14000;
  int k = 7200;
  int n = 7200;
  int numsteps = 2;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);
  
  Time([&] { MatMul(A, B, C1); }, "Classical gemm");
  Time([&] { grey433_29_234::FastMatmul(A, B, C2, numsteps); }, "Fast (4, 3, 3)");
  
  // Test for correctness.
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  
  return 0;
}
