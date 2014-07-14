#ifndef _grey342_20_144_HPP_
#define _grey342_20_144_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey342_20_144 {

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
    int A_col_step = A.n() / 4;
    Matrix<Scalar> A11 = A.Subblock(3, 4, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 4, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(3, 4, 1, 3);
    Matrix<Scalar> A14 = A.Subblock(3, 4, 1, 4);
    Matrix<Scalar> A21 = A.Subblock(3, 4, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 4, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(3, 4, 2, 3);
    Matrix<Scalar> A24 = A.Subblock(3, 4, 2, 4);
    Matrix<Scalar> A31 = A.Subblock(3, 4, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 4, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(3, 4, 3, 3);
    Matrix<Scalar> A34 = A.Subblock(3, 4, 3, 4);
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
    int C_row_step = C.m() / 3;
    int C_col_step = C.n() / 2;
    Matrix<Scalar> C11 = C.Subblock(3, 2, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(3, 2, 1, 2);
    Matrix<Scalar> C21 = C.Subblock(3, 2, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(3, 2, 2, 2);
    Matrix<Scalar> C31 = C.Subblock(3, 2, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(3, 2, 3, 2);


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


    // M1 = (1.0 * A11) * (-1.0 * B11 + -1.0 * B12 + -1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T1(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T1);
    FastMatmulRecursive(A11, T1, M1, numsteps - 1, x);
    T1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A12 + 1.0 * A22) * (-1.0 * B22 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B22, B32, Scalar(-1.0), Scalar(-1.0), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A11 + 1.0 * A21 + 1.0 * A31) * (-1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    Add(A11, A21, A31, Scalar(1.0), Scalar(1.0), Scalar(1.0), S3);
    M3.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S3, B11, M3, numsteps - 1, x);
    S3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A11 + -1.0 * A21 + -1.0 * A34) * (-1.0 * B12 + -1.0 * B41 + -1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A11, A21, A34, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B12, B41, B42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A34) * (1.0 * B12 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B12, B42, Scalar(1.0), Scalar(1.0), T5);
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A34, T5, M5, numsteps - 1, x);
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A14 + 1.0 * A23 + 1.0 * A33) * (1.0 * B32 + -1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A14, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B32, B41, Scalar(1.0), Scalar(-1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A11 + -1.0 * A12) * (-1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A11, A12, Scalar(1.0), Scalar(-1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(-1.0), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A33) * (1.0 * B21 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B21, B31, Scalar(1.0), Scalar(1.0), T8);
    FastMatmulRecursive(A33, T8, M8, numsteps - 1, x);
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A12 + -1.0 * A13 + 1.0 * A14 + 1.0 * A22 + 1.0 * A33) * (-1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A12, A13, A14, A22, A33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), S9);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S9, B32, M9, numsteps - 1, x);
    S9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-1.0 * A11 + -1.0 * A14 + -1.0 * A21 + 1.0 * A24) * (1.0 * B41 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A11, A14, A21, A24, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B41, B42, Scalar(1.0), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A23 + 1.0 * A24 + -1.0 * A33 + 1.0 * A34) * (-1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A23, A24, A33, A34, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S11);
    M11.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S11, B41, M11, numsteps - 1, x);
    S11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A12 + -1.0 * A22 + -1.0 * A33) * (1.0 * B21 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A12, A22, A33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S12);
    Matrix<Scalar> T12(B11.m(), B11.n());
    Add(B21, B32, Scalar(1.0), Scalar(-1.0), T12);
    FastMatmulRecursive(S12, T12, M12, numsteps - 1, x);
    S12.deallocate();
    T12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A14) * (1.0 * B32 + 1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T13(B11.m(), B11.n());
    Add(B32, B42, Scalar(1.0), Scalar(1.0), T13);
    FastMatmulRecursive(A14, T13, M13, numsteps - 1, x);
    T13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A13 + 1.0 * A23 + 1.0 * A33) * (1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A13, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B31, B32, Scalar(1.0), Scalar(1.0), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A11 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + -1.0 * A34) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    Add(A11, A22, A31, A32, A34, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S15);
    FastMatmulRecursive(S15, B12, M15, numsteps - 1, x);
    S15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A23 + 1.0 * A33) * (-1.0 * B31 + -1.0 * B41)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A23, A33, Scalar(1.0), Scalar(1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B31, B41, Scalar(-1.0), Scalar(-1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A32 + 1.0 * A33) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S17(A11.m(), A11.n());
    Add(A32, A33, Scalar(-1.0), Scalar(1.0), S17);
    FastMatmulRecursive(S17, B21, M17, numsteps - 1, x);
    S17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (-1.0 * A11 + -1.0 * A22 + -1.0 * A32) * (1.0 * B12 + 1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A11, A22, A32, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B12, B21, B22, Scalar(1.0), Scalar(1.0), Scalar(1.0), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (1.0 * A11 + 1.0 * A21) * (-1.0 * B11 + -1.0 * B12 + -1.0 * B41 + -1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A11, A21, Scalar(1.0), Scalar(1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B11, B12, B41, B42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A22 + 1.0 * A32) * (-1.0 * B12 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A22, A32, Scalar(1.0), Scalar(1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B12, B22, Scalar(-1.0), Scalar(-1.0), T20);
    FastMatmulRecursive(S20, T20, M20, numsteps - 1, x);
    S20.deallocate();
    T20.deallocate();
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


    Add(M1, M6, M9, M12, M14, M16, M17, M18, M20, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C11);
    Add(M7, M9, M12, M13, M17, M18, M20, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C12);
    Add(M1, M4, M5, M8, M11, M16, M17, M18, M19, M20, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C21);
    Add(M2, M4, M5, M6, M7, M10, M11, M12, M13, M17, M18, M20, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M3, M4, M5, M8, M17, M19, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C31);
    Add(M2, M5, M7, M12, M15, M17, M18, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C32);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 4, 2);
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

}  // namespace grey342_20_144

#endif  // _grey342_20_144_HPP_
