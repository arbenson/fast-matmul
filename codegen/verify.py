import sys

# the sizes; we check mxnxk matmul with q products, assuming row-major ordering.
m = int(sys.argv[1])
n = int(sys.argv[2])
k = int(sys.argv[3])
q = int(sys.argv[4])

# read in U,V,W
U = []
V = []
W = []
#for i in xrange(m*n):
#    U.append([])
#    V.append([])
#    W.append([])

for j in xrange(m*n):
    line = sys.stdin.readline().split()
    while line[0] == "#":
        line = sys.stdin.readline().split()
    U.append([])
    for i in xrange(q):
        U[j].append(int(line[i]))

for j in xrange(n*k):
    line = sys.stdin.readline().split()
    V.append([])
    while line[0] == "#":
        line = sys.stdin.readline().split()
    for i in xrange(q):
        V[j].append(int(line[i]))

for j in xrange(m*k):
    line = sys.stdin.readline().split()
    W.append([])
    while line[0] == "#":
        line = sys.stdin.readline().split()
    for i in xrange(q):
        W[j].append(int(line[i]))

print "U"
for r in U:
    print r
print "V"
for r in V:
    print r
print "W"
for r in W:
    print r
    
for a in xrange(m):
    for b in xrange(n):
        # a and b describe row of U
        rU = a*n+b
        for c in xrange(n):
            for d in xrange(k):
                rV = c*k+d
                for e in xrange(m):
                    for f in xrange(k):
                        rW = e*k+f
                        # compute the contribution
                        sum = 0
                        for i in xrange(q):
                            sum += U[rU][i]*V[rV][i]*W[rW][i]
                        if a == e and b == c and d == f:
                            # should be a 1
                            if sum != 1:
                                print "Trouble at", a, b, c, d, e, f, "sum should be 1, is ", sum
                        else:
                            if sum != 0:
                                print "Trouble at", a, b, c, d, e, f, "sum should be 0, is ", sum
