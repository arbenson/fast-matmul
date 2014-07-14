'''
This script automatically generates the Add() functions needed by the fast algorithms.
'''

def write_Add(num_adds):
    all_nums = range(1, num_adds + 1)
    add = 'template <typename Scalar>\n'
    add += 'void DaxpyAdd('
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

    # First add: C = alpha_1 * A_1
    add += '    Add(A1, alpha1, C);\n'
    # Subsequent adds: C = alpha_i A_i + C
    for i in range(2, num_adds + 1):
        add += '    UpdateAddDaxpy(A%d, alpha%d, C);\n' % (i, i)
    add += '}\n'

    return add


print '#ifndef _ALL_DAXPY_ADDS_HPP_'
print '#define _ALL_DAXPY_ADDS_HPP_\n'

for i in range(1, 40):
    print write_Add(i)
    print ''
print '\n#endif  // _ALL_DAXPY_ADDS_HPP_'
