extern "C" {
    void dgemm_(char *transa, char *transb, int *m, int *n, int *k,
		double *alpha, double *a, int *lda, double *b, int *ldb,
		double *beta, double *c, int *ldc);
}

template <typename T>
class Matrix<T> {
public:
    Matrix(T *data, int stride, m, n):
	data_(data), stride_(stride), m_(m), n_(n);

    Matrix(int n) {
	stride_ = n;
	m_ = n;
	n_ = n;
	allocate();
    }

    ~Matrix() {
	deallocate();
    }

    T *data() { return data_; }
    int stride() { return stride_; }
    int m() { return m_; }
    int n() { return n_; }

    void allocate() {
	data_ = new T[m_ * n_];
	assert(data_ != NULL);
    }

    void deallocate() {
	assert(data_ != NULL);
	delete data_;
    }

private:
    T *data_;
    int stride_;
    int m_;
    int n_;
};

void dgemm_wrap(int dim, double *A, int lda, double *B, int ldb, double *C, int ldc) {
    chat transa = 'n';
    chat transb = 'n';
    double alpha = 1;
    double beta = 0;
    dgemm_(&transa, &transb, &n, &n, &n, &alpha, A, &lda, B, &ldb, beta, C, &ldc);
}

// C <-- A * B
void gemm(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C) {
    // TODO: implement this
}

// C <-- alpha1 * A1 + alpha2 * A2
void add(Matrix<T>& A1, Matrix<T>& A2, Matrix<T>& C,
	 T alpha1, T alpha2) {
    assert(A1.m() == A1.n() &&
	   A1.n() == A2.m() &&
	   A2.m() == A2.n() &&
	   A2.n() == C.m() &&
	   C.m() == C.n());
    for (int j = 0; j < C.m(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	    a = alpha1 * A1.data()[i + j * A1.stride()];
	    b = alpha2 * A2.data()[i + j * A2.stride()];
	    C.data()[i + j * C.stride()] = a + b;
	}
    }
}

// C <-- alpah1 * A1 + alpha2 * A2 + alpha3 * A3
void add(Matrix<T>& A1, Matrix<T>& A2, Matrix<T> A3, Matrix<T>& C,
	 T alpha1, T alpha2, T alpha3) {
    assert(A1.m() == A1.n() &&
	   A1.n() == A2.m() &&
	   A2.m() == A2.n() &&
	   A2.n() == A3.m() &&
	   A3.m() == A3.n() &&
	   A3.n() == C.m() &&
	   C.m() == C.n());
    for (int j = 0; j < C.m(); ++j) {
	for (int i = 0; i < C.m(); ++i) {
	    a = alpha1 * A1.data()[i + j * A1.stride()];
	    b = alpha2 * A2.data()[i + j * A2.stride()];
	    c = alpha3 * A3.data()[i + j * A3.stride()];
	    C.data()[i + j * C.stride()] = a + b + c;
	}
    }
}

void FastMatmul3x3(Matrix<T>& A, Matrix<T>& B, Matrix<T>& C) {
    int n = A.n();
    int step = n / 3;

    if (n <= 27) {
	gemm(A, B, C);
    }

    // Sub-blocks of A
    Matrix<T> A11(A.data(), A.stride(), step, step);
    Matrix<T> A21(A.data() + step, A.stride(), step, step);
    Matrix<T> A31(A.data() + 2 * step, A.stride(), step, step);
    Matrix<T> A21(A.data() + step * A.stride(), A.stride(), step, step);
    Matrix<T> A22(A.data() + step * A.stride() + step, A.stride(), step, step);
    Matrix<T> A23(A.data() + step * A.stride() + 2 * step, A.stride(), step, step);
    Matrix<T> A31(A.data() + 2 * step * A.stride(), A.stride(), step, step);
    Matrix<T> A32(A.data() + 2 * step * A.stride() + step, A.stride(), step, step);
    Matrix<T> A33(A.data() + 2 * step * A.stride() + 2 * step, A.stride(), step, step);

    // Sub-blocks of B
    Matrix<T> B11(B.data(), B.stride(), step, step);
    Matrix<T> B21(B.data() + step, B.stride(), step, step);
    Matrix<T> B31(B.data() + 2 * step, B.stride(), step, step);
    Matrix<T> B21(B.data() + step * B.stride(), B.stride(), step, step);
    Matrix<T> B22(B.data() + step * B.stride() + step, B.stride(), step, step);
    Matrix<T> B23(B.data() + step * B.stride() + 2 * step, B.stride(), step, step);
    Matrix<T> B31(B.data() + 2 * step * B.stride(), B.stride(), step, step);
    Matrix<T> B32(B.data() + 2 * step * B.stride() + step, B.stride(), step, step);
    Matrix<T> B33(B.data() + 2 * step * B.stride() + 2 * step, B.stride(), step, step);

    // Sub-blocks of C
    Matrix<T> C11(C.data(), C.stride(), step, step);
    Matrix<T> C21(C.data() + step, C.stride(), step, step);
    Matrix<T> C31(C.data() + 2 * step, C.stride(), step, step);
    Matrix<T> C21(C.data() + step * C.stride(), C.stride(), step, step);
    Matrix<T> C22(C.data() + step * C.stride() + step, C.stride(), step, step);
    Matrix<T> C23(C.data() + step * C.stride() + 2 * step, C.stride(), step, step);
    Matrix<T> C31(C.data() + 2 * step * C.stride(), C.stride(), step, step);
    Matrix<T> C32(C.data() + 2 * step * C.stride() + step, C.stride(), step, step);
    Matrix<T> C33(C.data() + 2 * step * C.stride() + 2 * step, C.stride(), step, step);

    // Pre summations
    // S1 = -A31 - A32;
    Matrix<T> S1(step);
    add(A31, A32, -1, -1, S1);
    
    // S2 = A22 + A23;
    Matrix<T> S2(step);
    add(A22, A23, 1, 1, S2);

    // S3 = -A13 + S2;
    Matrix<T> S3(step);
    add(A13, S2, -1, 1, S3);

    // S4 = -B22 - B23;
    Matrix<T> S4(step);
    add(B22, B23, -1, -1, S4);

    // S5 = B22 - B32;
    Matrix<T> S5(step);
    add(B22, B32, 1, -1, S5);


    // M1 =  (A33)                    * (-B11 - B21 + B31);
    Matrix<T> M1(step);
    Matrix<T> M1B(step);
    add(B11, B21, B31, -1, -1, 1, M1B);
    FastMatmul3x3(A33, M1B, M1);
    M1B.deallocate();
    
    // M2 =  (A22 + A33)              * (-B21 + B32);
    Matrix<T> M2(step);
    Matrix<T> M2A(step);
    Matrix<T> M2B(step);
    add(A22, A33, 1, 1, M2A);
    add(B21, B32, -1, 1, M2B);
    FastMatmul3x3(M2A, M2B, M2);
    M2A.deallocate();
    M2B.deallocate();

    // M3 =  (A11 + A12 + A31 + A32)  * (B23);
    Matrix<T> M3(step);
    Matrix<T> M3A(step);
    add(A11, A12, A31, A32, 1, 1, 1, 1);
    FastMatmul3x3(M3A, B23, M3);
    M3A.deallocate();

    // M4 =  (-A11 + A21)             * (B12 + B13);    
    Matrix<T> M4(step);
    Matrix<T> M4A(step);
    Matrix<T> M4B(step);
    add(A11, A21, -1, 1, M4A);
    add(B12, B12, 1, 1, M4B);
    FastMatmul3x3(M4A, M4B, M4);
    M4A.deallocate();
    M4B.deallocate();

    // M5 =  (S1)                     * (-B12);
    Matrix<T> M5(step);
    // TODO: need to negate B12
    FastMatmul3x3(S1, B12, M4);

    // M6 =  (S2)                     * (B32);
    Matrix<T> M6(step);
    FastMatmul3x3(S2, B32, M6);

    // M7 =  (-A21 - A33)             * (B11);
    Matrix<T> M7(step);
    Matrix<T> M7A(step);
    add(A21, A33, -1, -1, M7A);
    FastMatmul3x3(M7A, B11, M7);
    M7A.deallocate();

    // M8 =  (A31 + A33)              * (B11);
    Matrix<T> M8(step);
    Matrix<T> M8A(step);
    add(A31, A33, 1, 1, M8A);
    FastMatmul3x3(M8A, B11, M8);
    M8A.deallocate();

    // M9 =  (A22)                    * (-B12 + S5);
    Matrix<T> M9(step);
    Matrix<T> M9B(step);    
    add(B12, S5, -1, 1, M9B);
    FastMatmul3x3(A22, M9B, M9);
    M9B.deallocate();

    // M10 = (A22 - A32)              * (B12 + B21 - B22);
    Matrix<T> M10(step);
    Matrix<T> M10A(step);
    Matrix<T> M10B(step);
    add(A22, A32, 1, -1, M10A);
    add(B12, B21, B22, 1, 1, -1, M10B);
    FastMatmul3x3(M10A, M10B, M10);
    M10A.deallocate();
    M10B.deallocate();

    // M11 = (-A32 - A33)             * (B21);
    Matrix<T> M11(step);
    Matrix<T> M11A(step);
    add(A32, A33, -1, -1, M11A);
    FastMatmul3x3(M11A, B21, M11);
    M11A.deallocate();

    // M12 = (S3)                     * (S5 + B23);
    Matrix<T> M12(step);
    Matrix<T> M12B(step);
    add(S5, B23, 1, 1, M12B);
    FastMatmul3x3(S3, M12B, M12);    
    M12B.deallocate();
    
    // M13 = (A13 + A33)              * (B31 + B33);
    Matrix<T> M13(step);
    Matrix<T> M13A(step);
    Matrix<T> M13B(step);
    add(A12, A33, 1, 1, M13A);
    add(B32, B33, 1, 1, M13B);
    FastMatmul3x3(M13A, M13B, M13);
    M13A.deallocate();
    M13B.deallocate();

    // M14 = (A11 + A31)              * (B11 + B13 - B23);
    Matrix<T> M14(step);
    Matrix<T> M14A(step);
    Matrix<T> M14B(step);
    add(A11, A31, 1, 1, M14A);
    add(B11, B13, B23, 1, 1, -1, M14B);
    FastMatmul3x3(M14A, M14B, M14);
    M14A.deallocate();
    M14B.deallocate();

    
    // M15 = (-A11 + A33)             * (B11 + B33);
    Matrix<T> M15(step);
    Matrix<T> M15B(step);
    Matrix<T> M15B(step);
    add(A11, A33, -1, 1, M15A);
    add(B11, B33, 1, 1, M15B);
    FastMatmul3x3(M15A, M15B, M15);
    M15A.deallocate();
    M15B.deallocate();
    
    // M16 = (-A13 + A23)             * (S4 + B32 + B33);
    Matrix<T> M16(step);
    Matrix<T> M16A(step);
    Matrix<T> M16B(step);
    add(A13, A23, 1, -1, M16A);
    add(S4, B32, B33, 1, 1, 1, M16B);
    FastMatmul3x3(M16A, M16B, M16);
    M16A.deallocate();
    M16B.deallocate();

    // M17 = (-A12 + S3)              * (S4);
    Matrix<T> M17(step);
    Matrix<T> M17A(step);
    add(A12, S3, -1, 1, M17A);
    FastMatmul3x3(M17A, S4, M17);
    M16A.deallocate();

    // M18 = (-A23 + A33)             * (-B31 + B32);
    Matrix<T> M18(step);
    Matrix<T> M18A(step);
    Matrix<T> M18B(step);
    add(A23, A33, -1, 1, M18A);
    add(B31, B32, -1, 1, M18B);
    FastMatmul3x3(M18A, M18B, M18);
    M18A.deallocate();
    M18B.deallocate();

    // M19 = (-A11 + S1)              * (-B12 - B23);
    Matrix<T> M19(step);
    Matrix<T> M19A(step);
    Matrix<T> M19B(step);
    add(A11, S1, -1, 1, M19A);
    add(B12, B23, -1, -1, M19B);
    FastMatmul3x3(M19A, M19B, M19);
    M19A.deallocate();
    M19B.deallocate();

    // M20 = (-A11 - A13)             * (B33);
    Matrix<T> M20(step);
    Matrix<T> M20A(step);
    add(A11, A13, -1, -1, M20A);
    FastMatmul3x3(M20A, B33, M20);
    M20A.deallocate();

    // M21 = (A11)                    * (-B12 - B13 + B33);
    Matrix<T> M21(step);
    Matrix<T> M21B(step);
    add(B12, B13, B33, -1, -1, 1, M21B);
    FastMatmul3x3(A11, M21B, M21);
    M21B.deallocate();

    // M22 = (-A21 - A22)             * (B12);
    Matrix<T> M22(step);
    Matrix<T> M22A(step);
    add(A21, A22, -1, -1, M22A);
    FastMatmul3x3(M22A, B12, M22);
    M22A.deallocate();

    // M23 = (-A12 + A33)             * (B21);
    Matrix<T> M23(step);
    Matrix<T> M23A(step);
    add(A12, A33, -1, 1, M23A);
    FastMatmul3x3(M23A, B21, M22);
    M23A.deallocate();


    //  R1 = -M20 - M21;
    Matrix<T> R1(step);
    add(M20, M21, -1, -1, R1);

    Matrix<T> tmp1(step);
    Matrix<T> tmp2(step);

    // C11 = -M1 + M13 - M15 + M20 - M23;
    add(M1, M13, M15, -1, 1, -1, tmp1);
    add(tmp1, M20, M23, 1, 1, -1, C11);
	
    // C12 = -M3 - M5 + M6 + M12 + M17 + M19;
    add(M3, M5, M6, -1, -1, 1, tmp1);
    add(M12, M17, M19, 1, 1, 1, tmp2);
    add(tmp1, tmp2, 1, 1, C12);

    // C13 = M3 + M5 - M19 + R1;
    add(M3, M5, M19, 1, 1, -1, tmp1);
    add(tmp1, R1, 1, 1, C13);

    // C21 = M1 - M2 + M6 - M7 + M18;
    add(M1, M2, M6, 1, -1, 1, tmp1);
    add(tmp1, M7, M18, 1, -1, 1, C21);

    // C22 = M6 + M9 - M22;
    add(M6, M9, M22, 1, 1, -1, C22);

    // C23 = M4 - M9 + M12 + M16 + R1 + M22;
    add(M4, M9, M12, 1, -1, 1, tmp1);
    add(M16, R1, M22, 1, 1, 1, tmp2);
    add(tmp1, tmp2, 1, 1, C23);

    // C31 = M1 + M8 - M11;
    add(M1, M8, M11, 1, 1, -1, C31);

    // C32 = M2 + M5 + M9 + M10 - M11;
    add(M2, M5, M9, 1, 1, 1, tmp1);
    add(tmp1, M10, M11, 1, 1, -1, C32);

    // C33 = -M5 - M8 + M14 + M15 + M19 + M21;
    add(M5, M8, M14, -1, -1, 1, tmp1);
    add(M15, M19, M21, 1, 1, 1, tmp2);
    add(tmp1, tmp2, 1, 1, C33);
}

