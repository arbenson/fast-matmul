#ifndef _BLAS_HPP_
#define _BLAS_HPP_

extern "C" {
  void dgemm_(char *transa, char *transb, int *m, int *n, int *k,
			  double *alpha, double *a, int *lda, double *b, int *ldb,
			  double *beta, double *c, int *ldc);
  void sgemm_(char *transa, char *transb, int *m, int *n, int *k,
			  float *alpha, float *a, int *lda, float *b, int *ldb,
			  float *beta, float *c, int *ldc);

  void daxpy_(int *n, double *alpha, double *A, int *incx, double *C, int *incy);
  void saxpy_(int *n, float *alpha, float *A, int *incx, float *C, int *incy);

  void dtrsm_(char *side, char *uplo, char *transa, char *diag, int *m, int *n,
			  double *alpha, double *A, int *lda, double *B, int *ldb);
  void strsm_(char *side, char *uplo, char *transa, char *diag, int *m, int *n,
			  float *alpha, float *A, int *lda, float *B, int *ldb);


  //  void dlaswp_(int *N, double *A, int *lda, int *K1, int *K2, int *ipiv, int *incx);
  //  void slaswp_(int *N, float *A, int *lda, int *K1, int *K2, int *ipiv, int *incx);
}

#endif  // _BLAS_HPP_
