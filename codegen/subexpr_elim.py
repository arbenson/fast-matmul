import convert

def all_pairs(col):
    ''' Return all pairs in column, where the column refers to the rank multiply.
    col is an array of coefficients. '''
    for i in range(len(col)):
        for j in range(i + 1, len(col)):
            if col[i] != '0' and col[j] != '0':
                yield ((col[i], col[j]), (i, j))


def can_substitute(val_pair1, val_pair2):
    ''' Returns true if and only if the two pairs can be replaced by a single multiply. '''
    try:
        val1a = float(val_pair1[0])
        val1b = float(val_pair1[1])
        val2a = float(val_pair2[0])
        val2b = float(val_pair2[1])
    except:
        return False

    # Can't match zeros
    if val2a == 0.0 or val2b == 0.0:
        return False

    scale1 = val1b / val1a
    scale2 = val2b / val2a

    if abs(scale1 - scale2) <= 1e-15:
        return True
    
        

def find_subexpression(pair, col):
    ''' Find occurence of the pair subexpression in the column '''
    ind1, ind2 = pair[1]
    curr_val = (col[ind1], col[ind2])
    return can_substitute(pair[0], curr_val)


def eliminate(coeff_set, m, n, elim_cols=True):
    # Turn into column form
    rank = len(coeff_set[0])
    cols = [[x[i] for x in coeff_set] for i in range(rank)]
    match_dict = {}

    for i, col in enumerate(cols):
        for pair in all_pairs(col):
            for j in range(i + 1, len(cols)):
                if find_subexpression(pair, cols[j]):
                    # Hash the mapping by pair index (tuple) and the subcomputation where the
                    # subexpression originates
                    key = (pair[1][0], pair[1][1], i)
                    if key in match_dict:
                        match_dict[key].append(j)
                    else:
                        match_dict[key] = [j]

    print match_dict


def main():
    try:
        coeff_file = sys.argv[1]
        dims = tuple([int(d) for d in sys.argv[2].split(',')])
        print 'Reading coefficients for %d x %d x %d matrix' % dims
    except:
        raise Exception('USAGE: python subexpr_elim.py coeff_file m,k,n out_file')

    coeffs = convert.read_coeffs(sys.argv[1])
    A_dict = eliminate(coeffs[0], dims[0], dims[1])
    B_dict = eliminate(coeffs[1], dims[0], dims[1])


if __name__ == '__main__':
    main()
