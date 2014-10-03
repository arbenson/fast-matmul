#ifndef __KERNELS_H__
#define __KERNELS_H__

#include <math.h>
#include "aux.h"

/* define struct for passing parameters through functions */
typedef struct {
    int rank;
    int matDims[3];
    int dims[3];
    char* method;
    int mkn2;
    double xNorm;
    int mtCols[3];
    double** U;
    double* lambda;
    double** X;
    double* A;
    double* tau;
    double* work;
    int lwork;
    double* NE_coeff;
    double* NE_rhs;
    double* residual;
    double** model;
    int* iwork;
    double alpha;
    int M[3];
    bool rnd;
    int rnd_pwrOfTwo;
    double rnd_maxVal;
} parameters;

// file I/O
void read_input( char* filename, parameters & prm );
void write_output( char* filename, parameters & prm );

// main kernels
double als(parameters & prm);
double compute_residual( parameters & prm, int eqn, bool recompute );

//void normalize_columns(double* A, int m, int n, int lda, double* norms);
//void scale_columns(double* A, int m, int n, int lda, double* scale, bool reciprocal);

// round each value to nearest reciprocal pwrOfTwo (3 implies 1/8th)
void rounding(double* A, int numVals, int pwrOfTwo);

// cap each value to maxVal if larger in absolute value
void capping(double* A, int numVals, double maxVal);

// leave M largest entries untouched, set the rest to zero
void setSmallestToZero(double* A, double* work, int* indices, int numVals, int M);

// count number of nonzeros
int nnz(double* A, int n);

// round values within threshold of +/- maxVal or 0 to those extremal values
void rounding_extremes(double* A, int numVals, double maxVal, double threshold);

// computes A = U (kr) V
void khatri_rao(double* A, int n, double* U, int mU, int ldu, double* V, int mV, int ldv);

// computes reverse Khatri-Rao product of other two matrices (besides idx)
void rev_khatri_rao(double* A, int n, double** U, int* m, int* ldus, int idx);

// computes C = kron(A,B) where A is m x n and B is k x l, so that C is mk x nl
void kron( double *C, int m, int n, double* A, int k, int l, double* B);

// in-place transposition of matrix
void transpose(double *A, int n);

// form identity matrix
void eye(double *A, int n);

// uses SVD and QR and "sandwiching" property to inject zeros into factors
void sparsify(parameters & prm);

// put all weights of model into ith array
void normalize_model( parameters& prm, int i );

#endif
