This directory contains code for searching for fast matrix multiplication algorithms.

To compile, first uncomment the appropriate lines in the Makefile.
Then, on a Mac:

    make

On Linux, first set the MKL variables (your path may be different) and then run make:

   /opt/intel/composerxe/mkl/bin/mklvars.sh 
   make

See run-time options:

    ./fast-matmul-search

Run search for a rank 7 solution to 2x2x2 multiplication with regularization parameters set to encourage 12 nonzeros in each of the factor matrices and with 10 seeds.

    ./fast-matmul-search --m 2 --k 2 --n 2 --rank 7 --M 12 --rndfin --numseeds 10

See other examples and options:

    more examples.txt

Run all of the examples (should take less than a minute):

    sh examples.txt


There are three main methods implemented in the code...
    The "als" method is the primary tool, as it uses alternating least squares with regularization to iteratively improve the size of the residual.  The initial guess can be set randomly (with options "seed" and "numseeds") or determined by an input file (with option "input").  The regularization parameters are set with options "alpha" (the weight of the regularization term) and "M" or "M{0,1,2}" (the target numbers of nonzeros in the factor matrices).  The "rndfin" and "pwrof2" options can be used to round the final solution to determine whether an exact discrete solution has been found.
    The "sparsify" method transforms dense factor matrices so that some entries in the first columns of U and V are guaranteed to be zero (to machine precision) without changing the size of the residual.  In practice, several more small entries are usually created.  This method is useful in jump-starting the sparsification process of an accurate dense solution.  If sparsity exists in the input factor matrices, this transformation can result in more nonzeros overall.
    The "round" method rounds each of the entries in the factor matrices to a nearest power of two (set by "pwrof2" option).  Unless an exact solution is found, this method typically increases the size of the residual.  Rounding can be helpful in the sparsification process to incourage nonzero values to converge to discrete values.
  
