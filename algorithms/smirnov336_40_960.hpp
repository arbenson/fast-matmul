#ifndef _smirnov336_40_960_HPP_
#define _smirnov336_40_960_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace smirnov336_40_960 {

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

    int A_row_step = A.m() / 3;
    int A_col_step = A.n() / 6;
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
    int B_row_step = B.m() / 6;
    int B_col_step = B.n() / 6;
    Matrix<Scalar> B11 = B.Subblock(6, 6, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(6, 6, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(6, 6, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(6, 6, 1, 4);
    Matrix<Scalar> B15 = B.Subblock(6, 6, 1, 5);
    Matrix<Scalar> B16 = B.Subblock(6, 6, 1, 6);
    Matrix<Scalar> B21 = B.Subblock(6, 6, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(6, 6, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(6, 6, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(6, 6, 2, 4);
    Matrix<Scalar> B25 = B.Subblock(6, 6, 2, 5);
    Matrix<Scalar> B26 = B.Subblock(6, 6, 2, 6);
    Matrix<Scalar> B31 = B.Subblock(6, 6, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(6, 6, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(6, 6, 3, 3);
    Matrix<Scalar> B34 = B.Subblock(6, 6, 3, 4);
    Matrix<Scalar> B35 = B.Subblock(6, 6, 3, 5);
    Matrix<Scalar> B36 = B.Subblock(6, 6, 3, 6);
    Matrix<Scalar> B41 = B.Subblock(6, 6, 4, 1);
    Matrix<Scalar> B42 = B.Subblock(6, 6, 4, 2);
    Matrix<Scalar> B43 = B.Subblock(6, 6, 4, 3);
    Matrix<Scalar> B44 = B.Subblock(6, 6, 4, 4);
    Matrix<Scalar> B45 = B.Subblock(6, 6, 4, 5);
    Matrix<Scalar> B46 = B.Subblock(6, 6, 4, 6);
    Matrix<Scalar> B51 = B.Subblock(6, 6, 5, 1);
    Matrix<Scalar> B52 = B.Subblock(6, 6, 5, 2);
    Matrix<Scalar> B53 = B.Subblock(6, 6, 5, 3);
    Matrix<Scalar> B54 = B.Subblock(6, 6, 5, 4);
    Matrix<Scalar> B55 = B.Subblock(6, 6, 5, 5);
    Matrix<Scalar> B56 = B.Subblock(6, 6, 5, 6);
    Matrix<Scalar> B61 = B.Subblock(6, 6, 6, 1);
    Matrix<Scalar> B62 = B.Subblock(6, 6, 6, 2);
    Matrix<Scalar> B63 = B.Subblock(6, 6, 6, 3);
    Matrix<Scalar> B64 = B.Subblock(6, 6, 6, 4);
    Matrix<Scalar> B65 = B.Subblock(6, 6, 6, 5);
    Matrix<Scalar> B66 = B.Subblock(6, 6, 6, 6);
    int C_row_step = C.m() / 3;
    int C_col_step = C.n() / 6;
    Matrix<Scalar> C11 = C.Subblock(3, 6, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(3, 6, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(3, 6, 1, 3);
    Matrix<Scalar> C14 = C.Subblock(3, 6, 1, 4);
    Matrix<Scalar> C15 = C.Subblock(3, 6, 1, 5);
    Matrix<Scalar> C16 = C.Subblock(3, 6, 1, 6);
    Matrix<Scalar> C21 = C.Subblock(3, 6, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(3, 6, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(3, 6, 2, 3);
    Matrix<Scalar> C24 = C.Subblock(3, 6, 2, 4);
    Matrix<Scalar> C25 = C.Subblock(3, 6, 2, 5);
    Matrix<Scalar> C26 = C.Subblock(3, 6, 2, 6);
    Matrix<Scalar> C31 = C.Subblock(3, 6, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(3, 6, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(3, 6, 3, 3);
    Matrix<Scalar> C34 = C.Subblock(3, 6, 3, 4);
    Matrix<Scalar> C35 = C.Subblock(3, 6, 3, 5);
    Matrix<Scalar> C36 = C.Subblock(3, 6, 3, 6);


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
    Matrix<Scalar> M30(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M31(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M32(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M33(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M34(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M35(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M36(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M37(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M38(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M39(C_row_step, C_col_step, C.multiplier());
    Matrix<Scalar> M40(C_row_step, C_col_step, C.multiplier());


    // M1 = (1.0 * A11 + 1.0 * A13 + 1.0 * A15 + 1.0 * A16 + -1.0 * A21 + 1.0 * A22) * (-0.125 * B12 + 1.0 * B15 + 0.125 * B16 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -1.0 * B31 + 0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S1);
    Matrix<Scalar> T1(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), T1);
    FastMatmulRecursive(S1, T1, M1, numsteps - 1, x);
    S1.deallocate();
    T1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A11 + -1.0 * A13 + 1.0 * A15 + -1.0 * A16 + -1.0 * A21 + 1.0 * A22) * (-0.125 * B13 + -0.125 * B14 + -1.0 * B15 + 0.125 * B22 + 1.0 * B25 + -0.125 * B26 + -1.0 * B31 + -0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A15 + -1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + 0.125 * B13 + -0.125 * B16 + -1.0 * B21 + 0.125 * B22 + 0.125 * B24 + -0.125 * B32 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S3);
    Matrix<Scalar> T3(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), T3);
    FastMatmulRecursive(S3, T3, M3, numsteps - 1, x);
    S3.deallocate();
    T3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A11 + 1.0 * A13 + -1.0 * A15 + -1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (-0.125 * B12 + -1.0 * B15 + -0.125 * B16 + -0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -1.0 * B31 + -0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A11 + 1.0 * A13 + 1.0 * A15 + -1.0 * A16 + -1.0 * A21 + -1.0 * A22) * (-0.125 * B13 + 0.125 * B14 + 1.0 * B15 + -0.125 * B22 + 1.0 * B25 + -0.125 * B26 + -1.0 * B31 + 0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S5);
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), T5);
    FastMatmulRecursive(S5, T5, M5, numsteps - 1, x);
    S5.deallocate();
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A15 + -1.0 * A16 + -1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B14 + 1.0 * B21 + 0.125 * B23 + 0.125 * B26 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A15 + 1.0 * A16 + -1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + 0.125 * B13 + 0.125 * B16 + 1.0 * B21 + -0.125 * B22 + 0.125 * B24 + -0.125 * B32 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A11 + 1.0 * A13 + 1.0 * A15 + -1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (0.125 * B12 + -1.0 * B15 + 0.125 * B16 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + 1.0 * B31 + -0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S8);
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(1.0), Scalar(-0.125), Scalar(0.125), T8);
    FastMatmulRecursive(S8, T8, M8, numsteps - 1, x);
    S8.deallocate();
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A15 + -1.0 * A16 + 1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + -0.125 * B13 + -0.125 * B16 + 1.0 * B21 + 0.125 * B22 + -0.125 * B24 + -0.125 * B32 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S9);
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), T9);
    FastMatmulRecursive(S9, T9, M9, numsteps - 1, x);
    S9.deallocate();
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A15 + 1.0 * A16 + 1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + 0.125 * B12 + -0.125 * B14 + 1.0 * B21 + -0.125 * B23 + -0.125 * B26 + -0.125 * B33 + -0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A11 + 1.0 * A13 + -1.0 * A15 + 1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + 0.125 * B12 + 0.125 * B14 + -1.0 * B21 + 0.125 * B23 + -0.125 * B26 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S11);
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), T11);
    FastMatmulRecursive(S11, T11, M11, numsteps - 1, x);
    S11.deallocate();
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A11 + 1.0 * A13 + 1.0 * A15 + 1.0 * A16 + 1.0 * A21 + -1.0 * A22) * (-0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B22 + -1.0 * B25 + -0.125 * B26 + -1.0 * B31 + 0.125 * B32 + -0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S12);
    Matrix<Scalar> T12(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), T12);
    FastMatmulRecursive(S12, T12, M12, numsteps - 1, x);
    S12.deallocate();
    T12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A11 + 1.0 * A13 + -1.0 * A15 + 1.0 * A16 + -1.0 * A21 + 1.0 * A22) * (-0.125 * B12 + -1.0 * B15 + 0.125 * B16 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + -1.0 * B31 + -0.125 * B33 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S13);
    Matrix<Scalar> T13(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), T13);
    FastMatmulRecursive(S13, T13, M13, numsteps - 1, x);
    S13.deallocate();
    T13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A15 + 1.0 * A16 + -1.0 * A21 + -1.0 * A22) * (1.0 * B11 + 0.125 * B13 + -0.125 * B16 + 1.0 * B21 + 0.125 * B22 + 0.125 * B24 + 0.125 * B32 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A15 + 1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (1.0 * B11 + 0.125 * B12 + 0.125 * B14 + 1.0 * B21 + 0.125 * B23 + -0.125 * B26 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S15);
    Matrix<Scalar> T15(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), T15);
    FastMatmulRecursive(S15, T15, M15, numsteps - 1, x);
    S15.deallocate();
    T15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A11 + -1.0 * A13 + 1.0 * A15 + 1.0 * A16 + 1.0 * A21 + 1.0 * A22) * (0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B22 + 1.0 * B25 + 0.125 * B26 + 1.0 * B31 + 0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A11, A13, A15, A16, A21, A22, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A14 + -1.0 * A15 + -1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B13 + -0.125 * B14 + 1.0 * B15 + -0.125 * B16 + -1.0 * B21 + 1.0 * B25 + 0.125 * B34 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S17(A11.m(), A11.n());
    Add(A14, A15, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S17);
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(-0.125), T17);
    FastMatmulRecursive(S17, T17, M17, numsteps - 1, x);
    S17.deallocate();
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A11 + 1.0 * A12 + -1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + 0.125 * B22 + -0.125 * B23 + 0.125 * B24 + -1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A14 + 1.0 * A15 + -1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B13 + 0.125 * B14 + 1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A14, A15, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A12 + 1.0 * A13 + 1.0 * A15 + 1.0 * A16) * (1.0 * B11 + 1.0 * B15 + 1.0 * B21 + 0.125 * B22 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A12, A13, A15, A16, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), T20);
    FastMatmulRecursive(S20, T20, M20, numsteps - 1, x);
    S20.deallocate();
    T20.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A14 + -1.0 * A16) * (1.0 * B11 + 0.125 * B12 + 0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B16 + -1.0 * B21 + 1.0 * B25 + 0.125 * B34 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S21(A11.m(), A11.n());
    Add(A11, A13, A14, A16, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S21);
    Matrix<Scalar> T21(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(-0.125), T21);
    FastMatmulRecursive(S21, T21, M21, numsteps - 1, x);
    S21.deallocate();
    T21.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (-1.0 * A11 + -1.0 * A13 + -1.0 * A14 + -1.0 * A16) * (1.0 * B11 + -0.125 * B12 + -0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S22(A11.m(), A11.n());
    Add(A11, A13, A14, A16, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S22);
    Matrix<Scalar> T22(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T22);
    FastMatmulRecursive(S22, T22, M22, numsteps - 1, x);
    S22.deallocate();
    T22.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (-1.0 * A15 + 1.0 * A16 + -1.0 * A22 + 1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + 0.125 * B32 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S23(A11.m(), A11.n());
    Add(A15, A16, A22, A23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S23);
    Matrix<Scalar> T23(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), T23);
    FastMatmulRecursive(S23, T23, M23, numsteps - 1, x);
    S23.deallocate();
    T23.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (-1.0 * A15 + -1.0 * A16 + -1.0 * A22 + -1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + -0.125 * B32 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S24(A11.m(), A11.n());
    Add(A15, A16, A22, A23, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S24);
    Matrix<Scalar> T24(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), T24);
    FastMatmulRecursive(S24, T24, M24, numsteps - 1, x);
    S24.deallocate();
    T24.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A21 + -1.0 * A22) * (1.0 * B11 + 1.0 * B15 + -1.0 * B21 + -0.125 * B22 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + 0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S25(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S25);
    Matrix<Scalar> T25(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), T25);
    FastMatmulRecursive(S25, T25, M25, numsteps - 1, x);
    S25.deallocate();
    T25.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (-1.0 * A12 + 1.0 * A13 + 1.0 * A15 + -1.0 * A16) * (-1.0 * B11 + -1.0 * B15 + 1.0 * B21 + 0.125 * B22 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S26(A11.m(), A11.n());
    Add(A12, A13, A15, A16, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S26);
    Matrix<Scalar> T26(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), T26);
    FastMatmulRecursive(S26, T26, M26, numsteps - 1, x);
    S26.deallocate();
    T26.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M27 = (1.0 * A11 + 1.0 * A13 + -1.0 * A21 + -1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + 0.125 * B32 + 0.125 * B33 + 0.125 * B34 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S27(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S27);
    Matrix<Scalar> T27(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), T27);
    FastMatmulRecursive(S27, T27, M27, numsteps - 1, x);
    S27.deallocate();
    T27.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M28 = (-1.0 * A11 + -1.0 * A13 + -1.0 * A21 + -1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + -0.125 * B32 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S28(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S28);
    Matrix<Scalar> T28(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), T28);
    FastMatmulRecursive(S28, T28, M28, numsteps - 1, x);
    S28.deallocate();
    T28.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M29 = (1.0 * A11 + -1.0 * A13 + 1.0 * A21 + -1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + -0.125 * B32 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S29(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S29);
    Matrix<Scalar> T29(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), T29);
    FastMatmulRecursive(S29, T29, M29, numsteps - 1, x);
    S29.deallocate();
    T29.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M30 = (1.0 * A15 + -1.0 * A16 + -1.0 * A22 + 1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + 0.125 * B32 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S30(A11.m(), A11.n());
    Add(A15, A16, A22, A23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S30);
    Matrix<Scalar> T30(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), T30);
    FastMatmulRecursive(S30, T30, M30, numsteps - 1, x);
    S30.deallocate();
    T30.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M31 = (-1.0 * A15 + -1.0 * A16 + 1.0 * A22 + 1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + -0.125 * B32 + 0.125 * B33 + 0.125 * B34 + -1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S31(A11.m(), A11.n());
    Add(A15, A16, A22, A23, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S31);
    Matrix<Scalar> T31(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), T31);
    FastMatmulRecursive(S31, T31, M31, numsteps - 1, x);
    S31.deallocate();
    T31.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M32 = (1.0 * A11 + -1.0 * A13 + -1.0 * A21 + 1.0 * A23) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + 0.125 * B32 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S32(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S32);
    Matrix<Scalar> T32(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), T32);
    FastMatmulRecursive(S32, T32, M32, numsteps - 1, x);
    S32.deallocate();
    T32.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M33 = (1.0 * A11 + -1.0 * A12 + 1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + -1.0 * B15 + 1.0 * B21 + -0.125 * B22 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S33(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S33);
    Matrix<Scalar> T33(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), T33);
    FastMatmulRecursive(S33, T33, M33, numsteps - 1, x);
    S33.deallocate();
    T33.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M34 = (1.0 * A11 + -1.0 * A13 + 1.0 * A14 + -1.0 * A16) * (1.0 * B11 + 0.125 * B12 + 0.125 * B13 + 0.125 * B14 + 1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S34(A11.m(), A11.n());
    Add(A11, A13, A14, A16, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S34);
    Matrix<Scalar> T34(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T34);
    FastMatmulRecursive(S34, T34, M34, numsteps - 1, x);
    S34.deallocate();
    T34.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M35 = (1.0 * A12 + -1.0 * A13 + 1.0 * A15 + -1.0 * A16) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + 0.125 * B22 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + -0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S35(A11.m(), A11.n());
    Add(A12, A13, A15, A16, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S35);
    Matrix<Scalar> T35(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), T35);
    FastMatmulRecursive(S35, T35, M35, numsteps - 1, x);
    S35.deallocate();
    T35.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M36 = (1.0 * A11 + 1.0 * A12 + 1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + -0.125 * B22 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + -0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S36(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S36);
    Matrix<Scalar> T36(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), T36);
    FastMatmulRecursive(S36, T36, M36, numsteps - 1, x);
    S36.deallocate();
    T36.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M37 = (-1.0 * A14 + 1.0 * A15 + 1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + 0.125 * B12 + -0.125 * B13 + -0.125 * B14 + 1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S37(A11.m(), A11.n());
    Add(A14, A15, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S37);
    Matrix<Scalar> T37(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T37);
    FastMatmulRecursive(S37, T37, M37, numsteps - 1, x);
    S37.deallocate();
    T37.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M38 = (-1.0 * A14 + -1.0 * A15 + 1.0 * A21 + 1.0 * A22) * (1.0 * B11 + -0.125 * B12 + 0.125 * B13 + -0.125 * B14 + -1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S38(A11.m(), A11.n());
    Add(A14, A15, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S38);
    Matrix<Scalar> T38(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T38);
    FastMatmulRecursive(S38, T38, M38, numsteps - 1, x);
    S38.deallocate();
    T38.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M39 = (-1.0 * A12 + -1.0 * A13 + 1.0 * A15 + 1.0 * A16) * (1.0 * B11 + 1.0 * B15 + -1.0 * B21 + 0.125 * B22 + 0.125 * B23 + -0.125 * B24 + 1.0 * B25 + 0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S39(A11.m(), A11.n());
    Add(A12, A13, A15, A16, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S39);
    Matrix<Scalar> T39(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), T39);
    FastMatmulRecursive(S39, T39, M39, numsteps - 1, x);
    S39.deallocate();
    T39.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M40 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A14 + 1.0 * A16) * (-1.0 * B11 + 0.125 * B12 + 0.125 * B13 + -0.125 * B14 + -1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S40(A11.m(), A11.n());
    Add(A11, A13, A14, A16, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S40);
    Matrix<Scalar> T40(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), T40);
    FastMatmulRecursive(S40, T40, M40, numsteps - 1, x);
    S40.deallocate();
    T40.deallocate();
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


    Add(M1, M2, M4, M5, M8, M12, M13, M16, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), C11);
    Add(M1, M4, M6, M8, M10, M11, M13, M15, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), C12);
    Add(M2, M3, M5, M7, M9, M12, M14, M16, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C13);
    Add(M2, M5, M6, M10, M11, M12, M15, M16, M18, M20, M25, M26, M33, M35, M36, M39, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C14);
    Add(M3, M6, M7, M9, M10, M11, M14, M15, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), C15);
    Add(M1, M3, M4, M7, M8, M9, M13, M14, M18, M20, M25, M26, M33, M35, M36, M39, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C16);
    Add(M1, M2, M4, M5, M8, M12, M13, M16, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), C21);
    Add(M2, M3, M5, M7, M9, M12, M14, M16, M17, M19, M21, M22, M34, M37, M38, M40, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C22);
    Add(M1, M4, M6, M8, M10, M11, M13, M15, M17, M19, M21, M22, M34, M37, M38, M40, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C23);
    Add(M1, M3, M4, M7, M8, M9, M13, M14, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C24);
    Add(M3, M6, M7, M9, M10, M11, M14, M15, M17, M18, M19, M20, M21, M22, M25, M26, M33, M34, M35, M36, M37, M38, M39, M40, Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), C25);
    Add(M2, M5, M6, M10, M11, M12, M15, M16, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C26);
    Add(M3, M6, M7, M9, M10, M11, M14, M15, M23, M24, M27, M28, M29, M30, M31, M32, Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), C31);
    Add(M1, M4, M6, M8, M10, M11, M13, M15, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C32);
    Add(M2, M3, M5, M7, M9, M12, M14, M16, M18, M20, M23, M24, M25, M26, M27, M28, M29, M30, M31, M32, M33, M35, M36, M39, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C33);
    Add(M1, M3, M4, M7, M8, M9, M13, M14, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C34);
    Add(M1, M2, M4, M5, M8, M12, M13, M16, M23, M24, M27, M28, M29, M30, M31, M32, Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), C35);
    Add(M2, M5, M6, M10, M11, M12, M15, M16, M17, M19, M21, M22, M23, M24, M27, M28, M29, M30, M31, M32, M34, M37, M38, M40, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C36);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 6, 6);
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

}  // namespace smirnov336_40_960

#endif  // _smirnov336_40_960_HPP_
