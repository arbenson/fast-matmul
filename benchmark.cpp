#include "common.hpp"

#include "bini322.hpp"
#include "classical.hpp"
#include "fast333.hpp"
#include "grey-fast234.hpp"
#include "grey-fast243.hpp"
#include "grey-fast322.hpp"
#include "grey-fast324.hpp"
#include "grey-fast332.hpp"
#include "grey-fast333.hpp"
#include "grey-fast342.hpp"
#include "grey-fast423.hpp"
#include "grey-fast432.hpp"
#include "grey-fast433.hpp"
#include "hk332.hpp"
#include "strassen.hpp"

#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

enum {
  BINI332,
  CLASSICAL,
  GREY322,
  GREY332,
  GREY333,
  GREY432,
  GREY423,
  GREY324,
  GREY342,
  GREY234,
  GREY243,
  GREY433,
  HK332,
};


// Run a single benchmark for multiplying m x k x n with numsteps of recursion.
// To just call GEMM, set numsteps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int numsteps, int algorithm, bool run_check=false) {
  Matrix<double> A(m, k);
  Matrix<double> B(k, n);
  Matrix<double> C1(m, n);
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
    }
  }
  for (int j = 0; j < B.n(); ++j) {
    for (int i = 0; i < B.m(); ++i) {
      B.data()[i + j * B.stride()] = ((double) rand() / RAND_MAX) * 1024;
    }
  }
  // Run a set number of trials and pick the median time.
  int num_trials = 5;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < num_trials; ++trial) {
    auto t1 = std::chrono::high_resolution_clock::now();
    switch (algorithm) {
    case BINI332:
      bini322::FastMatmul(A, B, C1, numsteps);
      break;
    case CLASSICAL:
      classical::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY322:
      grey322_11_50::FastMatmul(A, B, C1, numsteps);      
      break;
    case GREY332:
      grey332_15_103::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY333:
      grey333_23_152::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY432:
      grey432_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY423:
      grey423_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY324:
      grey324_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY342:
      grey342_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY234:
      grey234_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY243:
      grey324_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case GREY433:
      grey433_29_234::FastMatmul(A, B, C1, numsteps);
      break;
    case HK332:
      hk332_2::FastMatmul(A, B, C1, numsteps);
      break;
    default:
      std::cout << "Unknown algorithm type!" << std::endl;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    times[trial] = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
  }
  // Spit out the median time
  std::sort(times.begin(), times.end());
  size_t ind = num_trials / 2 + 1;
  std::cout << " " << m << " " << k << " " << n << " "
            << numsteps << " " << times[ind] << " "
            << "; ..." << std::endl;

  if (run_check) {
    // Test for correctness.
    Matrix<double> C2(m, n);
    Gemm(A, B, C2);
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  }
}

// Runs a set of benchmarks.
void BenchmarkSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
                  std::vector<int>& n_vals, std::vector<int>& numsteps,
                  int algorithm, bool run_check=false) {
  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());
  for (int i = 0; i < m_vals.size(); ++i) {
    for (int curr_numsteps : numsteps) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], curr_numsteps, algorithm, run_check);
    }
  }
}


int main(int argc, char **argv) {
  std::vector<int> numsteps = {0, 1};
  std::vector<int> m_vals = {1200, 2100};
  BenchmarkSet(m_vals, m_vals, m_vals, numsteps, GREY333);
}
