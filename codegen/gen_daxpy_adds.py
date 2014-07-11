'''
This script automatically generates the Add() functions needed by the fast algorithms.
'''

def write_Add(num_adds):
    all_nums = range(1, num_adds + 1)
    add = 'template <typename Scalar>\n'
    add += 'void BlasAdd('
    add += ' '.join(['Matrix<Scalar>& A%d,' % i for i in all_nums])
    add += '\n'
    add += '         '
    add += ' '.join(['Scalar alpha%d,' % i for i in all_nums])
    add += '\n'
    add += '         '
    add += 'Matrix<Scalar>& C) {\n'

    # Assertions for debugging
    for i in all_nums:
        add += '    assert(A%d.m() == C.m() && A%d.n() == C.n());\n' % (i, i)
    add += '\n'

    # All of the strides
    for i in all_nums:
        add += '    const int strideA%d = A%d.stride();\n' % (i, i)
    add += '    const int strideC = C.stride();\n\n'

    # All of the data pointers
    for i in all_nums:
        add += '    Scalar *dataA%d = A%d.data();\n' % (i, i)
    add += '    Scalar *dataC = C.data();\n\n'

    add += '    Scalar *c = 0;\n'
    add += '    for (int j = 0; j < C.n(); ++j) {\n'
    for ind, i in enumerate(all_nums):
        if ind == 0:
            add += '        c = dataC + j * strideC;\n'
        add += '        Scalar *a%d = dataA%d + j * strideA%d;\n' % (i, i, i)
        add += '        Axpy(c, a%d, C.m(), alpha%d);\n' % (i, i)
    add += '    }\n'
    add += '}\n'

    return add


print '#ifndef _ALL_BLAS_ADDS_HPP_'
print '#define _ALL_BLAS_ADDS_HPP_\n'

axpy_funcs = '''
// C <-- alpha * A + C
//template <typename Scalar>
void AxpyWrap(double *C, double *A, int n, double alpha) {
  int incx = 1;
  int incy = 1;
  daxpy_(&n, &alpha, A, &incx, C, &incy);
}

// C <-- alpha * A + C
//template <typename Scalar>
void AxpyWrap(float *C, float *A, int n, float alpha) {
  int incx = 1;
  int incy = 1;
  saxpy_(&n, &alpha, A, &incx, C, &incy);
}

template<typename Scalar>
void Axpy(Scalar *C, Scalar *A, int n, Scalar alpha) {
  AxpyWrap(C, A, n, alpha);
}
'''

print axpy_funcs


for i in range(1, 40):
    print write_Add(i)
    print ''
print '\n#endif  // _ALL_ADDS_HPP_'
