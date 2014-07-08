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
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B11, B31, Scalar(1.0), Scalar(1.0), M1B);
    FastMatmulRecursive(A11, M1B, M1, numsteps - 1, x);
    M1B.deallocate();
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
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B12, B13, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M2B);
    FastMatmulRecursive(A21, M2B, M2, numsteps - 1, x);
    M2B.deallocate();
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
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A23, A33, Scalar(1.0), Scalar(1.0), M3A);
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B13, B33, Scalar(-1.0), Scalar(-1.0), M3B);
    FastMatmulRecursive(M3A, M3B, M3, numsteps - 1, x);
    M3A.deallocate();
    M3B.deallocate();
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
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B13, Scalar(-1.0), Scalar(1.0), M4B);
    FastMatmulRecursive(A41, M4B, M4, numsteps - 1, x);
    M4B.deallocate();
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
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B21, B31, Scalar(1.0), Scalar(-1.0), M5B);
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A12, M5B, M5, numsteps - 1, x);
    M5B.deallocate();
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
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A23, A33, A41, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B13, B32, B33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M6B);
    FastMatmulRecursive(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
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
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A13, A33, A43, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B21, B22, B23, B31, B32, B33, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M7B);
    FastMatmulRecursive(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
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
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A11, A12, A13, A31, A32, A33, A41, A42, A43, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M8B);
    FastMatmulRecursive(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
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
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A22, A32, Scalar(1.0), Scalar(1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), M9B);
    FastMatmulRecursive(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
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
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A21, A22, A42, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), M10B);
    FastMatmulRecursive(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
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
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A13, A33, A42, A43, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B21, B22, B23, B32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M11B);
    FastMatmulRecursive(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
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
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A11, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M12A);
    Matrix<Scalar> M12B(B11.m(), B11.n());
    Add(B13, B31, Scalar(1.0), Scalar(1.0), M12B);
    FastMatmulRecursive(M12A, M12B, M12, numsteps - 1, x);
    M12A.deallocate();
    M12B.deallocate();
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
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A11, A22, A31, A32, A41, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M13A);
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B12, B21, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M13B);
    FastMatmulRecursive(M13A, M13B, M13, numsteps - 1, x);
    M13A.deallocate();
    M13B.deallocate();
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
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A13, A33, Scalar(-1.0), Scalar(1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B31, B33, Scalar(1.0), Scalar(-1.0), M14B);
    FastMatmulRecursive(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
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
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B11, B13, Scalar(1.0), Scalar(-1.0), M15B);
    FastMatmulRecursive(A21, M15B, M15, numsteps - 1, x);
    M15B.deallocate();
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
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A21, A22, A32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B12, B22, B23, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M16B);
    FastMatmulRecursive(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
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
    Matrix<Scalar> M17B(B11.m(), B11.n());
    Add(B23, B33, Scalar(1.0), Scalar(-1.0), M17B);
    FastMatmulRecursive(A23, M17B, M17, numsteps - 1, x);
    M17B.deallocate();
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
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A23, A41, A43, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M18A);
    Matrix<Scalar> M18B(B11.m(), B11.n());
    Add(B32, B33, Scalar(1.0), Scalar(-1.0), M18B);
    FastMatmulRecursive(M18A, M18B, M18, numsteps - 1, x);
    M18A.deallocate();
    M18B.deallocate();
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
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A12, A22, Scalar(-1.0), Scalar(-1.0), M19A);
    Matrix<Scalar> M19B(B11.m(), B11.n());
    Add(B21, B23, Scalar(-1.0), Scalar(1.0), M19B);
    FastMatmulRecursive(M19A, M19B, M19, numsteps - 1, x);
    M19A.deallocate();
    M19B.deallocate();
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
    Matrix<Scalar> M20A(A11.m(), A11.n());
    Add(A11, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M20A);
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), M20B);
    FastMatmulRecursive(M20A, M20B, M20, numsteps - 1, x);
    M20A.deallocate();
    M20B.deallocate();
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
    Matrix<Scalar> M21A(A11.m(), A11.n());
    Add(A12, A23, Scalar(1.0), Scalar(-1.0), M21A);
    Matrix<Scalar> M21B(B11.m(), B11.n());
    Add(B23, B31, Scalar(1.0), Scalar(-1.0), M21B);
    FastMatmulRecursive(M21A, M21B, M21, numsteps - 1, x);
    M21A.deallocate();
    M21B.deallocate();
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
    Matrix<Scalar> M22A(A11.m(), A11.n());
    Add(A23, A33, A42, A43, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M22A);
    FastMatmulRecursive(M22A, B32, M22, numsteps - 1, x);
    M22A.deallocate();
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
    Matrix<Scalar> M23B(B11.m(), B11.n());
    Add(B22, B32, Scalar(1.0), Scalar(-1.0), M23B);
    FastMatmulRecursive(A42, M23B, M23, numsteps - 1, x);
    M23B.deallocate();
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
    Matrix<Scalar> M24A(A11.m(), A11.n());
    Add(A23, A31, A33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M24A);
    FastMatmulRecursive(M24A, B13, M24, numsteps - 1, x);
    M24A.deallocate();
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
    Matrix<Scalar> M25B(B11.m(), B11.n());
    Add(B12, B13, B32, B33, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M25B);
    M25.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A41, M25B, M25, numsteps - 1, x);
    M25B.deallocate();
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
    Matrix<Scalar> M26A(A11.m(), A11.n());
    Add(A11, A12, A13, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M26A);
    M26.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M26A, B31, M26, numsteps - 1, x);
    M26A.deallocate();
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
    Matrix<Scalar> M27A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M27A);
    M27.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M27A, B12, M27, numsteps - 1, x);
    M27A.deallocate();
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
    Matrix<Scalar> M28A(A11.m(), A11.n());
    Add(A23, A32, Scalar(-1.0), Scalar(1.0), M28A);
    FastMatmulRecursive(M28A, B23, M28, numsteps - 1, x);
    M28A.deallocate();
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
    Matrix<Scalar> M29A(A11.m(), A11.n());
    Add(A23, A42, Scalar(1.0), Scalar(-1.0), M29A);
    Matrix<Scalar> M29B(B11.m(), B11.n());
    Add(B23, B32, Scalar(1.0), Scalar(-1.0), M29B);
    FastMatmulRecursive(M29A, M29B, M29, numsteps - 1, x);
    M29A.deallocate();
    M29B.deallocate();
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

}
  // namespace grey433_29_234
#endif  // _grey433_29_234_HPP_
