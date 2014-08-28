#ifndef _smirnov633_40_960_HPP_
#define _smirnov633_40_960_HPP_

// This is an automatically generated file from gen.py.
#include "common.hpp"

namespace smirnov633_40_960 {

template <typename Scalar>
void S_Add1(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add2(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add3(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add4(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add5(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add6(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + Scalar(-0.125) * dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add7(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add8(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add9(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add10(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + Scalar(-0.125) * dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add11(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + Scalar(0.125) * dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add12(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add13(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add14(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add15(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + Scalar(0.125) * dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] -dataS8[i + j * strideS8] -dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add16(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + dataS8[i + j * strideS8] + dataS9[i + j * strideS9];
        }
    }
}

template <typename Scalar>
void S_Add17(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add18(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add19(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add20(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add21(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add22(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + Scalar(-0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add23(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add24(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add25(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add26(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] -dataS5[i + j * strideS5] + dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add27(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add28(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add29(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] + dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add30(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add31(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add32(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add33(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add34(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] -dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add35(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add36(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] + dataS6[i + j * strideS6] -dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(-0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add37(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add38(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add39(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + Scalar(0.125) * dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void S_Add40(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& S7, Matrix<Scalar>& S8, Matrix<Scalar>& S9, Matrix<Scalar>& S10, Matrix<Scalar>& C, double x, bool sequential) {
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
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.125) * dataS1[i + j * strideS1] + Scalar(-0.125) * dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] -dataS5[i + j * strideS5] -dataS6[i + j * strideS6] + Scalar(0.125) * dataS7[i + j * strideS7] + Scalar(-0.125) * dataS8[i + j * strideS8] + dataS9[i + j * strideS9] -dataS10[i + j * strideS10];
        }
    }
}

template <typename Scalar>
void T_Add1(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add2(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add3(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add4(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add5(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] -dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add6(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add7(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add8(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add9(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] + dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add10(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] + dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add11(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add12(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] + dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add13(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add14(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add15(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add16(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideT6 = T6.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    const Scalar *dataT6 = T6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] + dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add17(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add18(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add19(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add20(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add21(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add22(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add23(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add24(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add25(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add26(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add27(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add28(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add29(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add30(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add31(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add32(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add33(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add34(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add35(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add36(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add37(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add38(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add39(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add40(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void M_Add1(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] + dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] + dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add2(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] + dataM22[i + j * strideM22] -dataM23[i + j * strideM23] + dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] + dataM22[i + j * strideM22] -dataM23[i + j * strideM23] + dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add3(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add4(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add5(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(-0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(-0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add6(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add7(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add8(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add9(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add10(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(-0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(-0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(-0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(-0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add11(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(-0.125) * dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add12(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(-0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(-0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(-0.125) * dataM12[i + j * strideM12] + Scalar(-0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(-0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add13(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + dataM14[i + j * strideM14] + dataM15[i + j * strideM15] -dataM16[i + j * strideM16] -dataM17[i + j * strideM17] + dataM18[i + j * strideM18] -dataM19[i + j * strideM19] -dataM20[i + j * strideM20] + dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add14(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14] -dataM15[i + j * strideM15] -dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14] -dataM15[i + j * strideM15] -dataM16[i + j * strideM16] + dataM17[i + j * strideM17] -dataM18[i + j * strideM18] + dataM19[i + j * strideM19] -dataM20[i + j * strideM20] -dataM21[i + j * strideM21] -dataM22[i + j * strideM22] + dataM23[i + j * strideM23] -dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add15(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] + dataM14[i + j * strideM14] -dataM15[i + j * strideM15] + dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add16(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(-0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(-0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(0.125) * dataM7[i + j * strideM7] + Scalar(-0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(0.125) * dataM17[i + j * strideM17] + Scalar(0.125) * dataM18[i + j * strideM18] + Scalar(0.125) * dataM19[i + j * strideM19] + Scalar(0.125) * dataM20[i + j * strideM20] + Scalar(-0.125) * dataM21[i + j * strideM21] + Scalar(-0.125) * dataM22[i + j * strideM22] + Scalar(-0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void M_Add17(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(-0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(-0.125) * dataM4[i + j * strideM4] + Scalar(-0.125) * dataM5[i + j * strideM5] + Scalar(-0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(0.125) * dataM9[i + j * strideM9] + Scalar(-0.125) * dataM10[i + j * strideM10] + Scalar(0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(-0.125) * dataM14[i + j * strideM14] + Scalar(-0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add18(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& M15, Matrix<Scalar>& M16, Matrix<Scalar>& M17, Matrix<Scalar>& M18, Matrix<Scalar>& M19, Matrix<Scalar>& M20, Matrix<Scalar>& M21, Matrix<Scalar>& M22, Matrix<Scalar>& M23, Matrix<Scalar>& M24, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = Scalar(0.125) * dataM1[i + j * strideM1] + Scalar(-0.125) * dataM2[i + j * strideM2] + Scalar(0.125) * dataM3[i + j * strideM3] + Scalar(0.125) * dataM4[i + j * strideM4] + Scalar(0.125) * dataM5[i + j * strideM5] + Scalar(0.125) * dataM6[i + j * strideM6] + Scalar(-0.125) * dataM7[i + j * strideM7] + Scalar(0.125) * dataM8[i + j * strideM8] + Scalar(-0.125) * dataM9[i + j * strideM9] + Scalar(0.125) * dataM10[i + j * strideM10] + Scalar(-0.125) * dataM11[i + j * strideM11] + Scalar(0.125) * dataM12[i + j * strideM12] + Scalar(0.125) * dataM13[i + j * strideM13] + Scalar(0.125) * dataM14[i + j * strideM14] + Scalar(0.125) * dataM15[i + j * strideM15] + Scalar(0.125) * dataM16[i + j * strideM16] + Scalar(-0.125) * dataM17[i + j * strideM17] + Scalar(-0.125) * dataM18[i + j * strideM18] + Scalar(-0.125) * dataM19[i + j * strideM19] + Scalar(-0.125) * dataM20[i + j * strideM20] + Scalar(0.125) * dataM21[i + j * strideM21] + Scalar(0.125) * dataM22[i + j * strideM22] + Scalar(0.125) * dataM23[i + j * strideM23] + Scalar(0.125) * dataM24[i + j * strideM24];
            }
        }
    }
}

template <typename Scalar>
void FastMatmulRecursive(MemoryManager<Scalar>& mem_mngr, Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int total_steps, int steps_left, int start_index, double x, int num_threads, Scalar beta) {
    // Update multipliers
    C.UpdateMultiplier(A.multiplier());
    C.UpdateMultiplier(B.multiplier());
    A.set_multiplier(Scalar(1.0));
    B.set_multiplier(Scalar(1.0));
    // Base case for recursion
    if (steps_left == 0) {
        MatMul(A, B, C);
        return;
    }

    Matrix<Scalar> A11 = A.Subblock(6, 3, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(6, 3, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(6, 3, 1, 3);
    Matrix<Scalar> A21 = A.Subblock(6, 3, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(6, 3, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(6, 3, 2, 3);
    Matrix<Scalar> A31 = A.Subblock(6, 3, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(6, 3, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(6, 3, 3, 3);
    Matrix<Scalar> A41 = A.Subblock(6, 3, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(6, 3, 4, 2);
    Matrix<Scalar> A43 = A.Subblock(6, 3, 4, 3);
    Matrix<Scalar> A51 = A.Subblock(6, 3, 5, 1);
    Matrix<Scalar> A52 = A.Subblock(6, 3, 5, 2);
    Matrix<Scalar> A53 = A.Subblock(6, 3, 5, 3);
    Matrix<Scalar> A61 = A.Subblock(6, 3, 6, 1);
    Matrix<Scalar> A62 = A.Subblock(6, 3, 6, 2);
    Matrix<Scalar> A63 = A.Subblock(6, 3, 6, 3);
    Matrix<Scalar> B11 = B.Subblock(3, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(3, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(3, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(3, 3, 2, 3);
    Matrix<Scalar> B31 = B.Subblock(3, 3, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 3, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(3, 3, 3, 3);
    Matrix<Scalar> C11 = C.Subblock(6, 3, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(6, 3, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(6, 3, 1, 3);
    Matrix<Scalar> C21 = C.Subblock(6, 3, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(6, 3, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(6, 3, 2, 3);
    Matrix<Scalar> C31 = C.Subblock(6, 3, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(6, 3, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(6, 3, 3, 3);
    Matrix<Scalar> C41 = C.Subblock(6, 3, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(6, 3, 4, 2);
    Matrix<Scalar> C43 = C.Subblock(6, 3, 4, 3);
    Matrix<Scalar> C51 = C.Subblock(6, 3, 5, 1);
    Matrix<Scalar> C52 = C.Subblock(6, 3, 5, 2);
    Matrix<Scalar> C53 = C.Subblock(6, 3, 5, 3);
    Matrix<Scalar> C61 = C.Subblock(6, 3, 6, 1);
    Matrix<Scalar> C62 = C.Subblock(6, 3, 6, 2);
    Matrix<Scalar> C63 = C.Subblock(6, 3, 6, 3);


    // Matrices to store the results of multiplications.
    Matrix<Scalar> M1(mem_mngr.GetMem(start_index, 1, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M2(mem_mngr.GetMem(start_index, 2, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M3(mem_mngr.GetMem(start_index, 3, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M7(mem_mngr.GetMem(start_index, 7, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M9(mem_mngr.GetMem(start_index, 9, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M12(mem_mngr.GetMem(start_index, 12, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M16(mem_mngr.GetMem(start_index, 16, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M17(mem_mngr.GetMem(start_index, 17, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M18(mem_mngr.GetMem(start_index, 18, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M19(mem_mngr.GetMem(start_index, 19, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M20(mem_mngr.GetMem(start_index, 20, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M21(mem_mngr.GetMem(start_index, 21, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M22(mem_mngr.GetMem(start_index, 22, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M23(mem_mngr.GetMem(start_index, 23, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M24(mem_mngr.GetMem(start_index, 24, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M25(mem_mngr.GetMem(start_index, 25, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M26(mem_mngr.GetMem(start_index, 26, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M27(mem_mngr.GetMem(start_index, 27, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M28(mem_mngr.GetMem(start_index, 28, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M29(mem_mngr.GetMem(start_index, 29, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M30(mem_mngr.GetMem(start_index, 30, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M31(mem_mngr.GetMem(start_index, 31, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M32(mem_mngr.GetMem(start_index, 32, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M33(mem_mngr.GetMem(start_index, 33, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M34(mem_mngr.GetMem(start_index, 34, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M35(mem_mngr.GetMem(start_index, 35, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M36(mem_mngr.GetMem(start_index, 36, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M37(mem_mngr.GetMem(start_index, 37, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M38(mem_mngr.GetMem(start_index, 38, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M39(mem_mngr.GetMem(start_index, 39, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M40(mem_mngr.GetMem(start_index, 40, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    bool sequential1 = should_launch_task(40, total_steps, steps_left, start_index, 1, num_threads);
    bool sequential2 = should_launch_task(40, total_steps, steps_left, start_index, 2, num_threads);
    bool sequential3 = should_launch_task(40, total_steps, steps_left, start_index, 3, num_threads);
    bool sequential4 = should_launch_task(40, total_steps, steps_left, start_index, 4, num_threads);
    bool sequential5 = should_launch_task(40, total_steps, steps_left, start_index, 5, num_threads);
    bool sequential6 = should_launch_task(40, total_steps, steps_left, start_index, 6, num_threads);
    bool sequential7 = should_launch_task(40, total_steps, steps_left, start_index, 7, num_threads);
    bool sequential8 = should_launch_task(40, total_steps, steps_left, start_index, 8, num_threads);
    bool sequential9 = should_launch_task(40, total_steps, steps_left, start_index, 9, num_threads);
    bool sequential10 = should_launch_task(40, total_steps, steps_left, start_index, 10, num_threads);
    bool sequential11 = should_launch_task(40, total_steps, steps_left, start_index, 11, num_threads);
    bool sequential12 = should_launch_task(40, total_steps, steps_left, start_index, 12, num_threads);
    bool sequential13 = should_launch_task(40, total_steps, steps_left, start_index, 13, num_threads);
    bool sequential14 = should_launch_task(40, total_steps, steps_left, start_index, 14, num_threads);
    bool sequential15 = should_launch_task(40, total_steps, steps_left, start_index, 15, num_threads);
    bool sequential16 = should_launch_task(40, total_steps, steps_left, start_index, 16, num_threads);
    bool sequential17 = should_launch_task(40, total_steps, steps_left, start_index, 17, num_threads);
    bool sequential18 = should_launch_task(40, total_steps, steps_left, start_index, 18, num_threads);
    bool sequential19 = should_launch_task(40, total_steps, steps_left, start_index, 19, num_threads);
    bool sequential20 = should_launch_task(40, total_steps, steps_left, start_index, 20, num_threads);
    bool sequential21 = should_launch_task(40, total_steps, steps_left, start_index, 21, num_threads);
    bool sequential22 = should_launch_task(40, total_steps, steps_left, start_index, 22, num_threads);
    bool sequential23 = should_launch_task(40, total_steps, steps_left, start_index, 23, num_threads);
    bool sequential24 = should_launch_task(40, total_steps, steps_left, start_index, 24, num_threads);
    bool sequential25 = should_launch_task(40, total_steps, steps_left, start_index, 25, num_threads);
    bool sequential26 = should_launch_task(40, total_steps, steps_left, start_index, 26, num_threads);
    bool sequential27 = should_launch_task(40, total_steps, steps_left, start_index, 27, num_threads);
    bool sequential28 = should_launch_task(40, total_steps, steps_left, start_index, 28, num_threads);
    bool sequential29 = should_launch_task(40, total_steps, steps_left, start_index, 29, num_threads);
    bool sequential30 = should_launch_task(40, total_steps, steps_left, start_index, 30, num_threads);
    bool sequential31 = should_launch_task(40, total_steps, steps_left, start_index, 31, num_threads);
    bool sequential32 = should_launch_task(40, total_steps, steps_left, start_index, 32, num_threads);
    bool sequential33 = should_launch_task(40, total_steps, steps_left, start_index, 33, num_threads);
    bool sequential34 = should_launch_task(40, total_steps, steps_left, start_index, 34, num_threads);
    bool sequential35 = should_launch_task(40, total_steps, steps_left, start_index, 35, num_threads);
    bool sequential36 = should_launch_task(40, total_steps, steps_left, start_index, 36, num_threads);
    bool sequential37 = should_launch_task(40, total_steps, steps_left, start_index, 37, num_threads);
    bool sequential38 = should_launch_task(40, total_steps, steps_left, start_index, 38, num_threads);
    bool sequential39 = should_launch_task(40, total_steps, steps_left, start_index, 39, num_threads);
    bool sequential40 = should_launch_task(40, total_steps, steps_left, start_index, 40, num_threads);
#else
    bool sequential1 = false;
    bool sequential2 = false;
    bool sequential3 = false;
    bool sequential4 = false;
    bool sequential5 = false;
    bool sequential6 = false;
    bool sequential7 = false;
    bool sequential8 = false;
    bool sequential9 = false;
    bool sequential10 = false;
    bool sequential11 = false;
    bool sequential12 = false;
    bool sequential13 = false;
    bool sequential14 = false;
    bool sequential15 = false;
    bool sequential16 = false;
    bool sequential17 = false;
    bool sequential18 = false;
    bool sequential19 = false;
    bool sequential20 = false;
    bool sequential21 = false;
    bool sequential22 = false;
    bool sequential23 = false;
    bool sequential24 = false;
    bool sequential25 = false;
    bool sequential26 = false;
    bool sequential27 = false;
    bool sequential28 = false;
    bool sequential29 = false;
    bool sequential30 = false;
    bool sequential31 = false;
    bool sequential32 = false;
    bool sequential33 = false;
    bool sequential34 = false;
    bool sequential35 = false;
    bool sequential36 = false;
    bool sequential37 = false;
    bool sequential38 = false;
    bool sequential39 = false;
    bool sequential40 = false;
#endif



    // M1 = (-0.125 * A11 + -0.125 * A12 + -1.0 * A21 + 1.0 * A23 + 1.0 * A32 + 1.0 * A42 + 1.0 * A43 + -0.125 * A53 + 1.0 * A61) * (1.0 * B11 + 1.0 * B13 + 1.0 * B22 + 1.0 * B23 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential1) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S1(mem_mngr.GetMem(start_index, 1, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add1(A11, A12, A21, A23, A32, A42, A43, A53, A61, S1, x, sequential1);
    Matrix<Scalar> T1(mem_mngr.GetMem(start_index, 1, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add1(B11, B13, B22, B23, B31, B32, T1, x, sequential1);
    FastMatmulRecursive(mem_mngr, S1, T1, M1, total_steps, steps_left - 1, (start_index + 1 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 1, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M2 = (0.125 * A11 + 0.125 * A12 + 1.0 * A22 + -1.0 * A31 + 1.0 * A33 + -1.0 * A41 + 0.125 * A53 + -1.0 * A62 + -1.0 * A63) * (1.0 * B11 + -1.0 * B13 + 1.0 * B22 + -1.0 * B23 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential2) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S2(mem_mngr.GetMem(start_index, 2, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add2(A11, A12, A22, A31, A33, A41, A53, A62, A63, S2, x, sequential2);
    Matrix<Scalar> T2(mem_mngr.GetMem(start_index, 2, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add2(B11, B13, B22, B23, B31, B32, T2, x, sequential2);
    FastMatmulRecursive(mem_mngr, S2, T2, M2, total_steps, steps_left - 1, (start_index + 2 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 2, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M3 = (-0.125 * A13 + 1.0 * A22 + -1.0 * A31 + 1.0 * A33 + 1.0 * A42 + 1.0 * A43 + -0.125 * A51 + -0.125 * A52 + 1.0 * A61) * (-1.0 * B11 + -1.0 * B13 + 1.0 * B22 + -1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential3) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S3(mem_mngr.GetMem(start_index, 3, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add3(A13, A22, A31, A33, A42, A43, A51, A52, A61, S3, x, sequential3);
    Matrix<Scalar> T3(mem_mngr.GetMem(start_index, 3, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add3(B11, B13, B22, B23, B31, B32, T3, x, sequential3);
    FastMatmulRecursive(mem_mngr, S3, T3, M3, total_steps, steps_left - 1, (start_index + 3 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 3, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M4 = (-0.125 * A11 + 0.125 * A12 + 1.0 * A21 + -1.0 * A23 + 1.0 * A32 + -1.0 * A42 + 1.0 * A43 + -0.125 * A53 + 1.0 * A61) * (-1.0 * B11 + 1.0 * B13 + -1.0 * B22 + -1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential4) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add4(A11, A12, A21, A23, A32, A42, A43, A53, A61, S4, x, sequential4);
    Matrix<Scalar> T4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add4(B11, B13, B22, B23, B31, B32, T4, x, sequential4);
    FastMatmulRecursive(mem_mngr, S4, T4, M4, total_steps, steps_left - 1, (start_index + 4 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 4, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M5 = (-0.125 * A11 + 0.125 * A12 + -1.0 * A22 + -1.0 * A31 + 1.0 * A33 + 1.0 * A41 + -0.125 * A53 + -1.0 * A62 + 1.0 * A63) * (1.0 * B11 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential5) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add5(A11, A12, A22, A31, A33, A41, A53, A62, A63, S5, x, sequential5);
    Matrix<Scalar> T5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add5(B11, B13, B22, B23, B31, B32, T5, x, sequential5);
    FastMatmulRecursive(mem_mngr, S5, T5, M5, total_steps, steps_left - 1, (start_index + 5 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 5, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M6 = (0.125 * A13 + 1.0 * A21 + 1.0 * A23 + 1.0 * A32 + -1.0 * A41 + -0.125 * A51 + 0.125 * A52 + 1.0 * A62 + 1.0 * A63) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential6) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add6(A13, A21, A23, A32, A41, A51, A52, A62, A63, S6, x, sequential6);
    Matrix<Scalar> T6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add6(B11, B13, B22, B23, B31, B32, T6, x, sequential6);
    FastMatmulRecursive(mem_mngr, S6, T6, M6, total_steps, steps_left - 1, (start_index + 6 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 6, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M7 = (0.125 * A13 + -1.0 * A22 + -1.0 * A31 + -1.0 * A33 + 1.0 * A42 + 1.0 * A43 + -0.125 * A51 + 0.125 * A52 + -1.0 * A61) * (-1.0 * B11 + -1.0 * B13 + 1.0 * B22 + 1.0 * B23 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential7) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S7(mem_mngr.GetMem(start_index, 7, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add7(A13, A22, A31, A33, A42, A43, A51, A52, A61, S7, x, sequential7);
    Matrix<Scalar> T7(mem_mngr.GetMem(start_index, 7, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add7(B11, B13, B22, B23, B31, B32, T7, x, sequential7);
    FastMatmulRecursive(mem_mngr, S7, T7, M7, total_steps, steps_left - 1, (start_index + 7 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 7, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M8 = (0.125 * A11 + -0.125 * A12 + 1.0 * A21 + 1.0 * A23 + 1.0 * A32 + -1.0 * A42 + -1.0 * A43 + -0.125 * A53 + 1.0 * A61) * (1.0 * B11 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential8) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add8(A11, A12, A21, A23, A32, A42, A43, A53, A61, S8, x, sequential8);
    Matrix<Scalar> T8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add8(B11, B13, B22, B23, B31, B32, T8, x, sequential8);
    FastMatmulRecursive(mem_mngr, S8, T8, M8, total_steps, steps_left - 1, (start_index + 8 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 8, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M9 = (-0.125 * A13 + 1.0 * A22 + 1.0 * A31 + -1.0 * A33 + -1.0 * A42 + 1.0 * A43 + -0.125 * A51 + 0.125 * A52 + 1.0 * A61) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential9) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S9(mem_mngr.GetMem(start_index, 9, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add9(A13, A22, A31, A33, A42, A43, A51, A52, A61, S9, x, sequential9);
    Matrix<Scalar> T9(mem_mngr.GetMem(start_index, 9, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add9(B11, B13, B22, B23, B31, B32, T9, x, sequential9);
    FastMatmulRecursive(mem_mngr, S9, T9, M9, total_steps, steps_left - 1, (start_index + 9 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 9, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M10 = (-0.125 * A13 + -1.0 * A21 + 1.0 * A23 + -1.0 * A32 + 1.0 * A41 + -0.125 * A51 + 0.125 * A52 + -1.0 * A62 + 1.0 * A63) * (-1.0 * B11 + -1.0 * B13 + 1.0 * B22 + 1.0 * B23 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential10) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add10(A13, A21, A23, A32, A41, A51, A52, A62, A63, S10, x, sequential10);
    Matrix<Scalar> T10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add10(B11, B13, B22, B23, B31, B32, T10, x, sequential10);
    FastMatmulRecursive(mem_mngr, S10, T10, M10, total_steps, steps_left - 1, (start_index + 10 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 10, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M11 = (-0.125 * A13 + 1.0 * A21 + 1.0 * A23 + -1.0 * A32 + 1.0 * A41 + 0.125 * A51 + 0.125 * A52 + 1.0 * A62 + -1.0 * A63) * (1.0 * B11 + 1.0 * B13 + -1.0 * B22 + 1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential11) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add11(A13, A21, A23, A32, A41, A51, A52, A62, A63, S11, x, sequential11);
    Matrix<Scalar> T11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add11(B11, B13, B22, B23, B31, B32, T11, x, sequential11);
    FastMatmulRecursive(mem_mngr, S11, T11, M11, total_steps, steps_left - 1, (start_index + 11 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 11, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M12 = (-0.125 * A11 + -0.125 * A12 + 1.0 * A22 + -1.0 * A31 + -1.0 * A33 + -1.0 * A41 + 0.125 * A53 + -1.0 * A62 + 1.0 * A63) * (1.0 * B11 + 1.0 * B13 + 1.0 * B22 + 1.0 * B23 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential12) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S12(mem_mngr.GetMem(start_index, 12, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add12(A11, A12, A22, A31, A33, A41, A53, A62, A63, S12, x, sequential12);
    Matrix<Scalar> T12(mem_mngr.GetMem(start_index, 12, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add12(B11, B13, B22, B23, B31, B32, T12, x, sequential12);
    FastMatmulRecursive(mem_mngr, S12, T12, M12, total_steps, steps_left - 1, (start_index + 12 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 12, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M13 = (-0.125 * A11 + -0.125 * A12 + 1.0 * A21 + 1.0 * A23 + -1.0 * A32 + -1.0 * A42 + 1.0 * A43 + 0.125 * A53 + -1.0 * A61) * (-1.0 * B11 + 1.0 * B13 + -1.0 * B22 + 1.0 * B23 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential13) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add13(A11, A12, A21, A23, A32, A42, A43, A53, A61, S13, x, sequential13);
    Matrix<Scalar> T13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add13(B11, B13, B22, B23, B31, B32, T13, x, sequential13);
    FastMatmulRecursive(mem_mngr, S13, T13, M13, total_steps, steps_left - 1, (start_index + 13 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 13, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M14 = (-0.125 * A13 + 1.0 * A22 + -1.0 * A31 + -1.0 * A33 + 1.0 * A42 + -1.0 * A43 + 0.125 * A51 + 0.125 * A52 + 1.0 * A61) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B22 + 1.0 * B23 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential14) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add14(A13, A22, A31, A33, A42, A43, A51, A52, A61, S14, x, sequential14);
    Matrix<Scalar> T14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add14(B11, B13, B22, B23, B31, B32, T14, x, sequential14);
    FastMatmulRecursive(mem_mngr, S14, T14, M14, total_steps, steps_left - 1, (start_index + 14 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 14, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M15 = (0.125 * A13 + -1.0 * A21 + 1.0 * A23 + 1.0 * A32 + -1.0 * A41 + 0.125 * A51 + 0.125 * A52 + -1.0 * A62 + -1.0 * A63) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B22 + 1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential15) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add15(A13, A21, A23, A32, A41, A51, A52, A62, A63, S15, x, sequential15);
    Matrix<Scalar> T15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add15(B11, B13, B22, B23, B31, B32, T15, x, sequential15);
    FastMatmulRecursive(mem_mngr, S15, T15, M15, total_steps, steps_left - 1, (start_index + 15 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 15, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M16 = (-0.125 * A11 + 0.125 * A12 + 1.0 * A22 + 1.0 * A31 + 1.0 * A33 + -1.0 * A41 + 0.125 * A53 + 1.0 * A62 + 1.0 * A63) * (1.0 * B11 + -1.0 * B13 + 1.0 * B22 + 1.0 * B23 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential16) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S16(mem_mngr.GetMem(start_index, 16, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add16(A11, A12, A22, A31, A33, A41, A53, A62, A63, S16, x, sequential16);
    Matrix<Scalar> T16(mem_mngr.GetMem(start_index, 16, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add16(B11, B13, B22, B23, B31, B32, T16, x, sequential16);
    FastMatmulRecursive(mem_mngr, S16, T16, M16, total_steps, steps_left - 1, (start_index + 16 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 16, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M17 = (-0.125 * A11 + 0.125 * A12 + 1.0 * A22 + -1.0 * A32 + 1.0 * A42 + 1.0 * A43 + -0.125 * A51 + -0.125 * A52 + 1.0 * A62 + 1.0 * A63) * (-1.0 * B21 + -1.0 * B22 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential17) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S17(mem_mngr.GetMem(start_index, 17, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add17(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S17, x, sequential17);
    Matrix<Scalar> T17(mem_mngr.GetMem(start_index, 17, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add17(B21, B22, B31, B32, T17, x, sequential17);
    FastMatmulRecursive(mem_mngr, S17, T17, M17, total_steps, steps_left - 1, (start_index + 17 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 17, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M18 = (-0.125 * A11 + 0.125 * A12 + 1.0 * A21 + -1.0 * A23 + -1.0 * A31 + 1.0 * A33 + 1.0 * A41 + -0.125 * A51 + -0.125 * A52 + 1.0 * A61) * (1.0 * B11 + 1.0 * B12 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential18) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S18(mem_mngr.GetMem(start_index, 18, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add18(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S18, x, sequential18);
    Matrix<Scalar> T18(mem_mngr.GetMem(start_index, 18, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add18(B11, B12, B31, B32, T18, x, sequential18);
    FastMatmulRecursive(mem_mngr, S18, T18, M18, total_steps, steps_left - 1, (start_index + 18 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 18, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M19 = (0.125 * A11 + 0.125 * A12 + 1.0 * A22 + -1.0 * A32 + -1.0 * A42 + -1.0 * A43 + 0.125 * A51 + -0.125 * A52 + -1.0 * A62 + -1.0 * A63) * (-1.0 * B21 + 1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential19) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S19(mem_mngr.GetMem(start_index, 19, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add19(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S19, x, sequential19);
    Matrix<Scalar> T19(mem_mngr.GetMem(start_index, 19, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add19(B21, B22, B31, B32, T19, x, sequential19);
    FastMatmulRecursive(mem_mngr, S19, T19, M19, total_steps, steps_left - 1, (start_index + 19 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 19, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M20 = (0.125 * A11 + 0.125 * A12 + 1.0 * A21 + -1.0 * A23 + 1.0 * A31 + 1.0 * A33 + 1.0 * A41 + -0.125 * A51 + -0.125 * A52 + -1.0 * A61) * (1.0 * B12 + 1.0 * B13 + 1.0 * B22 + 1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential20) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S20(mem_mngr.GetMem(start_index, 20, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add20(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S20, x, sequential20);
    Matrix<Scalar> T20(mem_mngr.GetMem(start_index, 20, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add20(B12, B13, B22, B23, T20, x, sequential20);
    FastMatmulRecursive(mem_mngr, S20, T20, M20, total_steps, steps_left - 1, (start_index + 20 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 20, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M21 = (-0.125 * A11 + 0.125 * A12 + 1.0 * A22 + 1.0 * A32 + -1.0 * A42 + 1.0 * A43 + -0.125 * A51 + 0.125 * A52 + 1.0 * A62 + 1.0 * A63) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B21 + -1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential21) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S21(mem_mngr.GetMem(start_index, 21, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add21(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S21, x, sequential21);
    Matrix<Scalar> T21(mem_mngr.GetMem(start_index, 21, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add21(B11, B13, B21, B23, T21, x, sequential21);
    FastMatmulRecursive(mem_mngr, S21, T21, M21, total_steps, steps_left - 1, (start_index + 21 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 21, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M22 = (-0.125 * A11 + -0.125 * A12 + 1.0 * A22 + 1.0 * A32 + 1.0 * A42 + 1.0 * A43 + -0.125 * A51 + -0.125 * A52 + -1.0 * A62 + 1.0 * A63) * (-1.0 * B11 + -1.0 * B13 + -1.0 * B21 + -1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential22) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S22(mem_mngr.GetMem(start_index, 22, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add22(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S22, x, sequential22);
    Matrix<Scalar> T22(mem_mngr.GetMem(start_index, 22, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add22(B11, B13, B21, B23, T22, x, sequential22);
    FastMatmulRecursive(mem_mngr, S22, T22, M22, total_steps, steps_left - 1, (start_index + 22 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 22, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M23 = (0.125 * A13 + 1.0 * A21 + 1.0 * A23 + 1.0 * A31 + -1.0 * A33 + -1.0 * A42 + -1.0 * A43 + -0.125 * A53 + 1.0 * A62 + 1.0 * A63) * (-1.0 * B22 + 1.0 * B23 + -1.0 * B32 + 1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential23) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S23(mem_mngr.GetMem(start_index, 23, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add23(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S23, x, sequential23);
    Matrix<Scalar> T23(mem_mngr.GetMem(start_index, 23, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add23(B22, B23, B32, B33, T23, x, sequential23);
    FastMatmulRecursive(mem_mngr, S23, T23, M23, total_steps, steps_left - 1, (start_index + 23 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 23, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M24 = (0.125 * A13 + -1.0 * A21 + 1.0 * A23 + -1.0 * A31 + -1.0 * A33 + 1.0 * A42 + 1.0 * A43 + -0.125 * A53 + -1.0 * A62 + -1.0 * A63) * (-1.0 * B22 + -1.0 * B23 + -1.0 * B32 + -1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential24) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S24(mem_mngr.GetMem(start_index, 24, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add24(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S24, x, sequential24);
    Matrix<Scalar> T24(mem_mngr.GetMem(start_index, 24, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add24(B22, B23, B32, B33, T24, x, sequential24);
    FastMatmulRecursive(mem_mngr, S24, T24, M24, total_steps, steps_left - 1, (start_index + 24 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 24, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M25 = (-0.125 * A11 + -0.125 * A12 + -1.0 * A21 + 1.0 * A23 + 1.0 * A31 + -1.0 * A33 + 1.0 * A41 + -0.125 * A51 + 0.125 * A52 + 1.0 * A61) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential25) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S25(mem_mngr.GetMem(start_index, 25, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add25(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S25, x, sequential25);
    Matrix<Scalar> T25(mem_mngr.GetMem(start_index, 25, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add25(B11, B12, B31, B32, T25, x, sequential25);
    FastMatmulRecursive(mem_mngr, S25, T25, M25, total_steps, steps_left - 1, (start_index + 25 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 25, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M26 = (-0.125 * A11 + 0.125 * A12 + -1.0 * A21 + -1.0 * A23 + -1.0 * A31 + 1.0 * A33 + 1.0 * A41 + 0.125 * A51 + -0.125 * A52 + -1.0 * A61) * (-1.0 * B12 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential26) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S26(mem_mngr.GetMem(start_index, 26, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add26(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S26, x, sequential26);
    Matrix<Scalar> T26(mem_mngr.GetMem(start_index, 26, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add26(B12, B13, B22, B23, T26, x, sequential26);
    FastMatmulRecursive(mem_mngr, S26, T26, M26, total_steps, steps_left - 1, (start_index + 26 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 26, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M27 = (0.125 * A13 + 1.0 * A21 + -1.0 * A23 + 1.0 * A31 + -1.0 * A33 + -1.0 * A42 + -1.0 * A43 + 0.125 * A53 + 1.0 * A62 + -1.0 * A63) * (1.0 * B11 + 1.0 * B13 + -1.0 * B31 + -1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential27) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S27(mem_mngr.GetMem(start_index, 27, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add27(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S27, x, sequential27);
    Matrix<Scalar> T27(mem_mngr.GetMem(start_index, 27, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add27(B11, B13, B31, B33, T27, x, sequential27);
    FastMatmulRecursive(mem_mngr, S27, T27, M27, total_steps, steps_left - 1, (start_index + 27 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 27, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M28 = (-0.125 * A13 + 1.0 * A21 + 1.0 * A23 + 1.0 * A31 + 1.0 * A33 + -1.0 * A42 + -1.0 * A43 + -0.125 * A53 + 1.0 * A62 + -1.0 * A63) * (-1.0 * B11 + -1.0 * B13 + -1.0 * B31 + -1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential28) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S28(mem_mngr.GetMem(start_index, 28, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add28(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S28, x, sequential28);
    Matrix<Scalar> T28(mem_mngr.GetMem(start_index, 28, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add28(B11, B13, B31, B33, T28, x, sequential28);
    FastMatmulRecursive(mem_mngr, S28, T28, M28, total_steps, steps_left - 1, (start_index + 28 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 28, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M29 = (0.125 * A13 + 1.0 * A21 + 1.0 * A23 + 1.0 * A31 + 1.0 * A33 + -1.0 * A42 + 1.0 * A43 + 0.125 * A53 + 1.0 * A62 + 1.0 * A63) * (1.0 * B11 + -1.0 * B13 + 1.0 * B31 + -1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential29) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S29(mem_mngr.GetMem(start_index, 29, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add29(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S29, x, sequential29);
    Matrix<Scalar> T29(mem_mngr.GetMem(start_index, 29, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add29(B11, B13, B31, B33, T29, x, sequential29);
    FastMatmulRecursive(mem_mngr, S29, T29, M29, total_steps, steps_left - 1, (start_index + 29 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 29, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M30 = (-0.125 * A13 + 1.0 * A21 + 1.0 * A23 + 1.0 * A31 + -1.0 * A33 + -1.0 * A42 + 1.0 * A43 + 0.125 * A53 + 1.0 * A62 + -1.0 * A63) * (1.0 * B22 + -1.0 * B23 + -1.0 * B32 + 1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential30) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S30(mem_mngr.GetMem(start_index, 30, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add30(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S30, x, sequential30);
    Matrix<Scalar> T30(mem_mngr.GetMem(start_index, 30, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add30(B22, B23, B32, B33, T30, x, sequential30);
    FastMatmulRecursive(mem_mngr, S30, T30, M30, total_steps, steps_left - 1, (start_index + 30 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 30, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M31 = (0.125 * A13 + 1.0 * A21 + -1.0 * A23 + 1.0 * A31 + 1.0 * A33 + -1.0 * A42 + 1.0 * A43 + -0.125 * A53 + 1.0 * A62 + -1.0 * A63) * (-1.0 * B22 + -1.0 * B23 + 1.0 * B32 + 1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential31) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S31(mem_mngr.GetMem(start_index, 31, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add31(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S31, x, sequential31);
    Matrix<Scalar> T31(mem_mngr.GetMem(start_index, 31, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add31(B22, B23, B32, B33, T31, x, sequential31);
    FastMatmulRecursive(mem_mngr, S31, T31, M31, total_steps, steps_left - 1, (start_index + 31 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 31, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M32 = (0.125 * A13 + -1.0 * A21 + 1.0 * A23 + -1.0 * A31 + 1.0 * A33 + 1.0 * A42 + -1.0 * A43 + 0.125 * A53 + -1.0 * A62 + -1.0 * A63) * (1.0 * B11 + -1.0 * B13 + -1.0 * B31 + 1.0 * B33)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential32) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S32(mem_mngr.GetMem(start_index, 32, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add32(A13, A21, A23, A31, A33, A42, A43, A53, A62, A63, S32, x, sequential32);
    Matrix<Scalar> T32(mem_mngr.GetMem(start_index, 32, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add32(B11, B13, B31, B33, T32, x, sequential32);
    FastMatmulRecursive(mem_mngr, S32, T32, M32, total_steps, steps_left - 1, (start_index + 32 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 32, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M33 = (-0.125 * A11 + -0.125 * A12 + 1.0 * A21 + 1.0 * A23 + -1.0 * A31 + -1.0 * A33 + -1.0 * A41 + -0.125 * A51 + 0.125 * A52 + -1.0 * A61) * (1.0 * B11 + -1.0 * B12 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential33) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S33(mem_mngr.GetMem(start_index, 33, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add33(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S33, x, sequential33);
    Matrix<Scalar> T33(mem_mngr.GetMem(start_index, 33, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add33(B11, B12, B31, B32, T33, x, sequential33);
    FastMatmulRecursive(mem_mngr, S33, T33, M33, total_steps, steps_left - 1, (start_index + 33 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 33, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M34 = (0.125 * A11 + 0.125 * A12 + 1.0 * A22 + 1.0 * A32 + 1.0 * A42 + -1.0 * A43 + 0.125 * A51 + 0.125 * A52 + -1.0 * A62 + -1.0 * A63) * (1.0 * B11 + -1.0 * B13 + 1.0 * B21 + -1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential34) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S34(mem_mngr.GetMem(start_index, 34, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add34(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S34, x, sequential34);
    Matrix<Scalar> T34(mem_mngr.GetMem(start_index, 34, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add34(B11, B13, B21, B23, T34, x, sequential34);
    FastMatmulRecursive(mem_mngr, S34, T34, M34, total_steps, steps_left - 1, (start_index + 34 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 34, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M35 = (-0.125 * A11 + -0.125 * A12 + 1.0 * A21 + 1.0 * A23 + 1.0 * A31 + -1.0 * A33 + 1.0 * A41 + 0.125 * A51 + 0.125 * A52 + -1.0 * A61) * (1.0 * B12 + -1.0 * B13 + 1.0 * B22 + -1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential35) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S35(mem_mngr.GetMem(start_index, 35, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add35(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S35, x, sequential35);
    Matrix<Scalar> T35(mem_mngr.GetMem(start_index, 35, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add35(B12, B13, B22, B23, T35, x, sequential35);
    FastMatmulRecursive(mem_mngr, S35, T35, M35, total_steps, steps_left - 1, (start_index + 35 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 35, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M36 = (-0.125 * A11 + 0.125 * A12 + -1.0 * A21 + -1.0 * A23 + 1.0 * A31 + 1.0 * A33 + -1.0 * A41 + -0.125 * A51 + -0.125 * A52 + -1.0 * A61) * (1.0 * B11 + 1.0 * B12 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential36) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S36(mem_mngr.GetMem(start_index, 36, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add36(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S36, x, sequential36);
    Matrix<Scalar> T36(mem_mngr.GetMem(start_index, 36, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add36(B11, B12, B31, B32, T36, x, sequential36);
    FastMatmulRecursive(mem_mngr, S36, T36, M36, total_steps, steps_left - 1, (start_index + 36 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 36, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M37 = (0.125 * A11 + 0.125 * A12 + -1.0 * A22 + 1.0 * A32 + 1.0 * A42 + -1.0 * A43 + 0.125 * A51 + -0.125 * A52 + 1.0 * A62 + -1.0 * A63) * (-1.0 * B21 + 1.0 * B22 + 1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential37) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S37(mem_mngr.GetMem(start_index, 37, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add37(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S37, x, sequential37);
    Matrix<Scalar> T37(mem_mngr.GetMem(start_index, 37, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add37(B21, B22, B31, B32, T37, x, sequential37);
    FastMatmulRecursive(mem_mngr, S37, T37, M37, total_steps, steps_left - 1, (start_index + 37 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 37, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M38 = (0.125 * A11 + -0.125 * A12 + 1.0 * A22 + -1.0 * A32 + 1.0 * A42 + -1.0 * A43 + 0.125 * A51 + 0.125 * A52 + 1.0 * A62 + -1.0 * A63) * (-1.0 * B21 + -1.0 * B22 + 1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential38) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S38(mem_mngr.GetMem(start_index, 38, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add38(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S38, x, sequential38);
    Matrix<Scalar> T38(mem_mngr.GetMem(start_index, 38, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add38(B21, B22, B31, B32, T38, x, sequential38);
    FastMatmulRecursive(mem_mngr, S38, T38, M38, total_steps, steps_left - 1, (start_index + 38 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 38, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M39 = (0.125 * A11 + -0.125 * A12 + -1.0 * A21 + 1.0 * A23 + -1.0 * A31 + -1.0 * A33 + 1.0 * A41 + -0.125 * A51 + 0.125 * A52 + -1.0 * A61) * (-1.0 * B12 + -1.0 * B13 + 1.0 * B22 + 1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential39) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S39(mem_mngr.GetMem(start_index, 39, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add39(A11, A12, A21, A23, A31, A33, A41, A51, A52, A61, S39, x, sequential39);
    Matrix<Scalar> T39(mem_mngr.GetMem(start_index, 39, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add39(B12, B13, B22, B23, T39, x, sequential39);
    FastMatmulRecursive(mem_mngr, S39, T39, M39, total_steps, steps_left - 1, (start_index + 39 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 39, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_domain_set_num_threads(num_threads, MKL_BLAS);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M40 = (0.125 * A11 + -0.125 * A12 + 1.0 * A22 + 1.0 * A32 + -1.0 * A42 + -1.0 * A43 + 0.125 * A51 + -0.125 * A52 + 1.0 * A62 + -1.0 * A63) * (-1.0 * B11 + -1.0 * B13 + 1.0 * B21 + 1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential40) shared(mem_mngr)
    {
#endif
    Matrix<Scalar> S40(mem_mngr.GetMem(start_index, 40, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add40(A11, A12, A22, A32, A42, A43, A51, A52, A62, A63, S40, x, sequential40);
    Matrix<Scalar> T40(mem_mngr.GetMem(start_index, 40, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add40(B11, B13, B21, B23, T40, x, sequential40);
    FastMatmulRecursive(mem_mngr, S40, T40, M40, total_steps, steps_left - 1, (start_index + 40 - 1) * 40, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(40, total_steps, steps_left, start_index, 40, num_threads)) {
# pragma omp taskwait
    }
#endif

    M_Add1(M3, M6, M7, M9, M10, M11, M14, M15, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, C11, x, false, beta);
    M_Add2(M3, M6, M7, M9, M10, M11, M14, M15, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, C12, x, false, beta);
    M_Add3(M1, M2, M4, M5, M8, M12, M13, M16, M23, M24, M27, M28, M29, M30, M31, M32, C13, x, false, beta);
    M_Add4(M1, M4, M6, M8, M10, M11, M13, M15, M17, M19, M21, M22, M34, M37, M38, M40, C21, x, false, beta);
    M_Add5(M2, M3, M5, M7, M9, M12, M14, M16, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, C22, x, false, beta);
    M_Add6(M2, M3, M5, M7, M9, M12, M14, M16, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, C23, x, false, beta);
    M_Add7(M2, M3, M5, M7, M9, M12, M14, M16, M17, M19, M21, M22, M34, M37, M38, M40, C31, x, false, beta);
    M_Add8(M1, M4, M6, M8, M10, M11, M13, M15, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, C32, x, false, beta);
    M_Add9(M1, M4, M6, M8, M10, M11, M13, M15, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, C33, x, false, beta);
    M_Add10(M2, M5, M6, M10, M11, M12, M15, M16, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, C41, x, false, beta);
    M_Add11(M1, M3, M4, M7, M8, M9, M13, M14, M18, M20, M25, M26, M33, M35, M36, M39, C42, x, false, beta);
    M_Add12(M2, M5, M6, M10, M11, M12, M15, M16, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, C43, x, false, beta);
    M_Add13(M1, M2, M4, M5, M8, M12, M13, M16, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, C51, x, false, beta);
    M_Add14(M1, M2, M4, M5, M8, M12, M13, M16, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, C52, x, false, beta);
    M_Add15(M3, M6, M7, M9, M10, M11, M14, M15, M23, M24, M27, M28, M29, M30, M31, M32, C53, x, false, beta);
    M_Add16(M1, M3, M4, M7, M8, M9, M13, M14, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, C61, x, false, beta);
    M_Add17(M2, M5, M6, M10, M11, M12, M15, M16, M18, M20, M25, M26, M33, M35, M36, M39, C62, x, false, beta);
    M_Add18(M1, M3, M4, M7, M8, M9, M13, M14, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, C63, x, false, beta);

    // Handle edge cases with dynamic peeling
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    if (total_steps == steps_left) {
        mkl_set_dynamic(0);
        mkl_set_num_threads_local(num_threads);
    }
#endif
    DynamicPeeling(A, B, C, 6, 3, 3, beta);
}

// C := alpha * A * B + beta * C
template <typename Scalar>
double FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
    int num_steps, double x=1e-8, Scalar alpha=Scalar(1.0), Scalar beta=Scalar(0.0)) {
    MemoryManager<Scalar> mem_mngr;
    mem_mngr.Allocate(6, 3, 3, 40, num_steps, A.m(), A.n(), B.n());
    A.set_multiplier(alpha);
    int num_multiplies_per_step = 40;
    int total_multiplies = pow(num_multiplies_per_step, num_steps);

    // Set parameters needed for all types of parallelism.
    int num_threads = 0;
#ifdef _PARALLEL_
# pragma omp parallel
    {
        if (omp_get_thread_num() == 0) { num_threads = omp_get_num_threads(); }
    }
    omp_set_nested(1);
#endif

#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_)
# pragma omp parallel
    {
        mkl_set_num_threads_local(1);
        mkl_set_dynamic(0);
    }
#endif

#if defined(_PARALLEL_) && (_PARALLEL_ == _DFS_PAR_)
    mkl_set_dynamic(0);
#endif

#if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    if (num_threads > total_multiplies) {
        mkl_set_dynamic(0);
    } else {
# pragma omp parallel
        {
            mkl_set_num_threads_local(1);
            mkl_set_dynamic(0);
        }
    }
#endif

    using FpMilliseconds = std::chrono::duration<float, std::chrono::milliseconds::period>;
    auto t1 = std::chrono::high_resolution_clock::now();

#ifdef _PARALLEL_
# pragma omp parallel
    {
# pragma omp single
#endif
        FastMatmulRecursive(mem_mngr, A, B, C, num_steps, num_steps, 0, x, num_threads, beta);
#ifdef _PARALLEL_
    }
#endif
    auto t2 = std::chrono::high_resolution_clock::now();
    return FpMilliseconds(t2 - t1).count();
}

}  // namespace smirnov633_40_960

#endif  // _smirnov633_40_960_HPP_
