#include "linalg.hpp"
#include "hk332_15_94.hpp"

#include <stdlib.h>

#include <chrono>
#include <random>

int main(int argc, char **argv) {
    int m = 900;
    int k = 900;
    int n = 200;
    int numsteps = 1;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    std::cout << "Running classical gemm..." << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    Gemm(A, B, C1);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Classical gemm took "
	      << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
	      << " milliseconds"
	      << std::endl;

    std::cout << "Running fast matmul..." << std::endl;
    auto t3 = std::chrono::high_resolution_clock::now();
    hk332_15_94::FastMatmul(A, B, C2, numsteps);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
	      << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
	      << " milliseconds"
	      << std::endl;


    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
