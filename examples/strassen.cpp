#include "linalg.hpp"
#include "strassen.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 10000;
  int k = 10000;
  int n = 10000;
  int numsteps = 2;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);

  mkl_set_num_threads(24);
  
  Time([&] { Gemm(A, B, C1); }, "Classical gemm");
  Time([&] { strassen::FastMatmul(A, B, C2, numsteps); }, "Strassen");
  
  // Test for correctness.
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  
  return 0;
}
