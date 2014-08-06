#ifndef _ALL_ALGORITHMS_HPP_
#define _ALL_ALGORITHMS_HPP_

#include "common.hpp"
#include "mkl.h"

// New fast algorithms
#include "fast234_20_144.hpp"
#include "fast243_20_144.hpp"
#include "fast322_11_50.hpp"
#include "fast323_15_103.hpp"
#include "fast323_15_89.hpp"
#include "fast324_20_144.hpp"
#include "fast332_15_103.hpp"
#include "fast333_23_125.hpp"
#include "fast333_23_152.hpp"
#include "fast333_23_221.hpp"
#include "fast342_20_144.hpp"
#include "fast422_14_84.hpp"
#include "fast423_20_144.hpp"
#include "fast424_26_206.hpp"
#include "fast424_26_257.hpp"
#include "fast432_20_144.hpp"
#include "fast433_29_234.hpp"
#include "fast442_26_257.hpp"
#include "fast522_18_99.hpp"

// Other fast algorithms and classical algorithms
#include "bini322.hpp"
#include "classical222.hpp"
#include "classical333.hpp"
#include "hk332_15_94.hpp"
#include "hk323_15_84.hpp"
#include "hk323_15_94.hpp"
#include "smirnov333_23_128.hpp"
#include "smirnov333_23_139.hpp"
#include "smirnov336_40_960.hpp"
#include "strassen.hpp"

// All of the algorithms
enum {
  MKL,
  BINI322,
  CLASSICAL222,
  CLASSICAL333,
  SMIRNOV333_23_128,
  SMIRNOV333_23_139,
  SMIRNOV336_40_960,
  HK332_15_94,
  HK323_15_94,
  HK323_15_84,
  STRASSEN,
  FAST322_11_50,
  FAST323_15_103,
  FAST323_15_89,
  FAST332_15_103,
  FAST333_23_125,
  FAST333_23_152,
  FAST333_23_221,
  FAST432_20_144,
  FAST423_20_144,
  FAST324_20_144,
  FAST342_20_144,
  FAST234_20_144,
  FAST243_20_144,
  FAST422_14_84,
  FAST424_26_257,
  FAST424_26_206,
  FAST433_29_234,
  FAST522_18_99,
};


template <typename Scalar>
void RunAlgorithm(int algorithm, Matrix<Scalar>& A, Matrix<Scalar>& B,
				  Matrix<Scalar>& C1, int num_steps) {
    switch (algorithm) {
    case MKL:
      // Just run the classical version with zero steps of recursion.
      classical222_8_24::FastMatmul(A, B, C1, 0);
      break;
    case BINI322:
	  double x;
	  // These values of x provide the minimum error, on average.
	  switch (num_steps) {
	  case 2:
		x = 1e-4;
		break;
	  case 3:
		x = 1e-2;
		break;
	  case 4:
		x = 1e-1;
		break;
	  case 0:
	  case 1:
	  default:
		x = 1e-8;
		break;
	  }
      bini322::FastMatmul(A, B, C1, num_steps, x);
      break;
    case CLASSICAL222:
      classical222_8_24::FastMatmul(A, B, C1, num_steps);
      break;
    case CLASSICAL333:
      classical333_27_81::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST322_11_50:
      grey322_11_50::FastMatmul(A, B, C1, num_steps);      
      break;
    case FAST332_15_103:
      grey332_15_103::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST323_15_103:
      grey323_15_103::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST323_15_89:
      grey323_15_103::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST333_23_125:
      grey333_23_125::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST333_23_152:
      grey333_23_152::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST333_23_221:
      grey333_23_221::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST432_20_144:
      grey432_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST423_20_144:
      grey423_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST324_20_144:
      grey324_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST342_20_144:
      grey342_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST234_20_144:
      grey234_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST243_20_144:
      grey243_20_144::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST433_29_234:
      grey433_29_234::FastMatmul(A, B, C1, num_steps);
      break;
    case SMIRNOV333_23_128:
      smirnov333_23_128::FastMatmul(A, B, C1, num_steps);
      break;
    case SMIRNOV333_23_139:
      smirnov333_23_139::FastMatmul(A, B, C1, num_steps);
      break;
    case SMIRNOV336_40_960:
      smirnov336_40_960::FastMatmul(A, B, C1, num_steps);
      break;
    case HK332_15_94:
      hk332_15_94::FastMatmul(A, B, C1, num_steps);
      break;
    case HK323_15_94:
      hk323_15_94::FastMatmul(A, B, C1, num_steps);
      break;
    case HK323_15_84:
      hk323_15_84::FastMatmul(A, B, C1, num_steps);
      break;
    case STRASSEN:
      strassen::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST422_14_84:
      grey422_14_84::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST424_26_257:
      grey424_26_257::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST424_26_206:
      grey424_26_206::FastMatmul(A, B, C1, num_steps);
      break;
    case FAST522_18_99:
      grey522_18_99::FastMatmul(A, B, C1, num_steps);
      break;
    default:
      std::cout << "Unknown algorithm type!" << std::endl;
    }
}


// Convert the algorithm to a string representation.  Useful for debugging, dumping data, etc.
std::string Alg2Str(int algorithm) {
  switch (algorithm) {
  case MKL:
    return "MKL";
  case BINI322:
    return "BINI322";
  case CLASSICAL222:
    return "CLASSICAL2x2";
  case CLASSICAL333:
    return "CLASSICAL3x3";
  case FAST322_11_50:
    return "FAST322_11_50";
  case FAST332_15_103:
    return "FAST332_15_103";
  case FAST323_15_103:
    return "FAST323_15_103";
  case FAST323_15_89:
    return "FAST323_15_89";
  case FAST333_23_125:
    return "FAST333_23_125";
  case FAST333_23_152:
    return "FAST333_23_152";
  case FAST333_23_221:
    return "FAST333_23_221";
  case FAST432_20_144:
    return "FAST432_20_144";
  case FAST423_20_144:
    return "FAST423_20_144";
  case FAST324_20_144:
    return "FAST324_20_144";
  case FAST342_20_144:
    return "FAST342_20_144";
  case FAST234_20_144:
    return "FAST234_20_144";
  case FAST243_20_144:
    return "FAST243_20_144";
  case FAST433_29_234:
    return "FAST433_29_234";
  case SMIRNOV333_23_128:
    return "SMIRNOV333_23_128";
  case SMIRNOV333_23_139:
    return "SMIRNOV333_23_139";
  case SMIRNOV336_40_960:
    return "SMIRNOV336_40_960";
  case HK332_15_94:
    return "HK332_15_94";
  case HK323_15_94:
    return "HK323_15_94";
  case HK323_15_84:
    return "HK323_15_84";
  case STRASSEN:
    return "STRASSEN";
  case FAST422_14_84:
    return "FAST422_14_84";
  case FAST424_26_257:
    return "FAST424_26_257";
  case FAST424_26_206:
    return "FAST424_26_206";
  case FAST522_18_99:
    return "FAST522_18_99";
  default:
    throw std::logic_error("Unknown algorithm type!");
  }
}

#endif  // _ALL_ALGORITHMS_HPP_
