CXX = icpc

#MODE = sequential
MODE = openmp

# for compiling with MKL
MKL_ROOT := /opt/intel/composer_xe_2013.5.192/mkl
INCLUDES := -I$(MKL_ROOT)/include -I./algorithms -I./linalg -I.
MKL_SEQ_LIBS =  $(MKL)
MKL_PAR_LIBS := -L$(MKL_ROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread

DEFINES := -DNDEBUG
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
  LDLIBS := -fopenmp $(MKL_PAR_LIBS) -fopenmp
else
  LDLIBS := $(MKL_SEQ_LIBS) 
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
    cse_add_perf_benchmarks.cpp \
    simple_dgemm.cpp	

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

matmul_bench_dfs: matmul_benchmarks.cpp
	$(CXX) $(CXXFLAGS) -D_PARALLEL_=1 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

matmul_bench_bfs: matmul_benchmarks.cpp
	$(CXX) $(CXXFLAGS) -D_PARALLEL_=2 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

matmul_bench_hybrid: matmul_benchmarks.cpp
	$(CXX) $(CXXFLAGS) -D_PARALLEL_=3 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

obj/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

% : obj/%.o
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $(OUTPUT_DIR)/$@

.PHONY : default all clean

default : all
all : $(TARGETS)
clean :
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR) out *~
