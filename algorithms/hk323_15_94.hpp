#ifndef _hk323_15_94_HPP_
#define _hk323_15_94_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace hk323_15_94 {

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
    int A_col_step = A.n() / 2;
    Matrix<Scalar> A11 = A.Subblock(3, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(3, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 2, 2, 2);
    Matrix<Scalar> A31 = A.Subblock(3, 2, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 2, 3, 2);
    int B_row_step = B.m() / 2;
    int B_col_step = B.n() / 3;
    Matrix<Scalar> B11 = B.Subblock(2, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(2, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 3, 2, 3);
    int C_row_step = C.m() / 3;
    int C_col_step = C.n() / 3;
    Matrix<Scalar> C11 = C.Subblock(3, 3, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(3, 3, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(3, 3, 1, 3);
    Matrix<Scalar> C21 = C.Subblock(3, 3, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(3, 3, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(3, 3, 2, 3);
    Matrix<Scalar> C31 = C.Subblock(3, 3, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(3, 3, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(3, 3, 3, 3);


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


    // M1 = (1.0 * A11 + 1.0 * A12) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    Add(A11, A12, Scalar(1.0), Scalar(1.0), S1);
    FastMatmulRecursive(S1, B21, M1, numsteps - 1, x);
    S1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A11) * (1.0 * B11 + -1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(-1.0), T2);
    FastMatmulRecursive(A11, T2, M2, numsteps - 1, x);
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A21 + 1.0 * A22) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(1.0), S3);
    FastMatmulRecursive(S3, B12, M3, numsteps - 1, x);
    S3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A11 + 1.0 * A21) * (1.0 * B11 + 1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A11, A21, Scalar(1.0), Scalar(1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B11, B12, Scalar(1.0), Scalar(1.0), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A11 + -1.0 * A22) * (1.0 * B12 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A11, A22, Scalar(1.0), Scalar(-1.0), S5);
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B12, B21, Scalar(1.0), Scalar(1.0), T5);
    FastMatmulRecursive(S5, T5, M5, numsteps - 1, x);
    S5.deallocate();
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A11 + -1.0 * A12 + 1.0 * A31 + 1.0 * A32) * (-1.0 * B11 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A11, A12, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B11, B13, Scalar(-1.0), Scalar(1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A31) * (1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A31, B13, M7, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A11 + 1.0 * A12 + -1.0 * A32) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A11, A12, A32, Scalar(1.0), Scalar(1.0), Scalar(-1.0), S8);
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B11, B13, B21, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T8);
    FastMatmulRecursive(S8, T8, M8, numsteps - 1, x);
    S8.deallocate();
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A22) * (1.0 * B12 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(-1.0), T9);
    FastMatmulRecursive(A22, T9, M9, numsteps - 1, x);
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A12 + 1.0 * A22) * (1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B21, B22, Scalar(1.0), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A21 + -1.0 * A22 + 1.0 * A31 + 1.0 * A32) * (-1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S11);
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), T11);
    FastMatmulRecursive(S11, T11, M11, numsteps - 1, x);
    S11.deallocate();
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A32) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A32, B23, M12, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A21 + 1.0 * A31) * (-1.0 * B12 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A21, A31, Scalar(-1.0), Scalar(1.0), S13);
    Matrix<Scalar> T13(B11.m(), B11.n());
    Add(B12, B13, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), T13);
    FastMatmulRecursive(S13, T13, M13, numsteps - 1, x);
    S13.deallocate();
    T13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A21 + -1.0 * A22 + 1.0 * A31) * (1.0 * B12 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A21, A22, A31, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B12, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A12 + 1.0 * A32) * (-1.0 * B11 + 1.0 * B13 + 1.0 * B21 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    Add(A12, A32, Scalar(-1.0), Scalar(1.0), S15);
    Matrix<Scalar> T15(B11.m(), B11.n());
    Add(B11, B13, B21, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), T15);
    FastMatmulRecursive(S15, T15, M15, numsteps - 1, x);
    S15.deallocate();
    T15.deallocate();
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


    Add(M1, M2, Scalar(1.0), Scalar(1.0), C11);
    Add(M1, M5, M9, M10, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M2, M8, M12, M15, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C13);
    Add(M2, M3, M4, M5, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C21);
    Add(M3, M9, Scalar(1.0), Scalar(-1.0), C22);
    Add(M7, M9, M13, M14, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C23);
    Add(M1, M6, M7, M8, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C31);
    Add(M3, M11, M12, M14, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M7, M12, Scalar(1.0), Scalar(1.0), C33);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 2, 3);
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

}  // namespace hk323_15_94

#endif  // _hk323_15_94_HPP_
