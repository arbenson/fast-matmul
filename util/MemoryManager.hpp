/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#ifndef _MEMORY_MANAGER_HPP_
#define _MEMORY_MANAGER_HPP_

#include <iostream>
#include <vector>

enum {
  S = 0,
  T,
  M,
};

template <typename Scalar>
class MemoryManager {
 public:
  MemoryManager() {}
  ~MemoryManager() {
	for (auto level_vec : M_mem) {
	  for (Scalar *data : level_vec) {
		delete [] data;
	  }
	}

	for (auto level_vec : S_mem) {
	  for (Scalar *data : level_vec) {
		delete [] data;
	  }
	}

	for (auto level_vec : T_mem) {
	  for (Scalar *data : level_vec) {
		delete [] data;
	  }
	}
  }

  // Allocate all of the memory for the <m, k, n> algorithm with rank equal
  // to num_mults.  num_levels is the number of recursive levels.
  // The size of the problem is num_rows_A * num_cols_A * num_cols_B
  void Allocate(int m, int k, int n, int num_mults, int num_levels,
		int num_rows_A, int num_cols_A, int num_cols_B);

  Scalar *GetMem(int start_index, int mult, int level, int type);

 private:
  int Size(int level, int m, int n, int num_rows_A, int num_cols_B);
  // Integer version of x ^ b
  int Pow(int x, int b);

  std::vector< std::vector<Scalar *> > M_mem;
  std::vector< std::vector<Scalar *> > S_mem;
  std::vector< std::vector<Scalar *> > T_mem;
};

template <typename Scalar>
void MemoryManager<Scalar>::Allocate(int m, int k, int n, int num_mults, int num_levels,
			     int num_rows_A, int num_cols_A, int num_cols_B) {
  
  M_mem.resize(num_levels);
  S_mem.resize(num_levels);
  T_mem.resize(num_levels);

  for (int level = 0; level < num_levels; ++level) {
    int size_M = Size(level, m, n, num_rows_A, num_cols_B);
    int size_S = Size(level, m, k, num_rows_A, num_cols_A);
    int size_T = Size(level, k, n, num_cols_A, num_cols_B);
	
	int mults_at_level = Pow(num_mults, level + 1);
	M_mem[level].resize(mults_at_level);
	S_mem[level].resize(mults_at_level);
	T_mem[level].resize(mults_at_level);

    for (int i = 0; i < mults_at_level; ++i) {
	  M_mem[level][i] = new Scalar[size_M];
	  S_mem[level][i] = new Scalar[size_S];
	  T_mem[level][i] = new Scalar[size_T];
    } 
  }
}

template <typename Scalar>  
Scalar *MemoryManager<Scalar>::GetMem(int start_index, int mult, int level, int type) {
  switch (type) {
  case M:
	return M_mem[level][start_index + mult - 1];
  case S:
	return S_mem[level][start_index + mult - 1];
  case T:
	return T_mem[level][start_index + mult - 1];
  default:
	return NULL;
  }
}


template <typename Scalar>
int MemoryManager<Scalar>::Size(int level, int m, int n, int num_rows_A, int num_cols_B) {
  int num_rows = num_rows_A / Pow(m, level + 1);
  int num_cols = num_cols_B / Pow(n, level + 1);
  return num_rows * num_cols;
}

template <typename Scalar>
int MemoryManager<Scalar>::Pow(int x, int b) {
  if (b == 0) { return 1; }
  return  x * Pow(x, b - 1);
}

#endif  // _MEMORY_MANAGER_HPP_
