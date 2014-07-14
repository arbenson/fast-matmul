#ifndef _grey522_18_99_HPP_
#define _grey522_18_99_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey522_18_99 {

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

    int A_row_step = A.m() / 5;
    int A_col_step = A.n() / 2;
    Matrix<Scalar> A11 = A.Subblock(5, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(5, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(5, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(5, 2, 2, 2);
    Matrix<Scalar> A31 = A.Subblock(5, 2, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(5, 2, 3, 2);
    Matrix<Scalar> A41 = A.Subblock(5, 2, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(5, 2, 4, 2);
    Matrix<Scalar> A51 = A.Subblock(5, 2, 5, 1);
    Matrix<Scalar> A52 = A.Subblock(5, 2, 5, 2);
    int B_row_step = B.m() / 2;
    int B_col_step = B.n() / 2;
    Matrix<Scalar> B11 = B.Subblock(2, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(2, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 2, 2, 2);
    int C_row_step = C.m() / 5;
    int C_col_step = C.n() / 2;
    Matrix<Scalar> C11 = C.Subblock(5, 2, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(5, 2, 1, 2);
    Matrix<Scalar> C21 = C.Subblock(5, 2, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(5, 2, 2, 2);
    Matrix<Scalar> C31 = C.Subblock(5, 2, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(5, 2, 3, 2);
    Matrix<Scalar> C41 = C.Subblock(5, 2, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(5, 2, 4, 2);
    Matrix<Scalar> C51 = C.Subblock(5, 2, 5, 1);
    Matrix<Scalar> C52 = C.Subblock(5, 2, 5, 2);


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


    // M1 = (-1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M1.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A32, B21, M1, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A41 + 1.0 * A52) * (1.0 * B11 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A41, A52, Scalar(1.0), Scalar(1.0), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B11, B22, Scalar(1.0), Scalar(1.0), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A31) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M3.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A31, B11, M3, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A52) * (1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(1.0), T4);
    FastMatmulRecursive(A52, T4, M4, numsteps - 1, x);
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A11 + -1.0 * A12 + -1.0 * A21 + 1.0 * A22) * (-1.0 * B11 + 1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S5);
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(1.0), T5);
    FastMatmulRecursive(S5, T5, M5, numsteps - 1, x);
    S5.deallocate();
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A41) * (1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), T6);
    FastMatmulRecursive(A41, T6, M6, numsteps - 1, x);
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A41 + -1.0 * A51) * (1.0 * B11 + -1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A41, A51, Scalar(-1.0), Scalar(-1.0), S7);
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

    // M8 = (1.0 * A31) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A31, B12, M8, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A12 + -1.0 * A22) * (-1.0 * B11 + 1.0 * B12 + -1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(-1.0), S9);
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T9);
    FastMatmulRecursive(S9, T9, M9, numsteps - 1, x);
    S9.deallocate();
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A42 + 1.0 * A52) * (-1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A42, A52, Scalar(1.0), Scalar(1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A12 + 1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A12, A32, Scalar(1.0), Scalar(1.0), S11);
    FastMatmulRecursive(S11, B21, M11, numsteps - 1, x);
    S11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A21 + 1.0 * A22 + -1.0 * A31) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A21, A22, A31, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S12);
    FastMatmulRecursive(S12, B22, M12, numsteps - 1, x);
    S12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A41 + 1.0 * A42) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A41, A42, Scalar(-1.0), Scalar(1.0), S13);
    FastMatmulRecursive(S13, B22, M13, numsteps - 1, x);
    S13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A12 + -1.0 * A21 + 1.0 * A22 + -1.0 * A31) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A12, A21, A22, A31, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B11, B12, B22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A11 + 1.0 * A31) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    Add(A11, A31, Scalar(1.0), Scalar(1.0), S15);
    FastMatmulRecursive(S15, B11, M15, numsteps - 1, x);
    S15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A21 + 1.0 * A31) * (1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A21, A31, Scalar(1.0), Scalar(1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A32) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M17.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A32, B22, M17, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A51 + -1.0 * A52) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A51, A52, Scalar(1.0), Scalar(-1.0), S18);
    FastMatmulRecursive(S18, B11, M18, numsteps - 1, x);
    S18.deallocate();
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


    Add(M1, M3, M11, M15, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C11);
    Add(M5, M8, M12, M14, M15, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C12);
    Add(M1, M3, M9, M11, M14, M16, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C21);
    Add(M8, M12, M16, Scalar(-1.0), Scalar(1.0), Scalar(1.0), C22);
    Add(M1, M3, Scalar(-1.0), Scalar(-1.0), C31);
    Add(M8, M17, Scalar(1.0), Scalar(-1.0), C32);
    Add(M2, M4, M10, M13, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C41);
    Add(M6, M13, Scalar(1.0), Scalar(1.0), C42);
    Add(M4, M18, Scalar(1.0), Scalar(1.0), C51);
    Add(M2, M6, M7, M18, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C52);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 5, 2, 2);
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

}  // namespace grey522_18_99

#endif  // _grey522_18_99_HPP_
