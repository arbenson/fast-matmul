Fast matrix multiplication
--------
Austin R. Benson and Grey Ballard


The codes here are implementations of fast matrix multiplication algorithms.


Build the benchmarking code:
    make benchmark	 

Run the dgemm curves:
	
	make dgemm_curves
	./dgemm_curves 1  # Square timings
	./dgemm_curves 2  # Outer product timings
	./dgemm_curves 3  # Inner-square timings

To run without dynamic threads (mkl_set_dynamic(0)), append a second argument, e.g.:

	./dgemm_curves 1 1  # Square timings without dynamic thread allocation

