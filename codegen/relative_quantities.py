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
This script takes a coefficient file (not eliminated) and prints the
parameters needed to compute the relative stability and fraction of classical flops:

R M0 K0 N0 emax

Example usage:

    python relative_quantities.py algorithms/strassen 2,2,2
'''

def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python relative_quantities.py coeff_file m,k,n')

    full_stab_mat = 0
    if len(sys.argv) > 3:
        full_stab_mat = sys.argv[3]

    coeffs = read_coeffs(coeff_file)

    # Using the notation from our paper
    a_vec = np.array([sum(np.abs([float(x) for x in row])) for row in transpose(coeffs[0])])
    b_vec = np.array([sum(np.abs([float(x) for x in row])) for row in transpose(coeffs[1])])

    e_vec = [np.dot(np.abs([float(x) for x in row]), a_vec * b_vec) for row in coeffs[2]]

    R = len(coeffs[0][0])

    print R, dims[0], dims[1], dims[2], int(max(e_vec))

if __name__ == '__main__':
    main()
