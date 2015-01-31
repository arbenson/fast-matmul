/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "common.hpp"
#include "mkl.h"
#include "timing.hpp"

#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <random>
#include <vector>

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

  auto func = [&] {
    for (int i = 0; i < num_trials; ++i) {
      if (type == MANUAL) {
        manual_add(vec1, vec2, m, n);
      } else {
        daxpy_add(vec1, vec2, m, n);
      }
    }
  };

  double time = Time(func);

  delete [] vec1;
  delete [] vec2;

  return time;
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
