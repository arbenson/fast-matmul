#include <stddef.h>   // NULL, exit, EXIT_FAILURE
#include <stdio.h>    // printf, fflush, stdout, stderr, fprintf, strerror
#include <string.h>   // strcmp
#include <stdlib.h>   // atoi, atof
#include <sys/time.h> // gettimeofday
#include <errno.h>    // errno
#include <math.h>     // pow

#include "aux.h" // bool, value_t

#ifndef CPLX

void dsyrk_wrap (char UPLO, char TRANS, int N, int K, double ALPHA, double const* A, int LDA, double BETA, double* C, int LDC)
{ dsyrk_ (&UPLO, &TRANS, &N, &K, &ALPHA, A, &LDA, &BETA, C, &LDC); }

void dgemm_wrap (char TRANSA, char TRANSB, int M, int N, int K, double ALPHA, double const* A, int LDA, double const* B, int LDB, double BETA, double* C, int LDC)
{ dgemm_ (&TRANSA, &TRANSB, &M, &N, &K, &ALPHA, A, &LDA, B, &LDB, &BETA, C, &LDC); }     
 
void daxpy_wrap (int N, double A, double const* X, int INCX, double* Y, int INCY)
{ daxpy_ (&N, &A, X, &INCX, Y, &INCY); }  
                                               
void dcopy_wrap (int N, double const* X, int INCX, double* Y, int INCY)
{ dcopy_ (&N, X, &INCX, Y, &INCY); }        

double dnrm2_wrap (int N, double const* X, int INCX)
{ return dnrm2_ (&N, X, &INCX); }    

void dscal_wrap (int N, double A, double* X, int INCX)
{ dscal_ (&N, &A, X, &INCX); }   

int idamax_wrap (int N, double const* X, int INCX)
{ return idamax_ (&N, X, &INCX) - 1; }  

void dposv_wrap (char UPLO, int N, int NRHS, double const* A, int LDA, double* B, int LDB, int* INFO)
{ dposv_ (&UPLO, &N, &NRHS, A, &LDA, B, &LDB, INFO); }

void dgesvd_wrap (char JOBU, char JOBVT, int M, int N, double* A, int LDA, double* S, double* U, int LDU, double* VT, int LDVT, double* WORK, int LWORK, int* INFO)
{ dgesvd_ (&JOBU, &JOBVT, &M, &N, A, &LDA, S, U, &LDU, VT, &LDVT, WORK, &LWORK, INFO); }

void dgerqf_wrap (int M, int N, double* A, int LDA, double* TAU, double* WORK, int LWORK, int* INFO)
{ dgerqf_ (&M, &N, A, &LDA, TAU, WORK, &LWORK, INFO); }
                                                                
void dormrq_wrap (char SIDE, char TRANS, int M, int N, int K, double const* A, int LDA, double const* TAU, double* C, int LDC, double* WORK, int LWORK, int* INFO)
{ dormrq_ (&SIDE, &TRANS, &M, &N, &K, A, &LDA, TAU, C, &LDC, WORK, &LWORK, INFO); }  

#else

void zherk_wrap (char UPLO, char TRANS, int N, int K, double complex ALPHA, double complex const* A, int LDA, double complex BETA, double complex* C, int LDC)
{ zherk_ (&UPLO, &TRANS, &N, &K, &ALPHA, A, &LDA, &BETA, C, &LDC); }   

void zgemm_wrap (char TRANSA, char TRANSB, int M, int N, int K, double complex ALPHA, double complex const* A, int LDA, double complex const* B, int LDB, double complex BETA, double complex* C, int LDC)
{ zgemm_ (&TRANSA, &TRANSB, &M, &N, &K, &ALPHA, A, &LDA, B, &LDB, &BETA, C, &LDC); }    

void zaxpy_wrap (int N, double complex A, double complex const* X, int INCX, double complex* Y, int INCY)
{ zaxpy_ (&N, &A, X, &INCX, Y, &INCY); }
                                             
void zcopy_wrap (int N, double complex const* X, int INCX, double complex* Y, int INCY)
{ zcopy_ (&N, X, &INCX, Y, &INCY); }   

double dznrm2_wrap (int N, double complex const* X, int INCX)
{ return dznrm2_ (&N, X, &INCX); } 

void zscal_wrap (int N, double complex A, double complex* X, int INCX)
{ zscal_ (&N, &A, X, &INCX); }     

void zdscal_wrap (int N, double A, double complex* X, int INCX)
{ zdscal_ (&N, &A, X, &INCX); }     
 
int izamax_wrap (int N, double complex const* X, int INCX)
{ return izamax_ (&N, X, &INCX) - 1; }    

void zposv_wrap (char UPLO, int N, int NRHS, double complex const* A, int LDA, double complex* B, int LDB, int* INFO)
{ zposv_ (&UPLO, &N, &NRHS, A, &LDA, B, &LDB, INFO); }  

void zgesvd_wrap (char JOBU, char JOBVT, int M, int N, double complex* A, int LDA, double* S, double complex* U, int LDU, double complex* VT, int LDVT, double complex* WORK, int LWORK, int* INFO)
{ zgesvd_ (&JOBU, &JOBVT, &M, &N, A, &LDA, S, U, &LDU, VT, &LDVT, WORK, &LWORK, INFO); }     

void zgerqf_wrap (int M, int N, double complex* A, int LDA, double complex* TAU, double complex* WORK, int LWORK, int* INFO)
{ zgerqf_ (&M, &N, A, &LDA, TAU, WORK, &LWORK, INFO); }    

void zunmrq_wrap (char SIDE, char TRANS, int M, int N, int K, double complex const* A, int LDA, double complex const* TAU, double complex* C, int LDC, double complex* WORK, int LWORK, int* INFO)
{ zunmrq_ (&SIDE, &TRANS, &M, &N, &K, A, &LDA, TAU, C, &LDC, WORK, &LWORK, INFO); }    

#endif              



int find_option( int argc, char **argv, const char *option )
{
	for( int i = 1; i < argc; i++ )
		if( strcmp( argv[i], option ) == 0 )
			return i;
	return -1;
}

bool read_bool( int argc, char **argv, const char *option, bool default_value )
{
	int iplace = find_option( argc, argv, option );
	if( iplace != -1 )
		return true;
	return default_value;
}

int read_int( int argc, char **argv, const char *option, int default_value )
{
	int iplace = find_option( argc, argv, option );
	if( iplace >= 0 && iplace < argc-1 )
		return atoi( argv[iplace+1] );
	return default_value;
}

double read_double( int argc, char **argv, const char *option, double default_value )
{
	int iplace = find_option( argc, argv, option );
	if( iplace >= 0 && iplace < argc-1 )
		return atof( argv[iplace+1] );
	return default_value;
}

char const* read_string( int argc, char **argv, char const* option, char const* default_value )
{
	int iplace = find_option( argc, argv, option );
	if( iplace >= 0 && iplace < argc-1 )
		return argv[iplace+1];
	return default_value;
}

//#ifndef CPLX
void quickSort( double* a, int* ind, int l, int r)
//#else
//void quickSort( double complex* a, int* ind, int l, int r)
//#endif
{
	int j;

	if( l < r ) 
	{
		// divide and conquer
		j = partition( a, ind, l, r);
		quickSort( a, ind, l, j-1);
		quickSort( a, ind, j+1, r);
	}

}

// #ifndef CPLX
int partition( double* a, int* ind, int l, int r) 
//#else
//int partition( double complex* a, int* ind, int l, int r) 
//#endif
{
	int i, j, t;

//#ifndef CPLX
	double pivot, dt;
//#else
//  double complex pivot, dt;
//#endif

	pivot = a[l];
	i = l; j = r+1;

	while(1)
	{
//#ifndef CPLX
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
//#else
//    do ++i; while( cabs(a[i]) <= cabs(pivot) && i <= r );
//		do --j; while( cabs(a[j]) > cabs(pivot) );
//#endif
		if( i >= j ) break;
		dt = a[i]; a[i] = a[j]; a[j] = dt;
		t = ind[i]; ind[i] = ind[j]; ind[j] = t;
	}
	dt = a[l]; a[l] = a[j]; a[j] = dt;
	t = ind[l]; ind[l] = ind[j]; ind[j] = t;
	return j;
}

double wall_time()
{
	struct timeval t;
	gettimeofday(&t,NULL);
	return 1.*t.tv_sec+1.e-6*t.tv_usec;
}

#ifndef CPLX
void print_int_matrix(double const* A, int m, int n, int lda, int pwrOfTwo)
#else
void print_int_matrix(double complex const* A, int m, int n, int lda, int pwrOfTwo)
#endif
{
	int i, j; // , k;
	if (pwrOfTwo > 0)
		// printf("\n (1 / %d) * \n",(int) pow(2,pwrOfTwo));
		printf("\n (1 / %d) * \n", 1 << pwrOfTwo);
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
#ifndef CPLX
			//k = (int) (pow(2,pwrOfTwo) * A[i+j*lda]);
			//if (k < 0)
			//	printf("%d  ", k);
			//else
			//	printf(" %d  ", k);
      
      printf("% lld%s", (long long int)(pow(2.,pwrOfTwo)*A[i+j*lda]), j < n-1 ? "  " : "\n");
#else
      printf("% lld%+lldi%s", (long long int)(pow(2.,pwrOfTwo)*creal(A[i+j*lda])), (long long int)(pow(2.,pwrOfTwo)*cimag(A[i+j*lda])), j < n-1 ? "  " : "\n");
#endif
		}
  }
  fflush(stdout);
}

#ifndef CPLX
void print_matrix(double const* A, int m, int n, int lda)
#else
void print_matrix(double complex const* A, int m, int n, int lda)
#endif
{
	int i, j;
	for (i = 0; i < m; ++i)
  {
    for (j = 0; j < n; ++j)
    {
#ifndef CPLX
      printf("%.3e%s", A[i+j*lda], j < n-1 ? "  " : "\n");
#else
      printf("%.3e%+.3ei%s", creal(A[i+j*lda]), cimag(A[i+j*lda]), j < n-1 ? "  " : "\n");
#endif
    }
  }
  fflush(stdout);
}

void die (const char* message)
{
  fprintf(stderr, "%s%s%s\n", message, errno == 0 ? "" : ": ", errno == 0 ? "" : strerror(errno)); 
	exit(EXIT_FAILURE);
}
