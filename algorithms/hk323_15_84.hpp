#ifndef _hk323_15_84_HPP_
#define _hk323_15_84_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace hk323_15_84 {

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
    

    Matrix<Scalar> A_X1(A11.m(), A11.n());
    Add(A11, A12, Scalar(1.0), Scalar(1.0), A_X1);
    Matrix<Scalar> A_X2(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(1.0), A_X2);
    Matrix<Scalar> A_X3(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(1.0), A_X3);
    

    Matrix<Scalar> B_X1(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(-1.0), B_X1);
    Matrix<Scalar> B_X2(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(-1.0), B_X2);
    Matrix<Scalar> B_X3(B11.m(), B11.n());
    Add(B13, B23, Scalar(1.0), Scalar(-1.0), B_X3);


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


    // M1 = (1.0 * A_X1) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A_X1, B21, M1, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A11) * (1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A11, B_X1, M2, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A_X2) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A_X2, B12, M3, numsteps - 1, x);
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
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A11, A21, Scalar(1.0), Scalar(1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B12, Scalar(1.0), Scalar(1.0), M4B);
    FastMatmulRecursive(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
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
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A11, A22, Scalar(1.0), Scalar(-1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B12, B21, Scalar(1.0), Scalar(1.0), M5B);
    FastMatmulRecursive(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A_X1 + 1.0 * A_X3) * (-1.0 * B11 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A_X1, A_X3, Scalar(-1.0), Scalar(1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B11, B13, Scalar(-1.0), Scalar(1.0), M6B);
    FastMatmulRecursive(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
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

    // M8 = (-1.0 * A32 + 1.0 * A_X1) * (1.0 * B13 + -1.0 * B_X1)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A32, A_X1, Scalar(-1.0), Scalar(1.0), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B13, B_X1, Scalar(1.0), Scalar(-1.0), M8B);
    FastMatmulRecursive(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A22) * (1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B_X2, M9, numsteps - 1, x);
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
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B21, B22, Scalar(1.0), Scalar(1.0), M10B);
    FastMatmulRecursive(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A_X2 + 1.0 * A_X3) * (-1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A_X2, A_X3, Scalar(-1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), M11B);
    FastMatmulRecursive(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
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

    // M13 = (-1.0 * A21 + 1.0 * A31) * (-1.0 * B_X2 + 1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A21, A31, Scalar(-1.0), Scalar(1.0), M13A);
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B_X2, B_X3, Scalar(-1.0), Scalar(1.0), M13B);
    FastMatmulRecursive(M13A, M13B, M13, numsteps - 1, x);
    M13A.deallocate();
    M13B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (1.0 * A31 + -1.0 * A_X2) * (1.0 * B23 + 1.0 * B_X2)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A31, A_X2, Scalar(1.0), Scalar(-1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B23, B_X2, Scalar(1.0), Scalar(1.0), M14B);
    FastMatmulRecursive(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A12 + 1.0 * A32) * (-1.0 * B_X1 + 1.0 * B_X3)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A12, A32, Scalar(-1.0), Scalar(1.0), M15A);
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B_X1, B_X3, Scalar(-1.0), Scalar(1.0), M15B);
    FastMatmulRecursive(M15A, M15B, M15, numsteps - 1, x);
    M15A.deallocate();
    M15B.deallocate();
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

}
  // namespace hk323_15_84
#endif  // _hk323_15_84_HPP_
