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

class Writer:
    def __init__(self):
        self.ctr = 0

    def flush_alg(self, algorithm):
        ''' Save the algorithm to file. '''
        if len(algorithm) != 16:
            for line in algorithm:
                print line
        assert(len(algorithm) == 16)
        U = algorithm[0:6]
        V = algorithm[6:12]
        W = algorithm[12:16]
        with open('madan232-11-SAT-%d' % self.ctr, 'w') as f:
            f.write("# Madan's 2x3x2 rank 11 solution from SAT Solver\n")
            for line in U:
                f.write(' '.join(line) + '\n')
            f.write('#\n')
            for line in V:
                f.write(' '.join(line) + '\n')
            f.write('#\n')
            for line in W:
                f.write(' '.join(line) + '\n')
        self.ctr += 1

    def flush_packet(self, packet):
        alg = []
        for line in packet:
            if line[0] == ' ' and line[1] == ' ':
                alg.append([x for x in line.strip().split()])

            # The solution in Z_2 could not be extended to Z_4.
            if line.find('UNSAT') != -1:
                return

        self.flush_alg(alg)

writer = Writer()
packet = []
started = False

for i, line in enumerate(sys.stdin):
    # skip the first line
    if i == 0:
        continue
    
    # start / end of packet
    if line[0] == '=' and line[1] == '-':
        if started:
            writer.flush_packet(packet)
            packet = []
            started = False
        else:
            started = True
    else:
        packet.append(line)

'''
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
'''
