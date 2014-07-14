#ifndef _grey333_23_125_HPP_
#define _grey333_23_125_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey333_23_125 {

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
    

    Matrix<Scalar> A_X1(A11.m(), A11.n());
    Add(A13, A21, Scalar(1.0), Scalar(1.0), A_X1);
    Matrix<Scalar> A_X2(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(-1.0), A_X2);
    Matrix<Scalar> A_X3(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(-1.0), A_X3);
    Matrix<Scalar> A_X4(A11.m(), A11.n());
    Add(A11, A31, Scalar(-1.0), Scalar(-1.0), A_X4);
    Matrix<Scalar> A_X5(A11.m(), A11.n());
    Add(A11, A12, Scalar(-1.0), Scalar(1.0), A_X5);
    Matrix<Scalar> A_X6(A11.m(), A11.n());
    Add(A23, A33, Scalar(-1.0), Scalar(-1.0), A_X6);
    

    Matrix<Scalar> B_X1(B11.m(), B11.n());
    Add(B11, B21, Scalar(-1.0), Scalar(-1.0), B_X1);
    Matrix<Scalar> B_X2(B11.m(), B11.n());
    Add(B13, B23, Scalar(1.0), Scalar(1.0), B_X2);
    Matrix<Scalar> B_X3(B11.m(), B11.n());
    Add(B32, B33, Scalar(1.0), Scalar(-1.0), B_X3);
    Matrix<Scalar> B_X4(B11.m(), B11.n());
    Add(B23, B32, Scalar(-1.0), Scalar(1.0), B_X4);
    Matrix<Scalar> B_X5(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(-1.0), B_X5);
    Matrix<Scalar> B_X6(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), B_X6);
    Matrix<Scalar> B_X7(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), B_X7);


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


    // M1 = (-1.0 * A12) * (1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M1.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A12, B_X1, M1, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (-1.0 * A13) * (-1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M2.UpdateMultiplier(Scalar(-1));
    M2.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A13, B31, M2, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A_X1) * (1.0 * B_X2 + 1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T3(B11.m(), B11.n());
    Add(B_X2, B_X3, Scalar(1.0), Scalar(1.0), T3);
    FastMatmulRecursive(A_X1, T3, M3, numsteps - 1, x);
    T3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A_X2 + 1.0 * A_X3) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A_X2, A_X3, Scalar(1.0), Scalar(1.0), S4);
    FastMatmulRecursive(S4, B11, M4, numsteps - 1, x);
    S4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A13 + 1.0 * A_X4) * (1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A13, A_X4, Scalar(-1.0), Scalar(1.0), S5);
    FastMatmulRecursive(S5, B_X2, M5, numsteps - 1, x);
    S5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A33 + 1.0 * A_X2) * (1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A33, A_X2, Scalar(1.0), Scalar(1.0), S6);
    FastMatmulRecursive(S6, B_X4, M6, numsteps - 1, x);
    S6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A31) * (1.0 * B13 + 1.0 * B_X5)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B13, B_X5, Scalar(1.0), Scalar(1.0), T7);
    FastMatmulRecursive(A31, T7, M7, numsteps - 1, x);
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A13) * (1.0 * B33 + -1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B33, B_X2, Scalar(1.0), Scalar(-1.0), T8);
    FastMatmulRecursive(A13, T8, M8, numsteps - 1, x);
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A_X5) * (-1.0 * B_X5)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A_X5, B_X5, M9, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A22 + 1.0 * A23 + -1.0 * A_X1) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A22, A23, A_X1, Scalar(1.0), Scalar(1.0), Scalar(-1.0), S10);
    FastMatmulRecursive(S10, B32, M10, numsteps - 1, x);
    S10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A33) * (-1.0 * B23 + 1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B23, B33, Scalar(-1.0), Scalar(1.0), T11);
    M11.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A33, T11, M11, numsteps - 1, x);
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A12 + -1.0 * A21) * (1.0 * B_X6)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A12, A21, Scalar(1.0), Scalar(-1.0), S12);
    FastMatmulRecursive(S12, B_X6, M12, numsteps - 1, x);
    S12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A21 + 1.0 * A_X6) * (-1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A21, A_X6, Scalar(-1.0), Scalar(1.0), S13);
    M13.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S13, B_X3, M13, numsteps - 1, x);
    S13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A32 + 1.0 * A_X2) * (1.0 * B11 + 1.0 * B_X7)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A32, A_X2, Scalar(-1.0), Scalar(1.0), S14);
    Matrix<Scalar> T14(B11.m(), B11.n());
    Add(B11, B_X7, Scalar(1.0), Scalar(1.0), T14);
    FastMatmulRecursive(S14, T14, M14, numsteps - 1, x);
    S14.deallocate();
    T14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A_X6) * (-1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M15.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A_X6, B31, M15, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (-1.0 * A_X5) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M16.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A_X5, B11, M16, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A32) * (1.0 * B21 + -1.0 * B_X7)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B21, B_X7, Scalar(1.0), Scalar(-1.0), T17);
    FastMatmulRecursive(A32, T17, M17, numsteps - 1, x);
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A21) * (-1.0 * B_X2 + -1.0 * B_X3 + 1.0 * B_X6)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B_X2, B_X3, B_X6, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T18);
    FastMatmulRecursive(A21, T18, M18, numsteps - 1, x);
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A12 + -1.0 * A_X4) * (1.0 * B23 + -1.0 * B_X5)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A12, A_X4, Scalar(-1.0), Scalar(-1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B23, B_X5, Scalar(1.0), Scalar(-1.0), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A_X2) * (-1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B22, B32, Scalar(-1.0), Scalar(1.0), T20);
    FastMatmulRecursive(A_X2, T20, M20, numsteps - 1, x);
    T20.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (1.0 * A33 + -1.0 * A_X3 + 1.0 * A_X5) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S21(A11.m(), A11.n());
    Add(A33, A_X3, A_X5, Scalar(1.0), Scalar(-1.0), Scalar(1.0), S21);
    FastMatmulRecursive(S21, B23, M21, numsteps - 1, x);
    S21.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (1.0 * A22 + 1.0 * A32) * (-1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S22(A11.m(), A11.n());
    Add(A22, A32, Scalar(1.0), Scalar(1.0), S22);
    M22.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S22, B_X1, M22, numsteps - 1, x);
    S22.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A33) * (1.0 * B31 + 1.0 * B_X4)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T23(B11.m(), B11.n());
    Add(B31, B_X4, Scalar(1.0), Scalar(1.0), T23);
    FastMatmulRecursive(A33, T23, M23, numsteps - 1, x);
    T23.deallocate();
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
    Add(M3, M8, Scalar(1.0), Scalar(1.0), M_X1);
    Matrix<Scalar> M_X2(C11.m(), C11.n());
    Add(M7, M9, Scalar(-1.0), Scalar(-1.0), M_X2);
    Matrix<Scalar> M_X3(C11.m(), C11.n());
    Add(M6, M14, Scalar(1.0), Scalar(1.0), M_X3);
    Matrix<Scalar> M_X4(C11.m(), C11.n());
    Add(M17, M20, Scalar(-1.0), Scalar(-1.0), M_X4);
    Matrix<Scalar> M_X5(C11.m(), C11.n());
    Add(M19, M21, Scalar(1.0), Scalar(1.0), M_X5);


    Add(M1, M2, M16, Scalar(1.0), Scalar(1.0), Scalar(1.0), C11);
    Add(M9, M12, M16, M18, M_X1, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M5, M8, M19, M_X2, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C13);
    Add(M15, M22, M23, M_X3, M_X4, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C21);
    Add(M10, M18, M20, M_X1, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C22);
    Add(M6, M10, M11, M13, M_X1, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C23);
    Add(M4, M23, M_X3, M_X4, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), C31);
    Add(M4, M9, M20, M_X3, M_X5, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M11, M_X2, M_X5, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C33);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 3, 3);
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

}  // namespace grey333_23_125

#endif  // _grey333_23_125_HPP_
