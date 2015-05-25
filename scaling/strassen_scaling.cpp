/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "linalg.hpp"
#include "random_matrices.hpp"
#include "scaling.hpp"
#include "strassen.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 1024;
  int k = 1024;
  int n = 1024;
  int numsteps = 1;

  Matrix<double> A = SkewedUniformRandomMatrix3<double>(m, k, 0, 1);
  Matrix<double> B = UniformRandomMatrix<double>(k, n, 0, 1);
  Matrix<double> C1(m, n), C2(m, n), C3(m, n);
  MatMul(A, B, C1);
  strassen::FastMatmul(A, B, C2, numsteps);

  double norm_scale = A.Norm(NormType::MAX) * B.Norm(NormType::MAX);

  int max_steps = 10;
  std::vector<double> r_vals, s_vals;
  Scaling<double>(A, B, max_steps, r_vals, s_vals, OUTER_INNER);
  strassen::FastMatmul(A, B, C3, numsteps);
  PostProcessScaling(C3, r_vals, s_vals);

  // Test for correctness.
  std::cout << "Rel. Frobenius diff. Strass / Classical (no scaling): "
	    << FrobeniusDiff(C1, C2) / norm_scale
	    << std::endl;
  std::cout << "Frobenius diff. Strass / Classical (w/ scaling): "
	    << FrobeniusDiff(C1, C3) / norm_scale
	    << std::endl;
  return 0;
}
