#include "linalg.hpp"
#include "fast333_23_152.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
    int m = 2700;
    int k = 2700;
    int n = 2700;
    int numsteps = 2;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { Gemm(A, B, C1); }, "Classical gemm");
	Time([&] { grey333_23_152::FastMatmul(A, B, C2, numsteps); },
		 "Fast (3, 3, 3)");

    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2)
			  << std::endl;

    return 0;
}
