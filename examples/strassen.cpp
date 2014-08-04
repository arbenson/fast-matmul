#include "linalg.hpp"
#include "strassen.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
    int m = 2001;
    int k = 2001;
    int n = 2001;
    int numsteps = 2;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { Gemm(A, B, C1); }, "Classical gemm");
	Time([&] { strassen::FastMatmul(A, B, C2, numsteps); }, "Strassen");

    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
