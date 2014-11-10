#include "linalg.hpp"
#include "scaling.hpp"
#include "strassen.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 4000;
  int k = 4000;
  int n = 4000;
  int numsteps = 2;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);
  MatMul(A, B, C1);
  
  int max_steps = 10;
  std::vector<double> r_vals, s_vals;
  AlternatingScaling<double>(A, B, max_steps, r_vals, s_vals);
  strassen::FastMatmul(A, B, C2, numsteps);
  PostProcessScaling(C2, r_vals, s_vals);
  
  // Test for correctness.
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  
  return 0;
}
