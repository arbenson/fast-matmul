/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "common.hpp"
#ifdef __INTEL_MKL__
# include "mkl.h"
#endif

#include "fast423_20_130.hpp"
#include "fast423_20_134.hpp"
#include "fast423_20_135.hpp"
#include "strassen.hpp"

#include "random_matrices.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

// Return the error in the computed matrix C_comp = A * B.
// Specifically, returns
//      max_{ij} 
double Error(Matrix<double>& A, Matrix<double>& B, Matrix<double>& Ccomp) {
  // No error (0 steps of recursion)
  Matrix<double> C(A.m(), B.n());
  strassen::FastMatmul(A, B, C, 0);
  return MaxAbsDiff(Ccomp, C);
}

// Run a benchmark for multiplying m x k x n with num_steps of recursion.
// To just call GEMM, set num_steps to zero.
// The median of five trials is printed to std::cout.
void Benchmark(int m, int k, int n, std::vector<int>& num_steps) {
  // Run a set number of trials and pick the median time.
  std::vector<double> errors130(num_steps.size());
  std::vector<double> errors134(num_steps.size());
  std::vector<double> errors135(num_steps.size());

  Matrix<double> A = UniformRandomMatrix<double>(m, k, -1, 1);
  Matrix<double> B = UniformRandomMatrix<double>(k, n, -1, 1);

  std::cout << "||A|| = "   << A.MaxNorm()
	    << ", ||B|| = " << B.MaxNorm()
	    << std::endl;

  Matrix<double> C1(m, n);

  for (int i = 0; i < num_steps.size(); ++i) {
    fast423_130::FastMatmul(A, B, C1, num_steps[i]);
    errors130[i] = Error(A, B, C1);

    fast423_134::FastMatmul(A, B, C1, num_steps[i]);
    errors134[i] = Error(A, B, C1);

    fast423_135::FastMatmul(A, B, C1, num_steps[i]);
    errors135[i] = Error(A, B, C1);

    std::cout << "step " << i << std::endl;
  }
 
  std::cout << "errors130 = [ ";
  for (double err : errors130) {
    std::cout << err << " ";
  }
  std::cout << " ];" << std::endl;

  std::cout << "errors134 = [ ";
  for (double err : errors134) {
    std::cout << err << " ";
  }
  std::cout << " ];" << std::endl;

  std::cout << "errors135 = [ ";
  for (double err : errors135) {
    std::cout << err << " ";
  }
  std::cout << " ];" << std::endl;
}

int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);

  int m = 4096;
  int k = 2048;
  int n = 3645;
  std::vector<int> num_steps = {1, 2, 3, 4, 5, 6};
  
  Benchmark(m, k, n, num_steps);

  return 0;
}
