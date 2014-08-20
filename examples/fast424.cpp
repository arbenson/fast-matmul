#include "linalg.hpp"
#include "fast424_26_257.hpp"
#include "timing.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 4000;
    int k = 1000;
    int n = 4000;
    int numsteps = 1;

    Matrix<double> A = RandomMatrix<double>(m, k);
    Matrix<double> B = RandomMatrix<double>(k, n);
    Matrix<double> C1(m, n), C2(m, n);

    Time([&] { MatMul(A, B, C1); }, "Classical gemm");
    double time;
    Time([&] { time = grey424_26_257::FastMatmul(A, B, C1, numsteps); }, "Fast matmul");
    std::cout << "Fast time: " << time << " ms." << std::endl;

    // Test for correctness.
    //std::cout << "Maximum relative difference: " << MaxRelativeDiff(C1, C2) << std::endl;

    return 0;
}
