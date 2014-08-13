#include "linalg.hpp"
#include "timing.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

// This code does timings for the dgemm curves.
// Run with:
//   ./dgemm_curves TYPE [NO_DYNAMIC]
//
// TYPE is 1, 2, or 3, corresponding to square, outer product, or inner-square
// matrix multiple.  If NO_DYNAMIC is provided, then no dynamic MKL thread
// allocation use (MKL will always use the maximum number of threads).

enum {
  SQUARE=1,
  OUTER_PRODUCT=2,
  INNER_SQUARE=3,
};

// Run a single timing test.  The output is
//    M K N NUM_TRIALS TIME
//
// where (M, K, N) is the matrix multiplication dimensions, NUM_TRIALS
// is the number of trials used for timing, and TIME is the time to do
// NUM_TRIALS matrix multiplies.
void RunSingleTest(Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
#ifdef _PARALLEL_
  mkl_set_num_threads(mkl_get_max_threads());
#endif

  int num_trials = 5;
  auto func = [&] {
	for (int trial = 0; trial < num_trials; ++trial) {
	  MatMul(A, B, C);
	}
  };
  double time = Time(func);
  
  std::cout << " " << A.m() << " " << A.n() << " " << B.n()
	    << " " << num_trials << " " << time << ";";
}


// Run the timing tests for all dimensions.  The "type" is either
// SQUARE, OUTER_PRODUCT, or INNER_SQUARE, corresponding to
// (N, N, N), (N, N / 4, N), or (N / 4, N, N) computations.
void RunAllDimensions(int type) {
  std::vector<int> N_vals;
#ifdef _PARALLEL_
  for (int i = 200; i <= 9000; i += 100) {
    N_vals.push_back(i);
  }
#else
  for (int i = 20; i <= 2500; i += 20) {
    N_vals.push_back(i);
  }
#endif

  Matrix<double> A, B, C;
  for (int N : N_vals) {
	switch (type) {
	case SQUARE:
	  A = RandomMatrix<double>(N, N);
	  B = RandomMatrix<double>(N, N);
	  C = Matrix<double>(N, N);
	  break;

	case OUTER_PRODUCT:
	  A = RandomMatrix<double>(N, N / 4);
	  B = RandomMatrix<double>(N / 4, N);
	  C = Matrix<double>(N, N);
	  break;

	case INNER_SQUARE:
	  A = RandomMatrix<double>(N / 4, N);
	  B = RandomMatrix<double>(N, N);
	  C = Matrix<double>(N / 4, N);
	  break;

	default:
	  throw std::invalid_argument("Incorrect type option");
	  break;
	}
    RunSingleTest(A, B, C);
    if (!(N % 1000)) {
      std::cout << "..." << std::endl;
    }	
  }
}


int main(int argc, char **argv) {
  if (argc < 2) {
	std::cout << "Usage: ./dgemm_curves TYPE [NO_DYNAMIC]" << std::endl;
	return -1;
  }
  if (argc > 2) {
    std::cout << "no dynamic MKL" << std::endl;
    mkl_set_dynamic(0);
  }
  int type = atoi(argv[1]);
  RunAllDimensions(type);
  return 0;
}
