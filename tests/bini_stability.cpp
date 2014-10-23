#include "linalg.hpp"
#include "bini322.hpp"
#include "float.h"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 90;
  int k = 80;
  int n = 80;
  int numsteps = 2;

  Matrix<double> A = RandomMatrix<double>(m, k);
  Matrix<double> B = RandomMatrix<double>(k, n);
  Matrix<double> C1(m, n), C2(m, n);
  MatMul(A, B, C1);

  for (int numsteps = 1; numsteps <= 2; ++numsteps) {
	double lambda = DBL_EPSILON;
	std::cout << numsteps << std::endl;
	while (lambda < 1) {
	  bini322::FastMatmul(A, B, C2, numsteps, lambda);
	  std::cout << lambda << ", " << MaxRelativeDiff(C1, C2) << "; ";
	  lambda *= 2;
	}
	std::cout << std::endl;
  }

  return 0;
}
