#include "linalg.hpp"
#include "grey-fast333.hpp"

#include <stdlib.h>
#include <time.h>

#include <chrono>
#include <random>

int main(int argc, char **argv) {
    int m = 2700;
    int k = 2700;
    int n = 2700;
    int numsteps = 2;

    srand (time(NULL));

    Matrix<double> A(m, k);
    Matrix<double> B(k, n);
    Matrix<double> C1(m, n), C2(m, n);
    for (int j = 0; j < A.n(); ++j) {
        for (int i = 0; i < A.m(); ++i) {
            A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
        }
    }
    for (int j = 0; j < B.n(); ++j) {
        for (int i = 0; i < B.m(); ++i) {
            B.data()[i + j * B.stride()] = ((double) rand() / RAND_MAX) * 1024;
        }
    }

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
    grey333_23_152::FastMatmul(A, B, C2, numsteps);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
	      << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
	      << " milliseconds"
	      << std::endl;


    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
