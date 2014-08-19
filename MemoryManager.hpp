#ifndef _MEMORY_MANAGER_HPP_
#define _MEMORY_MANAGER_HPP_

#include <iostream>
#include <map>

enum {
  S = 0,
  T,
  M,
};

typedef std::tuple<int, int, int, int> MatrixKey;

template <typename Scalar>
class MemoryManager {
 public:
  MemoryManager() {}
  ~MemoryManager() {
    for (auto& kv : mem_map_) {
      delete [] kv.second;
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

  std::map<MatrixKey, Scalar *> mem_map_;
};

template <typename Scalar>
void MemoryManager<Scalar>::Allocate(int m, int k, int n, int num_mults, int num_levels,
			     int num_rows_A, int num_cols_A, int num_cols_B) {
  for (int level = 0; level < num_levels; ++level) {
    int size_M = Size(level, m, n, num_rows_A, num_cols_B);
    int size_S = Size(level, m, k, num_rows_A, num_cols_A);
    int size_T = Size(level, k, n, num_cols_A, num_cols_B);
    for (int i = 0; i < Pow(num_mults, level + 1); ++i) {
      int start_index = (i / num_mults) * num_mults;
      int mult = (i % num_mults) + 1;

      MatrixKey key_M(start_index, mult, level, M);
      mem_map_[key_M] = new Scalar[size_M];
      
      MatrixKey key_S(start_index, mult, level, S);
      mem_map_[key_S] = new Scalar[size_S];
      
      MatrixKey key_T(start_index, mult, level, T);
      mem_map_[key_T] = new Scalar[size_T];
    } 
  }
}

template <typename Scalar>  
Scalar *MemoryManager<Scalar>::GetMem(int start_index, int mult, int level, int type) {
  MatrixKey key(start_index, mult, level, type);
  auto mem_data = mem_map_.find(key);
  //std::cout << "Looking for: " << start_index << " " << mult << " " << level << " " << type << std::endl;
  assert(mem_data != mem_map_.end());
  return mem_data->second;
}


template <typename Scalar>  
int MemoryManager<Scalar>::Size(int level, int m, int n, int num_rows_A, int num_cols_B) {
  int num_rows = num_rows_A / Pow(m, level + 1);
  int num_cols = num_cols_B / Pow(n, level + 1);
  std::cout << num_rows << " " << num_cols << std::endl;
  return num_rows * num_cols;
}

template <typename Scalar>
int MemoryManager<Scalar>::Pow(int x, int b) {
  if (b == 0) { return 1; }
  return  x * Pow(x, b - 1);
}

#endif  // _MEMORY_MANAGER_HPP_
