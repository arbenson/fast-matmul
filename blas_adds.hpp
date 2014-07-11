#ifndef _ALL_BLAS_ADDS_HPP_
#define _ALL_BLAS_ADDS_HPP_


// C <-- alpha * A + C
//template <typename Scalar>
void AxpyWrap(double *C, double *A, int n, double alpha) {
  int incx = 1;
  int incy = 1;
  daxpy_(&n, &alpha, A, &incx, C, &incy);
}

// C <-- alpha * A + C
//template <typename Scalar>
void AxpyWrap(float *C, float *A, int n, float alpha) {
  int incx = 1;
  int incy = 1;
  saxpy_(&n, &alpha, A, &incx, C, &incy);
}

template<typename Scalar>
void Axpy(Scalar *C, Scalar *A, int n, Scalar alpha) {
  AxpyWrap(C, A, n, alpha);
}

template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1,
         Scalar alpha1,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideC = C.stride();

    Scalar *dataA1 = A1.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2,
         Scalar alpha1, Scalar alpha2,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideC = C.stride();

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());

    const int strideA1 = A1.stride();
    const int strideA2 = A2.stride();
    const int strideA3 = A3.stride();
    const int strideC = C.stride();

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataA35 = A35.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
        Scalar *a35 = dataA35 + j * strideA35;
        Axpy(c, a35, C.m(), alpha35);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataA35 = A35.data();
    Scalar *dataA36 = A36.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
        Scalar *a35 = dataA35 + j * strideA35;
        Axpy(c, a35, C.m(), alpha35);
        Scalar *a36 = dataA36 + j * strideA36;
        Axpy(c, a36, C.m(), alpha36);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataA35 = A35.data();
    Scalar *dataA36 = A36.data();
    Scalar *dataA37 = A37.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
        Scalar *a35 = dataA35 + j * strideA35;
        Axpy(c, a35, C.m(), alpha35);
        Scalar *a36 = dataA36 + j * strideA36;
        Axpy(c, a36, C.m(), alpha36);
        Scalar *a37 = dataA37 + j * strideA37;
        Axpy(c, a37, C.m(), alpha37);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataA35 = A35.data();
    Scalar *dataA36 = A36.data();
    Scalar *dataA37 = A37.data();
    Scalar *dataA38 = A38.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
        Scalar *a35 = dataA35 + j * strideA35;
        Axpy(c, a35, C.m(), alpha35);
        Scalar *a36 = dataA36 + j * strideA36;
        Axpy(c, a36, C.m(), alpha36);
        Scalar *a37 = dataA37 + j * strideA37;
        Axpy(c, a37, C.m(), alpha37);
        Scalar *a38 = dataA38 + j * strideA38;
        Axpy(c, a38, C.m(), alpha38);
    }
}


template <typename Scalar>
void BlasAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38, Matrix<Scalar>& A39,
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

    Scalar *dataA1 = A1.data();
    Scalar *dataA2 = A2.data();
    Scalar *dataA3 = A3.data();
    Scalar *dataA4 = A4.data();
    Scalar *dataA5 = A5.data();
    Scalar *dataA6 = A6.data();
    Scalar *dataA7 = A7.data();
    Scalar *dataA8 = A8.data();
    Scalar *dataA9 = A9.data();
    Scalar *dataA10 = A10.data();
    Scalar *dataA11 = A11.data();
    Scalar *dataA12 = A12.data();
    Scalar *dataA13 = A13.data();
    Scalar *dataA14 = A14.data();
    Scalar *dataA15 = A15.data();
    Scalar *dataA16 = A16.data();
    Scalar *dataA17 = A17.data();
    Scalar *dataA18 = A18.data();
    Scalar *dataA19 = A19.data();
    Scalar *dataA20 = A20.data();
    Scalar *dataA21 = A21.data();
    Scalar *dataA22 = A22.data();
    Scalar *dataA23 = A23.data();
    Scalar *dataA24 = A24.data();
    Scalar *dataA25 = A25.data();
    Scalar *dataA26 = A26.data();
    Scalar *dataA27 = A27.data();
    Scalar *dataA28 = A28.data();
    Scalar *dataA29 = A29.data();
    Scalar *dataA30 = A30.data();
    Scalar *dataA31 = A31.data();
    Scalar *dataA32 = A32.data();
    Scalar *dataA33 = A33.data();
    Scalar *dataA34 = A34.data();
    Scalar *dataA35 = A35.data();
    Scalar *dataA36 = A36.data();
    Scalar *dataA37 = A37.data();
    Scalar *dataA38 = A38.data();
    Scalar *dataA39 = A39.data();
    Scalar *dataC = C.data();

    Scalar *c = 0;
    for (int j = 0; j < C.n(); ++j) {
        c = dataC + j * strideC;
        Scalar *a1 = dataA1 + j * strideA1;
        Axpy(c, a1, C.m(), alpha1);
        Scalar *a2 = dataA2 + j * strideA2;
        Axpy(c, a2, C.m(), alpha2);
        Scalar *a3 = dataA3 + j * strideA3;
        Axpy(c, a3, C.m(), alpha3);
        Scalar *a4 = dataA4 + j * strideA4;
        Axpy(c, a4, C.m(), alpha4);
        Scalar *a5 = dataA5 + j * strideA5;
        Axpy(c, a5, C.m(), alpha5);
        Scalar *a6 = dataA6 + j * strideA6;
        Axpy(c, a6, C.m(), alpha6);
        Scalar *a7 = dataA7 + j * strideA7;
        Axpy(c, a7, C.m(), alpha7);
        Scalar *a8 = dataA8 + j * strideA8;
        Axpy(c, a8, C.m(), alpha8);
        Scalar *a9 = dataA9 + j * strideA9;
        Axpy(c, a9, C.m(), alpha9);
        Scalar *a10 = dataA10 + j * strideA10;
        Axpy(c, a10, C.m(), alpha10);
        Scalar *a11 = dataA11 + j * strideA11;
        Axpy(c, a11, C.m(), alpha11);
        Scalar *a12 = dataA12 + j * strideA12;
        Axpy(c, a12, C.m(), alpha12);
        Scalar *a13 = dataA13 + j * strideA13;
        Axpy(c, a13, C.m(), alpha13);
        Scalar *a14 = dataA14 + j * strideA14;
        Axpy(c, a14, C.m(), alpha14);
        Scalar *a15 = dataA15 + j * strideA15;
        Axpy(c, a15, C.m(), alpha15);
        Scalar *a16 = dataA16 + j * strideA16;
        Axpy(c, a16, C.m(), alpha16);
        Scalar *a17 = dataA17 + j * strideA17;
        Axpy(c, a17, C.m(), alpha17);
        Scalar *a18 = dataA18 + j * strideA18;
        Axpy(c, a18, C.m(), alpha18);
        Scalar *a19 = dataA19 + j * strideA19;
        Axpy(c, a19, C.m(), alpha19);
        Scalar *a20 = dataA20 + j * strideA20;
        Axpy(c, a20, C.m(), alpha20);
        Scalar *a21 = dataA21 + j * strideA21;
        Axpy(c, a21, C.m(), alpha21);
        Scalar *a22 = dataA22 + j * strideA22;
        Axpy(c, a22, C.m(), alpha22);
        Scalar *a23 = dataA23 + j * strideA23;
        Axpy(c, a23, C.m(), alpha23);
        Scalar *a24 = dataA24 + j * strideA24;
        Axpy(c, a24, C.m(), alpha24);
        Scalar *a25 = dataA25 + j * strideA25;
        Axpy(c, a25, C.m(), alpha25);
        Scalar *a26 = dataA26 + j * strideA26;
        Axpy(c, a26, C.m(), alpha26);
        Scalar *a27 = dataA27 + j * strideA27;
        Axpy(c, a27, C.m(), alpha27);
        Scalar *a28 = dataA28 + j * strideA28;
        Axpy(c, a28, C.m(), alpha28);
        Scalar *a29 = dataA29 + j * strideA29;
        Axpy(c, a29, C.m(), alpha29);
        Scalar *a30 = dataA30 + j * strideA30;
        Axpy(c, a30, C.m(), alpha30);
        Scalar *a31 = dataA31 + j * strideA31;
        Axpy(c, a31, C.m(), alpha31);
        Scalar *a32 = dataA32 + j * strideA32;
        Axpy(c, a32, C.m(), alpha32);
        Scalar *a33 = dataA33 + j * strideA33;
        Axpy(c, a33, C.m(), alpha33);
        Scalar *a34 = dataA34 + j * strideA34;
        Axpy(c, a34, C.m(), alpha34);
        Scalar *a35 = dataA35 + j * strideA35;
        Axpy(c, a35, C.m(), alpha35);
        Scalar *a36 = dataA36 + j * strideA36;
        Axpy(c, a36, C.m(), alpha36);
        Scalar *a37 = dataA37 + j * strideA37;
        Axpy(c, a37, C.m(), alpha37);
        Scalar *a38 = dataA38 + j * strideA38;
        Axpy(c, a38, C.m(), alpha38);
        Scalar *a39 = dataA39 + j * strideA39;
        Axpy(c, a39, C.m(), alpha39);
    }
}



#endif  // _ALL_ADDS_HPP_
