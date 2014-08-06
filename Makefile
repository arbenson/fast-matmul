#CXX = g++ 
CXX = icpc

MODE = sequential
#MODE = openmp

# for compiling with MKL
MKLROOT := /opt/intel/composer_xe_2013_sp1/mkl
INCLUDES := -I$(MKLROOT)/include -I./algorithms -I./linalg -I.
BLAS_LAPACK_LIB =  -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread
MKLPAR := -L$(MKLROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread -fopenmp

# for compiling with Linux BLAS
#BLAS_LAPACK_LIB = -L/usr/lib64/ -lblas

DEFINES := -D_INTEL_MKL_ -DNDEBUG
#DEFINES += -D_PARALLEL_=1  # DFS
#DEFINES += -D_PARALLEL_=2  # BFS
#DEFINES += -D_PARALLEL_=3  # HYBRID

#DEBUG := -g -Wall
OPT := -O3
CXXFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11 $(DEFINES)
#CXXFLAGS += -g

LDFLAGS := -O3

ifeq ($(MODE), openmp)
  CXXFLAGS += -fopenmp
  LDLIBS := $(MKLPAR)
else
  LDLIBS := $(BLAS_LAPACK_LIB)  
endif

vpath %.cpp examples benchmarks tests

EXAMPLES_SRC = bini322.cpp \
    classical.cpp \
    fast322.cpp \
    fast323.cpp \
    fast332.cpp \
    fast333.cpp \
    fast424.cpp \
    fast432.cpp \
    fast433.cpp \
    hk332.cpp \
    strassen.cpp \
    fast_lu.cpp \
    fast_qr.cpp

BENCHMARKS_SRC = matmul_benchmarks.cpp \
    add_benchmark.cpp \
    daxpy_benchmark.cpp \
    dgemm_curves.cpp \
    add_perf_benchmarks.cpp

TESTS_SRC = matmul_tests.cpp \
    fast_lu_test.cpp \
    fast_qr_test.cpp


OBJ_DIR = obj
OUTPUT_DIR = build
ALL_SRC = $(EXAMPLES_SRC) $(BENCHMARKS_SRC) $(TESTS_SRC)
OBJECTS = $(patsubst %.cpp, obj/%.o, $(ALL_SRC)) 
TARGETS = $(patsubst %.cpp, %, $(ALL_SRC))

$(OBJECTS): | obj build

obj:
	mkdir -p $(OBJ_DIR)

build:
	mkdir -p $(OUTPUT_DIR)

obj/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

% : obj/%.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $(OUTPUT_DIR)/$@

.PHONY : default all clean

default : all
all : $(TARGETS)
clean :
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR) out *~
