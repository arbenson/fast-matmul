CC = g++ 
CC = icpc

MODE = sequential
MODE = openmp

# for compiling with MKL
MKLROOT := /opt/intel/composer_xe_2013_sp1/mkl
INCLUDES := -I$(MKLROOT)/include -I./algorithms -I./linalg -I.
BLAS_LAPACK_LIB =  -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread
MKLPAR := -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread -fopenmp

# for compiling with Linux BLAS
#BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

DEFINES := -D_INTEL_MKL_ -DNDEBUG
#DEFINES += -D_DFS_PAR_
#DEFINES += -D_BFS_PAR_
#DEFINES += -D_HYBRID_PAR_

#DEBUG := -g -Wall
OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11 $(DEFINES)
#CFLAGS += -g

LDFLAGS := -O3


ifeq ($(MODE), openmp)
  CFLAGS += -fopenmp
  LDLIBS := $(MKLPAR)
else
  LDLIBS := $(BLAS_LAPACK_LIB)  
endif

SRC = benchmark.cpp \
      add_benchmark.cpp \
      daxpy_benchmark.cpp \
      bini322.cpp \
      classical.cpp \
      dgemm_curve_par.cpp \
      fast322.cpp \
      fast323.cpp \
      fast332.cpp \
      fast333.cpp \
      fast424.cpp \
      fast432.cpp \
      fast433.cpp \
      hk332.cpp \
      strassen.cpp \
      fast_lu.cpp

OBJECTS = $(SRC:.cpp=.o)
TARGETS = $(OBJECTS:.o=)

.PHONY : default
default : all

.PHONY : all
all : $(TARGETS)

par_util_test: par_util_test.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast_lu: fast_lu.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

add_benchmark: add_benchmark.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

daxpy_benchmark: daxpy_benchmark.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

benchmark: benchmark.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

benchmark_par: benchmark_par.o
	$(CC) $(LDFLAGS) $^ $(MKLPAR) -o $@

bini322: bini322.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

classical: classical.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

dgemm_curve: dgemm_curve.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

dgemm_curve_par: dgemm_curve_par.o
	$(CC) $(LDFLAGS) $^ $(MKLPAR) -o $@

fast322: fast322.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast323: fast323.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast332: fast332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast333: fast333.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast424: fast424.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast432: fast432.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

fast433: fast433.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

hk332: hk332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

strassen: strassen.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@


%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean :
	rm -rf $(OBJECTS) $(TARGETS) *~
