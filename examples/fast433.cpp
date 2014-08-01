#include "linalg.hpp"
#include "fast433_29_234.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
    int m = 6400;
    int k = 4000;
    int n = 5000;
    int numsteps = 1;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { Gemm(A, B, C1); }, "Classical gemm");
	Time([&] { grey433_29_234::FastMatmul(A, B, C2, numsteps); }, "Fast (4, 3, 3)");

    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
