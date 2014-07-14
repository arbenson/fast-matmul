#ifndef _grey234_20_144_HPP_
#define _grey234_20_144_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey234_20_144 {

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

    int A_row_step = A.m() / 2;
    int A_col_step = A.n() / 3;
    Matrix<Scalar> A11 = A.Subblock(2, 3, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(2, 3, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(2, 3, 1, 3);
    Matrix<Scalar> A21 = A.Subblock(2, 3, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(2, 3, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(2, 3, 2, 3);
    int B_row_step = B.m() / 3;
    int B_col_step = B.n() / 4;
    Matrix<Scalar> B11 = B.Subblock(3, 4, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 4, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(3, 4, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(3, 4, 1, 4);
    Matrix<Scalar> B21 = B.Subblock(3, 4, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 4, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(3, 4, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(3, 4, 2, 4);
    Matrix<Scalar> B31 = B.Subblock(3, 4, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 4, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(3, 4, 3, 3);
    Matrix<Scalar> B34 = B.Subblock(3, 4, 3, 4);
    int C_row_step = C.m() / 2;
    int C_col_step = C.n() / 4;
    Matrix<Scalar> C11 = C.Subblock(2, 4, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(2, 4, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(2, 4, 1, 3);
    Matrix<Scalar> C14 = C.Subblock(2, 4, 1, 4);
    Matrix<Scalar> C21 = C.Subblock(2, 4, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(2, 4, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(2, 4, 2, 3);
    Matrix<Scalar> C24 = C.Subblock(2, 4, 2, 4);


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


    // M1 = (-1.0 * A11 + 1.0 * A12) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    Add(A11, A12, Scalar(-1.0), Scalar(1.0), S1);
    FastMatmulRecursive(S1, B11, M1, numsteps - 1, x);
    S1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (-1.0 * A22 + 1.0 * A23) * (1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A22, A23, Scalar(-1.0), Scalar(1.0), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A13) * (1.0 * B11 + 1.0 * B21 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T3(B11.m(), B11.n());
    Add(B11, B21, B31, Scalar(1.0), Scalar(1.0), Scalar(1.0), T3);
    M3.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A13, T3, M3, numsteps - 1, x);
    T3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A12 + 1.0 * A13 + 1.0 * A22) * (-1.0 * B11 + -1.0 * B21 + -1.0 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A12, A13, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B11, B21, B34, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A12 + 1.0 * A13 + 1.0 * A22 + -1.0 * A23) * (-1.0 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A12, A13, A22, A23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S5);
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S5, B34, M5, numsteps - 1, x);
    S5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A11 + 1.0 * A22) * (-1.0 * B14 + 1.0 * B23 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A11, A22, Scalar(1.0), Scalar(1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B14, B23, B33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A21 + -1.0 * A22 + 1.0 * A23) * (1.0 * B11 + -1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A21, A22, A23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B11, B12, Scalar(1.0), Scalar(-1.0), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (-1.0 * A12 + 1.0 * A13) * (1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A12, A13, Scalar(-1.0), Scalar(1.0), S8);
    FastMatmulRecursive(S8, B33, M8, numsteps - 1, x);
    S8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A21) * (1.0 * B12 + -1.0 * B13 + 1.0 * B14 + 1.0 * B22 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A11, A21, Scalar(-1.0), Scalar(1.0), S9);
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B12, B13, B14, B22, B33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), T9);
    FastMatmulRecursive(S9, T9, M9, numsteps - 1, x);
    S9.deallocate();
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A22) * (-1.0 * B11 + -1.0 * B14 + -1.0 * B21 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B11, B14, B21, B24, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T10);
    FastMatmulRecursive(A22, T10, M10, numsteps - 1, x);
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A12 + 1.0 * A22) * (-1.0 * B23 + 1.0 * B24 + -1.0 * B33 + 1.0 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A12, A22, Scalar(-1.0), Scalar(1.0), S11);
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B23, B24, B33, B34, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T11);
    FastMatmulRecursive(S11, T11, M11, numsteps - 1, x);
    S11.deallocate();
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A11 + 1.0 * A21 + -1.0 * A22 + 1.0 * A23) * (-1.0 * B12 + -1.0 * B22 + -1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A11, A21, A22, A23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S12);
    Matrix<Scalar> T12(B11.m(), B11.n());
    Add(B12, B22, B33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T12);
    FastMatmulRecursive(S12, T12, M12, numsteps - 1, x);
    S12.deallocate();
    T12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A21 + 1.0 * A22) * (1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(1.0), S13);
    FastMatmulRecursive(S13, B14, M13, numsteps - 1, x);
    S13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11) * (-1.0 * B13 + 1.0 * B23 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B13, B23, B33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T14);
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A11, T14, M14, numsteps - 1, x);
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A23) * (-1.0 * B11 + -1.0 * B22 + 1.0 * B31 + -1.0 * B32 + -1.0 * B34)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T15(B11.m(), B11.n());
    Add(B11, B22, B31, B32, B34, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), T15);
    FastMatmulRecursive(A23, T15, M15, numsteps - 1, x);
    T15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (-1.0 * A11 + -1.0 * A12) * (1.0 * B23 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A11, A12, Scalar(-1.0), Scalar(-1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B23, B33, Scalar(1.0), Scalar(1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A11 + 1.0 * A12 + -1.0 * A13 + 1.0 * A21 + -1.0 * A22 + 1.0 * A23) * (-1.0 * B32 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S17(A11.m(), A11.n());
    Add(A11, A12, A13, A21, A22, A23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), S17);
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B32, B33, Scalar(-1.0), Scalar(1.0), T17);
    FastMatmulRecursive(S17, T17, M17, numsteps - 1, x);
    S17.deallocate();
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A11 + -1.0 * A12 + -1.0 * A21 + 1.0 * A22 + -1.0 * A23) * (-1.0 * B11 + -1.0 * B22 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B11, B22, B32, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A12 + 1.0 * A13) * (1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A12, A13, Scalar(-1.0), Scalar(1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(1.0), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A21 + -1.0 * A22) * (1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B22, B32, Scalar(1.0), Scalar(1.0), T20);
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


    Add(M1, M3, M19, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C11);
    Add(M1, M7, M8, M12, M17, M18, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M8, M14, M16, Scalar(1.0), Scalar(1.0), Scalar(-1.0), C13);
    Add(M4, M6, M10, M11, M16, M19, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C14);
    Add(M1, M4, M5, M15, M18, M19, M20, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), C21);
    Add(M1, M2, M7, M18, M20, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M2, M6, M9, M12, M13, M14, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C23);
    Add(M4, M5, M10, M13, M19, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C24);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 2, 3, 4);
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

}  // namespace grey234_20_144

#endif  // _grey234_20_144_HPP_
