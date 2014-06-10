#ifndef _FAST_HPP_
#define _FAST_HPP_


// This is an automatically generated file from gen.py.
#include "linalg.hpp"
#ifdef _CILK_
# include <cilk/cilk.h>
#elifdef _OPEN_MP_
# include <openmp.h>
#endif


template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps) {
    // Base case for recursion
    if (numsteps == 0) {
        Gemm(A, B, C);
        return;
    }

    int A_x_step = A.m() / 3;
    int A_y_step = A.n() / 3;
    Matrix<Scalar> A11(A.data() + 0 * A_x_step + 0 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A12(A.data() + 0 * A_x_step + 1 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A13(A.data() + 0 * A_x_step + 2 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A21(A.data() + 1 * A_x_step + 0 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A22(A.data() + 1 * A_x_step + 1 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A23(A.data() + 1 * A_x_step + 2 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A31(A.data() + 2 * A_x_step + 0 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A32(A.data() + 2 * A_x_step + 1 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    Matrix<Scalar> A33(A.data() + 2 * A_x_step + 2 * A_y_step * A.stride(), A.stride(), A_x_step, A_y_step);
    int B_x_step = B.m() / 3;
    int B_y_step = B.n() / 2;
    Matrix<Scalar> B11(B.data() + 0 * B_x_step + 0 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    Matrix<Scalar> B12(B.data() + 0 * B_x_step + 1 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    Matrix<Scalar> B21(B.data() + 1 * B_x_step + 0 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    Matrix<Scalar> B22(B.data() + 1 * B_x_step + 1 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    Matrix<Scalar> B31(B.data() + 2 * B_x_step + 0 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    Matrix<Scalar> B32(B.data() + 2 * B_x_step + 1 * B_y_step * B.stride(), B.stride(), B_x_step, B_y_step);
    int C_x_step = C.m() / 3;
    int C_y_step = C.n() / 2;
    Matrix<Scalar> C11(C.data() + 0 * C_x_step + 0 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);
    Matrix<Scalar> C12(C.data() + 0 * C_x_step + 1 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);
    Matrix<Scalar> C21(C.data() + 1 * C_x_step + 0 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);
    Matrix<Scalar> C22(C.data() + 1 * C_x_step + 1 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);
    Matrix<Scalar> C31(C.data() + 2 * C_x_step + 0 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);
    Matrix<Scalar> C32(C.data() + 2 * C_x_step + 1 * C_y_step * C.stride(), C.stride(), C_x_step, C_y_step);


    // These are the intermediate matrices.
    // We define them here so that they can be used
    // inside the lambda functions for Cilk.
    Matrix<Scalar> M1(C_x_step, C_y_step);
    Matrix<Scalar> M2(C_x_step, C_y_step);
    Matrix<Scalar> M3(C_x_step, C_y_step);
    Matrix<Scalar> M4(C_x_step, C_y_step);
    Matrix<Scalar> M5(C_x_step, C_y_step);
    Matrix<Scalar> M6(C_x_step, C_y_step);
    Matrix<Scalar> M7(C_x_step, C_y_step);
    Matrix<Scalar> M8(C_x_step, C_y_step);
    Matrix<Scalar> M9(C_x_step, C_y_step);
    Matrix<Scalar> M10(C_x_step, C_y_step);
    Matrix<Scalar> M11(C_x_step, C_y_step);
    Matrix<Scalar> M12(C_x_step, C_y_step);
    Matrix<Scalar> M13(C_x_step, C_y_step);
    Matrix<Scalar> M14(C_x_step, C_y_step);
    Matrix<Scalar> M15(C_x_step, C_y_step);


    // M1 = (1.0 * A11 + -1.0 * A12 + 1.0 * A31) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M1A(A11.m(), A11.n());
    Add(A11, A12, A31, Scalar(1), Scalar(-1), Scalar(1), M1A);
    FastMatmul(M1A, B12, M1, numsteps - 1);
    M1A.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M2 = (1.0 * A11 + 1.0 * A13 + -1.0 * A21) * (1.0 * B11 + -1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M2A(A11.m(), A11.n());
    Add(A11, A13, A21, Scalar(1), Scalar(1), Scalar(-1), M2A);
    Matrix<Scalar> M2B(B11.m(), B11.n());
    Add(B11, B12, Scalar(1), Scalar(-1), M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M3 = (-1.0 * A21 + 1.0 * A22 + 1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M3A(A11.m(), A11.n());
    Add(A21, A22, A32, Scalar(-1), Scalar(1), Scalar(1), M3A);
    FastMatmul(M3A, B21, M3, numsteps - 1);
    M3A.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M4 = (1.0 * A21) * (1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M4B(B11.m(), B11.n());
    Add(B11, B21, Scalar(1), Scalar(1), M4B);
    FastMatmul(A21, M4B, M4, numsteps - 1);
    M4B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M5 = (1.0 * A12 + -1.0 * A21) * (1.0 * B12 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M5A(A11.m(), A11.n());
    Add(A12, A21, Scalar(1), Scalar(-1), M5A);
    Matrix<Scalar> M5B(B11.m(), B11.n());
    Add(B12, B21, Scalar(1), Scalar(1), M5B);
    FastMatmul(M5A, M5B, M5, numsteps - 1);
    M5A.deallocate();
    M5B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M6 = (-1.0 * A31) * (-1.0 * B11 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M6A(A11.m(), A11.n());
    Add(A31, Scalar(-1), M6A);
    Matrix<Scalar> M6B(B11.m(), B11.n());
    Add(B11, B31, Scalar(-1), Scalar(1), M6B);
    FastMatmul(M6A, M6B, M6, numsteps - 1);
    M6A.deallocate();
    M6B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M7 = (1.0 * A23 + 1.0 * A31 + 1.0 * A33) * (1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M7A(A11.m(), A11.n());
    Add(A23, A31, A33, Scalar(1), Scalar(1), Scalar(1), M7A);
    FastMatmul(M7A, B31, M7, numsteps - 1);
    M7A.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M8 = (1.0 * A13 + -1.0 * A31) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M8A(A11.m(), A11.n());
    Add(A13, A31, Scalar(1), Scalar(-1), M8A);
    Matrix<Scalar> M8B(B11.m(), B11.n());
    Add(B11, B12, B31, Scalar(-1), Scalar(1), Scalar(1), M8B);
    FastMatmul(M8A, M8B, M8, numsteps - 1);
    M8A.deallocate();
    M8B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M9 = (1.0 * A12 + -1.0 * A22 + -1.0 * A23) * (1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M9A(A11.m(), A11.n());
    Add(A12, A22, A23, Scalar(1), Scalar(-1), Scalar(-1), M9A);
    Matrix<Scalar> M9B(B11.m(), B11.n());
    Add(B21, B22, Scalar(1), Scalar(-1), M9B);
    FastMatmul(M9A, M9B, M9, numsteps - 1);
    M9A.deallocate();
    M9B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M10 = (1.0 * A12) * (1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M10B(B11.m(), B11.n());
    Add(B12, B22, Scalar(1), Scalar(1), M10B);
    FastMatmul(A12, M10B, M10, numsteps - 1);
    M10B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M11 = (-1.0 * A32) * (-1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M11A(A11.m(), A11.n());
    Add(A32, Scalar(-1), M11A);
    Matrix<Scalar> M11B(B11.m(), B11.n());
    Add(B22, B32, Scalar(-1), Scalar(1), M11B);
    FastMatmul(M11A, M11B, M11, numsteps - 1);
    M11A.deallocate();
    M11B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M12 = (1.0 * A13 + 1.0 * A32 + 1.0 * A33) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M12A(A11.m(), A11.n());
    Add(A13, A32, A33, Scalar(1), Scalar(1), Scalar(1), M12A);
    FastMatmul(M12A, B32, M12, numsteps - 1);
    M12A.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M13 = (-1.0 * A23) * (-1.0 * B21 + 1.0 * B22 + 1.0 * B31 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M13A(A11.m(), A11.n());
    Add(A23, Scalar(-1), M13A);
    Matrix<Scalar> M13B(B11.m(), B11.n());
    Add(B21, B22, B31, B32, Scalar(-1), Scalar(1), Scalar(1), Scalar(-1), M13B);
    FastMatmul(M13A, M13B, M13, numsteps - 1);
    M13A.deallocate();
    M13B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M14 = (-1.0 * A23 + 1.0 * A32) * (1.0 * B21 + -1.0 * B22 + 1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M14A(A11.m(), A11.n());
    Add(A23, A32, Scalar(-1), Scalar(1), M14A);
    Matrix<Scalar> M14B(B11.m(), B11.n());
    Add(B21, B22, B32, Scalar(1), Scalar(-1), Scalar(1), M14B);
    FastMatmul(M14A, M14B, M14, numsteps - 1);
    M14A.deallocate();
    M14B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

    // M15 = (1.0 * A13) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B31 + -1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elifdef _OPEN_MP_
# pragma omp task
    [&] {
#endif
    Matrix<Scalar> M15B(B11.m(), B11.n());
    Add(B11, B12, B31, B32, Scalar(-1), Scalar(1), Scalar(1), Scalar(-1), M15B);
    FastMatmul(A13, M15B, M15, numsteps - 1);
    M15B.deallocate();
#ifdef _CILK_
    }();
#elifdef _OPEN_MP_
    }();
#endif

#ifdef _CILK_
    cilk_sync;
#elifdef _OPEN_MP_
    # pragma omp taskwait
#endif
    Add(M1, M2, M4, M5, M6, M8, Scalar(1), Scalar(1), Scalar(1), Scalar(1), Scalar(-1), Scalar(1), C11);
    Add(M1, M6, M8, M10, M15, Scalar(1), Scalar(-1), Scalar(1), Scalar(1), Scalar(-1), C12);
    Add(M3, M4, M11, M13, M14, Scalar(1), Scalar(1), Scalar(-1), Scalar(-1), Scalar(-1), C21);
    Add(M3, M5, M9, M10, M11, M14, Scalar(1), Scalar(-1), Scalar(1), Scalar(1), Scalar(-1), Scalar(-1), C22);
    Add(M6, M7, M11, M13, M14, Scalar(1), Scalar(1), Scalar(1), Scalar(1), Scalar(1), C31);
    Add(M6, M8, M11, M12, M15, Scalar(1), Scalar(-1), Scalar(1), Scalar(1), Scalar(1), C32);
}

#endif  // _FAST_HPP_
