
# for compiling on Mac with Accelerate framework
CC = g++
INCLUDES = -DMAC -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/Headers/
BLAS_LAPACK_LIB = -lblas -llapack

# for compiling with Intel compiler and MKL
#CC = icc
#INCLUDES := -I$(MKLROOT)/include -DMKL
#BLAS_LAPACK_LIB = -L$(MKLROOT)/lib/em64t -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread

DEBUG := -g -O0 -Wall
#OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES)

LDFLAGS := 
LDLIBS := $(BLAS_LAPACK_LIB)

objects = fast-matmul-search.o kernels.o aux.o RandomMT.o
targets = fast-matmul-search

.PHONY : default
default : all

.PHONY : all
all : $(targets)

fast-matmul-search : fast-matmul-search.o kernels.o aux.o RandomMT.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean :
	rm -rf $(objects) $(targets) *~
