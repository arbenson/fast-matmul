CC = g++ 
CC = icpc

MODE = sequential
#MODE = cilk
#MODE = openmp

# for compiling with MKL
MKLROOT := /opt/intel/composer_xe_2013_sp1/mkl
INCLUDES := -I$(MKLROOT)/include -I./algorithms -I.
BLAS_LAPACK_LIB =  -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread
MKLPAR := -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread

# for compiling with Linux BLAS
#BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

#DEBUG := -g -O0 -Wall
OPT := -O3
CFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11 -DNDEBUG
#CFLAGS += -g

ifeq ($(MODE), cilk)
  CFLAGS += -D_CILK_
else ifeq ($(MODE), openmp)
  CFLAGS += -D_OPEN_MP_ -D_OPEN_MP_ADDS_ -fopenmp
endif

LDFLAGS := -O3
LDLIBS := $(BLAS_LAPACK_LIB)
ifeq ($(MODE), openmp)
  LDLIBS += -fopenmp
endif

SRC = benchmark.cpp \
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
      strassen.cpp

OBJECTS = $(SRC:.cpp=.o)
TARGETS = $(OBJECTS:.o=)

.PHONY : default
default : all

.PHONY : all
all : $(TARGETS)

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
