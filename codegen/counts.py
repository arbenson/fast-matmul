import convert
import sys
import gen
import subexpr_elim

'''
This script takes a coefficient file (eliminated or not) and counts the number
of additions, read, and writes performed by the algorithm. Example usage:

     python counts.py algorithms/eliminated/grey333-23-125 3,3,3

This produces the following output:

      +   r   w
A    12  35  10
B    11  34  10
C    29  38   9
AX    6  12   6
BX    7  14   7
CX    5  10   5
tot  70 143  47

The counts for A, B, and C refer to the 'S', 'T', and 'M' matrices.
The counts for AX, BX, and CX refer to the extra computation done for common
subexpression elimination.
'''

def base_counts(coeff_set):
    ''' Count the number of additions, reads, and writes for this coefficient set (A, B, or C).
    For A and B, these are the adds used to form the 'S' and 'T' matrices.
    If an S or T matrix is just a length-1 addition chain, then no additions are counted.
    '''
    cols = subexpr_elim.transpose(coeff_set)
    num_adds = sum([gen.num_nonzero(col) - 1 for col in cols])
    num_reads = sum([gen.num_nonzero(col) for col in cols])
    num_writes = sum([1 for col in cols if gen.num_nonzero(col) > 1])
    return (num_adds, num_reads, num_writes)


def elim_counts(elim_info):
    ''' Count the number of additions, reads, and writes for the elimination variables of
    a single coefficient set (for S matrices, T matrix, or M matrices).
    '''
    if any(map(lambda x: len(x) == 0, elim_info)):
        return (0, 0, 0)

    num_adds = sum([gen.num_nonzero(row) - 1 for row in elim_info])
    num_reads = sum([gen.num_nonzero(row) for row in elim_info])
    num_writes = len(elim_info)
    return (num_adds, num_reads, num_writes)


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python counts.py coeff_file m,k,n')

    coeffs = convert.read_coeffs(coeff_file)
    coeffs[2] = subexpr_elim.transpose(coeffs[2])

    counts = [base_counts(coeffs[i]) for i in range(3)]
    counts_X = [(0, 0, 0) for i in range(3, 6)]
    if len(coeffs) > 3:
        counts_X = [elim_counts(coeffs[i]) for i in range(3, 6)]
    xtotal = tuple([sum(cnts) for cnts in zip(*(counts_X))])
    total = tuple([sum(cnts) for cnts in zip(*(counts + counts_X))])


    print '      +   r   w'
    print 'A    %3d %3d %3d' % counts[0]
    print 'B    %3d %3d %3d' % counts[1]
    print 'C    %3d %3d %3d' % counts[2]
    print 'AX   %3d %3d %3d' % counts_X[0]
    print 'BX   %3d %3d %3d' % counts_X[1]
    print 'CX   %3d %3d %3d' % counts_X[2]
    print 'xtot %3d %3d %3d' % xtotal
    print 'tot  %3d %3d %3d' % total 

if __name__ == '__main__':
    main()
