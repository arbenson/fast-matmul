CC = g++ 
CC = icpc

MODE = sequential
#MODE = cilk
MODE = openmp

# for compiling with MKL
MKLROOT := /opt/intel/composer_xe_2013_sp1/mkl
INCLUDES := -I$(MKLROOT)/include
BLAS_LAPACK_LIB =  -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread  
MKLPAR := -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread -lm

# for compiling with Linux BLAS
#BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

#DEBUG := -g -O0 -Wall
OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11
ifeq ($(MODE), cilk)
  CFLAGS += -D_CILK_
else ifeq ($(MODE), openmp)
  CFLAGS += -D_OPEN_MP_ -fopenmp
endif

LDFLAGS := 
LDLIBS := $(BLAS_LAPACK_LIB) -lm 
ifeq ($(MODE), openmp)
  LDLIBS += -fopenmp
endif

SRC = dgemm_curve.cpp dgemm_curve_par.cpp fast333.cpp strassen.cpp fast332.cpp bini332.cpp
OBJECTS = $(SRC:.cpp=.o)
TARGETS = $(OBJECTS:.o=)


.PHONY : default
default : all

.PHONY : all
all : $(TARGETS)

dgemm_curve: dgemm_curve.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

dgemm_curve_par: dgemm_curve_par.o
	$(CC) $(LDFLAGS) $^ $(MKLPAR) -o $@

benchmark: benchmark.o
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
	rm -rf $(OBJECTS) $(TARGETS) *~
