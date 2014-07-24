#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include "linalg.hpp"
#ifdef _PARALLEL_
# include <omp.h>
# include "par_util.hpp"
#endif

#include <chrono>

#define _DFS_PAR_ 1
#define _BFS_PAR_ 2
#define _HYBRID_PAR_ 3

#endif  // _COMMON_HPP_
