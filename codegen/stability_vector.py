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

def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python stability_vector.py coeff_file m,k,n')

    coeffs = read_coeffs(coeff_file)

    # Using the notation of the Bini and Lotti and Demmel et al.
    a_vec = [num_nonzero(row) for row in transpose(coeffs[0])]
    b_vec = [num_nonzero(row) for row in transpose(coeffs[1])]
    c_vec = [num_nonzero(row) for row in coeffs[2]]

    
    # Max norms of the coefficient matrices.
    U_max_norm = max_norm(coeffs[0])
    V_max_norm = max_norm(coeffs[1])
    W_max_norm = max_norm(coeffs[2])
    print '|| U || = ', U_max_norm
    print '|| V || = ', V_max_norm
    print '|| W || = ', W_max_norm
    nu = U_max_norm * V_max_norm * W_max_norm
    print 'nu     := || U || || V || || W ||'
    print 'nu      = ', nu
    print ''

    alphas = np.ceil(np.log2(a_vec))
    betas  = np.ceil(np.log2(b_vec))
    gammas = np.ceil(np.log2(c_vec))

    eta = 3 + int(np.max(alphas + betas) + np.max(gammas))
    print 'eta := 3 + max_{r, s} alpha_s + beta_s + gamma_r'
    print 'eta  =', eta 


    def stability(row):
        val = 0
        for i, coeff in enumerate(row):
            if is_nonzero(coeff):
                val += a_vec[i] * b_vec[i]
        return val

    e_vec = [stability(row) for row in coeffs[2]]
    # emax is the same as omega in Bini and Lotti
    emax = max(e_vec)
    print 'emax =', emax
    print ''

    print '|| C_{comp} - C || \le mu(n) * ||A|| || B|| epsilon + O(epsilon^2)'
    print 'mu(n) = (n ./ (%d .^ L) + %d * L) .* (%d) .^ L' % (dims[1], eta, emax * nu)
    print '(n is inner dimension)'
    print ''

    # Print in the same style as D'Alberto presents in his 2014 paper.
    print 'stability vector:'
    for i in range(dims[0]):
        out_format = '\t' + ' '.join(['%4d' for _ in range(dims[2])])
        vals = e_vec[(i * dims[2]):(i * dims[2] + dims[2])]
        print out_format % tuple(vals)

    # The stability factor that goes in the exponent of the accuracy bound
    # is just the maximum value of the stability vector.
    
if __name__ == '__main__':
    main()
