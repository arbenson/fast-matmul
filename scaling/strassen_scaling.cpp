/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

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

  int max_steps = 50;
  std::vector<double> r_vals, s_vals;
  Scaling<double>(A, B, max_steps, r_vals, s_vals, OUTER_INNER);
  strassen::FastMatmul(A, B, C3, numsteps);
  PostProcessScaling(C3, r_vals, s_vals);
  
  // Test for correctness.
  std::cout << "Frobenius diff. Strass / Classical (no scaling): " << FrobeniusDiff(C1, C2) << std::endl;
  std::cout << "Frobenius diff. Strass / Classical (w/ scaling): " << FrobeniusDiff(C1, C3) << std::endl;

  std::cout << "Max. rel. diff. Strass / Classical (no scaling): " << MaxRelativeDiff(C1, C2) << std::endl;
  std::cout << "Max. rel. diff. Strass / Classical (w/ scaling): " << MaxRelativeDiff(C1, C3) << std::endl;
  
  return 0;
}
