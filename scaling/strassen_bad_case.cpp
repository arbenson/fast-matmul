#include "linalg.hpp"
#include "scaling.hpp"
#include "strassen.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 4000;
  int k = 4000;
  int n = 4000;
  int numsteps = 4;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n), C3(m, n);
  for (int j = 0; j < n / 2; ++j) {
	for (int i = 0; i < m / 2; ++i) {
	  A(i, j) *= 1e-8;
	}
  }
  MatMul(A, B, C1);
  strassen::FastMatmul(A, B, C2, numsteps);

  int max_steps = 50;
  std::vector<double> r_vals, s_vals;
  Scaling<double>(A, B, max_steps, r_vals, s_vals, INNER_OUTER);
  strassen::FastMatmul(A, B, C3, numsteps);
  PostProcessScaling(C3, r_vals, s_vals);
  
  // Test for correctness.
  std::cout << "Frobenius diff. Strass / Classical (no scaling): " << FrobeniusDiff(C1, C2) << std::endl;
  std::cout << "Frobenius diff. Strass / Classical (w/ scaling): " << FrobeniusDiff(C1, C3) << std::endl;

  std::cout << "Max. rel. diff. Strass / Classical (no scaling): " << MaxRelativeDiff(C1, C2) << std::endl;
  std::cout << "Max. rel. diff. Strass / Classical (w/ scaling): " << MaxRelativeDiff(C1, C3) << std::endl;
  
  return 0;
}
