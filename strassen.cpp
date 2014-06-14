#include "strassen.hpp"

#include <stdlib.h>
#include <time.h>

#include <chrono>  // note: C++11
#include <random>

int main(int argc, char **argv) {
    int n = 2400;
    int numsteps = 2;

    std::cout << "n is: " << n << std::endl;
    std::cout << "number of recursive steps is: " << numsteps << std::endl;

    srand (time(NULL));

    Matrix<double> A(n);
    Matrix<double> B(n);
    Matrix<double> C1(n), C2(n);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
            B.data()[i + j * B.stride()] = ((double) rand() / RAND_MAX) * 1024;
        }
    }

#ifdef _OPEN_MP_
    omp_set_num_threads(omp_get_max_threads());
#endif

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
    FastMatmul(A, B, C2, numsteps);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
	      << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
	      << " milliseconds"
	      << std::endl;

    // Test for correctness.
    double diff = FrobeniusDiff(C1, C2);
    std::cout << "Frobenius norm solution difference: "
              << diff
              << std::endl;

    // Component-wise differences
    int step = n / 2;
    Matrix<double> C11A(C1.data(), C1.stride(), step, step);
    Matrix<double> C21A(C1.data() + step, C1.stride(), step, step);
    Matrix<double> C12A(C1.data() + step * C1.stride(), C1.stride(), step, step);
    Matrix<double> C22A(C1.data() + step * C1.stride() + step, C1.stride(), step, step);

    Matrix<double> C11B(C2.data(), C2.stride(), step, step);
    Matrix<double> C21B(C2.data() + step, C2.stride(), step, step);
    Matrix<double> C12B(C2.data() + step * C2.stride(), C2.stride(), step, step);
    Matrix<double> C22B(C2.data() + step * C2.stride() + step, C2.stride(), step, step);

    std::cout << "(1, 1): " << FrobeniusDiff(C11A, C11B) << std::endl;
    std::cout << "(2, 1): " << FrobeniusDiff(C21A, C21B) << std::endl;

    std::cout << "(1, 2): " << FrobeniusDiff(C12A, C12B) << std::endl;
    std::cout << "(2, 2): " << FrobeniusDiff(C22A, C22B) << std::endl;
}
