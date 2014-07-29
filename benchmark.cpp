#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>
#include <vector>

#include "common.hpp"
#include "mkl.h"

// New fast algorithms
#include "fast234_20_144.hpp"
#include "fast243_20_144.hpp"
#include "fast322_11_50.hpp"
#include "fast323_15_103.hpp"
#include "fast323_15_89.hpp"
#include "fast324_20_144.hpp"
#include "fast332_15_103.hpp"
#include "fast333_23_125.hpp"
#include "fast333_23_152.hpp"
#include "fast333_23_221.hpp"
#include "fast342_20_144.hpp"
#include "fast422_14_84.hpp"
#include "fast423_20_144.hpp"
#include "fast424_26_206.hpp"
#include "fast424_26_257.hpp"
#include "fast432_20_144.hpp"
#include "fast433_29_234.hpp"
#include "fast442_26_257.hpp"
#include "fast522_18_99.hpp"

// Other fast algorithms and classical algorithms
#include "bini322.hpp"
#include "classical222.hpp"
#include "classical333.hpp"
#include "hk332_15_94.hpp"
#include "hk323_15_84.hpp"
#include "hk323_15_94.hpp"
#include "smirnov333_23_128.hpp"
#include "smirnov333_23_139.hpp"
#include "smirnov336_40_960.hpp"
#include "strassen.hpp"

// All of the algorithms
enum {
  MKL,
  BINI332,
  CLASSICAL222,
  CLASSICAL333,
  SMIRNOV333_23_128,
  SMIRNOV333_23_139,
  SMIRNOV336_40_960,
  HK332_15_94,
  HK323_15_94,
  HK323_15_84,
  STRASSEN,
  FAST322_11_50,
  FAST323_15_103,
  FAST323_15_89,
  FAST332_15_103,
  FAST333_23_125,
  FAST333_23_152,
  FAST333_23_221,
  FAST432_20_144,
  FAST423_20_144,
  FAST324_20_144,
  FAST342_20_144,
  FAST234_20_144,
  FAST243_20_144,
  FAST422_14_84,
  FAST424_26_257,
  FAST424_26_206,
  FAST433_29_234,
  FAST522_18_99,
};


// Run a single benchmark for multiplying m x k x n with numsteps of recursion.
// To just call GEMM, set numsteps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int numsteps, int algorithm, bool run_check=false) {
  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n);

  // Run a set number of trials and pick the median time.
  int num_trials = 5;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < num_trials; ++trial) {
    auto t1 = std::chrono::high_resolution_clock::now();
    switch (algorithm) {
    case MKL:
      // Just run the classical version with zero steps of recursion.
      classical222_8_24::FastMatmul(A, B, C1, 0);
      break;
    case BINI332:
      bini322::FastMatmul(A, B, C1, numsteps);
      break;
    case CLASSICAL222:
      classical222_8_24::FastMatmul(A, B, C1, numsteps);
      break;
    case CLASSICAL333:
      classical333_27_81::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST322_11_50:
      grey322_11_50::FastMatmul(A, B, C1, numsteps);      
      break;
    case FAST332_15_103:
      grey332_15_103::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST323_15_103:
      grey323_15_103::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST323_15_89:
      grey323_15_103::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST333_23_125:
      grey333_23_125::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST333_23_152:
      grey333_23_152::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST333_23_221:
      grey333_23_221::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST432_20_144:
      grey432_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST423_20_144:
      grey423_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST324_20_144:
      grey324_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST342_20_144:
      grey342_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST234_20_144:
      grey234_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST243_20_144:
      grey243_20_144::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST433_29_234:
      grey433_29_234::FastMatmul(A, B, C1, numsteps);
      break;
    case SMIRNOV333_23_128:
      smirnov333_23_128::FastMatmul(A, B, C1, numsteps);
      break;
    case SMIRNOV333_23_139:
      smirnov333_23_139::FastMatmul(A, B, C1, numsteps);
      break;
    case SMIRNOV336_40_960:
      smirnov336_40_960::FastMatmul(A, B, C1, numsteps);
      break;
    case HK332_15_94:
      hk332_15_94::FastMatmul(A, B, C1, numsteps);
      break;
    case HK323_15_94:
      hk323_15_94::FastMatmul(A, B, C1, numsteps);
      break;
    case HK323_15_84:
      hk323_15_84::FastMatmul(A, B, C1, numsteps);
      break;
    case STRASSEN:
      strassen::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST422_14_84:
      grey422_14_84::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST424_26_257:
      grey424_26_257::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST424_26_206:
      grey424_26_206::FastMatmul(A, B, C1, numsteps);
      break;
    case FAST522_18_99:
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
            << "; ";

  if (run_check) {
    // Test for correctness.
    Matrix<double> C2(m, n);
    Gemm(A, B, C2);
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;
  }
}


std::string Alg2Str(int algorithm) {
  switch (algorithm) {
  case MKL:
    return "MKL";
  case BINI332:
    return "BINI332";
  case CLASSICAL222:
    return "CLASSICAL2x2";
  case CLASSICAL333:
    return "CLASSICAL3x3";
  case FAST322_11_50:
    return "FAST322_11_50";
  case FAST332_15_103:
    return "FAST332_15_103";
  case FAST323_15_103:
    return "FAST323_15_103";
  case FAST323_15_89:
    return "FAST323_15_89";
  case FAST333_23_125:
    return "FAST333_23_125";
  case FAST333_23_152:
    return "FAST333_23_152";
  case FAST333_23_221:
    return "FAST333_23_221";
  case FAST432_20_144:
    return "FAST432_20_144";
  case FAST423_20_144:
    return "FAST423_20_144";
  case FAST324_20_144:
    return "FAST324_20_144";
  case FAST342_20_144:
    return "FAST342_20_144";
  case FAST234_20_144:
    return "FAST234_20_144";
  case FAST243_20_144:
    return "FAST243_20_144";
  case FAST433_29_234:
    return "FAST433_29_234";
  case SMIRNOV333_23_128:
    return "SMIRNOV333_23_128";
  case SMIRNOV333_23_139:
    return "SMIRNOV333_23_139";
  case SMIRNOV336_40_960:
    return "SMIRNOV336_40_960";
  case HK332_15_94:
    return "HK332_15_94";
  case HK323_15_94:
    return "HK323_15_94";
  case HK323_15_84:
    return "HK323_15_84";
  case STRASSEN:
    return "STRASSEN";
  case FAST422_14_84:
    return "FAST422_14_84";
  case FAST424_26_257:
    return "FAST424_26_257";
  case FAST424_26_206:
    return "FAST424_26_206";
  case FAST522_18_99:
    return "FAST522_18_99";
  default:
    throw std::logic_error("Unknown algorithm type!");
  }
}


// Runs a set of benchmarks.
void BenchmarkSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
                  std::vector<int>& n_vals, std::vector<int>& numsteps,
                  int algorithm, bool run_check=false) {

  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());

  for (int i = 0; i < m_vals.size(); ++i) {
    for (int curr_numsteps : numsteps) {
	  std::cout << Alg2Str(algorithm) << "_" << curr_numsteps << std::endl;
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], curr_numsteps, algorithm, run_check);
    }
  }
  std::cout << std::endl << std::endl;
}


void AlgorithmTest(std::vector<int>& n_vals, std::vector<int>& k_vals, std::vector<int>& m_vals,
				   int algorithm) {
  std::cout << Alg2Str(algorithm) << std::endl;
  std::vector<int> num_levels = {1, 2};
  BenchmarkSet(n_vals, n_vals, n_vals, num_levels, algorithm, true);
  BenchmarkSet(n_vals, k_vals, m_vals, num_levels, algorithm, true);
}


// Run a bunch of tests.
void TestSuite() {
  std::vector<int> n_vals = {55, 100, 200, 340, 562, 671, 1000, 1200, 1201, 1300, 1400, 1500, 2000, 2003, 2489, 2765};
  std::vector<int> k_vals = {71, 80,   99, 400, 500, 700, 1000, 1200, 1301, 1400, 1477, 1514, 2020, 2100, 2800, 2900};
  std::vector<int> m_vals = {44, 70,  101, 402, 600, 634, 4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010};

  AlgorithmTest(n_vals, k_vals, m_vals, CLASSICAL222);
  AlgorithmTest(n_vals, k_vals, m_vals, CLASSICAL333);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST322_11_50);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST332_15_103);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST333_23_221);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST432_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST423_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST324_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST342_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST234_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST243_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST422_14_84);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST424_26_257);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST433_29_234);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST522_18_99);
  AlgorithmTest(n_vals, k_vals, m_vals, FAST522_18_99);
  AlgorithmTest(n_vals, k_vals, m_vals, SMIRNOV333_23_139);
  AlgorithmTest(n_vals, k_vals, m_vals, HK332_15_94);
  AlgorithmTest(n_vals, k_vals, m_vals, BINI332);
}

void OuterProductBenchmark() {
  std::vector<int> m_vals;
  for (int i = 1600; i <= 12000; i += 400) {
	m_vals.push_back(i);
  }
  std::vector<int> k_vals(m_vals.size(), 1600);

  std::vector<int> num_levels = {0};
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, MKL);

  num_levels = {1, 2};
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, STRASSEN);
}

void InnerSquareBenchmark() {
  return;
}

void SquareBenchmark() {
  return;
}


int main(int argc, char **argv) {
  TestSuite();
  return 0;
  SquareBenchmark();
  OuterProductBenchmark();
  InnerSquareBenchmark();

}
