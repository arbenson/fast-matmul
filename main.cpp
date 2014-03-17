#include "fast3x3.hpp"

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

    // Test for correctness.
    double diff = FrobeniusDiff(C1, C2);
    std::cout << "Frobenius norm solution difference: "
              << diff
              << std::endl;

    // Component-wise differences
    int step = n / 3;
    Matrix<double> C11A(C1.data(), C1.stride(), step, step);
    Matrix<double> C21A(C1.data() + step, C1.stride(), step, step);
    Matrix<double> C31A(C1.data() + 2 * step, C1.stride(), step, step);
    Matrix<double> C12A(C1.data() + step * C1.stride(), C1.stride(), step, step);
    Matrix<double> C22A(C1.data() + step * C1.stride() + step, C1.stride(), step, step);
    Matrix<double> C32A(C1.data() + step * C1.stride() + 2 * step, C1.stride(), step, step);
    Matrix<double> C13A(C1.data() + 2 * step * C1.stride(), C1.stride(), step, step);
    Matrix<double> C23A(C1.data() + 2 * step * C1.stride() + step, C1.stride(), step, step);
    Matrix<double> C33A(C1.data() + 2 * step * C1.stride() + 2 * step, C1.stride(), step, step);

    Matrix<double> C11B(C2.data(), C2.stride(), step, step);
    Matrix<double> C21B(C2.data() + step, C2.stride(), step, step);
    Matrix<double> C31B(C2.data() + 2 * step, C2.stride(), step, step);
    Matrix<double> C12B(C2.data() + step * C2.stride(), C2.stride(), step, step);
    Matrix<double> C22B(C2.data() + step * C2.stride() + step, C2.stride(), step, step);
    Matrix<double> C32B(C2.data() + step * C2.stride() + 2 * step, C2.stride(), step, step);
    Matrix<double> C13B(C2.data() + 2 * step * C2.stride(), C2.stride(), step, step);
    Matrix<double> C23B(C2.data() + 2 * step * C2.stride() + step, C2.stride(), step, step);
    Matrix<double> C33B(C2.data() + 2 * step * C2.stride() + 2 * step, C2.stride(), step, step);

    std::cout << "(1, 1): " << FrobeniusDiff(C11A, C11B) << std::endl;
    std::cout << "(2, 1): " << FrobeniusDiff(C21A, C21B) << std::endl;
    std::cout << "(3, 1): " << FrobeniusDiff(C31A, C31B) << std::endl;

    std::cout << "(1, 2): " << FrobeniusDiff(C12A, C12B) << std::endl;
    std::cout << "(2, 2): " << FrobeniusDiff(C22A, C22B) << std::endl;
    std::cout << "(3, 2): " << FrobeniusDiff(C32A, C32B) << std::endl;

    std::cout << "(1, 3): " << FrobeniusDiff(C13A, C13B) << std::endl;
    std::cout << "(2, 3): " << FrobeniusDiff(C23A, C23B) << std::endl;
    std::cout << "(3, 3): " << FrobeniusDiff(C33A, C33B) << std::endl;
}
