#ifndef _LAPACK_WRAP_HPP_
#define _LAPACK_WRAP_HPP_

#include "mkl.h"

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

  //  void dlaswp_(int *N, double *A, int *lda, int *K1, int *K2, int *ipiv, int *incx);
  //  void slaswp_(int *N, float *A, int *lda, int *K1, int *K2, int *ipiv, int *incx);
}


// These are wrappers around lapack routines.
namespace lapack {
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


  void Larft(char direct, char storev, int m, int n, double *V, int ldv,
			 double *tau, double *T, int ldt) {
	dlarft_(&direct, &storev, &m, &n, V, &ldv, tau, T, &ldt);
  }


  void Larft(char direct, char storev, int m, int n, float *V, int ldv,
			 float *tau, float *T, int ldt) {
	slarft_(&direct, &storev, &m, &n, V, &ldv, tau, T, &ldt);
  }


  void Geqrf(int m, int n, float *A, int lda, float *tau) {
	// First perform the workspace query.
	std::function<void (float* &, int&, int&)> query = [&] (float *work,
															int& lwork,
															int& info) {
	  sgeqrf_(&m, &n, A, &lda, tau, work, &lwork, &info);
	};
	float *work;
	int lwork;
	int info;
	WorkspaceQueryAndAlloc(query, work, lwork, info);
  
	// QR routine that does the work.
	sgeqrf_(&m, &n, A, &lda, tau, work, &lwork, &info);  
	if (info != 0) {
	  throw std::runtime_error("Bad sgeqrf_ call");
	}
	delete [] work;
  }


  void Geqrf(int m, int n, double *A, int lda, double *tau) {
	// First perform the workspace query.
	std::function<void (double* &, int&, int&)> query = [&] (double *work,
															 int& lwork,
															 int& info) {
	  dgeqrf_(&m, &n, A, &lda, tau, work, &lwork, &info);
	};
	double *work;
	int lwork;
	int info;
	WorkspaceQueryAndAlloc(query, work, lwork, info);

	// QR routine that does the work.
	dgeqrf_(&m, &n, A, &lda, tau, work, &lwork, &info);  
	if (info != 0) {
	  throw std::runtime_error("Bad dgeqrf_ call");
	}
	delete [] work;
  }


  void Getrf(double *data, int m, int n, int lda, int *pivots) {
	int info;
	dgetrf_(&m, &n, data, &lda, pivots, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad dgetrf_ call");
	}
  }


  void Getrf(float *data, int m, int n, int lda, int *pivots) {
	int info;
	sgetrf_(&m, &n, data, &lda, pivots, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad sgetrf_ call");
	}
  }


  void Laswp(int num_cols, double *data, int lda, int piv_start, int piv_end,
			 int *pivots, int incx) {
	dlaswp_(&num_cols, data, &lda,  &piv_start, &piv_end, pivots, &incx);
  }


  void Laswp(int num_cols, float *data, int lda, int piv_start, int piv_end,
			 int *pivots, int incx) {
	slaswp_(&num_cols, data, &lda,  &piv_start, &piv_end, pivots, &incx);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
			double alpha, double *A, int lda, double *B, int ldb) {
	dtrsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }


  void Trsm(char side, char uplo, char transa, char diag, int m, int n,
			float alpha, float *A, int lda, float *B, int ldb) {
	strsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, A, &lda, B, &ldb);
  }


  void Getrs(char trans, int n, int nrhs, double *A, int lda, int *ipiv, double *b, int ldb) {
	int info;
	dgetrs_(&trans, &n, &nrhs, A, &lda, ipiv, b, &ldb, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad dgetrs_ call");
	}
  }


  void Getrs(char trans, int n, int nrhs, float *A, int lda, int *ipiv, float *b, int ldb) {
	int info;
	sgetrs_(&trans, &n, &nrhs, A, &lda, ipiv, b, &ldb, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad sgetrs_ call");
	}
  }


  void Ormqr(char side, char trans, int m, int n, int k, double *A, int lda,
			 double *tau, double *C, int ldc) {
	std::function<void (double* &, int&, int&)> query = [&] (double *work,
															 int& lwork,
															 int& info) {
	  dormqr_(&side, &trans, &m, &n, &k, A, &lda, tau, C, &ldc,
			  work, &lwork, &info);
	};
	double *work;
	int lwork;
	int info;
	WorkspaceQueryAndAlloc(query, work, lwork, info);
	
	dormqr_(&side, &trans, &m, &n, &k, A, &lda, tau, C, &ldc,
			work, &lwork, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad dormqr_ call");
	}
	delete [] work;
  }


  void Ormqr(char side, char trans, int m, int n, int k, float *A, int lda,
			 float *tau, float *C, int ldc) {
	std::function<void (float* &, int&, int&)> query = [&] (float *work,
															 int& lwork,
															 int& info) {
	  sormqr_(&side, &trans, &m, &n, &k, A, &lda, tau, C, &ldc,
			  work, &lwork, &info);
	};
	float *work;
	int lwork;
	int info;
	WorkspaceQueryAndAlloc(query, work, lwork, info);
	
	sormqr_(&side, &trans, &m, &n, &k, A, &lda, tau, C, &ldc,
			work, &lwork, &info);
	if (info != 0) {
	  throw std::runtime_error("Bad dormqr_ call");
	}
	delete [] work;
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

}  // end namespace lapack


#endif  // _LAPACK_WRAP_HPP_
