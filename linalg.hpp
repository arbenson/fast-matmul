#ifndef _LINALG_HPP_
#define _LINALG_HPP_

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

    Matrix(int n) : m_(n), n_(n), stride_(n), is_view_(false) {
        allocate();
    }

    Matrix(int m, int n) : m_(m), n_(n), stride_(n), is_view_(false) {
        allocate();
    }

    ~Matrix() {
        if (data_ != NULL && !is_view_) {
            deallocate();
        }
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
void GemmWrap(int m, int n, int k, double *A, int lda, double *B, int ldb, double *C,
               int ldc) {
    char transa = 'n';
    char transb = 'n';
    double alpha = 1;
    double beta = 0;    
    dgemm_(&transa, &transb, &m, &n, &n, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
}

// Wrapper for sgemm called by templated gemm.
void GemmWrap(int m, int n, int k, float *A, int lda, float *B, int ldb, float *C,
               int ldc) {
    char transa = 'n';
    char transb = 'n';
    float alpha = 1;
    float beta = 0;
    sgemm_(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta,
           C, &ldc);
}

// Frobenius norm difference: \| A - B \|_F
template<typename Scalar>
double FrobeniusDiff(Matrix<Scalar>& A, Matrix<Scalar>& B) {
    assert(A.m() == B.m() && A.n() == B.n());
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
template <typename Scalar>
void Gemm(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C) {
    assert(A.m() == C.m() && A.n() == B.m() && B.n() == C.n());
    GemmWrap(A.m(), A.n(), B.n(), A.data(), A.stride(), B.data(), B.stride(), C.data(), C.stride());
}

// C <-- alpha1 * A1 + alpha2 * A2
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Scalar alpha1, Scalar alpha2,
         Matrix<Scalar> &C) {
    assert(A1.m() == A2.m() && A2.m() == C.m() &&
	   A1.n() == A2.n() && A2.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = alpha1 * dataA1[i + j * strideA1];
            Scalar b = alpha2 * dataA2[i + j * strideA2];
            dataC[i + j * strideC] = a + b;
        }
    }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Matrix<Scalar>& C) {
    assert(A1.m() == A2.m() && A2.m() == A3.m() && A3.m() == C.m() &&
	   A1.n() == A2.n() && A2.n() == A3.n() && A3.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = alpha1 * dataA1[i + j * strideA1];
            Scalar b = alpha2 * dataA2[i + j * strideA2];
            Scalar c = alpha3 * dataA3[i + j * strideA3];
            dataC[i + j * strideC] = a + b + c;
        }
    }
}

// C <-- alpha1 * A1 + alpha2 * A2 + alpha3 * A3 + alpha4 * A4
template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Matrix<Scalar>& C) {
    assert(A1.m() == A2.m() && A2.m() == A3.m() && A3.m() == C.m() && A4.m() == C.m() &&
	   A1.n() == A2.n() && A2.n() == A3.n() && A3.n() == C.n() && A4.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    Scalar *dataC = C.data();

    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a = alpha1 * dataA1[i + j * strideA1];
            Scalar b = alpha2 * dataA2[i + j * strideA2];
            Scalar c = alpha3 * dataA3[i + j * strideA3];
            Scalar d = alpha4 * dataA4[i + j * strideA4];
            dataC[i + j * strideC] = a + b + c + d;
        }
    }
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

#endif  // _LINALG_HPP_
