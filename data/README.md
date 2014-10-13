Performance data collected on Edison.

* `all_parallel_algs`: main performance data of parallel fast matrix multiplication algorithms

* `all_sequential_algs`: main performance data of sequential fast matrix multiplication algorithms

* `dalberto`: data from the Strassen-Winograd implementation of D'Alberto et al.

* `dgemm_curves`: performance data of Intel MKL's dgemm

* `hybrid_bfs_dfs_comparisons`: benchmarking data for the different parallel methods

* `matrix_additions`: benchmarking data for the different matrix addition methods

The output is formatted for Matlab, which we use for plotting.
The data typically looks like:

    FAST442_26_257_1 = [ 9000 9000 9000 1 3169.76 ;  9500 9500 9500 1 3731.69 ;  10000 10000 10000 1 4316.75 ; ];

The semicolons separate data points.
Each data point is

    P Q R steps time,

where P, Q, and R signify multiplication of a P x Q matrix by a Q x R matrix, steps is the number of recursive steps, and time is the running time in ms.
The time is the median of five trials.
The name FAST442_26_257_1 means that this was the <4, 4, 2> fast matrix multiplication algorithm with 26 multiplies, 257 non-zeros in the factor matrices, and 1 step of recursion.
To get the effective GFLOPS performance, you can use, for example (in Matlab):

    eff_gflops = @(X) (X(:, 1) .* X(:, 3) .* (2 * X(:, 2) - 1) / 1e9) / (X(:, 5) / 1e3);
    perf = eff_gflops(FAST442_26_257_1);
