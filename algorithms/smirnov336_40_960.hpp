#ifndef _smirnov336_40_960_HPP_
#define _smirnov336_40_960_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace smirnov336_40_960 {

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
    int A_col_step = A.n() / 3;
    Matrix<Scalar> A11 = A.Subblock(3, 3, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 3, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(3, 3, 1, 3);
    Matrix<Scalar> A21 = A.Subblock(3, 3, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 3, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(3, 3, 2, 3);
    Matrix<Scalar> A31 = A.Subblock(3, 3, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 3, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(3, 3, 3, 3);
    int B_row_step = B.m() / 3;
    int B_col_step = B.n() / 6;
    Matrix<Scalar> B11 = B.Subblock(3, 6, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 6, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(3, 6, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(3, 6, 1, 4);
    Matrix<Scalar> B15 = B.Subblock(3, 6, 1, 5);
    Matrix<Scalar> B16 = B.Subblock(3, 6, 1, 6);
    Matrix<Scalar> B21 = B.Subblock(3, 6, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 6, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(3, 6, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(3, 6, 2, 4);
    Matrix<Scalar> B25 = B.Subblock(3, 6, 2, 5);
    Matrix<Scalar> B26 = B.Subblock(3, 6, 2, 6);
    Matrix<Scalar> B31 = B.Subblock(3, 6, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 6, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(3, 6, 3, 3);
    Matrix<Scalar> B34 = B.Subblock(3, 6, 3, 4);
    Matrix<Scalar> B35 = B.Subblock(3, 6, 3, 5);
    Matrix<Scalar> B36 = B.Subblock(3, 6, 3, 6);
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


    // M1 = (1.0 * A11 + 1.0 * A13 + 1.0 * A22 + 1.0 * A23 + -1.0 * A31 + 1.0 * A32) * (-0.125 * B12 + 1.0 * B15 + 0.125 * B16 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -1.0 * B31 + 0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M1A);
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), M1B);
    FastMatmulRecursive(M1A, M1B, M1, numsteps - 1, x);
    M1A.deallocate();
    M1B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A11 + -1.0 * A13 + 1.0 * A22 + -1.0 * A23 + -1.0 * A31 + 1.0 * A32) * (-0.125 * B13 + -0.125 * B14 + -1.0 * B15 + 0.125 * B22 + 1.0 * B25 + -0.125 * B26 + -1.0 * B31 + -0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M2B);
    FastMatmulRecursive(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A22 + -1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + 0.125 * B13 + -0.125 * B16 + -1.0 * B21 + 0.125 * B22 + 0.125 * B24 + -0.125 * B32 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M3A);
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), M3B);
    FastMatmulRecursive(M3A, M3B, M3, numsteps - 1, x);
    M3A.deallocate();
    M3B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A11 + 1.0 * A13 + -1.0 * A22 + -1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (-0.125 * B12 + -1.0 * B15 + -0.125 * B16 + -0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -1.0 * B31 + -0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M4B);
    FastMatmulRecursive(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A11 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23 + -1.0 * A31 + -1.0 * A32) * (-0.125 * B13 + 0.125 * B14 + 1.0 * B15 + -0.125 * B22 + 1.0 * B25 + -0.125 * B26 + -1.0 * B31 + 0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), M5B);
    FastMatmulRecursive(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23 + -1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B14 + 1.0 * B21 + 0.125 * B23 + 0.125 * B26 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), M6B);
    FastMatmulRecursive(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A22 + 1.0 * A23 + -1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + 0.125 * B13 + 0.125 * B16 + 1.0 * B21 + -0.125 * B22 + 0.125 * B24 + -0.125 * B32 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), M7B);
    FastMatmulRecursive(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A11 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (0.125 * B12 + -1.0 * B15 + 0.125 * B16 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + 1.0 * B31 + -0.125 * B33 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(1.0), Scalar(-0.125), Scalar(0.125), M8B);
    FastMatmulRecursive(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23 + 1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + -0.125 * B13 + -0.125 * B16 + 1.0 * B21 + 0.125 * B22 + -0.125 * B24 + -0.125 * B32 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), M9B);
    FastMatmulRecursive(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A22 + 1.0 * A23 + 1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + 0.125 * B12 + -0.125 * B14 + 1.0 * B21 + -0.125 * B23 + -0.125 * B26 + -0.125 * B33 + -0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), M10B);
    FastMatmulRecursive(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A11 + 1.0 * A13 + -1.0 * A22 + 1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + 0.125 * B12 + 0.125 * B14 + -1.0 * B21 + 0.125 * B23 + -0.125 * B26 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), M11B);
    FastMatmulRecursive(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A11 + 1.0 * A13 + 1.0 * A22 + 1.0 * A23 + 1.0 * A31 + -1.0 * A32) * (-0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B22 + -1.0 * B25 + -0.125 * B26 + -1.0 * B31 + 0.125 * B32 + -0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M12A);
    Matrix<Scalar> M12B(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), M12B);
    FastMatmulRecursive(M12A, M12B, M12, numsteps - 1, x);
    M12A.deallocate();
    M12B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A11 + 1.0 * A13 + -1.0 * A22 + 1.0 * A23 + -1.0 * A31 + 1.0 * A32) * (-0.125 * B12 + -1.0 * B15 + 0.125 * B16 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + -1.0 * B31 + -0.125 * B33 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M13A);
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B12, B15, B16, B23, B24, B25, B31, B33, B36, Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), M13B);
    FastMatmulRecursive(M13A, M13B, M13, numsteps - 1, x);
    M13A.deallocate();
    M13B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A22 + 1.0 * A23 + -1.0 * A31 + -1.0 * A32) * (1.0 * B11 + 0.125 * B13 + -0.125 * B16 + 1.0 * B21 + 0.125 * B22 + 0.125 * B24 + 0.125 * B32 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B11, B13, B16, B21, B22, B24, B32, B35, B36, Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), M14B);
    FastMatmulRecursive(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A22 + 1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (1.0 * B11 + 0.125 * B12 + 0.125 * B14 + 1.0 * B21 + 0.125 * B23 + -0.125 * B26 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M15A);
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B11, B12, B14, B21, B23, B26, B33, B34, B35, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), M15B);
    FastMatmulRecursive(M15A, M15B, M15, numsteps - 1, x);
    M15A.deallocate();
    M15B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A11 + -1.0 * A13 + 1.0 * A22 + 1.0 * A23 + 1.0 * A31 + 1.0 * A32) * (0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B22 + 1.0 * B25 + 0.125 * B26 + 1.0 * B31 + 0.125 * B32 + 0.125 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A11, A13, A22, A23, A31, A32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B13, B14, B15, B22, B25, B26, B31, B32, B34, Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), M16B);
    FastMatmulRecursive(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A21 + -1.0 * A22 + -1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B13 + -0.125 * B14 + 1.0 * B15 + -0.125 * B16 + -1.0 * B21 + 1.0 * B25 + 0.125 * B34 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M17A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M17A);
    Matrix<Scalar> M17B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(-0.125), M17B);
    FastMatmulRecursive(M17A, M17B, M17, numsteps - 1, x);
    M17A.deallocate();
    M17B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A11 + 1.0 * A12 + -1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + 0.125 * B22 + -0.125 * B23 + 0.125 * B24 + -1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A11, A12, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M18A);
    Matrix<Scalar> M18B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), M18B);
    FastMatmulRecursive(M18A, M18B, M18, numsteps - 1, x);
    M18A.deallocate();
    M18B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A21 + 1.0 * A22 + -1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + -0.125 * B12 + 0.125 * B13 + 0.125 * B14 + 1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M19A);
    Matrix<Scalar> M19B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M19B);
    FastMatmulRecursive(M19A, M19B, M19, numsteps - 1, x);
    M19A.deallocate();
    M19B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A12 + 1.0 * A13 + 1.0 * A22 + 1.0 * A23) * (1.0 * B11 + 1.0 * B15 + 1.0 * B21 + 0.125 * B22 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + -0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M20A(A11.m(), A11.n());
    Add(A12, A13, A22, A23, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M20A);
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), M20B);
    FastMatmulRecursive(M20A, M20B, M20, numsteps - 1, x);
    M20A.deallocate();
    M20B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (-1.0 * A11 + 1.0 * A13 + 1.0 * A21 + -1.0 * A23) * (1.0 * B11 + 0.125 * B12 + 0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B16 + -1.0 * B21 + 1.0 * B25 + 0.125 * B34 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M21A(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M21A);
    Matrix<Scalar> M21B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(-0.125), M21B);
    FastMatmulRecursive(M21A, M21B, M21, numsteps - 1, x);
    M21A.deallocate();
    M21B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (-1.0 * A11 + -1.0 * A13 + -1.0 * A21 + -1.0 * A23) * (1.0 * B11 + -0.125 * B12 + -0.125 * B13 + -0.125 * B14 + 1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M22A(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M22A);
    Matrix<Scalar> M22B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M22B);
    FastMatmulRecursive(M22A, M22B, M22, numsteps - 1, x);
    M22A.deallocate();
    M22B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (-1.0 * A22 + 1.0 * A23 + -1.0 * A32 + 1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + 0.125 * B32 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M23A(A11.m(), A11.n());
    Add(A22, A23, A32, A33, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M23A);
    Matrix<Scalar> M23B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), M23B);
    FastMatmulRecursive(M23A, M23B, M23, numsteps - 1, x);
    M23A.deallocate();
    M23B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (-1.0 * A22 + -1.0 * A23 + -1.0 * A32 + -1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + -0.125 * B32 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M24A(A11.m(), A11.n());
    Add(A22, A23, A32, A33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M24A);
    Matrix<Scalar> M24B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), M24B);
    FastMatmulRecursive(M24A, M24B, M24, numsteps - 1, x);
    M24A.deallocate();
    M24B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A31 + -1.0 * A32) * (1.0 * B11 + 1.0 * B15 + -1.0 * B21 + -0.125 * B22 + 0.125 * B23 + 0.125 * B24 + -1.0 * B25 + 0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M25A(A11.m(), A11.n());
    Add(A11, A12, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M25A);
    Matrix<Scalar> M25B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), M25B);
    FastMatmulRecursive(M25A, M25B, M25, numsteps - 1, x);
    M25A.deallocate();
    M25B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (-1.0 * A12 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23) * (-1.0 * B11 + -1.0 * B15 + 1.0 * B21 + 0.125 * B22 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M26A(A11.m(), A11.n());
    Add(A12, A13, A22, A23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M26A);
    Matrix<Scalar> M26B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), M26B);
    FastMatmulRecursive(M26A, M26B, M26, numsteps - 1, x);
    M26A.deallocate();
    M26B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M27 = (1.0 * A11 + 1.0 * A13 + -1.0 * A31 + -1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + 0.125 * B32 + 0.125 * B33 + 0.125 * B34 + -1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M27A(A11.m(), A11.n());
    Add(A11, A13, A31, A33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M27A);
    Matrix<Scalar> M27B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), M27B);
    FastMatmulRecursive(M27A, M27B, M27, numsteps - 1, x);
    M27A.deallocate();
    M27B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M28 = (-1.0 * A11 + -1.0 * A13 + -1.0 * A31 + -1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + -0.125 * B32 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M28A(A11.m(), A11.n());
    Add(A11, A13, A31, A33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M28A);
    Matrix<Scalar> M28B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), M28B);
    FastMatmulRecursive(M28A, M28B, M28, numsteps - 1, x);
    M28A.deallocate();
    M28B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M29 = (1.0 * A11 + -1.0 * A13 + 1.0 * A31 + -1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + -0.125 * B32 + -0.125 * B33 + -0.125 * B34 + -1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M29A(A11.m(), A11.n());
    Add(A11, A13, A31, A33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M29A);
    Matrix<Scalar> M29B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), M29B);
    FastMatmulRecursive(M29A, M29B, M29, numsteps - 1, x);
    M29A.deallocate();
    M29B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M30 = (1.0 * A22 + -1.0 * A23 + -1.0 * A32 + 1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + -1.0 * B31 + 0.125 * B32 + -0.125 * B33 + 0.125 * B34 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M30A(A11.m(), A11.n());
    Add(A22, A23, A32, A33, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M30A);
    Matrix<Scalar> M30B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), M30B);
    FastMatmulRecursive(M30A, M30B, M30, numsteps - 1, x);
    M30A.deallocate();
    M30B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M31 = (-1.0 * A22 + -1.0 * A23 + 1.0 * A32 + 1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + -0.125 * B32 + 0.125 * B33 + 0.125 * B34 + -1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M31A(A11.m(), A11.n());
    Add(A22, A23, A32, A33, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M31A);
    Matrix<Scalar> M31B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(-1.0), Scalar(-0.125), M31B);
    FastMatmulRecursive(M31A, M31B, M31, numsteps - 1, x);
    M31A.deallocate();
    M31B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M32 = (1.0 * A11 + -1.0 * A13 + -1.0 * A31 + 1.0 * A33) * (0.125 * B14 + 0.125 * B16 + -0.125 * B22 + 0.125 * B23 + 1.0 * B31 + 0.125 * B32 + 0.125 * B33 + -0.125 * B34 + 1.0 * B35 + -0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M32A(A11.m(), A11.n());
    Add(A11, A13, A31, A33, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M32A);
    Matrix<Scalar> M32B(B11.m(), B11.n());
    Add(B14, B16, B22, B23, B31, B32, B33, B34, B35, B36, Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), M32B);
    FastMatmulRecursive(M32A, M32B, M32, numsteps - 1, x);
    M32A.deallocate();
    M32B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M33 = (1.0 * A11 + -1.0 * A12 + 1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + -1.0 * B15 + 1.0 * B21 + -0.125 * B22 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + 0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M33A(A11.m(), A11.n());
    Add(A11, A12, A31, A32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M33A);
    Matrix<Scalar> M33B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), M33B);
    FastMatmulRecursive(M33A, M33B, M33, numsteps - 1, x);
    M33A.deallocate();
    M33B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M34 = (1.0 * A11 + -1.0 * A13 + 1.0 * A21 + -1.0 * A23) * (1.0 * B11 + 0.125 * B12 + 0.125 * B13 + 0.125 * B14 + 1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M34A(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M34A);
    Matrix<Scalar> M34B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M34B);
    FastMatmulRecursive(M34A, M34B, M34, numsteps - 1, x);
    M34A.deallocate();
    M34B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M35 = (1.0 * A12 + -1.0 * A13 + 1.0 * A22 + -1.0 * A23) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + 0.125 * B22 + 0.125 * B23 + 0.125 * B24 + 1.0 * B25 + -0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M35A(A11.m(), A11.n());
    Add(A12, A13, A22, A23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M35A);
    Matrix<Scalar> M35B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), Scalar(1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), M35B);
    FastMatmulRecursive(M35A, M35B, M35, numsteps - 1, x);
    M35A.deallocate();
    M35B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M36 = (1.0 * A11 + 1.0 * A12 + 1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + -1.0 * B15 + -1.0 * B21 + -0.125 * B22 + 0.125 * B23 + -0.125 * B24 + -1.0 * B25 + -0.125 * B26 + -0.125 * B32 + -0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M36A(A11.m(), A11.n());
    Add(A11, A12, A31, A32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M36A);
    Matrix<Scalar> M36B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(-0.125), Scalar(-0.125), M36B);
    FastMatmulRecursive(M36A, M36B, M36, numsteps - 1, x);
    M36A.deallocate();
    M36B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M37 = (-1.0 * A21 + 1.0 * A22 + 1.0 * A31 + -1.0 * A32) * (-1.0 * B11 + 0.125 * B12 + -0.125 * B13 + -0.125 * B14 + 1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M37A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M37A);
    Matrix<Scalar> M37B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(0.125), Scalar(-0.125), Scalar(-0.125), Scalar(1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M37B);
    FastMatmulRecursive(M37A, M37B, M37, numsteps - 1, x);
    M37A.deallocate();
    M37B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M38 = (-1.0 * A21 + -1.0 * A22 + 1.0 * A31 + 1.0 * A32) * (1.0 * B11 + -0.125 * B12 + 0.125 * B13 + -0.125 * B14 + -1.0 * B15 + -0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M38A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M38A);
    Matrix<Scalar> M38B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(1.0), Scalar(-0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(-0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M38B);
    FastMatmulRecursive(M38A, M38B, M38, numsteps - 1, x);
    M38A.deallocate();
    M38B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M39 = (-1.0 * A12 + -1.0 * A13 + 1.0 * A22 + 1.0 * A23) * (1.0 * B11 + 1.0 * B15 + -1.0 * B21 + 0.125 * B22 + 0.125 * B23 + -0.125 * B24 + 1.0 * B25 + 0.125 * B26 + 0.125 * B32 + 0.125 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M39A(A11.m(), A11.n());
    Add(A12, A13, A22, A23, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M39A);
    Matrix<Scalar> M39B(B11.m(), B11.n());
    Add(B11, B15, B21, B22, B23, B24, B25, B26, B32, B33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(1.0), Scalar(0.125), Scalar(0.125), Scalar(0.125), M39B);
    FastMatmulRecursive(M39A, M39B, M39, numsteps - 1, x);
    M39A.deallocate();
    M39B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M40 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A21 + 1.0 * A23) * (-1.0 * B11 + 0.125 * B12 + 0.125 * B13 + -0.125 * B14 + -1.0 * B15 + 0.125 * B16 + 1.0 * B21 + -1.0 * B25 + -0.125 * B34 + 0.125 * B36)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M40A(A11.m(), A11.n());
    Add(A11, A13, A21, A23, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M40A);
    Matrix<Scalar> M40B(B11.m(), B11.n());
    Add(B11, B12, B13, B14, B15, B16, B21, B25, B34, B36, Scalar(-1.0), Scalar(0.125), Scalar(0.125), Scalar(-0.125), Scalar(-1.0), Scalar(0.125), Scalar(1.0), Scalar(-1.0), Scalar(-0.125), Scalar(0.125), M40B);
    FastMatmulRecursive(M40A, M40B, M40, numsteps - 1, x);
    M40A.deallocate();
    M40B.deallocate();
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
    DynamicPeeling(A, B, C, 3, 3, 6);
}

}
  // namespace smirnov336_40_960
#endif  // _smirnov336_40_960_HPP_
