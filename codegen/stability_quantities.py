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
stability parameters.  The output looks like

M*K*N R nnz qmax emax

Example usage:

    python stability_quantities.py algorithms/grey333-23-221 3,3,3

Add an extra flag to print the full q and e vectors:

    python stability_quantities.py algorithms/grey333-23-221 3,3,3
'''

def max_norm(coeffs):
    ''' return maximum absolute value from matrix coefficients. '''
    return np.max([np.abs(float(x)) for row in coeffs for x in row])

def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python stability_vector.py coeff_file m,k,n')

    full_stab_mat = 0
    if len(sys.argv) > 3:
        full_stab_mat = sys.argv[3]

    coeffs = read_coeffs(coeff_file)

    # Using the notation from our paper
    a_vec = np.array([sum(np.abs([float(x) for x in row])) for row in transpose(coeffs[0])])
    b_vec = np.array([sum(np.abs([float(x) for x in row])) for row in transpose(coeffs[1])])

    e_vec = [np.dot(np.abs([float(x) for x in row]), a_vec * b_vec) for row in coeffs[2]]

    alpha_vec = np.array([num_nonzero(row) for row in transpose(coeffs[0])])
    beta_vec  = np.array([num_nonzero(row) for row in transpose(coeffs[1])])
    ab_vec = alpha_vec + beta_vec
    gamma_vec = [num_nonzero(row) for row in coeffs[2]]

    W_ind = np.array([[float(val) for val in row] for row in coeffs[2]])
    W_ind[np.nonzero(W_ind)] = 1
    q_vec = [gamma_vec[k] + np.max(ab_vec * W_ind[k,:]) \
                 for k in range(W_ind.shape[0])]

    # Number of additions
    nnz = sum([val for val in ab_vec]) + sum([val for val in gamma_vec])

    # print as q_vec emax
    rank = len(coeffs[0][0])
    mkn = dims[0] * dims[1] * dims[2]
    print mkn, rank, nnz, int(np.max(q_vec)), int(np.max(e_vec))

    if full_stab_mat:
        # Print in the same style as D'Alberto presents in his 2014 paper.
        print 'e vector:'
        for i in range(dims[0]):
            out_format = '\t' + ' '.join(['%4d' for _ in range(dims[2])])
            vals = e_vec[(i * dims[2]):(i * dims[2] + dims[2])]
            print out_format % tuple(vals)
        print 'q vector:'
        for i in range(dims[0]):
            out_format = '\t' + ' '.join(['%4d' for _ in range(dims[2])])
            vals = q_vec[(i * dims[2]):(i * dims[2] + dims[2])]
            print out_format % tuple(vals)

if __name__ == '__main__':
    main()
