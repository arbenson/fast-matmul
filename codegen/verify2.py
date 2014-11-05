import sys
from collections import defaultdict

# holds a polynomial in epsilon over integers (could be changed to floats pretty easily)
# internal storage is a dict from powers of epsilon to coefficients
class Number:
    def __init__( self, arg1, arg2=None ):
        self.orig = arg1
        self.val = defaultdict(lambda:0)
        if arg2 == None:
            if type(arg1) == type( "1" ):
                # one argument, string constructor
                try:
                    self.val[0] = int(arg1)
                except:
                    if arg1 == "x":
                        self.val[1] = 1
                    elif arg1 == "xi":
                        self.val[-1] = 1
                    elif arg1 == "-x":
                        self.val[1] = -1
                    elif arg1 == "-xi":
                        self.val[-1] = -1
                    elif arg1 == "x2":
                        self.val[2] = 1
                    elif arg1 == "-x2":
                        self.val[2] = -1
                    elif arg1 == "x2i":
                        self.val[-2] = 1
                    elif arg1 == "-x2i":
                        self.val[-2] = -1
                    elif arg1 == "-2x2":
                        self.val[2] = -2
                    elif arg1 == "x3":
                        self.val[3] = 1
                    elif arg1 == "-x3":
                        self.val[3] = -1
                    elif arg1 == "2x3":
                        self.val[3] = 2
                    elif arg1 == "-2x3":
                        self.val[3] = -2
                    elif arg1 == "x4":
                        self.val[4] = 1
                    elif arg1 == "(1+-x3)":
                        self.val[0] = 1
                        self.val[3] = -1
                    elif arg1 == "(1+x2)":
                        self.val[0] = 1
                        self.val[2] = 1
                    elif arg1 == "(x+x2)":
                        self.val[1] = 1
                        self.val[2] = 1
                    elif arg1 == "(x2+x3)":
                        self.val[2] = 1
                        self.val[3] = 1
                    elif arg1 == "(x+-x2)":
                        self.val[1] = 1
                        self.val[2] = -1
                    elif arg1 == "(-x2+-x3)":
                        self.val[2] = -1
                        self.val[3] = -1
                    elif arg1 == "(-x+x2)":
                        self.val[1] = -1
                        self.val[2] = 1
                    elif arg1 == "(x+-x4)":
                        self.val[1] = 1
                        self.val[4] = -1
                    else:
                        print "Not supported", arg1
                        raise NotImplemented
            elif type(arg1) == type(defaultdict(lambda:0)):
                # one argument, dict constructor
                self.val = arg1
            else:
                raise NotImplemented
        else:
            # two argument constructor
            assert( type(arg1) == type(1) )
            assert( type(arg2) == type(1) )
            self.val[arg2]=arg1
    def __add__( self, other ):
        newVal = defaultdict(lambda:0)
        for p in self.val:
            newVal[p] += self.val[p]
        for p in other.val:
            newVal[p] += other.val[p]
        return Number(newVal)
    def __mul__( self, other ):
        newVal = defaultdict(lambda:0)
        for p1 in self.val:
            for p2 in other.val:
                newVal[p1+p2] += self.val[p1] * other.val[p2]
        return Number(newVal)
    def __eq__( self, other ):
        for p in self.val:
            if p <= 0:
                if self.val[p] != other.val[p]:
                    return False
        for p in other.val:
            if p <= 0:
                if self.val[p] != other.val[p]:
                    return False
        return True
    def __ne__( self, other ):
        return not (self == other)
    def exacteq( self, other ):
        for p in self.val:
            if self.val[p] != other.val[p]:
                return False
        for p in other.val:
            if self.val[p] != other.val[p]:
                return False
        return True
        
    def __repr__(self):
        # assume it is simple
        if self.exacteq(Number("0")):
            return "0"
        if self.exacteq(Number("1")):
            return "1"
        if self.exacteq(Number("-1")):
            return "-1"
        if self.exacteq(Number("x")):
            return "x"
        if self.exacteq(Number("-x")):
            return "-x"
        if self.exacteq(Number("xi")):
            return "xi"
        if self.exacteq(Number("-xi")):
            return "-xi"
        if self.exacteq(Number("x2")):
            return "x2"
        if self.exacteq(Number("-x2")):
            return "-x2"
        if self.exacteq(Number("x2i")):
            return "x2i"
        if self.exacteq(Number("-x2i")):
            return "-x2i"
        return str(self.orig)


def main():        
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
	
	nnz = 0
	
	for j in xrange(m*n):
	    line = sys.stdin.readline().split()
	    while line[0] == "#":
	        line = sys.stdin.readline().split()
	    U.append([])
	    for i in xrange(q):
	        U[j].append(Number(line[i]))
	        if line[i] != "0":
	            nnz += 1
	
	for j in xrange(n*k):
	    line = sys.stdin.readline().split()
	    while line[0] == "#":
	        line = sys.stdin.readline().split()
	    V.append([])
	    for i in xrange(q):
	        V[j].append(Number(line[i]))
	        if line[i] != "0":
	            nnz += 1
	
	for j in xrange(m*k):
	    line = sys.stdin.readline().split()
	    while line[0] == "#":
	        line = sys.stdin.readline().split()
	    W.append([])
	    for i in xrange(q):
	        W[j].append(Number(line[i]))
	        if line[i] != "0":
	            nnz += 1
	
	print "U"
	for r in U:
	    print r
	print "V"
	for r in V:
	    print r
	print "W"
	for r in W:
	    print r
	print "Naive number of additions:", nnz-len(U[0])-len(V[0])-len(W)
	
	def isConnected(M):
	    def add(s, r):
	        for i in xrange(len(r)):
	            if not r[i].exacteq(Number("0")):
	                s.add(i)
	    def overlap(s, r):
	        for i in xrange(len(r)):
	            if (not r[i].exacteq(Number("0"))) and i in s:
	                return True
	        return False
	    current = set()
	    add(current, M[0])
	    while True:
	        sOld = len(current)
	        for j in xrange(len(M)):
	            if overlap(current,M[j]):
	                add(current,M[j])
	        if len(current) == sOld:
	            break
	    if len(current) == len(M[0]):
	        return True
	    return False
	
	if not isConnected(U):
	    print "U is disconnected"
	if not isConnected(V):
	    print "V is disconnected"
	if not isConnected(W):
	    print "W is disconnected"
	    
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
	                        sum = Number("0")
	                        for i in xrange(q):
	                            sum += U[rU][i]*V[rV][i]*W[rW][i]
	                        if a == e and b == c and d == f:
	                            # should be a 1
	                            if sum != Number("1"):
	                                print "Trouble at", a, b, c, d, e, f, "sum should be 1, is ", sum
	                        else:
	                            if sum != Number("0"):
	                                print "Trouble at", a, b, c, d, e, f, "sum should be 0, is ", sum

if __name__ == '__main__':
    main()
