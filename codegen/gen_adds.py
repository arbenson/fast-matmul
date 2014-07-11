'''
This script automatically generates the Add() functions needed by the fast algorithms.
'''

def write_Add(num_adds):
    all_nums = range(1, num_adds + 1)
    add = 'template <typename Scalar>\n'
    add += 'void Add('
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
        add += '    const Scalar *dataA%d = A%d.data();\n' % (i, i)
    add += '    Scalar *dataC = C.data();\n\n'

    # The doubly-nested loop for the add
    add += '#ifdef _OPEN_MP_ADDS_\n'
    add += '# pragma omp parallel for collapse(2)\n'
    add += '#endif\n'
    add += '    for (int j = 0; j < C.n(); ++j) {\n'
    add += '        for (int i = 0; i < C.m(); ++i) {\n'

    for i in all_nums:
        add += '            Scalar a%d = alpha%d * dataA%d[i + j * strideA%d];\n' % (i, i, i, i)
    add += '            dataC[i + j * strideC] = ' + ' + '.join(['a%d' % i for i in all_nums]) + ';\n'
    add += '        }\n'
    add += '    }\n'
    add += '}\n'

    return add


print '#ifndef _ALL_ADDS_HPP_'
print '#define _ALL_ADDS_HPP_\n'
for i in range(1, 40):
    print write_Add(i)
    print ''
print '\n#endif  // _ALL_ADDS_HPP_'



