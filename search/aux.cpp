/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "aux.h"

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

char *read_string( int argc, char **argv, const char *option, char *default_value )
{
	int iplace = find_option( argc, argv, option );
	if( iplace >= 0 && iplace < argc-1 )
		return argv[iplace+1];
	return default_value;
}

void quickSort( double* a, int* ind, int l, int r)
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

int partition( double* a, int* ind, int l, int r) {
	int i, j, t;
	double pivot, dt;

	pivot = a[l];
	i = l; j = r+1;

	while(1)
	{
		do ++i; while( a[i] <= pivot && i <= r );
		do --j; while( a[j] > pivot );
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

void print_int_matrix(double *A, int m, int n, int lda, int pwrOfTwo)
{
	int i, j, k;
	if (pwrOfTwo > 0)
		printf("\n (1 / %d) * \n",(int) pow(2,pwrOfTwo));
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			k = (int) (pow(2,pwrOfTwo) * A[i+j*lda]);
			if (k < 0)
				printf("%d  ", k);
			else
				printf(" %d  ", k);
		}
		printf("\n");
		fflush(stdout);
	}
}

void print_matrix(double *A, int m, int n, int lda)
{
	int i, j;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n-1; ++j)
			printf("%.3e  ", A[i+j*lda]);
		printf("%.3e\n", A[i+j*lda]);
		fflush(stdout);
	}
}

void die(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
