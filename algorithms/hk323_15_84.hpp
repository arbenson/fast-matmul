#ifndef _hk323_15_84_HPP_
#define _hk323_15_84_HPP_

// This is an automatically generated file from gen.py.
#include "common.hpp"

namespace hk323_15_84 {

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
void S_Add2(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add4(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add5(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = -dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add7(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add8(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add9(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataS1[i + j * strideS1] + dataS2[i + j * strideS2];
        }
    }
}

template <typename Scalar>
void S_Add11(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add12(Matrix<Scalar>& S1, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add13(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
void S_Add14(Matrix<Scalar>& S1, Matrix<Scalar>& S2, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add1(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add2(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add3(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add4(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
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
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add7(Matrix<Scalar>& T1, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1] -dataT2[i + j * strideT2];
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
            dataC[i + j * strideC] = dataT1[i + j * strideT1];
        }
    }
}

template <typename Scalar>
void T_Add10(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add11(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
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
void T_Add13(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void T_Add14(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
void T_Add15(Matrix<Scalar>& T1, Matrix<Scalar>& T2, Matrix<Scalar>& C, double x, bool sequential) {
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
            dataC[i + j * strideC] = -dataT1[i + j * strideT1] + dataT2[i + j * strideT2];
        }
    }
}

template <typename Scalar>
void M_Add1(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2];
            }
        }
    }
}

template <typename Scalar>
void M_Add2(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add3(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add4(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = -dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add5(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2];
            }
        }
    }
}

template <typename Scalar>
void M_Add6(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] -dataM3[i + j * strideM3] -dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add7(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] -dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add8(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& M3, Matrix<Scalar>& M4, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideM3 = M3.stride();
    const int strideM4 = M4.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    const Scalar *dataM3 = M3.data();
    const Scalar *dataM4 = M4.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] -dataM2[i + j * strideM2] + dataM3[i + j * strideM3] + dataM4[i + j * strideM4];
            }
        }
    }
}

template <typename Scalar>
void M_Add9(Matrix<Scalar>& M1, Matrix<Scalar>& M2, Matrix<Scalar>& C, double x, bool sequential, Scalar beta) {
    const int strideM1 = M1.stride();
    const int strideM2 = M2.stride();
    const int strideC = C.stride();
    const Scalar *dataM1 = M1.data();
    const Scalar *dataM2 = M2.data();
    Scalar *dataC = C.data();
    if (beta != Scalar(0.0)) {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2] + beta * dataC[i + j * strideC];
            }
        }
    } else {
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
        for (int j = 0; j < C.n(); ++j) {
            for (int i = 0; i < C.m(); ++i) {
                dataC[i + j * strideC] = dataM1[i + j * strideM1] + dataM2[i + j * strideM2];
            }
        }
    }
}

template <typename Scalar>
void SX_Add1(Matrix<Scalar>& SX1, Matrix<Scalar>& SX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideSX1 = SX1.stride();
    const int strideSX2 = SX2.stride();
    const int strideC = C.stride();
    const Scalar *dataSX1 = SX1.data();
    const Scalar *dataSX2 = SX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataSX1[i + j * strideSX1] + dataSX2[i + j * strideSX2];
        }
    }
}

template <typename Scalar>
void SX_Add2(Matrix<Scalar>& SX1, Matrix<Scalar>& SX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideSX1 = SX1.stride();
    const int strideSX2 = SX2.stride();
    const int strideC = C.stride();
    const Scalar *dataSX1 = SX1.data();
    const Scalar *dataSX2 = SX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataSX1[i + j * strideSX1] + dataSX2[i + j * strideSX2];
        }
    }
}

template <typename Scalar>
void SX_Add3(Matrix<Scalar>& SX1, Matrix<Scalar>& SX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideSX1 = SX1.stride();
    const int strideSX2 = SX2.stride();
    const int strideC = C.stride();
    const Scalar *dataSX1 = SX1.data();
    const Scalar *dataSX2 = SX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataSX1[i + j * strideSX1] + dataSX2[i + j * strideSX2];
        }
    }
}

template <typename Scalar>
void TX_Add1(Matrix<Scalar>& TX1, Matrix<Scalar>& TX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideTX1 = TX1.stride();
    const int strideTX2 = TX2.stride();
    const int strideC = C.stride();
    const Scalar *dataTX1 = TX1.data();
    const Scalar *dataTX2 = TX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataTX1[i + j * strideTX1] -dataTX2[i + j * strideTX2];
        }
    }
}

template <typename Scalar>
void TX_Add2(Matrix<Scalar>& TX1, Matrix<Scalar>& TX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideTX1 = TX1.stride();
    const int strideTX2 = TX2.stride();
    const int strideC = C.stride();
    const Scalar *dataTX1 = TX1.data();
    const Scalar *dataTX2 = TX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataTX1[i + j * strideTX1] -dataTX2[i + j * strideTX2];
        }
    }
}

template <typename Scalar>
void TX_Add3(Matrix<Scalar>& TX1, Matrix<Scalar>& TX2, Matrix<Scalar>& C, double x, bool sequential) {
    const int strideTX1 = TX1.stride();
    const int strideTX2 = TX2.stride();
    const int strideC = C.stride();
    const Scalar *dataTX1 = TX1.data();
    const Scalar *dataTX2 = TX2.data();
    Scalar *dataC = C.data();
#ifdef _PARALLEL_
# pragma omp parallel for if(!sequential)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            dataC[i + j * strideC] = dataTX1[i + j * strideTX1] -dataTX2[i + j * strideTX2];
        }
    }
}

template <typename Scalar>
void FastMatmulRecursive(LockAndCounter& locker, MemoryManager<Scalar>& mem_mngr, Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int total_steps, int steps_left, int start_index, double x, int num_threads, Scalar beta) {
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

    Matrix<Scalar> A11 = A.Subblock(3, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(3, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 2, 2, 2);
    Matrix<Scalar> A31 = A.Subblock(3, 2, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 2, 3, 2);
    Matrix<Scalar> B11 = B.Subblock(2, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(2, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 3, 2, 3);
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
#ifdef _PARALLEL_
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
#else
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
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    bool sequential1 = should_launch_task(15, total_steps, steps_left, start_index, 1, num_threads);
    bool sequential2 = should_launch_task(15, total_steps, steps_left, start_index, 2, num_threads);
    bool sequential3 = should_launch_task(15, total_steps, steps_left, start_index, 3, num_threads);
    bool sequential4 = should_launch_task(15, total_steps, steps_left, start_index, 4, num_threads);
    bool sequential5 = should_launch_task(15, total_steps, steps_left, start_index, 5, num_threads);
    bool sequential6 = should_launch_task(15, total_steps, steps_left, start_index, 6, num_threads);
    bool sequential7 = should_launch_task(15, total_steps, steps_left, start_index, 7, num_threads);
    bool sequential8 = should_launch_task(15, total_steps, steps_left, start_index, 8, num_threads);
    bool sequential9 = should_launch_task(15, total_steps, steps_left, start_index, 9, num_threads);
    bool sequential10 = should_launch_task(15, total_steps, steps_left, start_index, 10, num_threads);
    bool sequential11 = should_launch_task(15, total_steps, steps_left, start_index, 11, num_threads);
    bool sequential12 = should_launch_task(15, total_steps, steps_left, start_index, 12, num_threads);
    bool sequential13 = should_launch_task(15, total_steps, steps_left, start_index, 13, num_threads);
    bool sequential14 = should_launch_task(15, total_steps, steps_left, start_index, 14, num_threads);
    bool sequential15 = should_launch_task(15, total_steps, steps_left, start_index, 15, num_threads);
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
#endif
    Matrix<Scalar> A_X1(A11.m(), A11.n());
    SX_Add1(A11, A12, A_X1, x, false);
    Matrix<Scalar> A_X2(A11.m(), A11.n());
    SX_Add2(A21, A22, A_X2, x, false);
    Matrix<Scalar> A_X3(A11.m(), A11.n());
    SX_Add3(A31, A32, A_X3, x, false);

    Matrix<Scalar> B_X1(B11.m(), B11.n());
    TX_Add1(B11, B21, B_X1, x, false);
    Matrix<Scalar> B_X2(B11.m(), B11.n());
    TX_Add2(B12, B22, B_X2, x, false);
    Matrix<Scalar> B_X3(B11.m(), B11.n());
    TX_Add3(B13, B23, B_X3, x, false);


    // M1 = (1.0 * A_X1) * (1.0 * B21)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential1) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A_X1, B21, M1, total_steps, steps_left - 1, (start_index + 1 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 1, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M2 = (1.0 * A11) * (1.0 * B_X1)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential2) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A11, B_X1, M2, total_steps, steps_left - 1, (start_index + 2 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 2, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M3 = (1.0 * A_X2) * (1.0 * B12)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential3) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A_X2, B12, M3, total_steps, steps_left - 1, (start_index + 3 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 3, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M4 = (1.0 * A11 + 1.0 * A21) * (1.0 * B11 + 1.0 * B12)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential4) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S4(A11.m(), A11.n());
#endif
    S_Add4(A11, A21, S4, x, sequential4);
#ifdef _PARALLEL_
    Matrix<Scalar> T4(mem_mngr.GetMem(start_index, 4, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T4(B11.m(), B11.n());
#endif
    T_Add4(B11, B12, T4, x, sequential4);
    FastMatmulRecursive(locker, mem_mngr, S4, T4, M4, total_steps, steps_left - 1, (start_index + 4 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S4.deallocate();
    T4.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 4, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M5 = (1.0 * A11 + -1.0 * A22) * (1.0 * B12 + 1.0 * B21)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential5) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S5(A11.m(), A11.n());
#endif
    S_Add5(A11, A22, S5, x, sequential5);
#ifdef _PARALLEL_
    Matrix<Scalar> T5(mem_mngr.GetMem(start_index, 5, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T5(B11.m(), B11.n());
#endif
    T_Add5(B12, B21, T5, x, sequential5);
    FastMatmulRecursive(locker, mem_mngr, S5, T5, M5, total_steps, steps_left - 1, (start_index + 5 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S5.deallocate();
    T5.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 5, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M6 = (-1.0 * A_X1 + 1.0 * A_X3) * (-1.0 * B11 + 1.0 * B13)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential6) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S6(A11.m(), A11.n());
#endif
    S_Add6(A_X1, A_X3, S6, x, sequential6);
#ifdef _PARALLEL_
    Matrix<Scalar> T6(mem_mngr.GetMem(start_index, 6, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T6(B11.m(), B11.n());
#endif
    T_Add6(B11, B13, T6, x, sequential6);
    FastMatmulRecursive(locker, mem_mngr, S6, T6, M6, total_steps, steps_left - 1, (start_index + 6 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S6.deallocate();
    T6.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 6, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M7 = (1.0 * A31) * (1.0 * B13)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential7) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A31, B13, M7, total_steps, steps_left - 1, (start_index + 7 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 7, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M8 = (-1.0 * A32 + 1.0 * A_X1) * (1.0 * B13 + -1.0 * B_X1)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential8) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S8(A11.m(), A11.n());
#endif
    S_Add8(A32, A_X1, S8, x, sequential8);
#ifdef _PARALLEL_
    Matrix<Scalar> T8(mem_mngr.GetMem(start_index, 8, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T8(B11.m(), B11.n());
#endif
    T_Add8(B13, B_X1, T8, x, sequential8);
    FastMatmulRecursive(locker, mem_mngr, S8, T8, M8, total_steps, steps_left - 1, (start_index + 8 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S8.deallocate();
    T8.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 8, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M9 = (1.0 * A22) * (1.0 * B_X2)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential9) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A22, B_X2, M9, total_steps, steps_left - 1, (start_index + 9 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 9, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M10 = (1.0 * A12 + 1.0 * A22) * (1.0 * B21 + 1.0 * B22)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential10) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S10(A11.m(), A11.n());
#endif
    S_Add10(A12, A22, S10, x, sequential10);
#ifdef _PARALLEL_
    Matrix<Scalar> T10(mem_mngr.GetMem(start_index, 10, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T10(B11.m(), B11.n());
#endif
    T_Add10(B21, B22, T10, x, sequential10);
    FastMatmulRecursive(locker, mem_mngr, S10, T10, M10, total_steps, steps_left - 1, (start_index + 10 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S10.deallocate();
    T10.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 10, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M11 = (-1.0 * A_X2 + 1.0 * A_X3) * (-1.0 * B22 + 1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential11) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S11(A11.m(), A11.n());
#endif
    S_Add11(A_X2, A_X3, S11, x, sequential11);
#ifdef _PARALLEL_
    Matrix<Scalar> T11(mem_mngr.GetMem(start_index, 11, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T11(B11.m(), B11.n());
#endif
    T_Add11(B22, B23, T11, x, sequential11);
    FastMatmulRecursive(locker, mem_mngr, S11, T11, M11, total_steps, steps_left - 1, (start_index + 11 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S11.deallocate();
    T11.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 11, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M12 = (1.0 * A32) * (1.0 * B23)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential12) shared(mem_mngr, locker) untied
    {
#endif
    FastMatmulRecursive(locker, mem_mngr, A32, B23, M12, total_steps, steps_left - 1, (start_index + 12 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 12, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M13 = (-1.0 * A21 + 1.0 * A31) * (-1.0 * B_X2 + 1.0 * B_X3)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential13) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S13(A11.m(), A11.n());
#endif
    S_Add13(A21, A31, S13, x, sequential13);
#ifdef _PARALLEL_
    Matrix<Scalar> T13(mem_mngr.GetMem(start_index, 13, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T13(B11.m(), B11.n());
#endif
    T_Add13(B_X2, B_X3, T13, x, sequential13);
    FastMatmulRecursive(locker, mem_mngr, S13, T13, M13, total_steps, steps_left - 1, (start_index + 13 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S13.deallocate();
    T13.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 13, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M14 = (1.0 * A31 + -1.0 * A_X2) * (1.0 * B23 + 1.0 * B_X2)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential14) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S14(A11.m(), A11.n());
#endif
    S_Add14(A31, A_X2, S14, x, sequential14);
#ifdef _PARALLEL_
    Matrix<Scalar> T14(mem_mngr.GetMem(start_index, 14, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T14(B11.m(), B11.n());
#endif
    T_Add14(B23, B_X2, T14, x, sequential14);
    FastMatmulRecursive(locker, mem_mngr, S14, T14, M14, total_steps, steps_left - 1, (start_index + 14 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S14.deallocate();
    T14.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 14, num_threads)) {
# pragma omp taskwait
# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)
    SwitchToDFS(locker, num_threads);
# endif
    }
#endif

    // M15 = (-1.0 * A12 + 1.0 * A32) * (-1.0 * B_X1 + 1.0 * B_X3)
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
# pragma omp task if(sequential15) shared(mem_mngr, locker) untied
    {
#endif
#ifdef _PARALLEL_
    Matrix<Scalar> S15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, S), A11.m(), A11.m(), A11.n());
#else
    Matrix<Scalar> S15(A11.m(), A11.n());
#endif
    S_Add15(A12, A32, S15, x, sequential15);
#ifdef _PARALLEL_
    Matrix<Scalar> T15(mem_mngr.GetMem(start_index, 15, total_steps - steps_left, T), B11.m(), B11.m(), B11.n());
#else
    Matrix<Scalar> T15(B11.m(), B11.n());
#endif
    T_Add15(B_X1, B_X3, T15, x, sequential15);
    FastMatmulRecursive(locker, mem_mngr, S15, T15, M15, total_steps, steps_left - 1, (start_index + 15 - 1) * 15, x, num_threads, Scalar(0.0));
#ifndef _PARALLEL_
    S15.deallocate();
    T15.deallocate();
#endif
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
locker.Decrement();
    }
    if (should_task_wait(15, total_steps, steps_left, start_index, 15, num_threads)) {
# pragma omp taskwait
    }
#endif

    M_Add1(M1, M2, C11, x, false, beta);
    M_Add2(M1, M5, M9, M10, C12, x, false, beta);
    M_Add3(M2, M8, M12, M15, C13, x, false, beta);
    M_Add4(M2, M3, M4, M5, C21, x, false, beta);
    M_Add5(M3, M9, C22, x, false, beta);
    M_Add6(M7, M9, M13, M14, C23, x, false, beta);
    M_Add7(M1, M6, M7, M8, C31, x, false, beta);
    M_Add8(M3, M11, M12, M14, C32, x, false, beta);
    M_Add9(M7, M12, C33, x, false, beta);

    // Handle edge cases with dynamic peeling
#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)
    if (total_steps == steps_left) {
        mkl_set_num_threads_local(num_threads);
        mkl_set_dynamic(0);
    }
#endif
    DynamicPeeling(A, B, C, 3, 2, 3, beta);
}

// C := alpha * A * B + beta * C
template <typename Scalar>
double FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
    int num_steps, double x=1e-8, Scalar alpha=Scalar(1.0), Scalar beta=Scalar(0.0)) {
    MemoryManager<Scalar> mem_mngr;
#ifdef _PARALLEL_
    mem_mngr.Allocate(3, 2, 3, 15, num_steps, A.m(), A.n(), B.n());
#endif
    A.set_multiplier(alpha);
    int num_multiplies_per_step = 15;
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

    LockAndCounter locker(total_multiplies - (total_multiplies % num_threads));
    using FpMilliseconds = std::chrono::duration<float, std::chrono::milliseconds::period>;
    auto t1 = std::chrono::high_resolution_clock::now();

#ifdef _PARALLEL_
# pragma omp parallel
    {
# pragma omp single
#endif
        FastMatmulRecursive(locker, mem_mngr, A, B, C, num_steps, num_steps, 0, x, num_threads, beta);
#ifdef _PARALLEL_
    }
#endif
    auto t2 = std::chrono::high_resolution_clock::now();
    return FpMilliseconds(t2 - t1).count();
}

}  // namespace hk323_15_84

#endif  // _hk323_15_84_HPP_
