#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

import sys
from fractions import Fraction

'''
This is a script for verifying correctness of exact algorithms.
How to use this program:

  python verify.py 2 2 2 7 < algorithms/strassen
 
The output will include U/V/W matrices along with any errors.
No error information means the algorithm is correct.
'''

# the sizes; we check mxnxk matmul with q products, assuming row-major ordering.
m = int(sys.argv[1])
n = int(sys.argv[2])
k = int(sys.argv[3])
q = int(sys.argv[4])

# read in U,V,W
U = []
V = []
W = []
#for i in range(m*n):
#    U.append([])
#    V.append([])
#    W.append([])

for j in range(m*n):
    line = sys.stdin.readline().split()
    U.append([])
    while line[0] == "#":
        line = sys.stdin.readline().split()
    if len(line) != q:
        print("Trouble at line",j,"of U, should have",q,"entries, has",len(line))
    for i in range(q):
        U[j].append(Fraction(line[i]))

for j in range(n*k):
    line = sys.stdin.readline().split()
    V.append([])
    while line[0] == "#":
        line = sys.stdin.readline().split()
    if len(line) != q:
        print("Trouble at line",j,"of V, should have",q,"entries, has",len(line))
    for i in range(q):
        V[j].append(Fraction(line[i]))

for j in range(m*k):
    line = sys.stdin.readline().split()
    W.append([])
    while line[0] == "#":
        line = sys.stdin.readline().split()
    if len(line) != q:
        print("Trouble at line", j, "of W, should have", q, "entries, has", len(line))
    for i in range(q):
        W[j].append(Fraction(line[i]))

print("U")
for r in U:
    for e in r:
        print(e, end =" "),
    print()
print("V")
for r in V:
    for e in r:
        print(e, end =" "),
    print()
print("W")
for r in W:
    for e in r:
        print(e, end =" "),
    print()

#print "Ut"
#Ut = []
#for j in range(len(U[0])):
#    Ut.append([])
#    for i in range(len(U)):
#        Ut[j].append(U[i][j])
#for r in Ut:
#    print r

#print "Vt"
#Vt = []
#for j in range(len(V[0])):
#    Vt.append([])
#    for i in range(len(V)):
#        Vt[j].append(V[i][j])
#for r in Vt:
#    print r
    
#print "Wt"
#Wt = []
#for j in range(len(W[0])):
#    Wt.append([])
#    for i in range(len(W)):
#        Wt[j].append(W[i][j])
#for r in Wt:
#    print r


for a in range(m):
    for b in range(n):
        # a and b describe row of U
        rU = a*n+b
        for c in range(n):
            for d in range(k):
                rV = c*k+d
                for e in range(m):
                    for f in range(k):
                        rW = e*k+f
                        # compute the contribution
                        sum = 0
                        for i in range(q):
                            sum += U[rU][i]*V[rV][i]*W[rW][i]
                        if a == e and b == c and d == f:
                            # should be a 1
                            if sum != 1:
                                print("Trouble at", a, b, c, d, e, f, "sum should be 1, is ", sum)
                                print("\tcheck row",rU,"of U, row",rV,"of V, and row",rW,"of W")
                        else:
                            if sum != 0:
                                print("Trouble at", a, b, c, d, e, f, "sum should be 0, is ", sum)
                                print("\tcheck row",a*n+b,"of U, row",c*k+d,"of V, and row",e*k+f,"of W")
