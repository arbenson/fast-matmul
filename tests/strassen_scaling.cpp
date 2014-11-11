#include "linalg.hpp"
#include "scaling.hpp"
#include "strassen.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 80;
  int k = 80;
  int n = 80;
  int numsteps = 3;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n), C3(m, n);
  MatMul(A, B, C1);
  strassen::FastMatmul(A, B, C2, numsteps);

  int max_steps = 10;
  std::vector<double> r_vals, s_vals;
  AlternatingScaling<double>(A, B, max_steps, r_vals, s_vals);
  strassen::FastMatmul(A, B, C3, numsteps);
  PostProcessScaling(C3, r_vals, s_vals);
  //std::cout << C3 << std::endl;
  
  // Test for correctness.
  std::cout << "Maximum relative difference Strassen / Classical (no scaling): " << MaxRelativeDiff(C1, C2) << std::endl;
  std::cout << "Maximum relative difference Strassen / Classical (w/ scaling): " << MaxRelativeDiff(C1, C3) << std::endl;
  
  return 0;
}
