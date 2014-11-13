#include <stddef.h> // NULL
#include <stdlib.h> // atof, malloc, free
#include <stdio.h>  // FILE, EOF, fopen, fgets, snprintf, fputs, fclose, feof
#include <float.h>  // DECIMAL_DIG, fp_classify, FP_ZERO
#include <string.h> // strtok, strlen
#include <math.h>   // fabs, round


#include "aux.h" // die

#include "kernels.h" // CMPLX, bool, value_t


#define BUF_SIZE 10000

// File format: 
//   -- numbers separated by spaces
//   -- comment lines (those starting with '#') are ignored
//   -- lines cannot exceed BUF_SIZE characters (including '\n')
//   -- each line corresponds to a matrix row (U then V then W) 
//   -- U, V, W have prm->dims[0], prm->dims[1], prm->dims[2] rows, resp.
//   -- U, V, W each have prm->rank columns
//   -- complex numbers must include both real and imaginary components, separated only by ',' 
void read_input (char const* filename, parameters prm)
{
  int i,j,k; 

  FILE *fp = fopen (filename, "r");
  if (fp == NULL) die("Error opening input file");

  char line[BUF_SIZE], *p;
  for (k = 0; k < 3; k++) 
  {
    p = fgets(line, sizeof(line), fp);
    for (i = 0; i < prm.dims[k]; i++) 
    {
      if (p == NULL) die(feof(fp) ? "Error reading input file: unexpected EOF" : "Error reading input file");
      else if (*line == '#') continue;
      else if (line[strlen(line)-1] != '\n') die("Error reading input file: line too long");

      p = strtok(line, " ");
      for (j = 0; j < prm.rank; j++) 
      {
        if (p == NULL) die("Error reading input file: too few columns");

        double real_val;
#ifndef CPLX
        int ret = sscanf(p, "%lf", &real_val);
        if (ret != 1) die("Error reading input file: sscanf failed to parse real number");
        prm.U[k][j*prm.dims[k]+i] = real_val;
#else
        double imag_val;
        int ret = sscanf(p, "%lf%*[,]%lf", &real_val, &imag_val);
        if (ret != 2) die("Error reading input file: sscanf failed to parse complex number");   
        prm.U[k][j*prm.dims[k]+i] = CMPLX(real_val, imag_val); 
#endif
        p = strtok(NULL, " ");
      }
      p = fgets(line, sizeof(line), fp);
    }
  }

  fclose (fp);
}

void write_output (char const* filename, parameters prm)
{
  int i,j,k;

  FILE *fp = fopen (filename, "w");
  if (fp == NULL) die("Error opening output file");

  char entry[BUF_SIZE];
  for (k = 0; k < 3; k++) 
    for (i = 0; i < prm.dims[k]; i++) 
      for( j = 0; j < prm.rank; j++) 
      {
#ifndef CPLX
        // NK: old approach can lose accuracy when numbers fall below ~1e-20:
        // sprintf(entry,"%2.20f ",prm.U[k][j*prm.dims[k]+i]);
        int entry_sz = snprintf (
          entry, 
          BUF_SIZE, 
          "%.*e%s", 
          DECIMAL_DIG, 
          prm.U[k][j*prm.dims[k]+i], 
          j < prm.rank-1 ? " " : (i == prm.dims[k]-1 && k < 2 ? "\n#\n" : "\n" ) ); 
#else
        int entry_sz = snprintf (
          entry,
          BUF_SIZE, 
          "%.*e,%.*e%s", 
          DECIMAL_DIG, 
          DECIMAL_DIG, 
          creal(prm.U[k][j*prm.dims[k]+i]), 
          cimag(prm.U[k][j*prm.dims[k]+i]), 
          j < prm.rank-1 ? " " : (i == prm.dims[k]-1 && k < 2 ? "\n#\n" : "\n" ) ); 
#endif
        if (entry_sz < 0) die("Error writing output file");
        else if (entry_sz > BUF_SIZE-1) die("Error writing output file: entry too long");
        int ret = fputs(entry, fp);
        if (ret == EOF) die("Error while writing to output file");
      }
  fclose (fp);  
}

// Performs one (outer) iteration of Alternating Least Squares by solving normal equations
// with extra term in the objective to penalize deviation from model solution
//  - obj fcn is ||Ax-b||^2 + alpha * ||x-model||^2
//  - normal equations are (A^TA + alpha I) x = A^Tb + alpha model
//  - if model = 0, same as Tikhonov regularization or ridge regression
//  - note that model is stored as transpose of factor matrix
//  - treats everything as dense, using 3 matricizations of the tensor
//  - returns square of Frobenius norm of residual (ignoring extra term)

double als(parameters prm)
// double als(parameters & prm)
{
	int i, j, k, info;
	// char lower = 'L';

	// Iterate over factor matrices
	// Solve Ui*(Ai^T*Ai) = Xi*Ai for Ui, Ai is ith reverse Khatri-Rao product
	for (i = 0; i < 3; i++)
	{         
		// compute coefficient matrix Ai
		rev_khatri_rao(prm.A, prm.rank, prm.U, prm.dims, prm.dims, i);

		// form normal equations coefficients NE_coeff = Ai^T * Ai
#ifndef CPLX
    // cblas_dsyrk(CblasColMajor, CblasLower, CblasTrans, prm.rank, prm.mtCols[i], 1.0, prm.A, prm.mtCols[i], 0.0, prm.NE_coeff, prm.rank);
    dsyrk_wrap('L', 'T', prm.rank, prm.mtCols[i], 1., prm.A, prm.mtCols[i], 0., prm.NE_coeff, prm.rank);  
#else
    zherk_wrap('L', 'C', prm.rank, prm.mtCols[i], CMPLX(1.,0.), prm.A, prm.mtCols[i], CMPLX(0.,0.), prm.NE_coeff, prm.rank);  
#endif

		// add alpha*I to NE coefficient matrix
		for (j = 0; j < prm.rank; j++)
			prm.NE_coeff[j+j*prm.rank] += prm.alpha;

		// compute NE right-hand-side = Ai^T * Xi^T
#ifndef CPLX
    // cblas_dgemm(CblasColMajor, CblasTrans, CblasTrans, prm.rank, prm.dims[i], prm.mtCols[i], 1.0, prm.A, prm.mtCols[i], prm.X[i], prm.dims[i], 0.0, prm.NE_rhs, prm.rank);
    dgemm_wrap('T', 'T', prm.rank, prm.dims[i], prm.mtCols[i], 1., prm.A, prm.mtCols[i], prm.X[i], prm.dims[i], 0., prm.NE_rhs, prm.rank);
#else
    zgemm_wrap('C', 'C', prm.rank, prm.dims[i], prm.mtCols[i], CMPLX(1.,0.), prm.A, prm.mtCols[i], prm.X[i], prm.dims[i], CMPLX(0.,0.), prm.NE_rhs, prm.rank);
#endif

		// copy transpose of scaled previous solution to model 
		for (j = 0; j < prm.dims[i]; j++)
			for (k = 0; k < prm.rank; k++)
      {
#ifndef CPLX
        prm.model[i][k+j*prm.rank] = prm.U[i][j+k*prm.dims[i]];
#else
        prm.model[i][k+j*prm.rank] = conj(prm.U[i][j+k*prm.dims[i]]);
#endif
      }

		// set all but largest M entries to zero
		setSmallestToZero(prm.model[i], (double*) prm.work, prm.iwork, prm.rank*prm.dims[i], prm.M[i]);

		// cap model values
		capping(prm.model[i], prm.rank*prm.dims[i], prm.rnd_maxVal);

		// add alpha * model^T to right hand side
#ifndef CPLX
		// cblas_daxpy(prm.dims[i]*prm.rank,prm.alpha,prm.model[i],1,prm.NE_rhs,1);
    daxpy_wrap(prm.dims[i]*prm.rank, prm.alpha, prm.model[i], 1, prm.NE_rhs, 1);
#else
    zaxpy_wrap(prm.dims[i]*prm.rank, prm.alpha, prm.model[i], 1, prm.NE_rhs, 1);
#endif

		// solve (Ai^T*Ai + alpha * I) * Ui^T = Ai^T * Xi^T + alpha * modeli^T for Ui^T
		// dposv_(&lower, &prm.rank, &prm.dims[i], prm.NE_coeff, &prm.rank, prm.NE_rhs, &prm.rank, &info);
#ifndef CPLX
    dposv_wrap('L', prm.rank, prm.dims[i], prm.NE_coeff, prm.rank, prm.NE_rhs, prm.rank, &info);
#else
    zposv_wrap('L', prm.rank, prm.dims[i], prm.NE_coeff, prm.rank, prm.NE_rhs, prm.rank, &info);
#endif

		// transpose solution
		for (j = 0; j < prm.dims[i]; j++)
			for (k = 0; k < prm.rank; k++)
      {
#ifndef CPLX
        prm.U[i][j+k*prm.dims[i]] = prm.NE_rhs[k+j*prm.rank];
#else
        prm.U[i][j+k*prm.dims[i]] = conj(prm.NE_rhs[k+j*prm.rank]);
#endif
      }
        
	}

	// Return squared norm of absolute residual
	return compute_residual (prm, 2, false);
}

// Computes the residual (squared absolute Frobenius norm)
//  - eqn determines which matrix unfolding to use: || X_(eqn) - U[eqn]*(KR_(-eqn))^T ||
double compute_residual (parameters prm, int eqn, bool recompute)
{
	double resnrm;

	// fill in matricized tensor
#ifndef CPLX
	// cblas_dcopy(prm.mkn2, prm.X[eqn], 1, prm.residual, 1);
	dcopy_wrap (prm.mkn2, prm.X[eqn], 1, prm.residual, 1);
#else
  zcopy_wrap (prm.mkn2, prm.X[eqn], 1, prm.residual, 1);
#endif

	// put weights back in factor matrix
	//scale_columns(prm.U[eqn], prm.dims[eqn], prm.rank, prm.dims[eqn], prm.lambda, false);

	// recompute coefficient matrix if necessary
	if (recompute)
		rev_khatri_rao(prm.A, prm.rank, prm.U, prm.dims, prm.dims, eqn);

	// compute residual matrix
#ifndef CPLX
	// cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, prm.dims[eqn], prm.mtCols[eqn], prm.rank, 1.0, prm.U[eqn], prm.dims[eqn], prm.A, prm.mtCols[eqn], -1.0, prm.residual, prm.dims[eqn]);
	dgemm_wrap ('N', 'T', prm.dims[eqn], prm.mtCols[eqn], prm.rank, 1., prm.U[eqn], prm.dims[eqn], prm.A, prm.mtCols[eqn], -1., prm.residual, prm.dims[eqn]);
#else
	zgemm_wrap ('N', 'C', prm.dims[eqn], prm.mtCols[eqn], prm.rank, CMPLX(1.,0.), prm.U[eqn], prm.dims[eqn], prm.A, prm.mtCols[eqn], CMPLX(-1.,0.), prm.residual, prm.dims[eqn]);
#endif

	// compute norm
#ifndef CPLX
	// resnrm = cblas_dnrm2(prm.mkn2, prm.residual, 1);
	resnrm = dnrm2_wrap (prm.mkn2, prm.residual, 1);
#else
  resnrm = dznrm2_wrap (prm.mkn2, prm.residual, 1);
#endif

	// take weights back out of factor matrix
	//scale_columns(prm.U[eqn], prm.dims[eqn], prm.rank, prm.dims[eqn], prm.lambda, true);

	return resnrm*resnrm;

}

// Normalizes all columns of matrix, storing norms in separate array
void normalize_columns(value_t* A, int m, int n, int lda, double* norms)
{
	int max_idx;
	double nrm;
	for (int i = 0; i < n; i++)
	{
		// Compute INF norm of column
#ifndef CPLX
		// max_idx = cblas_idamax(m,A+i*lda,1);
		max_idx = idamax_wrap (m, A+i*lda, 1);
    // printf("*** %d\n", max_idx);
		nrm = fabs(A[max_idx+i*lda]);           // TODO: get rid of abs/mag in real/complex case
#else
		max_idx = izamax_wrap (m, A+i*lda, 1);
		nrm = cabs(A[max_idx+i*lda]);               
#endif

		// Compute 2 norm of column
		//nrm = cblas_dnrm2(m,A+i*lda,1);

		// Check for zero norm
		if (fpclassify(nrm) == FP_ZERO) 
    {
      fprintf(stderr, "Warning, zero norm\n");
			nrm = 1.0;
    }
		// Scale column by reciprocal
#ifndef CPLX
		// cblas_dscal(m,1/nrm,A+i*lda,1);
		dscal_wrap (m, 1./nrm, A+i*lda, 1);
#else
		zdscal_wrap (m, 1./nrm, A+i*lda, 1);
#endif

		// Update norms array
		norms[i] = nrm;
	}
}

// Scales all columns of matrix using values in separate array
//  - if reciprocal is true, scales by reciprocal of scale values
void scale_columns(value_t* A, int m, int n, int lda, double const* scale, bool reciprocal)
{
  for (int i = 0; i < n; i++)
  {     
    // Scale column
    if (reciprocal)
    {
#ifndef CPLX
      // cblas_dscal(m,1/scale[i],A+i*lda,1);
      dscal_wrap (m, 1./scale[i], A+i*lda, 1);
#else
      zdscal_wrap (m, 1./scale[i], A+i*lda, 1);
#endif
    }
    else
    {
#ifndef CPLX
      // cblas_dscal(m,scale[i],A+i*lda,1);
      dscal_wrap (m, scale[i], A+i*lda, 1);
#else
      zdscal_wrap (m, scale[i], A+i*lda, 1);
#endif
    }
  }
}

// put all weights of model into ith array
void normalize_model (parameters prm, int i)
{
	// put lambda weights into array i
	scale_columns(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.lambda, false);
	
  for (int j = 0; j < 3; ++j)
		if (j != i)
		{
			// pull weights out of factor matrix j, put into i
			normalize_columns(prm.U[j], prm.dims[j], prm.rank, prm.dims[j], prm.lambda);
			scale_columns(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.lambda, false);
		}

	// set lambda weights to ones
	for (int k = 0; k < prm.rank; ++k)
		prm.lambda[k] = 1.;
}

// Rounds each value to nearest reciprocal power of 2 
//  - pwrOfTwo = 3 implies rounding to nearest 1/8th
void rounding (value_t* A, int numVals, int pwrOfTwo)
{
	// long long prec = pow(2,pwrOfTwo);     
	uintmax_t prec = ((uintmax_t) 1) << pwrOfTwo;
  for (int i = 0; i < numVals; i++)
  {
    // Note: could overflow for very large inputs
#ifndef CPLX
		A[i] = round(prec*A[i])/prec;
#else
    A[i] = CMPLX( round(prec*creal(A[i]))/prec, round(prec*cimag(A[i]))/prec );
#endif
  }
}

// Caps entries to maximum value (with matching sign) if larger in absolute value
//  - maxVal specifies maximum absolute value 
void capping(value_t* A, int numVals, double maxVal)
{    
	for (int i = 0; i < numVals; i++)
  {  
    // if (A[i] < -maxVal)
    //	A[i] = -maxVal;
    //else if (A[i] > maxVal)
    //	A[i] = maxVal;

#ifndef CPLX
    double mag = fabs(A[i]);
#else
    double mag = cabs(A[i]);
#endif

    if (mag > maxVal)
      A[i] = maxVal * (A[i] / mag);
  }
}

// Leave largest M values untouched, set all others to zero
void setSmallestToZero(value_t* A, double* work, int* indices, int numVals, int M)
{
	// quick return if possible
	if (M < 0)
		return;

	if (M > numVals)
		die("Error with setSmallestToZero: M can't exceed number of entries in matrix");

	// initialize working arrays
	for (int i = 0; i < numVals; ++i)
	{
#ifndef CPLX
		work[i] = fabs(A[i]);
#else
    work[i] = cabs(A[i]);
#endif
		indices[i] = i;
	}

	// sort array with indices
	quickSort (work, indices, 0, numVals-1);

	// set smallest entries to zero
	for (int i = 0; i < numVals-M; ++i)
  {
#ifndef CPLX
		A[indices[i]] = 0.;
#else
    A[indices[i]] = CMPLX( 0., 0. );
#endif
  }
}

// Counts number of nonzeros
int nnz (value_t const* A, int n, double threshold)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
#ifndef CPLX
    double mag = fabs(A[i]);
#else
    double mag = cabs(A[i]);
#endif
    if (mag > threshold)
      count++;
  }
  return count;
}

// computes A = U (*) V where (*) is Khatri-Rao product
void khatri_rao(value_t* A, int n, value_t const* U, int mU, int ldu, value_t const* V, int mV, int ldv)
{
	value_t* Ai;
  value_t const* Ui;
  value_t const* Vi;
	for (int i = 0; i < n; i++)
	{
		Ai = A + i*mU*mV;
		Ui = U + i*ldu;
		Vi = V + i*ldv;
		for (int j = 0; j < mU; j++)
		{
			// copy ith column of V into A
#ifndef CPLX
			// cblas_dcopy(mV,Vi,1,Ai,1);
			dcopy_wrap (mV, Vi, 1, Ai, 1);
#else
			zcopy_wrap (mV, Vi, 1, Ai, 1);
#endif

			// scale column by U_ij
#ifndef CPLX
			// cblas_dscal(mV,Ui[j],Ai,1);
			dscal_wrap (mV, Ui[j], Ai, 1);
#else
			zscal_wrap (mV, Ui[j], Ai, 1);
#endif

			// increment Ai
			Ai += mV;
		}
	}
}

// computes U[2] (*) U[1] (*) U[0] with U[idx] excluded from the product
void rev_khatri_rao(value_t* A, int n, value_t const* const* U, int const* m, int const* ldus, int idx)
{
	switch(idx)
	{
		case 0 :
			khatri_rao(A,n,U[2],m[2],ldus[2],U[1],m[1],ldus[1]);
			break;
		case 1 :
			khatri_rao(A,n,U[2],m[2],ldus[2],U[0],m[0],ldus[0]);
			break;
		case 2 :
			khatri_rao(A,n,U[1],m[1],ldus[1],U[0],m[0],ldus[0]);
			break;
		default :
			die("rev_khatri_rao: invalid idx");
	}
	return;
}

// computes C = kron(A,B) where A is m x n and B is k x l, so that C is mk x nl
// assumes lda is m, ldb is k, and returns C with ldc mn
void kron( value_t *C, int m, int n, value_t const* A, int k, int l, value_t const* B)
{
	value_t const* Bptr;
  value_t* Cptr = C;

	// loop over block columns of C
	for (int nn = 0; nn < n; ++nn)
	{
		// reset Bptr
		Bptr = B;

		// loop over columns within block column
		for (int ll = 0; ll < l; ++ll)
		{        
			// loop over block rows with column
			for (int mm = 0; mm < m; ++mm)
			{

				// copy ll'th column of B into sub-column of C
#ifndef CPLX
        // cblas_dcopy(k,Bptr,1,Cptr,1);
        dcopy_wrap (k, Bptr, 1, Cptr, 1);
#else
        zcopy_wrap (k, Bptr, 1, Cptr, 1);
#endif

				// scale sub-column by A[mm,nn]
#ifndef CPLX
        // cblas_dscal(k,A[mm+nn*m],Cptr,1);
        dscal_wrap (k, A[mm+nn*m], Cptr, 1);
#else
        zscal_wrap (k, A[mm+nn*m], Cptr, 1);
#endif

				// advance Cptr
				Cptr += k;
			}

			// advance Bptr
			Bptr += k;
		}
	}
	return;

}

// in-place transposition of square matrix
// assumes lda = n
void transpose (value_t* A, int n )
{
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < i; ++j )
		{
#ifndef CPLX
			value_t tmp = A[i+j*n];
			A[i+j*n] = A[j+i*n];
#else  
      value_t tmp = conj(A[i+j*n]);
			A[i+j*n] = conj(A[j+i*n]);
#endif
			A[j+i*n] = tmp;
		}
}

// write identity matrix to array
// assumes lda = n
void eye (value_t* A, int n )
{
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
		{			
      //if( i == j )
			//	A[i+j*n] = 1;
			//else
			//	A[i+j*n] = 0;      
#ifndef CPLX
      A[i+j*n] = (i == j ? 1. : 0.);
#else
      A[i+j*n] = (i == j ? CMPLX(1., 0.) : CMPLX(0., 0.));
#endif
		}
}

// uses SVD and QR and "sandwiching" property to inject zeros into factors
//   * this code works for all m, k, and n, but to maximize the number of injected
//     zeros, the order should be m > k > n
void sparsify (parameters prm)
{
  int m = prm.matDims[0], k = prm.matDims[1], n = prm.matDims[2], comp, info;
  // char job = 'A'; // means that orthogonal matrices output from SVD are square
  // char right = 'R', notrans = 'N';

  // temporary space for Kronecker products (more than needed)
  value_t* Kr = (value_t*) malloc (prm.mkn2 * sizeof(value_t));

  // copy one component of A to perform SVD
  comp = 0;
  value_t* Acmp = (value_t*) malloc (prm.dims[0] * sizeof(value_t));
#ifndef CPLX
  // cblas_dcopy(prm.dims[0],prm.U[0]+comp*prm.dims[0],1,Acmp,1);
  dcopy_wrap (prm.dims[0], prm.U[0]+comp*prm.dims[0], 1, Acmp, 1);
#else
  zcopy_wrap (prm.dims[0], prm.U[0]+comp*prm.dims[0], 1, Acmp, 1);
#endif

  // temporary space for SVD of Acmp and RQ/LQ of Bcmp
  int minmk = (m < k) ? m : k;
  double* s  = (double*)  malloc (minmk * sizeof(double));
  value_t* P = (value_t*) malloc (m*m * sizeof(value_t));
  value_t* Q = (value_t*) malloc (k*k * sizeof(value_t));
  value_t* R = (value_t*) malloc (n*n * sizeof(value_t));

  // TODO: ensure workspace allocation
  // perform SVD of one component of A
#ifndef CPLX
  // dgesvd_( &job, &job, &m, &k, Acmp, &m, s, P, &m, Q, &k, prm.work, &prm.lwork, &info);
  dgesvd_wrap ('A', 'A', m, k, Acmp, m, s, P, m, Q, k, prm.work, prm.lwork, &info);
#else
  zgesvd_wrap ('A', 'A', m, k, Acmp, m, s, P, m, Q, k, prm.work, prm.lwork, &info);
#endif

  // explicit tranpose    
  transpose (P, m);

  // form Kronecker product kron(Q,P)
  kron (Kr, k, k, Q, m, m, P);

  // copy current A into work buffer
#ifndef CPLX
  // cblas_dcopy(prm.dims[0]*prm.rank,prm.U[0],1,prm.work,1);
  dcopy_wrap (prm.dims[0]*prm.rank, prm.U[0], 1, prm.work, 1);
#else
  zcopy_wrap (prm.dims[0]*prm.rank, prm.U[0], 1, prm.work, 1);
#endif

  // apply transformation kron(Q,P) to A
#ifndef CPLX
  // cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[0], prm.rank, prm.dims[0], 1, Kr, prm.dims[0], prm.work, prm.dims[0], 0, prm.U[0], prm.dims[0]);
  dgemm_wrap ('N', 'N', prm.dims[0], prm.rank, prm.dims[0], 1., Kr, prm.dims[0], prm.work, prm.dims[0], 0., prm.U[0], prm.dims[0]);
#else
  zgemm_wrap ('N', 'N', prm.dims[0], prm.rank, prm.dims[0], CMPLX(1.,0.), Kr, prm.dims[0], prm.work, prm.dims[0], CMPLX(0.,0.), prm.U[0], prm.dims[0]);
#endif

  // overwrite work with I_n
  eye (prm.work, n);

  // form Kronecker product kron(I_n,Q)
  kron (Kr, n, n, prm.work, k, k, Q);

  // copy current B into work buffer
#ifndef CPLX
  // cblas_dcopy(prm.dims[1]*prm.rank,prm.U[1],1,prm.work,1);
  dcopy_wrap (prm.dims[1]*prm.rank, prm.U[1], 1, prm.work, 1);
#else
  zcopy_wrap (prm.dims[1]*prm.rank, prm.U[1], 1, prm.work, 1);
#endif

  // apply partial transformation kron(I_n,Q) to B
#ifndef CPLX
  // cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[1], prm.rank, prm.dims[1], 1, Kr, prm.dims[1], prm.work, prm.dims[1], 0, prm.U[1], prm.dims[1]);
  dgemm_wrap ('N', 'N', prm.dims[1], prm.rank, prm.dims[1], 1., Kr, prm.dims[1], prm.work, prm.dims[1], 0., prm.U[1], prm.dims[1]);
#else
  zgemm_wrap ('N', 'N', prm.dims[1], prm.rank, prm.dims[1], CMPLX(1.,0.), Kr, prm.dims[1], prm.work, prm.dims[1], CMPLX(0.,0.), prm.U[1], prm.dims[1]);
#endif

  // copy one component of B to perform RQ
  comp = 0;
  value_t* Bcmp = (value_t*) malloc (prm.dims[1] * sizeof(value_t));
#ifndef CPLX
  // cblas_dcopy(prm.dims[1],prm.U[1]+comp*prm.dims[1],1,Bcmp,1);
  dcopy_wrap (prm.dims[1], prm.U[1]+comp*prm.dims[1], 1, Bcmp, 1);
#else
  zcopy_wrap (prm.dims[1], prm.U[1]+comp*prm.dims[1], 1, Bcmp, 1);
#endif

  // overwrite R with I_n
  eye (R, n);

  // perform RQ of one component of B and form orthogonal factor explicitly (store in R)
  int minnk = (n < k) ? n : k;
  value_t* Bcmp_ptr = (n < k) ? Bcmp+k-n : Bcmp;
  // TODO: ensure workspace allocation
#ifndef CPLX
  // dgerqf_(&k, &n, Bcmp, &k, prm.tau, prm.work, &prm.lwork, &info);
  // dormrq_(&right, &notrans, &n, &n, &minnk, Bcmp_ptr, &k, prm.tau, R, &n, prm.work, &prm.lwork, &info);
  dgerqf_wrap (k, n, Bcmp, k, prm.tau, prm.work, prm.lwork, &info);
  dormrq_wrap ('R', 'N', n, n, minnk, Bcmp_ptr, k, prm.tau, R, n, prm.work, prm.lwork, &info);
#else
  zgerqf_wrap (k, n, Bcmp, k, prm.tau, prm.work, prm.lwork, &info);
  zunmrq_wrap ('R', 'N', n, n, minnk, Bcmp_ptr, k, prm.tau, R, n, prm.work, prm.lwork, &info);
#endif

  // overwrite work with I_k
  eye (prm.work, k);

  // form Kronecker product kron(R,I_k)
  kron (Kr, n, n, R, k, k, prm.work);

  // copy current B into work buffer
#ifndef CPLX
  // cblas_dcopy(prm.dims[1]*prm.rank,prm.U[1],1,prm.work,1);
  dcopy_wrap (prm.dims[1]*prm.rank, prm.U[1], 1, prm.work, 1);
#else
  zcopy_wrap (prm.dims[1]*prm.rank, prm.U[1], 1, prm.work, 1);
#endif

  // apply partial transformation kron(R,I_k) to B
#ifndef CPLX
  // cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[1], prm.rank, prm.dims[1], 1, Kr, prm.dims[1], prm.work, prm.dims[1], 0, prm.U[1], prm.dims[1]);
  dgemm_wrap ('N', 'N', prm.dims[1], prm.rank, prm.dims[1], 1., Kr, prm.dims[1], prm.work, prm.dims[1], 0., prm.U[1], prm.dims[1]);
#else
  zgemm_wrap ('N', 'N', prm.dims[1], prm.rank, prm.dims[1], CMPLX(1.,0.), Kr, prm.dims[1], prm.work, prm.dims[1], CMPLX(0.,0.), prm.U[1], prm.dims[1]);
#endif

  // form Kronecker product kron(R,P)
  kron (Kr, n, n, R, m, m, P);

  // copy current C into work buffer
#ifndef CPLX
  // cblas_dcopy(prm.dims[2]*prm.rank,prm.U[2],1,prm.work,1);
  dcopy_wrap (prm.dims[2]*prm.rank, prm.U[2], 1, prm.work, 1);
#else
  zcopy_wrap (prm.dims[2]*prm.rank, prm.U[2], 1, prm.work, 1);
#endif

  // apply transformation kron(R,P) to C
#ifndef CPLX
  // cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[2], prm.rank, prm.dims[2], 1, Kr, prm.dims[2], prm.work, prm.dims[2], 0, prm.U[2], prm.dims[2]);
  dgemm_wrap ('N', 'N', prm.dims[2], prm.rank, prm.dims[2], 1., Kr, prm.dims[2], prm.work, prm.dims[2], 0., prm.U[2], prm.dims[2]);
#else
  zgemm_wrap ('N', 'N', prm.dims[2], prm.rank, prm.dims[2], CMPLX(1.,0.), Kr, prm.dims[2], prm.work, prm.dims[2], CMPLX(0.,0.), prm.U[2], prm.dims[2]);
#endif

  free (R);
  free (P);
  free (Q);
  free (s);
  free (Acmp);
  free (Bcmp);
  free (Kr);
  return;
}
