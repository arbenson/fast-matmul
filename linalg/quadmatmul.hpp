#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define BLOCK_SIZE (64)

void QuadMatmul(Matrix<double>& A, Matrix<double>& B, Matrix<__float128>& C) {
  int m = C.m();
  int n = C.n();
  int k = A.n();

  // Zero out C
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      C(i, j) = (__float128) 0;
    }
  }

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      for (int l = 0; l < k; ++l) {
	C(i, j) += (__float128) A(i, l) * (__float128) B(l, j);	
      }
    }
  }

#if 0    
  for (int jj = 0; jj < n / BLOCK_SIZE; ++jj) {
    for (int ii = 0; ii < m / BLOCK_SIZE; ++ii) {
      for (int ll = 0; ll < k / BLOCK_SIZE; ++ll) {
	for (int j = jj * BLOCK_SIZE; j < (jj + 1) * BLOCK_SIZE; ++j) {
	  for (int i = ii * BLOCK_SIZE; i < (ii + 1) * BLOCK_SIZE; ++i) {
	    #pragma unroll
	    for (int l = ll * BLOCK_SIZE; l < (ll + 1) * BLOCK_SIZE; ++l) {
	      C(i, j) += (__float128) A(i, l) * (__float128) B(l, j);
	    }
	  }
	}
      }
    }
  }

  // Cover the extra (i, j)
  for (int j = (n / BLOCK_SIZE) * BLOCK_SIZE; j < n; ++j) {
    for (int i = (m / BLOCK_SIZE) * BLOCK_SIZE; i < m; ++i) {
      for (int l  = 0; l < k; ++l) {
	C(i, j) += (__float128) A(i, l) * (__float128) B(l, k);
      }
    }
  }

  // Cover the extra inner dimension
  for (int j = 0; j < (n / BLOCK_SIZE) * BLOCK_SIZE; ++j) {
    for (int i = 0; i < (m / BLOCK_SIZE) * BLOCK_SIZE; ++i) {
      for (int l  = (k / BLOCK_SIZE) * BLOCK_SIZE; l < k; ++l) {
	C(i, j) += (__float128) A(i, l) * (__float128) B(l, j);
      }
    }
  }
#endif
}
