#include "fast3x3.hpp"

#include <stdlib.h>
#include <chrono>  // note: C++11
#include <time.h>
#include <random>
#include <vector>

// Build with: g++ dgemm_curve.cpp -std=c++0x -O3 -lblas -o dgemm_curve
int main(int argc, char **argv) {
    std::vector<int> n_vals;
    for (int i = 100; i <= 1500; i += 10) {
      n_vals.push_back(i);
    }
# if 0
    for (int i = 1300; i <= 2000; i += 100) {
        n_vals.push_back(i);
    }
#endif

    for (int i = 0; i < n_vals.size(); ++i) {
        int n = n_vals[i];
        int walltime = 0;
        srand (time(NULL));
        Matrix<double> A(n);
        Matrix<double> B(n);
        Matrix<double> C(n);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
                B.data()[i + j * B.stride()] = ((double) rand() / RAND_MAX) * 1024;
            }
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        int num_trials = 12;
        for (int trial = 0; trial < num_trials; ++trial) {
            Gemm(A, B, C);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::cout << " " 
                  << n
                  << " "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
                  << ";";
        if (!(n % 100)) {
            std::cout << "..." << std::endl;
        }
    }
}
