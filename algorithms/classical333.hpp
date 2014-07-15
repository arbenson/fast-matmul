#ifndef _classical333_27_81_HPP_
#define _classical333_27_81_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace classical333_27_81 {

template <typename Scalar>
void FastMatmulRecursive(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps, double x=1e-8) {
    // Update multipliers
    C.UpdateMultiplier(A.multiplier());
    C.UpdateMultiplier(B.multiplier());
    A.set_multiplier(Scalar(1.0));
    B.set_multiplier(Scalar(1.0));
    // Base case for recursion
    if (numsteps == 0) {
        Gemm(A, B, C);
        return;
    }

    Matrix<Scalar> A11 = A.Subblock(3, 3, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(3, 3, 1, 2);
    Matrix<Scalar> A13 = A.Subblock(3, 3, 1, 3);
    Matrix<Scalar> A21 = A.Subblock(3, 3, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(3, 3, 2, 2);
    Matrix<Scalar> A23 = A.Subblock(3, 3, 2, 3);
    Matrix<Scalar> A31 = A.Subblock(3, 3, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(3, 3, 3, 2);
    Matrix<Scalar> A33 = A.Subblock(3, 3, 3, 3);
    Matrix<Scalar> B11 = B.Subblock(3, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(3, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(3, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(3, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(3, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(3, 3, 2, 3);
    Matrix<Scalar> B31 = B.Subblock(3, 3, 3, 1);
    Matrix<Scalar> B32 = B.Subblock(3, 3, 3, 2);
    Matrix<Scalar> B33 = B.Subblock(3, 3, 3, 3);
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
    Matrix<Scalar> M1(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M2(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M3(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M4(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M5(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M6(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M7(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M8(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M9(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M10(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M11(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M12(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M13(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M14(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M15(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M16(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M17(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M18(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M19(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M20(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M21(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M22(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M23(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M24(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M25(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M26(C11.m(), C11.n(), C.multiplier());
    Matrix<Scalar> M27(C11.m(), C11.n(), C.multiplier());


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

    // M3 = (1.0 * A13) * (1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A13, B31, M3, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (1.0 * A11) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A11, B12, M4, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A12) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A12, B22, M5, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A13) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A13, B32, M6, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (1.0 * A11) * (1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A11, B13, M7, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A12) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A12, B23, M8, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A13) * (1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A13, B33, M9, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A21) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A21, B11, M10, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (1.0 * A22) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B21, M11, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A23) * (1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A23, B31, M12, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A21) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A21, B12, M13, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (1.0 * A22) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B22, M14, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A23) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A23, B32, M15, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A21) * (1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A21, B13, M16, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A22) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A22, B23, M17, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A23) * (1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A23, B33, M18, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (1.0 * A31) * (1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A31, B11, M19, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A32) * (1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A32, B21, M20, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (1.0 * A33) * (1.0 * B31)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A33, B31, M21, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (1.0 * A31) * (1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A31, B12, M22, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A32) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A32, B22, M23, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (1.0 * A33) * (1.0 * B32)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A33, B32, M24, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (1.0 * A31) * (1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A31, B13, M25, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (1.0 * A32) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A32, B23, M26, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M27 = (1.0 * A33) * (1.0 * B33)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A33, B33, M27, numsteps - 1, x);
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
    Add(M1, M2, M3, Scalar(1.0), Scalar(1.0), Scalar(1.0), C11);
    Add(M4, M5, M6, Scalar(1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M7, M8, M9, Scalar(1.0), Scalar(1.0), Scalar(1.0), C13);
    Add(M10, M11, M12, Scalar(1.0), Scalar(1.0), Scalar(1.0), C21);
    Add(M13, M14, M15, Scalar(1.0), Scalar(1.0), Scalar(1.0), C22);
    Add(M16, M17, M18, Scalar(1.0), Scalar(1.0), Scalar(1.0), C23);
    Add(M19, M20, M21, Scalar(1.0), Scalar(1.0), Scalar(1.0), C31);
    Add(M22, M23, M24, Scalar(1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M25, M26, M27, Scalar(1.0), Scalar(1.0), Scalar(1.0), C33);


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

}  // namespace classical333_27_81

#endif  // _classical333_27_81_HPP_
