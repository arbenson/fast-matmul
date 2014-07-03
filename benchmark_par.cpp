#include "common.hpp"
#include "mkl.h"
#include "omp.h"

#include "bini322.hpp"
#include "classical222.hpp"
#include "classical333.hpp"
#include "smirnov-fast333.hpp"
#include "grey-fast234.hpp"
#include "grey-fast243.hpp"
#include "grey-fast322.hpp"
#include "grey-fast324.hpp"
#include "grey-fast323.hpp"
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
  SMIRNOV333,
  HK332,
  STRASSEN,
  GREY322,
  GREY323,
  GREY332,
  GREY333,
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
    case GREY323:
	grey323_15_103::FastMatmul(A, B, C1, numsteps);
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
  std::cout << std::endl;
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
  std::cout << std::endl;
  for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], numsteps, algorithm, run_check);
  }
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
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY322", GREY322);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY332", GREY332);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY333", GREY333);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY432", GREY432);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY423", GREY423);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY324", GREY324);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY342", GREY342);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY234", GREY234);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY243", GREY243);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY422", GREY422);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY424", GREY424);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY433", GREY433);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY522", GREY522);
  AlgorithmTest(n_vals, k_vals, m_vals, "GREY522", GREY522);
  AlgorithmTest(n_vals, k_vals, m_vals, "SMIRNOV333", SMIRNOV333);
  AlgorithmTest(n_vals, k_vals, m_vals, "HK332", HK332);
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
  BenchmarkSet(m_vals, n_vals, n_vals, 0, CLASSICAL222);
  std::cout << "GREY522" << std::endl;
  BenchmarkSet(m_vals, n_vals, n_vals, 1, GREY522);
}


void OuterProductBenchmark() {
  std::vector<int> n0;
  for (int i = 2000; i <= 10000; i += 100) {
	n0.push_back(i);
  }
  std::vector<int> k_vals(n0.size(), 2000);

  std::cout << "MKL" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 0, CLASSICAL222);
  std::cout << "GREY424 (1)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 1, GREY424);
  std::cout << "GREY424 (2)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 2, GREY424);
  std::cout << "STRASSEN (1)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 1, STRASSEN);
  std::cout << "STRASSEN (2)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 2, STRASSEN);
  std::cout << "GREY323 (1)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 1, GREY323);
  std::cout << "GREY323 (2)" << std::endl;
  BenchmarkSet(n0, k_vals, n0, 2, GREY323);
}

void DgemmCurve() {
  std::vector<int> n0;
  for (int i = 200; i <= 4000; i += 20) {
	n0.push_back(i);
  }
  std::cout << "MKL" << std::endl;
  BenchmarkSet(n0, n0, n0, 0, CLASSICAL222);
}

void SquareBenchmark() {
  std::vector<int> dim;
  for (int i = 2000; i <= 8000; i += 100) {
	dim.push_back(i);
  }
  std::cout << "MKL" << std::endl;
  BenchmarkSet(dim, dim, dim, 0, CLASSICAL222);
  std::cout << "STRASSEN (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, STRASSEN);
  std::cout << "STRASSEN (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, STRASSEN);
  std::cout << "SMIRNOV333 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, SMIRNOV333);
  std::cout << "SMIRNOV333 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, SMIRNOV333);
  std::cout << "GREY422 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY422);
  std::cout << "GREY422 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY422);
  std::cout << "GREY522 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY522);
  std::cout << "GREY522 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY522);
  std::cout << "GREY234 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY234);
  std::cout << "GREY234 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY234);
  std::cout << "GREY433 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY433);
  std::cout << "GREY433 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY433);
  std::cout << "BINI322 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, BINI332);
  std::cout << "BINI332 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, BINI332);
  std::cout << "GREY333 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY333);
  std::cout << "GREY333 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY333);
  std::cout << "CLASSICAL222 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, CLASSICAL222);
  std::cout << "CLASSICAL222 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, CLASSICAL222);
  std::cout << "GREY332 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY332);
  std::cout << "GREY332 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY332);
  std::cout << "GREY322 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, GREY322);
  std::cout << "GREY322 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, GREY322);
  std::cout << "HK332 (1)" << std::endl;
  BenchmarkSet(dim, dim, dim, 1, HK332);
  std::cout << "HK332 (2)" << std::endl;
  BenchmarkSet(dim, dim, dim, 2, HK332);
}



int main(int argc, char **argv) {
    mkl_set_num_threads(16);
    omp_set_num_threads(16);

    int which = atoi(argv[1]);
    if (which == 0) {
	OuterProductBenchmark();
    } else {
	SquareBenchmark();
    }
}
