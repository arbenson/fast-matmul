#ifndef __KERNELS_H__
#define __KERNELS_H__

#include <stdbool.h> // bool

#include "complex_wrapper.h" // CMPLX, value_t

/* define struct for passing parameters through functions */
typedef struct {
	int rank;
	int matDims[3];
	int dims[3];
	char const* method;
	int mkn2;
	double xNorm;
	int mtCols[3];
	value_t** U;
	double* lambda;
	value_t** X;
	value_t* A;
	value_t* tau;
	value_t* work;
	int lwork;
	value_t* NE_coeff;
	value_t* NE_rhs;
	value_t* residual;
	value_t** model;
	int* iwork;
	double alpha;
	int M[3];
	bool rnd;
	int rnd_pwrOfTwo;
	double rnd_maxVal;
} parameters;

// file I/O
void read_input   (char const* filename, parameters prm);
void write_output (char const* filename, parameters prm);

// main kernels
// double als(parameters & prm);
double als (parameters prm);
// double compute_residual( parameters & prm, int eqn, bool recompute );
double compute_residual (parameters prm, int eqn, bool recompute);

// round each value to nearest reciprocal pwrOfTwo (3 implies 1/8th)
void rounding (value_t* A, int numVals, int pwrOfTwo);

// cap each value to maxVal if larger in absolute value
void capping (value_t* A, int numVals, double maxVal);

// leave M largest entries untouched, set the rest to zero
void setSmallestToZero (value_t* A, double* work, int* indices, int numVals, int M);

// count number of nonzeros
// int nnz(value_t* A, int n, double threshold = 0.0);
int nnz (value_t const* A, int n, double threshold);

// computes A = U (kr) V
void khatri_rao (value_t* A, int n, value_t const* U, int mU, int ldu, value_t const* V, int mV, int ldv);

// computes reverse Khatri-Rao product of other two matrices (besides idx)
void rev_khatri_rao (value_t* A, int n, value_t const* const* U, int const* m, int const* ldus, int idx);

// computes C = kron(A,B) where A is m x n and B is k x l, so that C is mk x nl
void kron (value_t *C, int m, int n, value_t const* A, int k, int l, value_t const* B);

// in-place transposition of matrix
void transpose (value_t* A, int n);

// form identity matrix
void eye (value_t* A, int n);

// uses SVD and QR and "sandwiching" property to inject zeros into factors
void sparsify (parameters prm);

// put all weights of model into ith array
void normalize_model (parameters prm, int i );
void normalize_columns (value_t* A, int m, int n, int lda, double* norms);
void scale_columns (value_t* A, int m, int n, int lda, double const* scale, bool reciprocal);

#endif
