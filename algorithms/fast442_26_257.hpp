#ifndef _grey442_26_257_HPP_
#define _grey442_26_257_HPP_

// This is an automatically generated file from gen.py.
#include "common.hpp"

namespace grey442_26_257 {

template <typename Scalar>
void S_Add1(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1];
        }
    }
}

template <typename Scalar>
void S_Add2(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6];
        }
    }
}

template <typename Scalar>
void S_Add3(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1];
        }
    }
}

template <typename Scalar>
void S_Add4(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2] + Scalar(0.5) * dataS3[i + j * strideS3];
        }
    }
}

template <typename Scalar>
void S_Add5(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4] + dataS5[i + j * strideS5] -dataS6[i + j * strideS6];
        }
    }
}

template <typename Scalar>
void S_Add6(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add7(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.5) * dataS1[i + j * strideS1] + Scalar(-0.5) * dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add8(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.5) * dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2] + Scalar(-0.5) * dataS3[i + j * strideS3] + Scalar(0.5) * dataS4[i + j * strideS4] + Scalar(0.5) * dataS5[i + j * strideS5] + Scalar(-0.5) * dataS6[i + j * strideS6];
        }
    }
}

template <typename Scalar>
void S_Add9(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add10(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.5) * dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add11(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add12(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add13(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2] -dataS3[i + j * strideS3] + dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add14(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4] + dataS5[i + j * strideS5];
        }
    }
}

template <typename Scalar>
void S_Add15(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add16(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.5) * dataS1[i + j * strideS1] + Scalar(-0.5) * dataS2[i + j * strideS2] + Scalar(0.5) * dataS3[i + j * strideS3] + Scalar(0.5) * dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add17(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.5) * dataS1[i + j * strideS1] + Scalar(-0.5) * dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add18(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& S5, Matrix<Scalar>& S6, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideS5 = S5.stride();
    const int strideS6 = S6.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    const Scalar *dataS5 = S5.data();
    const Scalar *dataS6 = S6.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.5) * dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2] + Scalar(0.5) * dataS3[i + j * strideS3] + Scalar(-0.5) * dataS4[i + j * strideS4] + Scalar(-0.5) * dataS5[i + j * strideS5] + Scalar(-0.5) * dataS6[i + j * strideS6];
        }
    }
}

template <typename Scalar>
void S_Add19(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(-0.5) * dataS1[i + j * strideS1] + Scalar(-0.5) * dataS2[i + j * strideS2] + Scalar(0.5) * dataS3[i + j * strideS3] + Scalar(0.5) * dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add20(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = Scalar(0.5) * dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add21(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + Scalar(0.5) * dataS2[i + j * strideS2] + Scalar(-0.5) * dataS3[i + j * strideS3];
        }
    }
}

template <typename Scalar>
void S_Add22(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] -dataS2[i + j * strideS2] -dataS3[i + j * strideS3] -dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add23(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add24(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add25(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& S3, Matrix<Scalar>& S4, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideS3 = S3.stride();
    const int strideS4 = S4.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    const Scalar *dataS3 = S3.data();
    const Scalar *dataS4 = S4.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + dataS2[i + j * strideS2] + dataS3[i + j * strideS3] -dataS4[i + j * strideS4];
        }
    }
}

template <typename Scalar>
void S_Add26(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideS1 = S1.stride();
    const int strideS2 = S2.stride();
    const int strideC = C.stride();
    const Scalar *dataS1 = S1.data();
    const Scalar *dataS2 = S2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataS1[i + j * strideS1] -dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void T_Add1(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add2(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3];
        }
    }
}

template <typename Scalar>
void T_Add3(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3];
        }
    }
}

template <typename Scalar>
void T_Add4(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3];
        }
    }
}

template <typename Scalar>
void T_Add5(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add6(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add7(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add8(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add9(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1];
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add11(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3];
        }
    }
}

template <typename Scalar>
void T_Add12(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add13(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add14(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add15(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] -dataT4[i + j * strideT4] -dataT5[i + j * strideT5] + dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add17(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add19(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add20(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& T6, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] + dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5] -dataT6[i + j * strideT6];
        }
    }
}

template <typename Scalar>
void T_Add21(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& T4, Matrix<Scalar>& T5, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideT4 = T4.stride();
    const int strideT5 = T5.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    const Scalar *dataT4 = T4.data();
    const Scalar *dataT5 = T5.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] -dataT3[i + j * strideT3] + dataT4[i + j * strideT4] -dataT5[i + j * strideT5];
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2] -dataT3[i + j * strideT3] -dataT4[i + j * strideT4];
        }
    }
}

template <typename Scalar>
void T_Add23(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = -dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add24(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add25(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& T3, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideT3 = T3.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    const Scalar *dataT3 = T3.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2] + dataT3[i + j * strideT3];
        }
    }
}

template <typename Scalar>
void T_Add26(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideT1 = T1.stride();
    const int strideT2 = T2.stride();
    const int strideC = C.stride();
    const Scalar *dataT1 = T1.data();
    const Scalar *dataT2 = T2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void M_Add1(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideM5 = M5.stride();
    const int strideM6 = M6.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    const Scalar *dataM5 = M5.data();
    const Scalar *dataM6 = M6.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6];
            }
        }
    }
}

template <typename Scalar>
void M_Add2(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8];
            }
        }
    }
}

template <typename Scalar>
void M_Add3(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + Scalar(-0.5) * dataM12[i + j * strideM12] + dataM13[i + j * strideM13] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + Scalar(-0.5) * dataM12[i + j * strideM12] + dataM13[i + j * strideM13];
            }
        }
    }
}

template <typename Scalar>
void M_Add4(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12];
            }
        }
    }
}

template <typename Scalar>
void M_Add5(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + Scalar(0.5) * dataM13[i + j * strideM13] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] -dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + Scalar(0.5) * dataM13[i + j * strideM13];
            }
        }
    }
}

template <typename Scalar>
void M_Add6(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] -dataM5[i + j * strideM5] + dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] + dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12];
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
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + Scalar(-0.5) * dataM16[i + j * strideM16] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + Scalar(0.5) * dataM2[i + j * strideM2] -dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + dataM5[i + j * strideM5] + dataM6[i + j * strideM6] + dataM7[i + j * strideM7] + dataM8[i + j * strideM8] -dataM9[i + j * strideM9] + dataM10[i + j * strideM10] + dataM11[i + j * strideM11] + dataM12[i + j * strideM12] -dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + dataM15[i + j * strideM15] + Scalar(-0.5) * dataM16[i + j * strideM16];
            }
        }
    }
}

template <typename Scalar>
void M_Add8(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& M5, Matrix<Scalar>& M6, Matrix<Scalar>& M7, Matrix<Scalar>& M8, Matrix<Scalar>& M9, Matrix<Scalar>& M10, Matrix<Scalar>& M11, Matrix<Scalar>& M12, Matrix<Scalar>& M13, Matrix<Scalar>& M14, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
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
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + dataM5[i + j * strideM5] -dataM6[i + j * strideM6] -dataM7[i + j * strideM7] -dataM8[i + j * strideM8] + dataM9[i + j * strideM9] -dataM10[i + j * strideM10] -dataM11[i + j * strideM11] -dataM12[i + j * strideM12] + dataM13[i + j * strideM13] -dataM14[i + j * strideM14];
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

    Matrix<Scalar> A11 = A.Subblock(4, 4, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(4, 4, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(4, 4, 1, 3);
    Matrix<Scalar> A14 = A.Subblock(4, 4, 1, 4);
    Matrix<Scalar> A21 = A.Subblock(4, 4, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(4, 4, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(4, 4, 2, 3);
    Matrix<Scalar> A24 = A.Subblock(4, 4, 2, 4);
    Matrix<Scalar> A31 = A.Subblock(4, 4, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(4, 4, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(4, 4, 3, 3);
    Matrix<Scalar> A34 = A.Subblock(4, 4, 3, 4);
    Matrix<Scalar> A41 = A.Subblock(4, 4, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(4, 4, 4, 2);
    Matrix<Scalar> A43 = A.Subblock(4, 4, 4, 3);
    Matrix<Scalar> A44 = A.Subblock(4, 4, 4, 4);
    Matrix<Scalar> B11 = B.Subblock(4, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(4, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(4, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(4, 2, 2, 2);
    Matrix<Scalar> B31 = B.Subblock(4, 2, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(4, 2, 3, 2);
    Matrix<Scalar> B41 = B.Subblock(4, 2, 4, 1);
    Matrix<Scalar> B42 = B.Subblock(4, 2, 4, 2);
    Matrix<Scalar> C11 = C.Subblock(4, 2, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 2, 1, 2);
    Matrix<Scalar> C21 = C.Subblock(4, 2, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 2, 2, 2);
    Matrix<Scalar> C31 = C.Subblock(4, 2, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 2, 3, 2);
    Matrix<Scalar> C41 = C.Subblock(4, 2, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 2, 4, 2);


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
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    bool sequential1 = should_launch_task(26, total_steps, steps_left, start_index, 1, num_threads);
    bool sequential2 = should_launch_task(26, total_steps, steps_left, start_index, 2, num_threads);
    bool sequential3 = should_launch_task(26, total_steps, steps_left, start_index, 3, num_threads);
    bool sequential4 = should_launch_task(26, total_steps, steps_left, start_index, 4, num_threads);
    bool sequential5 = should_launch_task(26, total_steps, steps_left, start_index, 5, num_threads);
    bool sequential6 = should_launch_task(26, total_steps, steps_left, start_index, 6, num_threads);
    bool sequential7 = should_launch_task(26, total_steps, steps_left, start_index, 7, num_threads);
    bool sequential8 = should_launch_task(26, total_steps, steps_left, start_index, 8, num_threads);
    bool sequential9 = should_launch_task(26, total_steps, steps_left, start_index, 9, num_threads);
    bool sequential10 = should_launch_task(26, total_steps, steps_left, start_index, 10, num_threads);
    bool sequential11 = should_launch_task(26, total_steps, steps_left, start_index, 11, num_threads);
    bool sequential12 = should_launch_task(26, total_steps, steps_left, start_index, 12, num_threads);
    bool sequential13 = should_launch_task(26, total_steps, steps_left, start_index, 13, num_threads);
    bool sequential14 = should_launch_task(26, total_steps, steps_left, start_index, 14, num_threads);
    bool sequential15 = should_launch_task(26, total_steps, steps_left, start_index, 15, num_threads);
    bool sequential16 = should_launch_task(26, total_steps, steps_left, start_index, 16, num_threads);
    bool sequential17 = should_launch_task(26, total_steps, steps_left, start_index, 17, num_threads);
    bool sequential18 = should_launch_task(26, total_steps, steps_left, start_index, 18, num_threads);
    bool sequential19 = should_launch_task(26, total_steps, steps_left, start_index, 19, num_threads);
    bool sequential20 = should_launch_task(26, total_steps, steps_left, start_index, 20, num_threads);
    bool sequential21 = should_launch_task(26, total_steps, steps_left, start_index, 21, num_threads);
    bool sequential22 = should_launch_task(26, total_steps, steps_left, start_index, 22, num_threads);
    bool sequential23 = should_launch_task(26, total_steps, steps_left, start_index, 23, num_threads);
    bool sequential24 = should_launch_task(26, total_steps, steps_left, start_index, 24, num_threads);
    bool sequential25 = should_launch_task(26, total_steps, steps_left, start_index, 25, num_threads);
    bool sequential26 = should_launch_task(26, total_steps, steps_left, start_index, 26, num_threads);
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
#endif



    // M1 = (1.0 * A11) * (1.0 * B11 + 1.0 * B41)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential1) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> T1(mem_mngr.GetMem(start_index, 1, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add1(B11, B41, T1, x, sequential1);
    FastMatmulRecursive(mem_mngr, A11, T1, M1, total_steps, steps_left - 1, (start_index + 1 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 1, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M2 = (1.0 * A21 + 1.0 * A22 + 1.0 * A23 + 1.0 * A32 + 1.0 * A33 + -1.0 * A41) * (-1.0 * B11 + -1.0 * B12 + 1.0 * B31)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential2) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S2(mem_mngr.GetMem(start_index, 2, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add2(A21, A22, A23, A32, A33, A41, S2, x, sequential2);
    Matrix<Scalar> T2(mem_mngr.GetMem(start_index, 2, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add2(B11, B12, B31, T2, x, sequential2);
    FastMatmulRecursive(mem_mngr, S2, T2, M2, total_steps, steps_left - 1, (start_index + 2 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 2, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M3 = (1.0 * A13) * (1.0 * B21 + -1.0 * B31 + -1.0 * B41)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential3) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> T3(mem_mngr.GetMem(start_index, 3, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add3(B21, B31, B41, T3, x, sequential3);
    FastMatmulRecursive(mem_mngr, A13, T3, M3, total_steps, steps_left - 1, (start_index + 3 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 3, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M4 = (-1.0 * A11 + 0.5 * A24 + 0.5 * A34) * (1.0 * B11 + 1.0 * B12 + 1.0 * B41)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential4) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add4(A11, A24, A34, S4, x, sequential4);
    Matrix<Scalar> T4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add4(B11, B12, B41, T4, x, sequential4);
    FastMatmulRecursive(mem_mngr, S4, T4, M4, total_steps, steps_left - 1, (start_index + 4 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 4, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M5 = (1.0 * A24 + -1.0 * A32 + -1.0 * A33 + 1.0 * A42 + 1.0 * A43 + -1.0 * A44) * (1.0 * B21 + -1.0 * B22)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential5) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add5(A24, A32, A33, A42, A43, A44, S5, x, sequential5);
    Matrix<Scalar> T5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add5(B21, B22, T5, x, sequential5);
    FastMatmulRecursive(mem_mngr, S5, T5, M5, total_steps, steps_left - 1, (start_index + 5 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 5, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M6 = (-1.0 * A12 + -1.0 * A13) * (1.0 * B22 + 1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential6) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add6(A12, A13, S6, x, sequential6);
    Matrix<Scalar> T6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add6(B22, B42, T6, x, sequential6);
    FastMatmulRecursive(mem_mngr, S6, T6, M6, total_steps, steps_left - 1, (start_index + 6 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 6, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M7 = (-0.5 * A24 + -0.5 * A34) * (1.0 * B11 + 1.0 * B12 + 1.0 * B41 + 1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential7) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S7(mem_mngr.GetMem(start_index, 7, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add7(A24, A34, S7, x, sequential7);
    Matrix<Scalar> T7(mem_mngr.GetMem(start_index, 7, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add7(B11, B12, B41, B42, T7, x, sequential7);
    FastMatmulRecursive(mem_mngr, S7, T7, M7, total_steps, steps_left - 1, (start_index + 7 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 7, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M8 = (0.5 * A21 + 0.5 * A23 + -0.5 * A24 + 0.5 * A31 + 0.5 * A33 + -0.5 * A34) * (1.0 * B11 + 1.0 * B12)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential8) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add8(A21, A23, A24, A31, A33, A34, S8, x, sequential8);
    Matrix<Scalar> T8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add8(B11, B12, T8, x, sequential8);
    FastMatmulRecursive(mem_mngr, S8, T8, M8, total_steps, steps_left - 1, (start_index + 8 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 8, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A41) * (-1.0 * B12)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential9) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S9(mem_mngr.GetMem(start_index, 9, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add9(A11, A41, S9, x, sequential9);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(mem_mngr, S9, B12, M9, total_steps, steps_left - 1, (start_index + 9 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 9, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M10 = (-0.5 * A24 + 0.5 * A34) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32 + -1.0 * B41 + 1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential10) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add10(A24, A34, S10, x, sequential10);
    Matrix<Scalar> T10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add10(B21, B22, B31, B32, B41, B42, T10, x, sequential10);
    FastMatmulRecursive(mem_mngr, S10, T10, M10, total_steps, steps_left - 1, (start_index + 10 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 10, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M11 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A44) * (-1.0 * B21 + 1.0 * B22 + 1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential11) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add11(A12, A13, A24, A44, S11, x, sequential11);
    Matrix<Scalar> T11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add11(B21, B22, B42, T11, x, sequential11);
    FastMatmulRecursive(mem_mngr, S11, T11, M11, total_steps, steps_left - 1, (start_index + 11 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 11, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M12 = (1.0 * A12 + 1.0 * A13 + -1.0 * A14 + 1.0 * A24) * (1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential12) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S12(mem_mngr.GetMem(start_index, 12, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add12(A12, A13, A14, A24, S12, x, sequential12);
    FastMatmulRecursive(mem_mngr, S12, B42, M12, total_steps, steps_left - 1, (start_index + 12 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 12, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M13 = (1.0 * A12 + 1.0 * A13 + -1.0 * A22 + 1.0 * A42) * (-1.0 * B21)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential13) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add13(A12, A13, A22, A42, S13, x, sequential13);
    M13.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(mem_mngr, S13, B21, M13, total_steps, steps_left - 1, (start_index + 13 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 13, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M14 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A14 + -1.0 * A24 + 1.0 * A44) * (-1.0 * B41)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential14) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add14(A11, A13, A14, A24, A44, S14, x, sequential14);
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(mem_mngr, S14, B41, M14, total_steps, steps_left - 1, (start_index + 14 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 14, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M15 = (-1.0 * A24 + 1.0 * A44) * (1.0 * B21 + -1.0 * B22 + 1.0 * B41 + -1.0 * B42)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential15) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add15(A24, A44, S15, x, sequential15);
    Matrix<Scalar> T15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add15(B21, B22, B41, B42, T15, x, sequential15);
    FastMatmulRecursive(mem_mngr, S15, T15, M15, total_steps, steps_left - 1, (start_index + 15 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 15, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M16 = (0.5 * A22 + -0.5 * A31 + 0.5 * A32 + 0.5 * A41) * (1.0 * B11 + 1.0 * B12 + 1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential16) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S16(mem_mngr.GetMem(start_index, 16, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add16(A22, A31, A32, A41, S16, x, sequential16);
    Matrix<Scalar> T16(mem_mngr.GetMem(start_index, 16, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add16(B11, B12, B21, B22, B31, B32, T16, x, sequential16);
    FastMatmulRecursive(mem_mngr, S16, T16, M16, total_steps, steps_left - 1, (start_index + 16 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 16, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M17 = (0.5 * A31 + -0.5 * A41) * (1.0 * B11 + -1.0 * B12 + 1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential17) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S17(mem_mngr.GetMem(start_index, 17, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add17(A31, A41, S17, x, sequential17);
    Matrix<Scalar> T17(mem_mngr.GetMem(start_index, 17, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add17(B11, B12, B21, B22, B31, B32, T17, x, sequential17);
    FastMatmulRecursive(mem_mngr, S17, T17, M17, total_steps, steps_left - 1, (start_index + 17 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 17, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M18 = (0.5 * A24 + 0.5 * A31 + 0.5 * A33 + -0.5 * A34 + -0.5 * A41 + -0.5 * A43) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential18) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S18(mem_mngr.GetMem(start_index, 18, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add18(A24, A31, A33, A34, A41, A43, S18, x, sequential18);
    Matrix<Scalar> T18(mem_mngr.GetMem(start_index, 18, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add18(B21, B22, B31, B32, T18, x, sequential18);
    FastMatmulRecursive(mem_mngr, S18, T18, M18, total_steps, steps_left - 1, (start_index + 18 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 18, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M19 = (-0.5 * A21 + -0.5 * A23 + 0.5 * A41 + 0.5 * A43) * (-1.0 * B31)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential19) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S19(mem_mngr.GetMem(start_index, 19, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add19(A21, A23, A41, A43, S19, x, sequential19);
    M19.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(mem_mngr, S19, B31, M19, total_steps, steps_left - 1, (start_index + 19 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 19, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M20 = (0.5 * A22 + 0.5 * A32) * (1.0 * B11 + 1.0 * B12 + 1.0 * B21 + 1.0 * B22 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential20) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S20(mem_mngr.GetMem(start_index, 20, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add20(A22, A32, S20, x, sequential20);
    Matrix<Scalar> T20(mem_mngr.GetMem(start_index, 20, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add20(B11, B12, B21, B22, B31, B32, T20, x, sequential20);
    FastMatmulRecursive(mem_mngr, S20, T20, M20, total_steps, steps_left - 1, (start_index + 20 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 20, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M21 = (-1.0 * A13 + 0.5 * A24 + -0.5 * A34) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32 + -1.0 * B41)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential21) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S21(mem_mngr.GetMem(start_index, 21, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add21(A13, A24, A34, S21, x, sequential21);
    Matrix<Scalar> T21(mem_mngr.GetMem(start_index, 21, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add21(B21, B22, B31, B32, B41, T21, x, sequential21);
    FastMatmulRecursive(mem_mngr, S21, T21, M21, total_steps, steps_left - 1, (start_index + 21 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 21, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M22 = (-1.0 * A22 + -1.0 * A23 + -1.0 * A32 + -1.0 * A33) * (1.0 * B11 + 1.0 * B12 + -1.0 * B31 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential22) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S22(mem_mngr.GetMem(start_index, 22, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add22(A22, A23, A32, A33, S22, x, sequential22);
    Matrix<Scalar> T22(mem_mngr.GetMem(start_index, 22, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add22(B11, B12, B31, B32, T22, x, sequential22);
    FastMatmulRecursive(mem_mngr, S22, T22, M22, total_steps, steps_left - 1, (start_index + 22 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 22, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M23 = (1.0 * A32 + 1.0 * A33) * (-1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential23) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S23(mem_mngr.GetMem(start_index, 23, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add23(A32, A33, S23, x, sequential23);
    M23.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(mem_mngr, S23, B32, M23, total_steps, steps_left - 1, (start_index + 23 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 23, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M24 = (1.0 * A13 + 1.0 * A22) * (1.0 * B22 + -1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential24) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S24(mem_mngr.GetMem(start_index, 24, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add24(A13, A22, S24, x, sequential24);
    Matrix<Scalar> T24(mem_mngr.GetMem(start_index, 24, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add24(B22, B32, T24, x, sequential24);
    FastMatmulRecursive(mem_mngr, S24, T24, M24, total_steps, steps_left - 1, (start_index + 24 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 24, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M25 = (-1.0 * A22 + 1.0 * A32 + 1.0 * A33 + -1.0 * A43) * (1.0 * B21 + -1.0 * B22 + 1.0 * B32)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential25) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S25(mem_mngr.GetMem(start_index, 25, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add25(A22, A32, A33, A43, S25, x, sequential25);
    Matrix<Scalar> T25(mem_mngr.GetMem(start_index, 25, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add25(B21, B22, B32, T25, x, sequential25);
    FastMatmulRecursive(mem_mngr, S25, T25, M25, total_steps, steps_left - 1, (start_index + 25 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 25, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    mkl_set_num_threads_local(num_threads);
    mkl_set_dynamic(0);
# endif
    }
#endif

    // M26 = (1.0 * A21 + -1.0 * A41) * (1.0 * B11 + -1.0 * B31)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential26) shared(mem_mngr) untied
    {
#endif
    Matrix<Scalar> S26(mem_mngr.GetMem(start_index, 26, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
    S_Add26(A21, A41, S26, x, sequential26);
    Matrix<Scalar> T26(mem_mngr.GetMem(start_index, 26, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
    T_Add26(B11, B31, T26, x, sequential26);
    FastMatmulRecursive(mem_mngr, S26, T26, M26, total_steps, steps_left - 1, (start_index + 26 - 1) * 26, x, num_threads, Scalar(0.0));
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
    if (should_task_wait(26, total_steps, steps_left, start_index, 26, num_threads)) {
# pragma omp taskwait
    }
#endif

    M_Add1(M1, M3, M6, M11, M14, M15, C11, x, false, beta);
    M_Add2(M1, M3, M4, M6, M7, M10, M12, M21, C12, x, false, beta);
    M_Add3(M1, M2, M3, M4, M8, M9, M16, M18, M19, M21, M24, M25, M26, C21, x, false, beta);
    M_Add4(M1, M2, M3, M4, M7, M9, M10, M21, M22, M23, M24, M26, C22, x, false, beta);
    M_Add5(M1, M2, M3, M4, M8, M9, M17, M18, M19, M20, M21, M24, M25, C31, x, false, beta);
    M_Add6(M1, M3, M4, M7, M9, M10, M16, M17, M20, M21, M23, M24, C32, x, false, beta);
    M_Add7(M1, M2, M3, M4, M6, M8, M9, M11, M13, M15, M16, M18, M19, M21, M24, M25, C41, x, false, beta);
    M_Add8(M1, M3, M4, M5, M6, M7, M9, M10, M11, M13, M21, M23, M24, M25, C42, x, false, beta);

    // Handle edge cases with dynamic peeling
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    if (total_steps == steps_left) {
        mkl_set_dynamic(0);
        mkl_set_num_threads_local(num_threads);
    }
#endif
    DynamicPeeling(A, B, C, 4, 4, 2, beta);
}

// C := alpha * A * B + beta * C
template <typename Scalar>
double FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
    int num_steps, double x=1e-8, Scalar alpha=Scalar(1.0), Scalar beta=Scalar(0.0)) {
    MemoryManager<Scalar> mem_mngr;
    mem_mngr.Allocate(4, 4, 2, 26, num_steps, A.m(), A.n(), B.n());
    A.set_multiplier(alpha);
    int num_multiplies_per_step = 26;
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
    using FpMilliseconds = std::chrono::duration<float, std::chrono::milliseconds::period>;
    auto t1 = std::chrono::high_resolution_clock::now();
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    omp_set_nested(1);
    if (num_threads > total_multiplies) {
        mkl_set_dynamic(0);
    }
# pragma omp parallel
    {
# pragma omp single
#endif
        FastMatmulRecursive(mem_mngr, A, B, C, num_steps, num_steps, 0, x, num_threads, beta);
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    }
#endif
    auto t2 = std::chrono::high_resolution_clock::now();
    return FpMilliseconds(t2 - t1).count();
}

}  // namespace grey442_26_257

#endif  // _grey442_26_257_HPP_
