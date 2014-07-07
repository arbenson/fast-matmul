#ifndef _grey332_15_103_HPP_
#define _grey332_15_103_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey332_15_103 {
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
    // Update multipliers
    C.UpdateMultiplier(A.multiplier());
    C.UpdateMultiplier(B.multiplier());
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
    int B_col_step = B.n() / 2;
    Matrix<Scalar> B11 = B.Subblock(3, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(3, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 2, 2, 2);
    Matrix<Scalar> B31 = B.Subblock(3, 2, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 2, 3, 2);
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


#ifdef _OPEN_MP_
    #pragma omp parallel
    {
    #pragma omp single
        {
#endif
    // M1 = (-1.0 * A13) * (1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A13, Scalar(-1.0), M1A);
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B22, B32, Scalar(1.0), Scalar(1.0), M1B);
    FastMatmul(M1A, M1B, M1, numsteps - 1, x);
    M1A.deallocate();
    M1B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (-1.0 * A13 + -1.0 * A32) * (-1.0 * B22 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A13, A32, Scalar(-1.0), Scalar(-1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B22, B31, Scalar(-1.0), Scalar(1.0), M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A32) * (-1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A11, A12, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M3A);
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(-1.0), M3B);
    FastMatmul(M3A, M3B, M3, numsteps - 1, x);
    M3A.deallocate();
    M3B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A13 + 1.0 * A23 + -1.0 * A31) * (-1.0 * B12 + 1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A13, A23, A31, Scalar(1.0), Scalar(1.0), Scalar(-1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B12, B31, B32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M4B);
    FastMatmul(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A22) * (1.0 * B11 + 1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A11, A12, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B11, B21, B22, Scalar(1.0), Scalar(1.0), Scalar(1.0), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A11 + -1.0 * A12 + 1.0 * A21 + -1.0 * A22 + 1.0 * A31) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A31, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M6A);
    FastMatmul(M6A, B11, M6, numsteps - 1, x);
    M6A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A13 + -1.0 * A23) * (1.0 * B12 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A13, A23, Scalar(-1.0), Scalar(-1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B12, B32, Scalar(1.0), Scalar(-1.0), M7B);
    FastMatmul(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A13 + 1.0 * A21 + 1.0 * A23) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A13, A21, A23, Scalar(1.0), Scalar(1.0), Scalar(1.0), M8A);
    FastMatmul(M8A, B12, M8, numsteps - 1, x);
    M8A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A32) * (1.0 * B21 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B21, B31, Scalar(1.0), Scalar(1.0), M9B);
    FastMatmul(A32, M9B, M9, numsteps - 1, x);
    M9B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A12 + 1.0 * A22) * (-1.0 * B11 + -1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B11, B21, Scalar(-1.0), Scalar(-1.0), M10B);
    FastMatmul(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A13 + 1.0 * A31 + 1.0 * A33) * (1.0 * B31 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A13, A31, A33, Scalar(1.0), Scalar(1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B31, B32, Scalar(1.0), Scalar(1.0), M11B);
    FastMatmul(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A13 + 1.0 * A23 + -1.0 * A32 + 1.0 * A33) * (1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A13, A23, A32, A33, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M12A);
    FastMatmul(M12A, B31, M12, numsteps - 1, x);
    M12A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A11) * (1.0 * B11 + 1.0 * B12 + 1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M13B);
    FastMatmul(A11, M13B, M13, numsteps - 1, x);
    M13B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A31) * (1.0 * B11 + 1.0 * B12 + -1.0 * B31 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A31, Scalar(-1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B11, B12, B31, B32, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M14B);
    FastMatmul(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A13 + -1.0 * A22) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A13, A22, Scalar(-1.0), Scalar(-1.0), M15A);
    FastMatmul(M15A, B22, M15, numsteps - 1, x);
    M15A.deallocate();
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
    Add(M2, M3, M5, M9, M10, M15, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C11);
    Add(M1, M5, M10, M13, M15, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M2, M3, M4, M5, M6, M7, M9, M14, M15, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C21);
    Add(M1, M7, M8, M15, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M4, M7, M9, M12, M14, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C31);
    Add(M1, M2, M4, M7, M11, M12, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C32);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 3, 2);
}

}
  // namespace grey332_15_103
#endif  // _grey332_15_103_HPP_
