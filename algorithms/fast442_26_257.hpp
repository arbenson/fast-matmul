#ifndef _grey442_26_257_HPP_
#define _grey442_26_257_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey442_26_257 {

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
    int A_col_step = A.n() / 4;
    Matrix<Scalar> A11 = A.Subblock(4, 4, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(4, 4, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(4, 4, 1, 3);
    Matrix<Scalar> A14 = A.Subblock(4, 4, 1, 4);
    Matrix<Scalar> A21 = A.Subblock(4, 4, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(4, 4, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(4, 4, 2, 3);
    Matrix<Scalar> A24 = A.Subblock(4, 4, 2, 4);
    Matrix<Scalar> A31 = A.Subblock(4, 4, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(4, 4, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(4, 4, 3, 3);
    Matrix<Scalar> A34 = A.Subblock(4, 4, 3, 4);
    Matrix<Scalar> A41 = A.Subblock(4, 4, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(4, 4, 4, 2);
    Matrix<Scalar> A43 = A.Subblock(4, 4, 4, 3);
    Matrix<Scalar> A44 = A.Subblock(4, 4, 4, 4);
    int B_row_step = B.m() / 4;
    int B_col_step = B.n() / 2;
    Matrix<Scalar> B11 = B.Subblock(4, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(4, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(4, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(4, 2, 2, 2);
    Matrix<Scalar> B31 = B.Subblock(4, 2, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(4, 2, 3, 2);
    Matrix<Scalar> B41 = B.Subblock(4, 2, 4, 1);
    Matrix<Scalar> B42 = B.Subblock(4, 2, 4, 2);
    int C_row_step = C.m() / 4;
    int C_col_step = C.n() / 2;
    Matrix<Scalar> C11 = C.Subblock(4, 2, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 2, 1, 2);
    Matrix<Scalar> C21 = C.Subblock(4, 2, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 2, 2, 2);
    Matrix<Scalar> C31 = C.Subblock(4, 2, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 2, 3, 2);
    Matrix<Scalar> C41 = C.Subblock(4, 2, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 2, 4, 2);


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


    // M1 = (1.0 * A11) * (1.0 * B11 + 1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B11, B41, Scalar(1.0), Scalar(1.0), M1B);
    FastMatmulRecursive(A11, M1B, M1, numsteps - 1, x);
    M1B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A21 + 1.0 * A22 + 1.0 * A23 + 1.0 * A32 + 1.0 * A33 + -1.0 * A41) * (-1.0 * B11 + -1.0 * B12 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A21, A22, A23, A32, A33, A41, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B11, B12, B31, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M2B);
    FastMatmulRecursive(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A13) * (1.0 * B21 + -1.0 * B31 + -1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B21, B31, B41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M3B);
    FastMatmulRecursive(A13, M3B, M3, numsteps - 1, x);
    M3B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A11 + 0.5 * A24 + 0.5 * A34) * (1.0 * B11 + 1.0 * B12 + 1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A11, A24, A34, Scalar(-1.0), Scalar(0.5), Scalar(0.5), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B12, B41, Scalar(1.0), Scalar(1.0), Scalar(1.0), M4B);
    FastMatmulRecursive(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A24 + -1.0 * A32 + -1.0 * A33 + 1.0 * A42 + 1.0 * A43 + -1.0 * A44) * (1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A24, A32, A33, A42, A43, A44, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B21, B22, Scalar(1.0), Scalar(-1.0), M5B);
    FastMatmulRecursive(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A12 + -1.0 * A13) * (1.0 * B22 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A12, A13, Scalar(-1.0), Scalar(-1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B22, B42, Scalar(1.0), Scalar(1.0), M6B);
    FastMatmulRecursive(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-0.5 * A24 + -0.5 * A34) * (1.0 * B11 + 1.0 * B12 + 1.0 * B41 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A24, A34, Scalar(-0.5), Scalar(-0.5), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B11, B12, B41, B42, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M7B);
    FastMatmulRecursive(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (0.5 * A21 + 0.5 * A23 + -0.5 * A24 + 0.5 * A31 + 0.5 * A33 + -0.5 * A34) * (1.0 * B11 + 1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A21, A23, A24, A31, A33, A34, Scalar(0.5), Scalar(0.5), Scalar(-0.5), Scalar(0.5), Scalar(0.5), Scalar(-0.5), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B11, B12, Scalar(1.0), Scalar(1.0), M8B);
    FastMatmulRecursive(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A41) * (-1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A11, A41, Scalar(-1.0), Scalar(1.0), M9A);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M9A, B12, M9, numsteps - 1, x);
    M9A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-0.5 * A24 + 0.5 * A34) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32 + -1.0 * B41 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A24, A34, Scalar(-0.5), Scalar(0.5), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B21, B22, B31, B32, B41, B42, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M10B);
    FastMatmulRecursive(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A12 + 1.0 * A13 + -1.0 * A24 + 1.0 * A44) * (-1.0 * B21 + 1.0 * B22 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A12, A13, A24, A44, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B21, B22, B42, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M11B);
    FastMatmulRecursive(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A12 + 1.0 * A13 + -1.0 * A14 + 1.0 * A24) * (1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A12, A13, A14, A24, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M12A);
    FastMatmulRecursive(M12A, B42, M12, numsteps - 1, x);
    M12A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A12 + 1.0 * A13 + -1.0 * A22 + 1.0 * A42) * (-1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A12, A13, A22, A42, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M13A);
    M13.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M13A, B21, M13, numsteps - 1, x);
    M13A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11 + -1.0 * A13 + 1.0 * A14 + -1.0 * A24 + 1.0 * A44) * (-1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A11, A13, A14, A24, A44, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M14A);
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M14A, B41, M14, numsteps - 1, x);
    M14A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A24 + 1.0 * A44) * (1.0 * B21 + -1.0 * B22 + 1.0 * B41 + -1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A24, A44, Scalar(-1.0), Scalar(1.0), M15A);
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B21, B22, B41, B42, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M15B);
    FastMatmulRecursive(M15A, M15B, M15, numsteps - 1, x);
    M15A.deallocate();
    M15B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (0.5 * A22 + -0.5 * A31 + 0.5 * A32 + 0.5 * A41) * (1.0 * B11 + 1.0 * B12 + 1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A22, A31, A32, A41, Scalar(0.5), Scalar(-0.5), Scalar(0.5), Scalar(0.5), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, B31, B32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M16B);
    FastMatmulRecursive(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (0.5 * A31 + -0.5 * A41) * (1.0 * B11 + -1.0 * B12 + 1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M17A(A11.m(), A11.n());
    Add(A31, A41, Scalar(0.5), Scalar(-0.5), M17A);
    Matrix<Scalar> M17B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, B31, B32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M17B);
    FastMatmulRecursive(M17A, M17B, M17, numsteps - 1, x);
    M17A.deallocate();
    M17B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (0.5 * A24 + 0.5 * A31 + 0.5 * A33 + -0.5 * A34 + -0.5 * A41 + -0.5 * A43) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A24, A31, A33, A34, A41, A43, Scalar(0.5), Scalar(0.5), Scalar(0.5), Scalar(-0.5), Scalar(-0.5), Scalar(-0.5), M18A);
    Matrix<Scalar> M18B(B11.m(), B11.n());
    Add(B21, B22, B31, B32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M18B);
    FastMatmulRecursive(M18A, M18B, M18, numsteps - 1, x);
    M18A.deallocate();
    M18B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-0.5 * A21 + -0.5 * A23 + 0.5 * A41 + 0.5 * A43) * (-1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A21, A23, A41, A43, Scalar(-0.5), Scalar(-0.5), Scalar(0.5), Scalar(0.5), M19A);
    M19.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M19A, B31, M19, numsteps - 1, x);
    M19A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (0.5 * A22 + 0.5 * A32) * (1.0 * B11 + 1.0 * B12 + 1.0 * B21 + 1.0 * B22 + -1.0 * B31 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M20A(A11.m(), A11.n());
    Add(A22, A32, Scalar(0.5), Scalar(0.5), M20A);
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, B31, B32, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M20B);
    FastMatmulRecursive(M20A, M20B, M20, numsteps - 1, x);
    M20A.deallocate();
    M20B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (-1.0 * A13 + 0.5 * A24 + -0.5 * A34) * (1.0 * B21 + -1.0 * B22 + -1.0 * B31 + 1.0 * B32 + -1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M21A(A11.m(), A11.n());
    Add(A13, A24, A34, Scalar(-1.0), Scalar(0.5), Scalar(-0.5), M21A);
    Matrix<Scalar> M21B(B11.m(), B11.n());
    Add(B21, B22, B31, B32, B41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M21B);
    FastMatmulRecursive(M21A, M21B, M21, numsteps - 1, x);
    M21A.deallocate();
    M21B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (-1.0 * A22 + -1.0 * A23 + -1.0 * A32 + -1.0 * A33) * (1.0 * B11 + 1.0 * B12 + -1.0 * B31 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M22A(A11.m(), A11.n());
    Add(A22, A23, A32, A33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M22A);
    Matrix<Scalar> M22B(B11.m(), B11.n());
    Add(B11, B12, B31, B32, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M22B);
    FastMatmulRecursive(M22A, M22B, M22, numsteps - 1, x);
    M22A.deallocate();
    M22B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A32 + 1.0 * A33) * (-1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M23A(A11.m(), A11.n());
    Add(A32, A33, Scalar(1.0), Scalar(1.0), M23A);
    M23.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(M23A, B32, M23, numsteps - 1, x);
    M23A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (1.0 * A13 + 1.0 * A22) * (1.0 * B22 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M24A(A11.m(), A11.n());
    Add(A13, A22, Scalar(1.0), Scalar(1.0), M24A);
    Matrix<Scalar> M24B(B11.m(), B11.n());
    Add(B22, B32, Scalar(1.0), Scalar(-1.0), M24B);
    FastMatmulRecursive(M24A, M24B, M24, numsteps - 1, x);
    M24A.deallocate();
    M24B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-1.0 * A22 + 1.0 * A32 + 1.0 * A33 + -1.0 * A43) * (1.0 * B21 + -1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M25A(A11.m(), A11.n());
    Add(A22, A32, A33, A43, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M25A);
    Matrix<Scalar> M25B(B11.m(), B11.n());
    Add(B21, B22, B32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M25B);
    FastMatmulRecursive(M25A, M25B, M25, numsteps - 1, x);
    M25A.deallocate();
    M25B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (1.0 * A21 + -1.0 * A41) * (1.0 * B11 + -1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M26A(A11.m(), A11.n());
    Add(A21, A41, Scalar(1.0), Scalar(-1.0), M26A);
    Matrix<Scalar> M26B(B11.m(), B11.n());
    Add(B11, B31, Scalar(1.0), Scalar(-1.0), M26B);
    FastMatmulRecursive(M26A, M26B, M26, numsteps - 1, x);
    M26A.deallocate();
    M26B.deallocate();
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


    Add(M1, M3, M6, M11, M14, M15, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C11);
    Add(M1, M3, M4, M6, M7, M10, M12, M21, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C12);
    Add(M1, M2, M3, M4, M8, M9, M16, M18, M19, M21, M24, M25, M26, Scalar(1.0), Scalar(0.5), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-0.5), Scalar(1.0), C21);
    Add(M1, M2, M3, M4, M7, M9, M10, M21, M22, M23, M24, M26, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M1, M2, M3, M4, M8, M9, M17, M18, M19, M20, M21, M24, M25, Scalar(1.0), Scalar(0.5), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(0.5), C31);
    Add(M1, M3, M4, M7, M9, M10, M16, M17, M20, M21, M23, M24, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), C32);
    Add(M1, M2, M3, M4, M6, M8, M9, M11, M13, M15, M16, M18, M19, M21, M24, M25, Scalar(1.0), Scalar(0.5), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-0.5), C41);
    Add(M1, M3, M4, M5, M6, M7, M9, M10, M11, M13, M21, M23, M24, M25, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C42);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 4, 4, 2);
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
  // namespace grey442_26_257
#endif  // _grey442_26_257_HPP_
