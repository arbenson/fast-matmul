CC = g++ 
#CC = icpc

MODE = sequential
MODE = cilk
MODE = openmp

# for compiling with MKL
MKLROOT := /opt/intel/composer_xe_2013_sp1/mkl
INCLUDES := -I$(MKLROOT)/include
BLAS_LAPACK_LIB =  -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread  

# for compiling with Linux BLAS
BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

#DEBUG := -g -O0 -Wall
OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11
ifeq ($(MODE), cilk)
  CFLAGS += -D_CILK_
else ifeq ($(MODE), openmp)
  CFLAGS += -D_OPEN_MP_
endif

LDFLAGS := 
LDLIBS := $(BLAS_LAPACK_LIB) -lm 
ifeq ($(MODE), openmp)
  LDLIBS += -fopenmp
endif

objects = dgemm_curve.o fast333.o strassen.o fast332.o bini332.o
targets = dgemm_curve fast333 strassen fast332 bini332

.PHONY : default
default : all

.PHONY : all
all : $(targets)

dgemm_curve: dgemm_curve.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast333: fast333.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

strassen: strassen.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast332: fast332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

bini332: bini332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean :
	rm -rf $(objects) $(targets) *~
