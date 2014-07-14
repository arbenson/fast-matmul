#ifndef _grey433_29_234_HPP_
#define _grey433_29_234_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey433_29_234 {

template <typename Scalar>
void FastMatmulRecursive(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
    // Update multipliers
    C.UpdateMultiplier(A.multiplier());
    C.UpdateMultiplier(B.multiplier());
    A.UpdateMultiplier(Scalar(1.0));
    B.UpdateMultiplier(Scalar(1.0));
    // Base case for recursion
    if (numsteps == 0) {
        Gemm(A, B, C);
        return;
    }

    int A_row_step = A.m() / 4;
    int A_col_step = A.n() / 3;
    Matrix<Scalar> A11 = A.Subblock(4, 3, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(4, 3, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(4, 3, 1, 3);
    Matrix<Scalar> A21 = A.Subblock(4, 3, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(4, 3, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(4, 3, 2, 3);
    Matrix<Scalar> A31 = A.Subblock(4, 3, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(4, 3, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(4, 3, 3, 3);
    Matrix<Scalar> A41 = A.Subblock(4, 3, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(4, 3, 4, 2);
    Matrix<Scalar> A43 = A.Subblock(4, 3, 4, 3);
    int B_row_step = B.m() / 3;
    int B_col_step = B.n() / 3;
    Matrix<Scalar> B11 = B.Subblock(3, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(3, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(3, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(3, 3, 2, 3);
    Matrix<Scalar> B31 = B.Subblock(3, 3, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 3, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(3, 3, 3, 3);
    int C_row_step = C.m() / 4;
    int C_col_step = C.n() / 3;
    Matrix<Scalar> C11 = C.Subblock(4, 3, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 3, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(4, 3, 1, 3);
    Matrix<Scalar> C21 = C.Subblock(4, 3, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 3, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(4, 3, 2, 3);
    Matrix<Scalar> C31 = C.Subblock(4, 3, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 3, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(4, 3, 3, 3);
    Matrix<Scalar> C41 = C.Subblock(4, 3, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 3, 4, 2);
    Matrix<Scalar> C43 = C.Subblock(4, 3, 4, 3);


    // These are the intermediate matrices.
    // We define them here so that they can be used
    // inside the lambda functions for Cilk.
    Matrix<Scalar> M1(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M2(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M3(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M4(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M5(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M6(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M7(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M8(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M9(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M10(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M11(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M12(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M13(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M14(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M15(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M16(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M17(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M18(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M19(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M20(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M21(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M22(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M23(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M24(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M25(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M26(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M27(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M28(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M29(C_row_step, C_col_step, C.multiplier());


    // M1 = (1.0 * A11) * (1.0 * B11 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T1(B11.m(), B11.n());
    Add(B11, B31, Scalar(1.0), Scalar(1.0), T1);
    FastMatmulRecursive(A11, T1, M1, numsteps - 1, x);
    T1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A21) * (-1.0 * B12 + 1.0 * B13 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B12, B13, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T2);
    FastMatmulRecursive(A21, T2, M2, numsteps - 1, x);
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A23 + 1.0 * A33) * (-1.0 * B13 + -1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    Add(A23, A33, Scalar(1.0), Scalar(1.0), S3);
    Matrix<Scalar> T3(B11.m(), B11.n());
    Add(B13, B33, Scalar(-1.0), Scalar(-1.0), T3);
    FastMatmulRecursive(S3, T3, M3, numsteps - 1, x);
    S3.deallocate();
    T3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A41) * (-1.0 * B11 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B11, B13, Scalar(-1.0), Scalar(1.0), T4);
    FastMatmulRecursive(A41, T4, M4, numsteps - 1, x);
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A12) * (1.0 * B21 + -1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B21, B31, Scalar(1.0), Scalar(-1.0), T5);
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A12, T5, M5, numsteps - 1, x);
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A23 + -1.0 * A33 + -1.0 * A41) * (1.0 * B13 + -1.0 * B32 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A23, A33, A41, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B13, B32, B33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A13 + 1.0 * A33 + 1.0 * A43) * (1.0 * B21 + -1.0 * B22 + -1.0 * B23 + -1.0 * B31 + 1.0 * B32 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A13, A33, A43, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B21, B22, B23, B31, B32, B33, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A13 + 1.0 * A31 + -1.0 * A32 + -1.0 * A33 + 1.0 * A41 + -1.0 * A42 + -1.0 * A43) * (-1.0 * B21 + 1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A11, A12, A13, A31, A32, A33, A41, A42, A43, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S8);
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T8);
    FastMatmulRecursive(S8, T8, M8, numsteps - 1, x);
    S8.deallocate();
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A22 + 1.0 * A32) * (1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A22, A32, Scalar(1.0), Scalar(1.0), S9);
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), T9);
    FastMatmulRecursive(S9, T9, M9, numsteps - 1, x);
    S9.deallocate();
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-1.0 * A21 + 1.0 * A22 + 1.0 * A42) * (-1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A21, A22, A42, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A13 + -1.0 * A33 + -1.0 * A42 + -1.0 * A43) * (1.0 * B21 + -1.0 * B22 + -1.0 * B23 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A13, A33, A42, A43, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S11);
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B21, B22, B23, B32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T11);
    FastMatmulRecursive(S11, T11, M11, numsteps - 1, x);
    S11.deallocate();
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A11 + 1.0 * A23 + 1.0 * A33) * (1.0 * B13 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A11, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S12);
    Matrix<Scalar> T12(B11.m(), B11.n());
    Add(B13, B31, Scalar(1.0), Scalar(1.0), T12);
    FastMatmulRecursive(S12, T12, M12, numsteps - 1, x);
    S12.deallocate();
    T12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A11 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + 1.0 * A41) * (1.0 * B12 + -1.0 * B21 + 1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A11, A22, A31, A32, A41, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S13);
    Matrix<Scalar> T13(B11.m(), B11.n());
    Add(B12, B21, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), T13);
    FastMatmulRecursive(S13, T13, M13, numsteps - 1, x);
    S13.deallocate();
    T13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A13 + 1.0 * A33) * (1.0 * B31 + -1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A13, A33, Scalar(-1.0), Scalar(1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B31, B33, Scalar(1.0), Scalar(-1.0), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A21) * (1.0 * B11 + -1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T15(B11.m(), B11.n());
    Add(B11, B13, Scalar(1.0), Scalar(-1.0), T15);
    FastMatmulRecursive(A21, T15, M15, numsteps - 1, x);
    T15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A21 + -1.0 * A22 + -1.0 * A32) * (-1.0 * B12 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A21, A22, A32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B12, B22, B23, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A23) * (1.0 * B23 + -1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B23, B33, Scalar(1.0), Scalar(-1.0), T17);
    FastMatmulRecursive(A23, T17, M17, numsteps - 1, x);
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (-1.0 * A23 + 1.0 * A41 + -1.0 * A43) * (1.0 * B32 + -1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A23, A41, A43, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B32, B33, Scalar(1.0), Scalar(-1.0), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A12 + -1.0 * A22) * (-1.0 * B21 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A12, A22, Scalar(-1.0), Scalar(-1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B21, B23, Scalar(-1.0), Scalar(1.0), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A11 + -1.0 * A31 + -1.0 * A41) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B13 + -1.0 * B21 + 1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A11, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), T20);
    FastMatmulRecursive(S20, T20, M20, numsteps - 1, x);
    S20.deallocate();
    T20.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (1.0 * A12 + -1.0 * A23) * (1.0 * B23 + -1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S21(A11.m(), A11.n());
    Add(A12, A23, Scalar(1.0), Scalar(-1.0), S21);
    Matrix<Scalar> T21(B11.m(), B11.n());
    Add(B23, B31, Scalar(1.0), Scalar(-1.0), T21);
    FastMatmulRecursive(S21, T21, M21, numsteps - 1, x);
    S21.deallocate();
    T21.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (1.0 * A23 + 1.0 * A33 + 1.0 * A42 + 1.0 * A43) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S22(A11.m(), A11.n());
    Add(A23, A33, A42, A43, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S22);
    FastMatmulRecursive(S22, B32, M22, numsteps - 1, x);
    S22.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A42) * (1.0 * B22 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T23(B11.m(), B11.n());
    Add(B22, B32, Scalar(1.0), Scalar(-1.0), T23);
    FastMatmulRecursive(A42, T23, M23, numsteps - 1, x);
    T23.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (1.0 * A23 + -1.0 * A31 + 1.0 * A33) * (1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S24(A11.m(), A11.n());
    Add(A23, A31, A33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), S24);
    FastMatmulRecursive(S24, B13, M24, numsteps - 1, x);
    S24.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-1.0 * A41) * (-1.0 * B12 + 1.0 * B13 + -1.0 * B32 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T25(B11.m(), B11.n());
    Add(B12, B13, B32, B33, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T25);
    M25.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A41, T25, M25, numsteps - 1, x);
    T25.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (1.0 * A11 + -1.0 * A12 + -1.0 * A13) * (-1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S26(A11.m(), A11.n());
    Add(A11, A12, A13, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S26);
    M26.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S26, B31, M26, numsteps - 1, x);
    S26.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M27 = (1.0 * A21 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + 1.0 * A41) * (-1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S27(A11.m(), A11.n());
    Add(A21, A22, A31, A32, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S27);
    M27.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S27, B12, M27, numsteps - 1, x);
    S27.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M28 = (-1.0 * A23 + 1.0 * A32) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S28(A11.m(), A11.n());
    Add(A23, A32, Scalar(-1.0), Scalar(1.0), S28);
    FastMatmulRecursive(S28, B23, M28, numsteps - 1, x);
    S28.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M29 = (1.0 * A23 + -1.0 * A42) * (1.0 * B23 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S29(A11.m(), A11.n());
    Add(A23, A42, Scalar(1.0), Scalar(-1.0), S29);
    Matrix<Scalar> T29(B11.m(), B11.n());
    Add(B23, B32, Scalar(1.0), Scalar(-1.0), T29);
    FastMatmulRecursive(S29, T29, M29, numsteps - 1, x);
    S29.deallocate();
    T29.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

#ifdef _CILK_
    cilk_sync;
#elif defined _OPEN_MP_
        # pragma omp taskwait
#endif


    Add(M1, M5, M26, Scalar(1.0), Scalar(-1.0), Scalar(1.0), C11);
    Add(M8, M9, M10, M11, M13, M16, M19, M22, M23, M27, M28, M29, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M3, M12, M14, M17, M21, M26, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C13);
    Add(M2, M5, M9, M15, M16, M19, M21, M28, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C21);
    Add(M9, M10, M16, M23, M28, M29, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C22);
    Add(M2, M9, M16, M17, M28, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C23);
    Add(M1, M4, M5, M9, M12, M13, M19, M20, M21, M24, M28, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C31);
    Add(M3, M6, M10, M16, M23, M25, M27, M28, M29, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M3, M17, M24, M28, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C33);
    Add(M3, M4, M6, M7, M11, M14, M17, M18, M22, M23, M29, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C41);
    Add(M3, M6, M22, M23, M25, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C42);
    Add(M3, M6, M17, M18, M22, M29, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C43);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 4, 3, 3);
}

template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
#ifdef _OPEN_MP_
# pragma omp parallel
    {
# pragma omp single
#endif
        FastMatmulRecursive(A, B, C, numsteps, x);
#ifdef _OPEN_MP_
    }
#endif
}

}  // namespace grey433_29_234

#endif  // _grey433_29_234_HPP_
