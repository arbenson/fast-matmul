#include "blas.hpp"
#include "linalg.hpp"
#include "mkl.h"
#include "fast424_26_257.hpp"

#include <chrono>
#include <vector>

void GetrfWrap(double *data, int m, int n, int lda, std::vector<int>& pivots) {
  int info;
  dgetrf_(&m, &n, data, &lda, &pivots[0], &info);
  assert(info == 0);
}

void GetrfWrap(float *data, int m, int n, int lda, std::vector<int>& pivots) {
  int info;
  sgetrf_(&m, &n, data, &lda, &pivots[0], &info);
  assert(info == 0);
}

template<typename Scalar>
void LU(Matrix<Scalar>& A, std::vector<int>& pivots) {
  assert(A.m() > 0 && A.n() > 0);
  int m = A.m();
  int n = A.n();
  pivots.resize(n);
  int lda = A.stride();
  Scalar *data = A.data();
  GetrfWrap(data, m, n, lda, pivots);
  // Convert back to C++ zero-indexing
  for (int i = 0; i < pivots.size(); ++i) {
	pivots[i] -= 1;
  }
}

template<typename Scalar>
void Pivot(Matrix<Scalar>& A, std::vector<int>& pivots) {
  Scalar *data = A.data();
  int stride = A.stride();
  for (int j = 0; j < A.n(); ++j) {
	for (int i = 0; i < pivots.size(); ++i) {
	  // Swap rows i and pivots[i]
	  int pivot_row = pivots[i];
	  Scalar aij = data[i + j * stride];
	  data[i + j * stride] = data[pivot_row + j * stride];
	  data[pivot_row + j * stride] = aij;
	}
  }
}


template<typename Scalar>
void FastLU(Matrix<Scalar>& A, int blocksize) {
  std::vector<int> all_pivots(A.m());
  for (int i = 0; i < A.m() && A.m() - i >= blocksize; i += blocksize) {
	Matrix<double> Panel = A.Submatrix(i, i, A.m() - i, blocksize);
	std::vector<int> pivots;
	LU(Panel, pivots);
	Pivot(A, pivots);

	Matrix<double> L21 = Panel.Submatrix(i, 0, A.m() - i - blocksize, blocksize);
	Matrix<double> A22 = A.Submatrix(i, i, A.m() - i, A.n() - i);
	Matrix<double> A12 = A.Submatrix(0, i, blocksize, A.n() - i);
	// TODO: Need to update and multiply by negative one, not just overwrite
	grey424_26_257::FastMatmul(L21, A12, A22, 1);
	// Append pivots
	for (int j = i; j < i + blocksize; ++j) {
	  all_pivots[j] = pivots[j - i];
	}
  }

  // Now deal with the leftovers
  int start_ind = (A.m() / blocksize) * blocksize;
  int num_left = A.m() - start_ind;
  assert(num_left >= A.m());
  if (num_left == 0) {
	return;
  }
  std::vector<int> pivots;
  Matrix<double> A_end = A.Submatrix(start_ind, start_ind, num_left, A.n() - start_ind);
  LU(A_end, pivots);
  for (int j = start_ind; j < A.m(); ++j) {
	all_pivots[j] = pivots[j - start_ind];
  }
}


int main(int argc, char **argv) {
  int n = 10000;
  Matrix<double> A = RandomMatrix<double>(n, n);
  Matrix<double> B = A;

  auto t1 = std::chrono::high_resolution_clock::now();
  std::vector<int> pivots(A.m());
  LU(A, pivots);
  auto t2 = std::chrono::high_resolution_clock::now();  
  std::cout << "Classical LU took "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
			<< " milliseconds"
			<< std::endl;

  auto t3 = std::chrono::high_resolution_clock::now();
  FastLU(B, 1600);
  auto t4 = std::chrono::high_resolution_clock::now();
  std::cout << "Fast LU took "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
			<< " milliseconds"
			<< std::endl;
}
