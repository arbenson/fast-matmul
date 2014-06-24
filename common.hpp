#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include "linalg.hpp"
#ifdef _CILK_
# include <cilk/cilk.h>
#elif defined _OPEN_MP_
# include <omp.h>
#endif

#endif  // _COMMON_HPP_
