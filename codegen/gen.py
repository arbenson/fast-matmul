import sys
import subexpr_elim

'''
How to use this program:

  python gen.py coeff_file m,n,p out_file

coeff_file is the path to the coefficients file.
m,n,p are the matrix dimensions:
   multiplying an m x n matrix A by a n x p matrix B and storing in a m x p matrix C
out_file is the name of the output file

Suppose there are R matrix multiplications in the subproblem.
Let alpha_{ij}_r and be the coefficients for submatrix A_{ij} in the r-th
matrix multiplication, i = 1, ..., m, j = 1, ..., n, r = 1, ..., R.
Similarly, let beta_{ij}_r and be the coefficients for submatrix B_{ij} in the r-th
matrix multiplication, i = 1, ..., n, j = 1, ..., p, r = 1, ..., R.
Finally, let gamma_{ij}_r be the coefficients for r-th matrix multiplication in C_{ij}.
The file format for m = n = p = 2 with r = 7 is:

alpha_{11}_1 alpha_{11}_2 alpha_{11}_3 alpha_{11}_4 alpha_{11}_5 alpha_{11}_6 alpha_{11}_7
alpha_{12}_1 alpha_{12}_2 alpha_{12}_3 alpha_{12}_4 alpha_{12}_5 alpha_{12}_6 alpha_{12}_7
alpha_{21}_1 alpha_{21}_2 alpha_{21}_3 alpha_{21}_4 alpha_{21}_5 alpha_{21}_6 alpha_{21}_7
alpha_{22}_1 alpha_{22}_2 alpha_{22}_3 alpha_{22}_4 alpha_{22}_5 alpha_{22}_6 alpha_{22}_7
#
beta_{11}_1 beta_{11}_2 beta_{11}_3 beta_{11}_4 beta_{11}_5 beta_{11}_6 beta_{11}_7
beta_{12}_1 beta_{12}_2 beta_{12}_3 beta_{12}_4 beta_{12}_5 beta_{12}_6 beta_{12}_7
beta_{21}_1 beta_{21}_2 beta_{21}_3 beta_{21}_4 beta_{21}_5 beta_{21}_6 beta_{21}_7
beta_{22}_1 beta_{22}_2 beta_{22}_3 beta_{22}_4 beta_{22}_5 beta_{22}_6 beta_{22}_7
#
gamma_{11}_1 gamma_{11}_2 gamma_{11}_3 gamma_{11}_4 gamma_{11}_5 gamma_{11}_6 gamma_{11}_7
gamma_{12}_1 gamma_{12}_2 gamma_{12}_3 gamma_{12}_4 gamma_{12}_5 gamma_{12}_6 gamma_{12}_7
gamma_{21}_1 gamma_{21}_2 gamma_{21}_3 gamma_{21}_4 gamma_{21}_5 gamma_{21}_6 gamma_{21}_7
gamma_{22}_1 gamma_{22}_2 gamma_{22}_3 gamma_{22}_4 gamma_{22}_5 gamma_{22}_6 gamma_{22}_7

The coefficients are listed in row-major order.
See the file 'strassen' for an example.
'''

def parse_coeff(coeff):
    ''' Parse a coefficient. The grammar is:
        
        * --> *i | -* | *p | [a-z] | [floating point number]
        p --> 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
        *i --> 1 / (*)
        -* --> -(*)
        *p --> (*)^p

        So -x2i is parsed as - (1 / ((x)^2))
    '''
    coeff = coeff.strip()
    # First try to convert to float
    try:
        coeff = float(coeff)
        return coeff
    except:
        pass
    
    # Parameterized coefficient
    if len(coeff) == 1:
        # Coeff is like 'x'.  We will use 'x' instead of whatever is provided.
        # For now, this means that we only support one paramterized coefficient.
        return 'x'
    elif coeff[0] == '-':
        return '-(%s)' % parse_coeff(coeff[1:])
    elif coeff[-1] == 'i':
        return '1.0 / (%s)' % parse_coeff(coeff[:-1])
    else:
        try:
            exp = float(coeff[-1])
            return ('(%s)' % parse_coeff(coeff[:-1])) * exp
        except:
            raise Exception('Cannot parse coefficient: %s' % coeff)


def read_coeffs(filename):
    ''' Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.  '''
    coeffs = []
    with open(filename, 'r') as coeff_file:
        curr_group = []
        for line in coeff_file:
            if line[0] == '#':
                if len(curr_group) > 0:
                    coeffs.append(curr_group)
                    curr_group = []
            else:
                curr_group.append([parse_coeff(val) for val in line.split()])
    coeffs.append(curr_group)
    # There should be three sets of coefficients: one for each matrix.
    if (len(coeffs) < 3):
        raise Exception('Expected three sets of coefficients!')
    return coeffs


def write_line(header, num_indent, code):
    ''' Write the line of code with num_indent number of indents. '''
    header.write(' ' * 4 * num_indent + code + '\n')


def write_subblocks(header, mat_name, dim1, dim2):
    ''' Write subblocks of matrix of dimensions dim1 x dim2.
    mat_name is the name of the matrix, e.g., 'A' or 'B'
    header is file to write to.
    '''
    for i in xrange(dim1):
        for j in xrange(dim2):
            write_line(header, 1, 'Matrix<Scalar> %s%d%d = %s.Subblock(%d, %d, %d, %d);' %
                       (mat_name, i + 1, j + 1, mat_name, dim1, dim2, i + 1, j + 1))



def is_nonzero(x):
    return x != 0 and x != '0'


def num_nonzero(arr):
    ''' Returns number of non-zero entries in the array arr. '''
    return len(filter(is_nonzero, arr))


def need_tmp_mat(coeffs):
    return num_nonzero(coeffs) > 1


def linear2cart(ind, cols):
    ''' Given a linear index ind from [0, 1, 2, ..., rows * cols - 1],
    return the corresponding (row, col) index from
    [1, 2, ..., row] x [1, 2, ..., col].
    Ordering of the linear index is assumed to be _row_ major.
    '''
    return ((ind / cols) + 1, (ind % cols) + 1)


def get_suffix(ind, num_rows, num_cols):
    ''' Get the suffix for a matrix subblock.
    ind is the number of the matrix subblock (the row in the U or V matrix)
    num_rows and num_cols are the number of rows and columns in the originial
                         matrix where the subblock lives
    '''
    if ind < num_rows * num_cols:
        return '%d%d' % linear2cart(ind, num_cols)
    else:
        # These correspond to matrices formed by subexpression elimination.
        return '_X%d' % (ind - num_rows * num_cols + 1)


def streaming_additions(header, coeff_set, mat_name, tmp_name, num_rows, num_cols):
    num_subblocks = len(coeff_set)

    def tmp_mat_name(i):
        return tmp_name + str(i + 1)

    def subblock_name(i):
        return mat_name + get_suffix(i, num_rows, num_cols)

    def stride_call(name):
        return  'const int stride%s = %s.stride();' % (name, name)

    def data_call(name):
        return 'Scalar *data%s = %s.data();' % (name, name)

    # All of the strides for the matrix subblocks
    for i in range(num_subblocks):
        subblock = subblock_name(i)
        write_line(header, 1, stride_call(subblock))
        write_line(header, 1, data_call(subblock))

    # Data for the temporary matrices
    for i, col in enumerate(subexpr_elim.transpose(coeff_set)):
        if need_tmp_mat(col):
            tmp_mat = tmp_mat_name(i)
            instantiate = 'Matrix<Scalar> %s(%s11.m(), %s11.n());' % (tmp_mat, mat_name, mat_name)
            write_line(header, 1, instantiate)
            write_line(header, 1, stride_call(tmp_mat))
            write_line(header, 1, data_call(tmp_mat))

    write_line(header, 1, '#ifdef _OPEN_MP_ADDS_')
    write_line(header, 1, '# pragma omp parallel for collapse(2)')
    write_line(header, 1, '#endif')
    write_line(header, 1, 'for (int j = 0; j < %s11.n(); ++j) {' % mat_name)
    write_line(header, 2, 'for (int i = 0; i < %s11.m(); ++i) {' % mat_name)

    def arr_access(name):
        return 'data%s[i + j * stride%s]' % (name, name)

    for i, col in enumerate(subexpr_elim.transpose(coeff_set)):
        if need_tmp_mat(col):
            add = '%s = ' % arr_access(tmp_mat_name(i))
            lhs_adds = []
            for ind, coeff in enumerate(col):
                if is_nonzero(coeff):
                    name = subblock_name(ind)
                    lhs_adds.append('Scalar(%s) * %s' % (coeff, arr_access(name)))
            
            add += ' + '.join(lhs_adds) + ';'
            write_line(header, 3, add)

    write_line(header, 2, '}')  # end i loop
    write_line(header, 1, '}')  # end j loop


def streaming_output_additions(header, coeff_set, mat_name, tmp_name, num_rows, num_cols):
    num_subblocks = len(coeff_set)

    def tmp_mat_name(i):
        return tmp_name + str(i + 1)

    def subblock_name(i):
        return mat_name + get_suffix(i, num_rows, num_cols)

    def stride_call(name):
        return  'const int stride%s = %s.stride();' % (name, name)

    def data_call(name):
        return 'Scalar *data%s = %s.data();' % (name, name)

    # All of the strides for the matrix subblocks
    for i in range(num_subblocks):
        subblock = subblock_name(i)
        write_line(header, 1, stride_call(subblock))
        write_line(header, 1, data_call(subblock))

    for i in range(len(coeff_set[0])):
            tmp_mat = 'M%d' % (i + 1)
            write_line(header, 1, stride_call(tmp_mat))
            write_line(header, 1, data_call(tmp_mat))

    write_line(header, 1, '#ifdef _OPEN_MP_ADDS_')
    write_line(header, 1, '# pragma omp parallel for collapse(2)')
    write_line(header, 1, '#endif')
    write_line(header, 1, 'for (int j = 0; j < %s11.n(); ++j) {' % mat_name)
    write_line(header, 2, 'for (int i = 0; i < %s11.m(); ++i) {' % mat_name)

    def arr_access(name):
        return 'data%s[i + j * stride%s]' % (name, name)

    for i, col in enumerate(coeff_set):
        if need_tmp_mat(col):
            add = '%s = ' % arr_access(subblock_name(i))
            lhs_adds = []
            for ind, coeff in enumerate(col):
                if is_nonzero(coeff):
                    name = tmp_mat_name(ind)
                    lhs_adds.append('Scalar(%s) * %s' % (coeff, arr_access(name)))
            
            add += ' + '.join(lhs_adds) + ';'
            write_line(header, 3, add)

    write_line(header, 2, '}')  # end i loop
    write_line(header, 1, '}')  # end j loop


def addition(header, tmp_mat, mat_name, mat_dims, coeffs, limited_memory=False):
    if not limited_memory:
        write_line(header, 1, 'Matrix<Scalar> %s(%s11.m(), %s11.n());' % (
                tmp_mat, mat_name, mat_name))
    add = 'Add('
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += mat_name + '%s, ' % get_suffix(i, mat_dims[0], mat_dims[1])
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += 'Scalar(%s), ' % coeff
    return add + tmp_mat + ');'


def write_matmul(header, ind, a_coeffs, b_coeffs, dims, streaming_adds=False, c_coeffs=None):
    ''' Write a matrix multiplication call.

    header is the file to which we are writing
    ind is which multiplication this is (1, 2, 3, ...)
    a_coeffs are the coefficients for the A matrix
    b_coeffs are the coefficients for the B matrix
    dims is a 3-tuple of the dimensions of the algorithm (m, k, n)
    streaming_adds is a boolean indicated whether or not we are using streaming
                   additions
    c_coeffs is the set of coefficients describing how the temporary M matrix
             updates the output solution.  This is used for the limited memory version.
             If c_coeffs is None, then no updates are made(i.e., the updates will be
             made at the end).  If c_coeffs is not None, then the M matrix will be
             re-used.
    '''
    limited_memory = (c_coeffs != None)
    comment = '// M%d = (' % (ind + 1)
    comment += ' + '.join([str(c) + ' * A%s' % get_suffix(i, dims[0], dims[1]) \
                               for i, c in enumerate(a_coeffs) if is_nonzero(c)])
    comment += ') * ('
    comment += ' + '.join([str(c) + ' * B%s' % get_suffix(i, dims[1], dims[2]) \
                               for i, c in enumerate(b_coeffs) if is_nonzero(c)])
    comment += ')'
    write_line(header, 1, comment)

    # Shared memory wrappers (start)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, 'cilk_spawn [&] {')
    write_line(header, 0, '#elif defined _OPEN_MP_')
    write_line(header, 0, '# pragma omp task')
    write_line(header, 1, '{')
    write_line(header, 0, '#endif')

    def addition_str(ind, coeffs, mat_name, tmp_name, mat_dims):
        if need_tmp_mat(coeffs):
            tmp_mat = '%s%d' % (tmp_name, ind + 1)
            if limited_memory:
                tmp_mat = tmp_name
            return addition(header, tmp_mat, mat_name, mat_dims, coeffs, limited_memory)
        return None

    if not streaming_adds:
        add = addition_str(ind, a_coeffs, 'A', 'S', (dims[0], dims[1]))
        if add != None:
            write_line(header, 1, add)
        
        add = addition_str(ind, b_coeffs, 'B', 'T', (dims[1], dims[2]))
        if add != None:
            write_line(header, 1, add)

    def subblock_name(coeffs, mat_name, tmp_name, mat_dims):
        if need_tmp_mat(coeffs):
            if limited_memory:
                return tmp_name
            return '%s%d' % (tmp_name, ind + 1)
        else:
            loc = [i for i, c in enumerate(coeffs) if is_nonzero(c)]
            return mat_name + get_suffix(loc[0], mat_dims[0], mat_dims[1])

    res_mat = 'M%d' % (ind + 1)
    if limited_memory:
        res_mat = 'M'

    # Handle the case where there is one non-zero coefficient and it is
    # not equal to one.  We need to propagate the multiplier information.
    a_nonzero_coeffs = filter(is_nonzero, a_coeffs)
    b_nonzero_coeffs = filter(is_nonzero, b_coeffs)
    if len(a_nonzero_coeffs) == 1 and a_nonzero_coeffs[0] != 1:
        write_line(header, 1, '%s.UpdateMultiplier(Scalar(%d));' % (res_mat, a_nonzero_coeffs[0]))

    if len(b_nonzero_coeffs) == 1 and b_nonzero_coeffs[0] != 1:
        write_line(header, 1, '%s.UpdateMultiplier(Scalar(%d));' % (res_mat, b_nonzero_coeffs[0]))


    # Finally, write the actual call to matrix multiply.
    write_line(header, 1, 'FastMatmulRecursive(%s, %s, %s, numsteps - 1, x);' % (
            subblock_name(a_coeffs, 'A', 'S', (dims[0], dims[1])),
            subblock_name(b_coeffs, 'B', 'T', (dims[1], dims[2])),
            res_mat))
    
    if need_tmp_mat(a_coeffs) and not limited_memory:
        write_line(header, 1, 'S%d.deallocate();' % (ind + 1))
    if need_tmp_mat(b_coeffs) and not limited_memory:
        write_line(header, 1, 'T%d.deallocate();' % (ind + 1))

    if limited_memory:
        for i, coeff in enumerate(c_coeffs):
            if is_nonzero(coeff):
                out_block = 'C%s' % get_suffix(i, dims[0], dims[2])
                write_line(header, 1, 'UpdateAddDaxpy(M, Scalar(%d), %s);' % (coeff, out_block))
    

    # Shared memory wrappers (end)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, '}();')
    write_line(header, 0, '#elif defined _OPEN_MP_')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif\n')


def write_substitutions(header, mat_name, mat_dims, coeffs):
    # If it is empty, skip it
    if len(coeffs) == 0 or len(coeffs[0]) == 0:
        return

    write_line(header, 1, '\n')
    for i, coeff_line in enumerate(coeffs):
        tmp_mat_name = '%s_X%d' % (mat_name, i + 1)
        write_line(header, 1,
                   addition(header, tmp_mat_name, mat_name, mat_dims, coeff_line))



def output_addition(output_mat, coeffs, mat_dims, rank):
    add = 'Add('
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            suffix = i + 1
            if suffix > rank:
                suffix = '_X%d' % (suffix - rank)
            add += 'M%s, ' % suffix
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += 'Scalar(%s), ' % coeff
    return add + '%s);' % output_mat


def write_output_sub(header, ind, coeffs, mat_dims, rank):
    if len(coeffs) == 0:
        return
    tmp_mat = 'M_X%d' % (ind + 1)
    write_line(header, 1, 'Matrix<Scalar> %s(C11.m(), C11.n());' % tmp_mat)
    add = output_addition(tmp_mat, coeffs, mat_dims, rank)
    write_line(header, 1, add)


def write_output(header, ind, coeffs, mat_dims, rank):
    add = output_addition('C%s' % get_suffix(ind, mat_dims[0], mat_dims[1]), coeffs, mat_dims, rank)
    write_line(header, 1, add)


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
        outfile = 'output/fast.hpp'
        if len(sys.argv) > 3:
            outfile = sys.argv[3]

        streaming_adds = False
        if len(sys.argv) > 4:
            streaming_adds = int(sys.argv[4])
        limited_memory = False
        if len(sys.argv) > 5:
            limited_memory = int(sys.argv[5])

        print 'Generating code for %d x %d x %d' % dims
    except:
        raise Exception('USAGE: python gen.py coeff_file m,n,p out_file')

    coeffs = read_coeffs(sys.argv[1])
    # Create a namespace name from the file name
    namespace_name = coeff_file.split('.')[0]
    namespace_name = namespace_name.replace('-', '_')
    namespace_name = namespace_name.split('/')[-1]

    with open(outfile, 'w') as header:
        # header information
        write_line(header, 0, '#ifndef _%s_HPP_' % namespace_name)
        write_line(header, 0, '#define _%s_HPP_' % namespace_name)
        write_line(header, 0, '\n')
        write_line(header, 0, '// This is an automatically generated file from gen.py.')
        write_line(header, 0, '#include "common.hpp"')
        write_line(header, 0, '\n')

        # Wrap in a namespace
        write_line(header, 0, 'namespace %s {\n' % namespace_name)

        # Start of fast matrix multiplication function
        write_line(header, 0, 'template <typename Scalar>')
        write_line(header, 0, 'void FastMatmulRecursive(Matrix<Scalar>& A, Matrix<Scalar>& B, ' +
                   'Matrix<Scalar>& C, int numsteps, double x=1e-8) {')
        if limited_memory:
            # TODO: There are more efficient ways to handle zero-ing out C.
            # For example, we could just overwrite C the first time we add to it.
            write_line(header, 1, 'ZeroOut(C);')

        # Handle the multipliers
        write_line(header, 1, '// Update multipliers')
        write_line(header, 1, 'C.UpdateMultiplier(A.multiplier());')
        write_line(header, 1, 'C.UpdateMultiplier(B.multiplier());')
        write_line(header, 1, 'A.set_multiplier(Scalar(1.0));')
        write_line(header, 1, 'B.set_multiplier(Scalar(1.0));')

        # Handle base case
        write_line(header, 1, '// Base case for recursion')
        write_line(header, 1, 'if (numsteps == 0) {')
        write_line(header, 2, 'Gemm(A, B, C);')
        write_line(header, 2, 'return;')
        write_line(header, 1, '}\n')
        
        # Generate sub-blocks
        write_subblocks(header, 'A', dims[0], dims[1])
        write_subblocks(header, 'B', dims[1], dims[2])
        write_subblocks(header, 'C', dims[0], dims[2])

        if streaming_adds:
            write_line(header, 0, '\n')
            streaming_additions(header, coeffs[0], 'A', 'S', dims[0], dims[1])
            write_line(header, 0, '\n')
            streaming_additions(header, coeffs[1], 'B', 'T', dims[1], dims[2])
    
        # Generate substitution matrices
        if len(coeffs) > 3:
            write_substitutions(header, 'A', (dims[0], dims[1]), coeffs[3])
            write_substitutions(header, 'B', (dims[1], dims[2]), coeffs[4])
        
        num_multiplies = len(coeffs[0][0])
        print '%d matrix multiplications...' % num_multiplies

        # Declaration of all of the intermediate multiplication results.
        if limited_memory:
            write_line(header, 1, 'Matrix<Scalar> M(C11.m(), C11.n(), C.multiplier());')
            write_line(header, 1, 'Matrix<Scalar> S(A11.m(), A11.n());')
            write_line(header, 1, 'Matrix<Scalar> T(B11.m(), B11.n());')
        else:
            write_line(header, 0, '\n')
            write_line(header, 1, '// These are the intermediate matrices.')
            write_line(header, 1, '// We define them here so that they can be used')
            write_line(header, 1, '// inside the lambda functions for Cilk.')
            
            for i in xrange(num_multiplies):
                write_line(header, 1, 'Matrix<Scalar> M%d(C11.m(), C11.n(), C.multiplier());' % (i + 1))
            write_line(header, 0, '\n')

        # Write the mutliplication blocks.
        for i in xrange(num_multiplies):
            a_coeffs = [c[i] for c in coeffs[0]]
            b_coeffs = [c[i] for c in coeffs[1]]
            c_coeffs = None
            if limited_memory:
                c_coeffs = [c[i] for c in coeffs[2]]
            write_matmul(header, i, a_coeffs, b_coeffs, dims, streaming_adds=streaming_adds, c_coeffs=c_coeffs)

        write_line(header, 0, '#ifdef _CILK_')
        write_line(header, 1, 'cilk_sync;')
        write_line(header, 0, '#elif defined _OPEN_MP_')
        write_line(header, 2, '# pragma omp taskwait')
        write_line(header, 0, '#endif')


        if not limited_memory:
            # In the limited memory  case, we have already completed the updates
            # to the output matrix
            if len(coeffs) >= 6:
                for ind, row in enumerate(coeffs[5]):
                    write_output_sub(header, ind, row, (dims[0], dims[2]), num_multiplies)
                    write_line(header, 0, '\n')

            if streaming_adds:
                write_line(header, 0, '\n')
                streaming_output_additions(header, coeffs[2], 'C', 'M', dims[0], dims[2])
            else:
                for ind, row in enumerate(coeffs[2]):
                    write_output(header, ind, row, (dims[0], dims[2]), num_multiplies)

        write_line(header, 0, '\n')
        write_line(header, 1, '// Handle edge cases with dynamic peeling')
        write_line(header, 1, 'DynamicPeeling(A, B, C, %d, %d, %d);' % dims)

        # end of function
        write_line(header, 0, '}\n')

        # Wrapper to deal with OpenMP
        write_line(header, 0, 'template <typename Scalar>')
        write_line(header, 0, 'void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, ' +
                   'Matrix<Scalar>& C, int numsteps, double x=1e-8) {')
        write_line(header, 0, '#ifdef _OPEN_MP_')
        write_line(header, 0, '# pragma omp parallel')
        write_line(header, 1, '{')
        write_line(header, 0, '# pragma omp single')
        write_line(header, 0, '#endif')
	write_line(header, 2, 'FastMatmulRecursive(A, B, C, numsteps, x);')
        write_line(header, 0, '#ifdef _OPEN_MP_')
        write_line(header, 1, '}')
        write_line(header, 0, '#endif')
        write_line(header, 0, '}\n')

        # end of namespace
        write_line(header, 0, '}  // namespace %s\n' % namespace_name)
        # end of file
        write_line(header, 0, '#endif  // _%s_HPP_' % namespace_name)

if __name__ == '__main__':
    main()
