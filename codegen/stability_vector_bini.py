#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

import sys
import numpy as np
from convert import read_coeffs
from gen import num_nonzero, is_nonzero
from subexpr_elim import transpose


'''
This script takes a coefficient file (not eliminated) and computes the
stability vector as described by Bini and Lotti in their 1980 paper
"Stability of Fast Algorithms for Matrix Multiplication".  Example usage:

    python stability_vector.py algorithms/grey333-23-221 3,3,3
'''


def max_norm(coeffs):
    ''' return maximum absolute value from matrix coefficients. '''
    return np.max([np.abs(float(x)) for row in coeffs for x in row])

def zero_one(val):
    return 1.0 if is_nonzero(val) else 0.0

def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python stability_vector.py coeff_file m,k,n')

    coeffs = read_coeffs(coeff_file)

    # Using the notation from our paper
    a_vec = np.array([sum(np.abs([zero_one(x) for x in row])) for row in transpose(coeffs[0])])
    b_vec = np.array([sum(np.abs([zero_one(x) for x in row])) for row in transpose(coeffs[1])])

    e_vec = [np.dot(np.abs([float(x) for x in row]), a_vec * b_vec) for row in coeffs[2]]

    mn = max_norm(coeffs[0]) * max_norm(coeffs[1]) * max_norm(coeffs[2])
    emax = int(np.max(e_vec))

    print emax, mn, emax * mn


if __name__ == '__main__':
    main()
