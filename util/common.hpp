/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#define _DFS_PAR_ 1
#define _BFS_PAR_ 2
#define _HYBRID_PAR_ 3

#include "MemoryManager.hpp"
#include "linalg.hpp"
#ifdef _PARALLEL_
# include "omp.h"
#endif
#include "par_util.hpp"


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
