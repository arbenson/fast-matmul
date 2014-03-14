#include "fast3x3.hpp"

int main() {
    int n = 729;
    Matrix<double> A(n);
    Matrix<double> B(n);
    Matrix<double> C(n);
    for (int j = 0; j < n; ++j) {
	for (int i = 0; i < n; ++i) {
	    A.data()[i + j * A.stride()] = 0.25;
	    B.data()[i + j * B.stride()] = 0.125;
	    C.data()[i + j * C.stride()] = 1.0;
	}
    }

    FastMatmul3x3(A, B, C);
}
