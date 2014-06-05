#ifndef _FAST_3x3_HPP_
#define _FAST_3x3_HPP_

#include "linalg.hpp"

#ifdef _CILK_
# include <cilk/cilk.h>
#endif

// C <-- A * B with fast 3x3 matrix multiplication
// All matrices are assumed to be square with dimension a power of 3
// numsteps is the number of recursive steps to take before using
// classical matrix multiplication
template <typename Scalar>
void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C,
		int numsteps) {
    // Base case for recursion
    if (numsteps == 0) {
        Gemm(A, B, C);
        return;
    }

    const int n = A.n();
    const int step = n / 3;

    // Get a view of all sub-blocks in 3 x 3 partitioning of the matrices.
    // Sub-blocks of A
    Matrix<Scalar> A11(A.data(), A.stride(), step, step);
    Matrix<Scalar> A21(A.data() + step, A.stride(), step, step);
    Matrix<Scalar> A31(A.data() + 2 * step, A.stride(), step, step);
    Matrix<Scalar> A12(A.data() + step * A.stride(), A.stride(), step, step);
    Matrix<Scalar> A22(A.data() + step * A.stride() + step, A.stride(), step, step);
    Matrix<Scalar> A32(A.data() + step * A.stride() + 2 * step, A.stride(), step, step);
    Matrix<Scalar> A13(A.data() + 2 * step * A.stride(), A.stride(), step, step);
    Matrix<Scalar> A23(A.data() + 2 * step * A.stride() + step, A.stride(), step, step);
    Matrix<Scalar> A33(A.data() + 2 * step * A.stride() + 2 * step, A.stride(), step, step);

    // Sub-blocks of B
    Matrix<Scalar> B11(B.data(), B.stride(), step, step);
    Matrix<Scalar> B21(B.data() + step, B.stride(), step, step);
    Matrix<Scalar> B31(B.data() + 2 * step, B.stride(), step, step);
    Matrix<Scalar> B12(B.data() + step * B.stride(), B.stride(), step, step);
    Matrix<Scalar> B22(B.data() + step * B.stride() + step, B.stride(), step, step);
    Matrix<Scalar> B32(B.data() + step * B.stride() + 2 * step, B.stride(), step, step);
    Matrix<Scalar> B13(B.data() + 2 * step * B.stride(), B.stride(), step, step);
    Matrix<Scalar> B23(B.data() + 2 * step * B.stride() + step, B.stride(), step, step);
    Matrix<Scalar> B33(B.data() + 2 * step * B.stride() + 2 * step, B.stride(), step, step);

    // Sub-blocks of C
    Matrix<Scalar> C11(C.data(), C.stride(), step, step);
    Matrix<Scalar> C21(C.data() + step, C.stride(), step, step);
    Matrix<Scalar> C31(C.data() + 2 * step, C.stride(), step, step);
    Matrix<Scalar> C12(C.data() + step * C.stride(), C.stride(), step, step);
    Matrix<Scalar> C22(C.data() + step * C.stride() + step, C.stride(), step, step);
    Matrix<Scalar> C32(C.data() + step * C.stride() + 2 * step, C.stride(), step, step);
    Matrix<Scalar> C13(C.data() + 2 * step * C.stride(), C.stride(), step, step);
    Matrix<Scalar> C23(C.data() + 2 * step * C.stride() + step, C.stride(), step, step);
    Matrix<Scalar> C33(C.data() + 2 * step * C.stride() + 2 * step, C.stride(), step, step);

    Scalar NegOne = Scalar(-1);
    Scalar One = Scalar(1);

    // Number of additions/subtractions:
    // Pre-compute:
    //
    // S1 = -A31 - A32; [1]
    // S2 = A22 + A23;  [1]
    // S3 = -A13 + S2;  [1]
    // S4 = -B22 - B23; [1]
    // S5 = B22 - B32;  [1]
    // S6 = A11 + A31;  [1]
    // 6 in total
    //
    //  M1 =  (A33)                    * (-B11 - B21 + B31); [2]
    //  M2 =  (A22 + A33)              * (-B21 + B32);       [2]
    //  M3 =  (S6 + A12 + A32)         * (B23);              [2]
    //  M4 =  (-A11 + A21)             * (B12 + B13);        [2]
    //  M5 =  (S1)                     * (-B12);             [0/1]
    //  M6 =  (S2)                     * (B32);              [0]
    //  M7 =  (-A21 - A33)             * (B11);              [1]
    //  M8 =  (A31 + A33)              * (B11);              [1]
    //  M9 =  (A22)                    * (-B12 + S5);        [1]
    //  M10 = (A22 - A32)              * (B12 + B21 - B22);  [3]
    //  M11 = (-A32 - A33)             * (B21);              [1]
    //  M12 = (S3)                     * (S5 + B23);         [1]
    //  M13 = (A13 + A33)              * (B31 + B33);        [2]
    //  M14 = (S6)                     * (B11 + B13 - B23);  [2]
    //  M15 = (-A11 + A33)             * (B11 + B33);        [2]
    //  M16 = (-A13 + A23)             * (S4 + B32 + B33);   [3]
    //  M17 = (-A12 + S3)              * (S4);               [1]
    //  M18 = (-A23 + A33)             * (-B31 + B32);       [2]
    //  M19 = (-A11 + S1)              * (-B12 - B23);       [2]
    //  M20 = (-A11 - A13)             * (B33);              [1]
    //  M21 = (A11)                    * (-B12 - B13 + B33); [2]
    //  M22 = (-A21 - A22)             * (B12);              [1]
    //  M23 = (-A12 + A33)             * (B21);              [1]
    //
    // For M5, we don't need one addition, but it requires some extra code.
    // We need to negate B12 but it needs to be done in the matrix multiply.
    // With recursion, this is a little tricky.  For now, we just negate
    // and suffer from one more "subtraction".
    // In total, 35 additions/subtractions (not counting negation) for the 
    // intermediate multiplications.
    //
    // Pre-compute for formulation of C blocks:
    // 
    // R1 = -M20 - M21;                         [1]
    // R2 = M3 + M5;                            [1]
    // R3 = M9 - M22;                           [1]
    // 
    // In total, 3 additions/subtractions
    // 
    // C11 = -M1 + M13 - M15 + M20 - M23;       [4]
    // C12 = -R2 + M6 + M12 + M17 + M19;        [4]
    // C13 = R2 - M19 + R1;                     [2]
    // C21 = M1 - M2 + M6 - M7 + M18;           [4]
    // C22 = M6 + R3;                           [1]
    // C23 = M4 - R3 + M12 + M16 + R1;          [4]
    // C31 = M1 + M8 - M11;                     [2]
    // C32 = M2 + M5 + M9 + M10 - M11;          [4]
    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;  [5]
    // 
    // In total, 30 additions/subtractions
    //
    // Overall: 6 + 35 + 3 + 30 = 74 additions/subtractions

    // S1, ..., S5 variables are pre-computations of summations
    // that are used multiple times in the multiplications.
    // S1 = -A31 - A32;
    Matrix<Scalar> S1(step);
    Add(A31, A32, NegOne, NegOne, S1);
    
    // S2 = A22 + A23;
    Matrix<Scalar> S2(step);
    Add(A22, A23, One, One, S2);

    // S3 = -A13 + S2;
    Matrix<Scalar> S3(step);
    Add(A13, S2, NegOne, One, S3);

    // S4 = -B22 - B23;
    Matrix<Scalar> S4(step);
    Add(B22, B23, NegOne, NegOne, S4);

    // S5 = B22 - B32;
    Matrix<Scalar> S5(step);
    Add(B22, B32, One, NegOne, S5);

    // S6 = A11 + A31;
    Matrix<Scalar> S6(step);
    Add(A11, A31, One, One, S6);


    // M1, M2, ..., M23 are the intermediate matrix multiplications
    // We define them here so that they can be used inside the lambda functions
    // for Cilk.
    Matrix<Scalar> M1(step), M2(step), M3(step), M4(step), M5(step), M6(step), 
	M7(step), M8(step), M9(step), M10(step), M11(step), M12(step),
	M13(step), M14(step), M15(step), M16(step), M17(step), M18(step),
	M19(step), M20(step), M21(step), M22(step), M23(step);

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    //  M1 =  (A33)                    * (-B11 - B21 + B31);
    Matrix<Scalar> M1B(step);
    Add(B11, B21, B31, NegOne, NegOne, One, M1B);
    FastMatmul(A33, M1B, M1, numsteps - 1);
    M1B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M2 =  (A22 + A33)              * (-B21 + B32);
    Matrix<Scalar> M2A(step);
    Matrix<Scalar> M2B(step);
    Add(A22, A33, One, One, M2A);
    Add(B21, B32, NegOne, One, M2B);
    FastMatmul(M2A, M2B, M2, numsteps - 1);
    M2A.deallocate();
    M2B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M3 =  (S6 + A12 + A32)  * (B23);
    Matrix<Scalar> M3A(step);
    Add(S6, A12, A32, One, One, One, M3A);
    FastMatmul(M3A, B23, M3, numsteps - 1);
    M3A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M4 =  (-A11 + A21)             * (B12 + B13);    
    Matrix<Scalar> M4A(step);
    Matrix<Scalar> M4B(step);
    Add(A11, A21, NegOne, One, M4A);
    Add(B12, B13, One, One, M4B);
    FastMatmul(M4A, M4B, M4, numsteps - 1);
    M4A.deallocate();
    M4B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M5 =  (S1)                     * (-B12);
    Matrix<Scalar> M5B(step);
    Negate(B12, M5B);
    FastMatmul(S1, M5B, M5, numsteps - 1);
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M6 =  (S2)                     * (B32);
    FastMatmul(S2, B32, M6, numsteps - 1);
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M7 =  (-A21 - A33)             * (B11);
    Matrix<Scalar> M7A(step);
    Add(A21, A33, NegOne, NegOne, M7A);
    FastMatmul(M7A, B11, M7, numsteps - 1);
    M7A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M8 =  (A31 + A33)              * (B11);
    Matrix<Scalar> M8A(step);
    Add(A31, A33, One, One, M8A);
    FastMatmul(M8A, B11, M8, numsteps - 1);
    M8A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M9 =  (A22)                    * (-B12 + S5);
    Matrix<Scalar> M9B(step);    
    Add(B12, S5, NegOne, One, M9B);
    FastMatmul(A22, M9B, M9, numsteps - 1);
    M9B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M10 = (A22 - A32)              * (B12 + B21 - B22);
    Matrix<Scalar> M10A(step);
    Matrix<Scalar> M10B(step);
    Add(A22, A32, One, NegOne, M10A);
    Add(B12, B21, B22, One, One, NegOne, M10B);
    FastMatmul(M10A, M10B, M10, numsteps - 1);
    M10A.deallocate();
    M10B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M11 = (-A32 - A33)             * (B21);
    Matrix<Scalar> M11A(step);
    Add(A32, A33, NegOne, NegOne, M11A);
    FastMatmul(M11A, B21, M11, numsteps - 1);
    M11A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M12 = (S3)                     * (S5 + B23);
    Matrix<Scalar> M12B(step);
    Add(S5, B23, One, One, M12B);
    FastMatmul(S3, M12B, M12, numsteps - 1);
    M12B.deallocate();
#ifdef _CILK_
    }();
#endif
    
#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M13 = (A13 + A33)              * (B31 + B33);
    Matrix<Scalar> M13A(step);
    Matrix<Scalar> M13B(step);
    Add(A13, A33, One, One, M13A);
    Add(B31, B33, One, One, M13B);
    FastMatmul(M13A, M13B, M13, numsteps - 1);
    M13A.deallocate();
    M13B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M14 = (S6)                     * (B11 + B13 - B23);
    Matrix<Scalar> M14B(step);
    Add(B11, B13, B23, One, One, NegOne, M14B);
    FastMatmul(S6, M14B, M14, numsteps - 1);
    M14B.deallocate();
#ifdef _CILK_
    }();
#endif
    
#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M15 = (-A11 + A33)             * (B11 + B33);
    Matrix<Scalar> M15A(step);
    Matrix<Scalar> M15B(step);
    Add(A11, A33, NegOne, One, M15A);
    Add(B11, B33, One, One, M15B);
    FastMatmul(M15A, M15B, M15, numsteps - 1);
    M15A.deallocate();
    M15B.deallocate();
#ifdef _CILK_
    }();
#endif
    
#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M16 = (-A13 + A23)             * (S4 + B32 + B33);
    Matrix<Scalar> M16A(step);
    Matrix<Scalar> M16B(step);
    Add(A13, A23, NegOne, One, M16A);
    Add(S4, B32, B33, One, One, One, M16B);
    FastMatmul(M16A, M16B, M16, numsteps - 1);
    M16A.deallocate();
    M16B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M17 = (-A12 + S3)              * (S4);
    Matrix<Scalar> M17A(step);
    Add(A12, S3, NegOne, One, M17A);
    FastMatmul(M17A, S4, M17, numsteps - 1);
    M17A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M18 = (-A23 + A33)             * (-B31 + B32);
    Matrix<Scalar> M18A(step);
    Matrix<Scalar> M18B(step);
    Add(A23, A33, NegOne, One, M18A);
    Add(B31, B32, NegOne, One, M18B);
    FastMatmul(M18A, M18B, M18, numsteps - 1);
    M18A.deallocate();
    M18B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M19 = (-A11 + S1)              * (-B12 - B23);
    Matrix<Scalar> M19A(step);
    Matrix<Scalar> M19B(step);
    Add(A11, S1, NegOne, One, M19A);
    Add(B12, B23, NegOne, NegOne, M19B);
    FastMatmul(M19A, M19B, M19, numsteps - 1);
    M19A.deallocate();
    M19B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M20 = (-A11 - A13)             * (B33);
    Matrix<Scalar> M20A(step);
    Add(A11, A13, NegOne, NegOne, M20A);
    FastMatmul(M20A, B33, M20, numsteps - 1);
    M20A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M21 = (A11)                    * (-B12 - B13 + B33);
    Matrix<Scalar> M21B(step);
    Add(B12, B13, B33, NegOne, NegOne, One, M21B);
    FastMatmul(A11, M21B, M21, numsteps - 1);
    M21B.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M22 = (-A21 - A22)             * (B12);
    Matrix<Scalar> M22A(step);
    Add(A21, A22, NegOne, NegOne, M22A);
    FastMatmul(M22A, B12, M22, numsteps - 1);
    M22A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_spawn [&]{
#endif
    // M23 = (-A12 + A33)             * (B21);
    Matrix<Scalar> M23A(step);
    Add(A12, A33, NegOne, One, M23A);
    FastMatmul(M23A, B21, M23, numsteps - 1);
    M23A.deallocate();
#ifdef _CILK_
    }();
#endif

#ifdef _CILK_
    cilk_sync;
#endif

    // Fill in the matrix C

    // R1 = -M20 - M21;
    Matrix<Scalar> R1(step);
    Add(M20, M21, NegOne, NegOne, R1);
    // R2 = M3 + M5;
    Matrix<Scalar> R2(step);
    Add(M3, M5, One, One, R2);
    // R3 = M9 - M22;
    Matrix<Scalar> R3(step);
    Add(M9, M22, One, NegOne, R3);

    Matrix<Scalar> tmp1(step);
    Matrix<Scalar> tmp2(step);

    // C11 = -M1 + M13 - M15 + M20 - M23;
    Add(M1, M13, M15, NegOne, One, NegOne, tmp1);
    Add(tmp1, M20, M23, One, One, NegOne, C11);
        
    // C12 = -R2 + M6 + M12 + M17 + M19;
    Add(R2, M6, NegOne, One, tmp1);
    Add(M12, M17, M19, One, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C12);

    // C13 = R2 - M19 + R1;
    Add(R2, M19, R1, One, NegOne, One, C13);

    // C21 = M1 - M2 + M6 - M7 + M18;
    Add(M1, M2, M6, One, NegOne, One, tmp1);
    Add(tmp1, M7, M18, One, NegOne, One, C21);

    // C22 = M6 + R3;
    Add(M6, R3, One, One, C22);

    // C23 = M4 - R3 + M12 + M16 + R1;
    Add(M4, R3, M12, One, NegOne, One, tmp1);
    Add(M16, R1, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C23);

    // C31 = M1 + M8 - M11;
    Add(M1, M8, M11, One, One, NegOne, C31);

    // C32 = M2 + M5 + M9 + M10 - M11;
    Add(M2, M5, M9, One, One, One, tmp1);
    Add(tmp1, M10, M11, One, One, NegOne, C32);

    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;
    Add(M5, M8, M14, NegOne, NegOne, One, tmp1);
    Add(M15, M19, M21, One, One, One, tmp2);
    Add(tmp1, tmp2, One, One, C33);
    
    tmp1.deallocate();
    tmp2.deallocate();
}

// Template declarations
template void FastMatmul(Matrix<double>& A, Matrix<double>& B,
			 Matrix<double>& C, int numsteps);
template void FastMatmul(Matrix<float>& A, Matrix<float>& B,
			 Matrix<float>& C, int numsteps);

#endif  // _FAST_3x3_HPP_
