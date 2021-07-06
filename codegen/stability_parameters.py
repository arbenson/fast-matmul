#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

import sys
from convert import read_coeffs
from subexpr_elim import transpose
from verify2 import Number

'''
This script takes a coefficient file (not eliminated) for an APA and computes
the stability parameters as described by Bini, Lotti, and Romani in their 1980
paper "Approximate solutions for the bilinear form computational problem".
Example usage:

    python stability_parameters.py algorithms/bini322-10-52-approx 3,2,2
'''

def compute_phi(coeffs):
    ''' Compute phi (in Bini et al. notation), which is defined as
 
            \phi = max { z | u_i^{(r)}v_j^{(r)}w_k^{(r)} = O(\epsilon^{-z}) },

        where u_i^{(r)}, v_j^{(r)}, and w_k^{(r)} are entries of the rth column of U, V, and W.
    '''

    U = transpose(coeffs[0])
    V = transpose(coeffs[1])
    W = transpose(coeffs[2])
    
    def smallest_exponent(u, v, w):
        def min_exp(num):
            # num.val is a dictionary of (exponent, coefficient)
            all_viable = filter(lambda keyval: keyval[1] != 0, num.val.items())
            listViable = list(all_viable)
            if len(listViable) == 0:
                return 0
            return min([key for key, val in listViable])

        all_nums = [Number(x1) * Number(x2) * Number(x3) \
                    for x1 in u for x2 in v for x3 in w]

        return min([min_exp(num) for num in all_nums])

    return -min([smallest_exponent(u, v, w) for u, v, w in zip(U, V, W)])

def compute_sigma(coeffs, dims):
    ''' Compute sigma (in Bini et al. notation), which is defined as
 
            \sigma = min { z | e^{s}_{ij} = O(\epsilon^z) },

        where e^{s}_{ij} is an entry in the error tensor for the low-rank
        factorization of the tensor representing the bilinear form.
    '''

    m = dims[0]
    n = dims[1]
    k = dims[2]
    U = coeffs[0]
    V = coeffs[1]
    W = coeffs[2]

    # rank
    q = len(U[0])

    curr_smallest = None
    for a in range(m):
        for b in range(n):
            # a and b describe row of U
            rU = a * n + b
            for c in range(n):
                for d in range(k):
                    rV = c * k + d
                    for e in range(m):
                        for f in range(k):
                            rW = e * k + f
                            # compute the contribution
                            sum = Number("0")
                            for i in range(q):
                                sum += Number(U[rU][i]) * Number(V[rV][i]) * Number(W[rW][i])
                            errors = filter(lambda keyval: keyval[0] > 0 and keyval[1] != 0,
                                            sum.val.items())
                            listError = list(errors)
                            if len(listError) > 0:
                                smallest = min([keyval[0] for keyval in listError])
                                if curr_smallest == None or smallest < curr_smallest:
                                    curr_smallest = smallest

    return curr_smallest


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python stability_parameters.py coeff_file m,k,n')

    coeffs = read_coeffs(coeff_file)

    phi = compute_phi(coeffs)
    print('phi   =', phi)

    sigma = compute_sigma(coeffs, dims)
    print('sigma =', sigma)

    omega = 1.0 + float(phi) / sigma
    print('omega =', omega)

    # set bits of precision
    d = 24 # float
    prec = 'single'
    #d = 53 # double
    #prec = 'double'
    
    # One recursive step
    print('optimal lambda (1 recursive step)  = ', 2.0 ** -(d / (float(phi + sigma))))
    print('error (1 recursive step)           = ', 2.0 ** -(d / omega))

    # Two recursive steps
    phi *= 2
    omega = 1.0 + float(phi) / sigma
    print('optimal lambda (2 recursive steps) = ', 2.0 ** -(d / (float(phi + sigma))))
    print('error (2 recursive steps)          = ', 2.0 ** -(d / omega))
    
    # Note precision 
    print('\t\t....................... assuming ', prec, ' precision')

if __name__ == '__main__':
    main()
