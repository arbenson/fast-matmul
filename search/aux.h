#ifndef __AUX_H__
#define __AUX_H__

#include <stdbool.h> // bool

#include "complex_wrapper.h" // value_t

#ifndef CPLX

void dsyrk_ (char const*, char const*, int const*, int const*, double const*, double const*, int const*, double const*, double*, int const*);
void dsyrk_wrap (char, char, int, int, double, double const*, int, double, double*, int);

void dgemm_ (char const*, char const*, int const*, int const*, int const*, double const*, double const*, int const*, double const*, int const*, double const*, double*, int const*);
void dgemm_wrap (char, char, int, int, int, double, double const*, int, double const*, int, double, double*, int);
 
void daxpy_ (int const*, double const*, double const*, int const*, double*, int const*);
void daxpy_wrap (int, double, double const*, int, double*, int);
                                               
void dcopy_ (int const*, double const*, int const*, double*, int const*);
void dcopy_wrap (int, double const*, int, double*, int);

double dnrm2_ (int const*, double const*, int const*);
double dnrm2_wrap (int, double const*, int);

void dscal_ (int const*, double const*, double*, int const*);
void dscal_wrap (int, double, double*, int);

int idamax_ (int const*, double const*, int const*);
int idamax_wrap (int, double const*, int);

void dposv_ (char const*, int const*, int const*, double const*, int const*, double*, int const*, int*);
void dposv_wrap (char, int, int, double const*, int, double*, int, int*);

void dgesvd_ (char const*, char const*, int const*, int const*, double*, int const*, double*, double*, int const*, double*, int const*, double*, int const*, int*);
void dgesvd_wrap (char, char, int, int, double*, int, double*, double*, int, double*, int, double*, int, int*);

void dgerqf_ (int const*, int const*, double*, int const*, double*, double*, int const*, int*);
void dgerqf_wrap (int, int, double*, int, double*, double*, int, int*);
                                                                
void dormrq_ (char const*, char const*, int const*, int const*, int const*, double const*, int const*, double const*, double*, int const*, double*, int const*, int*);
void dormrq_wrap (char, char, int, int, int, double const*, int, double const*, double*, int, double*, int, int*);

#else

void zherk_ (char const*, char const*, int const*, int const*, double complex const*, double complex const*, int const*, double complex const*, double complex*, int const*);
void zherk_wrap (char, char, int, int, double complex, double complex const*, int, double complex, double complex*, int);

void zgemm_ (char const*, char const*, int const*, int const*, int const*, double complex const*, double complex const*, int const*, double complex const*, int const*, double complex const*, double complex*, int const*);
void zgemm_wrap (char, char, int, int, int, double complex, double complex const*, int, double complex const*, int, double complex, double complex*, int);

void zaxpy_ (int const*, double complex const*, double complex const*, int const*, double complex*, int const*);
void zaxpy_wrap (int, double complex, double complex const*, int, double complex*, int);
                                             
void zcopy_ (int const*, double complex const*, int const*, double complex*, int const*);
void zcopy_wrap (int, double complex const*, int, double complex*, int);

double dznrm2_ (int const*, double complex const*, int const*);
double dznrm2_wrap (int, double complex const*, int);

void zscal_ (int const*, double complex const*, double complex*, int const*);
void zscal_wrap (int, double complex, double complex*, int);

void zdscal_ (int const*, double const*, double complex*, int const*);
void zdscal_wrap (int, double, double complex*, int);
 
int izamax_ (int const*, double complex const*, int const*);
int izamax_wrap (int, double complex const*, int);

void zposv_ (char const*, int const*, int const*, double complex const*, int const*, double complex*, int const*, int*);
void zposv_wrap (char, int, int, double complex const*, int, double complex*, int, int*);

void zgesvd_ (char const*, char const*, int const*, int const*, double complex*, int const*, double*, double complex*, int const*, double complex*, int const*, double complex*, int const*, int*);
void zgesvd_wrap (char, char, int, int, double complex*, int, double*, double complex*, int, double complex*, int, double complex*, int, int*);

void zgerqf_ (int const*, int const*, double complex*, int const*, double complex*, double complex*, int const*, int*);
void zgerqf_wrap (int, int, double complex*, int, double complex*, double complex*, int, int*);

void zunmrq_ (char const*, char const*, int const*, int const*, int const*, double complex const*, int const*, double complex const*, double complex*, int const*, double complex*, int const*, int*);
void zunmrq_wrap (char, char, int, int, int, double complex const*, int, double complex const*, double complex*, int, double complex*, int, int*);

#endif


// // BLAS & LAPACK function definitions
// extern "C" {
// 
// 	/* BLAS defs */
// #define CBLAS_INDEX int
// 	enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102 };
// 	enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113,
// 		AtlasConj=114};
// 	enum CBLAS_UPLO  {CblasUpper=121, CblasLower=122};
// 	enum CBLAS_DIAG  {CblasNonUnit=131, CblasUnit=132};
// 	enum CBLAS_SIDE  {CblasLeft=141, CblasRight=142};
// 
// 	/* BLAS routines */
// 	void cblas_dcopy(const int N, const double *X, const int incX,
// 			double *Y, const int incY);
// 	CBLAS_INDEX cblas_idamax(const int N, const double *X, const int incX);
// 	double cblas_dnrm2(const int N, const double *X, const int incX);
// 	void cblas_dscal(const int N, const double alpha, double *X, const int incX);
// 	void cblas_daxpy(const int N, const double alpha, const double *X,
// 			const int incX, double *Y, const int incY);
// 	void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
// 			const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
// 			const int K, const double alpha, const double *A,
// 			const int lda, const double *B, const int ldb,
// 			const double beta, double *C, const int ldc); 
// 	void cblas_dsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
// 			const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
// 			const double alpha, const double *A, const int lda,
// 			const double beta, double *C, const int ldc);
// 
// 	/* LAPACK defs */
// 	typedef int 		__CLPK_integer;
// 	typedef double 		__CLPK_doublereal;
// 
// 	/* LAPACK routines   */    
// 	int dposv_(char *uplo, __CLPK_integer *n, __CLPK_integer *nrhs, __CLPK_doublereal 
// 			*a, __CLPK_integer *lda, __CLPK_doublereal *b, __CLPK_integer *ldb, __CLPK_integer *info);
// 	int dgesvd_(char *jobu, char *jobvt, __CLPK_integer *m, __CLPK_integer *n, 
// 			__CLPK_doublereal *a, __CLPK_integer *lda, __CLPK_doublereal *s, __CLPK_doublereal *u, __CLPK_integer *
// 			ldu, __CLPK_doublereal *vt, __CLPK_integer *ldvt, __CLPK_doublereal *work, __CLPK_integer *lwork, 
// 			__CLPK_integer *info);
// 	int dgeqrf_(__CLPK_integer *m, __CLPK_integer *n, __CLPK_doublereal *a, __CLPK_integer *
// 			lda, __CLPK_doublereal *tau, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
// 	int dgerqf_(__CLPK_integer *m, __CLPK_integer *n, __CLPK_doublereal *a, __CLPK_integer *
// 			lda, __CLPK_doublereal *tau, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
// 	int dormrq_(char *side, char *trans, __CLPK_integer *m, __CLPK_integer *n, 
// 			__CLPK_integer *k, __CLPK_doublereal *a, __CLPK_integer *lda, __CLPK_doublereal *tau, __CLPK_doublereal *
// 			c__, __CLPK_integer *ldc, __CLPK_doublereal *work, __CLPK_integer *lwork, __CLPK_integer *info);
// }

// command line parsing functions
int find_option( int argc, char **argv, const char *option );
bool read_bool( int argc, char **argv, const char *option, bool default_value );
int read_int( int argc, char **argv, const char *option, int default_value );
double read_double( int argc, char **argv, const char *option, double default_value );
char const* read_string( int argc, char **argv, char const* option, char const* default_value );

// sorting functions
//#ifndef CPLX
void quickSort( double* a, int* x, int l, int r);
int partition( double* a, int* x, int l, int r);
//#else
//void quickSort( double complex* a, int* x, int l, int r);
//int partition( double complex * a, int* x, int l, int r);      
//#endif


// other auxiliary functions
double wall_time();
//#ifndef CPLX
void print_matrix(value_t const*, int, int, int);
void print_int_matrix(value_t const*, int, int, int, int);
//#else
//void print_matrix(double complex const*, int, int, int);
//void print_int_matrix(double complex const*, int, int, int, int);      
//#endif
void die (const char*);

#endif
