
# for compiling on Mac with Accelerate framework
#CC = g++
#INCLUDES =  
#BLAS_LAPACK_LIB = -lblas -llapack

# for compiling with Intel compiler and MKL
# (to set MKLROOT: run mklvars.sh using command like
# source /opt/intel/composerxe/mkl/bin/mklvars.sh intel64) 
CC  := icc
CXX := icpc
LD  := icc
INCLUDES := -I$(MKLROOT)/include 
BLAS_LAPACK_LDFLAGS := -L$(MKLROOT)/lib
BLAS_LAPACK_LDLIBS  := -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread

#DEBUG := -g -O0 -Wall
DEBUG := -w3 -diag-disable 981 
OPT := -O3 -xCORE-AVX2
CFLAGS   := -std=c99   $(OPT) $(DEBUG) $(INCLUDES)
CXXFLAGS := -std=c++11 $(OPT) $(DEBUG) $(INCLUDES) 

LDFLAGS := $(BLAS_LAPACK_LDFLAGS)
LDLIBS  := $(BLAS_LAPACK_LDLIBS)

objects = fast-matmul-search_real.o kernels_real.o aux_real.o RandomMT.o RandomMT_C.o \
					fast-matmul-search_cplx.o kernels_cplx.o aux_cplx.o
targets = fast-matmul-search \
					fast-matmul-search_cplx 

.PHONY : default
default : all

.PHONY : all
all : $(targets)

fast-matmul-search      : fast-matmul-search_real.o kernels_real.o aux_real.o RandomMT.o RandomMT_C.o ; $(LD) $(LDFLAGS) $^ $(LDLIBS) -o $@
fast-matmul-search_cplx : fast-matmul-search_cplx.o kernels_cplx.o aux_cplx.o RandomMT.o RandomMT_C.o ; $(LD) $(LDFLAGS) $^ $(LDLIBS) -o $@

%_real.o : %.c   ; $(CC)  -c $(CFLAGS)         $< -o $@
%_cplx.o : %.c   ; $(CC)  -c $(CFLAGS) -DCPLX  $< -o $@
%.o      : %.cpp ; $(CXX) -c $(CXXFLAGS)       $< -o $@

.PHONY : clean
clean :
	rm -rf $(objects) $(targets) *~
