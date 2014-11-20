#include "kernels.h"

void read_input( char* filename, parameters & prm )
{
	int i,j,k; 

	// open file for reading
	FILE *fp = fopen( filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open input file!\n");
		exit(1);
	}

	// file format assumed to be U then V then W, each with rank columns
	// lines starting with "#" can separate matrices
	char line[10000], *p;
	for( k = 0; k < 3; k++ ) {
		// skip lines starting with #
		do { fgets(line, sizeof line, fp); } while (*line == '#');
		for( i = 0; i < prm.dims[k]; i++ ) {

			// tokenize line
			p = strtok(line, " ");

			// read matrix entries
			for( j = 0; j < prm.rank; j++ ) {
				prm.U[k][j*prm.dims[k]+i] = atof(p);
				p = strtok(NULL, " ");
			}

			// read next line
			fgets(line, sizeof line, fp);
		}
	}

	// close file
	fclose( fp );
}

void write_output( char* filename, parameters & prm )
{
	int i,j,k;

	// open file for (over-)writing
	FILE *fp = fopen( filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Can't open output file!\n");
		exit(1);
	}

	// write to file
	char entry[10000];
	for( k = 0; k < 3; k++ ) {
		fputs("#\n",fp);
		for( i = 0; i < prm.dims[k]; i++ ) {
			for( j = 0; j < prm.rank; j++ ) {
				sprintf(entry,"%.20e ",prm.U[k][j*prm.dims[k]+i]);
				fputs(entry,fp);
			}
			fputs("\n",fp);
		}
	}

	// close file
	fclose( fp );  
}

// Performs one (outer) iteration of Alternating Least Squares by solving normal equations
// with extra term in the objective to penalize deviation from model solution
//  - obj fcn is ||Ax-b||^2 + alpha * ||x-model||^2
//  - normal equations are (A^TA + alpha I) x = A^Tb + alpha model
//  - if model = 0, same as Tikhonov regularization or ridge regression
//  - note that model is stored as transpose of factor matrix
//  - treats everything as dense, using 3 matricizations of the tensor
//  - returns square of Frobenius norm of residual (ignoring extra term)
double als(parameters & prm)
{
	int i, j, k, info;
	char lower = 'L';

	// Iterate over factor matrices
	// Solve Ui*(Ai^T*Ai) = Xi*Ai for Ui, Ai is ith reverse Khatri-Rao product
	for (i = 0; i < 3; i++)
	{         
		// compute coefficient matrix Ai
		rev_khatri_rao(prm.A, prm.rank, prm.U, prm.dims, prm.dims, i);

		// form normal equations coefficients NE_coeff = Ai^T * Ai
		cblas_dsyrk(CblasColMajor, CblasLower, CblasTrans, prm.rank, prm.mtCols[i], 1.0, prm.A, prm.mtCols[i], 0.0, prm.NE_coeff, prm.rank);

		// add alpha*I to NE coefficient matrix
		for (j = 0; j < prm.rank; j++)
			prm.NE_coeff[j+j*prm.rank] += prm.alpha;

		// compute NE right-hand-side = Ai^T * Xi^T
		cblas_dgemm(CblasColMajor, CblasTrans, CblasTrans, prm.rank, prm.dims[i], prm.mtCols[i], 1.0, prm.A, prm.mtCols[i], prm.X[i], prm.dims[i], 0.0, prm.NE_rhs, prm.rank);

		// copy transpose of scaled previous solution to model 
		for (j = 0; j < prm.dims[i]; j++)
			for (k = 0; k < prm.rank; k++)
				prm.model[i][k+j*prm.rank] = prm.U[i][j+k*prm.dims[i]];

		// set all but largest M entries to zero
		setSmallestToZero(prm.model[i], prm.work, prm.iwork, prm.rank*prm.dims[i], prm.M[i]);

		// cap model values
		capping(prm.model[i], prm.rank*prm.dims[i], prm.rnd_maxVal);

		// add alpha * model^T to right hand side
		cblas_daxpy(prm.dims[i]*prm.rank,prm.alpha,prm.model[i],1,prm.NE_rhs,1);

		// solve (Ai^T*Ai + alpha * I) * Ui^T = Ai^T * Xi^T + alpha * modeli^T for Ui^T
		dposv_(&lower, &prm.rank, &prm.dims[i], prm.NE_coeff, &prm.rank, prm.NE_rhs, &prm.rank, &info);

		// transpose solution
		for (j = 0; j < prm.dims[i]; j++)
			for (k = 0; k < prm.rank; k++)
				prm.U[i][j+k*prm.dims[i]] = prm.NE_rhs[k+j*prm.rank];

	}

	// Return squared norm of absolute residual
	return compute_residual( prm, 2, false );
}

// Computes the residual (squared absolute Frobenius norm)
//  - eqn determines which matrix unfolding to use: || X_(eqn) - U[eqn]*(KR_(-eqn))^T ||
double compute_residual( parameters & prm, int eqn, bool recompute )
{
	double resnrm;

	// fill in matricized tensor
	cblas_dcopy(prm.mkn2, prm.X[eqn], 1, prm.residual, 1);

	// put weights back in factor matrix
	//scale_columns(prm.U[eqn], prm.dims[eqn], prm.rank, prm.dims[eqn], prm.lambda, false);

	// recompute coefficient matrix if necessary
	if (recompute)
		rev_khatri_rao(prm.A, prm.rank, prm.U, prm.dims, prm.dims, eqn);

	// compute residual matrix
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, prm.dims[eqn], prm.mtCols[eqn], prm.rank, 1.0, prm.U[eqn], prm.dims[eqn], prm.A, prm.mtCols[eqn], -1.0, prm.residual, prm.dims[eqn]);

	// compute norm
	resnrm = cblas_dnrm2(prm.mkn2, prm.residual, 1);

	// take weights back out of factor matrix
	//scale_columns(prm.U[eqn], prm.dims[eqn], prm.rank, prm.dims[eqn], prm.lambda, true);

	return resnrm*resnrm;

}

// Normalizes all columns of matrix, storing norms in separate array
void normalize_columns(double* A, int m, int n, int lda, double* norms)
{
	int max_idx;
	double nrm;
	for (int i = 0; i < n; i++)
	{
		// Compute INF norm of column
		max_idx =  cblas_idamax(m,A+i*lda,1);
		nrm = fabs(A[max_idx+i*lda]);

		// Compute 2 norm of column
		//nrm = cblas_dnrm2(m,A+i*lda,1);

		// Check for zero norm
		if (nrm == 0) 
			nrm = 1.0;

		// Scale column by reciprocal
		cblas_dscal(m,1/nrm,A+i*lda,1);

		// Update norms array
		norms[i] = nrm;
	}
}

// Scales all columns of matrix using values in separate array
//  - if reciprocal is true, scales by reciprocal of scale values
void scale_columns(double* A, int m, int n, int lda, double* scale, bool reciprocal)
{
	for (int i = 0; i < n; i++)
	{     
		// Scale column
		if (reciprocal)
			cblas_dscal(m,1/scale[i],A+i*lda,1);
		else
			cblas_dscal(m,scale[i],A+i*lda,1);
	}
}

// put all weights of model into ith array
void normalize_model( parameters& prm, int i )
{
	// put lambda weights into array i
	scale_columns(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.lambda, false);

	for( int j = 0; j < 3; ++j)
		if (j != i)
		{
			// pull weights out of factor matrix j, put into i
			normalize_columns(prm.U[j], prm.dims[j], prm.rank, prm.dims[j], prm.lambda);
			scale_columns(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.lambda, false);
		}

	// set lambda weights to ones
	for( int k = 0; k < prm.rank; ++k)
		prm.lambda[k] = 1.0;
}

// Rounds each value to nearest reciprocal power of 2 
//  - pwrOfTwo = 3 implies rounding to nearest 1/8th
void rounding(double* A, int numVals, int pwrOfTwo)
{
	long long prec = pow(2,pwrOfTwo);     
	for (int i = 0; i < numVals; i++)
		A[i] = round(prec * A[i]) / prec;
}

// Caps entries to maximum value (with matching sign) if larger in absolute value
//  - maxVal specifies maximum absolute value 
void capping(double* A, int numVals, double maxVal)
{    
	for (int i = 0; i < numVals; i++)
	{   
		if (A[i] < -maxVal)
			A[i] = -maxVal;
		else if (A[i] > maxVal)
			A[i] = maxVal;
	}
}

// Leave largest M values untouched, set all others to zero
void setSmallestToZero(double* A, double* work, int* indices, int numVals, int M)
{
	// quick return if possible
	if (M < 0)
		return;

	if (M > numVals)
		die("Error with setSmallestToZero: M can't exceed number of entries in matrix\n");

	// initialize working arrays
	for (int i = 0; i < numVals; ++i)
	{
		work[i] = fabs(A[i]);
		indices[i] = i;
	}

	// sort array with indices
	quickSort( work, indices, 0, numVals-1);

	// set smallest entries to zero
	for (int i = 0; i < numVals-M; ++i)
		A[indices[i]] = 0;
}

// Counts number of nonzeros
int nnz(double* A, int n, double threshold)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if ( fabs(A[i]) > threshold )
			count++;
	return count;
}

// computes A = U (*) V where (*) is Khatri-Rao product
void khatri_rao(double* A, int n, double* U, int mU, int ldu, double* V, int mV, int ldv)
{
	double *Ai, *Ui, *Vi;
	for (int i = 0; i < n; i++)
	{
		Ai = A + i*mU*mV;
		Ui = U + i*ldu;
		Vi = V + i*ldv;
		for (int j = 0; j < mU; j++)
		{
			// copy ith column of V into A
			cblas_dcopy(mV,Vi,1,Ai,1);

			// scale column by U_ij
			cblas_dscal(mV,Ui[j],Ai,1);

			// increment Ai
			Ai += mV;
		}
	}
}

// computes U[2] (*) U[1] (*) U[0] with U[idx] excluded from the product
void rev_khatri_rao(double* A, int n, double** U, int* m, int* ldus, int idx)
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
			die("rev_khatri_rao: invalid idx\n");
	}
	return;
}

// computes C = kron(A,B) where A is m x n and B is k x l, so that C is mk x nl
// assumes lda is m, ldb is k, and returns C with ldc mn
void kron( double *C, int m, int n, double* A, int k, int l, double* B)
{
	double *Bptr, *Cptr;

	Cptr = C;

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
				cblas_dcopy(k,Bptr,1,Cptr,1);

				// scale sub-column by A[mm,nn]
				cblas_dscal(k,A[mm+nn*m],Cptr,1);

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
void transpose( double *A, int n )
{
	double tmp;
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < i; ++j )
		{
			tmp = A[i+j*n];
			A[i+j*n] = A[j+i*n];
			A[j+i*n] = tmp;
		}
}

// write identity matrix to array
// assumes lda = n
void eye( double *A, int n )
{
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
		{
			if( i == j )
				A[i+j*n] = 1;
			else
				A[i+j*n] = 0;
		}
}

// uses SVD and QR and "sandwiching" property to inject zeros into factors
//   * this code works for all m, k, and n, but to maximize the number of injected
//     zeros, the order should be m > k > n
void sparsify( parameters & prm )
{
	int m = prm.matDims[0], k = prm.matDims[1], n = prm.matDims[2], comp, info;
	char job = 'A'; // means that orthogonal matrices output from SVD are square
	char right = 'R', notrans = 'N';

	// temporary space for Kronecker products (more than needed)
	double * Kr = (double*) malloc( prm.mkn2 * sizeof(double) );

	// copy one component of A to perform SVD
	comp = 0;
	double * Acmp = (double*) malloc( prm.dims[0] * sizeof(double) );
	cblas_dcopy(prm.dims[0],prm.U[0]+comp*prm.dims[0],1,Acmp,1);

	// temporary space for SVD of Acmp and RQ/LQ of Bcmp
	int minmk = (m<k) ? m : k;
	double * s = (double*) malloc( minmk * sizeof(double) );
	double * P = (double*) malloc( m*m * sizeof(double) );
	double * Q = (double*) malloc( k*k * sizeof(double) );
	double * R = (double*) malloc( n*n * sizeof(double) );

	// perform SVD of one component of A
	dgesvd_( &job, &job, &m, &k, Acmp, &m, s, P, &m, Q, &k, prm.work, &prm.lwork, &info);

	// explicit tranpose    
	transpose( P, m );

	// form Kronecker product kron(Q,P)
	kron( Kr, k, k, Q, m, m, P );

	// copy current A into work buffer
	cblas_dcopy(prm.dims[0]*prm.rank,prm.U[0],1,prm.work,1);

	// apply transformation kron(Q,P) to A
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[0], prm.rank, prm.dims[0], 1, Kr, prm.dims[0], prm.work, prm.dims[0], 0, prm.U[0], prm.dims[0]);

	// overwrite work with I_n
	eye( prm.work, n );

	// form Kronecker product kron(I_n,Q)
	kron( Kr, n, n, prm.work, k, k, Q );

	// copy current B into work buffer
	cblas_dcopy(prm.dims[1]*prm.rank,prm.U[1],1,prm.work,1);


	// apply partial transformation kron(I_n,Q) to B
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[1], prm.rank, prm.dims[1], 1, Kr, prm.dims[1], prm.work, prm.dims[1], 0, prm.U[1], prm.dims[1]);

	// copy one component of B to perform RQ
	comp = 0;
	double * Bcmp = (double*) malloc( prm.dims[1] * sizeof(double) );
	cblas_dcopy(prm.dims[1],prm.U[1]+comp*prm.dims[1],1,Bcmp,1);

	// overwrite R with I_n
	eye( R, n );

	// perform RQ of one component of B and form orthogonal factor explicitly (store in R)
	int minnk = (n<k) ? n : k;
	double * Bcmp_ptr = (n<k) ? Bcmp+k-n : Bcmp;
	dgerqf_(&k, &n, Bcmp, &k, prm.tau, prm.work, &prm.lwork, &info);
	dormrq_(&right, &notrans, &n, &n, &minnk, Bcmp_ptr, &k, prm.tau, R, &n, prm.work, &prm.lwork, &info);

	// overwrite work with I_k
	eye( prm.work, k );

	// form Kronecker product kron(R,I_k)
	kron( Kr, n, n, R, k, k, prm.work );

	// copy current B into work buffer
	cblas_dcopy(prm.dims[1]*prm.rank,prm.U[1],1,prm.work,1);

	// apply partial transformation kron(R,I_k) to B
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[1], prm.rank, prm.dims[1], 1, Kr, prm.dims[1], prm.work, prm.dims[1], 0, prm.U[1], prm.dims[1]);

	// form Kronecker product kron(R,P)
	kron( Kr, n, n, R, m, m, P );

	// copy current C into work buffer
	cblas_dcopy(prm.dims[2]*prm.rank,prm.U[2],1,prm.work,1);

	// apply transformation kron(R,P) to C
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, prm.dims[2], prm.rank, prm.dims[2], 1, Kr, prm.dims[2], prm.work, prm.dims[2], 0, prm.U[2], prm.dims[2]);

	free( R );
	free( P );
	free( Q );
	free( s );
	free( Acmp );
	free( Bcmp );
	free( Kr );
	return;
}

