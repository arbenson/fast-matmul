/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "linalg.hpp"
#include "strassen.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 4000;
  int k = 4000;
  int n = 4000;
  int numsteps = 2;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);

  //mkl_set_num_threads(24);
  
  Time([&] { MatMul(A, B, C1); }, "Classical gemm");
  double time = strassen::FastMatmul(A, B, C2, numsteps);
  std::cout << "Fast time: " << time << " ms" << std::endl;
  
  // Test for correctness.
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  
  return 0;
}
