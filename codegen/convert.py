import sys

'''
This script converts coefficients for <m, k, n> algorithms to all permutations:

0,1,2: <m, k, n>
0,2,1: <m, n, k>
1,0,2: <k, m, n>
1,2,0: <k, n, m>
2,0,1: <n, m, k>
2,1,0: <n, k, m>

The usage is:
   python convert.py coeff_file m,k,n out_file s1,s2,s3

where

coeff_file is the name of the original coefficient file
m,k,n is the original algorithm dimensions
out_file is the name of the file in which to write the new coefficients
s1,s2,s3 is the permutation, e.g. 1,2,0 for the <k, n, m> algorithm
'''


def transpose(coeff_set, m, n, row2col=True):
    ''' Return a transpose of the coefficient set.
    coeff_set is the original set of coefficients
    m is the number of rows
    n is the number of columns
    '''
    if len(coeff_set) != m * n:
        raise Exception('Incorrect number of entries in coefficient set')

    new_coeff_set = []
    if row2col:
        for j in range(n):
            for i in range(m):
                # Get the (i, j) coefficient set from the original coefficients
                new_coeff_set.append([x for x in coeff_set[i * n + j]])
    else:
        for i in range(m):
            for j in range(n):
                # Get the (i, j) coefficient set from the original coefficients
                new_coeff_set.append([x for x in coeff_set[j * m + i]])

    return new_coeff_set


def replicate(coeff_set):
    ''' Return a copy of the coefficient set. '''
    return [[coeff for coeff in entry] for entry in coeff_set]


def swap(coeffs, dims):
    ''' Get the new coefficients for the swapped algorithm, i.e., if
    coeffs comes from <m, k, n>, the return value contains the coefficients
    for the <n, k, m> algorithm.  The first return value is the new coefficient
    set and the second return value contains the new algorithm dimensions.

    coeffs are the original coefficiets
    dims is a 3-tuple of the algorithm dimensions
    '''
    new_coeffs = []
    new_coeffs.append(transpose(coeffs[1], dims[1], dims[2]))
    new_coeffs.append(transpose(coeffs[0], dims[0], dims[1]))
    new_coeffs.append(transpose(coeffs[2], dims[0], dims[2]))
    return new_coeffs, (dims[2], dims[1], dims[0])


def cyclic_right(coeffs, dims):
    ''' Get the new coefficients for the cyclic right permutation, i.e., if
    coeffs comes from <m, k, n>, the return value contains the coefficients
    for the <n, m, k> algorithm.  The first return value is the new coefficient
    set and the second return value contains the new algorithm dimensions.

    coeffs are the original coefficiets
    dims is a 3-tuple of the algorithm dimensions
    '''
    new_coeffs = []
    new_coeffs.append(transpose(coeffs[2], dims[0], dims[2]))
    new_coeffs.append(replicate(coeffs[0]))
    new_coeffs.append(transpose(coeffs[1], dims[1], dims[2]))
    return new_coeffs, (dims[2], dims[0], dims[1])


def col2row(coeffs, dims):
    ''' Convert from column-major ordering to row-major ordering. '''
    new_coeffs = []
    new_coeffs.append(transpose(coeffs[0], dims[0], dims[1], row2col=False))
    new_coeffs.append(transpose(coeffs[1], dims[1], dims[2], row2col=False))
    new_coeffs.append(transpose(coeffs[2], dims[0], dims[2], row2col=False))
    return new_coeffs


def read_coeffs(filename):
    ''' Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.  Keep the textual structure of the file. '''
    coeffs = []
    with open(filename, 'r') as coeff_file:
        curr_group = []
        for line in coeff_file:
            if line[0] == '#':
                if len(curr_group) > 0:
                    coeffs.append(curr_group)
                    curr_group = []
            else:
                curr_group.append([val for val in line.split()])
    coeffs.append(curr_group)
    # There should be three sets of coefficients: one for each matrix.
    if (len(coeffs) != 3):
        raise Exception('Expected three sets of coefficients!')
    return coeffs


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
        perm = tuple([int(d) for d in sys.argv[4].split(',')])
        print 'Reading coefficients for %d x %d x %d matrix' % dims
        print 'Converting to %d x %d x %d matrix' % (dims[perm[0]], dims[perm[1]], dims[perm[2]])
    except:
        raise Exception('USAGE: python convert.py coeff_file m,k,n out_file s1,s2,s3')

    coeffs = read_coeffs(sys.argv[1])

    if perm == (0, 1, 2):
        new_coeffs = [replicate(coeffs[i]) for i in range(3)]
    elif perm == (2, 0, 1):
        new_coeffs, _ = cyclic_right(coeffs, dims)
    elif perm == (1, 2, 0):
        new_coeffs, new_dims = cyclic_right(coeffs, dims)
        new_coeffs, _ = cyclic_right(new_coeffs, new_dims)
    elif perm == (0, 2, 1):
        new_coeffs, new_dims = cyclic_right(coeffs, dims)
        new_coeffs, new_dims = cyclic_right(new_coeffs, new_dims)
        new_coeffs, _ = swap(new_coeffs, new_dims)
    elif perm == (1, 0, 2):
        new_coeffs, new_dims = cyclic_right(coeffs, dims)
        new_coeffs, _ = swap(new_coeffs, new_dims)
    elif perm == (2, 1, 0):
        new_coeffs, _ = swap(coeffs, dims)
    elif perm == (0, 0, 0):
        # This is a special case for converting from column-major to row-major.
        new_coeffs = col2row(coeffs, dims)
    else:
        raise Exception('Invalid permutation %d,%d,%d' % perm)

    with open(sys.argv[3], 'w') as out_file:
        out_file.write('# (%d, %d, %d) permutation of %s\n' % (perm[0], perm[1], perm[2], coeff_file))
        def write_coeff_set(coeff_set):
            ''' Write the coefficient set for a single matrix (A, B, or C). '''
            for entry in coeff_set:
                # Single (i, j) entry of a single matrix.
                out_file.write(' '.join([str(val) for val in entry]) + '\n')
     
        write_coeff_set(new_coeffs[0])
        out_file.write('#\n')
        write_coeff_set(new_coeffs[1])
        out_file.write('#\n')
        write_coeff_set(new_coeffs[2])

if __name__ == '__main__':
    main()
