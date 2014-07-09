#ifndef _classical222_8_24_HPP_
#define _classical222_8_24_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace classical222_8_24 {

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
    int A_col_step = A.n() / 2;
    Matrix<Scalar> A11 = A.Subblock(2, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(2, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(2, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(2, 2, 2, 2);
    int B_row_step = B.m() / 2;
    int B_col_step = B.n() / 2;
    Matrix<Scalar> B11 = B.Subblock(2, 2, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 2, 1, 2);
    Matrix<Scalar> B21 = B.Subblock(2, 2, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 2, 2, 2);
    int C_row_step = C.m() / 2;
    int C_col_step = C.n() / 2;
    Matrix<Scalar> C11 = C.Subblock(2, 2, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(2, 2, 1, 2);
    Matrix<Scalar> C21 = C.Subblock(2, 2, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(2, 2, 2, 2);


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


    // M1 = (1.0 * A11) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A11, B11, M1, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (1.0 * A12) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A12, B21, M2, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (1.0 * A11) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A11, B12, M3, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A12) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A12, B22, M4, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A21) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A21, B11, M5, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A22) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B21, M6, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A21) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A21, B12, M7, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A22) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B22, M8, numsteps - 1, x);
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
    Add(M3, M4, Scalar(1.0), Scalar(1.0), C12);
    Add(M5, M6, Scalar(1.0), Scalar(1.0), C21);
    Add(M7, M8, Scalar(1.0), Scalar(1.0), C22);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 2, 2, 2);
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

}
  // namespace classical222_8_24
#endif  // _classical222_8_24_HPP_
