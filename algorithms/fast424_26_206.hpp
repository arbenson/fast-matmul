#ifndef _grey424_26_206_HPP_
#define _grey424_26_206_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey424_26_206 {

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

    int A_row_step = A.m() / 4;
    int A_col_step = A.n() / 2;
    Matrix<Scalar> A11 = A.Subblock(4, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(4, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(4, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(4, 2, 2, 2);
    Matrix<Scalar> A31 = A.Subblock(4, 2, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(4, 2, 3, 2);
    Matrix<Scalar> A41 = A.Subblock(4, 2, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(4, 2, 4, 2);
    int B_row_step = B.m() / 2;
    int B_col_step = B.n() / 4;
    Matrix<Scalar> B11 = B.Subblock(2, 4, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 4, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 4, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(2, 4, 1, 4);
    Matrix<Scalar> B21 = B.Subblock(2, 4, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 4, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 4, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(2, 4, 2, 4);
    int C_row_step = C.m() / 4;
    int C_col_step = C.n() / 4;
    Matrix<Scalar> C11 = C.Subblock(4, 4, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 4, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(4, 4, 1, 3);
    Matrix<Scalar> C14 = C.Subblock(4, 4, 1, 4);
    Matrix<Scalar> C21 = C.Subblock(4, 4, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 4, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(4, 4, 2, 3);
    Matrix<Scalar> C24 = C.Subblock(4, 4, 2, 4);
    Matrix<Scalar> C31 = C.Subblock(4, 4, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 4, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(4, 4, 3, 3);
    Matrix<Scalar> C34 = C.Subblock(4, 4, 3, 4);
    Matrix<Scalar> C41 = C.Subblock(4, 4, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 4, 4, 2);
    Matrix<Scalar> C43 = C.Subblock(4, 4, 4, 3);
    Matrix<Scalar> C44 = C.Subblock(4, 4, 4, 4);
    

    Matrix<Scalar> A_X1(A11.m(), A11.n());
    Add(A11, A21, Scalar(1.0), Scalar(1.0), A_X1);
    Matrix<Scalar> A_X2(A11.m(), A11.n());
    Add(A12, A22, Scalar(-1.0), Scalar(-1.0), A_X2);
    Matrix<Scalar> A_X3(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(-1.0), A_X3);
    Matrix<Scalar> A_X4(A11.m(), A11.n());
    Add(A41, A42, Scalar(1.0), Scalar(-1.0), A_X4);
    Matrix<Scalar> A_X5(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(1.0), A_X5);
    Matrix<Scalar> A_X6(A11.m(), A11.n());
    Add(A41, A42, Scalar(-1.0), Scalar(-1.0), A_X6);
    

    Matrix<Scalar> B_X1(B11.m(), B11.n());
    Add(B11, B14, Scalar(1.0), Scalar(1.0), B_X1);
    Matrix<Scalar> B_X2(B11.m(), B11.n());
    Add(B11, B13, Scalar(-1.0), Scalar(1.0), B_X2);
    Matrix<Scalar> B_X3(B11.m(), B11.n());
    Add(B12, B13, Scalar(1.0), Scalar(-1.0), B_X3);
    Matrix<Scalar> B_X4(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(-1.0), B_X4);
    Matrix<Scalar> B_X5(B11.m(), B11.n());
    Add(B14, B22, Scalar(-1.0), Scalar(-1.0), B_X5);
    Matrix<Scalar> B_X6(B11.m(), B11.n());
    Add(B21, B23, Scalar(-1.0), Scalar(1.0), B_X6);


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


    // M1 = (1.0 * A_X1 + 1.0 * A_X2 + 1.0 * A_X3 + 1.0 * A_X4) * (1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A_X1, A_X2, A_X3, A_X4, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M1A);
    FastMatmulRecursive(M1A, B_X1, M1, numsteps - 1, x);
    M1A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (0.5 * A21 + -1.0 * A22 + 0.5 * A31 + 0.5 * A41) * (-1.0 * B21 + 1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A21, A22, A31, A41, Scalar(0.5), Scalar(-1.0), Scalar(0.5), Scalar(0.5), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B21, B_X2, Scalar(-1.0), Scalar(1.0), M2B);
    FastMatmulRecursive(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A_X1 + 1.0 * A_X2 + 1.0 * A_X5 + 1.0 * A_X6) * (-1.0 * B14 + 1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A_X1, A_X2, A_X5, A_X6, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M3A);
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B14, B_X3, Scalar(-1.0), Scalar(1.0), M3B);
    FastMatmulRecursive(M3A, M3B, M3, numsteps - 1, x);
    M3A.deallocate();
    M3B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A21 + 1.0 * A_X2 + 1.0 * A_X3 + 1.0 * A_X4) * (1.0 * B21 + 1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A21, A_X2, A_X3, A_X4, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B21, B_X1, Scalar(1.0), Scalar(1.0), M4B);
    FastMatmulRecursive(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A42) * (1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A42, B_X4, M5, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A11 + -1.0 * A12 + -1.0 * A_X6) * (1.0 * B22 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A11, A12, A_X6, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B22, B24, Scalar(1.0), Scalar(1.0), M6B);
    FastMatmulRecursive(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A32 + -1.0 * A42 + 1.0 * A_X2) * (1.0 * B21 + 1.0 * B24 + 1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A32, A42, A_X2, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B21, B24, B_X1, Scalar(1.0), Scalar(1.0), Scalar(1.0), M7B);
    FastMatmulRecursive(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A21 + 1.0 * A31 + 1.0 * A41) * (1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(1.0), Scalar(1.0), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(1.0), M8B);
    FastMatmulRecursive(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A21 + -1.0 * A22 + 1.0 * A_X3 + 1.0 * A_X4) * (-1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A21, A22, A_X3, A_X4, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M9A);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M9A, B21, M9, numsteps - 1, x);
    M9A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A32 + -1.0 * A42 + 1.0 * A_X2) * (1.0 * B23 + 1.0 * B24 + 1.0 * B_X3 + 1.0 * B_X5)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A32, A42, A_X2, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B23, B24, B_X3, B_X5, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M10B);
    FastMatmulRecursive(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A11 + -1.0 * A_X6) * (1.0 * B24 + -1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A11, A_X6, Scalar(-1.0), Scalar(-1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B24, B_X4, Scalar(1.0), Scalar(-1.0), M11B);
    FastMatmulRecursive(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A12) * (1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M12.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A12, B24, M12, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A_X6) * (-1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M13.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A_X6, B12, M13, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11) * (-1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M14.UpdateMultiplier(Scalar(-1));
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A11, B14, M14, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A11 + 1.0 * A41) * (1.0 * B14 + -1.0 * B24 + 1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A11, A41, Scalar(-1.0), Scalar(1.0), M15A);
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B14, B24, B_X4, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M15B);
    FastMatmulRecursive(M15A, M15B, M15, numsteps - 1, x);
    M15A.deallocate();
    M15B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A21 + -1.0 * A32 + 1.0 * A41) * (1.0 * B21 + 1.0 * B23 + -1.0 * B_X2 + 1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A21, A32, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B21, B23, B_X2, B_X4, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M16B);
    FastMatmulRecursive(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A_X3) * (-1.0 * B_X2 + 1.0 * B_X4 + 1.0 * B_X6)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M17B(B11.m(), B11.n());
    Add(B_X2, B_X4, B_X6, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M17B);
    FastMatmulRecursive(A_X3, M17B, M17, numsteps - 1, x);
    M17B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A21 + -1.0 * A31 + 1.0 * A41) * (-1.0 * B22 + 1.0 * B23 + 1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M18A);
    Matrix<Scalar> M18B(B11.m(), B11.n());
    Add(B22, B23, B_X3, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M18B);
    FastMatmulRecursive(M18A, M18B, M18, numsteps - 1, x);
    M18A.deallocate();
    M18B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (1.0 * A21 + -1.0 * A31 + -1.0 * A41) * (-1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M19A);
    M19.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M19A, B13, M19, numsteps - 1, x);
    M19A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A_X5) * (1.0 * B12 + 1.0 * B22 + -1.0 * B_X2 + -1.0 * B_X6)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B12, B22, B_X2, B_X6, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M20B);
    FastMatmulRecursive(A_X5, M20B, M20, numsteps - 1, x);
    M20B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (-1.0 * A21 + 1.0 * A_X2 + 1.0 * A_X5 + 1.0 * A_X6) * (1.0 * B23 + 1.0 * B_X3 + 1.0 * B_X5)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M21A(A11.m(), A11.n());
    Add(A21, A_X2, A_X5, A_X6, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M21A);
    Matrix<Scalar> M21B(B11.m(), B11.n());
    Add(B23, B_X3, B_X5, Scalar(1.0), Scalar(1.0), Scalar(1.0), M21B);
    FastMatmulRecursive(M21A, M21B, M21, numsteps - 1, x);
    M21A.deallocate();
    M21B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (1.0 * A22) * (-1.0 * B_X2 + -1.0 * B_X6)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M22B(B11.m(), B11.n());
    Add(B_X2, B_X6, Scalar(-1.0), Scalar(-1.0), M22B);
    FastMatmulRecursive(A22, M22B, M22, numsteps - 1, x);
    M22B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A22 + -1.0 * A32 + -1.0 * A42) * (-1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M23A(A11.m(), A11.n());
    Add(A22, A32, A42, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M23A);
    M23.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M23A, B23, M23, numsteps - 1, x);
    M23A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (1.0 * A21 + 1.0 * A22 + -1.0 * A_X5 + -1.0 * A_X6) * (1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M24A(A11.m(), A11.n());
    Add(A21, A22, A_X5, A_X6, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M24A);
    Matrix<Scalar> M24B(B11.m(), B11.n());
    Add(B22, B23, Scalar(1.0), Scalar(-1.0), M24B);
    FastMatmulRecursive(M24A, M24B, M24, numsteps - 1, x);
    M24A.deallocate();
    M24B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-0.5 * A21 + 0.5 * A31 + -0.5 * A41 + -1.0 * A42) * (1.0 * B23 + 1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M25A(A11.m(), A11.n());
    Add(A21, A31, A41, A42, Scalar(-0.5), Scalar(0.5), Scalar(-0.5), Scalar(-1.0), M25A);
    Matrix<Scalar> M25B(B11.m(), B11.n());
    Add(B23, B_X4, Scalar(1.0), Scalar(1.0), M25B);
    FastMatmulRecursive(M25A, M25B, M25, numsteps - 1, x);
    M25A.deallocate();
    M25B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (1.0 * A21 + -1.0 * A22) * (-1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M26A(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(-1.0), M26A);
    M26.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M26A, B_X2, M26, numsteps - 1, x);
    M26A.deallocate();
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
    Matrix<Scalar> M_X1(C11.m(), C11.n());
    Add(M6, M11, Scalar(-1.0), Scalar(1.0), M_X1);
    Matrix<Scalar> M_X2(C11.m(), C11.n());
    Add(M12, M13, Scalar(1.0), Scalar(1.0), M_X2);
    Matrix<Scalar> M_X3(C11.m(), C11.n());
    Add(M2, M8, Scalar(1.0), Scalar(0.5), M_X3);
    Matrix<Scalar> M_X4(C11.m(), C11.n());
    Add(M19, M26, Scalar(-0.5), Scalar(1.0), M_X4);
    Matrix<Scalar> M_X5(C11.m(), C11.n());
    Add(M2, M16, Scalar(1.0), Scalar(0.5), M_X5);
    Matrix<Scalar> M_X6(C11.m(), C11.n());
    Add(M20, M22, Scalar(0.5), Scalar(-1.0), M_X6);
    Matrix<Scalar> M_X7(C11.m(), C11.n());
    Add(M4, M7, Scalar(0.5), Scalar(-0.5), M_X7);
    Matrix<Scalar> M_X8(C11.m(), C11.n());
    Add(M5, M11, Scalar(1.0), Scalar(-1.0), M_X8);
    Matrix<Scalar> M_X9(C11.m(), C11.n());
    Add(M10, M18, Scalar(-0.5), Scalar(0.5), M_X9);
    Matrix<Scalar> M_X10(C11.m(), C11.n());
    Add(M14, M15, Scalar(-1.0), Scalar(-1.0), M_X10);
    Matrix<Scalar> M_X11(C11.m(), C11.n());
    Add(M16, M17, Scalar(-0.5), Scalar(0.5), M_X11);
    Matrix<Scalar> M_X12(C11.m(), C11.n());
    Add(M5, M23, Scalar(-1.0), Scalar(1.0), M_X12);
    Matrix<Scalar> M_X13(C11.m(), C11.n());
    Add(M18, M25, Scalar(0.5), Scalar(1.0), M_X13);


    Add(M1, M4, M9, M14, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C11);
    Add(M_X1, M_X2, Scalar(1.0), Scalar(1.0), C12);
    Add(M3, M14, M21, M24, M_X1, M_X2, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C13);
    Add(M12, M14, Scalar(-1.0), Scalar(1.0), C14);
    Add(M_X3, M_X4, Scalar(1.0), Scalar(1.0), C21);
    Add(M13, M24, M25, M_X5, M_X6, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C22);
    Add(M19, M22, M_X3, Scalar(-0.5), Scalar(-1.0), Scalar(1.0), C23);
    Add(M8, M12, M21, M_X7, M_X8, M_X9, M_X10, Scalar(-0.5), Scalar(1.0), Scalar(0.5), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C24);
    Add(M8, M18, M_X11, Scalar(0.5), Scalar(0.5), Scalar(1.0), C31);
    Add(M25, M_X5, M_X6, M_X12, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M22, M_X3, M_X12, M_X13, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C33);
    Add(M8, M21, M_X7, M_X9, Scalar(-0.5), Scalar(-0.5), Scalar(1.0), Scalar(-1.0), C34);
    Add(M2, M9, M18, M_X4, M_X11, Scalar(-1.0), Scalar(1.0), Scalar(-0.5), Scalar(-1.0), Scalar(-1.0), C41);
    Add(M5, M13, Scalar(1.0), Scalar(1.0), C42);
    Add(M5, M19, M_X13, Scalar(1.0), Scalar(0.5), Scalar(-1.0), C43);
    Add(M_X8, M_X10, Scalar(-1.0), Scalar(-1.0), C44);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 4, 2, 4);
}

}
  // namespace grey424_26_206
#endif  // _grey424_26_206_HPP_