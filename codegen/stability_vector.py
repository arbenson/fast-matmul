import convert
import gen
import subexpr_elim
import sys

'''
This script takes a coefficient file (not eliminated) and computes the
stability vector as described by Bini and Lotti in their 1980 paper
"Stability of Fast Algorithms for Matrix Multiplication".  Example usage:

    python stability_vector.py algorithms/grey333-23-221 3,3,3
'''

def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
    except:
        raise Exception('USAGE: python counts.py coeff_file m,k,n')

    coeffs = convert.read_coeffs(coeff_file)

    # Using the notation of the Bini and Lottis paper
    a_vec = [gen.num_nonzero(row) for row in subexpr_elim.transpose(coeffs[0])]
    b_vec = [gen.num_nonzero(row) for row in subexpr_elim.transpose(coeffs[1])]

    def stability(row):
        val = 0
        for i, coeff in enumerate(row):
            if gen.is_nonzero(coeff):
                val += a_vec[i] * b_vec[i]
        return val

    e_vec = [stability(row) for row in coeffs[2]]

    # Print in the same style as D'Alberto presents in his 2014 paper.
    print 'stability vector:'
    for i in range(dims[0]):
        out_format = '\t' + ' '.join(['%4d' for _ in range(dims[2])])
        vals = e_vec[(i * dims[2]):(i * dims[2] + dims[2])]
        print out_format % tuple(vals)

    # The stability factor that goes in the exponent of the accuracy bound
    # is just the maximum value of the stability vector.
    omega = max(e_vec)
    print ''
    print 'stability factor:'
    print '\t %d' % omega
    
    
if __name__ == '__main__':
    main()
