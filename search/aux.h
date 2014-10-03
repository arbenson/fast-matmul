#ifndef __AUX_H__
#define __AUX_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "kernels.h"

#ifdef MAC
    #include <clapack.h>
    #include <cblas.h>
#elif defined MKL
    #include <mkl.h>
    #include <mkl_service.h>
#endif


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
