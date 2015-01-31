#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

import sys

'''
This is a script to parse the output of Madan's SAT solver and write the
algorithms to file.
'''

def flush(algorithm, ind):
    ''' Save the algorithm to file. '''
    assert(len(alg) == 16)
    U = algorithm[0:6]
    V = algorithm[6:12]
    W = algorithm[12:16]
    with open('madan232-11-SAT-%02d' % ind, 'w') as f:
        f.write("# Madan's 2x3x2 rank 11 solution from SAT Solver\n")
        for line in U:
            f.write(' '.join(line) + '\n')
        f.write('#\n')
        for line in V:
            f.write(' '.join(line) + '\n')
        f.write('#\n')
        for line in W:
            f.write(' '.join(line) + '\n')

sol_flag = False
alg = []
ctr = 0

for line in sys.stdin:
    if line[0] == line[1] == ' ':
        sol_flag = True
        alg.append([x for x in line.strip().split()])
    elif len(line) == 2:
        sol_flag = True
    else:
        if sol_flag == True:
            flush(alg, ctr)
            ctr += 1
            alg = []
        sol_flag = False

