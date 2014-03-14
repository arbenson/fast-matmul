#ifndef FAST_3x3_
#define FAST_3x3_

#include <assert.h>

extern "C" {
    void dgemm_(char *transa, char *transb, int *m, int *n, int *k,
		double *alpha, double *a, int *lda, double *b, int *ldb,
		double *beta, double *c, int *ldc);
    void sgemm_(char *transa, char *transb, int *m, int *n, int *k,
	        float *alpha, float *a, int *lda, float *b, int *ldb,
	        float *beta, float *c, int *ldc);
}


// This is a basic templated matrix class.
// It stores the matrix data, the stride, and the dimensions.
template <typename Scalar>
class Matrix {
public:
    Matrix(Scalar *data, int stride, int m, int n):
	data_(data), stride_(stride), m_(m), n_(n) {}

    Matrix(int n) {
	stride_ = n;
	m_ = n;
	n_ = n;
	allocate();
    }

    ~Matrix() {
	deallocate();
    }

    Scalar *data() { return data_; }
    int stride() { return stride_; }
    int m() { return m_; }
    int n() { return n_; }

    void allocate() {
	data_ = new Scalar[m_ * n_];
	assert(data_ != NULL);
    }

    void deallocate() {
	assert(data_ != NULL);
	delete data_;
    }

private:
    Scalar *data_;
    int stride_;
    int m_;
    int n_;
};

void gemm_wrap(int dim, double *A, int lda, double *B, int ldb, double *C,
	       int ldc) {
    char transa = 'n';
    char transb = 'n';
    double alpha = 1;
    double beta = 0;
    dgemm_(&transa, &transb, &dim, &dim, &dim, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
}

void gemm_wrap(int dim, float *A, int lda, float *B, int ldb, float *C,
	       int ldc) {
    char transa = 'n';
    char transb = 'n';
    float alpha = 1;
    float beta = 0;
    sgemm_(&transa, &transb, &dim, &dim, &dim, &alpha, A, &lda, B, &ldb, &beta,
	   C, &ldc);
}

// C <-- A * B
// all matrices are assumed to be square
template <typename Scalar>
void gemm(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C) {
    assert(A.m() == A.n() &&
	   A.n() == B.m() &&
	   B.m() == B.n() &&
	   B.n() == C.m() &&
	   C.m() == C.n());
    gemm_wrap(A.n(), A.data(), A.stride(), B.data(), B.stride(), C.data(),
	      C.stride());
}

// C <-- alpha1 * A1 + alpha2 * A2
// all matrices are assumed to be square
template <typename Scalar>
void add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Scalar alpha1, Scalar alpha2,
         Matrix<Scalar> &C) {
    assert(A1.m() == A1.n() &&
	   A1.n() == A2.m() &&
	   A2.m() == A2.n() &&
	   A2.n() == C.m() &&
	   C.m() == C.n());
    for (int j = 0; j < C.m(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	    Scalar a = alpha1 * A1.data()[i + j * A1.stride()];
	    Scalar b = alpha2 * A2.data()[i + j * A2.stride()];
	    C.data()[i + j * C.stride()] = a + b;
	}
    }
}


// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3
// all matrices are assumed to be square
template <typename Scalar>
void add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Matrix<Scalar>& C) {
    assert(A1.m() == A1.n() &&
	   A1.n() == A2.m() &&
	   A2.m() == A2.n() &&
	   A2.n() == A3.m() &&
	   A3.m() == A3.n() &&
	   A3.n() == C.m() &&
	   C.m() == C.n());
    for (int j = 0; j < C.m(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	    Scalar a = alpha1 * A1.data()[i + j * A1.stride()];
	    Scalar b = alpha2 * A2.data()[i + j * A2.stride()];
	    Scalar c = alpha3 * A3.data()[i + j * A3.stride()];
	    C.data()[i + j * C.stride()] = a + b + c;
	}
    }
}

// C <-- A * B with fast 3x3 matrix multiplication
// all matrices are assumed to be square with dimension a power of 3
template <typename Scalar>
void FastMatmul3x3(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C) {
    int n = A.n();
    int step = n / 3;

    if (n <= 27) {
	gemm(A, B, C);
    }

    // Sub-blocks of A
    Matrix<Scalar> A11(A.data(), A.stride(), step, step);
    Matrix<Scalar> A21(A.data() + step, A.stride(), step, step);
    Matrix<Scalar> A31(A.data() + 2 * step, A.stride(), step, step);
    Matrix<Scalar> A12(A.data() + step * A.stride(), A.stride(), step, step);
    Matrix<Scalar> A22(A.data() + step * A.stride() + step, A.stride(), step, step);
    Matrix<Scalar> A32(A.data() + step * A.stride() + 2 * step, A.stride(), step, step);
    Matrix<Scalar> A13(A.data() + 2 * step * A.stride(), A.stride(), step, step);
    Matrix<Scalar> A23(A.data() + 2 * step * A.stride() + step, A.stride(), step, step);
    Matrix<Scalar> A33(A.data() + 2 * step * A.stride() + 2 * step, A.stride(), step, step);

    // Sub-blocks of B
    Matrix<Scalar> B11(B.data(), B.stride(), step, step);
    Matrix<Scalar> B21(B.data() + step, B.stride(), step, step);
    Matrix<Scalar> B31(B.data() + 2 * step, B.stride(), step, step);
    Matrix<Scalar> B12(B.data() + step * B.stride(), B.stride(), step, step);
    Matrix<Scalar> B22(B.data() + step * B.stride() + step, B.stride(), step, step);
    Matrix<Scalar> B32(B.data() + step * B.stride() + 2 * step, B.stride(), step, step);
    Matrix<Scalar> B13(B.data() + 2 * step * B.stride(), B.stride(), step, step);
    Matrix<Scalar> B23(B.data() + 2 * step * B.stride() + step, B.stride(), step, step);
    Matrix<Scalar> B33(B.data() + 2 * step * B.stride() + 2 * step, B.stride(), step, step);

    // Sub-blocks of C
    Matrix<Scalar> C11(C.data(), C.stride(), step, step);
    Matrix<Scalar> C21(C.data() + step, C.stride(), step, step);
    Matrix<Scalar> C31(C.data() + 2 * step, C.stride(), step, step);
    Matrix<Scalar> C12(C.data() + step * C.stride(), C.stride(), step, step);
    Matrix<Scalar> C22(C.data() + step * C.stride() + step, C.stride(), step, step);
    Matrix<Scalar> C32(C.data() + step * C.stride() + 2 * step, C.stride(), step, step);
    Matrix<Scalar> C13(C.data() + 2 * step * C.stride(), C.stride(), step, step);
    Matrix<Scalar> C23(C.data() + 2 * step * C.stride() + step, C.stride(), step, step);
    Matrix<Scalar> C33(C.data() + 2 * step * C.stride() + 2 * step, C.stride(), step, step);

    Scalar NegOne = Scalar(-1);
    Scalar One = Scalar(1);

    // S* variables are summations that lower the number of additions needed
    // S1 = -A31 - A32;
    Matrix<Scalar> S1(step);
    add(A31, A32, NegOne, NegOne, S1);
    
    // S2 = A22 + A23;
    Matrix<Scalar> S2(step);
    add(A22, A23, One, One, S2);

    // S3 = -A13 + S2;
    Matrix<Scalar> S3(step);
    add(A13, S2, NegOne, One, S3);

    // S4 = -B22 - B23;
    Matrix<Scalar> S4(step);
    add(B22, B23, NegOne, NegOne, S4);

    // S5 = B22 - B32;
    Matrix<Scalar> S5(step);
    add(B22, B32, One, NegOne, S5);


    // M1, M2, ..., M23 are the intermediate matrix multiplications

    // M1 =  (A33)                    * (-B11 - B21 + B31);
    Matrix<Scalar> M1(step);
    Matrix<Scalar> M1B(step);
    add(B11, B21, B31, NegOne, NegOne, One, M1B);
    FastMatmul3x3(A33, M1B, M1);
    M1B.deallocate();
    
    // M2 =  (A22 + A33)              * (-B21 + B32);
    Matrix<Scalar> M2(step);
    Matrix<Scalar> M2A(step);
    Matrix<Scalar> M2B(step);
    add(A22, A33, One, One, M2A);
    add(B21, B32, NegOne, One, M2B);
    FastMatmul3x3(M2A, M2B, M2);
    M2A.deallocate();
    M2B.deallocate();

    // M3 =  (A11 + A12 + A31 + A32)  * (B23);
    Matrix<Scalar> M3(step);
    Matrix<Scalar> M3A(step);
    Matrix<Scalar> M3tmp(step);
    add(A11, A12, A31, One, One, One, M3tmp);
    add(M3tmp, A32, One, One, M3A);
    FastMatmul3x3(M3A, B23, M3);
    M3tmp.deallocate();
    M3A.deallocate();

    // M4 =  (-A11 + A21)             * (B12 + B13);    
    Matrix<Scalar> M4(step);
    Matrix<Scalar> M4A(step);
    Matrix<Scalar> M4B(step);
    add(A11, A21, NegOne, One, M4A);
    add(B12, B12, One, One, M4B);
    FastMatmul3x3(M4A, M4B, M4);
    M4A.deallocate();
    M4B.deallocate();

    // M5 =  (S1)                     * (-B12);
    Matrix<Scalar> M5(step);
    // TODO: need to negate B12
    FastMatmul3x3(S1, B12, M4);

    // M6 =  (S2)                     * (B32);
    Matrix<Scalar> M6(step);
    FastMatmul3x3(S2, B32, M6);

    // M7 =  (-A21 - A33)             * (B11);
    Matrix<Scalar> M7(step);
    Matrix<Scalar> M7A(step);
    add(A21, A33, NegOne, NegOne, M7A);
    FastMatmul3x3(M7A, B11, M7);
    M7A.deallocate();

    // M8 =  (A31 + A33)              * (B11);
    Matrix<Scalar> M8(step);
    Matrix<Scalar> M8A(step);
    add(A31, A33, One, One, M8A);
    FastMatmul3x3(M8A, B11, M8);
    M8A.deallocate();

    // M9 =  (A22)                    * (-B12 + S5);
    Matrix<Scalar> M9(step);
    Matrix<Scalar> M9B(step);    
    add(B12, S5, NegOne, One, M9B);
    FastMatmul3x3(A22, M9B, M9);
    M9B.deallocate();

    // M10 = (A22 - A32)              * (B12 + B21 - B22);
    Matrix<Scalar> M10(step);
    Matrix<Scalar> M10A(step);
    Matrix<Scalar> M10B(step);
    add(A22, A32, One, NegOne, M10A);
    add(B12, B21, B22, One, One, NegOne, M10B);
    FastMatmul3x3(M10A, M10B, M10);
    M10A.deallocate();
    M10B.deallocate();

    // M11 = (-A32 - A33)             * (B21);
    Matrix<Scalar> M11(step);
    Matrix<Scalar> M11A(step);
    add(A32, A33, NegOne, NegOne, M11A);
    FastMatmul3x3(M11A, B21, M11);
    M11A.deallocate();

    // M12 = (S3)                     * (S5 + B23);
    Matrix<Scalar> M12(step);
    Matrix<Scalar> M12B(step);
    add(S5, B23, One, One, M12B);
    FastMatmul3x3(S3, M12B, M12);    
    M12B.deallocate();
    
    // M13 = (A13 + A33)              * (B31 + B33);
    Matrix<Scalar> M13(step);
    Matrix<Scalar> M13A(step);
    Matrix<Scalar> M13B(step);
    add(A12, A33, One, One, M13A);
    add(B32, B33, One, One, M13B);
    FastMatmul3x3(M13A, M13B, M13);
    M13A.deallocate();
    M13B.deallocate();

    // M14 = (A11 + A31)              * (B11 + B13 - B23);
    Matrix<Scalar> M14(step);
    Matrix<Scalar> M14A(step);
    Matrix<Scalar> M14B(step);
    add(A11, A31, One, One, M14A);
    add(B11, B13, B23, One, One, NegOne, M14B);
    FastMatmul3x3(M14A, M14B, M14);
    M14A.deallocate();
    M14B.deallocate();

    
    // M15 = (-A11 + A33)             * (B11 + B33);
    Matrix<Scalar> M15(step);
    Matrix<Scalar> M15A(step);
    Matrix<Scalar> M15B(step);
    add(A11, A33, NegOne, One, M15A);
    add(B11, B33, One, One, M15B);
    FastMatmul3x3(M15A, M15B, M15);
    M15A.deallocate();
    M15B.deallocate();
    
    // M16 = (-A13 + A23)             * (S4 + B32 + B33);
    Matrix<Scalar> M16(step);
    Matrix<Scalar> M16A(step);
    Matrix<Scalar> M16B(step);
    add(A13, A23, One, NegOne, M16A);
    add(S4, B32, B33, One, One, One, M16B);
    FastMatmul3x3(M16A, M16B, M16);
    M16A.deallocate();
    M16B.deallocate();

    // M17 = (-A12 + S3)              * (S4);
    Matrix<Scalar> M17(step);
    Matrix<Scalar> M17A(step);
    add(A12, S3, NegOne, One, M17A);
    FastMatmul3x3(M17A, S4, M17);
    M16A.deallocate();

    // M18 = (-A23 + A33)             * (-B31 + B32);
    Matrix<Scalar> M18(step);
    Matrix<Scalar> M18A(step);
    Matrix<Scalar> M18B(step);
    add(A23, A33, NegOne, One, M18A);
    add(B31, B32, NegOne, One, M18B);
    FastMatmul3x3(M18A, M18B, M18);
    M18A.deallocate();
    M18B.deallocate();

    // M19 = (-A11 + S1)              * (-B12 - B23);
    Matrix<Scalar> M19(step);
    Matrix<Scalar> M19A(step);
    Matrix<Scalar> M19B(step);
    add(A11, S1, NegOne, One, M19A);
    add(B12, B23, NegOne, NegOne, M19B);
    FastMatmul3x3(M19A, M19B, M19);
    M19A.deallocate();
    M19B.deallocate();

    // M20 = (-A11 - A13)             * (B33);
    Matrix<Scalar> M20(step);
    Matrix<Scalar> M20A(step);
    add(A11, A13, NegOne, NegOne, M20A);
    FastMatmul3x3(M20A, B33, M20);
    M20A.deallocate();

    // M21 = (A11)                    * (-B12 - B13 + B33);
    Matrix<Scalar> M21(step);
    Matrix<Scalar> M21B(step);
    add(B12, B13, B33, NegOne, NegOne, One, M21B);
    FastMatmul3x3(A11, M21B, M21);
    M21B.deallocate();

    // M22 = (-A21 - A22)             * (B12);
    Matrix<Scalar> M22(step);
    Matrix<Scalar> M22A(step);
    add(A21, A22, NegOne, NegOne, M22A);
    FastMatmul3x3(M22A, B12, M22);
    M22A.deallocate();

    // M23 = (-A12 + A33)             * (B21);
    Matrix<Scalar> M23(step);
    Matrix<Scalar> M23A(step);
    add(A12, A33, NegOne, One, M23A);
    FastMatmul3x3(M23A, B21, M22);
    M23A.deallocate();


    // Fill in the matrix C

    // R1 saves one addition.
    // R1 = -M20 - M21;
    Matrix<Scalar> R1(step);
    add(M20, M21, NegOne, NegOne, R1);

    Matrix<Scalar> tmp1(step);
    Matrix<Scalar> tmp2(step);

    // C11 = -M1 + M13 - M15 + M20 - M23;
    add(M1, M13, M15, NegOne, One, NegOne, tmp1);
    add(tmp1, M20, M23, One, One, NegOne, C11);
	
    // C12 = -M3 - M5 + M6 + M12 + M17 + M19;
    add(M3, M5, M6, NegOne, NegOne, One, tmp1);
    add(M12, M17, M19, One, One, One, tmp2);
    add(tmp1, tmp2, One, One, C12);

    // C13 = M3 + M5 - M19 + R1;
    add(M3, M5, M19, One, One, NegOne, tmp1);
    add(tmp1, R1, One, One, C13);

    // C21 = M1 - M2 + M6 - M7 + M18;
    add(M1, M2, M6, One, NegOne, One, tmp1);
    add(tmp1, M7, M18, One, NegOne, One, C21);

    // C22 = M6 + M9 - M22;
    add(M6, M9, M22, One, One, NegOne, C22);

    // C23 = M4 - M9 + M12 + M16 + R1 + M22;
    add(M4, M9, M12, One, NegOne, One, tmp1);
    add(M16, R1, M22, One, One, One, tmp2);
    add(tmp1, tmp2, One, One, C23);

    // C31 = M1 + M8 - M11;
    add(M1, M8, M11, One, One, NegOne, C31);

    // C32 = M2 + M5 + M9 + M10 - M11;
    add(M2, M5, M9, One, One, One, tmp1);
    add(tmp1, M10, M11, One, One, NegOne, C32);

    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;
    add(M5, M8, M14, NegOne, NegOne, One, tmp1);
    add(M15, M19, M21, One, One, One, tmp2);
    add(tmp1, tmp2, One, One, C33);
}

// Template declarations
// template Matrix<double>;
// template Matrix<float>;

template void gemm(Matrix<double>& A, Matrix<double>& B, Matrix<double>& C);
template void gemm(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);


template void add(Matrix<double>& A1, Matrix<double>& A2, double alpha1,
                  double alpha2,  Matrix<double>& C);
template void add(Matrix<float>& A1, Matrix<float>& A2, float alpha1,
                  float alpha2, Matrix<float>& C);

template void add(Matrix<double>& A1, Matrix<double>& A2, Matrix<double>& A3,
                  double alpha1, double alpha2, double alpha3,
                  Matrix<double>& C);
template void add(Matrix<float>& A1, Matrix<float>& A2, Matrix<float>& A3,
                  float alpha1, float alpha2, float alpha3, Matrix<float>& C);

template void FastMatmul3x3(Matrix<double>& A, Matrix<double>& B,
                            Matrix<double>& C);
template void FastMatmul3x3(Matrix<float>& A, Matrix<float>& B,
                            Matrix<float>& C);

#endif  // FAST_3x3_
