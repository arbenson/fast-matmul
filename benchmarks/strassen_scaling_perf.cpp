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

#include "scaling.hpp"
#include "strassen.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

enum Algorithm {
  CLASSICAL = 0,
  STRASSEN,
  STRASSEN_SCALED,
};

const int kNumScalingSteps = 5;
const int kNumTrials = 5;

// Run a single benchmark for multiplying m x k x n with num_steps of recursion.
// To just call GEMM, set num_steps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int alg) {
  // Run a set number of trials and pick the median time.
  int num_trials = 5;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < kNumTrials; ++trial) {
    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C(m, n);
    if (alg == CLASSICAL) {
      times[trial] = Time([&] { MatMul(A, B, C); });
    } else if (alg == STRASSEN) {
      times[trial] = Time([&] { strassen::FastMatmul(A, B, C, 1); });
    } else if (alg == STRASSEN_SCALED) {
      times[trial] = Time([&] {
	  Matrix<double> A_roi = A;
	  Matrix<double> B_roi = B;
	  std::vector<double> r_roi, s_roi;
	  Scaling(A_roi, B_roi, kNumScalingSteps, r_roi, s_roi, OUTSIDE_INSIDE);
	  strassen::FastMatmul(A, B, C, 1);
	  PostProcessScaling(C, r_roi, s_roi);
	});
    }
  }

  // Spit out the median time
  std::sort(times.begin(), times.end());
  size_t ind = num_trials / 2;
  std::cout << " " << m << " " << k << " " << n << " "
            << " " << times[ind] << "; ";
}

int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);

  int start = 1000;
  int end = 7500;
  int skip = 500;

  std::cout << "Classical" << std::endl;
  for (int N = start; N <= end; N += skip) {
    SingleBenchmark(N, N, N, CLASSICAL);
  }
  std::cout << std::endl;

  std::cout << "Strassen" << std::endl;
  for (int N = start; N <= end; N += skip) {
    SingleBenchmark(N, N, N, STRASSEN);
  }
  std::cout << std::endl;

  std::cout << "Strassen" << std::endl;
  for (int N = start; N <= end; N += skip) {
    SingleBenchmark(N, N, N, STRASSEN_SCALED);
  }
  std::cout << std::endl;

  return 0;
}
