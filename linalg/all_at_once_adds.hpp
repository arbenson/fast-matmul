#ifndef _ALL_ADDS_HPP_
#define _ALL_ADDS_HPP_

template <typename Scalar>
void Add(Matrix<Scalar>& A1,
         Scalar alpha1,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            dataC[i + j * strideC] = a1;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2,
         Scalar alpha1, Scalar alpha2,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            dataC[i + j * strideC] = a1 + a2;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            dataC[i + j * strideC] = a1 + a2 + a3;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());

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

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34, Scalar alpha35,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());
    assert(A35.m() == C.m() && A35.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideA35 = A35.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    const Scalar *dataA35 = A35.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            Scalar a35 = alpha35 * dataA35[i + j * strideA35];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34 + a35;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34, Scalar alpha35, Scalar alpha36,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());
    assert(A35.m() == C.m() && A35.n() == C.n());
    assert(A36.m() == C.m() && A36.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideA35 = A35.stride();
    const int strideA36 = A36.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    const Scalar *dataA35 = A35.data();
    const Scalar *dataA36 = A36.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            Scalar a35 = alpha35 * dataA35[i + j * strideA35];
            Scalar a36 = alpha36 * dataA36[i + j * strideA36];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34 + a35 + a36;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34, Scalar alpha35, Scalar alpha36, Scalar alpha37,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());
    assert(A35.m() == C.m() && A35.n() == C.n());
    assert(A36.m() == C.m() && A36.n() == C.n());
    assert(A37.m() == C.m() && A37.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideA35 = A35.stride();
    const int strideA36 = A36.stride();
    const int strideA37 = A37.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    const Scalar *dataA35 = A35.data();
    const Scalar *dataA36 = A36.data();
    const Scalar *dataA37 = A37.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            Scalar a35 = alpha35 * dataA35[i + j * strideA35];
            Scalar a36 = alpha36 * dataA36[i + j * strideA36];
            Scalar a37 = alpha37 * dataA37[i + j * strideA37];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34 + a35 + a36 + a37;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34, Scalar alpha35, Scalar alpha36, Scalar alpha37, Scalar alpha38,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());
    assert(A35.m() == C.m() && A35.n() == C.n());
    assert(A36.m() == C.m() && A36.n() == C.n());
    assert(A37.m() == C.m() && A37.n() == C.n());
    assert(A38.m() == C.m() && A38.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideA35 = A35.stride();
    const int strideA36 = A36.stride();
    const int strideA37 = A37.stride();
    const int strideA38 = A38.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    const Scalar *dataA35 = A35.data();
    const Scalar *dataA36 = A36.data();
    const Scalar *dataA37 = A37.data();
    const Scalar *dataA38 = A38.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            Scalar a35 = alpha35 * dataA35[i + j * strideA35];
            Scalar a36 = alpha36 * dataA36[i + j * strideA36];
            Scalar a37 = alpha37 * dataA37[i + j * strideA37];
            Scalar a38 = alpha38 * dataA38[i + j * strideA38];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34 + a35 + a36 + a37 + a38;
        }
    }
}


template <typename Scalar>
void Add(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38, Matrix<Scalar>& A39,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7, Scalar alpha8, Scalar alpha9, Scalar alpha10, Scalar alpha11, Scalar alpha12, Scalar alpha13, Scalar alpha14, Scalar alpha15, Scalar alpha16, Scalar alpha17, Scalar alpha18, Scalar alpha19, Scalar alpha20, Scalar alpha21, Scalar alpha22, Scalar alpha23, Scalar alpha24, Scalar alpha25, Scalar alpha26, Scalar alpha27, Scalar alpha28, Scalar alpha29, Scalar alpha30, Scalar alpha31, Scalar alpha32, Scalar alpha33, Scalar alpha34, Scalar alpha35, Scalar alpha36, Scalar alpha37, Scalar alpha38, Scalar alpha39,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());
    assert(A8.m() == C.m() && A8.n() == C.n());
    assert(A9.m() == C.m() && A9.n() == C.n());
    assert(A10.m() == C.m() && A10.n() == C.n());
    assert(A11.m() == C.m() && A11.n() == C.n());
    assert(A12.m() == C.m() && A12.n() == C.n());
    assert(A13.m() == C.m() && A13.n() == C.n());
    assert(A14.m() == C.m() && A14.n() == C.n());
    assert(A15.m() == C.m() && A15.n() == C.n());
    assert(A16.m() == C.m() && A16.n() == C.n());
    assert(A17.m() == C.m() && A17.n() == C.n());
    assert(A18.m() == C.m() && A18.n() == C.n());
    assert(A19.m() == C.m() && A19.n() == C.n());
    assert(A20.m() == C.m() && A20.n() == C.n());
    assert(A21.m() == C.m() && A21.n() == C.n());
    assert(A22.m() == C.m() && A22.n() == C.n());
    assert(A23.m() == C.m() && A23.n() == C.n());
    assert(A24.m() == C.m() && A24.n() == C.n());
    assert(A25.m() == C.m() && A25.n() == C.n());
    assert(A26.m() == C.m() && A26.n() == C.n());
    assert(A27.m() == C.m() && A27.n() == C.n());
    assert(A28.m() == C.m() && A28.n() == C.n());
    assert(A29.m() == C.m() && A29.n() == C.n());
    assert(A30.m() == C.m() && A30.n() == C.n());
    assert(A31.m() == C.m() && A31.n() == C.n());
    assert(A32.m() == C.m() && A32.n() == C.n());
    assert(A33.m() == C.m() && A33.n() == C.n());
    assert(A34.m() == C.m() && A34.n() == C.n());
    assert(A35.m() == C.m() && A35.n() == C.n());
    assert(A36.m() == C.m() && A36.n() == C.n());
    assert(A37.m() == C.m() && A37.n() == C.n());
    assert(A38.m() == C.m() && A38.n() == C.n());
    assert(A39.m() == C.m() && A39.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideA4 = A4.stride();
    const int strideA5 = A5.stride();
    const int strideA6 = A6.stride();
    const int strideA7 = A7.stride();
    const int strideA8 = A8.stride();
    const int strideA9 = A9.stride();
    const int strideA10 = A10.stride();
    const int strideA11 = A11.stride();
    const int strideA12 = A12.stride();
    const int strideA13 = A13.stride();
    const int strideA14 = A14.stride();
    const int strideA15 = A15.stride();
    const int strideA16 = A16.stride();
    const int strideA17 = A17.stride();
    const int strideA18 = A18.stride();
    const int strideA19 = A19.stride();
    const int strideA20 = A20.stride();
    const int strideA21 = A21.stride();
    const int strideA22 = A22.stride();
    const int strideA23 = A23.stride();
    const int strideA24 = A24.stride();
    const int strideA25 = A25.stride();
    const int strideA26 = A26.stride();
    const int strideA27 = A27.stride();
    const int strideA28 = A28.stride();
    const int strideA29 = A29.stride();
    const int strideA30 = A30.stride();
    const int strideA31 = A31.stride();
    const int strideA32 = A32.stride();
    const int strideA33 = A33.stride();
    const int strideA34 = A34.stride();
    const int strideA35 = A35.stride();
    const int strideA36 = A36.stride();
    const int strideA37 = A37.stride();
    const int strideA38 = A38.stride();
    const int strideA39 = A39.stride();
    const int strideC = C.stride();

    const Scalar *dataA1 = A1.data();
    const Scalar *dataA2 = A2.data();
    const Scalar *dataA3 = A3.data();
    const Scalar *dataA4 = A4.data();
    const Scalar *dataA5 = A5.data();
    const Scalar *dataA6 = A6.data();
    const Scalar *dataA7 = A7.data();
    const Scalar *dataA8 = A8.data();
    const Scalar *dataA9 = A9.data();
    const Scalar *dataA10 = A10.data();
    const Scalar *dataA11 = A11.data();
    const Scalar *dataA12 = A12.data();
    const Scalar *dataA13 = A13.data();
    const Scalar *dataA14 = A14.data();
    const Scalar *dataA15 = A15.data();
    const Scalar *dataA16 = A16.data();
    const Scalar *dataA17 = A17.data();
    const Scalar *dataA18 = A18.data();
    const Scalar *dataA19 = A19.data();
    const Scalar *dataA20 = A20.data();
    const Scalar *dataA21 = A21.data();
    const Scalar *dataA22 = A22.data();
    const Scalar *dataA23 = A23.data();
    const Scalar *dataA24 = A24.data();
    const Scalar *dataA25 = A25.data();
    const Scalar *dataA26 = A26.data();
    const Scalar *dataA27 = A27.data();
    const Scalar *dataA28 = A28.data();
    const Scalar *dataA29 = A29.data();
    const Scalar *dataA30 = A30.data();
    const Scalar *dataA31 = A31.data();
    const Scalar *dataA32 = A32.data();
    const Scalar *dataA33 = A33.data();
    const Scalar *dataA34 = A34.data();
    const Scalar *dataA35 = A35.data();
    const Scalar *dataA36 = A36.data();
    const Scalar *dataA37 = A37.data();
    const Scalar *dataA38 = A38.data();
    const Scalar *dataA39 = A39.data();
    Scalar *dataC = C.data();

#ifdef _OPEN_MP_ADDS_
# pragma omp parallel for collapse(2)
#endif
    for (int j = 0; j < C.n(); ++j) {
        for (int i = 0; i < C.m(); ++i) {
            Scalar a1 = alpha1 * dataA1[i + j * strideA1];
            Scalar a2 = alpha2 * dataA2[i + j * strideA2];
            Scalar a3 = alpha3 * dataA3[i + j * strideA3];
            Scalar a4 = alpha4 * dataA4[i + j * strideA4];
            Scalar a5 = alpha5 * dataA5[i + j * strideA5];
            Scalar a6 = alpha6 * dataA6[i + j * strideA6];
            Scalar a7 = alpha7 * dataA7[i + j * strideA7];
            Scalar a8 = alpha8 * dataA8[i + j * strideA8];
            Scalar a9 = alpha9 * dataA9[i + j * strideA9];
            Scalar a10 = alpha10 * dataA10[i + j * strideA10];
            Scalar a11 = alpha11 * dataA11[i + j * strideA11];
            Scalar a12 = alpha12 * dataA12[i + j * strideA12];
            Scalar a13 = alpha13 * dataA13[i + j * strideA13];
            Scalar a14 = alpha14 * dataA14[i + j * strideA14];
            Scalar a15 = alpha15 * dataA15[i + j * strideA15];
            Scalar a16 = alpha16 * dataA16[i + j * strideA16];
            Scalar a17 = alpha17 * dataA17[i + j * strideA17];
            Scalar a18 = alpha18 * dataA18[i + j * strideA18];
            Scalar a19 = alpha19 * dataA19[i + j * strideA19];
            Scalar a20 = alpha20 * dataA20[i + j * strideA20];
            Scalar a21 = alpha21 * dataA21[i + j * strideA21];
            Scalar a22 = alpha22 * dataA22[i + j * strideA22];
            Scalar a23 = alpha23 * dataA23[i + j * strideA23];
            Scalar a24 = alpha24 * dataA24[i + j * strideA24];
            Scalar a25 = alpha25 * dataA25[i + j * strideA25];
            Scalar a26 = alpha26 * dataA26[i + j * strideA26];
            Scalar a27 = alpha27 * dataA27[i + j * strideA27];
            Scalar a28 = alpha28 * dataA28[i + j * strideA28];
            Scalar a29 = alpha29 * dataA29[i + j * strideA29];
            Scalar a30 = alpha30 * dataA30[i + j * strideA30];
            Scalar a31 = alpha31 * dataA31[i + j * strideA31];
            Scalar a32 = alpha32 * dataA32[i + j * strideA32];
            Scalar a33 = alpha33 * dataA33[i + j * strideA33];
            Scalar a34 = alpha34 * dataA34[i + j * strideA34];
            Scalar a35 = alpha35 * dataA35[i + j * strideA35];
            Scalar a36 = alpha36 * dataA36[i + j * strideA36];
            Scalar a37 = alpha37 * dataA37[i + j * strideA37];
            Scalar a38 = alpha38 * dataA38[i + j * strideA38];
            Scalar a39 = alpha39 * dataA39[i + j * strideA39];
            dataC[i + j * strideC] = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15 + a16 + a17 + a18 + a19 + a20 + a21 + a22 + a23 + a24 + a25 + a26 + a27 + a28 + a29 + a30 + a31 + a32 + a33 + a34 + a35 + a36 + a37 + a38 + a39;
        }
    }
}



#endif  // _ALL_ADDS_HPP_
