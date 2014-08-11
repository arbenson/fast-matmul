#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#define _DFS_PAR_ 1
#define _BFS_PAR_ 2
#define _HYBRID_PAR_ 3

#include "linalg.hpp"
#ifdef _PARALLEL_
# include <omp.h>
# include "par_util.hpp"
#endif

#include "options.hpp"
#include "timing.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i) {
	os << vec[i] << " ";
  }
  os << std::endl;
}


#endif  // _COMMON_HPP_
