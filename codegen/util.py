def parse_coeff(coeff):
    ''' Parse a coefficient. The grammar is:
        
        * --> *i | -* | *p | [a-z] | [floating point number]
        p --> 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
        *i --> 1 / (*)
        -* --> -(*)
        *p --> (*)^p

        So -x2i is parsed as - (1 / ((x)^2))
    '''
    coeff = coeff.strip()
    # First try to convert to float
    try:
        coeff = float(coeff)
        return coeff
    except:
        pass
    
    # Parameterized coefficient
    if len(coeff) == 1:
        # Coeff is like 'x'.  We will use 'x' instead of whatever is provided.
        # For now, this means that we only support one paramterized coefficient.
        return 'x'
    elif coeff[0] == '-':
        return '-(%s)' % parse_coeff(coeff[1:])
    elif coeff[-1] == 'i':
        return '1.0 / (%s)' % parse_coeff(coeff[:-1])
    else:
        try:
            exp = float(coeff[-1])
            return ('(%s)' % parse_coeff(coeff[:-1])) * exp
        except:
            raise Exception('Cannot parse coefficient: %s' % coeff)


def read_coeffs(filename):
    ''' Read the coefficient file.  There is one group of coefficients for each
    of the three matrices.  '''
    coeffs = []
    with open(filename, 'r') as coeff_file:
        curr_group = []
        for line in coeff_file:
            if line[0] == '#':
                if len(curr_group) > 0:
                    coeffs.append(curr_group)
                    curr_group = []
            else:
                curr_group.append([parse_coeff(val) for val in line.split()])
    coeffs.append(curr_group)
    # There should be three sets of coefficients: one for each matrix.
    if (len(coeffs) != 3):
        raise Exception('Expected three sets of coefficients!')
    return coeffs
