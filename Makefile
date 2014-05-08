CC = g++ 

MODE = sequential
#MODE = cilk

ifeq ($(MODE), cilk)
  CC = icpc
endif

# for compiling with MKL
#MKLROOT := /opt/intel/Compiler/11.1/064/mkl
#INCLUDES := -I$(MKLROOT)/include
#BLAS_LAPACK_LIB = -L$(MKLROOT)/lib/em64t -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread

# for compiling with Linux BLAS
BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

#DEBUG := -g -O0 -Wall
OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++0x
ifeq ($(MODE), cilk)
  CFLAGS += -D_CILK_
endif

LDFLAGS := 
LDLIBS := $(BLAS_LAPACK_LIB) -lm 

objects = dgemm_curve.o main.o strassen.o fast3x3x2.o
targets = dgemm_curve test strassen fast332

.PHONY : default
default : all

.PHONY : all
all : $(targets)

dgemm_curve: dgemm_curve.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

test: main.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

strassen: strassen.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast332: fast332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean :
	rm -rf $(objects) $(targets) *~
