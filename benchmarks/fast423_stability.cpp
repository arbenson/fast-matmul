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
#include "fast423_20_138.hpp"
#include "fast423_20_156.hpp"
#include "strassen.hpp"

#include "random_matrices.hpp"
#include "quadmatmul.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

void PrintData(std::vector<double>& data, std::string msg) {
  std::cout << msg << " = [ ";
  for (double point : data) {
    std::cout << point << " ";
  }
  std::cout << " ];" << std::endl;
}

// Run the benchmark code for multiplying a m x k matrix by a k x n matrix.
void Benchmark(int m, int k, int n, std::vector<int>& num_steps) {
  std::vector<double> errorscls(num_steps.size());
  std::vector<double> errors130(num_steps.size());
  std::vector<double> errors134(num_steps.size());
  std::vector<double> errors138(num_steps.size());
  std::vector<double> errors156(num_steps.size());

  Matrix<double> A = UniformRandomMatrix<double>(m, k, -1, 1);
  Matrix<double> B = UniformRandomMatrix<double>(k, n, -1, 1);

  std::cout << "||A|| = "   << A.MaxNorm()
	    << ", ||B|| = " << B.MaxNorm()
	    << std::endl;

  std::cout << "Quad matmul..." << std::endl;
  Matrix<__float128> C(A.m(), B.n());
  QuadMatmul(A.data(), B.data(), C.data(), A.m(), A.n(), B.n());
  std::cout << "Done...";
  // Convert back to double
  Matrix<double> C_dbl(A.m(), B.n());
  for (int j = 0; j < C.n(); ++j) {
    for (int i = 0; i < C.m(); ++i) {
      C_dbl(i, j) = (double) C(i, j);
    }
  }

  Matrix<double> C1(m, n);
  for (int i = 0; i < num_steps.size(); ++i) {
    fast423_130::FastMatmul(A, B, C1, 0);
    errorscls[i] = MaxAbsDiff(C_dbl, C1);

    fast423_130::FastMatmul(A, B, C1, num_steps[i]);
    errors130[i] = MaxAbsDiff(C_dbl, C1);

    fast423_134::FastMatmul(A, B, C1, num_steps[i]);
    errors134[i] = MaxAbsDiff(C_dbl, C1);

    fast423_138::FastMatmul(A, B, C1, num_steps[i]);
    errors138[i] = MaxAbsDiff(C_dbl, C1);

    fast423_156::FastMatmul(A, B, C1, num_steps[i]);
    errors156[i] = MaxAbsDiff(C_dbl, C1);

    std::cout << "step " << i << std::endl;
  }

  PrintData(errorscls, "errorscls");
  PrintData(errors130, "errors134");
  PrintData(errors134, "errors134");
  PrintData(errors138, "errors138");
  PrintData(errors156, "errors156");
}

int main(int argc, char **argv) {
#if 1
  int m = 4096;
  int k = 256;
  int n = 2187;
#else
  int m = 4096;
  int k = 2048;
  int n = 3645;
#endif
  std::vector<int> num_steps = {1, 2, 3, 4, 5, 6};
  
  Benchmark(m, k, n, num_steps);

  return 0;
}
