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

def is_one(x):
    return x == 1 or x == 1.0 or x == '1' or x == '1.0'


def is_negone(x):
    return x == -1 or x == -1.0 or x == '-1' or x == '-1.0'


def is_nonzero(x):
    return x != 0 and x != '0'


def num_nonzero(arr):
    ''' Returns number of non-zero entries in the array arr. '''
    return len(filter(is_nonzero, arr))


def need_tmp_mat(coeffs):
    return num_nonzero(coeffs) > 1


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


def write_break(header, num_breaks=1):
    header.write('\n' * num_breaks)


def write_subblocks(header, mat_name, dim1, dim2):
    ''' Write subblocks of matrix of dimensions dim1 x dim2.
    mat_name is the name of the matrix, e.g., 'A' or 'B'
    header is file to write to.
    '''
    for i in xrange(dim1):
        for j in xrange(dim2):
            write_line(header, 1, 'Matrix<Scalar> %s%d%d = %s.Subblock(%d, %d, %d, %d);' %
                       (mat_name, i + 1, j + 1, mat_name, dim1, dim2, i + 1, j + 1))


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


def write_output_add(header, index, coeffs, mat_dims, rank):
    add = 'M_Add%d(' % (index)
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            suffix = i + 1
            if suffix > rank:
                suffix = '_X%d' % (suffix - rank)
            add += 'M%s, ' % suffix
    output_mat = 'C' + get_suffix(index - 1, mat_dims[0], mat_dims[1])
    add += '%s, x);' % output_mat
    write_line(header, 1, add)


def write_add_func(header, coeffs, index, mat_name):
    ''' Write the add function for a set of coefficients.  This is a custom add
    function used for a single multiply in a single fast algorithm.

    coeffs is the set of coefficients used for the add
    '''
    nonzero_coeffs = [coeff for coeff in coeffs if is_nonzero(coeff)]
    nnz = len(nonzero_coeffs)
    # TODO(arbenson): put in a comment here
    write_line(header, 0, 'template <typename Scalar>')
    add = 'void %s_Add%d(' % (mat_name, index)
    add += ', '.join(['Matrix<Scalar>& %s%d' % (mat_name, i + 1) for i in range(nnz)])
    add += ', Matrix<Scalar>& C, double x=1e-8) {'
    write_line(header, 0, add)

    # All of the strides
    for i in range(nnz):
        write_line(header, 1, 'const int stride%s%d = %s%d.stride();' % (mat_name, i + 1, mat_name, i + 1))
    write_line(header, 1, 'const int strideC = C.stride();')

    # All of the data pointers
    for i in range(nnz):
        write_line(header, 1, 'const Scalar *data%s%d = %s%d.data();' % (mat_name, i + 1, mat_name, i + 1))
    write_line(header, 1, 'Scalar *dataC = C.data();')

    write_line(header, 1, 'for (int j = 0; j < C.n(); ++j) {')
    write_line(header, 2, 'for (int i = 0; i < C.m(); ++i) {')
    add = 'dataC[i + j * strideC] ='
    for i, coeff in enumerate(nonzero_coeffs):
        ind = i + 1
        if is_one(coeff):
            str = ' data%s%d[i + j * stride%s%d]' % (mat_name, ind, mat_name, ind)
        elif is_negone(coeff):
            str = ' -data%s%d[i + j * stride%s%d]' % (mat_name, ind, mat_name, ind)
        else:
            str = ' Scalar(%s) * data%s%d[i + j * stride%s%d]' % (coeff, mat_name, ind, mat_name, ind)
        if i != 0 and not is_negone(coeff):
            str  = ' +' + str

        add += str
    
    add += ';'
    write_line(header, 3,add)
    write_line(header, 2, '}')
    write_line(header, 1, '}')
    write_line(header, 0, '}')


def write_multiply(header, index, a_coeffs, b_coeffs, dims):
    comment = '// M%d = (' % (index)
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

    def addition_str(coeffs, mat_name, tmp_name, mat_dims):
        tmp_mat = '%s%d' % (tmp_name, index)
        add = '%s_Add%d(' % (tmp_name, index)
        for i, coeff in enumerate(coeffs):
            if is_nonzero(coeff):
                add += mat_name + '%s, ' % get_suffix(i, mat_dims[0], mat_dims[1])
        return add + tmp_mat + ', x);'

    # Write the adds to temps if necessary
    if need_tmp_mat(a_coeffs):
        write_line(header, 1, 'Matrix<Scalar> S%d(A11.m(), A11.n());' % (index))
        write_line(header, 1, addition_str(a_coeffs, 'A', 'S', (dims[0], dims[1])))
    if need_tmp_mat(b_coeffs):
        write_line(header, 1, 'Matrix<Scalar> T%d(B11.m(), B11.n());' % (index))
        write_line(header, 1, addition_str(b_coeffs, 'B', 'T', (dims[1], dims[2])))

    res_mat = 'M%d' % (index)

    # Handle the case where there is one non-zero coefficient and it is
    # not equal to one.  We need to propagate the multiplier information.
    a_nonzero_coeffs = filter(is_nonzero, a_coeffs)
    b_nonzero_coeffs = filter(is_nonzero, b_coeffs)
    if len(a_nonzero_coeffs) == 1 and a_nonzero_coeffs[0] != 1:
        write_line(header, 1, '%s.UpdateMultiplier(Scalar(%d));' % (res_mat, a_nonzero_coeffs[0]))

    if len(b_nonzero_coeffs) == 1 and b_nonzero_coeffs[0] != 1:
        write_line(header, 1, '%s.UpdateMultiplier(Scalar(%d));' % (res_mat, b_nonzero_coeffs[0]))

    def subblock_name(coeffs, mat_name, tmp_name, mat_dims):
        if need_tmp_mat(coeffs):
            return '%s%d' % (tmp_name, index)
        else:
            loc = [i for i, c in enumerate(coeffs) if is_nonzero(c)]
            return mat_name + get_suffix(loc[0], mat_dims[0], mat_dims[1])

    # Finally, write the actual call to matrix multiply.
    write_line(header, 1, 'FastMatmulRecursive(%s, %s, %s, numsteps - 1, x);' % (
            subblock_name(a_coeffs, 'A', 'S', (dims[0], dims[1])),
            subblock_name(b_coeffs, 'B', 'T', (dims[1], dims[2])),
            res_mat))
    
    if need_tmp_mat(a_coeffs):
        write_line(header, 1, 'S%d.deallocate();' % (index))
    if need_tmp_mat(b_coeffs):
        write_line(header, 1, 'T%d.deallocate();' % (index))

    # Shared memory wrappers (end)
    write_line(header, 0, '#ifdef _CILK_')
    write_line(header, 1, '}();')
    write_line(header, 0, '#elif defined _OPEN_MP_')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif\n')


def create_add_functions(header, coeffs):
    ''' Generate all of the custom add functions.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    '''
    
    def all_adds(coeffs, name):
        for i, coeff_set in enumerate(coeffs):
            if len(coeff_set) > 0:
                write_add_func(header, coeff_set, i + 1, name)
                write_break(header)

    # S matrices formed from A subblocks
    all_adds(subexpr_elim.transpose(coeffs[0]), 'S')

    # T matrices formed from B subblocks
    all_adds(subexpr_elim.transpose(coeffs[1]), 'T')

    # Output C formed from multiplications
    all_adds(coeffs[2], 'M')

    # If there was CSE, create more add functions for the temporary matrices.
    if len(coeffs) > 3:
        all_adds(coeffs[3], 'SX')

    if len(coeffs) > 4:
        all_adds(coeffs[4], 'TX')

    if len(coeffs) > 5:
        all_adds(coeffs[5], 'MX')


def create_multiplications(header, coeffs, dims):
    ''' Generate all of the recursive multiplication calls.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple (m, k, n) of the dimensions of the problem
    '''

    for i in xrange(len(coeffs[0][0])):
        a_coeffs = [c[i] for c in coeffs[0]]
        b_coeffs = [c[i] for c in coeffs[1]]
        write_multiply(header, i + 1, a_coeffs, b_coeffs, dims)


def write_input_cse_sub(header, coeffs, index, mat_name, add_name, mat_dims):
    # If it is empty, skip it
    if len(coeffs) == 0:
        return

    tmp_mat_name = '%s_X%d' % (mat_name, index)
    write_line(header, 1, 'Matrix<Scalar> %s(%s11.m(), %s11.n());' % (tmp_mat_name, mat_name, mat_name))
    add = '%s%d(' % (add_name, index)
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += '%s%s, ' % (mat_name, get_suffix(i, mat_dims[0], mat_dims[1]))
    add += tmp_mat_name + ');'
    write_line(header, 1, add)


def write_output_cse_sub(header, coeffs, index, mat_name, add_name, mat_dims):
    # If it is empty, skip it
    if len(coeffs) == 0 or num_nonzero(coeffs) == 0:
        return

    tmp_mat_name = '%s_X%d' % (mat_name, index)
    write_line(header, 1, 'Matrix<Scalar> %s(%s1.m(), %s1.n());' % (tmp_mat_name, mat_name, mat_name))
    add = '%s%d(' % (add_name, index)
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += '%s%d, ' % (mat_name, i + 1)
    add += tmp_mat_name + ');'
    write_line(header, 1, add)


def create_input_cse_subs(header, coeffs, dims):
    ''' Generate all of the substitutions for CSE for S and T matrices.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple of the algorithm dimensions (m, k, n)
    '''
    if len(coeffs) > 3:
        for i, coeff_line in enumerate(coeffs[3]):
            write_input_cse_sub(header, coeff_line, i + 1, 'A', 'SX_Add', (dims[0], dims[1]))

    write_break(header)
    if len(coeffs) > 4:
        for i, coeff_line in enumerate(coeffs[4]):
            write_input_cse_sub(header, coeff_line, i + 1, 'B', 'TX_Add', (dims[1], dims[2]))

    write_break(header)


def create_output_cse_subs(header, coeffs, dims):
    ''' Generate all of the substitutions for CSE for M matrices.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple of the algorithm dimensions (m, k, n)
    '''
    if len(coeffs) > 5:
        for i, coeff_line in enumerate(coeffs[5]):
            write_output_cse_sub(header, coeff_line, i + 1, 'M', 'MX_Add', (dims[0], dims[2]))


def create_output(header, coeffs, dims):
    # TODO: remove streaming_adds
    streaming_adds = False
    num_multiplies = len(coeffs[0][0])
            
    if streaming_adds:
        write_break(header)
        streaming_output_additions(header, coeffs[2], 'C', 'M', dims[0], dims[2])
    else:
        for i, row in enumerate(coeffs[2]):
            write_output_add(header, i + 1, row, (dims[0], dims[2]), num_multiplies)


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
        write_break(header)
        write_line(header, 0, '// This is an automatically generated file from gen.py.')
        write_line(header, 0, '#include "common.hpp"')
        write_break(header)

        # Wrap in a namespace
        write_line(header, 0, 'namespace %s {\n' % namespace_name)

        create_add_functions(header, coeffs)

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
        write_break(header)

        if streaming_adds:
            write_break(header)
            streaming_additions(header, coeffs[0], 'A', 'S', dims[0], dims[1])
            write_break(header)
            streaming_additions(header, coeffs[1], 'B', 'T', dims[1], dims[2])
    

        num_multiplies = len(coeffs[0][0])
        print '%d matrix multiplications...' % num_multiplies

        # Declaration of all of the intermediate multiplication results.
        if limited_memory:
            write_line(header, 1, 'Matrix<Scalar> M(C11.m(), C11.n(), C.multiplier());')
            write_line(header, 1, 'Matrix<Scalar> S(A11.m(), A11.n());')
            write_line(header, 1, 'Matrix<Scalar> T(B11.m(), B11.n());')
        else:
            write_break(header)
            write_line(header, 1, '// These are the intermediate matrices.')
            write_line(header, 1, '// We define them here so that they can be used')
            write_line(header, 1, '// inside the lambda functions for Cilk.')
            
            for i in xrange(num_multiplies):
                write_line(header, 1, 'Matrix<Scalar> M%d(C11.m(), C11.n(), C.multiplier());' % (i + 1))
            write_break(header)

        # Handle common subexpression elimination on the S and T matrices.
        create_input_cse_subs(header, coeffs, dims)
        write_break(header)

        # Write the mutliplication blocks.
        create_multiplications(header, coeffs, dims)

        write_line(header, 0, '#ifdef _CILK_')
        write_line(header, 1, 'cilk_sync;')
        write_line(header, 0, '#elif defined _OPEN_MP_')
        write_line(header, 0, '# pragma omp taskwait')
        write_line(header, 0, '#endif')
        write_break(header)

        # Handle common subexpression elimination on the M matrices.
        create_output_cse_subs(header, coeffs, dims)

        # Add the multiplication blocks to form the output.
        create_output(header, coeffs, dims)

        write_break(header)
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
