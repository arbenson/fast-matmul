/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "linalg.hpp"
#include "schonhage333_21_117_approx.hpp"
#include "float.h"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 90;
  int k = 90;
  int n = 90;
  int numsteps = 1;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);
  MatMul(A, B, C1);

  for (int numsteps = 1; numsteps <= 2; ++numsteps) {
	double lambda = DBL_EPSILON;
	std::cout << numsteps << std::endl;
	while (lambda < 1) {
	  schonhage333_21_117_approx::FastMatmul(A, B, C2, numsteps, lambda);
	  std::cout << lambda << ", " << MaxRelativeDiff(C1, C2) << "; ";
	  lambda *= 2;
	}
	std::cout << std::endl;
  }

  return 0;
}
