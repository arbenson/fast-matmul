#include "common.hpp"
#include "linalg.hpp"
#include "mkl.h"

#include "special/fast424_26_206_pw.hpp"
#include "special/fast424_26_206_st.hpp"
#include "special/fast424_26_206_wo.hpp"
#include "special/fast424_26_257_pw.hpp"
#include "special/fast424_26_257_st.hpp"
#include "special/fast424_26_257_wo.hpp"
#include "special/fast423_20_121_pw.hpp"
#include "special/fast423_20_121_st.hpp"
#include "special/fast423_20_121_wo.hpp"
#include "special/fast423_20_144_pw.hpp"
#include "special/fast423_20_144_st.hpp"
#include "special/fast423_20_144_wo.hpp"

#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>


enum {
  FAST424_26=0,
  FAST423_20,
};


enum {
  WRITE_ONCE=0,
  STREAMING,
  PAIRWISE,
};


typedef decltype(fast424_26_206_wo::FastMatmul<double>) *matmul_func;

// Get around default arguments with this function.
void FastMatmulShim(Matrix<double>& A, Matrix<double>& B, Matrix<double>& C,
                    int num_steps, matmul_func func) {
  func(A, B, C, num_steps, 1e-8, 1.0, 0.0);
}


matmul_func GetAlgFunction(int algorithm, int add_type, bool use_cse) {
  switch (algorithm) {
  case FAST424_26:
    switch (add_type) {
    case WRITE_ONCE:
      if (use_cse) {
        return fast424_26_206_wo::FastMatmul<double>;
      } else {
        return fast424_26_257_wo::FastMatmul<double>;
      }
      break;

    case STREAMING:
      if (use_cse) {
        return fast424_26_206_st::FastMatmul<double>;
      } else {
        return fast424_26_257_st::FastMatmul<double>;
      }
      break;

    case PAIRWISE:
      if (use_cse) {
        return fast424_26_206_pw::FastMatmul<double>;
      } else {
        return fast424_26_257_pw::FastMatmul<double>;
      }
      break;
    default:
      throw std::logic_error("Unknown addition type");
    }
    break;

  case FAST423_20:
    switch (add_type) {
    case WRITE_ONCE:
      if (use_cse) {
        return fast423_20_121_wo::FastMatmul<double>;
      } else {
        return fast423_20_144_wo::FastMatmul<double>;
      }
      break;

    case STREAMING:
      if (use_cse) {
        return fast423_20_121_st::FastMatmul<double>;
      } else {
        return fast423_20_144_st::FastMatmul<double>;
      }
      break;

    case PAIRWISE:
      if (use_cse) {
        return fast423_20_121_pw::FastMatmul<double>;
      } else {
        return fast423_20_144_pw::FastMatmul<double>;
      }
      break;
    default:
      throw std::logic_error("Unknown addition type");
    }
    break;
  default:
    throw std::logic_error("Unknown algorithm");
  }
}


std::string Alg2Str(int algorithm, int add_type, bool use_cse) {
  std::string alg_str, add_type_str, use_cse_str;
  switch (algorithm) {
  case FAST424_26:
    alg_str = "FAST424_26";
    break;
  case FAST423_20:
    alg_str = "FAST423_20";
    break;
  default:
    throw std::logic_error("Unknown algorithm");
  }
  
  switch (add_type) {
  case WRITE_ONCE:
    add_type_str = "WO";
    break;
  case STREAMING:
    add_type_str = "ST";
    break;
  case PAIRWISE:
    add_type_str = "PW";
    break;
  default:
    throw std::logic_error("Unknown addition type");
  }
  
  if (use_cse) {
    use_cse_str = "YES_CSE";
  } else {
    use_cse_str = "NO_CSE";
  }
  
  return alg_str + "_" + add_type_str + "_" + use_cse_str;
}


// Run a single benchmark for multiplying m x k x n with num_steps of recursion.
// To just call GEMM, set num_steps to zero.
// The median of five trials is printed to std::cout.
// If run_check is true, then it also
void SingleBenchmark(int m, int k, int n, int num_steps, matmul_func func) {
  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C(m, n);

  // Run a set number of trials and pick the median time.
  int num_trials = 3;
  std::vector<double> times(num_trials);
  for (int trial = 0; trial < num_trials; ++trial) {
    times[trial] = Time([&] { FastMatmulShim(A, B, C, num_steps, func); });
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
                  std::vector<int>& n_vals, int num_steps,
                  int algorithm) {
  assert(m_vals.size() == k_vals.size() && k_vals.size() == n_vals.size());
  {
    auto func = GetAlgFunction(algorithm, WRITE_ONCE, false);
    std::cout << Alg2Str(algorithm, WRITE_ONCE, false) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }
  {
    auto func = GetAlgFunction(algorithm, WRITE_ONCE, true);
    std::cout << Alg2Str(algorithm, WRITE_ONCE, true) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }


  {
    auto func = GetAlgFunction(algorithm, STREAMING, false);
    std::cout << Alg2Str(algorithm, STREAMING, false) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }
  {
    auto func = GetAlgFunction(algorithm, STREAMING, true);
    std::cout << Alg2Str(algorithm, STREAMING, true) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }


  {
    auto func = GetAlgFunction(algorithm, PAIRWISE, false);
    std::cout << Alg2Str(algorithm, PAIRWISE, false) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }
  {
    auto func = GetAlgFunction(algorithm, PAIRWISE, true);
    std::cout << Alg2Str(algorithm, PAIRWISE, true) << "_" << num_steps << std::endl;
    for (int i = 0; i < m_vals.size(); ++i) {
      SingleBenchmark(m_vals[i], k_vals[i], n_vals[i], num_steps, func);
    }
    std::cout << std::endl;
  }
}


void Benchmark424(int num_steps) {
  std::vector<int> m_vals;
  for (int i = 2000; i <= 9000; i += 500) {
    m_vals.push_back(i);
  }
  std::vector<int> k_vals(m_vals.size(), 1600);
  BenchmarkSet(m_vals, k_vals, m_vals, num_steps, FAST424_26);
}


void Benchmark423(int num_steps) {
  std::vector<int> m_vals;
  for (int i = 2000; i <= 6500; i += 500) {
    m_vals.push_back(i);
  }
  BenchmarkSet(m_vals, m_vals, m_vals, num_steps, FAST423_20);
}


int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);
  int num_steps = GetIntOpt(opts, "424", -1);
  if (num_steps != -1) {
    Benchmark424(num_steps);
  }

  num_steps = GetIntOpt(opts, "423", -1);
  if (num_steps != -1) {
    Benchmark423(num_steps);
  }

  return 0;
}
