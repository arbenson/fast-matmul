#include "fast3x3.hpp"

#include <stdlib.h>
#include <chrono>  // note: C++11

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

    Matrix<double> A1(n);
    Matrix<double> B1(n);
    Matrix<double> C1(n);
    for (int j = 0; j < n; ++j) {
	for (int i = 0; i < n; ++i) {
	    A1.data()[i + j * A1.stride()] = 0.25;
	    B1.data()[i + j * B1.stride()] = 0.125;
	    C1.data()[i + j * C1.stride()] = 1.0;
	}
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    gemm(A1, B1, C1);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Normal gemm took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds"
	      << std::endl;

    Matrix<double> A2(n);
    Matrix<double> B2(n);
    Matrix<double> C2(n);
    for (int j = 0; j < n; ++j) {
	for (int i = 0; i < n; ++i) {
	    A2.data()[i + j * A2.stride()] = 0.25;
	    B2.data()[i + j * B2.stride()] = 0.125;
	    C2.data()[i + j * C2.stride()] = 1.0;
	}
    }
    t1 = std::chrono::high_resolution_clock::now();
    FastMatmul3x3(A2, B2, C2, base);
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds"
	      << std::endl;
}
