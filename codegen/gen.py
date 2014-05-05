def write_line(header, num_indent, code):
    ''' Write the line of code with num_indent number of indents. '''
    header.write(' ' * 4 * num_indent + code + '\n')

def write_subblocks(header, mat_name, dim1, dim2):
    '''
    Write subblocks of matrix of dimensions dim1 x dim2.
    mat_name is the name of the matrix, e.g., 'A' or 'B'
    header is file to write to.
    '''
    x_step = '%s_x_step' % mat_name
    y_step = '%s_y_step' % mat_name
    write_line(header, 1, 'int %s = %s.m() / %d;' % (x_step, mat_name, dim1))
    write_line(header, 1, 'int %s = %s.n() / %d;' % (y_step, mat_name, dim2))
    for i in xrange(dim1):
        for j in xrange(dim2):
            write_line(header, 1, 'Matrix<Scalar> %s%d%d(%s.data() + %d * %s + %d * %s * %s.stride(), %s.stride(), %s, %s);' % (
                    mat_name, i + 1, j + 1, mat_name, i, x_step, j, y_step, mat_name, mat_name, x_step, y_step))

def read_coeffs(filename):
    ''' Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.  '''
    coeffs = []
    with open(filename, 'r') as coeff_file:
        curr_group = []
        for line in coeff_file:
            if line[0] == '#':
                coeffs.append(curr_group)
                curr_group = []
            else:
                curr_group.append([float(val) for val in line.split()])
    coeffs.append(curr_group)
    # There should be three sets of coefficients: one for each matrix.
    if (len(coeffs) != 3):
        raise Exception('Expected three sets of coefficients!')
    return coeffs

def addition(ind, coeffs, mat_name, mat_dims):
    if num_nonzero(coeffs) > 1:
        tmp_mat = 'M%d%s' % (ind + 1, mat_name)
        write_line(header, 1, 'Matrix<Scalar> %s(%s11.n());' % (
                tmp_mat, mat_name))
        add = 'Add('
        for i, coeff in enumerate(coeffs):
            if coeff != 0:
                add += mat_name + '%d%d, ' % linear2cart(i, mat_dims[0], mat_dims[1])
        for i, coeff in enumerate(coeffs):
            if coeff != 0:
                add += 'Scalar(%g), ' % coeff
        return add + tmp_mat + ');'
    return ''

def num_nonzero(arr):
    ''' Returns number of non-zero entries in the array arr. '''
    return len(filter(lambda x: x != 0, arr))


def linear2cart(ind, rows, cols):
    ''' Given a linear index ind from [0, 1, 2, ..., rows * cols - 1],
    return the corresponding (row, col) index from
    [1, 2, ..., row] x [1, 2, ..., col].
    Ordering of the linear index is assumed to be _row_ major.
    '''
    return ((ind / rows) + 1, (ind % cols) + 1)


def write_matmul(header, ind, a_coeffs, b_coeffs):
    ''' Write a matrix multiplication call.

    header is the file to which we are writing
    ind is which multiplication this is (1, 2, 3, ...)
    a_coeffs are the coefficients for the A matrix
    b_coeffs are the coefficients for the B matrix
    '''
    comment = '// M%d = (' % (ind + 1)
    comment += ' + '.join([str(c) + ' * A%d%d' % linear2cart(i, dims[0], dims[1]) \
                               for i, c in enumerate(a_coeffs) if c != 0])
    comment += ') * ('
    comment += ' + '.join([str(c) + ' * B%d%d' % linear2cart(i, dims[1], dims[2]) \
                               for i, c in enumerate(b_coeffs) if c != 0])
    comment += ')'
    write_line(header, 1, comment)

    # Cilk wrapper (start)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, 'cilk_spawn [&]{')
    write_line(header, 0, '#endif')

    write_line(header, 1, addition(ind, a_coeffs, 'A', (dims[0], dims[1])))
    write_line(header, 1, addition(ind, b_coeffs, 'B', (dims[1], dims[2])))

    def subblock_name(coeffs, mat_name):
        if (num_nonzero(coeffs) > 1):
            name = 'M%d%s' % (ind + 1, mat_name)
        else:
            loc = [i for i, c in enumerate(coeffs) if c != 0]
            name = '%s%d' % (mat_name, loc[0] + 1)
        return name

    write_line(header, 1, 'FastMatmul(%s, %s, M%d, numsteps - 1);' % (
            subblock_name(a_coeffs, 'A'), subblock_name(b_coeffs, 'B'), ind + 1))
    
    if (num_nonzero(a_coeffs) > 1):
        write_line(header, 1, 'M%dA.deallocate();' % (ind + 1))
    if (num_nonzero(b_coeffs) > 1):
        write_line(header, 1, 'M%dB.deallocate();' % (ind + 1))

    # Cilk wrapper (end)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, '}();')
    write_line(header, 0, '#endif\n')

def write_output(header, ind, coeffs, mat_dims):
    add = 'Add('
    for i, coeff in enumerate(coeffs):
        if coeff != 0:
            add += 'M%d, ' % (i + 1)
    for i, coeff in enumerate(coeffs):
        if coeff != 0:
            add += 'Scalar(%g), ' % coeff
    add += 'C%d%d);' % linear2cart(ind, mat_dims[0], mat_dims[1])
    write_line(header, 1, add)
    

outfile = 'output/fast.hpp'
coeffs = read_coeffs('grey-strassen')
dims = (2, 2, 2)
print 'Generating code for %d x %d x %d' % dims

with open(outfile, 'w') as header:
    # header information
    write_line(header, 0, '#ifndef _FAST_HPP_')
    write_line(header, 0, '#define _FAST_HPP_')
    write_line(header, 0, '\n')
    write_line(header, 0, '#include "linalg.hpp"')
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 0, '# include <cilk/cilk.h>')
    write_line(header, 0, '#endif')
    write_line(header, 0, '\n')

    write_line(header, 0, 'template <typename Scalar>')
    write_line(header, 0, 'void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, ' +
                          'Matrix<Scalar>& C, int numsteps) {')
    write_line(header, 1, '// Base case for recursion')
    write_line(header, 1, 'if (numsteps == 0) {')
    write_line(header, 2, 'Gemm(A, B, C);')
    write_line(header, 2, 'return;')
    write_line(header, 1, '}\n')

    # Generate sub-blocks
    write_subblocks(header, 'A', dims[0], dims[1])
    write_subblocks(header, 'B', dims[1], dims[2])
    write_subblocks(header, 'C', dims[0], dims[2])

    num_multiplies = len(coeffs[0][0])
    print '%d matrix multiplications...' % num_multiplies

    # Declaration of all of the intermediate multiplication results.
    write_line(header, 0, '\n')
    write_line(header, 1, '// These are the intermediate matrices.')
    write_line(header, 1, '// We define them here so that they can be used')
    write_line(header, 1, '// inside the lambda functions for Cilk.')
    for i in xrange(num_multiplies):
        write_line(header, 1, 'Matrix<Scalar> M%d(C_x_step, C_y_step);' % (i + 1))
    write_line(header, 0, '\n')

    # Write the mutliplication blocks.
    for i in xrange(num_multiplies):
        a_coeffs = [c[i] for c in coeffs[0]]
        b_coeffs = [c[i] for c in coeffs[1]]
        write_matmul(header, i, a_coeffs, b_coeffs)

    for ind, row in enumerate(coeffs[2]):
        write_output(header, ind, row, (dims[0], dims[2]))
    
    # end of function
    write_line(header, 0, '}\n')

    # end of file
    write_line(header, 0, '#endif  // _FAST_HPP_')
