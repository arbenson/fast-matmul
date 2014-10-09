Fast matrix multiplication
--------
Austin R. Benson and Grey Ballard

This software contains implementations of fast matrix multiplication algorithms for
sequential and shared-memory parallel environments.

Copyright 2014 Sandia Corporation. Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive license for use of this work by or on behalf of the U.S. Government. Export of this program may require a license from the United States Government.

Setup
--------
The code requires:
* Intel MKL
* Compiler supporting C++11 and OpenMP

The Makefile depends on an included file that specifies the compiler and the run-time mode.
You must specify this file in the first line of the Makefile.
For an example, see the file `make.incs/make.inc.edison`, which contains the information for running
on NERSC's Edison machine.
The `MODE` variable specifies sequential or parallel mode.
The `DEFINES` variable can specifies the type of parallelism if running in parallel mode.
The `MKL_ROOT` variable must be set for your machine.

We did most testing using the Intel compiler (icpc).
Depending on the version of g++, the OpenMP task constructs can be different and the hybrid shared-memory
parallel code may crash.  Sequential mode, DFS parallel, and BFS parallel should work with g++.

Building examples
--------
First, use the code generator to generate the algorithms:
          
	cd codegen
	bash gen_all_algorithms.sh 0

Some simple codes that use the fast algorithms are in the `examples` directory.
For example, you can build and run the (4, 3, 3) algorithm:

	make fast433
	./build/fast433

Building tests
--------

We now assume that all of the algorithms have been gernated with the code generator (see above).
The tests are built and run with:

    make matmul_tests
	./build/matmul_tests -all 1

The tests are just for correctness of the algorithms, not for performance.
You should see output like:

    STRASSEN_1: 257, 500, 55
    Maximum relative difference: 3.87253e-15

This test runs one step of Strassen's algorithm, multiplying a 257 x 500 matrix with a 500 x 55 matrix.
The maximum relative difference is an error measure:

    max_{ij} |C_{ij} - D_{ij}| / |C_{ij}|,

where C is the result computed with the fast algorithm and D is the result computed with the classical algorithm.
For all of the exact fast algorithms, the error should be around 1e-14 or 1e-15.
The approximate algorithms (e.g., Bini's) have larger error.
Typically, additional recursive steps leads to a larger error.


Building with different parallel methods
--------

The BFS, DFS, and HYBRID parallel algorithms are compile-time options.
In your make include file in the `make.incs` directory, to use DFS:

    MODE=openmp
    DEFINES += -D_PARALLEL_=1

Switch the `_PARALLEL_` define to 2 for BFS or 3 for HYBRID.
For an example, run

    make fast424
    ./build/fast424



DGEMM curve benchmarks
--------
Build and run the benchmark for the dgemm curves:
	
	make dgemm_curves
	./build/dgemm_curves 1  # N x N x N
	./build/dgemm_curves 2  # N x 800 x N
	./build/dgemm_curves 3  # N x 800 x 800

The output is a semi-colon separated list, where each item loooks like:

    M K N num_trials time;

The M, K, and N terms specify the matrix dimensions: M x K multiplied by K x N.
The time is in milliseconds and is the total time to run num_trials multiplies.
For example,

	1200 800 1200 5 104.87;

means that it took 104.87 milliseconds to multiply a 1200 x 800 matrix by a 800 x 1200 matrix five times.
To build with parallelism enabled, you need to define the `_PARALLEL_` (see `make.incs/make.inc.linux`).
To run without dynamic threads (i.e., mkl_set_dynamic(0)), append a second argument, e.g.:

	./build/dgemm_curves 1 1  # Square timings without dynamic thread allocation



Fast algorithms benchmarks
--------
Build benchmarking code for all of the fast algorithms:

    make matmul_benchmarks

The build takes a while because we are compiling all of the algorithms.
To run a small test to benchmark MKL against Strassen with one, two, and three levels of recursion:

    ./build/matmul_benchmarks -square_test 1

The output format is specified in `data/README.md`.

To run all of the benchmarks for the tall-and-skinny matrix multiplied by a small square matrix (N x k x k for fixed k):

    ./build/matmul_benchmarks -ts_square_like 1


