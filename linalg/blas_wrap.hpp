#ifndef _BLAS_WRAP_HPP_
#define _BLAS_WRAP_HPP_

#ifdef __INTEL_MKL__
# include "mkl.h"
# include "mkl_types.h"
#endif

#include <functional>
#include <stdexcept>

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

  void dtrmm_(char *side, char *uplo, char *transt, char *diag, int *m, int *n,
              double *alpha, double *T, int *ldt, double *B, int *ldb);
  void strmm_(char *side, char *uplo, char *transt, char *diag, int *m, int *n,
              float *alpha, float *T, int *ldt, float *B, int *ldb);
}


// These are wrappers around blas routines.
namespace blas {
  // This is a wrapper around workspace queries.  The query function takes
  // the work, lwork, and info variables and performs a workspace query.
  // After the query, the work array is allocated.
  template <typename Scalar>
  void WorkspaceQueryAndAlloc(std::function<void (Scalar* &, int&, int&)> query_func,
                              Scalar* &work, int& lwork, int& info) {
    work = new Scalar[1];
    lwork = -1;
    query_func(work, lwork, info);
    if (info != 0) {
      throw std::runtime_error("Bad workspace query");
    }
        
    // Now allocate the work array.
    lwork = static_cast<int>(work[0]);
    delete [] work;
    work = new Scalar[lwork];
  }


  void Trmm(char side, char uplo, char transt, char diag, int m, int n,
            double alpha, double *T, int ldt, double *B, int ldb) {
    dtrmm_(&side, &uplo, &transt, &diag, &m, &n, &alpha, T, &ldt, B, &ldb);
  }


  void Trmm(char side, char uplo, char transt, char diag, int m, int n,
            float alpha, float *T, int ldt, float *B, int ldb) {
    strmm_(&side, &uplo, &transt, &diag, &m, &n, &alpha, T, &ldt, B, &ldb);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
            double alpha, double *A, int lda, double *B, int ldb) {
    dtrsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
            float alpha, float *A, int lda, float *B, int ldb) {
    strsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }

  // Wrapper for dgemm called by templated gemm.
  void Gemm(char transa, char transb, int m, int n, int k, double *A, int lda,
            double *B, int ldb, double *C, int ldc, double alpha, double beta) {
    dgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
  }

  // Wrapper for sgemm called by templated gemm.
  void Gemm(char transa, char transb, int m, int n, int k, float *A, int lda,
            float *B, int ldb, float *C, int ldc, float alpha, float beta) {
    sgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
  }

  // C <-- alpha * A + C
  void Axpy(double *C, double *A, int n, double alpha, int incx, int incy) {
    daxpy_(&n, &alpha, A, &incx, C, &incy);
  }


  // C <-- alpha * A + C
  void Axpy(float *C, float *A, int n, float alpha, int incx, int incy) {
    saxpy_(&n, &alpha, A, &incx, C, &incy);
  }

}  // end namespace blas


#endif  // _BLAS_WRAP_HPP_
