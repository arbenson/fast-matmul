#ifndef __AUX_H__
#define __AUX_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "kernels.h"

// BLAS & LAPACK function definitions
extern "C" {

	/* BLAS defs */
#define CBLAS_INDEX int
	enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102 };
	enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113,
		AtlasConj=114};
	enum CBLAS_UPLO  {CblasUpper=121, CblasLower=122};
	enum CBLAS_DIAG  {CblasNonUnit=131, CblasUnit=132};
	enum CBLAS_SIDE  {CblasLeft=141, CblasRight=142};

	/* BLAS routines */
	void cblas_dcopy(const int N, const double *X, const int incX,
			double *Y, const int incY);
	CBLAS_INDEX cblas_idamax(const int N, const double *X, const int incX);
	double cblas_dnrm2(const int N, const double *X, const int incX);
	void cblas_dscal(const int N, const double alpha, double *X, const int incX);
	void cblas_daxpy(const int N, const double alpha, const double *X,
			const int incX, double *Y, const int incY);
	void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
			const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
			const int K, const double alpha, const double *A,
			const int lda, const double *B, const int ldb,
			const double beta, double *C, const int ldc); 
	void cblas_dsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
			const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
			const double alpha, const double *A, const int lda,
			const double beta, double *C, const int ldc);

	/* LAPACK defs */
	typedef int 		__CLPK_integer;
	typedef double 		__CLPK_doublereal;

	/* LAPACK routines   */    
	int dposv_(char *uplo, __CLPK_integer *n, __CLPK_integer *nrhs, __CLPK_doublereal 
			*a, __CLPK_integer *lda, __CLPK_doublereal *b, __CLPK_integer *ldb, __CLPK_integer *info);
	int dgesvd_(char *jobu, char *jobvt, __CLPK_integer *m, __CLPK_integer *n, 
			__CLPK_doublereal *a, __CLPK_integer *lda, __CLPK_doublereal *s, __CLPK_doublereal *u, __CLPK_integer *
			ldu, __CLPK_doublereal *vt, __CLPK_integer *ldvt, __CLPK_doublereal *work, __CLPK_integer *lwork, 
			__CLPK_integer *info);
	int dgeqrf_(__CLPK_integer *m, __CLPK_integer *n, __CLPK_doublereal *a, __CLPK_integer *
			lda, __CLPK_doublereal *tau, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
	int dgerqf_(__CLPK_integer *m, __CLPK_integer *n, __CLPK_doublereal *a, __CLPK_integer *
			lda, __CLPK_doublereal *tau, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
	int dormrq_(char *side, char *trans, __CLPK_integer *m, __CLPK_integer *n, 
			__CLPK_integer *k, __CLPK_doublereal *a, __CLPK_integer *lda, __CLPK_doublereal *tau, __CLPK_doublereal *
			c__, __CLPK_integer *ldc, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
}

// command line parsing functions
int find_option( int argc, char **argv, const char *option );
bool read_bool( int argc, char **argv, const char *option, bool default_value );
int read_int( int argc, char **argv, const char *option, int default_value );
double read_double( int argc, char **argv, const char *option, double default_value );
char *read_string( int argc, char **argv, const char *option, char *default_value );

// sorting functions
void quickSort( double* a, int* x, int l, int r);
int partition( double* a, int* x, int l, int r);

// other auxiliary functions
double wall_time();
void print_matrix(double*, int, int, int);
void print_int_matrix(double*, int, int, int, int);
void die(const char*);

#endif
