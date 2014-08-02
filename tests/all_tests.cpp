#include <stdexcept>
#include <vector>

#include "all_algorithms.hpp"
#include "common.hpp"
#include "mkl.h"

// Run the fast algorithm and standard GEMM and print out the maximum relative
// difference between the two algorithms.
void SingleTest(int m, int k, int n, int num_steps, int algorithm) {
  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);
  RunAlgorithm(algorithm, A, B, C1, num_steps);
  Gemm(A, B, C2);
  std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;  
}

// Runs a set of tests.
void TestSet(std::vector<int>& m_vals, std::vector<int>& k_vals,
			 std::vector<int>& n_vals, int algorithm) {
  std::vector<int> num_steps = {1, 2, 3};
  for (int curr_num_steps : num_steps) {
	for (int i = 0; i < m_vals.size(); ++i) {
	  std::cout << Alg2Str(algorithm) << "_" << curr_num_steps
				<< ": " << m_vals[i] << ", " << k_vals[i]
				<< ", " << n_vals[i] << std::endl;
	  SingleTest(m_vals[i], k_vals[i], n_vals[i], curr_num_steps, algorithm);
	}
  }
}


// Run all of the tests.
void TestSuite() {
  std::vector<int> m_vals = {44, 70,  101, 402, 600, 634, 4001, 4002, 4003,
							 4004, 4005, 4006, 4007, 4008, 4009, 4010};
  std::vector<int> k_vals = {71, 80,   99, 400, 500, 700, 1000, 1200, 1301,
							 1400, 1477, 1514, 2020, 2100, 2800, 2900};
  std::vector<int> n_vals = {55, 100, 200, 340, 562, 671, 1000, 1200, 1201,
							 1300, 1400, 1500, 2000, 2003, 2489, 2765};

  TestSet(m_vals, k_vals, n_vals, CLASSICAL222);
  TestSet(m_vals, k_vals, n_vals, CLASSICAL333);
  TestSet(m_vals, k_vals, n_vals, FAST322_11_50);
  TestSet(m_vals, k_vals, n_vals, FAST332_15_103);
  TestSet(m_vals, k_vals, n_vals, FAST323_15_103);
  TestSet(m_vals, k_vals, n_vals, FAST323_15_89);
  TestSet(m_vals, k_vals, n_vals, FAST333_23_125);
  TestSet(m_vals, k_vals, n_vals, FAST333_23_152);
  TestSet(m_vals, k_vals, n_vals, FAST333_23_221);
  TestSet(m_vals, k_vals, n_vals, FAST432_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST423_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST324_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST342_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST234_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST243_20_144);
  TestSet(m_vals, k_vals, n_vals, FAST422_14_84);
  TestSet(m_vals, k_vals, n_vals, FAST424_26_257);
  TestSet(m_vals, k_vals, n_vals, FAST424_26_206);
  TestSet(m_vals, k_vals, n_vals, FAST433_29_234);
  TestSet(m_vals, k_vals, n_vals, FAST522_18_99);
  TestSet(m_vals, k_vals, n_vals, SMIRNOV333_23_128);
  TestSet(m_vals, k_vals, n_vals, SMIRNOV333_23_139);
  TestSet(m_vals, k_vals, n_vals, HK332_15_94);
  TestSet(m_vals, k_vals, n_vals, HK323_15_84);
  TestSet(m_vals, k_vals, n_vals, BINI332);
}

int main(int argc, char **argv) {
  TestSuite();
  return 0;
}
