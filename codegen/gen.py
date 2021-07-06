#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

import sys
import subexpr_elim
from fractions import Fraction

'''
This is the main code generation script.  How to use this program:

  python gen.py coeff_file M,K,N out_file [adds_type]

coeff_file is the path to the coefficients file.
M,K,N are the matrix dimensions:
   multiplying an M x K matrix A by a K x N matrix B and storing in a M x N matrix C
out_file is the name of the output file
adds_type is the type of matrix additions to use.  It is one of {0, 1, 2}:
   0: write-once additions
   1: streaming additions
   2: pairwise additions

Suppose there are R matrix multiplications in the subproblem.
Let alpha_{ij}_r and be the coefficients for submatrix A_{ij} in the r-th
matrix multiplication, i = 1, ..., m, j = 1, ..., n, r = 1, ..., R.
Similarly, let beta_{ij}_r and be the coefficients for submatrix B_{ij} in the r-th
matrix multiplication, i = 1, ..., n, j = 1, ..., p, r = 1, ..., R.
Finally, let gamma_{ij}_r be the coefficients for r-th matrix multiplication in C_{ij}.
The file format for M = K = N = 2 with R = 7 is:

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
    return x != 0 and x != 0.0 and x != '0' and x != '0.0'


def num_nonzero(arr):
    ''' Returns number of non-zero entries in the array arr. '''
    return len(list(filter(is_nonzero, arr)))


def need_tmp_mat(coeffs):
    return num_nonzero(coeffs) > 1


def stride_call(name):
    return  'const int stride%s = %s.stride();' % (name, name)


def data_call(name):
    return 'Scalar *data%s = %s.data();' % (name, name)


def data_access(name):
    return 'data%s[i + j * stride%s]' % (name, name)

def instantiate_tmp(header, tmp_name, mult_index, mat_name):
    write_line(header, 0, '#ifdef _PARALLEL_')
    inst = 'Matrix<Scalar> %s%d(' % (tmp_name, mult_index)
    inst += 'mem_mngr.GetMem(start_index, %d, total_steps - steps_left, %s), ' % (mult_index, tmp_name)
    inst += '%s11.m(), %s11.m(), %s11.n());' % (mat_name, mat_name, mat_name)
    write_line(header, 1, inst)
    write_line(header, 0, '#else')
    inst = 'Matrix<Scalar> %s%d(%s11.m(), %s11.n());' % (tmp_name, mult_index, mat_name, mat_name)
    write_line(header, 1, inst)
    write_line(header, 0, '#endif')


def instantiate(subblock, mat_name):
    return 'Matrix<Scalar> %s(%s11.m(), %s11.n());' % (subblock, mat_name, mat_name)


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
        val = float(Fraction(coeff))
        return str(val)
    except:
        pass
    
    # Parameterized coefficient
    if len(coeff) == 1:
        # Coeff is like 'x'.  We will use 'x' instead of whatever is provided.
        # For now, this means that we only support one paramterized coefficient.
        return 'x'
    elif coeff[0] == '(':
        assert(coeff[-1] == ')')
        expr = coeff[1:-1].split('+')
        return '(' + ' + '.join([parse_coeff(e) for e in expr]) + ')'
    elif coeff[0] == '-':
        return '-(%s)' % parse_coeff(coeff[1:])
    else:
        # Test for a multiplier out in front
        try:
            mult = float(Fraction(coeff[:coeff.find('x')]))
            # mult = float(coeff[0])
            return '%s * (%s)' % (mult, parse_coeff(coeff[coeff.find('x'):]))
        except:
            pass

        # Test for an exponent
        if coeff[-1] == 'i':
            return '1.0 / (%s)' % parse_coeff(coeff[:-1])
        try:
            exp = int(coeff[-1])
            return ' * '.join([parse_coeff(coeff[:-1]) for i in range(exp)])
        except:
            raise Exception('Cannot parse coefficient: %s' % coeff)


def read_coeffs(filename):
    ''' Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.

    filename is the name of the file from which coefficients are read
    '''
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
    ''' Write a break (new line) in the file header. '''
    header.write('\n' * num_breaks)


def write_subblocks(header, mat_name, dim1, dim2):
    ''' Write subblocks of matrix of dimensions dim1 x dim2.
    mat_name is the name of the matrix, e.g., 'A' or 'B'
    header is file to write to.
    '''
    for i in range(dim1):
        for j in range(dim2):
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


def arith_expression(coeff, value, place):
    ''' Return the arithmetic expression needed for multiplying coeff by value
    in a string of expressions.

    coeff is the coefficient
    value is a string representing the value to be multiplied by coeff
    place is the place in the arithmetic expression
    '''
    if is_one(coeff):
         expr = ' %s' % value
    elif is_negone(coeff):
        expr = ' -%s' % value
    else:
        expr = ' Scalar(%s) * %s' % (coeff, value)

    if place != 0 and not is_negone(coeff):
        return ' +' + expr
    return expr


def need_streaming_cse_tmp(ind, coeffs, mat_dims):
    ''' Given an index, determine whether or not we need an extra temporary
    matrix for streaming additions.  This occurs when we have an expression
    that is a eliminated through common subexpression elimination and the
    expression is part of a length-1 addition string in a multiplication.
    For example,
       
       M1 = (A11 + A12 + A13) * (B11 + B12)
       M2 = (A11 + A12) * (B21 + B22)
       
    We would eliminate A_X = A11 + A12 and have:

       M1 = (A_X + A13) * (B11 + B12)
       M2 = (A_X) * (B21 + B22)

    A_X gets used as part of a length-1 addition string for M2.

    ind is the index (zero-indexed linearly) of the of the matrix in the
        coefficient file
    coeffs is the set of coefficients for the U or V matrix
    mat_dims is 2-tuple of the matrix dimensions (A or B corresponding to U or V)
    '''
    if ind < mat_dims[0] * mat_dims[1]:
        return False
    for col in subexpr_elim.transpose(coeffs):
        data = [(i, val) for i, val in enumerate(col) if is_nonzero(val)]
        if len(data) == 1 and data[0][0] == ind:
            return True
    
    return False


def streaming_additions(header, coeff_set, mat_name, tmp_name, mat_dims, is_output,
                        num_multiplies, sub_coeffs=None):
    '''
    Write the streaming additions for the matrices to be used in the multiplications.

    header is the file where the code is being generated
    coeff_set is the set of coefficients (corresponding to U, V, or W)
    mat_name is the name of the matrix we are working on (A, B, or C, that matches
             U, V, or W where coeff_set comes from)
    tmp_name is the base name to use for temporary variables (e.g., 'S' or 'T')
    mat_dims is the dimension of the base case matrix
    is_output indicates whether or not we are working on the matrix C
    num_multiplies is the number of multiplications, i.e., the rank of the
                   algorithm sub_coeffs are the substitution coefficients used
                   for common subexpression elimination (CSE).  This is an
                   optional argument, and should only be used if we are using CSE.
    '''
    def tmp_mat_name(i):
        return tmp_name + str(i + 1)

    def subblock_name(i):
        return mat_name + get_suffix(i, mat_dims[0], mat_dims[1])

    # Find indices of additional temporaries needed from subexpression elimination
    if is_output:
        additional_tmps = []
    else:
        additional_tmps = [i for i in range(len(coeff_set)) if \
                               need_streaming_cse_tmp(i, coeff_set, mat_dims)]
        
    # All of the strides for the matrix subblocks
    for i in range(len(coeff_set)):
        subblock = subblock_name(i)
        if i in additional_tmps:
            write_line(header, 1, instantiate(subblock, mat_name))
        if i < mat_dims[0] * mat_dims[1] or i in additional_tmps:
            write_line(header, 1, stride_call(subblock))
            write_line(header, 1, data_call(subblock))

    # Data for the temporary matrices
    if is_output:
        for i in range(num_multiplies):
            tmp_mat = tmp_mat_name(i)
            write_line(header, 1, stride_call(tmp_mat))
            write_line(header, 1, data_call(tmp_mat))
    else:
        for i, col in enumerate(subexpr_elim.transpose(coeff_set)):
            if need_tmp_mat(col):
                tmp_mat = tmp_mat_name(i)
                write_line(header, 1, instantiate(tmp_mat, mat_name))
                write_line(header, 1, stride_call(tmp_mat))
                write_line(header, 1, data_call(tmp_mat))

    if not is_output:
        coeff_set = subexpr_elim.transpose(coeff_set)

    def inner_loop(handle_beta=False):
        write_line(header, 0, '#ifdef _PARALLEL_')
        write_line(header, 0, '# pragma omp parallel for')
        write_line(header, 0, '#endif')
        write_line(header, 1, 'for (int j = 0; j < %s11.n(); ++j) {' % mat_name)
        write_line(header, 2, 'for (int i = 0; i < %s11.m(); ++i) {' % mat_name)
    
        # Deal with substitutions from CSE
        if sub_coeffs != None:
            for i, col in enumerate(sub_coeffs):
                if i + mat_dims[0] * mat_dims[1] in additional_tmps:
                    add = data_access('%s_X%d' % (mat_name, i + 1)) + ' ='
                else:
                    if is_output:
                        curr_name = tmp_name
                    else:
                        curr_name = mat_name
                    add = 'Scalar %s_X%d = ' % (curr_name, i + 1)
    
                data = [(k, coeff) for k, coeff in enumerate(col) if is_nonzero(coeff)]
                for j, (ind, coeff) in enumerate(data):
                    if is_output:
                        data_name = tmp_mat_name(ind)
                    else:
                        data_name = subblock_name(ind)
                    add += arith_expression(coeff, data_access(data_name), j)
                
                add += ';'
                write_line(header, 3, add)
                    
    
        for i, col in enumerate(coeff_set):
            if need_tmp_mat(col):
                if is_output:
                    add = data_access(subblock_name(i))
                else:
                    add = data_access(tmp_mat_name(i))
                add += ' = '
    
                data = [(k, coeff) for k, coeff in enumerate(col) if is_nonzero(coeff)]
                for j, (ind, coeff) in enumerate(data):
                    if is_output:
                        if ind >= num_multiplies:
                            data_name = 'M_X' + str(ind + 1 - num_multiplies)
                        else:
                            data_name = tmp_mat_name(ind)
                    else:
                        data_name = subblock_name(ind)
    
                    # Deal with subexpression elimination
                    if (ind >= mat_dims[0] * mat_dims[1] and not is_output and ind not in additional_tmps) or \
                            (ind >= num_multiplies and is_output):
                        add += arith_expression(coeff, data_name, j)
                    else:
                        add += arith_expression(coeff, data_access(data_name), j)
                
                if is_output and handle_beta:
                    add += ' + beta * ' + data_access(subblock_name(i))
                add += ';'
                write_line(header, 3, add)
    
        write_line(header, 2, '}')  # end i loop
        write_line(header, 1, '}')  # end j loop

    if not is_output:
        inner_loop()
    else:
        write_line(header, 1, 'if (beta == Scalar(0.0)) {')
        inner_loop()
        write_line(header, 1, '} else {')
        inner_loop(True)
        write_line(header, 1, '}')
    

def create_streaming_input_adds(header, coeffs, dims):
    num_multiplies = len(coeffs[0][0])
    write_break(header)
    if len(coeffs) > 3 and len(coeffs[3][0]) > 0:
        sub_coeffs = coeffs[3]
    else:
        sub_coeffs = None
    streaming_additions(header, coeffs[0], 'A', 'S', (dims[0], dims[1]), False,
                        num_multiplies, sub_coeffs)

    if len(coeffs) > 4  and len(coeffs[4][0]) > 0:
        sub_coeffs = coeffs[4]
    else:
        sub_coeffs = None
    write_break(header)
    streaming_additions(header, coeffs[1], 'B', 'T', (dims[1], dims[2]), False,
                        num_multiplies, sub_coeffs)


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
    add += '%s, x, false, beta);' % output_mat
    write_line(header, 1, add)


def write_add_func(header, coeffs, index, mat_name, bfs_par_avail):
    ''' Write the add function for a set of coefficients.  This is a custom add
    function used for a single multiply in a single fast algorithm.

    coeffs is the set of coefficients used for the add
    '''
    nonzero_coeffs = [coeff for coeff in coeffs if is_nonzero(coeff)]
    nnz = len(nonzero_coeffs)
    # TODO(arbenson): put in a code-generated comment here
    write_line(header, 0, 'template <typename Scalar>')
    add = 'void %s_Add%d(' % (mat_name, index)
    add += ', '.join(['Matrix<Scalar>& %s%d' % (mat_name, i + 1) for i in range(nnz)])
    add += ', Matrix<Scalar>& C, double x, bool sequential'
    # Handle the C := alpha A * B + beta C
    is_output = (mat_name == 'M')
    if is_output:
        add += ', Scalar beta'
    add += ') {'
    write_line(header, 0, add)

    # All of the strides
    for i in range(nnz):
        write_line(header, 1, stride_call(mat_name + str(i + 1)))
    write_line(header, 1, stride_call('C'))

    # All of the data pointers
    for i in range(nnz):
        write_line(header, 1, 'const Scalar *data%s%d = %s%d.data();' % (
                mat_name, i + 1, mat_name, i + 1))
    write_line(header, 1, 'Scalar *dataC = C.data();')

    # Handle the C := alpha A * B + beta C
    if is_output:
        write_line(header, 1, 'if (beta != Scalar(0.0)) {')
        write_line(header, 0, '#ifdef _PARALLEL_')
        write_line(header, 0, '# pragma omp parallel for if(!sequential)')
        write_line(header, 0, '#endif')
        write_line(header, 2, 'for (int j = 0; j < C.n(); ++j) {')
        write_line(header, 3, 'for (int i = 0; i < C.m(); ++i) {')
        add = data_access('C') + ' ='
        for j, coeff in enumerate(nonzero_coeffs):
            ind = j + 1
            add += arith_expression(coeff, data_access(mat_name + str(ind)), j)
        add += ' + beta * %s;' % (data_access('C'))

        write_line(header, 4, add)
        write_line(header, 3, '}')
        write_line(header, 2, '}')
        write_line(header, 1, '} else {')
        write_line(header, 0, '#ifdef _PARALLEL_')
        write_line(header, 0, '# pragma omp parallel for if(!sequential)')
        write_line(header, 0, '#endif')
        write_line(header, 2, 'for (int j = 0; j < C.n(); ++j) {')
        write_line(header, 3, 'for (int i = 0; i < C.m(); ++i) {')
        add = data_access('C') + ' ='
        for j, coeff in enumerate(nonzero_coeffs):
            ind = j + 1
            add += arith_expression(coeff, data_access(mat_name + str(ind)), j)
        add += ';'
        write_line(header, 4, add)
        write_line(header, 3, '}')
        write_line(header, 2, '}')
        write_line(header, 1, '}')
    else:
        write_line(header, 0, '#ifdef _PARALLEL_')
        write_line(header, 0, '# pragma omp parallel for if(!sequential)')
        write_line(header, 0, '#endif')
        write_line(header, 1, 'for (int j = 0; j < C.n(); ++j) {')
        write_line(header, 2, 'for (int i = 0; i < C.m(); ++i) {')
        add = data_access('C') + ' ='
        for j, coeff in enumerate(nonzero_coeffs):
            ind = j + 1
            add += arith_expression(coeff, data_access(mat_name + str(ind)), j)
    
        add += ';'
        write_line(header, 3, add)
        write_line(header, 2, '}')
        write_line(header, 1, '}')

    write_line(header, 0, '}')  # end of function


def write_pairwise_add_func(header, coeffs, index, mat_name):
    ''' Write the add function for a set of coefficients.  This is a custom add
    function used for a single multiply in a single fast algorithm.

    coeffs is the set of coefficients used for the add
    '''
    is_output = (mat_name == 'M')

    nonzero_coeffs = [coeff for coeff in coeffs if is_nonzero(coeff)]
    nnz = len(nonzero_coeffs)
    # TODO(arbenson): put in a code-generated comment here
    write_line(header, 0, 'template <typename Scalar>')
    add = 'void %s_Add%d(' % (mat_name, index)
    add += ', '.join(['Matrix<Scalar>& %s%d' % (mat_name, i + 1) for i in range(nnz)])
    add += ', Matrix<Scalar>& C, double x, bool sequential'
    if is_output:
        add += ', Scalar beta'
    add += ') {'
    write_line(header, 0, add)

    if is_output:
        write_line(header, 1, 'Matrix<Scalar> C_orig;')
        write_line(header, 1, 'if (beta != Scalar(0.0)) {')
        write_line(header, 2, 'C_orig = C;  // copy')
        write_line(header, 1, '}')
    

    for j, coeff in enumerate(nonzero_coeffs):
        ind = j + 1
        if ind == 1:
            if is_one(coeff):
                write_line(header, 1, 'Copy(%s, C);' % (mat_name + str(ind)))
            elif is_negone(coeff):
                write_line(header, 1, 'Negate(%s, C);' % (mat_name + str(ind)))
            else:
                write_line(header, 1, 'Copy(%s, %s, C);' % (mat_name + str(ind), coeff))
        else:
            write_line(header, 1, 'UpdateAddDaxpy(%s, Scalar(%s), C);' % (
                    mat_name + str(ind), coeff))
    
    if is_output:
        write_line(header, 1, 'if (beta != Scalar(0.0)) {')
        write_line(header, 2, 'UpdateAddDaxpy(C_orig, beta, C);')
        write_line(header, 1, '}')

    write_line(header, 0, '}')


def write_multiply(header, index, a_coeffs, b_coeffs, dims, streaming_adds, num_multiplies):
    comment = '// M%d = (' % (index)
    comment += ' + '.join([str(c) + ' * A%s' % get_suffix(i, dims[0], dims[1]) \
                               for i, c in enumerate(a_coeffs) if is_nonzero(c)])
    comment += ') * ('
    comment += ' + '.join([str(c) + ' * B%s' % get_suffix(i, dims[1], dims[2]) \
                               for i, c in enumerate(b_coeffs) if is_nonzero(c)])
    comment += ')'
    write_line(header, 1, comment)

    # Shared memory wrappers (start)
    write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)')
    task = '# pragma omp task if(sequential%d) shared(mem_mngr, locker) untied default(shared)' % index
    write_line(header, 0, task)
    write_line(header, 1, '{')
    write_line(header, 0, '#endif')

    def addition_str(coeffs, mat_name, tmp_name, mat_dims):
        tmp_mat = '%s%d' % (tmp_name, index)
        add = '%s_Add%d(' % (tmp_name, index)
        for i, coeff in enumerate(coeffs):
            if is_nonzero(coeff):
                add += mat_name + '%s, ' % get_suffix(i, mat_dims[0], mat_dims[1])
        return add + tmp_mat + ', x, sequential%d);' % index

    # Write the adds to temps if necessary
    if need_tmp_mat(a_coeffs) and not streaming_adds:
        instantiate_tmp(header, 'S', index, 'A')
        write_line(header, 1, addition_str(a_coeffs, 'A', 'S', (dims[0], dims[1])))
    if need_tmp_mat(b_coeffs) and not streaming_adds:
        instantiate_tmp(header, 'T', index, 'B')
        write_line(header, 1, addition_str(b_coeffs, 'B', 'T', (dims[1], dims[2])))

    res_mat = 'M%d' % (index)

    # Handle the case where there is one non-zero coefficient and it is
    # not equal to one.  We need to propagate the multiplier information.
    a_nonzero_coeffs = list(filter(is_nonzero, a_coeffs))
    b_nonzero_coeffs = list(filter(is_nonzero, b_coeffs))
    #a_nz_coef_list = list(a_nonzero_coeffs)
    if len(a_nonzero_coeffs) == 1:
        if a_nonzero_coeffs[0] != 1:
            write_line(header, 1, '%s.UpdateMultiplier(Scalar(%s));' % (res_mat,
                                                                    a_nonzero_coeffs[0]))

    if len(b_nonzero_coeffs) == 1 and b_nonzero_coeffs[0] != 1:
        write_line(header, 1, '%s.UpdateMultiplier(Scalar(%s));' % (res_mat,
                                                                    b_nonzero_coeffs[0]))

    def subblock_name(coeffs, mat_name, tmp_name, mat_dims):
        if need_tmp_mat(coeffs):
            return '%s%d' % (tmp_name, index)
        else:
            loc = [i for i, c in enumerate(coeffs) if is_nonzero(c)]
            return mat_name + get_suffix(loc[0], mat_dims[0], mat_dims[1])

    # Finally, write the actual call to matrix multiply.
    write_line(header, 1,
               'FastMatmulRecursive(locker, mem_mngr, %s, %s, %s, total_steps, steps_left - 1, %s, x, num_threads, Scalar(0.0));' % (
            subblock_name(a_coeffs, 'A', 'S', (dims[0], dims[1])),
            subblock_name(b_coeffs, 'B', 'T', (dims[1], dims[2])),
            res_mat, '(start_index + %d - 1) * %d' % (index, num_multiplies)))

    # If we are not in parallel mode, de-allocate the temporary matrices
    write_line(header, 0, '#ifndef _PARALLEL_')
    if need_tmp_mat(a_coeffs) and not streaming_adds:
        write_line(header, 1, 'S%d.deallocate();' % (index))
    if need_tmp_mat(b_coeffs) and not streaming_adds:
        write_line(header, 1, 'T%d.deallocate();' % (index))
    write_line(header, 0, '#endif')
    
    # Shared memory wrappers (end)
    write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)')
    write_line(header, 0, 'locker.Decrement();')
    write_line(header, 1, '}')
    write_line(header, 1, 'if (should_task_wait(%d, total_steps, steps_left, start_index, %d, num_threads)) {' % (
            num_multiplies, index))
    write_line(header, 0, '# pragma omp taskwait')
    if index != num_multiplies:
        write_line(header, 0, '# if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)')
        write_line(header, 1, 'SwitchToDFS(locker, num_threads);')
        write_line(header, 0, '# endif')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif\n')


def create_add_functions(header, coeffs, pairwise):
    ''' Generate all of the custom add functions.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    '''
    def all_adds(coeffs, name, bfs_par_avail):
        for i, coeff_set in enumerate(coeffs):
            if len(coeff_set) > 0:
                if pairwise:
                    write_pairwise_add_func(header, coeff_set, i + 1, name)
                else:
                    write_add_func(header, coeff_set, i + 1, name, bfs_par_avail)
                write_break(header)

    # S matrices formed from A subblocks
    all_adds(subexpr_elim.transpose(coeffs[0]), 'S', False)

    # T matrices formed from B subblocks
    all_adds(subexpr_elim.transpose(coeffs[1]), 'T', False)

    # Output C formed from multiplications
    all_adds(coeffs[2], 'M', True)

    # If there was CSE, create more add functions for the temporary matrices.
    if len(coeffs) > 3:
        all_adds(coeffs[3], 'SX', True)

    if len(coeffs) > 4:
        all_adds(coeffs[4], 'TX', True)

    if len(coeffs) > 5:
        all_adds(coeffs[5], 'MX', True)


def create_multiplications(header, coeffs, dims, streaming_adds, num_multiplies):
    ''' Generate all of the recursive multiplication calls.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple (m, k, n) of the dimensions of the problem
    streaming_adds inidicates whether or not we are using the streaming version
                   of matrix additions
    '''
    for i in range(len(coeffs[0][0])):
        a_coeffs = [c[i] for c in coeffs[0]]
        b_coeffs = [c[i] for c in coeffs[1]]
        write_multiply(header, i + 1, a_coeffs, b_coeffs, dims, streaming_adds, num_multiplies)


def write_input_cse_sub(header, coeffs, index, mat_name, add_name, mat_dims):
    # If it is empty, skip it
    if len(coeffs) == 0:
        return

    tmp_mat_name = '%s_X%d' % (mat_name, index)
    write_line(header, 1, instantiate(tmp_mat_name, mat_name))
    add = '%s%d(' % (add_name, index)
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += '%s%s, ' % (mat_name, get_suffix(i, mat_dims[0], mat_dims[1]))
    add += tmp_mat_name
    add += ', x, false);'
    write_line(header, 1, add)


def write_output_cse_sub(header, coeffs, index, mat_name, add_name, mat_dims):
    # If it is empty, skip it
    if len(coeffs) == 0 or num_nonzero(coeffs) == 0:
        return

    tmp_mat_name = '%s_X%d' % (mat_name, index)
    write_line(header, 1, instantiate(tmp_mat_name, mat_name))
    add = '%s%d(' % (add_name, index)
    for i, coeff in enumerate(coeffs):
        if is_nonzero(coeff):
            add += '%s%d, ' % (mat_name, i + 1)
    add += tmp_mat_name
    add += ', x, false);'
    write_line(header, 1, add)


def create_input_cse_subs(header, coeffs, dims, streaming_adds):
    ''' Generate all of the substitutions for CSE for S and T matrices.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple of the algorithm dimensions (m, k, n)
    '''
    if streaming_adds:
        # All temporaries are created within the streaming loop.
        return

    if len(coeffs) > 3:
        for i, coeff_line in enumerate(coeffs[3]):
            write_input_cse_sub(header, coeff_line, i + 1, 'A', 'SX_Add',
                                (dims[0], dims[1]))

    write_break(header)
    if len(coeffs) > 4:
        for i, coeff_line in enumerate(coeffs[4]):
            write_input_cse_sub(header, coeff_line, i + 1, 'B', 'TX_Add',
                                (dims[1], dims[2]))

    write_break(header)


def create_output_cse_subs(header, coeffs, dims, streaming_adds):
    ''' Generate all of the substitutions for CSE for M matrices.

    header is the file to which we are writing
    coeffs is the set of all coefficients
    dims is a 3-tuple of the algorithm dimensions (m, k, n)
    '''
    if streaming_adds:
        # All temporaries are created within the streaming loop.
        return

    if len(coeffs) > 5:
        for i, coeff_line in enumerate(coeffs[5]):
            write_output_cse_sub(header, coeff_line, i + 1, 'M', 'MX_Add',
                                 (dims[0], dims[2]))


def create_output(header, coeffs, dims, streaming_adds):
    num_multiplies = len(coeffs[0][0])

    if streaming_adds:
        if len(coeffs) > 5 and len(coeffs[5][0]) > 0:
            sub_coeffs = coeffs[5]
        else:
            sub_coeffs = None
        streaming_additions(header, coeffs[2], 'C', 'M', (dims[0], dims[2]),
                            True, num_multiplies, sub_coeffs)
    else:
        for i, row in enumerate(coeffs[2]):
            write_output_add(header, i + 1, row, (dims[0], dims[2]),
                             num_multiplies)


def create_wrapper_func(header, num_multiplies, dims):
    # Wrapper to deal with OpenMP
    write_line(header, 0, '// C := alpha * A * B + beta * C')
    write_line(header, 0, 'template <typename Scalar>')
    write_line(header, 0, 'double FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, ' +
               'Matrix<Scalar>& C,')
    write_line(header, 1, 'int num_steps, double x=1e-8, int num_threads=1, Scalar alpha=Scalar(1.0), ' +
               'Scalar beta=Scalar(0.0)) {')
    write_line(header, 1, 'MemoryManager<Scalar> mem_mngr;')
    write_line(header, 0, '#ifdef _PARALLEL_')
    write_line(header, 1, 'mem_mngr.Allocate(%d, %d, %d, %d, num_steps, A.m(), A.n(), B.n());'
               % (dims[0], dims[1], dims[2], num_multiplies))
    write_line(header, 0, '#endif')               

    write_line(header, 1, 'A.set_multiplier(alpha);')
    write_line(header, 1, 'int num_multiplies_per_step = %d;' % num_multiplies)
    write_line(header, 1, 'int total_multiplies = pow(num_multiplies_per_step, num_steps);')
    write_line(header, 0, '')

    write_line(header, 1, '// Set parameters needed for all types of parallelism.')
    write_line(header, 1, '// int num_threads = 0;')
    write_line(header, 1, 'omp_set_num_threads(num_threads);')
    write_line(header, 0, '#ifdef _PARALLEL_')
    write_line(header, 0, '# pragma omp parallel')
    write_line(header, 1,  '{')
    write_line(header, 2, 'if (omp_get_thread_num() == 0) { num_threads = omp_get_num_threads(); }')
    write_line(header, 1,  '}')
    write_line(header, 1, 'omp_set_max_active_levels(2);')
    write_line(header, 0, '#endif')
    write_line(header, 0, '')

    write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_)')
    write_line(header, 0, '# pragma omp parallel')
    write_line(header, 1, '{')
    write_line(header, 2, 'mkl_set_num_threads_local(1);')
    write_line(header, 2, 'mkl_set_dynamic(0);')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif')
    write_line(header, 0, '')

    write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _DFS_PAR_)')
    write_line(header, 1, 'mkl_set_dynamic(0);')
    write_line(header, 0, '#endif')
    write_line(header, 0, '')

    write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _HYBRID_PAR_)')
    write_line(header, 1, 'if (num_threads > total_multiplies) {')
    write_line(header, 2, 'mkl_set_dynamic(0);')
    write_line(header, 1, '} else {')
    write_line(header, 0, '# pragma omp parallel')
    write_line(header, 2, '{')
    write_line(header, 3, 'mkl_set_num_threads_local(1);')
    write_line(header, 3, 'mkl_set_dynamic(0);')
    write_line(header, 2, '}')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif')
    write_line(header, 0, '')

    write_line(header, 1, 'LockAndCounter locker(total_multiplies - (total_multiplies % num_threads));')
    write_line(header, 1, 'using FpMilliseconds = std::chrono::duration<float, std::chrono::milliseconds::period>;')
    write_line(header, 1, 'auto t1 = std::chrono::high_resolution_clock::now();')
    write_line(header, 0, '')

    write_line(header, 0, '#ifdef _PARALLEL_')
    write_line(header, 0, '# pragma omp parallel')
    write_line(header, 1, '{')
    write_line(header, 0, '# pragma omp single')
    write_line(header, 0, '#endif')

    write_line(header, 2, 'FastMatmulRecursive(locker, mem_mngr, A, B, C, num_steps, num_steps, 0, x, num_threads, beta);')

    write_line(header, 0, '#ifdef _PARALLEL_')
    write_line(header, 1, '}')
    write_line(header, 0, '#endif')

    write_line(header, 1, 'auto t2 = std::chrono::high_resolution_clock::now();')
    write_line(header, 1, 'return FpMilliseconds(t2 - t1).count();')
    write_line(header, 0, '}\n')


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
        outfile = 'fast.hpp'
        if len(sys.argv) > 3:
            outfile = sys.argv[3]

        streaming_adds = False
        pairwise_adds = False
        if len(sys.argv) > 4:
            arg = int(sys.argv[4])
            if arg == 0:
                write_once_adds = True
            elif arg == 1:
                streaming_adds = True
            elif arg == 2:
                pairwise_adds = True
            else:
                raise Exception('Unknown fourth argument.')

        # Create a namespace name from the file name
        namespace_name = coeff_file.split('.')[0]
        namespace_name = namespace_name.replace('-', '_')
        namespace_name = namespace_name.split('/')[-1]
        if len(sys.argv) > 5:
            namespace_name = sys.argv[5]

        print('Generating code for %d x %d x %d' % dims)
    except:
        raise Exception('USAGE: python gen.py coeff_file m,n,p out_file')

    coeffs = read_coeffs(sys.argv[1])

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

        if not streaming_adds:
            create_add_functions(header, coeffs, pairwise_adds)

        # Start of fast matrix multiplication function
        write_line(header, 0, 'template <typename Scalar>')
        write_line(header, 0, 'void FastMatmulRecursive(LockAndCounter& locker, MemoryManager<Scalar>& mem_mngr, Matrix<Scalar>& A, Matrix<Scalar>& B, ' +
                   'Matrix<Scalar>& C, int total_steps, int steps_left, int start_index, double x, int num_threads, Scalar beta) {')

        # Handle the multipliers
        write_line(header, 1, '// Update multipliers')
        write_line(header, 1, 'C.UpdateMultiplier(A.multiplier());')
        write_line(header, 1, 'C.UpdateMultiplier(B.multiplier());')
        write_line(header, 1, 'A.set_multiplier(Scalar(1.0));')
        write_line(header, 1, 'B.set_multiplier(Scalar(1.0));')

        # Handle base case
        write_line(header, 1, '// Base case for recursion')
        write_line(header, 1, 'if (steps_left == 0) {')
        write_line(header, 2, 'MatMul(A, B, C);')
        write_line(header, 2, 'return;')
        write_line(header, 1, '}\n')
        
        # Generate sub-blocks
        write_subblocks(header, 'A', dims[0], dims[1])
        write_subblocks(header, 'B', dims[1], dims[2])
        write_subblocks(header, 'C', dims[0], dims[2])
        write_break(header)

        if streaming_adds:
            create_streaming_input_adds(header, coeffs, dims)
    

        num_multiplies = len(coeffs[0][0])
        print('%d matrix multiplications...' % num_multiplies)

        # Declaration of all of the intermediate multiplication results.
        write_break(header)
        write_line(header, 1, '// Matrices to store the results of multiplications.')
            
        write_line(header, 0, '#ifdef _PARALLEL_')
        for i in range(num_multiplies):
            write_line(header, 1,
                       'Matrix<Scalar> M%d(mem_mngr.GetMem(start_index, %d, total_steps - steps_left, M), C11.m(), C11.m(), C11.n(), C.multiplier());' % (i + 1, i + 1))
        write_line(header, 0, '#else')
        for i in range(num_multiplies):
            write_line(header, 1, 'Matrix<Scalar> M%d(C11.m(), C11.n(), C.multiplier());' % (i + 1))
        write_line(header, 0, '#endif')

        write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)')
        for i in range(num_multiplies):
            write_line(header, 1,
                       'bool sequential%d = should_launch_task(%d, total_steps, steps_left, start_index, %d, num_threads);' % (
                    i + 1, num_multiplies, i + 1))
        write_line(header, 0, '#else')
        for i in range(num_multiplies):
            write_line(header, 1, 'bool sequential%d = false;' % (i + 1))
        write_line(header, 0, '#endif')


        # Handle common subexpression elimination on the S and T matrices.
        create_input_cse_subs(header, coeffs, dims, streaming_adds)
        write_break(header)

        # Write the mutliplication blocks.
        create_multiplications(header, coeffs, dims, streaming_adds, num_multiplies)

        # Handle common subexpression elimination on the M matrices.
        create_output_cse_subs(header, coeffs, dims, streaming_adds)

        # Add the multiplication blocks to form the output.
        create_output(header, coeffs, dims, streaming_adds)

        write_break(header)
        write_line(header, 1, '// Handle edge cases with dynamic peeling')
        write_line(header, 0, '#if defined(_PARALLEL_) && (_PARALLEL_ == _BFS_PAR_ || _PARALLEL_ == _HYBRID_PAR_)')
        write_line(header, 1, 'if (total_steps == steps_left) {')
        write_line(header, 2, 'mkl_set_num_threads_local(num_threads);')
        write_line(header, 2, 'mkl_set_dynamic(0);')
        write_line(header, 1, '}')
        write_line(header, 0, '#endif')
        write_line(header, 1, 'DynamicPeeling(A, B, C, %d, %d, %d, beta);' % dims)

        # end of function
        write_line(header, 0, '}\n')

        create_wrapper_func(header, num_multiplies, dims)

        # end of namespace
        write_line(header, 0, '}  // namespace %s\n' % namespace_name)
        # end of file
        write_line(header, 0, '#endif  // _%s_HPP_' % namespace_name)


if __name__ == '__main__':
    main()
