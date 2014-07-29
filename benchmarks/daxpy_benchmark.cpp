#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "common.hpp"
#include "mkl.h"

enum {
  MANUAL=0,
  MKL_DAXPY,
};


void FillRandom(double *vec, int m, int n) {
  for (int j = 0; j < n; ++j) {
	for (int i = 0; i < m; ++i) {
	  vec[i + j * m] = ((double) rand() / RAND_MAX) * 1024;
	}
  }
}

void manual_add(double *vec1, double *vec2, int m, int n) {
  assert(m != n && m > n);
  for (int j = 0; j < n; ++j) {
	for (int i = 0; i < m; ++i) {
	  vec1[i + j * m] += 4.0 * vec2[i + j * m];
	}
  }
}

void daxpy_add(double *vec1, double *vec2, int m, int n) {
  int incx = 1;
  int incy = 1;
  double alpha = 4.0;
  for (int j = 0; j < n; ++j) {
	daxpy_(&m, &alpha, vec2 + j * m, &incx, vec1 + j * m, &incy);
  }
}


double benchmark(int m, int n, int type) {
  double *vec1 = new double[m * n];
  FillRandom(vec1, m, n);
  double *vec2 = new double[m * n];
  FillRandom(vec2, m, n);

  int num_trials = 10;

  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < num_trials; ++i) {
	if (type == MANUAL) {
	  manual_add(vec1, vec2, m, n);
	} else {
	  daxpy_add(vec1, vec2, m, n);
	}
  }
  auto t2 = std::chrono::high_resolution_clock::now();

  delete [] vec1;
  delete [] vec2;

  return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}

void benchmark_all(int m, int n) {
  {
  std::cout << "MANUAL" << std::endl;
  double time = benchmark(m, n, MANUAL);
  std::cout << time << std::endl;
  }

  {
  std::cout << "MKL_DAXPY" << std::endl;
  double time = benchmark(m, n, MKL_DAXPY);
  std::cout << time << std::endl;
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    return -1;
  }
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  benchmark_all(m, n);
  return 0;
}
