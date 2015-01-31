#   Copyright (c) 2014-2015, Sandia Corporation
#   All rights reserved.
#
#   This file is part of fast-matmul and is under the BSD 2-Clause License, 
#   which can be found in the LICENSE file in the root directory, or at 
#   http://opensource.org/licenses/BSD-2-Clause.

include make.incs/make.inc.linux

INCLUDES := -I$(MKL_ROOT)/include -I./algorithms -I./linalg -I./util -I./scaling
MKL_SEQ_LIBS =  -L$(MKL_ROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread
MKL_PAR_LIBS := -L$(MKL_ROOT)/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lpthread

OPT := -O3
CXXFLAGS := $(OPT) $(DEBUG) $(INCLUDES) -std=c++11
#CXXFLAGS += -g

LDFLAGS := -O3

ifeq ($(MODE), openmp)
  CXXFLAGS += -fopenmp
  LDLIBS := $(MKL_PAR_LIBS) -fopenmp
else
  LDLIBS := $(MKL_SEQ_LIBS) 
endif

vpath %.cpp examples benchmarks tests scaling

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
    schonhage333.cpp \
    fast_lu.cpp \
    fast_qr.cpp

BENCHMARKS_SRC = matmul_benchmarks.cpp \
    add_benchmark.cpp \
    daxpy_benchmark.cpp \
    dgemm_curves.cpp \
    cse_add_perf_benchmarks.cpp \
    simple_dgemm.cpp \
    square54_benchmark.cpp

TESTS_SRC = matmul_tests.cpp \
    bini_stability.cpp \
    schonhage_stability.cpp \
    smirnov333_stability.cpp \
    strassen_scaling.cpp \
    strassen_bad_case.cpp \
    fast_scaling.cpp


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

matmul_bench_dfs: matmul_benchmarks.cpp build
	$(CXX) $(CXXFLAGS) -fopenmp -DNDEBUG -D_PARALLEL_=1 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

matmul_bench_bfs: matmul_benchmarks.cpp build
	$(CXX) $(CXXFLAGS) -fopenmp -DNDEBUG -D_PARALLEL_=2 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

matmul_bench_hybrid: matmul_benchmarks.cpp build
	$(CXX) $(CXXFLAGS) -fopenmp -DNDEBUG -D_PARALLEL_=3 $< $(MKL_PAR_LIBS) -o $(OUTPUT_DIR)/$@

obj/%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(DEFINES) -c $< -o $@

% : obj/%.o
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $(OUTPUT_DIR)/$@

.PHONY : default all clean

default : all
all : $(TARGETS)
clean :
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR) out *~
