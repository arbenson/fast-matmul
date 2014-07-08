#ifndef _bini322_HPP_
#define _bini322_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace bini322 {
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
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
    int B_col_step = B.n() / 2;
    Matrix<Scalar> B11 = B.Subblock(2, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(2, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 2, 2, 2);
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


#ifdef _OPEN_MP_
    #pragma omp parallel
    {
    #pragma omp single
        {
#endif
    // M1 = (1.0 * A11 + 1.0 * A22) * (x * B11 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A11, A22, Scalar(1.0), Scalar(1.0), M1A);
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B11, B22, Scalar(x), Scalar(1.0), M1B);
    FastMatmul(M1A, M1B, M1, numsteps - 1, x);
    M1A.deallocate();
    M1B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A22) * (-1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(-1.0), M2B);
    FastMatmul(A22, M2B, M2, numsteps - 1, x);
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A11) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmul(A11, B22, M3, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (x * A12 + 1.0 * A22) * (-(x) * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A12, A22, Scalar(x), Scalar(1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B21, Scalar(-(x)), Scalar(1.0), M4B);
    FastMatmul(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A11 + x * A12) * (x * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A11, A12, Scalar(1.0), Scalar(x), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B12, B22, Scalar(x), Scalar(1.0), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A21 + 1.0 * A32) * (1.0 * B11 + x * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A21, A32, Scalar(1.0), Scalar(1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B11, B22, Scalar(1.0), Scalar(x), M6B);
    FastMatmul(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A32) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmul(A32, B11, M7, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A21) * (-1.0 * B11 + -1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(-1.0), M8B);
    FastMatmul(A21, M8B, M8, numsteps - 1, x);
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (x * A31 + 1.0 * A32) * (1.0 * B11 + x * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A31, A32, Scalar(x), Scalar(1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(x), M9B);
    FastMatmul(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A21 + x * A31) * (1.0 * B12 + -(x) * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A21, A31, Scalar(1.0), Scalar(x), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(-(x)), M10B);
    FastMatmul(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

#ifdef _CILK_
    cilk_sync;
#elif defined _OPEN_MP_
        }  // End omp single region
    }  // End omp parallel region
#endif


    Add(M1, M2, M3, M4, Scalar(1.0 / (x)), Scalar(1.0 / (x)), Scalar(-(1.0 / (x))), Scalar(1.0 / (x)), C11);
    Add(M3, M5, Scalar(-(1.0 / (x))), Scalar(1.0 / (x)), C12);
    Add(M4, M6, M9, Scalar(1.0), Scalar(1.0), Scalar(-1.0), C21);
    Add(M1, M5, M10, Scalar(1.0), Scalar(-1.0), Scalar(1.0), C22);
    Add(M7, M9, Scalar(-(1.0 / (x))), Scalar(1.0 / (x)), C31);
    Add(M6, M7, M8, M10, Scalar(1.0 / (x)), Scalar(-(1.0 / (x))), Scalar(1.0 / (x)), Scalar(1.0 / (x)), C32);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 2, 2);
}

}
  // namespace bini322
#endif  // _bini322_HPP_
