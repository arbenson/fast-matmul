CC = g++ 
CC = icpc

MODE = sequential
#MODE = cilk
#MODE = openmp

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

SRC = bini332.cpp \
      classical.cpp \
      dgemm_curve_par.cpp \
      fast333.cpp \
      grey-fast322.cpp \
      grey-fast332.cpp \
      grey-fast333.cpp \
      grey-fast432.cpp \
      grey-fast433.cpp \
      hk332.cpp \
      strassen.cpp

OBJECTS = $(SRC:.cpp=.o)
TARGETS = $(OBJECTS:.o=)

.PHONY : default
default : all

.PHONY : all
all : $(TARGETS)

#benchmark: benchmark.o
#	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

bini332: bini332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

classical: classical.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

#dgemm_curve: dgemm_curve.o
#	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

dgemm_curve_par: dgemm_curve_par.o
	$(CC) $(LDFLAGS) $^ $(MKLPAR) -o $@

fast333: fast333.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

grey-fast322: grey-fast322.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

grey-fast332: grey-fast332.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

grey-fast333: grey-fast333.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

grey-fast432: grey-fast432.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

grey-fast433: grey-fast433.o
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
