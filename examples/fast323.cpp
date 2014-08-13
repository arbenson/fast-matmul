#include "linalg.hpp"
#include "fast323_15_103.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
    int m = 1600;
    int k = 1600;
    int n = 1600;
    int numsteps = 2;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { MatMul(A, B, C1); }, "Classical gemm");
	Time([&] { grey323_15_103::FastMatmul(A, B, C2, numsteps); },
		 "Fast (3, 2, 3)");

    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
