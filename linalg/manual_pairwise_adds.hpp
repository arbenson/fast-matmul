#ifndef _ALL_SLOW_ADDS_HPP_
#define _ALL_SLOW_ADDS_HPP_

#include "all_at_once_adds.hpp"
#include "linalg.hpp"

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
    UpdateAdd(A2, alpha2, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3,
         Scalar alpha1, Scalar alpha2, Scalar alpha3,
         Matrix<Scalar>& C) {
    assert(A1.m() == C.m() && A1.n() == C.n());
    assert(A2.m() == C.m() && A2.n() == C.n());
    assert(A3.m() == C.m() && A3.n() == C.n());

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
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
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
    UpdateAdd(A35, alpha35, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
    UpdateAdd(A35, alpha35, C);
    UpdateAdd(A36, alpha36, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
    UpdateAdd(A35, alpha35, C);
    UpdateAdd(A36, alpha36, C);
    UpdateAdd(A37, alpha37, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
    UpdateAdd(A35, alpha35, C);
    UpdateAdd(A36, alpha36, C);
    UpdateAdd(A37, alpha37, C);
    UpdateAdd(A38, alpha38, C);
}


template <typename Scalar>
void SlowAdd(Matrix<Scalar>& A1, Matrix<Scalar>& A2, Matrix<Scalar>& A3, Matrix<Scalar>& A4, Matrix<Scalar>& A5, Matrix<Scalar>& A6, Matrix<Scalar>& A7, Matrix<Scalar>& A8, Matrix<Scalar>& A9, Matrix<Scalar>& A10, Matrix<Scalar>& A11, Matrix<Scalar>& A12, Matrix<Scalar>& A13, Matrix<Scalar>& A14, Matrix<Scalar>& A15, Matrix<Scalar>& A16, Matrix<Scalar>& A17, Matrix<Scalar>& A18, Matrix<Scalar>& A19, Matrix<Scalar>& A20, Matrix<Scalar>& A21, Matrix<Scalar>& A22, Matrix<Scalar>& A23, Matrix<Scalar>& A24, Matrix<Scalar>& A25, Matrix<Scalar>& A26, Matrix<Scalar>& A27, Matrix<Scalar>& A28, Matrix<Scalar>& A29, Matrix<Scalar>& A30, Matrix<Scalar>& A31, Matrix<Scalar>& A32, Matrix<Scalar>& A33, Matrix<Scalar>& A34, Matrix<Scalar>& A35, Matrix<Scalar>& A36, Matrix<Scalar>& A37, Matrix<Scalar>& A38, Matrix<Scalar>& A39,
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

    Add(A1, alpha1, C);
    UpdateAdd(A2, alpha2, C);
    UpdateAdd(A3, alpha3, C);
    UpdateAdd(A4, alpha4, C);
    UpdateAdd(A5, alpha5, C);
    UpdateAdd(A6, alpha6, C);
    UpdateAdd(A7, alpha7, C);
    UpdateAdd(A8, alpha8, C);
    UpdateAdd(A9, alpha9, C);
    UpdateAdd(A10, alpha10, C);
    UpdateAdd(A11, alpha11, C);
    UpdateAdd(A12, alpha12, C);
    UpdateAdd(A13, alpha13, C);
    UpdateAdd(A14, alpha14, C);
    UpdateAdd(A15, alpha15, C);
    UpdateAdd(A16, alpha16, C);
    UpdateAdd(A17, alpha17, C);
    UpdateAdd(A18, alpha18, C);
    UpdateAdd(A19, alpha19, C);
    UpdateAdd(A20, alpha20, C);
    UpdateAdd(A21, alpha21, C);
    UpdateAdd(A22, alpha22, C);
    UpdateAdd(A23, alpha23, C);
    UpdateAdd(A24, alpha24, C);
    UpdateAdd(A25, alpha25, C);
    UpdateAdd(A26, alpha26, C);
    UpdateAdd(A27, alpha27, C);
    UpdateAdd(A28, alpha28, C);
    UpdateAdd(A29, alpha29, C);
    UpdateAdd(A30, alpha30, C);
    UpdateAdd(A31, alpha31, C);
    UpdateAdd(A32, alpha32, C);
    UpdateAdd(A33, alpha33, C);
    UpdateAdd(A34, alpha34, C);
    UpdateAdd(A35, alpha35, C);
    UpdateAdd(A36, alpha36, C);
    UpdateAdd(A37, alpha37, C);
    UpdateAdd(A38, alpha38, C);
    UpdateAdd(A39, alpha39, C);
}



#endif  // _ALL_ADDS_HPP_
