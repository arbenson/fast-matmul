#ifndef _smirnov363_40_960_HPP_
#define _smirnov363_40_960_HPP_

// This is an automatically generated file from gen.py.
#include "common.hpp"

namespace smirnov363_40_960 {

template <typename Scalar>
void S_Add1(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + Scalar(-0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add2(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + Scalar(0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add3(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + Scalar(-0.125) * dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add4(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + Scalar(0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add5(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + Scalar(0.125) * dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add6(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + Scalar(-0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add7(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + Scalar(0.125) * dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add8(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + Scalar(-0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add9(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + Scalar(0.125) * dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add10(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + Scalar(-0.125) * dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add11(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add12(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + Scalar(-0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add13(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + Scalar(-0.125) * dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add14(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + Scalar(0.125) * dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add15(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add16(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + Scalar(0.125) * dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add17(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add18(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add19(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add20(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add21(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add22(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + Scalar(-0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add23(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] -dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add24(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add25(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add26(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add27(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add28(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add29(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add30(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add31(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add32(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add33(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add34(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add35(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add36(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add37(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + Scalar(0.125) * dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add38(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + Scalar(-0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add39(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + Scalar(-0.125) * dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add40(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideS7 = S7.stride();
    const int strideS8 = S8.stride();
    const int strideS9 = S9.stride();
    const int strideS10 = S10.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    const Scalar *dataS7 = S7.data();
    const Scalar *dataS8 = S8.data();
    const Scalar *dataS9 = S9.data();
    const Scalar *dataS10 = S10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + Scalar(-0.125) * dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void T_Add1(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + dataT6[i + j * strideT6] -dataT7[i + j * strideT7] + Scalar(0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add2(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] -dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add3(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + Scalar(-0.125) * dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add4(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] -dataT6[i + j * strideT6] -dataT7[i + j * strideT7] + Scalar(-0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add5(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add6(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add7(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + Scalar(0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add8(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] -dataT6[i + j * strideT6] -dataT7[i + j * strideT7] + Scalar(0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add9(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] -dataT7[i + j * strideT7] + Scalar(-0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add10(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add11(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add12(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add13(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] -dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + Scalar(0.125) * dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add14(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + Scalar(-0.125) * dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add15(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add16(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9];
        }
    }
}

template <typename Scalar>
void T_Add17(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add18(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] -dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add19(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add20(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] -dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add21(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add22(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add23(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add24(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add25(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] -dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add26(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] -dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add27(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add28(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add29(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add30(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add31(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add32(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + Scalar(-0.125) * dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add33(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add34(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add35(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add36(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] -dataT8[i + j * strideT8] -dataT9[i + j * strideT9] + Scalar(-0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add37(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(-0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] + dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add38(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(-0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] -dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(-0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add39(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(0.125) * dataT5[i + j * strideT5] + Scalar(0.125) * dataT6[i + j * strideT6] + Scalar(-0.125) * dataT7[i + j * strideT7] + dataT8[i + j * strideT8] + dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void T_Add40(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& T7, Matrix<Scalar>& T8, Matrix<Scalar>& T9, Matrix<Scalar>& T10, Matrix<Scalar>& C, double x=1e-8) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideT7 = T7.stride();
    const int strideT8 = T8.stride();
    const int strideT9 = T9.stride();
    const int strideT10 = T10.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    const Scalar *dataT7 = T7.data();
    const Scalar *dataT8 = T8.data();
    const Scalar *dataT9 = T9.data();
    const Scalar *dataT10 = T10.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + Scalar(0.125) * dataT3[i + j * strideT3] + Scalar(0.125) * dataT4[i + j * strideT4] + Scalar(-0.125) * dataT5[i + j * strideT5] + Scalar(-0.125) * dataT6[i + j * strideT6] -dataT7[i + j * strideT7] -dataT8[i + j * strideT8] + Scalar(0.125) * dataT9[i + j * strideT9] + Scalar(0.125) * dataT10[i + j * strideT10];
        }
    }
}

template <typename Scalar>
void M_Add1(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] + dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] + dataM27[i + j * strideM27] -dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] + dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] + dataM27[i + j * strideM27] -dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add2(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8];
            }
        }
    }
}

template <typename Scalar>
void M_Add3(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] + dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] -dataM24[i + j * strideM24] -dataM25[i + j * strideM25] -dataM26[i + j * strideM26] -dataM27[i + j * strideM27] -dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] + dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] -dataM24[i + j * strideM24] -dataM25[i + j * strideM25] -dataM26[i + j * strideM26] -dataM27[i + j * strideM27] -dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add4(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8];
            }
        }
    }
}

template <typename Scalar>
void M_Add5(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] + dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] -dataM27[i + j * strideM27] + dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] + dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] -dataM27[i + j * strideM27] + dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add6(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] -dataM24[i + j * strideM24] -dataM25[i + j * strideM25] -dataM26[i + j * strideM26] + dataM27[i + j * strideM27] + dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] -dataM24[i + j * strideM24] -dataM25[i + j * strideM25] -dataM26[i + j * strideM26] + dataM27[i + j * strideM27] + dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add7(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] + dataM27[i + j * strideM27] + dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] -dataM18[i + j * strideM18] -dataM19[i + j * strideM19] + dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + dataM25[i + j * strideM25] + dataM26[i + j * strideM26] + dataM27[i + j * strideM27] + dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add8(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& M25, Matrix<Scalar>& M26, Matrix<Scalar>& M27, Matrix<Scalar>& M28, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideM9 = M9.stride();
    const int strideM10 = M10.stride();
    const int strideM11 = M11.stride();
    const int strideM12 = M12.stride();
    const int strideM13 = M13.stride();
    const int strideM14 = M14.stride();
    const int strideM15 = M15.stride();
    const int strideM16 = M16.stride();
    const int strideM17 = M17.stride();
    const int strideM18 = M18.stride();
    const int strideM19 = M19.stride();
    const int strideM20 = M20.stride();
    const int strideM21 = M21.stride();
    const int strideM22 = M22.stride();
    const int strideM23 = M23.stride();
    const int strideM24 = M24.stride();
    const int strideM25 = M25.stride();
    const int strideM26 = M26.stride();
    const int strideM27 = M27.stride();
    const int strideM28 = M28.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    const Scalar *dataM9 = M9.data();
    const Scalar *dataM10 = M10.data();
    const Scalar *dataM11 = M11.data();
    const Scalar *dataM12 = M12.data();
    const Scalar *dataM13 = M13.data();
    const Scalar *dataM14 = M14.data();
    const Scalar *dataM15 = M15.data();
    const Scalar *dataM16 = M16.data();
    const Scalar *dataM17 = M17.data();
    const Scalar *dataM18 = M18.data();
    const Scalar *dataM19 = M19.data();
    const Scalar *dataM20 = M20.data();
    const Scalar *dataM21 = M21.data();
    const Scalar *dataM22 = M22.data();
    const Scalar *dataM23 = M23.data();
    const Scalar *dataM24 = M24.data();
    const Scalar *dataM25 = M25.data();
    const Scalar *dataM26 = M26.data();
    const Scalar *dataM27 = M27.data();
    const Scalar *dataM28 = M28.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] -dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] + dataM24[i + j * strideM24] -dataM25[i + j * strideM25] + dataM26[i + j * strideM26] -dataM27[i + j * strideM27] + dataM28[i + j * strideM28] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] -dataM17[i + j * strideM17] -dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] -dataM23[i + j * strideM23] + dataM24[i + j * strideM24] -dataM25[i + j * strideM25] + dataM26[i + j * strideM26] -dataM27[i + j * strideM27] + dataM28[i + j * strideM28];
            }
        }
    }
}

template <typename Scalar>
void M_Add9(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& C, double x=1e-8, Scalar beta=Scalar(0.0)) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideM7 = M7.stride();
    const int strideM8 = M8.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    const Scalar *dataM7 = M7.data();
    const Scalar *dataM8 = M8.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for collapse(2)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8];
            }
        }
    }
}

template <typename Scalar>
void FastMatmulRecursive(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int total_steps, int steps_left, int start_index, double x, int num_threads, Scalar beta) {
    // Update multipliers
    C.UpdateMultiplier(A.multiplier());
    C.UpdateMultiplier(B.multiplier());
    A.set_multiplier(Scalar(1.0));
    B.set_multiplier(Scalar(1.0));
    // Base case for recursion
    if (steps_left == 0) {
        Gemm(A, B, C);
        return;
    }

    Matrix<Scalar> A11 = A.Subblock(3, 6, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 6, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(3, 6, 1, 3);
    Matrix<Scalar> A14 = A.Subblock(3, 6, 1, 4);
    Matrix<Scalar> A15 = A.Subblock(3, 6, 1, 5);
    Matrix<Scalar> A16 = A.Subblock(3, 6, 1, 6);
    Matrix<Scalar> A21 = A.Subblock(3, 6, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 6, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(3, 6, 2, 3);
    Matrix<Scalar> A24 = A.Subblock(3, 6, 2, 4);
    Matrix<Scalar> A25 = A.Subblock(3, 6, 2, 5);
    Matrix<Scalar> A26 = A.Subblock(3, 6, 2, 6);
    Matrix<Scalar> A31 = A.Subblock(3, 6, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 6, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(3, 6, 3, 3);
    Matrix<Scalar> A34 = A.Subblock(3, 6, 3, 4);
    Matrix<Scalar> A35 = A.Subblock(3, 6, 3, 5);
    Matrix<Scalar> A36 = A.Subblock(3, 6, 3, 6);
    Matrix<Scalar> B11 = B.Subblock(6, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(6, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(6, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(6, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(6, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(6, 3, 2, 3);
    Matrix<Scalar> B31 = B.Subblock(6, 3, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(6, 3, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(6, 3, 3, 3);
    Matrix<Scalar> B41 = B.Subblock(6, 3, 4, 1);
    Matrix<Scalar> B42 = B.Subblock(6, 3, 4, 2);
    Matrix<Scalar> B43 = B.Subblock(6, 3, 4, 3);
    Matrix<Scalar> B51 = B.Subblock(6, 3, 5, 1);
    Matrix<Scalar> B52 = B.Subblock(6, 3, 5, 2);
    Matrix<Scalar> B53 = B.Subblock(6, 3, 5, 3);
    Matrix<Scalar> B61 = B.Subblock(6, 3, 6, 1);
    Matrix<Scalar> B62 = B.Subblock(6, 3, 6, 2);
    Matrix<Scalar> B63 = B.Subblock(6, 3, 6, 3);
    Matrix<Scalar> C11 = C.Subblock(3, 3, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(3, 3, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(3, 3, 1, 3);
    Matrix<Scalar> C21 = C.Subblock(3, 3, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(3, 3, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(3, 3, 2, 3);
    Matrix<Scalar> C31 = C.Subblock(3, 3, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(3, 3, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(3, 3, 3, 3);


    // Matrices to store the results of multiplications.
    Matrix<Scalar> M1(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M2(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M3(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M4(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M5(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M6(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M7(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M8(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M9(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M10(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M11(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M12(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M13(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M14(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M15(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M16(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M17(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M18(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M19(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M20(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M21(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M22(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M23(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M24(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M25(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M26(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M27(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M28(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M29(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M30(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M31(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M32(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M33(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M34(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M35(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M36(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M37(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M38(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M39(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M40(C11.m(), C11.n(), C.multiplier());



    // M1 = (-0.125 * A11 + -1.0 * A12 + 1.0 * A16 + -0.125 * A21 + 1.0 * A23 + 1.0 * A24 + 1.0 * A32 + 1.0 * A34 + -0.125 * A35) * (-1.0 * B13 + -0.125 * B21 + 0.125 * B32 + 0.125 * B33 + 0.125 * B42 + 1.0 * B51 + -1.0 * B52 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 1, num_threads)) untied
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    S_Add1(A11, A12, A16, A21, A23, A24, A32, A34, A35, S1, x);
    Matrix<Scalar> T1(B11.m(), B11.n());
    T_Add1(B13, B21, B32, B33, B42, B51, B52, B61, B63, T1, x);
    FastMatmulRecursive(S1, T1, M1, total_steps, steps_left - 1, (start_index + 1 - 1) * 40, x, num_threads, Scalar(0.0));
    S1.deallocate();
    T1.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 1, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M2 = (0.125 * A11 + -1.0 * A13 + -1.0 * A14 + 0.125 * A21 + 1.0 * A22 + -1.0 * A26 + 1.0 * A33 + 0.125 * A35 + -1.0 * A36) * (-1.0 * B13 + 0.125 * B22 + -0.125 * B23 + -0.125 * B31 + -0.125 * B41 + 0.125 * B43 + -1.0 * B51 + 1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 2, num_threads)) untied
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    S_Add2(A11, A13, A14, A21, A22, A26, A33, A35, A36, S2, x);
    Matrix<Scalar> T2(B11.m(), B11.n());
    T_Add2(B13, B22, B23, B31, B41, B43, B51, B52, B62, T2, x);
    FastMatmulRecursive(S2, T2, M2, total_steps, steps_left - 1, (start_index + 2 - 1) * 40, x, num_threads, Scalar(0.0));
    S2.deallocate();
    T2.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 2, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M3 = (-1.0 * A13 + -0.125 * A15 + 1.0 * A16 + 1.0 * A22 + 1.0 * A24 + -0.125 * A25 + -0.125 * A31 + 1.0 * A33 + 1.0 * A34) * (-1.0 * B11 + -1.0 * B12 + 0.125 * B22 + -0.125 * B23 + 0.125 * B31 + 0.125 * B42 + 1.0 * B53 + -0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 3, num_threads)) untied
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    S_Add3(A13, A15, A16, A22, A24, A25, A31, A33, A34, S3, x);
    Matrix<Scalar> T3(B11.m(), B11.n());
    T_Add3(B11, B12, B22, B23, B31, B42, B53, B61, B63, T3, x);
    FastMatmulRecursive(S3, T3, M3, total_steps, steps_left - 1, (start_index + 3 - 1) * 40, x, num_threads, Scalar(0.0));
    S3.deallocate();
    T3.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 3, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M4 = (-0.125 * A11 + 1.0 * A12 + 1.0 * A16 + 0.125 * A21 + 1.0 * A23 + -1.0 * A24 + -1.0 * A32 + 1.0 * A34 + -0.125 * A35) * (-1.0 * B13 + -0.125 * B21 + -0.125 * B32 + -0.125 * B33 + 0.125 * B42 + -1.0 * B51 + -1.0 * B52 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 4, num_threads)) untied
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    S_Add4(A11, A12, A16, A21, A23, A24, A32, A34, A35, S4, x);
    Matrix<Scalar> T4(B11.m(), B11.n());
    T_Add4(B13, B21, B32, B33, B42, B51, B52, B61, B63, T4, x);
    FastMatmulRecursive(S4, T4, M4, total_steps, steps_left - 1, (start_index + 4 - 1) * 40, x, num_threads, Scalar(0.0));
    S4.deallocate();
    T4.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 4, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M5 = (-0.125 * A11 + -1.0 * A13 + 1.0 * A14 + 0.125 * A21 + -1.0 * A22 + -1.0 * A26 + 1.0 * A33 + -0.125 * A35 + 1.0 * A36) * (-1.0 * B13 + -0.125 * B22 + 0.125 * B23 + -0.125 * B31 + 0.125 * B41 + 0.125 * B43 + 1.0 * B51 + 1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 5, num_threads)) untied
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    S_Add5(A11, A13, A14, A21, A22, A26, A33, A35, A36, S5, x);
    Matrix<Scalar> T5(B11.m(), B11.n());
    T_Add5(B13, B22, B23, B31, B41, B43, B51, B52, B62, T5, x);
    FastMatmulRecursive(S5, T5, M5, total_steps, steps_left - 1, (start_index + 5 - 1) * 40, x, num_threads, Scalar(0.0));
    S5.deallocate();
    T5.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 5, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M6 = (1.0 * A12 + -1.0 * A14 + -0.125 * A15 + 1.0 * A23 + 0.125 * A25 + 1.0 * A26 + 0.125 * A31 + 1.0 * A32 + 1.0 * A36) * (-1.0 * B11 + 1.0 * B12 + -0.125 * B21 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + -0.125 * B43 + -1.0 * B53 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 6, num_threads)) untied
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    S_Add6(A12, A14, A15, A23, A25, A26, A31, A32, A36, S6, x);
    Matrix<Scalar> T6(B11.m(), B11.n());
    T_Add6(B11, B12, B21, B32, B33, B41, B43, B53, B62, T6, x);
    FastMatmulRecursive(S6, T6, M6, total_steps, steps_left - 1, (start_index + 6 - 1) * 40, x, num_threads, Scalar(0.0));
    S6.deallocate();
    T6.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 6, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M7 = (-1.0 * A13 + -0.125 * A15 + -1.0 * A16 + -1.0 * A22 + 1.0 * A24 + 0.125 * A25 + 0.125 * A31 + -1.0 * A33 + 1.0 * A34) * (-1.0 * B11 + 1.0 * B12 + -0.125 * B22 + -0.125 * B23 + 0.125 * B31 + 0.125 * B42 + 1.0 * B53 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 7, num_threads)) untied
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    S_Add7(A13, A15, A16, A22, A24, A25, A31, A33, A34, S7, x);
    Matrix<Scalar> T7(B11.m(), B11.n());
    T_Add7(B11, B12, B22, B23, B31, B42, B53, B61, B63, T7, x);
    FastMatmulRecursive(S7, T7, M7, total_steps, steps_left - 1, (start_index + 7 - 1) * 40, x, num_threads, Scalar(0.0));
    S7.deallocate();
    T7.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 7, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M8 = (0.125 * A11 + 1.0 * A12 + 1.0 * A16 + -0.125 * A21 + 1.0 * A23 + -1.0 * A24 + 1.0 * A32 + -1.0 * A34 + -0.125 * A35) * (1.0 * B13 + 0.125 * B21 + 0.125 * B32 + -0.125 * B33 + -0.125 * B42 + -1.0 * B51 + -1.0 * B52 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 8, num_threads)) untied
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    S_Add8(A11, A12, A16, A21, A23, A24, A32, A34, A35, S8, x);
    Matrix<Scalar> T8(B11.m(), B11.n());
    T_Add8(B13, B21, B32, B33, B42, B51, B52, B61, B63, T8, x);
    FastMatmulRecursive(S8, T8, M8, total_steps, steps_left - 1, (start_index + 8 - 1) * 40, x, num_threads, Scalar(0.0));
    S8.deallocate();
    T8.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 8, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M9 = (1.0 * A13 + -0.125 * A15 + 1.0 * A16 + 1.0 * A22 + -1.0 * A24 + 0.125 * A25 + -0.125 * A31 + -1.0 * A33 + 1.0 * A34) * (-1.0 * B11 + 1.0 * B12 + 0.125 * B22 + -0.125 * B23 + -0.125 * B31 + -0.125 * B42 + -1.0 * B53 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 9, num_threads)) untied
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    S_Add9(A13, A15, A16, A22, A24, A25, A31, A33, A34, S9, x);
    Matrix<Scalar> T9(B11.m(), B11.n());
    T_Add9(B11, B12, B22, B23, B31, B42, B53, B61, B63, T9, x);
    FastMatmulRecursive(S9, T9, M9, total_steps, steps_left - 1, (start_index + 9 - 1) * 40, x, num_threads, Scalar(0.0));
    S9.deallocate();
    T9.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 9, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M10 = (-1.0 * A12 + 1.0 * A14 + -0.125 * A15 + -1.0 * A23 + 0.125 * A25 + -1.0 * A26 + -0.125 * A31 + 1.0 * A32 + 1.0 * A36) * (-1.0 * B11 + 1.0 * B12 + 0.125 * B21 + -0.125 * B32 + -0.125 * B33 + -0.125 * B41 + -0.125 * B43 + 1.0 * B53 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 10, num_threads)) untied
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    S_Add10(A12, A14, A15, A23, A25, A26, A31, A32, A36, S10, x);
    Matrix<Scalar> T10(B11.m(), B11.n());
    T_Add10(B11, B12, B21, B32, B33, B41, B43, B53, B62, T10, x);
    FastMatmulRecursive(S10, T10, M10, total_steps, steps_left - 1, (start_index + 10 - 1) * 40, x, num_threads, Scalar(0.0));
    S10.deallocate();
    T10.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 10, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M11 = (1.0 * A12 + 1.0 * A14 + 0.125 * A15 + -1.0 * A23 + 0.125 * A25 + 1.0 * A26 + -0.125 * A31 + 1.0 * A32 + -1.0 * A36) * (-1.0 * B11 + -1.0 * B12 + 0.125 * B21 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + 0.125 * B43 + 1.0 * B53 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 11, num_threads)) untied
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    S_Add11(A12, A14, A15, A23, A25, A26, A31, A32, A36, S11, x);
    Matrix<Scalar> T11(B11.m(), B11.n());
    T_Add11(B11, B12, B21, B32, B33, B41, B43, B53, B62, T11, x);
    FastMatmulRecursive(S11, T11, M11, total_steps, steps_left - 1, (start_index + 11 - 1) * 40, x, num_threads, Scalar(0.0));
    S11.deallocate();
    T11.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 11, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M12 = (-0.125 * A11 + -1.0 * A13 + -1.0 * A14 + -0.125 * A21 + 1.0 * A22 + -1.0 * A26 + -1.0 * A33 + 0.125 * A35 + 1.0 * A36) * (-1.0 * B13 + 0.125 * B22 + 0.125 * B23 + -0.125 * B31 + -0.125 * B41 + -0.125 * B43 + 1.0 * B51 + -1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 12, num_threads)) untied
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    S_Add12(A11, A13, A14, A21, A22, A26, A33, A35, A36, S12, x);
    Matrix<Scalar> T12(B11.m(), B11.n());
    T_Add12(B13, B22, B23, B31, B41, B43, B51, B52, B62, T12, x);
    FastMatmulRecursive(S12, T12, M12, total_steps, steps_left - 1, (start_index + 12 - 1) * 40, x, num_threads, Scalar(0.0));
    S12.deallocate();
    T12.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 12, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M13 = (-0.125 * A11 + 1.0 * A12 + -1.0 * A16 + -0.125 * A21 + -1.0 * A23 + -1.0 * A24 + 1.0 * A32 + 1.0 * A34 + 0.125 * A35) * (-1.0 * B13 + -0.125 * B21 + 0.125 * B32 + -0.125 * B33 + 0.125 * B42 + -1.0 * B51 + 1.0 * B52 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 13, num_threads)) untied
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    S_Add13(A11, A12, A16, A21, A23, A24, A32, A34, A35, S13, x);
    Matrix<Scalar> T13(B11.m(), B11.n());
    T_Add13(B13, B21, B32, B33, B42, B51, B52, B61, B63, T13, x);
    FastMatmulRecursive(S13, T13, M13, total_steps, steps_left - 1, (start_index + 13 - 1) * 40, x, num_threads, Scalar(0.0));
    S13.deallocate();
    T13.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 13, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M14 = (-1.0 * A13 + 0.125 * A15 + 1.0 * A16 + 1.0 * A22 + 1.0 * A24 + 0.125 * A25 + -0.125 * A31 + -1.0 * A33 + -1.0 * A34) * (1.0 * B11 + 1.0 * B12 + 0.125 * B22 + 0.125 * B23 + 0.125 * B31 + 0.125 * B42 + 1.0 * B53 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 14, num_threads)) untied
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    S_Add14(A13, A15, A16, A22, A24, A25, A31, A33, A34, S14, x);
    Matrix<Scalar> T14(B11.m(), B11.n());
    T_Add14(B11, B12, B22, B23, B31, B42, B53, B61, B63, T14, x);
    FastMatmulRecursive(S14, T14, M14, total_steps, steps_left - 1, (start_index + 14 - 1) * 40, x, num_threads, Scalar(0.0));
    S14.deallocate();
    T14.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 14, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M15 = (-1.0 * A12 + -1.0 * A14 + 0.125 * A15 + 1.0 * A23 + 0.125 * A25 + -1.0 * A26 + 0.125 * A31 + 1.0 * A32 + -1.0 * A36) * (1.0 * B11 + 1.0 * B12 + 0.125 * B21 + 0.125 * B32 + 0.125 * B33 + 0.125 * B41 + -0.125 * B43 + 1.0 * B53 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 15, num_threads)) untied
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    S_Add15(A12, A14, A15, A23, A25, A26, A31, A32, A36, S15, x);
    Matrix<Scalar> T15(B11.m(), B11.n());
    T_Add15(B11, B12, B21, B32, B33, B41, B43, B53, B62, T15, x);
    FastMatmulRecursive(S15, T15, M15, total_steps, steps_left - 1, (start_index + 15 - 1) * 40, x, num_threads, Scalar(0.0));
    S15.deallocate();
    T15.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 15, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M16 = (-0.125 * A11 + 1.0 * A13 + -1.0 * A14 + 0.125 * A21 + 1.0 * A22 + 1.0 * A26 + 1.0 * A33 + 0.125 * A35 + 1.0 * A36) * (1.0 * B13 + 0.125 * B22 + 0.125 * B23 + 0.125 * B31 + -0.125 * B41 + 0.125 * B43 + 1.0 * B51 + 1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 16, num_threads)) untied
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    S_Add16(A11, A13, A14, A21, A22, A26, A33, A35, A36, S16, x);
    Matrix<Scalar> T16(B11.m(), B11.n());
    T_Add16(B13, B22, B23, B31, B41, B43, B51, B52, B62, T16, x);
    FastMatmulRecursive(S16, T16, M16, total_steps, steps_left - 1, (start_index + 16 - 1) * 40, x, num_threads, Scalar(0.0));
    S16.deallocate();
    T16.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 16, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M17 = (-0.125 * A11 + -0.125 * A15 + 0.125 * A21 + 1.0 * A22 + -1.0 * A23 + 1.0 * A24 + -0.125 * A25 + 1.0 * A26 + 1.0 * A34 + 1.0 * A36) * (-1.0 * B11 + -1.0 * B12 + -0.125 * B21 + 0.125 * B31 + -0.125 * B41 + 0.125 * B43 + 1.0 * B51 + 1.0 * B52 + -0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 17, num_threads)) untied
    {
#endif
    Matrix<Scalar> S17(A11.m(), A11.n());
    S_Add17(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S17, x);
    Matrix<Scalar> T17(B11.m(), B11.n());
    T_Add17(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T17, x);
    FastMatmulRecursive(S17, T17, M17, total_steps, steps_left - 1, (start_index + 17 - 1) * 40, x, num_threads, Scalar(0.0));
    S17.deallocate();
    T17.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 17, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M18 = (-0.125 * A11 + 1.0 * A12 + -1.0 * A13 + 1.0 * A14 + -0.125 * A15 + 1.0 * A16 + 0.125 * A21 + -0.125 * A25 + -1.0 * A32 + 1.0 * A33) * (-1.0 * B11 + -1.0 * B12 + 0.125 * B22 + -0.125 * B23 + -0.125 * B32 + -0.125 * B33 + 0.125 * B42 + -1.0 * B51 + -1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 18, num_threads)) untied
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    S_Add18(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S18, x);
    Matrix<Scalar> T18(B11.m(), B11.n());
    T_Add18(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T18, x);
    FastMatmulRecursive(S18, T18, M18, total_steps, steps_left - 1, (start_index + 18 - 1) * 40, x, num_threads, Scalar(0.0));
    S18.deallocate();
    T18.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 18, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M19 = (0.125 * A11 + 0.125 * A15 + 0.125 * A21 + 1.0 * A22 + -1.0 * A23 + -1.0 * A24 + -0.125 * A25 + -1.0 * A26 + -1.0 * A34 + -1.0 * A36) * (-1.0 * B11 + 1.0 * B12 + -0.125 * B21 + 0.125 * B31 + 0.125 * B41 + -0.125 * B43 + 1.0 * B51 + -1.0 * B52 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 19, num_threads)) untied
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    S_Add19(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S19, x);
    Matrix<Scalar> T19(B11.m(), B11.n());
    T_Add19(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T19, x);
    FastMatmulRecursive(S19, T19, M19, total_steps, steps_left - 1, (start_index + 19 - 1) * 40, x, num_threads, Scalar(0.0));
    S19.deallocate();
    T19.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 19, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M20 = (0.125 * A11 + 1.0 * A12 + 1.0 * A13 + 1.0 * A14 + -0.125 * A15 + -1.0 * A16 + 0.125 * A21 + -0.125 * A25 + -1.0 * A32 + 1.0 * A33) * (1.0 * B11 + 1.0 * B12 + 0.125 * B22 + 0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B42 + 1.0 * B51 + -1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 20, num_threads)) untied
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    S_Add20(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S20, x);
    Matrix<Scalar> T20(B11.m(), B11.n());
    T_Add20(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T20, x);
    FastMatmulRecursive(S20, T20, M20, total_steps, steps_left - 1, (start_index + 20 - 1) * 40, x, num_threads, Scalar(0.0));
    S20.deallocate();
    T20.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 20, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M21 = (-0.125 * A11 + -0.125 * A15 + 0.125 * A21 + 1.0 * A22 + 1.0 * A23 + -1.0 * A24 + 0.125 * A25 + 1.0 * A26 + 1.0 * A34 + 1.0 * A36) * (1.0 * B11 + -1.0 * B12 + 0.125 * B21 + 0.125 * B31 + -0.125 * B41 + 0.125 * B43 + 1.0 * B51 + 1.0 * B52 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 21, num_threads)) untied
    {
#endif
    Matrix<Scalar> S21(A11.m(), A11.n());
    S_Add21(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S21, x);
    Matrix<Scalar> T21(B11.m(), B11.n());
    T_Add21(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T21, x);
    FastMatmulRecursive(S21, T21, M21, total_steps, steps_left - 1, (start_index + 21 - 1) * 40, x, num_threads, Scalar(0.0));
    S21.deallocate();
    T21.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 21, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M22 = (-0.125 * A11 + -0.125 * A15 + -0.125 * A21 + 1.0 * A22 + 1.0 * A23 + 1.0 * A24 + -0.125 * A25 + -1.0 * A26 + 1.0 * A34 + 1.0 * A36) * (1.0 * B11 + 1.0 * B12 + -0.125 * B21 + -0.125 * B31 + -0.125 * B41 + -0.125 * B43 + 1.0 * B51 + -1.0 * B52 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 22, num_threads)) untied
    {
#endif
    Matrix<Scalar> S22(A11.m(), A11.n());
    S_Add22(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S22, x);
    Matrix<Scalar> T22(B11.m(), B11.n());
    T_Add22(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T22, x);
    FastMatmulRecursive(S22, T22, M22, total_steps, steps_left - 1, (start_index + 22 - 1) * 40, x, num_threads, Scalar(0.0));
    S22.deallocate();
    T22.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 22, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M23 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + 0.125 * A31 + 1.0 * A32 + -1.0 * A33 + -1.0 * A34 + -0.125 * A35 + 1.0 * A36) * (1.0 * B13 + -0.125 * B22 + 0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + -0.125 * B43 + -1.0 * B53 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 23, num_threads)) untied
    {
#endif
    Matrix<Scalar> S23(A11.m(), A11.n());
    S_Add23(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S23, x);
    Matrix<Scalar> T23(B11.m(), B11.n());
    T_Add23(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T23, x);
    FastMatmulRecursive(S23, T23, M23, total_steps, steps_left - 1, (start_index + 23 - 1) * 40, x, num_threads, Scalar(0.0));
    S23.deallocate();
    T23.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 23, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M24 = (-1.0 * A12 + -1.0 * A13 + 1.0 * A24 + -1.0 * A26 + 0.125 * A31 + 1.0 * A32 + -1.0 * A33 + 1.0 * A34 + -0.125 * A35 + -1.0 * A36) * (-1.0 * B13 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B41 + -0.125 * B43 + 1.0 * B53 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 24, num_threads)) untied
    {
#endif
    Matrix<Scalar> S24(A11.m(), A11.n());
    S_Add24(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S24, x);
    Matrix<Scalar> T24(B11.m(), B11.n());
    T_Add24(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T24, x);
    FastMatmulRecursive(S24, T24, M24, total_steps, steps_left - 1, (start_index + 24 - 1) * 40, x, num_threads, Scalar(0.0));
    S24.deallocate();
    T24.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 24, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M25 = (-0.125 * A11 + -1.0 * A12 + 1.0 * A13 + 1.0 * A14 + -0.125 * A15 + 1.0 * A16 + -0.125 * A21 + 0.125 * A25 + 1.0 * A32 + -1.0 * A33) * (1.0 * B11 + -1.0 * B12 + -0.125 * B22 + 0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B42 + 1.0 * B51 + -1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 25, num_threads)) untied
    {
#endif
    Matrix<Scalar> S25(A11.m(), A11.n());
    S_Add25(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S25, x);
    Matrix<Scalar> T25(B11.m(), B11.n());
    T_Add25(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T25, x);
    FastMatmulRecursive(S25, T25, M25, total_steps, steps_left - 1, (start_index + 25 - 1) * 40, x, num_threads, Scalar(0.0));
    S25.deallocate();
    T25.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 25, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M26 = (-0.125 * A11 + -1.0 * A12 + -1.0 * A13 + 1.0 * A14 + 0.125 * A15 + -1.0 * A16 + 0.125 * A21 + -0.125 * A25 + -1.0 * A32 + 1.0 * A33) * (-1.0 * B11 + 1.0 * B12 + 0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + -0.125 * B42 + -1.0 * B51 + -1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 26, num_threads)) untied
    {
#endif
    Matrix<Scalar> S26(A11.m(), A11.n());
    S_Add26(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S26, x);
    Matrix<Scalar> T26(B11.m(), B11.n());
    T_Add26(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T26, x);
    FastMatmulRecursive(S26, T26, M26, total_steps, steps_left - 1, (start_index + 26 - 1) * 40, x, num_threads, Scalar(0.0));
    S26.deallocate();
    T26.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 26, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M27 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + 0.125 * A31 + -1.0 * A32 + -1.0 * A33 + -1.0 * A34 + 0.125 * A35 + -1.0 * A36) * (-1.0 * B13 + -0.125 * B22 + 0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B41 + 0.125 * B43 + -1.0 * B53 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 27, num_threads)) untied
    {
#endif
    Matrix<Scalar> S27(A11.m(), A11.n());
    S_Add27(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S27, x);
    Matrix<Scalar> T27(B11.m(), B11.n());
    T_Add27(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T27, x);
    FastMatmulRecursive(S27, T27, M27, total_steps, steps_left - 1, (start_index + 27 - 1) * 40, x, num_threads, Scalar(0.0));
    S27.deallocate();
    T27.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 27, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M28 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + -0.125 * A31 + 1.0 * A32 + 1.0 * A33 + -1.0 * A34 + -0.125 * A35 + -1.0 * A36) * (1.0 * B13 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + 0.125 * B43 + 1.0 * B53 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 28, num_threads)) untied
    {
#endif
    Matrix<Scalar> S28(A11.m(), A11.n());
    S_Add28(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S28, x);
    Matrix<Scalar> T28(B11.m(), B11.n());
    T_Add28(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T28, x);
    FastMatmulRecursive(S28, T28, M28, total_steps, steps_left - 1, (start_index + 28 - 1) * 40, x, num_threads, Scalar(0.0));
    S28.deallocate();
    T28.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 28, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M29 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + 0.125 * A31 + 1.0 * A32 + 1.0 * A33 + 1.0 * A34 + 0.125 * A35 + 1.0 * A36) * (-1.0 * B13 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + -0.125 * B43 + -1.0 * B53 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 29, num_threads)) untied
    {
#endif
    Matrix<Scalar> S29(A11.m(), A11.n());
    S_Add29(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S29, x);
    Matrix<Scalar> T29(B11.m(), B11.n());
    T_Add29(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T29, x);
    FastMatmulRecursive(S29, T29, M29, total_steps, steps_left - 1, (start_index + 29 - 1) * 40, x, num_threads, Scalar(0.0));
    S29.deallocate();
    T29.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 29, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M30 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + -0.125 * A31 + 1.0 * A32 + -1.0 * A33 + 1.0 * A34 + 0.125 * A35 + -1.0 * A36) * (-1.0 * B13 + -0.125 * B22 + 0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B41 + 0.125 * B43 + 1.0 * B53 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 30, num_threads)) untied
    {
#endif
    Matrix<Scalar> S30(A11.m(), A11.n());
    S_Add30(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S30, x);
    Matrix<Scalar> T30(B11.m(), B11.n());
    T_Add30(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T30, x);
    FastMatmulRecursive(S30, T30, M30, total_steps, steps_left - 1, (start_index + 30 - 1) * 40, x, num_threads, Scalar(0.0));
    S30.deallocate();
    T30.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 30, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M31 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A26 + 0.125 * A31 + -1.0 * A32 + 1.0 * A33 + 1.0 * A34 + -0.125 * A35 + -1.0 * A36) * (1.0 * B13 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B41 + 0.125 * B43 + -1.0 * B53 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 31, num_threads)) untied
    {
#endif
    Matrix<Scalar> S31(A11.m(), A11.n());
    S_Add31(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S31, x);
    Matrix<Scalar> T31(B11.m(), B11.n());
    T_Add31(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T31, x);
    FastMatmulRecursive(S31, T31, M31, total_steps, steps_left - 1, (start_index + 31 - 1) * 40, x, num_threads, Scalar(0.0));
    S31.deallocate();
    T31.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 31, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M32 = (-1.0 * A12 + -1.0 * A13 + 1.0 * A24 + -1.0 * A26 + 0.125 * A31 + 1.0 * A32 + 1.0 * A33 + -1.0 * A34 + 0.125 * A35 + -1.0 * A36) * (1.0 * B13 + -0.125 * B22 + 0.125 * B23 + 0.125 * B32 + 0.125 * B33 + 0.125 * B41 + -0.125 * B43 + 1.0 * B53 + 0.125 * B61 + -0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 32, num_threads)) untied
    {
#endif
    Matrix<Scalar> S32(A11.m(), A11.n());
    S_Add32(A12, A13, A24, A26, A31, A32, A33, A34, A35, A36, S32, x);
    Matrix<Scalar> T32(B11.m(), B11.n());
    T_Add32(B13, B22, B23, B32, B33, B41, B43, B53, B61, B63, T32, x);
    FastMatmulRecursive(S32, T32, M32, total_steps, steps_left - 1, (start_index + 32 - 1) * 40, x, num_threads, Scalar(0.0));
    S32.deallocate();
    T32.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 32, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M33 = (-0.125 * A11 + 1.0 * A12 + -1.0 * A13 + -1.0 * A14 + -0.125 * A15 + -1.0 * A16 + -0.125 * A21 + 0.125 * A25 + 1.0 * A32 + -1.0 * A33) * (-1.0 * B11 + 1.0 * B12 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B42 + -1.0 * B51 + 1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 33, num_threads)) untied
    {
#endif
    Matrix<Scalar> S33(A11.m(), A11.n());
    S_Add33(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S33, x);
    Matrix<Scalar> T33(B11.m(), B11.n());
    T_Add33(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T33, x);
    FastMatmulRecursive(S33, T33, M33, total_steps, steps_left - 1, (start_index + 33 - 1) * 40, x, num_threads, Scalar(0.0));
    S33.deallocate();
    T33.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 33, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M34 = (0.125 * A11 + 0.125 * A15 + 0.125 * A21 + 1.0 * A22 + 1.0 * A23 + 1.0 * A24 + 0.125 * A25 + -1.0 * A26 + -1.0 * A34 + -1.0 * A36) * (1.0 * B11 + 1.0 * B12 + 0.125 * B21 + 0.125 * B31 + 0.125 * B41 + -0.125 * B43 + 1.0 * B51 + -1.0 * B52 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 34, num_threads)) untied
    {
#endif
    Matrix<Scalar> S34(A11.m(), A11.n());
    S_Add34(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S34, x);
    Matrix<Scalar> T34(B11.m(), B11.n());
    T_Add34(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T34, x);
    FastMatmulRecursive(S34, T34, M34, total_steps, steps_left - 1, (start_index + 34 - 1) * 40, x, num_threads, Scalar(0.0));
    S34.deallocate();
    T34.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 34, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M35 = (-0.125 * A11 + 1.0 * A12 + 1.0 * A13 + 1.0 * A14 + 0.125 * A15 + -1.0 * A16 + -0.125 * A21 + 0.125 * A25 + 1.0 * A32 + -1.0 * A33) * (-1.0 * B11 + -1.0 * B12 + 0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + 0.125 * B42 + -1.0 * B51 + 1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 35, num_threads)) untied
    {
#endif
    Matrix<Scalar> S35(A11.m(), A11.n());
    S_Add35(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S35, x);
    Matrix<Scalar> T35(B11.m(), B11.n());
    T_Add35(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T35, x);
    FastMatmulRecursive(S35, T35, M35, total_steps, steps_left - 1, (start_index + 35 - 1) * 40, x, num_threads, Scalar(0.0));
    S35.deallocate();
    T35.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 35, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M36 = (-0.125 * A11 + -1.0 * A12 + 1.0 * A13 + -1.0 * A14 + -0.125 * A15 + -1.0 * A16 + 0.125 * A21 + -0.125 * A25 + -1.0 * A32 + 1.0 * A33) * (-1.0 * B11 + -1.0 * B12 + -0.125 * B22 + -0.125 * B23 + 0.125 * B32 + -0.125 * B33 + -0.125 * B42 + -1.0 * B51 + -1.0 * B52 + -0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 36, num_threads)) untied
    {
#endif
    Matrix<Scalar> S36(A11.m(), A11.n());
    S_Add36(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S36, x);
    Matrix<Scalar> T36(B11.m(), B11.n());
    T_Add36(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T36, x);
    FastMatmulRecursive(S36, T36, M36, total_steps, steps_left - 1, (start_index + 36 - 1) * 40, x, num_threads, Scalar(0.0));
    S36.deallocate();
    T36.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 36, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M37 = (0.125 * A11 + 0.125 * A15 + 0.125 * A21 + -1.0 * A22 + 1.0 * A23 + 1.0 * A24 + -0.125 * A25 + 1.0 * A26 + -1.0 * A34 + -1.0 * A36) * (-1.0 * B11 + 1.0 * B12 + 0.125 * B21 + -0.125 * B31 + -0.125 * B41 + -0.125 * B43 + 1.0 * B51 + -1.0 * B52 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 37, num_threads)) untied
    {
#endif
    Matrix<Scalar> S37(A11.m(), A11.n());
    S_Add37(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S37, x);
    Matrix<Scalar> T37(B11.m(), B11.n());
    T_Add37(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T37, x);
    FastMatmulRecursive(S37, T37, M37, total_steps, steps_left - 1, (start_index + 37 - 1) * 40, x, num_threads, Scalar(0.0));
    S37.deallocate();
    T37.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 37, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M38 = (0.125 * A11 + 0.125 * A15 + -0.125 * A21 + 1.0 * A22 + -1.0 * A23 + 1.0 * A24 + 0.125 * A25 + 1.0 * A26 + -1.0 * A34 + -1.0 * A36) * (1.0 * B11 + 1.0 * B12 + -0.125 * B21 + 0.125 * B31 + -0.125 * B41 + -0.125 * B43 + -1.0 * B51 + -1.0 * B52 + -0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 38, num_threads)) untied
    {
#endif
    Matrix<Scalar> S38(A11.m(), A11.n());
    S_Add38(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S38, x);
    Matrix<Scalar> T38(B11.m(), B11.n());
    T_Add38(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T38, x);
    FastMatmulRecursive(S38, T38, M38, total_steps, steps_left - 1, (start_index + 38 - 1) * 40, x, num_threads, Scalar(0.0));
    S38.deallocate();
    T38.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 38, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M39 = (0.125 * A11 + -1.0 * A12 + -1.0 * A13 + 1.0 * A14 + -0.125 * A15 + -1.0 * A16 + -0.125 * A21 + 0.125 * A25 + 1.0 * A32 + -1.0 * A33) * (1.0 * B11 + -1.0 * B12 + 0.125 * B22 + 0.125 * B23 + 0.125 * B32 + 0.125 * B33 + -0.125 * B42 + 1.0 * B51 + 1.0 * B52 + 0.125 * B62)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 39, num_threads)) untied
    {
#endif
    Matrix<Scalar> S39(A11.m(), A11.n());
    S_Add39(A11, A12, A13, A14, A15, A16, A21, A25, A32, A33, S39, x);
    Matrix<Scalar> T39(B11.m(), B11.n());
    T_Add39(B11, B12, B22, B23, B32, B33, B42, B51, B52, B62, T39, x);
    FastMatmulRecursive(S39, T39, M39, total_steps, steps_left - 1, (start_index + 39 - 1) * 40, x, num_threads, Scalar(0.0));
    S39.deallocate();
    T39.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 39, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
# endif
    }
#endif

    // M40 = (0.125 * A11 + 0.125 * A15 + -0.125 * A21 + 1.0 * A22 + 1.0 * A23 + -1.0 * A24 + -0.125 * A25 + 1.0 * A26 + -1.0 * A34 + -1.0 * A36) * (-1.0 * B11 + 1.0 * B12 + 0.125 * B21 + 0.125 * B31 + -0.125 * B41 + -0.125 * B43 + -1.0 * B51 + -1.0 * B52 + 0.125 * B61 + 0.125 * B63)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(should_launch_task(40, total_steps, steps_left, start_index, 40, num_threads)) untied
    {
#endif
    Matrix<Scalar> S40(A11.m(), A11.n());
    S_Add40(A11, A15, A21, A22, A23, A24, A25, A26, A34, A36, S40, x);
    Matrix<Scalar> T40(B11.m(), B11.n());
    T_Add40(B11, B12, B21, B31, B41, B43, B51, B52, B61, B63, T40, x);
    FastMatmulRecursive(S40, T40, M40, total_steps, steps_left - 1, (start_index + 40 - 1) * 40, x, num_threads, Scalar(0.0));
    S40.deallocate();
    T40.deallocate();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ ||  _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 40, num_threads)) {
# pragma omp taskwait
    }
#endif

    M_Add1(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M18, M21, M22, M25, M27, M28, M29, M32, M33, M34, M36, M40, C11, x, beta);
    M_Add2(M18, M20, M25, M26, M33, M35, M36, M39, C12, x, beta);
    M_Add3(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M20, M21, M22, M26, M27, M28, M29, M32, M34, M35, M39, M40, C13, x, beta);
    M_Add4(M17, M19, M21, M22, M34, M37, M38, M40, C21, x, beta);
    M_Add5(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M17, M19, M20, M23, M24, M26, M30, M31, M35, M37, M38, M39, C22, x, beta);
    M_Add6(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M20, M21, M22, M23, M24, M26, M30, M31, M34, M35, M39, M40, C23, x, beta);
    M_Add7(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M17, M18, M19, M25, M27, M28, M29, M32, M33, M36, M37, M38, C31, x, beta);
    M_Add8(M1, M2, M3, M4, M5, M6, M7, M8, M9, M10, M11, M12, M13, M14, M15, M16, M17, M18, M19, M23, M24, M25, M30, M31, M33, M36, M37, M38, C32, x, beta);
    M_Add9(M23, M24, M27, M28, M29, M30, M31, M32, C33, x, beta);

    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 6, 3, beta);
}

// C := alpha * A * B + beta * C
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
    int num_steps, double x=1e-8, Scalar alpha=Scalar(1.0), Scalar beta=Scalar(0.0)) {
    A.set_multiplier(alpha);
    int num_multiplies_per_step = 40;
    int total_multiplies = pow(num_multiplies_per_step, num_steps);
#ifdef _PARALLEL_
    int num_threads = -1;
# pragma omp parallel
    {
        if (omp_get_thread_num() == 0) { num_threads = omp_get_num_threads(); }
    }
#else
    int num_threads = 0;
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    omp_set_nested(1);
    if (num_threads > total_multiplies) {
        mkl_set_dynamic(0);
    }
# pragma omp parallel
    {
# pragma omp single
#endif
        FastMatmulRecursive(A, B, C, num_steps, num_steps, 0, x, num_threads, beta);
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
#endif
}

}  // namespace smirnov363_40_960

#endif  // _smirnov363_40_960_HPP_
