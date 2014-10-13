#include "common.hpp"
#ifdef __INTEL_MKL__
# include "mkl.h"
#endif

#include "all_algorithms.hpp"
#include "square54/square54_1.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

// Run a single benchmark for multiplying m x k x n with num_steps of recursion.
// To just call GEMM, set num_steps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int num_steps, int algorithm) {
  // Run a set number of trials and pick the median time.
  int num_trials = 1;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < num_trials; ++trial) {
    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n);
    if (algorithm == SMIRNOV54) {
      times[trial] = square54_1::FastMatmul(A, B, C1, 3);
    } else if (algorithm == MKL) {
      times[trial] = strassen::FastMatmul(A, B, C1, 0);
    } else if (algorithm == STRASSEN) {
      times[trial] = strassen::FastMatmul(A, B, C1, num_steps);
    } else if (algorithm == SCHONHAGE333_21_117_APPROX) {
      times[trial] = schonhage333_21_117_approx::FastMatmul(A, B, C1, num_steps);
    }
  }

  // Spit out the median time
  std::sort(times.begin(), times.end());
  size_t ind = num_trials / 2;
  std::cout << " " << m << " " << k << " " << n << " "
            << num_steps << " " << times[ind] << " "
            << "; ";
}

// Runs a set of benchmarks.
void BenchmarkSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
                  std::vector<int>& n_vals, std::vector<int>& num_steps,
                  int algorithm) {

  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());

  for (int curr_num_steps : num_steps) {
    std::cout << Alg2Str(algorithm) << "_" << curr_num_steps << " = [";
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], curr_num_steps, algorithm);
    }
    std::cout << "];" << std::endl;
  }
  std::cout << std::endl << std::endl;
}

int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);

  std::vector<int> m_vals;
  for (int i = 13000; i <= 13000; i += 1000) {
    m_vals.push_back(i);
  }
  
  if (OptExists(opts, "mkl")) {
    std::vector<int> num_steps = {0};
    BenchmarkSet(m_vals, m_vals, m_vals, num_steps, MKL);
  }

  if (OptExists(opts, "strassen")) {
    //int num_steps = GetIntOpt(opts, "strassen");
    std::vector<int> num_steps = {5};
    BenchmarkSet(m_vals, m_vals, m_vals, num_steps, STRASSEN);
  }

  if (OptExists(opts, "smirnov54")) {
    std::vector<int> num_steps = {3};
    BenchmarkSet(m_vals, m_vals, m_vals, num_steps, SMIRNOV54);
  }

  if (OptExists(opts, "schonhage")) {
    std::vector<int> num_steps = {2};
    BenchmarkSet(m_vals, m_vals, m_vals, num_steps, SCHONHAGE333_21_117_APPROX);
  }

  return 0;
}
