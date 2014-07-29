Fast matrix multiplication
--------
Austin R. Benson and Grey Ballard


The codes here are implementations of fast matrix multiplication algorithms.

Building examples
--------
Some simple fast algorithm examples are located in the `examples` directory.

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
