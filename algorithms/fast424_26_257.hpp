#ifndef _grey424_26_257_HPP_
#define _grey424_26_257_HPP_


// This is an automatically generated file from gen.py.
#include "common.hpp"


namespace grey424_26_257 {

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
    Matrix<Scalar> B11 = B.Subblock(2, 4, 1, 1);
    Matrix<Scalar> B12 = B.Subblock(2, 4, 1, 2);
    Matrix<Scalar> B13 = B.Subblock(2, 4, 1, 3);
    Matrix<Scalar> B14 = B.Subblock(2, 4, 1, 4);
    Matrix<Scalar> B21 = B.Subblock(2, 4, 2, 1);
    Matrix<Scalar> B22 = B.Subblock(2, 4, 2, 2);
    Matrix<Scalar> B23 = B.Subblock(2, 4, 2, 3);
    Matrix<Scalar> B24 = B.Subblock(2, 4, 2, 4);
    Matrix<Scalar> C11 = C.Subblock(4, 4, 1, 1);
    Matrix<Scalar> C12 = C.Subblock(4, 4, 1, 2);
    Matrix<Scalar> C13 = C.Subblock(4, 4, 1, 3);
    Matrix<Scalar> C14 = C.Subblock(4, 4, 1, 4);
    Matrix<Scalar> C21 = C.Subblock(4, 4, 2, 1);
    Matrix<Scalar> C22 = C.Subblock(4, 4, 2, 2);
    Matrix<Scalar> C23 = C.Subblock(4, 4, 2, 3);
    Matrix<Scalar> C24 = C.Subblock(4, 4, 2, 4);
    Matrix<Scalar> C31 = C.Subblock(4, 4, 3, 1);
    Matrix<Scalar> C32 = C.Subblock(4, 4, 3, 2);
    Matrix<Scalar> C33 = C.Subblock(4, 4, 3, 3);
    Matrix<Scalar> C34 = C.Subblock(4, 4, 3, 4);
    Matrix<Scalar> C41 = C.Subblock(4, 4, 4, 1);
    Matrix<Scalar> C42 = C.Subblock(4, 4, 4, 2);
    Matrix<Scalar> C43 = C.Subblock(4, 4, 4, 3);
    Matrix<Scalar> C44 = C.Subblock(4, 4, 4, 4);


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


    // M1 = (1.0 * A11 + -1.0 * A12 + 1.0 * A21 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + 1.0 * A41 + -1.0 * A42) * (1.0 * B11 + 1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S1(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A31, A32, A41, A42, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S1);
    Matrix<Scalar> T1(B11.m(), B11.n());
    Add(B11, B14, Scalar(1.0), Scalar(1.0), T1);
    FastMatmulRecursive(S1, T1, M1, numsteps - 1, x);
    S1.deallocate();
    T1.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M2 = (0.5 * A21 + -1.0 * A22 + 0.5 * A31 + 0.5 * A41) * (-1.0 * B11 + 1.0 * B13 + -1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S2(A11.m(), A11.n());
    Add(A21, A22, A31, A41, Scalar(0.5), Scalar(-1.0), Scalar(0.5), Scalar(0.5), S2);
    Matrix<Scalar> T2(B11.m(), B11.n());
    Add(B11, B13, B21, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), T2);
    FastMatmulRecursive(S2, T2, M2, numsteps - 1, x);
    S2.deallocate();
    T2.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M3 = (-1.0 * A11 + -1.0 * A12 + -1.0 * A21 + -1.0 * A22 + 1.0 * A31 + 1.0 * A32 + -1.0 * A41 + -1.0 * A42) * (1.0 * B12 + -1.0 * B13 + -1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S3(A11.m(), A11.n());
    Add(A11, A12, A21, A22, A31, A32, A41, A42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S3);
    Matrix<Scalar> T3(B11.m(), B11.n());
    Add(B12, B13, B14, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), T3);
    FastMatmulRecursive(S3, T3, M3, numsteps - 1, x);
    S3.deallocate();
    T3.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M4 = (-1.0 * A12 + 1.0 * A21 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + 1.0 * A41 + -1.0 * A42) * (1.0 * B11 + 1.0 * B14 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S4(A11.m(), A11.n());
    Add(A12, A21, A22, A31, A32, A41, A42, Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S4);
    Matrix<Scalar> T4(B11.m(), B11.n());
    Add(B11, B14, B21, Scalar(1.0), Scalar(1.0), Scalar(1.0), T4);
    FastMatmulRecursive(S4, T4, M4, numsteps - 1, x);
    S4.deallocate();
    T4.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M5 = (-1.0 * A42) * (1.0 * B12 + -1.0 * B22)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T5(B11.m(), B11.n());
    Add(B12, B22, Scalar(1.0), Scalar(-1.0), T5);
    M5.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A42, T5, M5, numsteps - 1, x);
    T5.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M6 = (-1.0 * A11 + -1.0 * A12 + 1.0 * A41 + 1.0 * A42) * (1.0 * B22 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S6(A11.m(), A11.n());
    Add(A11, A12, A41, A42, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S6);
    Matrix<Scalar> T6(B11.m(), B11.n());
    Add(B22, B24, Scalar(1.0), Scalar(1.0), T6);
    FastMatmulRecursive(S6, T6, M6, numsteps - 1, x);
    S6.deallocate();
    T6.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M7 = (-1.0 * A12 + -1.0 * A22 + -1.0 * A32 + -1.0 * A42) * (1.0 * B11 + 1.0 * B14 + 1.0 * B21 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S7(A11.m(), A11.n());
    Add(A12, A22, A32, A42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), S7);
    Matrix<Scalar> T7(B11.m(), B11.n());
    Add(B11, B14, B21, B24, Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), T7);
    FastMatmulRecursive(S7, T7, M7, numsteps - 1, x);
    S7.deallocate();
    T7.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M8 = (1.0 * A21 + 1.0 * A31 + 1.0 * A41) * (1.0 * B11 + 1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S8(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(1.0), Scalar(1.0), S8);
    Matrix<Scalar> T8(B11.m(), B11.n());
    Add(B11, B21, Scalar(1.0), Scalar(1.0), T8);
    FastMatmulRecursive(S8, T8, M8, numsteps - 1, x);
    S8.deallocate();
    T8.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M9 = (1.0 * A21 + -1.0 * A22 + 1.0 * A31 + -1.0 * A32 + 1.0 * A41 + -1.0 * A42) * (-1.0 * B21)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S9(A11.m(), A11.n());
    Add(A21, A22, A31, A32, A41, A42, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S9);
    M9.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S9, B21, M9, numsteps - 1, x);
    S9.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M10 = (-1.0 * A12 + -1.0 * A22 + 1.0 * A32 + -1.0 * A42) * (1.0 * B12 + -1.0 * B13 + -1.0 * B14 + -1.0 * B22 + 1.0 * B23 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S10(A11.m(), A11.n());
    Add(A12, A22, A32, A42, Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), S10);
    Matrix<Scalar> T10(B11.m(), B11.n());
    Add(B12, B13, B14, B22, B23, B24, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), T10);
    FastMatmulRecursive(S10, T10, M10, numsteps - 1, x);
    S10.deallocate();
    T10.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M11 = (-1.0 * A11 + 1.0 * A41 + 1.0 * A42) * (-1.0 * B12 + 1.0 * B22 + 1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S11(A11.m(), A11.n());
    Add(A11, A41, A42, Scalar(-1.0), Scalar(1.0), Scalar(1.0), S11);
    Matrix<Scalar> T11(B11.m(), B11.n());
    Add(B12, B22, B24, Scalar(-1.0), Scalar(1.0), Scalar(1.0), T11);
    FastMatmulRecursive(S11, T11, M11, numsteps - 1, x);
    S11.deallocate();
    T11.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M12 = (-1.0 * A12) * (1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M12.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A12, B24, M12, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M13 = (-1.0 * A41 + -1.0 * A42) * (-1.0 * B12)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S13(A11.m(), A11.n());
    Add(A41, A42, Scalar(-1.0), Scalar(-1.0), S13);
    M13.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S13, B12, M13, numsteps - 1, x);
    S13.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M14 = (-1.0 * A11) * (-1.0 * B14)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    M14.UpdateMultiplier(Scalar(-1));
    M14.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(A11, B14, M14, numsteps - 1, x);
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M15 = (-1.0 * A11 + 1.0 * A41) * (1.0 * B12 + 1.0 * B14 + -1.0 * B22 + -1.0 * B24)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S15(A11.m(), A11.n());
    Add(A11, A41, Scalar(-1.0), Scalar(1.0), S15);
    Matrix<Scalar> T15(B11.m(), B11.n());
    Add(B12, B14, B22, B24, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), T15);
    FastMatmulRecursive(S15, T15, M15, numsteps - 1, x);
    S15.deallocate();
    T15.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M16 = (1.0 * A21 + -1.0 * A32 + 1.0 * A41) * (1.0 * B11 + 1.0 * B12 + -1.0 * B13 + 1.0 * B21 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S16(A11.m(), A11.n());
    Add(A21, A32, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), S16);
    Matrix<Scalar> T16(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), T16);
    FastMatmulRecursive(S16, T16, M16, numsteps - 1, x);
    S16.deallocate();
    T16.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M17 = (1.0 * A31 + -1.0 * A32) * (1.0 * B11 + 1.0 * B12 + -1.0 * B13 + -1.0 * B21 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S17(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(-1.0), S17);
    Matrix<Scalar> T17(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T17);
    FastMatmulRecursive(S17, T17, M17, numsteps - 1, x);
    S17.deallocate();
    T17.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M18 = (1.0 * A21 + -1.0 * A31 + 1.0 * A41) * (1.0 * B12 + -1.0 * B13 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S18(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(1.0), S18);
    Matrix<Scalar> T18(B11.m(), B11.n());
    Add(B12, B13, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T18);
    FastMatmulRecursive(S18, T18, M18, numsteps - 1, x);
    S18.deallocate();
    T18.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M19 = (1.0 * A21 + -1.0 * A31 + -1.0 * A41) * (-1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S19(A11.m(), A11.n());
    Add(A21, A31, A41, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S19);
    M19.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S19, B13, M19, numsteps - 1, x);
    S19.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M20 = (1.0 * A31 + 1.0 * A32) * (1.0 * B11 + 1.0 * B12 + -1.0 * B13 + 1.0 * B21 + 1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S20(A11.m(), A11.n());
    Add(A31, A32, Scalar(1.0), Scalar(1.0), S20);
    Matrix<Scalar> T20(B11.m(), B11.n());
    Add(B11, B12, B13, B21, B22, B23, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), T20);
    FastMatmulRecursive(S20, T20, M20, numsteps - 1, x);
    S20.deallocate();
    T20.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M21 = (-1.0 * A12 + -1.0 * A21 + -1.0 * A22 + 1.0 * A31 + 1.0 * A32 + -1.0 * A41 + -1.0 * A42) * (1.0 * B12 + -1.0 * B13 + -1.0 * B14 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S21(A11.m(), A11.n());
    Add(A12, A21, A22, A31, A32, A41, A42, Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S21);
    Matrix<Scalar> T21(B11.m(), B11.n());
    Add(B12, B13, B14, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), T21);
    FastMatmulRecursive(S21, T21, M21, numsteps - 1, x);
    S21.deallocate();
    T21.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M22 = (1.0 * A22) * (1.0 * B11 + -1.0 * B13 + 1.0 * B21 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> T22(B11.m(), B11.n());
    Add(B11, B13, B21, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), T22);
    FastMatmulRecursive(A22, T22, M22, numsteps - 1, x);
    T22.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M23 = (1.0 * A22 + -1.0 * A32 + -1.0 * A42) * (-1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S23(A11.m(), A11.n());
    Add(A22, A32, A42, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), S23);
    M23.UpdateMultiplier(Scalar(-1));
    FastMatmulRecursive(S23, B23, M23, numsteps - 1, x);
    S23.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M24 = (1.0 * A21 + 1.0 * A22 + -1.0 * A31 + -1.0 * A32 + 1.0 * A41 + 1.0 * A42) * (1.0 * B22 + -1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S24(A11.m(), A11.n());
    Add(A21, A22, A31, A32, A41, A42, Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), S24);
    Matrix<Scalar> T24(B11.m(), B11.n());
    Add(B22, B23, Scalar(1.0), Scalar(-1.0), T24);
    FastMatmulRecursive(S24, T24, M24, numsteps - 1, x);
    S24.deallocate();
    T24.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M25 = (-0.5 * A21 + 0.5 * A31 + -0.5 * A41 + -1.0 * A42) * (1.0 * B12 + -1.0 * B22 + 1.0 * B23)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S25(A11.m(), A11.n());
    Add(A21, A31, A41, A42, Scalar(-0.5), Scalar(0.5), Scalar(-0.5), Scalar(-1.0), S25);
    Matrix<Scalar> T25(B11.m(), B11.n());
    Add(B12, B22, B23, Scalar(1.0), Scalar(-1.0), Scalar(1.0), T25);
    FastMatmulRecursive(S25, T25, M25, numsteps - 1, x);
    S25.deallocate();
    T25.deallocate();
#ifdef _CILK_
    }();
#elif defined _OPEN_MP_
    }
#endif

    // M26 = (1.0 * A21 + -1.0 * A22) * (1.0 * B11 + -1.0 * B13)
#ifdef _CILK_
    cilk_spawn [&] {
#elif defined _OPEN_MP_
# pragma omp task
    {
#endif
    Matrix<Scalar> S26(A11.m(), A11.n());
    Add(A21, A22, Scalar(1.0), Scalar(-1.0), S26);
    Matrix<Scalar> T26(B11.m(), B11.n());
    Add(B11, B13, Scalar(1.0), Scalar(-1.0), T26);
    FastMatmulRecursive(S26, T26, M26, numsteps - 1, x);
    S26.deallocate();
    T26.deallocate();
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
    Add(M1, M4, M9, M14, Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(-1.0), C11);
    Add(M6, M11, M12, M13, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C12);
    Add(M3, M6, M11, M12, M13, M14, M21, M24, Scalar(1.0), Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(1.0), C13);
    Add(M12, M14, Scalar(-1.0), Scalar(1.0), C14);
    Add(M2, M8, M19, M26, Scalar(1.0), Scalar(0.5), Scalar(-0.5), Scalar(1.0), C21);
    Add(M2, M13, M16, M20, M22, M24, M25, Scalar(1.0), Scalar(-1.0), Scalar(0.5), Scalar(0.5), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), C22);
    Add(M2, M8, M19, M22, Scalar(1.0), Scalar(0.5), Scalar(-0.5), Scalar(-1.0), C23);
    Add(M4, M5, M7, M8, M10, M11, M12, M14, M15, M18, M21, Scalar(0.5), Scalar(1.0), Scalar(-0.5), Scalar(-0.5), Scalar(-0.5), Scalar(-1.0), Scalar(1.0), Scalar(-1.0), Scalar(-1.0), Scalar(0.5), Scalar(0.5), C24);
    Add(M8, M16, M17, M18, Scalar(0.5), Scalar(-0.5), Scalar(0.5), Scalar(0.5), C31);
    Add(M2, M5, M16, M20, M22, M23, M25, Scalar(1.0), Scalar(-1.0), Scalar(0.5), Scalar(0.5), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C32);
    Add(M2, M5, M8, M18, M22, M23, M25, Scalar(1.0), Scalar(-1.0), Scalar(0.5), Scalar(0.5), Scalar(-1.0), Scalar(1.0), Scalar(1.0), C33);
    Add(M4, M7, M8, M10, M18, M21, Scalar(0.5), Scalar(-0.5), Scalar(-0.5), Scalar(0.5), Scalar(-0.5), Scalar(-0.5), C34);
    Add(M2, M9, M16, M17, M18, M19, M26, Scalar(-1.0), Scalar(1.0), Scalar(0.5), Scalar(-0.5), Scalar(-0.5), Scalar(0.5), Scalar(-1.0), C41);
    Add(M5, M13, Scalar(1.0), Scalar(1.0), C42);
    Add(M5, M18, M19, M25, Scalar(1.0), Scalar(-0.5), Scalar(0.5), Scalar(-1.0), C43);
    Add(M5, M11, M14, M15, Scalar(-1.0), Scalar(1.0), Scalar(1.0), Scalar(1.0), C44);


    // Handle edge cases with dynamic peeling
    DynamicPeeling(A, B, C, 4, 2, 4);
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

}  // namespace grey424_26_257

#endif  // _grey424_26_257_HPP_
