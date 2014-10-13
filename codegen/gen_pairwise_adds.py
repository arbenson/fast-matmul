import sys

'''
This script automatically generates the Add() functions needed by the fast algorithms.
The adds are the "pairwise version", i.e., the adds look like:

C  = alpha1 * A1
C += alpha2 * A2
C += alpha3 * A3
  .
  .
  .
C += alphaN * AN

Each add can be a manually written for loop or a DAXPY add.  Usage:

python gen_pairwise_adds.py manual

OR

python gen_pairwise_adds.py daxpy
'''


def write_Add(num_adds, add_type='manual'):
    all_nums = range(1, num_adds + 1)
    add = 'template <typename Scalar>\n'
    add += 'void SlowAdd('
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
    if add_type == 'manual':
        func_name = 'UpdateAdd'
    elif add_type == 'daxpy':
        func_name = 'UpdateAddDaxpy'
    else:
        raise Exception('Unknown add type: %s' % add_type)

    for i in range(2, num_adds + 1):
        add += '    %s(A%d, alpha%d, C);\n' % (func_name, i, i)
    add += '}\n'

    return add


if len(sys.argv) < 2:
    raise Exception('USAGE: python gen_pairwise_adds.py add_type')
add_type = sys.argv[1]
header_name = add_type.upper()
print '#ifndef _ALL_PAIRWISE_%s_ADDS_HPP_' % header_name
print '#define _ALL_PAIRWISE_%s_ADDS_HPP_' % header_name

for i in range(1, 40):
    print write_Add(i, add_type=add_type)
    print ''
print '\n#endif  // _ALL_PAIRWISE_%s_ADDS_HPP_' % header_name
