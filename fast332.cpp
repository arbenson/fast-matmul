#include "linalg.hpp"
#include "fast332.hpp"

#include <stdlib.h>
#include <time.h>

#include <chrono>  // note: C++11
#include <random>

int main(int argc, char **argv) {
    int m = 2700;
    int n = 400;
    int numsteps = 2;

    srand (time(NULL));

    Matrix<double> A(m, m);
    Matrix<double> B(m, n);
    Matrix<double> C1(m, n), C2(m, n);
    for (int j = 0; j < A.m(); ++j) {
        for (int i = 0; i < A.n(); ++i) {
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
    FastMatmul(A, B, C2, numsteps);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Fast matmul took "
	      << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()
	      << " milliseconds"
	      << std::endl;


    // Test for correctness.
    double diff = FrobeniusDiff<double>(C1, C2);
    std::cout << "Frobenius norm solution difference: "
              << diff
              << std::endl;

    // Component-wise differences
    int C_x_step = C1.m() / 3;
    int C_y_step = C1.n() / 2;
    Matrix<double> C11A(C1.data() + 0 * C_x_step + 0 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);
    Matrix<double> C12A(C1.data() + 0 * C_x_step + 1 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);
    Matrix<double> C21A(C1.data() + 1 * C_x_step + 0 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);
    Matrix<double> C22A(C1.data() + 1 * C_x_step + 1 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);
    Matrix<double> C31A(C1.data() + 2 * C_x_step + 0 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);
    Matrix<double> C32A(C1.data() + 2 * C_x_step + 1 * C_y_step * C1.stride(), C1.stride(), C_x_step, C_y_step);

    C_x_step = C2.m() / 3;
    C_y_step = C2.n() / 2;
    Matrix<double> C11B(C2.data() + 0 * C_x_step + 0 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);
    Matrix<double> C12B(C2.data() + 0 * C_x_step + 1 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);
    Matrix<double> C21B(C2.data() + 1 * C_x_step + 0 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);
    Matrix<double> C22B(C2.data() + 1 * C_x_step + 1 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);
    Matrix<double> C31B(C2.data() + 2 * C_x_step + 0 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);
    Matrix<double> C32B(C2.data() + 2 * C_x_step + 1 * C_y_step * C2.stride(), C2.stride(), C_x_step, C_y_step);

    std::cout << "(1, 1): " << FrobeniusDiff(C11A, C11B) << std::endl;
    std::cout << "(2, 1): " << FrobeniusDiff(C21A, C21B) << std::endl;
    std::cout << "(3, 1): " << FrobeniusDiff(C31A, C31B) << std::endl;

    std::cout << "(1, 2): " << FrobeniusDiff(C12A, C12B) << std::endl;
    std::cout << "(2, 2): " << FrobeniusDiff(C22A, C22B) << std::endl;
    std::cout << "(3, 2): " << FrobeniusDiff(C32A, C32B) << std::endl;

    return 0;
}
