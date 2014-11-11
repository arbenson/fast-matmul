#include "linalg.hpp"
#include "fast442_26_257.hpp"
#include "random_matrices.hpp"
#include "scaling.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 160;
  int k = 160;
  int n = 160;
  int numsteps = 2;

  Matrix<double> A = UniformRandomMatrix<double>(m, k, 0.0, 1.0);
  Matrix<double> B = UniformRandomMatrix<double>(k, n, 0.0, 1.0);
  Matrix<double> C1(m, n), C2(m, n), C3(m, n);
  MatMul(A, B, C1);
  grey442_26_257::FastMatmul(A, B, C2, numsteps);

  int max_steps = 100;
  std::vector<double> r_vals, s_vals;
  int scaling_type = INNER_OUTER;
  Scaling<double>(A, B, max_steps, r_vals, s_vals, scaling_type);
  grey442_26_257::FastMatmul(A, B, C3, numsteps);
  PostProcessScaling(C3, r_vals, s_vals);
  
  // Test for correctness.
  std::cout << "Frobenius diff. 442 / Classical (no scaling): " << FrobeniusDiff(C1, C2) << std::endl;
  std::cout << "Frobenius diff. 442 / Classical (w/ scaling): " << FrobeniusDiff(C1, C3) << std::endl;

  std::cout << "Max. rel. diff. 442 / Classical (no scaling): " << MaxRelativeDiff(C1, C2) << std::endl;
  std::cout << "Max. rel. diff. 442 / Classical (w/ scaling): " << MaxRelativeDiff(C1, C3) << std::endl;
  
  return 0;
}
