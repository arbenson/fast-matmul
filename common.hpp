#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include "linalg.hpp"
#ifdef _CILK_
# include <cilk/cilk.h>
#elif defined(_BFS_PAR_) || defined(_DFS_PAR_) || defined(_HYBRID_PAR_)
# include <omp.h>
# include "par_util.hpp"
#endif

#endif  // _COMMON_HPP_
