#include "common.hpp"
#include "daxpy_pairwise_adds.hpp"
#include "linalg.hpp"
#include "manual_pairwise_adds.hpp"
#include "timing.hpp"

#include "mkl.h"

#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <random>
#include <vector>

enum {
  ADD = 0,
  DAXPY_ADD,
  SLOW_ADD,
};

void add_call(Matrix<double>& C, std::vector< Matrix<double>* >& A, int add_type) {
  std::vector<double> alpha(A.size());
  for (int i = 0; i < alpha.size(); ++i) {
    if (i % 3 == 0) {
      alpha[i] = 1.0;
    } else if (i % 3 == 1) {
      alpha[i] = -1.0;
    } else {
      alpha[i] = 0.25;
    }
  }
  switch (A.size()) {
  case 1:
    switch (add_type) {
    case ADD:
      Add(*A[0], 
          alpha[0], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], 
              alpha[0], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], 
               alpha[0], C);
      break;
    }

    break;
  case 2:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], 
          alpha[0], alpha[1], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], 
              alpha[0], alpha[1], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], 
               alpha[0], alpha[1], C);
      break;
    }

    break;
  case 3:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], 
          alpha[0], alpha[1], alpha[2], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], 
              alpha[0], alpha[1], alpha[2], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], 
               alpha[0], alpha[1], alpha[2], C);
      break;
    }

    break;
  case 4:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], 
          alpha[0], alpha[1], alpha[2], alpha[3], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], 
              alpha[0], alpha[1], alpha[2], alpha[3], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], 
               alpha[0], alpha[1], alpha[2], alpha[3], C);
      break;
    }

    break;
  case 5:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], C);
      break;
    }

    break;
  case 6:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], C);
      break;
    }

    break;
  case 7:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], C);
      break;
    }

    break;
  case 8:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], C);
      break;
    }

    break;
  case 9:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], C);
      break;
    }

    break;
  case 10:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], C);
      break;
    }

    break;
  case 11:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], C);
      break;
    }

    break;
  case 12:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], C);
      break;
    }

    break;
  case 13:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], C);
      break;
    }

    break;
  case 14:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], C);
      break;
    }

    break;
  case 15:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], C);
      break;
    }

    break;
  case 16:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], C);
      break;
    }

    break;
  case 17:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], C);
      break;
    }

    break;
  case 18:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], C);
      break;
    }

    break;
  case 19:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], C);
      break;
    }

    break;
  case 20:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], C);
      break;
    }

    break;
  case 21:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], C);
      break;
    }

    break;
  case 22:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], C);
      break;
    }

    break;
  case 23:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], C);
      break;
    }

    break;
  case 24:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], C);
      break;
    }

    break;
  case 25:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], C);
      break;
    }

    break;
  case 26:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], C);
      break;
    }

    break;
  case 27:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], C);
      break;
    }

    break;
  case 28:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], C);
      break;
    }

    break;
  case 29:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], C);
      break;
    }

    break;
  case 30:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], C);
      break;
    }

    break;
  case 31:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], C);
      break;
    }

    break;
  case 32:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], C);
      break;
    }

    break;
  case 33:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], C);
      break;
    }

    break;
  case 34:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], C);
      break;
    }

    break;
  case 35:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], C);
      break;
    }

    break;
  case 36:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], C);
      break;
    }

    break;
  case 37:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], C);
      break;
    }

    break;
  case 38:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], C);
      break;
    }

    break;
  case 39:
    switch (add_type) {
    case ADD:
      Add(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], *A[38], 
          alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], alpha[38], C);
      break;
    case SLOW_ADD:
      SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], *A[38], 
              alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], alpha[38], C);
      break;
    case DAXPY_ADD:
      DaxpyAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], *A[24], *A[25], *A[26], *A[27], *A[28], *A[29], *A[30], *A[31], *A[32], *A[33], *A[34], *A[35], *A[36], *A[37], *A[38], 
               alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], alpha[24], alpha[25], alpha[26], alpha[27], alpha[28], alpha[29], alpha[30], alpha[31], alpha[32], alpha[33], alpha[34], alpha[35], alpha[36], alpha[37], alpha[38], C);
      break;
    }

    break;
  }
}

void FillRandom(Matrix<double>& A) {
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A.data()[i + j * A.stride()] = ((double) rand() / RAND_MAX) * 1024;
    }
  }
}

double benchmark(int m, int n, int add_length, int add_type) {
  Matrix<double> C(m, n);
  FillRandom(C);
  std::vector< Matrix<double>*  > A_matrices;
  for (int i = 0; i < add_length; ++i) {
    Matrix<double> *A = new Matrix<double>(m, n);
    A_matrices.push_back(A);
    FillRandom(*A);
  }

  int num_trials = 10;
  auto func = [&] {
    for (int i = 0; i < num_trials; ++i) {
      add_call(C, A_matrices, add_type);
    }
  };
  double time = Time(func);

  for (Matrix<double> *A : A_matrices) {
    delete A;
  }

  return time;
}

void benchmark_all(int m, int n) {
  int start = 1;
  int total = 40;

  std::cout << "Normal_" << m << "_" << n << " = [";
  for (int add_length = start; add_length < total; ++add_length) {
    double time = benchmark(m, n, add_length, ADD);
    std::cout << time << " ";
  }
  std::cout << "];" << std::endl;

  std::cout << "DAXPY_" << m << "_" << n << " = [";
  for (int add_length = start; add_length < total; ++add_length) {
    double time = benchmark(m, n, add_length, DAXPY_ADD);
    std::cout << time << " ";
  }
  std::cout << "];" << std::endl;

  std::cout << "SLOW_" << m << "_" << n << " = [";
  for (int add_length = start; add_length < total; ++add_length) {
    double time = benchmark(m, n, add_length, SLOW_ADD);
    std::cout << time << " ";
  }
  std::cout << "];" << std::endl;

}

int main(int argc, char **argv) {
  if (argc < 3) {
    return -1;
  }
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  benchmark_all(m, n);
  return 0;
}
