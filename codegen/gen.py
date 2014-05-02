def write_line(header, num_indent, code):
    '''
    Write the line of code with num_indent number of indents.
    '''
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
            write_line(header, 1, 'Matrix<Scalar> %s%d%d(A.data() + %d * %s + %d * %s * A.stride(), A.stride(), %s, %s);' % (
                    mat_name, i + 1, j + 1, i, x_step, j, y_step, x_step, y_step))

def read_coeffs(filename):
    '''
    Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.
    '''
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

def write_matmul(header, ind, a_coeffs, b_coeffs):
    '''
    header is the file to which we are writing
    ind is which multiplication this is (1, 2, 3, ...)
    a_coeffs are the coefficients for the A matrix
    b_coeffs are the coefficients for the B matrix
    '''

    comment = '// M%d = ( ' % (ind + 1)
    comment += ' + '.join(['%d * A%d' % (c, i + 1) for i, c in enumerate(a_coeffs) if c != 0])
    comment += ') * ( '
    comment += ' + '.join(['%d * B%d' % (c, i + 1) for i, c in enumerate(b_coeffs) if c != 0])
    comment += ')'
    write_line(header, 1, comment)

    # Cilk wrapper (start)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, 'cilk_spawn [&]{')
    write_line(header, 0, '#endif')

    def num_nonzero(arr):
        ''' Returns number of non-zero entries in the array arr. '''
        return len(filter(lambda x: x != 0, arr))

    def write_addition(coeffs, mat_name):
        if num_nonzero(coeffs) > 1:
            write_line(header, 1, 'Matrix<Scalar> M%d%s(%s11.n());' % (
                    ind + 1, mat_name, mat_name))
        '''
        Add(B11, B21, B31, NegOne, NegOne, One, M1B);
        '''

    write_addition(a_coeffs, 'A')
    write_addition(b_coeffs, 'B')

    def subblock_name(coeffs, mat_name):
        if (num_nonzero(coeffs) > 1):
            name = 'M%d%s' % (ind, mat_name)
        else:
            loc = [i for i, c in enumerate(coeffs) if c != 0]
            name = '%s%d' % (mat_name, loc[0] + 1)
        return name

    write_line(header, 1, 'FastMatmul(%s, %s, M%d, numsteps - 1);' % (
            subblock_name(a_coeffs, 'A'), subblock_name(b_coeffs, 'B'), ind))
    
    if (num_nonzero(a_coeffs) > 1):
        write_line(header, 1, 'M%dA.deallocate();' % ind)
    if (num_nonzero(b_coeffs) > 1):
        write_line(header, 1, 'M%dB.deallocate();' % ind)

    # Cilk wrapper (end)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, '}();')
    write_line(header, 0, '#endif\n')

outfile = 'output/fast.hpp'
coeffs = read_coeffs('grey-strassen')
dims = (2, 2, 2)

with open(outfile, 'w') as header:
    write_line(header, 0, 'template <typename Scalar>')
    write_line(header, 0, 'void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps) {')
    write_line(header, 1, '// Base case for recursion')
    write_line(header, 1, 'if (numsteps == 0) {')
    write_line(header, 2, 'Gemm(A, B, C);')
    write_line(header, 2, 'return;')
    write_line(header, 1, '}')

    # Generate sub-blocks
    write_subblocks(header, 'A', dims[0], dims[1])
    write_subblocks(header, 'B', dims[1], dims[2])
    write_subblocks(header, 'C', dims[0], dims[2])

    # Scalars needed for multiplications.
    write_line(header, 0, '\n')
    write_line(header, 1, 'Scalar NegOne = Scalar(-1);')
    write_line(header, 1, 'Scalar One = Scalar(1);')
    write_line(header, 0, '\n')

    num_multiplies = len(coeffs[0][0])
    for i in xrange(num_multiplies):
        a_coeffs = [c[i] for c in coeffs[0]]
        b_coeffs = [c[i] for c in coeffs[1]]
        write_matmul(header, i, a_coeffs, b_coeffs)

    
    # end of function
    write_line(header, 0, '}\n')
