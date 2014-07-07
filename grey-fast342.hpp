#ifndef _grey342_20_144_HPP_
#define _grey342_20_144_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey342_20_144 {
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


#ifdef _OPEN_MP_
    #pragma omp parallel
    {
    #pragma omp single
        {
#endif
    // M1 = (1.0 * A11) * (-1.0 * B11 + -1.0 * B12 + -1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M1B(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M1B);
    FastMatmul(A11, M1B, M1, numsteps - 1, x);
    M1B.deallocate();
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
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A12, A22, Scalar(1.0), Scalar(1.0), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B22, B32, Scalar(-1.0), Scalar(-1.0), M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1, x);
    M2A.deallocate();
    M2B.deallocate();
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
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A11, A21, A31, Scalar(1.0), Scalar(1.0), Scalar(1.0), M3A);
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

    // M4 = (-1.0 * A11 + -1.0 * A21 + -1.0 * A34) * (-1.0 * B12 + -1.0 * B41 + -1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M4A(A11.m(), A11.n());
    Add(A11, A21, A34, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M4A);
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B12, B41, B42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M4B);
    FastMatmul(M4A, M4B, M4, numsteps - 1, x);
    M4A.deallocate();
    M4B.deallocate();
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
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A34, Scalar(-1.0), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B12, B42, Scalar(1.0), Scalar(1.0), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1, x);
    M5A.deallocate();
    M5B.deallocate();
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
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A14, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B32, B41, Scalar(1.0), Scalar(-1.0), M6B);
    FastMatmul(M6A, M6B, M6, numsteps - 1, x);
    M6A.deallocate();
    M6B.deallocate();
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
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A11, A12, Scalar(1.0), Scalar(-1.0), M7A);
    Matrix<Scalar> M7B(B11.m(), B11.n());
    Add(B21, B22, Scalar(-1.0), Scalar(-1.0), M7B);
    FastMatmul(M7A, M7B, M7, numsteps - 1, x);
    M7A.deallocate();
    M7B.deallocate();
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
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B21, B31, Scalar(1.0), Scalar(1.0), M8B);
    FastMatmul(A33, M8B, M8, numsteps - 1, x);
    M8B.deallocate();
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
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A12, A13, A14, A22, A33, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B32, Scalar(-1.0), M9B);
    FastMatmul(M9A, M9B, M9, numsteps - 1, x);
    M9A.deallocate();
    M9B.deallocate();
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
    Matrix<Scalar> M10A(A11.m(), A11.n());
    Add(A11, A14, A21, A24, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), M10A);
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B41, B42, Scalar(1.0), Scalar(1.0), M10B);
    FastMatmul(M10A, M10B, M10, numsteps - 1, x);
    M10A.deallocate();
    M10B.deallocate();
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
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A23, A24, A33, A34, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B41, Scalar(-1.0), M11B);
    FastMatmul(M11A, M11B, M11, numsteps - 1, x);
    M11A.deallocate();
    M11B.deallocate();
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
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A12, A22, A33, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M12A);
    Matrix<Scalar> M12B(B11.m(), B11.n());
    Add(B21, B32, Scalar(1.0), Scalar(-1.0), M12B);
    FastMatmul(M12A, M12B, M12, numsteps - 1, x);
    M12A.deallocate();
    M12B.deallocate();
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
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B32, B42, Scalar(1.0), Scalar(1.0), M13B);
    FastMatmul(A14, M13B, M13, numsteps - 1, x);
    M13B.deallocate();
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
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A13, A23, A33, Scalar(-1.0), Scalar(1.0), Scalar(1.0), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B31, B32, Scalar(1.0), Scalar(1.0), M14B);
    FastMatmul(M14A, M14B, M14, numsteps - 1, x);
    M14A.deallocate();
    M14B.deallocate();
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
    Matrix<Scalar> M15A(A11.m(), A11.n());
    Add(A11, A22, A31, A32, A34, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), M15A);
    FastMatmul(M15A, B12, M15, numsteps - 1, x);
    M15A.deallocate();
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
    Matrix<Scalar> M16A(A11.m(), A11.n());
    Add(A23, A33, Scalar(1.0), Scalar(1.0), M16A);
    Matrix<Scalar> M16B(B11.m(), B11.n());
    Add(B31, B41, Scalar(-1.0), Scalar(-1.0), M16B);
    FastMatmul(M16A, M16B, M16, numsteps - 1, x);
    M16A.deallocate();
    M16B.deallocate();
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
    Matrix<Scalar> M17A(A11.m(), A11.n());
    Add(A32, A33, Scalar(-1.0), Scalar(1.0), M17A);
    FastMatmul(M17A, B21, M17, numsteps - 1, x);
    M17A.deallocate();
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
    Matrix<Scalar> M18A(A11.m(), A11.n());
    Add(A11, A22, A32, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M18A);
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

    // M19 = (1.0 * A11 + 1.0 * A21) * (-1.0 * B11 + -1.0 * B12 + -1.0 * B41 + -1.0 * B42)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> M19A(A11.m(), A11.n());
    Add(A11, A21, Scalar(1.0), Scalar(1.0), M19A);
    Matrix<Scalar> M19B(B11.m(), B11.n());
    Add(B11, B12, B41, B42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), M19B);
    FastMatmul(M19A, M19B, M19, numsteps - 1, x);
    M19A.deallocate();
    M19B.deallocate();
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
    Matrix<Scalar> M20A(A11.m(), A11.n());
    Add(A22, A32, Scalar(1.0), Scalar(1.0), M20A);
    Matrix<Scalar> M20B(B11.m(), B11.n());
    Add(B12, B22, Scalar(-1.0), Scalar(-1.0), M20B);
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
    Add(M1, M6, M9, M12, M14, M16, M17, M18, M20, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C11);
    Add(M7, M9, M12, M13, M17, M18, M20, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C12);
    Add(M1, M4, M5, M8, M11, M16, M17, M18, M19, M20, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C21);
    Add(M2, M4, M5, M6, M7, M10, M11, M12, M13, M17, M18, M20, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M3, M4, M5, M8, M17, M19, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C31);
    Add(M2, M5, M7, M12, M15, M17, M18, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), C32);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 3, 4, 2);
}

}
  // namespace grey342_20_144
#endif  // _grey342_20_144_HPP_
