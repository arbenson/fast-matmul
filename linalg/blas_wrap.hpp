/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#ifndef _BLAS_WRAP_HPP_
#define _BLAS_WRAP_HPP_

#include "common.hpp"

#ifdef __INTEL_MKL__
# include "mkl.h"
# include "mkl_types.h"
#endif

#include <functional>
#include <stdexcept>

#if defined(BLAS_POST)
# define BLAS_NAME(name) name ## _
#else
# define BLAS_NAME(name) name
#endif

extern "C" {
  void BLAS_NAME(dgemm) (char *transa, char *transb, int *m, int *n, int *k,
                         double *alpha, double *a, int *lda, double *b,
                         int *ldb, double *beta, double *c, int *ldc);
  void BLAS_NAME(sgemm) (char *transa, char *transb, int *m, int *n, int *k,
                         float *alpha, float *a, int *lda, float *b, int *ldb,
                         float *beta, float *c, int *ldc);

  void BLAS_NAME(daxpy) (int *n, double *alpha, double *A, int *incx, double *C,
                         int *incy);
  void BLAS_NAME(saxpy) (int *n, float *alpha, float *A, int *incx, float *C,
                         int *incy);

  void BLAS_NAME(dtrsm) (char *side, char *uplo, char *transa, char *diag,
                         int *m, int *n, double *alpha, double *A, int *lda,
                         double *B, int *ldb);
  void BLAS_NAME(strsm) (char *side, char *uplo, char *transa, char *diag,
                         int *m, int *n, float *alpha, float *A, int *lda,
                         float *B, int *ldb);

  void BLAS_NAME(dtrmm) (char *side, char *uplo, char *transt, char *diag,
                         int *m, int *n, double *alpha, double *T, int *ldt,
                         double *B, int *ldb);
  void BLAS_NAME(strmm) (char *side, char *uplo, char *transt, char *diag,
                         int *m, int *n, float *alpha, float *T, int *ldt,
                         float *B, int *ldb);

  double BLAS_NAME(dlange) (char *norm, int *m, int *n, double *A, int *lda,
                            double *work);
  float BLAS_NAME(slange) (char *norm, int *m, int *n, float *A, int *lda,
                           float *work);
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
    BLAS_NAME(dtrmm) (&side, &uplo, &transt, &diag, &m, &n, &alpha, T, &ldt, B, &ldb);
  }


  void Trmm(char side, char uplo, char transt, char diag, int m, int n,
            float alpha, float *T, int ldt, float *B, int ldb) {
    BLAS_NAME(strmm) (&side, &uplo, &transt, &diag, &m, &n, &alpha, T, &ldt, B, &ldb);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
            double alpha, double *A, int lda, double *B, int ldb) {
    BLAS_NAME(dtrsm) (&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
            float alpha, float *A, int lda, float *B, int ldb) {
    BLAS_NAME(strsm) (&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }

  // Wrapper for dgemm called by templated gemm.
  void Gemm(char transa, char transb, int m, int n, int k, double *A, int lda,
            double *B, int ldb, double *C, int ldc, double alpha, double beta) {
    BLAS_NAME(dgemm) (&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
                      C, &ldc);
  }

  // Wrapper for sgemm called by templated gemm.
  void Gemm(char transa, char transb, int m, int n, int k, float *A, int lda,
            float *B, int ldb, float *C, int ldc, float alpha, float beta) {
    BLAS_NAME(sgemm) (&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
                      C, &ldc);
  }

  // C <-- alpha * A + C
  void Axpy(double *C, double *A, int n, double alpha, int incx, int incy) {
    BLAS_NAME(daxpy) (&n, &alpha, A, &incx, C, &incy);
  }


  // C <-- alpha * A + C
  void Axpy(float *C, float *A, int n, float alpha, int incx, int incy) {
    BLAS_NAME(saxpy) (&n, &alpha, A, &incx, C, &incy);
  }

  double Lange(char norm, int m, int n, double *A, int lda) {
    double *work = NULL;
    // Only need workspace for the infinity norm.
    bool is_inf_norm = (norm == 'I' || norm == 'i');
    if (is_inf_norm) {
      work = new double[m];
    }
    double ret = BLAS_NAME(dlange) (&norm, &m, &n, A, &lda, work);
    if (is_inf_norm) {
      delete [] work;
    }
    return ret;
  }

  float Lange (char norm, int m, int n, float *A, int lda) {
    float *work = NULL;
    // Only need workspace for the infinity norm.
    bool is_inf_norm = (norm == 'I' || norm == 'i');
    if (is_inf_norm) {
      work = new float[m];
    }
    float ret = BLAS_NAME(slange) (&norm, &m, &n, A, &lda, work);
    if (is_inf_norm) {
      delete [] work;
    }
    return ret;
  }
}  // end namespace blas


#endif  // _BLAS_WRAP_HPP_
