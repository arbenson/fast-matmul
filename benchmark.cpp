#include "common.hpp"
#include "mkl.h"

#include "bini322.hpp"
#include "classical222.hpp"
#include "classical333.hpp"
#include "smirnov-fast333.hpp"
#include "grey-fast234.hpp"
#include "grey-fast243.hpp"
#include "grey-fast322.hpp"
#include "grey-fast324.hpp"
#include "grey-fast332.hpp"
#include "grey-fast333.hpp"
#include "grey-fast342.hpp"
#include "grey-fast423.hpp"
#include "grey-fast432.hpp"
#include "grey-fast422.hpp"
#include "grey-fast424.hpp"
#include "grey-fast433.hpp"
#include "grey-fast522.hpp"
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
  CLASSICAL222,
  CLASSICAL333,
  GREY322,
  GREY332,
  GREY333,
  SMIRNOV333,
  GREY432,
  GREY423,
  GREY324,
  GREY342,
  GREY234,
  GREY243,
  GREY422,
  GREY424,
  GREY433,
  GREY522,
  HK332,
  STRASSEN,
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
    case CLASSICAL222:
      classical222_8_24::FastMatmul(A, B, C1, numsteps);
      break;
    case CLASSICAL333:
      classical333_27_81::FastMatmul(A, B, C1, numsteps);
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
	case SMIRNOV333:
	  smirnov333_23_139::FastMatmul(A, B, C1, numsteps);
	  break;
    case HK332:
      hk332_2::FastMatmul(A, B, C1, numsteps);
      break;
    case STRASSEN:
      strassen::FastMatmul(A, B, C1, numsteps);
      break;
	case GREY422:
      grey422_14_84::FastMatmul(A, B, C1, numsteps);
	  break;
	case GREY424:
      grey424_26_257::FastMatmul(A, B, C1, numsteps);
	  break;
	case GREY522:
	  grey522_18_99::FastMatmul(A, B, C1, numsteps);
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

// Runs a set of benchmarks.
void BenchmarkSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
                  std::vector<int>& n_vals, int numsteps,
                  int algorithm, bool run_check=false) {
  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());
  for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], numsteps, algorithm, run_check);
  }
}

void GetDims(std::vector<int>& n0, int rec_size, int num_steps, std::vector<int>& vals) {
  vals.clear();
  for (int curr_n0 : n0) {
	int tmp_num_steps = num_steps;
	while (tmp_num_steps > 0) {
	  curr_n0 *= rec_size;
	  --tmp_num_steps;
	}
	vals.push_back(curr_n0);
  }
}

void SquareBenchmarks() {
  std::vector<int> n0;
  for (int i = 100; i <= 1600; i += 10) {
	n0.push_back(i);
  }

  mkl_set_num_threads(16);
  std::vector<int> m_vals;
  GetDims(n0, 2, 2, m_vals);
  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, m_vals, m_vals, 0, CLASSICAL222);

#if 0
  for (int num_steps = 1; num_steps <= 3; ++num_steps) {
	std::cout << "Classical (recursive) " << num_steps << std::endl;
	BenchmarkSet(m_vals, m_vals, m_vals, num_steps, CLASSICAL222);
	std::cout << "Strassen " << num_steps << std::endl;
	BenchmarkSet(m_vals, m_vals, m_vals, num_steps, STRASSEN);
  }
#endif

  n0.clear();
  for (int i = 50; i <= 700; i += 10) {
	n0.push_back(i);
  }
  GetDims(n0, 3, 2, m_vals);

  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, m_vals, m_vals, 0, CLASSICAL333);

#if 0
  for (int num_steps = 1; num_steps <= 2; ++num_steps) {
	std::cout << "GREY333" << std::endl;
	BenchmarkSet(m_vals, m_vals, m_vals, num_steps, GREY333);
  }
#endif
}


void RectangularBenchmarks() {
  std::vector<int> n0;
  for (int i = 200; i <= 2000; i += 10) {
	n0.push_back(i);
  }

  std::vector<int> m_vals, n_vals;
  GetDims(n0, 5, 1, m_vals);
  GetDims(n0, 2, 1, n_vals);

  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, n_vals, n_vals, 0, CLASSICAL222);
  std::cout << "GREY522" << std::endl;
  BenchmarkSet(m_vals, n_vals, n_vals, 1, GREY522);
}


void OuterProductBenchmark() {
  std::vector<int> n0;
  for (int i = 500; i <= 1500; i += 25) {
	n0.push_back(i);
  }
  std::vector<int> m_vals;
  GetDims(n0, 4, 1, m_vals);
  std::vector<int> k_vals(m_vals.size(), 1000);

  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 0, CLASSICAL222);
  std::cout << "GREY424" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, GREY424);
}


int main(int argc, char **argv) {
  OuterProductBenchmark();
}
