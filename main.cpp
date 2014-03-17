#include "fast3x3.hpp"

#include <math.h>
#include <stdlib.h>

#include <chrono>  // note: C++11
#include <random>

// Build with: g++ main.cpp -std=c++0x -O3 -lblas -o test
// Use with:
//    ./test n base
// n is the size of the matrix (default 2187)
// base is the cutoff for recursion (default 729)

int main(int argc, char **argv) {
    int n = 2187;
    int base = 729;
    if (argc > 1) {
	n = atoi(argv[1]);
    }
    if (argc > 2) {
	base = atoi(argv[2]);
    }

    std::cout << "n is: " << n << std::endl;
    std::cout << "base case is: " << base << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1e5);

    Matrix<double> A(n);
    Matrix<double> B(n);
    Matrix<double> C1(n);
    for (int j = 0; j < n; ++j) {
	for (int i = 0; i < n; ++i) {
	    A.data()[i + j * A.stride()] = dist(gen);
	    B.data()[i + j * B.stride()] = dist(gen);
	}
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    Gemm(A, B, C1);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Normal gemm took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds"
	      << std::endl;

    Matrix<double> C2(n);
    t1 = std::chrono::high_resolution_clock::now();
    FastMatmul3x3(A, B, C2, base);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds"
	      << std::endl;

    // Test for correctness
    double diff = 0.0;
    for (int j = 0; j < n; ++j) {
	for (int i = 0; i < n; ++i) {
	    double c1 = C1.data()[i + j * C1.stride()];
	    double c2 = C2.data()[i + j * C2.stride()];
	    diff += (c1 - c2) * (c1 - c2);
	}
    }
    std::cout << "Frobenius norm solution difference: "
	      << sqrt(diff)
	      << std::endl;
}
