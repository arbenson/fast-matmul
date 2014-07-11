#ifndef _ALL_SLOW_ADDS_HPP_
#define _ALL_SLOW_ADDS_HPP_

template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1,
         Scalar alpha1,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());

    Add(A1, alpha1, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2,
         Scalar alpha1, Scalar alpha2,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7,
         Scalar alpha1, Scalar alpha2, Scalar alpha3, Scalar alpha4, Scalar alpha5, Scalar alpha6, Scalar alpha7,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());
    assert(A4.m() == C.m() && A4.n() == C.n());
    assert(A5.m() == C.m() && A5.n() == C.n());
    assert(A6.m() == C.m() && A6.n() == C.n());
    assert(A7.m() == C.m() && A7.n() == C.n());

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
    Add(A21, C, alpha21, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
    Add(A21, C, alpha21, Scalar(1.0), C);
    Add(A22, C, alpha22, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
    Add(A21, C, alpha21, Scalar(1.0), C);
    Add(A22, C, alpha22, Scalar(1.0), C);
    Add(A23, C, alpha23, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
    Add(A21, C, alpha21, Scalar(1.0), C);
    Add(A22, C, alpha22, Scalar(1.0), C);
    Add(A23, C, alpha23, Scalar(1.0), C);
    Add(A24, C, alpha24, Scalar(1.0), C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25,
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

    Add(A1, alpha1, C);
    Add(A2, C, alpha2, Scalar(1.0), C);
    Add(A3, C, alpha3, Scalar(1.0), C);
    Add(A4, C, alpha4, Scalar(1.0), C);
    Add(A5, C, alpha5, Scalar(1.0), C);
    Add(A6, C, alpha6, Scalar(1.0), C);
    Add(A7, C, alpha7, Scalar(1.0), C);
    Add(A8, C, alpha8, Scalar(1.0), C);
    Add(A9, C, alpha9, Scalar(1.0), C);
    Add(A10, C, alpha10, Scalar(1.0), C);
    Add(A11, C, alpha11, Scalar(1.0), C);
    Add(A12, C, alpha12, Scalar(1.0), C);
    Add(A13, C, alpha13, Scalar(1.0), C);
    Add(A14, C, alpha14, Scalar(1.0), C);
    Add(A15, C, alpha15, Scalar(1.0), C);
    Add(A16, C, alpha16, Scalar(1.0), C);
    Add(A17, C, alpha17, Scalar(1.0), C);
    Add(A18, C, alpha18, Scalar(1.0), C);
    Add(A19, C, alpha19, Scalar(1.0), C);
    Add(A20, C, alpha20, Scalar(1.0), C);
    Add(A21, C, alpha21, Scalar(1.0), C);
    Add(A22, C, alpha22, Scalar(1.0), C);
    Add(A23, C, alpha23, Scalar(1.0), C);
    Add(A24, C, alpha24, Scalar(1.0), C);
    Add(A25, C, alpha25, Scalar(1.0), C);
}



#endif  // _ALL_ADDS_HPP_
