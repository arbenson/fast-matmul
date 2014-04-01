#ifndef FAST_3x3_
#define FAST_3x3_

#include <assert.h>
#include <math.h>

#include <iostream>

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
// The variable is_view indicates whether or not the data is owned
// by this instance.
template <typename Scalar>
class Matrix {
public:
    Matrix(Scalar *data, int stride, int m, int n):
        data_(data), stride_(stride), m_(m), n_(n), is_view_(true) {}

    Matrix(int n) {
        stride_ = n;
        m_ = n;
        n_ = n;
        is_view_ = false;
        allocate();
    }

    ~Matrix() {
        if (data_ != NULL && !is_view_) {
            deallocate();
        }
    }

    Scalar *data() { return data_; }
    const int stride() { return stride_; }
    const int m() { return m_; }
    const int n() { return n_; }

    void allocate() {
        data_ = new Scalar[m_ * n_];
        assert(data_ != NULL);
    }

    void deallocate() {
        if (data_ != NULL) {
            delete data_;
            data_ = NULL;
        }
    }

private:
    Scalar *data_;
    int stride_;
    int m_;
    int n_;
    bool is_view_;
};

// Wrapper for dgemm called by templated gemm.
void GemmWrap(int dim, double *A, int lda, double *B, int ldb, double *C,
               int ldc) {
    char transa = 'n';
    char transb = 'n';
    double alpha = 1;
    double beta = 0;
    
    dgemm_(&transa, &transb, &dim, &dim, &dim, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
}

// Wrapper for sgemm called by templated gemm.
void GemmWrap(int dim, float *A, int lda, float *B, int ldb, float *C,
               int ldc) {
    char transa = 'n';
    char transb = 'n';
    float alpha = 1;
    float beta = 0;
    sgemm_(&transa, &transb, &dim, &dim, &dim, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
}

// Frobenius norm difference: \| A - B \|_F
template<typename Scalar>
double FrobeniusDiff(Matrix<Scalar>& A, Matrix<Scalar>& B) {
    assert(A.m() == B.m() &&
           A.n() == B.n());
    double diff = 0.0;
    for (int j = 0; j < A.m(); ++j) {
        for (int i = 0; i < A.n(); ++i) {
            Scalar a = A.data()[i + j * A.stride()];
            Scalar b = B.data()[i + j * B.stride()];
            diff += (a - b) * (a - b);
        }
    }
    return sqrt(diff);
}

// C <-- -A
template<typename Scalar>
void Negate(Matrix<Scalar>& A, Matrix<Scalar>& C) {
    assert(A.m() == C.m() &&
           A.n() == C.n());
    const int strideA = A.stride();
    const int strideC = C.stride();
    const Scalar *dataA = A.data();
    Scalar *dataC = C.data();
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = dataA[i + j * strideA];
            dataC[i + j * strideC] = -a;
        }
    }
}

// C <-- A * B
// all matrices are assumed to be square
template <typename Scalar>
void Gemm(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C) {
    assert(A.m() == A.n() &&
           A.n() == B.m() &&
           B.m() == B.n() &&
           B.n() == C.m() &&
           C.m() == C.n());
    GemmWrap(A.n(), A.data(), A.stride(), B.data(), B.stride(), C.data(),
              C.stride());
}

// C <-- alpha1 * A1 + alpha2 * A2
// all matrices are assumed to be square
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Scalar alpha1, Scalar alpha2,
         Matrix<Scalar> &C) {
    assert(A1.m() == A1.n() &&
           A1.n() == A2.m() &&
           A2.m() == A2.n() &&
           A2.n() == C.m() &&
           C.m() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.m(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = alpha1 * dataA1[i + j * strideA1];
            Scalar b = alpha2 * dataA2[i + j * strideA2];
            dataC[i + j * strideC] = a + b;
        }
    }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3
// all matrices are assumed to be square
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Matrix<Scalar>& C) {
    assert(A1.m() == A1.n() &&
           A1.n() == A2.m() &&
           A2.m() == A2.n() &&
           A2.n() == A3.m() &&
           A3.m() == A3.n() &&
           A3.n() == C.m() &&
           C.m() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.m(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = alpha1 * dataA1[i + j * strideA1];
            Scalar b = alpha2 * dataA2[i + j * strideA2];
            Scalar c = alpha3 * dataA3[i + j * strideA3];
            dataC[i + j * strideC] = a + b + c;
        }
    }
}

// C <-- A * B with fast 3x3 matrix multiplication
// All matrices are assumed to be square with dimension a power of 3
// numsteps is the number of recursive steps to take before using
// classical matrix multiplication
template <typename Scalar>
void FastMatmul3x3(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
                   int numsteps) {
    // Base case for recursion
    if (numsteps == 0) {
        Gemm(A, B, C);
        return;
    }

    const int n = A.n();
    const int step = n / 3;

    // Get a view of all sub-blocks in 3 x 3 partitioning of the matrices.
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

    // Number of additions/subtractions:
    // Pre-compute:
    //
    // S1 = -A31 - A32; [1]
    // S2 = A22 + A23;  [1]
    // S3 = -A13 + S2;  [1]
    // S4 = -B22 - B23; [1]
    // S5 = B22 - B32;  [1]
    // S6 = A11 + A31;  [1]
    // 6 in total
    //
    //  M1 =  (A33)                    * (-B11 - B21 + B31); [3]
    //  M2 =  (A22 + A33)              * (-B21 + B32);       [2]
    //  M3 =  (S6 + A12 + A32)         * (B23);              [2]
    //  M4 =  (-A11 + A21)             * (B12 + B13);        [2]
    //  M5 =  (S1)                     * (-B12);             [0/1]
    //  M6 =  (S2)                     * (B32);              [0]
    //  M7 =  (-A21 - A33)             * (B11);              [1]
    //  M8 =  (A31 + A33)              * (B11);              [1]
    //  M9 =  (A22)                    * (-B12 + S5);        [1]
    //  M10 = (A22 - A32)              * (B12 + B21 - B22);  [3]
    //  M11 = (-A32 - A33)             * (B21);              [1]
    //  M12 = (S3)                     * (S5 + B23);         [1]
    //  M13 = (A13 + A33)              * (B31 + B33);        [2]
    //  M14 = (S6)                     * (B11 + B13 - B23);  [2]
    //  M15 = (-A11 + A33)             * (B11 + B33);        [2]
    //  M16 = (-A13 + A23)             * (S4 + B32 + B33);   [3]
    //  M17 = (-A12 + S3)              * (S4);               [1]
    //  M18 = (-A23 + A33)             * (-B31 + B32);       [2]
    //  M19 = (-A11 + S1)              * (-B12 - B23);       [2]
    //  M20 = (-A11 - A13)             * (B33);              [1]
    //  M21 = (A11)                    * (-B12 - B13 + B33); [2]
    //  M22 = (-A21 - A22)             * (B12);              [1]
    //  M23 = (-A12 + A33)             * (B21);              [1]
    //
    // For M5, we don't need one addition, but it requires some extra code.
    // We need to negate B12 but it needs to be done in the matrix multiply.
    // With recursion, this is a little tricky.  For now, we just negate
    // and suffer from one more "subtraction".
    // In total, 37 additions/subtractions for the intermediate multiplications.
    //
    // Pre-compute for formulation of C blocks:
    // 
    // R1 = -M20 - M21;                         [1]
    // R2 = M3 + M5;                            [1]
    // R3 = M9 - M22;                           [1]
    // 
    // In total, 3 additions/subtractions
    // 
    // C11 = -M1 + M13 - M15 + M20 - M23;       [4]
    // C12 = -R2 + M6 + M12 + M17 + M19;        [4]
    // C13 = R2 - M19 + R1;                     [2]
    // C21 = M1 - M2 + M6 - M7 + M18;           [4]
    // C22 = M6 + R3;                           [1]
    // C23 = M4 - R3 + M12 + M16 + R1;          [4]
    // C31 = M1 + M8 - M11;                     [2]
    // C32 = M2 + M5 + M9 + M10 - M11;          [4]
    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;  [5]
    // 
    // In total, 30 additions/subtractions
    //
    // Overall: 6 + 37 + 3 + 30 = 76 additions/subtractions

    // S1, ..., S5 variables are pre-computations of summations
    // that are used multiple times in the multiplications.
    // S1 = -A31 - A32;
    Matrix<Scalar> S1(step);
    Add(A31, A32, NegOne, NegOne, S1);
    
    // S2 = A22 + A23;
    Matrix<Scalar> S2(step);
    Add(A22, A23, One, One, S2);

    // S3 = -A13 + S2;
    Matrix<Scalar> S3(step);
    Add(A13, S2, NegOne, One, S3);

    // S4 = -B22 - B23;
    Matrix<Scalar> S4(step);
    Add(B22, B23, NegOne, NegOne, S4);

    // S5 = B22 - B32;
    Matrix<Scalar> S5(step);
    Add(B22, B32, One, NegOne, S5);

    // S6 = A11 + A31;
    Matrix<Scalar> S6(step);
    Add(A11, A31, One, One, S6);


    // M1, M2, ..., M23 are the intermediate matrix multiplications

    //  M1 =  (A33)                    * (-B11 - B21 + B31);
    Matrix<Scalar> M1(step);
    Matrix<Scalar> M1B(step);
    Add(B11, B21, B31, NegOne, NegOne, One, M1B);
    FastMatmul3x3(A33, M1B, M1, numsteps - 1);
    M1B.deallocate();
    
    // M2 =  (A22 + A33)              * (-B21 + B32);
    Matrix<Scalar> M2(step);
    Matrix<Scalar> M2A(step);
    Matrix<Scalar> M2B(step);
    Add(A22, A33, One, One, M2A);
    Add(B21, B32, NegOne, One, M2B);
    FastMatmul3x3(M2A, M2B, M2, numsteps - 1);
    M2A.deallocate();
    M2B.deallocate();

    // M3 =  (S6 + A12 + A32)  * (B23);
    Matrix<Scalar> M3(step);
    Matrix<Scalar> M3A(step);
    Add(S6, A12, A32, One, One, One, M3A);
    FastMatmul3x3(M3A, B23, M3, numsteps - 1);
    M3A.deallocate();

    // M4 =  (-A11 + A21)             * (B12 + B13);    
    Matrix<Scalar> M4(step);
    Matrix<Scalar> M4A(step);
    Matrix<Scalar> M4B(step);
    Add(A11, A21, NegOne, One, M4A);
    Add(B12, B13, One, One, M4B);
    FastMatmul3x3(M4A, M4B, M4, numsteps - 1);
    M4A.deallocate();
    M4B.deallocate();

    // M5 =  (S1)                     * (-B12);
    Matrix<Scalar> M5(step);
    Matrix<Scalar> M5B(step);
    Negate(B12, M5B);
    FastMatmul3x3(S1, M5B, M5, numsteps - 1);

    // M6 =  (S2)                     * (B32);
    Matrix<Scalar> M6(step);
    FastMatmul3x3(S2, B32, M6, numsteps - 1);

    // M7 =  (-A21 - A33)             * (B11);
    Matrix<Scalar> M7(step);
    Matrix<Scalar> M7A(step);
    Add(A21, A33, NegOne, NegOne, M7A);
    FastMatmul3x3(M7A, B11, M7, numsteps - 1);
    M7A.deallocate();

    // M8 =  (A31 + A33)              * (B11);
    Matrix<Scalar> M8(step);
    Matrix<Scalar> M8A(step);
    Add(A31, A33, One, One, M8A);
    FastMatmul3x3(M8A, B11, M8, numsteps - 1);
    M8A.deallocate();

    // M9 =  (A22)                    * (-B12 + S5);
    Matrix<Scalar> M9(step);
    Matrix<Scalar> M9B(step);    
    Add(B12, S5, NegOne, One, M9B);
    FastMatmul3x3(A22, M9B, M9, numsteps - 1);
    M9B.deallocate();

    // M10 = (A22 - A32)              * (B12 + B21 - B22);
    Matrix<Scalar> M10(step);
    Matrix<Scalar> M10A(step);
    Matrix<Scalar> M10B(step);
    Add(A22, A32, One, NegOne, M10A);
    Add(B12, B21, B22, One, One, NegOne, M10B);
    FastMatmul3x3(M10A, M10B, M10, numsteps - 1);
    M10A.deallocate();
    M10B.deallocate();

    // M11 = (-A32 - A33)             * (B21);
    Matrix<Scalar> M11(step);
    Matrix<Scalar> M11A(step);
    Add(A32, A33, NegOne, NegOne, M11A);
    FastMatmul3x3(M11A, B21, M11, numsteps - 1);
    M11A.deallocate();

    // M12 = (S3)                     * (S5 + B23);
    Matrix<Scalar> M12(step);
    Matrix<Scalar> M12B(step);
    Add(S5, B23, One, One, M12B);
    FastMatmul3x3(S3, M12B, M12, numsteps - 1);
    M12B.deallocate();
    
    // M13 = (A13 + A33)              * (B31 + B33);
    Matrix<Scalar> M13(step);
    Matrix<Scalar> M13A(step);
    Matrix<Scalar> M13B(step);
    Add(A13, A33, One, One, M13A);
    Add(B31, B33, One, One, M13B);
    FastMatmul3x3(M13A, M13B, M13, numsteps - 1);
    M13A.deallocate();
    M13B.deallocate();

    // M14 = (S6)                     * (B11 + B13 - B23);
    Matrix<Scalar> M14(step);
    Matrix<Scalar> M14B(step);
    Add(B11, B13, B23, One, One, NegOne, M14B);
    FastMatmul3x3(S6, M14B, M14, numsteps - 1);
    M14B.deallocate();
    
    // M15 = (-A11 + A33)             * (B11 + B33);
    Matrix<Scalar> M15(step);
    Matrix<Scalar> M15A(step);
    Matrix<Scalar> M15B(step);
    Add(A11, A33, NegOne, One, M15A);
    Add(B11, B33, One, One, M15B);
    FastMatmul3x3(M15A, M15B, M15, numsteps - 1);
    M15A.deallocate();
    M15B.deallocate();
    
    // M16 = (-A13 + A23)             * (S4 + B32 + B33);
    Matrix<Scalar> M16(step);
    Matrix<Scalar> M16A(step);
    Matrix<Scalar> M16B(step);
    Add(A13, A23, NegOne, One, M16A);
    Add(S4, B32, B33, One, One, One, M16B);
    FastMatmul3x3(M16A, M16B, M16, numsteps - 1);
    M16A.deallocate();
    M16B.deallocate();

    // M17 = (-A12 + S3)              * (S4);
    Matrix<Scalar> M17(step);
    Matrix<Scalar> M17A(step);
    Add(A12, S3, NegOne, One, M17A);
    FastMatmul3x3(M17A, S4, M17, numsteps - 1);
    M16A.deallocate();

    // M18 = (-A23 + A33)             * (-B31 + B32);
    Matrix<Scalar> M18(step);
    Matrix<Scalar> M18A(step);
    Matrix<Scalar> M18B(step);
    Add(A23, A33, NegOne, One, M18A);
    Add(B31, B32, NegOne, One, M18B);
    FastMatmul3x3(M18A, M18B, M18, numsteps - 1);
    M18A.deallocate();
    M18B.deallocate();

    // M19 = (-A11 + S1)              * (-B12 - B23);
    Matrix<Scalar> M19(step);
    Matrix<Scalar> M19A(step);
    Matrix<Scalar> M19B(step);
    Add(A11, S1, NegOne, One, M19A);
    Add(B12, B23, NegOne, NegOne, M19B);
    FastMatmul3x3(M19A, M19B, M19, numsteps - 1);
    M19A.deallocate();
    M19B.deallocate();

    // M21 = (A11)                    * (-B12 - B13 + B33);
    Matrix<Scalar> M21(step);
    Matrix<Scalar> M21B(step);
    Add(B12, B13, B33, NegOne, NegOne, One, M21B);
    FastMatmul3x3(A11, M21B, M21, numsteps - 1);
    M21B.deallocate();

    // M20 = (-A11 - A13)             * (B33);
    Matrix<Scalar> M20(step);
    Matrix<Scalar> M20A(step);
    Add(A11, A13, NegOne, NegOne, M20A);
    FastMatmul3x3(M20A, B33, M20, numsteps - 1);
    M20A.deallocate();

    // M22 = (-A21 - A22)             * (B12);
    Matrix<Scalar> M22(step);
    Matrix<Scalar> M22A(step);
    Add(A21, A22, NegOne, NegOne, M22A);
    FastMatmul3x3(M22A, B12, M22, numsteps - 1);
    M22A.deallocate();

    // M23 = (-A12 + A33)             * (B21);
    Matrix<Scalar> M23(step);
    Matrix<Scalar> M23A(step);
    Add(A12, A33, NegOne, One, M23A);
    FastMatmul3x3(M23A, B21, M23, numsteps - 1);
    M23A.deallocate();


    // Fill in the matrix C

    // R1 = -M20 - M21;
    Matrix<Scalar> R1(step);
    Add(M20, M21, NegOne, NegOne, R1);
    // R2 = M3 + M5;
    Matrix<Scalar> R2(step);
    Add(M3, M5, One, One, R2);
    // R3 = M9 - M22;
    Matrix<Scalar> R3(step);
    Add(M9, M22, One, NegOne, R3);

    Matrix<Scalar> tmp1(step);
    Matrix<Scalar> tmp2(step);

    // C11 = -M1 + M13 - M15 + M20 - M23;
    Add(M1, M13, M15, NegOne, One, NegOne, tmp1);
    Add(tmp1, M20, M23, One, One, NegOne, C11);
        
    // C12 = -R2 + M6 + M12 + M17 + M19;
    Add(R2, M6, NegOne, One, tmp1);
    Add(M12, M17, M19, One, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C12);

    // C13 = R2 - M19 + R1;
    Add(R2, M19, R1, One, NegOne, One, C13);

    // C21 = M1 - M2 + M6 - M7 + M18;
    Add(M1, M2, M6, One, NegOne, One, tmp1);
    Add(tmp1, M7, M18, One, NegOne, One, C21);

    // C22 = M6 + R3;
    Add(M6, R3, One, One, C22);

    // C23 = M4 - R3 + M12 + M16 + R1;
    Add(M4, R3, M12, One, NegOne, One, tmp1);
    Add(M16, R1, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C23);

    // C31 = M1 + M8 - M11;
    Add(M1, M8, M11, One, One, NegOne, C31);

    // C32 = M2 + M5 + M9 + M10 - M11;
    Add(M2, M5, M9, One, One, One, tmp1);
    Add(tmp1, M10, M11, One, One, NegOne, C32);

    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;
    Add(M5, M8, M14, NegOne, NegOne, One, tmp1);
    Add(M15, M19, M21, One, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C33);
    
    tmp1.deallocate();
    tmp2.deallocate();
}


// Template declarations

template void Gemm(Matrix<double>& A, Matrix<double>& B, Matrix<double>& C);
template void Gemm(Matrix<float>& A, Matrix<float>& B, Matrix<float>& C);

template void Negate(Matrix<double>& A, Matrix<double>& C);
template void Negate(Matrix<float>& A, Matrix<float>& C);

template void Add(Matrix<double>& A1, Matrix<double>& A2, double alpha1,
                  double alpha2,  Matrix<double>& C);
template void Add(Matrix<float>& A1, Matrix<float>& A2, float alpha1,
                  float alpha2, Matrix<float>& C);

template void Add(Matrix<double>& A1, Matrix<double>& A2, Matrix<double>& A3,
                  double alpha1, double alpha2, double alpha3,
                  Matrix<double>& C);
template void Add(Matrix<float>& A1, Matrix<float>& A2, Matrix<float>& A3,
                  float alpha1, float alpha2, float alpha3, Matrix<float>& C);

template double FrobeniusDiff(Matrix<double>& A, Matrix<double>& B);
template double FrobeniusDiff(Matrix<float>& A, Matrix<float>& B);

template void FastMatmul3x3(Matrix<double>& A, Matrix<double>& B,
                            Matrix<double>& C, int numsteps);
template void FastMatmul3x3(Matrix<float>& A, Matrix<float>& B,
                            Matrix<float>& C, int numsteps);

#endif  // FAST_3x3_
