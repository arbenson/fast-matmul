#include "linalg.hpp"
#include "fast424_26_257.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
    int m = 12000;
    int k = 3000;
    int n = 12000;
    int numsteps = 2;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { MatMul(A, B, C1); }, "Classical gemm");
	Time([&] { grey424_26_257::FastMatmul(A, B, C2, numsteps); },
		 "Fast (4, 2, 4)");

    // Test for correctness.
    std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
