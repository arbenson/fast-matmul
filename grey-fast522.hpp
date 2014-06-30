#ifndef _grey522_18_99_HPP_
#define _grey522_18_99_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey522_18_99 {
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
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
    Matrix<Scalar> M1(C_row_step, C_col_step);
    Matrix<Scalar> M2(C_row_step, C_col_step);
    Matrix<Scalar> M3(C_row_step, C_col_step);
    Matrix<Scalar> M4(C_row_step, C_col_step);
    Matrix<Scalar> M5(C_row_step, C_col_step);
    Matrix<Scalar> M6(C_row_step, C_col_step);
    Matrix<Scalar> M7(C_row_step, C_col_step);
    Matrix<Scalar> M8(C_row_step, C_col_step);
    Matrix<Scalar> M9(C_row_step, C_col_step);
    Matrix<Scalar> M10(C_row_step, C_col_step);
    Matrix<Scalar> M11(C_row_step, C_col_step);
    Matrix<Scalar> M12(C_row_step, C_col_step);
    Matrix<Scalar> M13(C_row_step, C_col_step);
    Matrix<Scalar> M14(C_row_step, C_col_step);
    Matrix<Scalar> M15(C_row_step, C_col_step);
    Matrix<Scalar> M16(C_row_step, C_col_step);
    Matrix<Scalar> M17(C_row_step, C_col_step);
    Matrix<Scalar> M18(C_row_step, C_col_step);


#ifdef _OPEN_MP_
    #pragma omp parallel
    {
    #pragma omp single
        {
#endif
    // M1 = (-1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A32, Scalar(-1.0), M1A);
    FastMatmul(M1A, B21, M1, numsteps - 1, x);
    M1A.deallocate();
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
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A41, A52, Scalar(1.0), Scalar(1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B11, B22, Scalar(1.0), Scalar(1.0), M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
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
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A31, Scalar(-1.0), M3A);
    FastMatmul(M3A, B11, M3, numsteps - 1, x);
    M3A.deallocate();
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
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(1.0), M4B);
    FastMatmul(A52, M4B, M4, numsteps - 1, x);
    M4B.deallocate();
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
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(1.0), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
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
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), M6B);
    FastMatmul(A41, M6B, M6, numsteps - 1, x);
    M6B.deallocate();
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
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A41, A51, Scalar(-1.0), Scalar(-1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B11, B12, Scalar(1.0), Scalar(-1.0), M7B);
    FastMatmul(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
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
    FastMatmul(A31, B12, M8, numsteps - 1, x);
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
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(-1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M9B);
    FastMatmul(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
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
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A42, A52, Scalar(1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(1.0), M10B);
    FastMatmul(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
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
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A12, A32, Scalar(1.0), Scalar(1.0), M11A);
    FastMatmul(M11A, B21, M11, numsteps - 1, x);
    M11A.deallocate();
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
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A21, A22, A31, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M12A);
    FastMatmul(M12A, B22, M12, numsteps - 1, x);
    M12A.deallocate();
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
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A41, A42, Scalar(-1.0), Scalar(1.0), M13A);
    FastMatmul(M13A, B22, M13, numsteps - 1, x);
    M13A.deallocate();
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
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A12, A21, A22, A31, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B11, B12, B22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M14B);
    FastMatmul(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
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
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A11, A31, Scalar(1.0), Scalar(1.0), M15A);
    FastMatmul(M15A, B11, M15, numsteps - 1, x);
    M15A.deallocate();
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
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A21, A31, Scalar(1.0), Scalar(1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(1.0), M16B);
    FastMatmul(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
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
    Matrix<Scalar> M17A(A11.m(), A11.n());
    Add(A32, Scalar(-1.0), M17A);
    FastMatmul(M17A, B22, M17, numsteps - 1, x);
    M17A.deallocate();
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
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A51, A52, Scalar(1.0), Scalar(-1.0), M18A);
    FastMatmul(M18A, B11, M18, numsteps - 1, x);
    M18A.deallocate();
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

}
  // namespace grey522_18_99
#endif  // _grey522_18_99_HPP_
