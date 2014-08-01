Fast matrix multiplication
--------
Austin R. Benson and Grey Ballard

This software contains implementations of fast matrix multiplication algorithms for
sequential and shared memory.

Setup
--------
The code requires:
* Intel MKL
* Compiler supporting C++11

Building examples
--------
Some simple codes that use the fast algorithms are in the `examples` directory.
For example, you can build and run the (4, 3, 3) algorithm:

	make fast433
	./out/fast433

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


LU and QR
--------
Build with:

    make fast_lu fast_qr
