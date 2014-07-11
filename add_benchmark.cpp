#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "common.hpp"
#include "mkl.h"

#include "linalg.hpp"
#include "blas_adds.hpp"
#include "slow_adds.hpp"

enum {
  ADD = 0,
  BLAS_ADD,
  SLOW_ADD,
};

void add_call(Matrix<double>& C, std::vector< Matrix<double>* >& A, int add_type) {
  std::vector<double> alpha(A.size(), 1.0);
  switch (A.size()) {
  case 1:
	switch (add_type) {
	case ADD:
	  Add(*A[0], 
		  alpha[0], C);
	  break;
	case BLAS_ADD:
	  BlasAdd(*A[0], 
			  alpha[0], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], 
			  alpha[0], alpha[1], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], 
			  alpha[0], alpha[1], alpha[2], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], 
			  alpha[0], alpha[1], alpha[2], alpha[3], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], 
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
	case BLAS_ADD:
	  BlasAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], C);
	  break;
	case SLOW_ADD:
	  SlowAdd(*A[0], *A[1], *A[2], *A[3], *A[4], *A[5], *A[6], *A[7], *A[8], *A[9], *A[10], *A[11], *A[12], *A[13], *A[14], *A[15], *A[16], *A[17], *A[18], *A[19], *A[20], *A[21], *A[22], *A[23], 
			  alpha[0], alpha[1], alpha[2], alpha[3], alpha[4], alpha[5], alpha[6], alpha[7], alpha[8], alpha[9], alpha[10], alpha[11], alpha[12], alpha[13], alpha[14], alpha[15], alpha[16], alpha[17], alpha[18], alpha[19], alpha[20], alpha[21], alpha[22], alpha[23], C);
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
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < num_trials; ++i) {
    add_call(C, A_matrices, add_type);
  }
  auto t2 = std::chrono::high_resolution_clock::now();

  for (Matrix<double> *A : A_matrices) {
    delete A;
  }

  return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
}

void benchmark_all(int m, int n) {
  std::cout << "Normal_" << m << "_" << n << std::endl;
  for (int add_length = 1; add_length < 24; ++add_length) {
    double time = benchmark(m, n, add_length, ADD);
    std::cout << time << " ";
  }
  std::cout << std::endl;

  std::cout << "Slow_" << m << "_" << n << std::endl;
  for (int add_length = 1; add_length < 24; ++add_length) {
    double time = benchmark(m, n, add_length, SLOW_ADD);
    std::cout << time << " ";
  }
  std::cout << std::endl;

  std::cout << "BLAS_" << m << "_" << n << std::endl;
  for (int add_length = 1; add_length < 24; ++add_length) {
    double time = benchmark(m, n, add_length, BLAS_ADD);
    std::cout << time << " ";
  }
  std::cout << std::endl;
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
