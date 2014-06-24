import sys
from util import *

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
s1,s2,s3 i the permutation, e.g. 1,2,0 for the <k, n, m> algorithm
'''

def transpose(coeff_set, m, n):
    ''' Return a transpose of the coefficient set. '''
    new_coeff_set = []
    for j in range(n):
        for i in range(m):
            # Get the (i, j) coefficient set from the original coefficients
            new_coeff_set.append([x for x in coeff_set[i * n + j]])
    return new_coeff_set


def replicate(coeff_set):
    ''' Return a copy of the coefficient set. '''
    return [[coeff for coeff in entry] for entry in coeff_set]


def swap(coeffs, dims):
    ''' Return the new coefficients for the swapped algorithm, i.e., if
    coeffs comes from <m, k, n>, the return value contains the coefficients
    for the <n, k, m> algorithm.
    '''
    new_coeffs = []
    new_coeffs.append(transpose(coeffs[0], dims[0], dims[1]))
    new_coeffs.append(replicate(coeffs[1]))
    new_coeffs.append(transpose(coeffs[2], dims[1], dims[2]))
    return new_coeffs, (dims[2], dims[1], dims[0])


def cyclic_right(coeffs, dims):
    ''' Return the new coefficients for the cyclic right permutation, i.e., if
    coeffs comes from <m, k, n>, the return value contains the coefficients
    for the <n, m, k> algorithm.
    '''
    new_coeffs = []
    new_coeffs.append(transpose(coeffs[2], dims[0], dims[2]))
    new_coeffs.append(replicate(coeffs[0]))
    new_coeffs.append(transpose(coeffs[1], dims[1], dims[2]))
    return new_coeffs, (dims[2], dims[0], dims[1])


def main():
    print sys.argv
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
        perm = tuple([int(d) for d in sys.argv[4].split(',')])
        print 'Reading coefficients for %d x %d x %d matrix' % dims
        print 'Converting to %d x %d x %d matrix' % (dims[perm[0]], dims[perm[1]], dims[perm[2]])
    except:
        raise Exception('USAGE: python convert.py coeff_file m,n,p out_file s1,s2,s3')

    coeffs = read_coeffs(sys.argv[1])
    new_coeffs = []
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



    with open(sys.argv[3], 'w') as out_file:
        out_file.write('# (%d, %d, %d) permutation of %s\n' % (perm[0], perm[1], perm[2], coeff_file))
        def write_coeff_set(coeff_set):
            print coeff_set
            for entry in coeff_set:
                out_file.write(' '.join([str(val) for val in entry]) + '\n')
     
        write_coeff_set(new_coeffs[0])
        out_file.write('#\n')
        write_coeff_set(new_coeffs[1])
        out_file.write('#\n')
        write_coeff_set(new_coeffs[2])


if __name__ == '__main__':
    main()
