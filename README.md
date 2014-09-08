Fast matrix multiplication
--------
Austin R. Benson and Grey Ballard

This software contains implementations of fast matrix multiplication algorithms for
sequential and shared-memory parallel environments.

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
	./out/fast433

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


Building benchmarks
--------
Build the benchmarking code:

    make benchmark	 

Run the dgemm curves:
	
	make dgemm_curves
	./out/dgemm_curves 1  # Square timings
	./out/dgemm_curves 2  # Outer product timings
	./out/dgemm_curves 3  # Inner-square timings

To run without dynamic threads (mkl_set_dynamic(0)), append a second argument, e.g.:

	./out/dgemm_curves 1 1  # Square timings without dynamic thread allocation
