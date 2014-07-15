#ifndef _grey423_20_144_HPP_
#define _grey423_20_144_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey423_20_144 {

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

    Matrix<Scalar> A11 = A.Subblock(4, 2, 1, 1);
    Matrix<Scalar> A12 = A.Subblock(4, 2, 1, 2);
    Matrix<Scalar> A21 = A.Subblock(4, 2, 2, 1);
    Matrix<Scalar> A22 = A.Subblock(4, 2, 2, 2);
    Matrix<Scalar> A31 = A.Subblock(4, 2, 3, 1);
    Matrix<Scalar> A32 = A.Subblock(4, 2, 3, 2);
    Matrix<Scalar> A41 = A.Subblock(4, 2, 4, 1);
    Matrix<Scalar> A42 = A.Subblock(4, 2, 4, 2);
    Matrix<Scalar> B11 = B.Subblock(2, 3, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 3, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 3, 1, 3);
    Matrix<Scalar> B21 = B.Subblock(2, 3, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 3, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 3, 2, 3);
    Matrix<Scalar> C11 = C.Subblock(4, 3, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 3, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(4, 3, 1, 3);
    Matrix<Scalar> C21 = C.Subblock(4, 3, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 3, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(4, 3, 2, 3);
    Matrix<Scalar> C31 = C.Subblock(4, 3, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 3, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(4, 3, 3, 3);
    Matrix<Scalar> C41 = C.Subblock(4, 3, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 3, 4, 2);
    Matrix<Scalar> C43 = C.Subblock(4, 3, 4, 3);


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


    // M1 = (-1.0 * A11 + -1.0 * A12 + -1.0 * A21 + -1.0 * A22) * (-1.0 * B11 + 1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    Add(A11, A12, A21, A22, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S1);
    Matrix<Scalar> T1(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(1.0), T1);
    FastMatmulRecursive(S1, T1, M1, numsteps - 1, x);
    S1.deallocate();
    T1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (-1.0 * A22 + -1.0 * A32) * (-1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A22, A32, Scalar(-1.0), Scalar(-1.0), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B22, B23, Scalar(-1.0), Scalar(1.0), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A11) * (-1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M3.UpdateMultiplier(Scalar(-1));
    M3.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A11, B13, M3, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A12 + -1.0 * A41 + -1.0 * A42) * (-1.0 * B12 + 1.0 * B13 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A12, A41, A42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B12, B13, B22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (1.0 * A12 + 1.0 * A42) * (-1.0 * B12 + 1.0 * B13 + 1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S5(A11.m(), A11.n());
    Add(A12, A42, Scalar(1.0), Scalar(1.0), S5);
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B12, B13, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), T5);
    FastMatmulRecursive(S5, T5, M5, numsteps - 1, x);
    S5.deallocate();
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (1.0 * A32 + -1.0 * A41) * (1.0 * B11 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A32, A41, Scalar(1.0), Scalar(-1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B11, B22, Scalar(1.0), Scalar(1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A21 + -1.0 * A22) * (1.0 * B21 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A21, A22, Scalar(-1.0), Scalar(-1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B21, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A21 + 1.0 * A31) * (-1.0 * B12 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A21, A31, Scalar(1.0), Scalar(1.0), S8);
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B12, B13, Scalar(-1.0), Scalar(1.0), T8);
    FastMatmulRecursive(S8, T8, M8, numsteps - 1, x);
    S8.deallocate();
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (-1.0 * A32) * (-1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T9(B11.m(), B11.n());
    Add(B11, B21, Scalar(-1.0), Scalar(1.0), T9);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A32, T9, M9, numsteps - 1, x);
    T9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (1.0 * A41 + 1.0 * A42) * (1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A41, A42, Scalar(1.0), Scalar(1.0), S10);
    FastMatmulRecursive(S10, B22, M10, numsteps - 1, x);
    S10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A41) * (-1.0 * B12 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B12, B22, Scalar(-1.0), Scalar(1.0), T11);
    M11.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A41, T11, M11, numsteps - 1, x);
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (1.0 * A21 + -1.0 * A32) * (-1.0 * B11 + 1.0 * B21 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S12(A11.m(), A11.n());
    Add(A21, A32, Scalar(1.0), Scalar(-1.0), S12);
    Matrix<Scalar> T12(B11.m(), B11.n());
    Add(B11, B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T12);
    FastMatmulRecursive(S12, T12, M12, numsteps - 1, x);
    S12.deallocate();
    T12.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (1.0 * A32 + 1.0 * A42) * (1.0 * B21 + 1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A32, A42, Scalar(1.0), Scalar(1.0), S13);
    Matrix<Scalar> T13(B11.m(), B11.n());
    Add(B21, B22, Scalar(1.0), Scalar(1.0), T13);
    FastMatmulRecursive(S13, T13, M13, numsteps - 1, x);
    S13.deallocate();
    T13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (1.0 * A31 + 1.0 * A32) * (-1.0 * B11)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S14(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(1.0), S14);
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S14, B11, M14, numsteps - 1, x);
    S14.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (1.0 * A12) * (1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    FastMatmulRecursive(A12, B23, M15, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (-1.0 * A31 + -1.0 * A41) * (-1.0 * B11 + -1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A31, A41, Scalar(-1.0), Scalar(-1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B11, B12, Scalar(-1.0), Scalar(-1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A21) * (-1.0 * B11 + 1.0 * B12 + -1.0 * B13 + 1.0 * B21 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T17);
    FastMatmulRecursive(A21, T17, M17, numsteps - 1, x);
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A12 + 1.0 * A21 + 1.0 * A22) * (1.0 * B11 + -1.0 * B12 + -1.0 * B21 + 1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A12, A21, A22, Scalar(1.0), Scalar(1.0), Scalar(1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B11, B12, B21, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (-1.0 * A11 + -1.0 * A12 + -1.0 * A41 + -1.0 * A42) * (-1.0 * B12 + 1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A11, A12, A41, A42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S19);
    Matrix<Scalar> T19(B11.m(), B11.n());
    Add(B12, B13, Scalar(-1.0), Scalar(1.0), T19);
    FastMatmulRecursive(S19, T19, M19, numsteps - 1, x);
    S19.deallocate();
    T19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (-1.0 * A12 + -1.0 * A22) * (-1.0 * B11 + 1.0 * B12 + 1.0 * B21 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A12, A22, Scalar(-1.0), Scalar(-1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B11, B12, B21, B22, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), T20);
    FastMatmulRecursive(S20, T20, M20, numsteps - 1, x);
    S20.deallocate();
    T20.deallocate();
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
    Add(M1, M3, M4, M7, M10, M15, M18, M19, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C11);
    Add(M3, M4, M10, M19, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C12);
    Add(M3, M15, Scalar(1.0), Scalar(1.0), C13);
    Add(M2, M7, M9, M12, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C21);
    Add(M2, M9, M12, M15, M18, M20, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C22);
    Add(M15, M17, M18, M20, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C23);
    Add(M9, M14, Scalar(-1.0), Scalar(-1.0), C31);
    Add(M6, M11, M14, M16, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M6, M8, M9, M11, M12, M14, M16, M17, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C33);
    Add(M6, M9, M10, M13, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), C41);
    Add(M10, M11, Scalar(1.0), Scalar(1.0), C42);
    Add(M4, M5, M11, M15, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C43);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 4, 2, 3);
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

}  // namespace grey423_20_144

#endif  // _grey423_20_144_HPP_
