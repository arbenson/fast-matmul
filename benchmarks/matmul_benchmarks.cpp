#include "all_algorithms.hpp"
#include "common.hpp"
#include "mkl.h"

#include <algorithm>
#include <stdexcept>
#include <vector>


// Run a single benchmark for multiplying m x k x n with num_steps of recursion.
// To just call GEMM, set num_steps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int num_steps, int algorithm) {
  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n);

  // Run a set number of trials and pick the median time.
  int num_trials = 5;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < num_trials; ++trial) {
    times[trial] = Time([&] { RunAlgorithm(algorithm, A, B, C1, num_steps); });
  }

  // Spit out the median time
  std::sort(times.begin(), times.end());
  size_t ind = num_trials / 2 + 1;
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
	std::cout << Alg2Str(algorithm) << "_" << curr_num_steps << std::endl;
	for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], curr_num_steps, algorithm);
    }
	std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;
}

void SquareBenchmark() {
  std::vector<int> m_vals;
  for (int i = 2000; i <= 6500; i += 500) {
	m_vals.push_back(i);
  }
  std::vector<int> num_levels = {1};
  BenchmarkSet(m_vals, m_vals, m_vals, num_levels, FAST423_20_144);
  return;
}


// (N, k, N) for fixed k ~ 2000
void OuterProductBenchmark() {
  std::vector<int> m_vals;
  for (int i = 2000; i <= 12000; i += 500) {
	m_vals.push_back(i);
  }
  std::vector<int> k_vals(m_vals.size(), 1600);
  std::vector<int> num_levels = {0};
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, MKL);

  num_levels = {1, 2};
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, FAST424_26_257);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, FAST433_29_234);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, FAST323_15_103);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, FAST522_18_99);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, FAST423_20_144);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, STRASSEN);
  BenchmarkSet(m_vals, k_vals, m_vals, num_levels, BINI322);
}


// (N, k, k) for fixed k ~ 2000
void TSSquareBenchmark() {
  std::vector<int> m_vals;
  for (int i = 10000; i <= 18000; i += 500) {
	m_vals.push_back(i);
  }
  std::vector<int> k_vals(m_vals.size(), 2400);

  std::vector<int> num_levels = {0};
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, MKL);

  num_levels = {1, 2};
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, FAST424_26_257);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, FAST433_29_234);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, FAST323_15_103);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, FAST522_18_99);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, FAST423_20_144);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, STRASSEN);
  BenchmarkSet(m_vals, k_vals, k_vals, num_levels, BINI322);
}


int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);
  if (OptExists(opts, "square")) {
	SquareBenchmark();
  }
  if (OptExists(opts, "outer_prod_like")) {
	OuterProductBenchmark();
  }
  if (OptExists(opts, "ts_square_like")) {
	TSSquareBenchmark();
  }
  return 0;
}
