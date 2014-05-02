outfile = 'output/fast.hpp'

def write_subblocks(header, mat_name, dim1, dim2):
    '''
    Write subblocks of matrix of dimensions dim1 x dim2.
    mat_name is the name of the matrix, e.g., 'A' or 'B'
    header is file to write to.
    '''
    x_step = '%s_x_step' % mat_name
    y_step = '%s_y_step' % mat_name
    header.write('int %s = %s.m() / %d;' % (x_step, mat_name, dim1))
    header.write('int %s = %s.n() / %d;' % (y_step, mat_name, dim2))
    for i in xrange(dim1):
        for j in xrange(dim2):
            line = '''
                   Matrix<Scalar> %s%d%d(A.data() + %d * %s + %d * %s * A.stride(),
                                        A.stride(), %s, %s);
                   ''' % (mat_name, i + 1, j + 1, i, x_step, j, y_step, x_step, y_step)
            header.write(line)

dims = (3, 3, 3)
with open(outfile, 'w') as header:
    start =  '''
           template <typename Scalar>
           void FastMatmul(Matrix<Scalar>& A, Matrix<Scalar>& B, Matrix<Scalar>& C, int numsteps) {
           // Base case for recursion
           if (numsteps == 0) {
               Gemm(A, B, C);
               return;
           }
           '''
    header.write(start)

    # Generate sub-blocks
    write_subblocks(header, 'A', dims[0], dims[1])
    write_subblocks(header, 'B', dims[1], dims[2])
    write_subblocks(header, 'C', dims[0], dims[2])

    # Scalars needed
    header.write('''Scalar NegOne = Scalar(-1);
                   Scalar One = Scalar(1);''')

    

    # end of function
    header.write('\n}\n')
