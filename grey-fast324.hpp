#ifndef _grey324_20_144_HPP_
#define _grey324_20_144_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey324_20_144 {
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
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
    int B_col_step = B.n() / 4;
    Matrix<Scalar> B11 = B.Subblock(2, 4, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 4, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 4, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(2, 4, 1, 4);
    Matrix<Scalar> B21 = B.Subblock(2, 4, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 4, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 4, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(2, 4, 2, 4);
    int C_row_step = C.m() / 3;
    int C_col_step = C.n() / 4;
    Matrix<Scalar> C11 = C.Subblock(3, 4, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(3, 4, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(3, 4, 1, 3);
    Matrix<Scalar> C14 = C.Subblock(3, 4, 1, 4);
    Matrix<Scalar> C21 = C.Subblock(3, 4, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(3, 4, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(3, 4, 2, 3);
    Matrix<Scalar> C24 = C.Subblock(3, 4, 2, 4);
    Matrix<Scalar> C31 = C.Subblock(3, 4, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(3, 4, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(3, 4, 3, 3);
    Matrix<Scalar> C34 = C.Subblock(3, 4, 3, 4);


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
    Matrix<Scalar> M19(C_row_step, C_col_step);
    Matrix<Scalar> M20(C_row_step, C_col_step);


#ifdef _OPEN_MP_
    #pragma omp parallel
    {
    #pragma omp single
        {
#endif
    // M1 = (-1.0 * A11 + 1.0 * A21) * (-1.0 * B11 + -1.0 * B12 + -1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A11, A21, Scalar(-1.0), Scalar(1.0), M1A);
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M1B);
    FastMatmul(M1A, M1B, M1, numsteps - 1, x);
    M1A.deallocate();
    M1B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (-1.0 * A22 + 1.0 * A32) * (-1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A22, A32, Scalar(-1.0), Scalar(1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(-1.0), M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A31) * (-1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A31, Scalar(-1.0), M3A);
    Matrix<Scalar> M3B(B11.m(), B11.n());
    Add(B11, Scalar(-1.0), M3B);
    FastMatmul(M3A, M3B, M3, numsteps - 1, x);
    M3A.deallocate();
    M3B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A21 + 1.0 * A22 + 1.0 * A31) * (-1.0 * B14 + -1.0 * B21 + -1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A21, A22, A31, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B14, B21, B24, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M4B);
    FastMatmul(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A21 + 1.0 * A22 + 1.0 * A31 + -1.0 * A32) * (1.0 * B21 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A21, A22, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B21, B24, Scalar(1.0), Scalar(1.0), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A11 + 1.0 * A22) * (-1.0 * B14 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A11, A22, Scalar(1.0), Scalar(1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B14, B23, Scalar(-1.0), Scalar(1.0), M6B);
    FastMatmul(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A12 + -1.0 * A22 + 1.0 * A32) * (-1.0 * B12 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A12, A22, A32, Scalar(1.0), Scalar(-1.0), Scalar(1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B12, B22, Scalar(-1.0), Scalar(-1.0), M7B);
    FastMatmul(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (-1.0 * A21 + 1.0 * A31) * (1.0 * B12 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A21, A31, Scalar(-1.0), Scalar(1.0), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B12, B13, Scalar(1.0), Scalar(1.0), M8B);
    FastMatmul(M8A, M8B, M8, numsteps - 1, x);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A11 + 1.0 * A12) * (-1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A11, A12, Scalar(-1.0), Scalar(1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B23, Scalar(-1.0), M9B);
    FastMatmul(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A22) * (1.0 * B14 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B14, B24, Scalar(1.0), Scalar(1.0), M10B);
    FastMatmul(A22, M10B, M10, numsteps - 1, x);
    M10B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A21 + 1.0 * A22) * (-1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A21, A22, Scalar(-1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B14, Scalar(-1.0), M11B);
    FastMatmul(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A11 + 1.0 * A12 + -1.0 * A22 + 1.0 * A32) * (1.0 * B12 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A11, A12, A22, A32, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M12A);
    Matrix<Scalar> M12B(B11.m(), B11.n());
    Add(B12, B23, Scalar(1.0), Scalar(-1.0), M12B);
    FastMatmul(M12A, M12B, M12, numsteps - 1, x);
    M12A.deallocate();
    M12B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A12 + 1.0 * A22) * (1.0 * B23 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), M13A);
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B23, B24, Scalar(1.0), Scalar(1.0), M13B);
    FastMatmul(M13A, M13B, M13, numsteps - 1, x);
    M13A.deallocate();
    M13B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11) * (1.0 * B13 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A11, Scalar(-1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B13, B23, Scalar(1.0), Scalar(1.0), M14B);
    FastMatmul(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmul(A32, B21, M15, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (-1.0 * A11 + -1.0 * A21) * (-1.0 * B13 + -1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A11, A21, Scalar(-1.0), Scalar(-1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B13, B14, Scalar(-1.0), Scalar(-1.0), M16B);
    FastMatmul(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A21 + -1.0 * A22 + -1.0 * A31 + 1.0 * A32) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M17A(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A31, A32, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M17A);
    FastMatmul(M17A, B12, M17, numsteps - 1, x);
    M17A.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A11 + -1.0 * A12 + -1.0 * A21 + 1.0 * A22 + -1.0 * A32) * (1.0 * B12 + 1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A32, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), M18A);
    Matrix<Scalar> M18B(B11.m(), B11.n());
    Add(B12, B21, B22, Scalar(1.0), Scalar(1.0), Scalar(1.0), M18B);
    FastMatmul(M18A, M18B, M18, numsteps - 1, x);
    M18A.deallocate();
    M18B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A21 + 1.0 * A31) * (-1.0 * B11 + -1.0 * B14 + -1.0 * B21 + -1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A21, A31, Scalar(-1.0), Scalar(1.0), M19A);
    Matrix<Scalar> M19B(B11.m(), B11.n());
    Add(B11, B14, B21, B24, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M19B);
    FastMatmul(M19A, M19B, M19, numsteps - 1, x);
    M19A.deallocate();
    M19B.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (-1.0 * A11 + 1.0 * A12 + 1.0 * A21 + -1.0 * A22) * (-1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M20A(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), M20A);
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(-1.0), M20B);
    FastMatmul(M20A, M20B, M20, numsteps - 1, x);
    M20A.deallocate();
    M20B.deallocate();
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
    Add(M1, M3, M4, M7, M10, M15, M18, M19, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C11);
    Add(M2, M7, M9, M12, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C12);
    Add(M9, M14, Scalar(-1.0), Scalar(-1.0), C13);
    Add(M6, M9, M10, M13, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C14);
    Add(M3, M4, M10, M19, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C21);
    Add(M2, M9, M12, M15, M18, M20, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C22);
    Add(M6, M11, M14, M16, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C23);
    Add(M10, M11, Scalar(1.0), Scalar(1.0), C24);
    Add(M3, M15, Scalar(1.0), Scalar(1.0), C31);
    Add(M15, M17, M18, M20, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C32);
    Add(M6, M8, M9, M11, M12, M14, M16, M17, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C33);
    Add(M4, M5, M11, M15, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C34);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 2, 4);
}

}
  // namespace grey324_20_144
#endif  // _grey324_20_144_HPP_
