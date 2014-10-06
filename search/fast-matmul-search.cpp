// ************************************************************************
// Alternating Least Squares for Fast Matrix Multiplication Algorithm
//
// Grey Ballard
// ************************************************************************

#include "aux.h"
#include "RandomMT.h"
#include "kernels.h"

void usage(char **argv)
{
	printf("Usage: %s [options]\n",argv[0]);
	printf("options:\n");
	printf("	--m <int>                 first matrix dimension (rows of A / rows of C)\n");
	printf("	--k <int>                 second matrix dimension (cols of A / rows of B)\n");
	printf("	--n <int>                 third matrix dimension (cols of B / cols of C)\n");
	printf("	--rank <int>              rank of factorization\n");
	printf("	--method <string>         choose from the following options:\n");
	printf("					- als: use alternating least squares to iteratively improve residual\n");
	printf("					- sparsify: apply transformation to solution to inject sparsity (does not affect residual)\n");
	printf("					- round: round factor matrices to nearest power of two\n");
	printf("	--maxiters <int>          maximum iterations to perform per initial guess\n");
	printf("	--maxsecs <int>           maximum time (in sec) to use per initial guess\n");
	printf("	--printitn <int>          print every <int>th iteration; 0 for no printing is default\n");
	printf("	--printtol <float>        print info if residual breaks threshold\n");
	printf("	--tol <float>             stopping tolerance (change in residual norm squared)\n");
	printf("	--seed <int>              seed for random number generator used in initial guess\n");
	printf("	--numseeds <int>          number of seeds to try\n");
	printf("	--alpha <float>           regularization weighting parameter\n");
	printf("	--M <int>                 regularization parameter for max number of nonzeros sought in factor matrices (same for all 3)\n");
	printf("	--M{0,1,2} <int>          regularization parameter for max number of nonzeros in factor matrix {0,1,2}\n");
	printf("	--rndfin                  rounds final solution to nearest power of two\n");
	printf("	--pwrof2                  sets power of two for rounding\n");
	printf("	--verbose                 print more information\n");

}

int main(int argc, char* argv[])
{

    // Print help if necessary
	bool help = read_bool(argc, argv, "--help", false);
	if ((argc < 2) || (help)) {
		usage(argv);
		return 0;
	}
	
	// Use parameters struct for passing parameters to kernels efficiently
	parameters prm;
	
	// Parse inputs
	prm.matDims[0] = read_int(argc, argv, "--m", 2);
	prm.matDims[1] = read_int(argc, argv, "--k", 2);
	prm.matDims[2] = read_int(argc, argv, "--n", 2);
	prm.rank = read_int(argc, argv, "--rank", 7);
	prm.method = read_string(argc, argv, "--method", (char *)"als");
	int maxIters = read_int(argc, argv, "--maxiters", 1000);
	int maxSecs = read_int(argc, argv, "--maxsecs", 1000);
	double tol = read_double(argc, argv, "--tol", 1e-8);
	int printItn = read_int(argc, argv, "--printitn", 0);
	double printTol = read_double(argc, argv, "--printtol", 1.0);
	int seed = read_int(argc, argv, "--seed", 0);
	int numSeeds = read_int(argc, argv, "--numseeds", 1);
	bool verbose = read_bool(argc, argv, "--verbose", false);
	prm.rnd_maxVal = read_double(argc,argv,"--maxval",1.0);
	prm.rnd_pwrOfTwo = read_int(argc,argv,"--pwrof2",0);
	bool roundFinal = read_bool(argc, argv, "--rndfin",false);
	prm.alpha = read_double(argc,argv, "--alpha", 0.1);
	int M = read_int(argc,argv, "--M", 0);
	if (M)
	{
	    prm.M[0] = M;
	    prm.M[1] = M;
	    prm.M[2] = M;
	} else {	    
	    prm.M[0] = read_int(argc, argv, "--M0", -1);
	    prm.M[1] = read_int(argc, argv, "--M1", -1);
	    prm.M[2] = read_int(argc, argv, "--M2", -1);
	}
	char * infile = read_string(argc, argv, "--input", NULL);
	char * outfile = read_string(argc, argv, "--output", NULL);
		
	if (verbose) {
        setbuf(stdout, NULL);
        printf("\n\n---------------------------------------------------------\n");
    	printf("PARAMETERS\n");
    	printf("dimensions = %d %d %d\n",prm.matDims[0],prm.matDims[1],prm.matDims[2]);
    	printf("rank       = %d\n",prm.rank);
    	printf("method     = %s\n",prm.method);
    	if (infile)
    	    printf("input      = %s\n",infile);
    	else
    	{
    	    if (numSeeds == 1)
    	        printf("input      = seed %d\n",seed); 
    	    else
    	        printf("inputs     = seeds %d-%d\n",seed,seed+numSeeds-1);
    	}
    	if (outfile)
    	    printf("output     = %s\n",outfile);
    	else
    	    printf("output     = none\n"); 
    	if (!strcmp(prm.method,"als"))
    	{
    	    printf("tol        = %1.2e\n",tol);
    	    printf("alpha      = %1.2e\n",prm.alpha);
            printf("M's        = (%d,%d,%d)\n",prm.M[0],prm.M[1],prm.M[2]);
            printf("maxiters   = %d\n",maxIters);
    	    printf("maxsecs    = %d\n",maxSecs);
    	    printf("printitn   = %d\n",printItn);
    	    printf("printtol   = %1.2e\n",printTol);
    	}
        printf("---------------------------------------------------------\n");
    }
    
    // Initialize other variables
	int i, j, k, numIters, mkn, tidx[3];
    double err, errOld, errChange = 0.0, start_als, start_search, elapsed, threshold;
    
    // Compute tensor dimensions
    prm.dims[0] = prm.matDims[0]*prm.matDims[1];
    prm.dims[1] = prm.matDims[1]*prm.matDims[2];
    prm.dims[2] = prm.matDims[0]*prm.matDims[2];
                
    // Compute tensor's nnz, total number of entries, and Frobenius norm
    mkn = prm.matDims[0]*prm.matDims[1]*prm.matDims[2];
    prm.mkn2 = mkn*mkn;
    prm.xNorm = sqrt(mkn);
        
    // Compute number of columns in matricized tensors
    for (i = 0; i < 3; i++)
        prm.mtCols[i] = prm.mkn2 / prm.dims[i];
        
    // Construct three matricizations of matmul tensor
    prm.X = (double**) malloc( 3 * sizeof(double*) );
    for (i = 0; i < 3; i++)
        prm.X[i] = (double*) calloc( prm.mkn2, sizeof(double) );
    for (int mm = 0; mm < prm.matDims[0]; mm++)
        for (int kk = 0; kk < prm.matDims[1]; kk++)
            for (int nn = 0; nn < prm.matDims[2]; nn++)
            {
                tidx[0] = mm + kk*prm.matDims[0];
                tidx[1] = kk + nn*prm.matDims[1];
                tidx[2] = mm + nn*prm.matDims[0];
                prm.X[0][tidx[0]+prm.dims[0]*(tidx[1]+prm.dims[1]*tidx[2])] = 1;
                prm.X[1][tidx[1]+prm.dims[1]*(tidx[0]+prm.dims[0]*tidx[2])] = 1;
                prm.X[2][tidx[2]+prm.dims[2]*(tidx[0]+prm.dims[0]*tidx[1])] = 1;
            }
                
    // Allocate factor weights and matrices: working, initial, and model
    prm.lambda = (double*) malloc( prm.rank * sizeof(double) );
    prm.U  = (double**) malloc( 3 * sizeof(double*) );
    double** U0 = (double**) malloc( 3 * sizeof(double*) );
    prm.model = (double**) malloc( 3 * sizeof(double*) );
    for (i = 0; i < 3; i++)
    {
        prm.U[i] =  (double*) calloc( prm.mkn2, sizeof(double) );
        U0[i] = (double*) calloc( prm.dims[i]*prm.rank, sizeof(double) );
        prm.model[i] = (double*) calloc( prm.dims[i]*prm.rank, sizeof(double) );
    }
    
    // Allocate coefficient matrix within ALS (Khatri-Rao product) 
    int maxMatDim = prm.matDims[0];
    if (maxMatDim < prm.matDims[1]) maxMatDim = prm.matDims[1];
    if (maxMatDim < prm.matDims[2]) maxMatDim = prm.matDims[2];
    prm.A = (double*) malloc( maxMatDim*mkn*prm.rank * sizeof(double) );
    
    // Allocate workspaces
    prm.tau = (double*) malloc( mkn * sizeof(double) );
    prm.lwork = maxMatDim*mkn*prm.rank;
    prm.work = (double*) malloc( prm.lwork * sizeof(double) );
    prm.iwork = (int*) malloc( prm.mkn2 * sizeof(int) );    
    
    // Allocate matrices for normal equations 
    int maxDim = prm.dims[0];
    if (maxDim < prm.dims[1]) maxDim = prm.dims[1];
    if (maxDim < prm.dims[2]) maxDim = prm.dims[2];
    prm.NE_coeff = (double*) malloc( prm.rank*prm.rank * sizeof(double) );
    prm.NE_rhs = (double*) malloc( maxDim*prm.rank * sizeof(double) );
    prm.residual = (double*) malloc( prm.mkn2 * sizeof(double) );
            
    //--------------------------------------------------
    // Search Loop
    //--------------------------------------------------
    int mySeed = seed, numGoodSeeds = 0, statusCnt = 0, status = 1;
    start_search = wall_time(); 
    for (int seed_cnt = 0; seed_cnt < numSeeds; ++seed_cnt)
    {
        // Set starting point from random seed (match Matlab Tensor Toolbox)
        RandomMT cRMT(mySeed);
        for (i = 0; i < 3; i++)
            for (j = 0; j < prm.dims[i]; j++)
                for (k = 0; k < prm.rank; k++)
                    U0[i][j+k*prm.dims[i]] = cRMT.genMatlabMT();
        for (i = 0; i < prm.rank; i++)
            prm.lambda[i] = 1.0;  
            
        // Copy starting point
        for (i = 0; i < 3; i++)
            cblas_dcopy(prm.dims[i]*prm.rank,U0[i],1,prm.U[i],1); 
            
        // read from file if input is given    
        if( infile )
	    read_input( infile, prm ); 

        if (verbose)
        { 
            printf("\nSTARTING POINT...\n");
            for (i = 0; i < 3; i++)
            {
                printf("Factor matrix %d:\n",i);
                print_matrix(prm.U[i],prm.dims[i],prm.rank,prm.dims[i]);
            }
            printf("\n");
        }   
                
        //--------------------------------------------------
        // Main ALS Loop
        //--------------------------------------------------
        start_als = wall_time();
        err = 1.0; 
        threshold = 1e-4;
        for (numIters = 0; numIters < maxIters && (wall_time()-start_als) < maxSecs; numIters++)
        {
            errOld = err;

            if (!strcmp(prm.method,"als"))
            {
                // Perform an iteration of ALS using NE with Smirnov's penalty term
                err = als( prm );
            }
            else if (!strcmp(prm.method,"sparsify"))
            {   
                // print stats before sparsifying
                printf("Old residual: %1.2e\n",compute_residual(prm,2,true));
                printf("Old nnz (larger than %1.1e): %d %d %d\n", threshold, nnz(prm.U[0],prm.dims[0]*prm.rank,threshold), nnz(prm.U[1],prm.dims[1]*prm.rank,threshold), nnz(prm.U[2],prm.dims[2]*prm.rank,threshold) );
                
                // sparsify and return
                printf("\nSparsifying...\n\n");
                sparsify( prm );
                numIters = maxIters;
                
                // print stats after sparsifying
                printf("New residual: %1.2e\n",compute_residual(prm,2,true));
                printf("New nnz (larger than %1.1e): %d %d %d\n", threshold, nnz(prm.U[0],prm.dims[0]*prm.rank,threshold), nnz(prm.U[1],prm.dims[1]*prm.rank,threshold), nnz(prm.U[2],prm.dims[2]*prm.rank,threshold) );
            }
            else if (!strcmp(prm.method,"round"))
            {
                // print stats before rounding
                printf("Old residual: %1.2e\n",compute_residual(prm,2,true));
                printf("Old nnz (larger than %1.1e): %d %d %d\n", threshold, nnz(prm.U[0],prm.dims[0]*prm.rank,threshold), nnz(prm.U[1],prm.dims[1]*prm.rank,threshold), nnz(prm.U[2],prm.dims[2]*prm.rank,threshold) );
                // round and return
                for (i = 0; i < 3; i++)
                {
                    capping(prm.U[i],prm.dims[i]*prm.rank,prm.rnd_maxVal);
                    rounding(prm.U[i],prm.dims[i]*prm.rank,prm.rnd_pwrOfTwo);
                }
                numIters = maxIters;
                
                // print stats after rounding
                printf("New residual: %1.2e\n",compute_residual(prm,2,true));
                printf("New nnz (larger than %1.1e): %d %d %d\n", threshold, nnz(prm.U[0],prm.dims[0]*prm.rank,threshold), nnz(prm.U[1],prm.dims[1]*prm.rank,threshold), nnz(prm.U[2],prm.dims[2]*prm.rank,threshold) );
            }
            else
                die("Invalid method\n");   
                                                           
            // Compute change in relative residual norm
            errChange = fabs(err - errOld);          

            // Print info at current iteration
            if ((printItn > 0) && (((numIters + 1) % printItn) == 0))
            {                
                // print info                    
                printf ("Iter %d: residual = %1.5e change = %1.5e\n", numIters + 1, err, errChange);
            } 

            // Check for convergence 
            if ( numIters > 0 && errChange < tol )
                break;
            
        }
        
        // If rounding, round final solution and re-compute residual
        if(roundFinal)
        {
            // normalize columns in A and B factors, put arbitrary weights into C
            normalize_model( prm, 2 );
        
            // cap large values and round to nearest power of 2
            for (i = 0; i < 3; i++)
            {
                capping(prm.U[i],prm.dims[i]*prm.rank,prm.rnd_maxVal);
                rounding(prm.U[i],prm.dims[i]*prm.rank,prm.rnd_pwrOfTwo);
            }
            
            err = compute_residual(prm,0,true);
        }    
        
        // Print status if searching over many seeds
        statusCnt++;
        if (numSeeds > 1000 && statusCnt == numSeeds/10)
        {
            printf("...%d%% complete...\n",10*status);
            status++;
            statusCnt = 0;
        }
    
        // Print final info
        elapsed = wall_time() - start_als;
        if ((printItn > 0 || verbose) && !strcmp(prm.method,"als"))
        {
            if (infile)
                printf("\nInput %s ",infile);
            else
                printf("\nInitial seed %d ",mySeed);
            printf("achieved residual %1.3e in %d iterations and %1.3e seconds\n \t final residual change: %1.3e\n \t average time per iteration: %1.3e s\n", err, numIters, elapsed, errChange, elapsed/numIters);
        }
        
        if (verbose)
        {
            printf("\nSOLUTION...\n");
            for (i = 0; i < 3; i++)
            {
                printf("Factor matrix %d:\n",i);
                if (roundFinal || !strcmp(prm.method,"round"))
                    print_int_matrix(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.rnd_pwrOfTwo);
                else
                    print_matrix(prm.U[i],prm.dims[i],prm.rank,prm.dims[i]);
            }
        }
        else if (err < printTol)
        {
            numGoodSeeds++;

            printf("\n\n***************************************\n");
            if (infile)
                printf("\nInput %s: ",infile);
            else
                printf("\nInitial seed %d: ",mySeed);
            printf("after %d iterations, achieved residual %1.3e with final residual change of %1.3e\n", numIters, err, errChange);
            if (roundFinal)
            {
            
                for (i = 0; i < 3; i++)
                {
                    printf("Factor matrix %d:\n",i);
                    print_int_matrix(prm.U[i], prm.dims[i], prm.rank, prm.dims[i], prm.rnd_pwrOfTwo);
                }
        
                int count = 0;
                for (i = 0; i < 3; i++)
                    count += nnz(prm.U[i],prm.dims[i]*prm.rank);
                printf("\ttotal nnz in solution: %d\n",count);
                printf("\tnaive adds/subs:       %d\n",count - prm.dims[2] - 2*prm.rank);
            }
            printf("***************************************\n\n\n");
        }
                               
        // write to output
        if( outfile )
	        write_output( outfile, prm ); 
        
        mySeed++;
    }      
    
    // Final report of processor statistics
    elapsed = wall_time()-start_search;
    
    // Print stats
    if (!strcmp(prm.method,"als"))
    {
        printf("\n\n------------------------------------------------------------\n");
        printf("Time elapsed:                \t%1.1e\tseconds\n",elapsed);
        printf("Total number of seeds tried: \t%d\n",numSeeds);
        printf("Total number of good seeds:  \t%d",numGoodSeeds);
        printf("\t(residual < %2.1e)\n",printTol);   
        printf("------------------------------------------------------------\n");
    }

    
    // free allocated memory
    for (i = 0; i < 3; i++)
    {
        free( prm.X[i] );
        free( prm.U[i] );
        free( U0[i] );
        free( prm.model[i] );
    } 
    free( prm.X );
    free( prm.U );
    free( U0 );
    free( prm.model );
    free( prm.lambda );
    free( prm.A );
    free( prm.NE_coeff );
    free( prm.NE_rhs );
    free( prm.residual );
    free( prm.tau );
    free( prm.work );
    free( prm.iwork );
        
	return 0;
	
}
