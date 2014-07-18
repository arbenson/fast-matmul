#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <chrono>
#include <random>
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
  std::cout << std::endl << std::endl;
}

// Runs a set of benchmarks.
void BenchmarkSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
                  std::vector<int>& n_vals, int numsteps,
                  int algorithm, bool run_check=false) {
  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());
  for (int i = 0; i < m_vals.size(); ++i) {
	SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], numsteps, algorithm, run_check);
  }
  std::cout << std::endl << std::endl;
}


void AlgorithmTest(std::vector<int>& n_vals, std::vector<int>& k_vals, std::vector<int>& m_vals,
				   std::string output_str, int algorithm) {
  std::cout << output_str << std::endl;
  BenchmarkSet(n_vals, n_vals, n_vals, 1, algorithm, true);
  BenchmarkSet(n_vals, n_vals, n_vals, 2, algorithm, true);
  BenchmarkSet(n_vals, k_vals, m_vals, 1, algorithm, true);
  BenchmarkSet(n_vals, k_vals, m_vals, 2, algorithm, true);
}


void TestSuite() {
  std::vector<int> n_vals = {55, 100, 200, 340, 562, 671, 1000, 1200, 1201, 1300, 1400, 1500, 2000, 2003, 2489, 2765};
  std::vector<int> k_vals = {71, 80,   99, 400, 500, 700, 1000, 1200, 1301, 1400, 1477, 1514, 2020, 2100, 2800, 2900};
  std::vector<int> m_vals = {44, 70,  101, 402, 600, 634, 4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010};

  AlgorithmTest(n_vals, k_vals, m_vals, "Classical (2 x 2 recursive)", CLASSICAL222);
  AlgorithmTest(n_vals, k_vals, m_vals, "Classical (3 x 3 recursive)", CLASSICAL333);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST322_11_50", FAST322_11_50);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST332_15_103", FAST332_15_103);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST333_23_221", FAST333_23_221);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST432_20_144", FAST432_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST423_20_144", FAST423_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST324_20_144", FAST324_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST342_20_144", FAST342_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST234_20_144", FAST234_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST243_20_144", FAST243_20_144);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST422_14_84", FAST422_14_84);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST424_26_257", FAST424_26_257);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST433_29_234", FAST433_29_234);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST522_18_99", FAST522_18_99);
  AlgorithmTest(n_vals, k_vals, m_vals, "FAST522_18_99", FAST522_18_99);
  AlgorithmTest(n_vals, k_vals, m_vals, "SMIRNOV333_23_139", SMIRNOV333_23_139);
  AlgorithmTest(n_vals, k_vals, m_vals, "HK332_15_94", HK332_15_94);
  AlgorithmTest(n_vals, k_vals, m_vals, "BINI332", BINI332);
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




void RectangularBenchmarks() {
  std::vector<int> n0;
  for (int i = 200; i <= 2000; i += 10) {
	n0.push_back(i);
  }

  std::vector<int> m_vals, n_vals;
  GetDims(n0, 5, 1, m_vals);
  GetDims(n0, 2, 1, n_vals);

  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, n_vals, n_vals, 0, MKL);
  std::cout << "FAST522_18_99" << std::endl;
  BenchmarkSet(m_vals, n_vals, n_vals, 1, FAST522_18_99);
}


void OuterProductBenchmark() {
  std::vector<int> m_vals;
  for (int i = 1600; i <= 12000; i += 400) {
	m_vals.push_back(i);
  }
  std::vector<int> k_vals(m_vals.size(), 1600);

#if 0
  std::cout << "MKL" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 0, MKL);

  std::cout << "STRASSEN_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, STRASSEN);
  std::cout << "STRASSEN_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, STRASSEN);

  std::cout << "FAST323_15_103_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, FAST323_15_103);
  std::cout << "FAST323_15_103_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, FAST323_15_103);

  std::cout << "FAST323_15_89_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, FAST323_15_89);
  std::cout << "FAST323_15_89_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, FAST323_15_89);

  std::cout << "HK323_15_94_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, HK323_15_94);
  std::cout << "HK323_15_94_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, HK323_15_94);

  std::cout << "HK323_15_84_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, HK323_15_84);
  std::cout << "HK323_15_84_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, HK323_15_84);
#endif

#if 0
  std::cout << "FAST424_26_257_lm_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, FAST424_26_257_lm);

  std::cout << "FAST424_26_257_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, FAST424_26_257);

  std::cout << "FAST424_26_257_lm_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, FAST424_26_257_lm);

  std::cout << "FAST424_26_257_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, FAST424_26_257);
#endif

#if 0
  std::cout << "FAST424_26_206_1" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 1, FAST424_26_206);
  std::cout << "FAST424_26_206_2" << std::endl;
  BenchmarkSet(m_vals, k_vals, m_vals, 2, FAST424_26_206);
#endif
}

void DgemmCurve() {
  std::vector<int> n0;
  for (int i = 200; i <= 4000; i += 20) {
	n0.push_back(i);
  }
  std::cout << "MKL" << std::endl;
  BenchmarkSet(n0, n0, n0, 0, MKL);
}


void ShortFatSquareBenchmark() {
  std::vector<int> k_vals;
  for (int i = 8000; i <= 12000; i += 100) {
	k_vals.push_back(i);
  }

  std::vector<int> m_vals(k_vals.size(), 1200);
}


void SquareBenchmark(int which) {
  std::vector<int> dim;
  for (int i = 2000; i <= 7600; i += 400) {
	dim.push_back(i);
  }
#if 0
    std::cout << "FAST333_23_152_lm_1" << std::endl;
    BenchmarkSet(dim, dim, dim, 1, FAST333_23_152_lm);

    std::cout << "FAST333_23_152_1" << std::endl;
    BenchmarkSet(dim, dim, dim, 1, FAST333_23_152);

    std::cout << "FAST333_23_152_lm_2" << std::endl;
    BenchmarkSet(dim, dim, dim, 2, FAST333_23_152_lm);

    std::cout << "FAST333_23_152_2" << std::endl;
    BenchmarkSet(dim, dim, dim, 2, FAST333_23_152);
#endif
}



int main(int argc, char **argv) {
  TestSuite();
  return 0;
  int which = atoi(argv[1]);
  if (which == 0) {
	OuterProductBenchmark();
  } else {
	SquareBenchmark(which);
  }
}
