#ifndef _ALL_ALGORITHMS_HPP_
#define _ALL_ALGORITHMS_HPP_

#include "common.hpp"
#ifdef __INTEL_MKL__
# include "mkl.h"
#endif

// New fast algorithms
#include "fast234_20_144.hpp"
#include "fast243_20_144.hpp"
#include "fast322_11_50.hpp"
#include "fast323_15_103.hpp"
#include "fast323_15_89.hpp"
#include "fast324_20_144.hpp"
#include "fast332_15_103.hpp"
#include "fast333_23_152.hpp"
#include "fast333_23_221.hpp"
#include "fast342_20_144.hpp"
#include "fast422_14_84.hpp"
#include "fast423_20_144.hpp"
#include "fast424_26_257.hpp"
#include "fast432_20_144.hpp"
#include "fast433_29_234.hpp"
#include "fast343_29_234.hpp"
#include "fast442_26_257.hpp"
#include "fast522_18_99.hpp"
#include "fast252_18_99.hpp"

// Other fast algorithms and classical algorithms
#include "bini322_10_52_approx.hpp"
#include "classical222.hpp"
#include "classical423.hpp"
#include "classical333.hpp"
#include "hk332_15_94.hpp"
#include "hk323_15_94.hpp"
#include "schonhage333_21_117_approx.hpp"
#include "smirnov333_23_139.hpp"
#include "smirnov336_40_960.hpp"
#include "smirnov363_40_960.hpp"
#include "smirnov633_40_960.hpp"
#include "strassen.hpp"

// Common subexpression elimination
#include "fast424_26_206.hpp"
#include "hk323_15_84.hpp"
#include "fast333_23_125.hpp"
#include "smirnov333_23_128.hpp"


// All of the algorithms
enum {
  MKL,
  BINI322_10_52_APPROX,
  CLASSICAL222,
  CLASSICAL423,
  CLASSICAL333,
  SMIRNOV333_23_128,
  SMIRNOV333_23_139,
  SMIRNOV336_40_960,
  SMIRNOV363_40_960,
  SMIRNOV633_40_960,
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
  FAST442_26_257,
  FAST424_26_257,
  FAST424_26_206,
  FAST433_29_234,
  FAST343_29_234,
  FAST522_18_99,
  FAST252_18_99,
  SCHONHAGE333_21_117_APPROX,
  SMIRNOV54,
};


template <typename Scalar>
double RunAlgorithm(int algorithm, Matrix<Scalar>& A, Matrix<Scalar>& B,
                  Matrix<Scalar>& C1, int num_steps) {
  double x = 1e-8;
  switch (algorithm) {
  case MKL:
    // Just run the classical version with zero steps of recursion.
    return classical222_8_24::FastMatmul(A, B, C1, 0);
    break;
  case BINI322_10_52_APPROX:
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
    return bini322_10_52_approx::FastMatmul(A, B, C1, num_steps, x);
    break;
  case SCHONHAGE333_21_117_APPROX:
    // These values of x provide the minimum error, on average.
    switch (num_steps) {
    case 1:
      x = 1e-4;
      break;
    case 2:
      x = 1e-2;
      break;
    case 3:
    case 4:
      x = 1e-1;
      break;
    default:
      x = 1e-4;
      break;
    }
    return schonhage333_21_117_approx::FastMatmul(A, B, C1, num_steps, x);
    break;
  case CLASSICAL222:
    return classical222_8_24::FastMatmul(A, B, C1, num_steps);
    break;
  case CLASSICAL423:
    return classical423_24_72::FastMatmul(A, B, C1, num_steps);
    break;
  case CLASSICAL333:
    return classical333_27_81::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST322_11_50:
    return grey322_11_50::FastMatmul(A, B, C1, num_steps);      
    break;
  case FAST332_15_103:
    return grey332_15_103::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST323_15_103:
    return grey323_15_103::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST323_15_89:
    return grey323_15_103::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST333_23_125:
    return grey333_23_125::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST333_23_152:
    return grey333_23_152::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST333_23_221:
    return grey333_23_221::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST432_20_144:
    return grey432_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST423_20_144:
    return grey423_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST324_20_144:
    return grey324_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST342_20_144:
    return grey342_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST234_20_144:
    return grey234_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST243_20_144:
    return grey243_20_144::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST433_29_234:
    return grey433_29_234::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST343_29_234:
    return grey343_29_234::FastMatmul(A, B, C1, num_steps);
    break;
  case SMIRNOV333_23_128:
    return smirnov333_23_128::FastMatmul(A, B, C1, num_steps);
    break;
  case SMIRNOV333_23_139:
    return smirnov333_23_139::FastMatmul(A, B, C1, num_steps);
    break;
  case SMIRNOV336_40_960:
    return smirnov336_40_960::FastMatmul(A, B, C1, num_steps);
    break;
  case SMIRNOV363_40_960:
    return smirnov363_40_960::FastMatmul(A, B, C1, num_steps);
    break;
  case SMIRNOV633_40_960:
    return smirnov633_40_960::FastMatmul(A, B, C1, num_steps);
    break;
  case HK332_15_94:
    return hk332_15_94::FastMatmul(A, B, C1, num_steps);
    break;
  case HK323_15_94:
    return hk323_15_94::FastMatmul(A, B, C1, num_steps);
    break;
  case HK323_15_84:
    return hk323_15_84::FastMatmul(A, B, C1, num_steps);
    break;
  case STRASSEN:
    return strassen::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST422_14_84:
    return grey422_14_84::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST424_26_257:
    return grey424_26_257::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST442_26_257:
    return grey442_26_257::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST424_26_206:
    return grey424_26_206::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST522_18_99:
    return grey522_18_99::FastMatmul(A, B, C1, num_steps);
    break;
  case FAST252_18_99:
    return grey252_18_99::FastMatmul(A, B, C1, num_steps);
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
  case BINI322_10_52_APPROX:
    return "BINI322_10_52_APPROX";
  case CLASSICAL222:
    return "CLASSICAL222";
  case CLASSICAL423:
    return "CLASSICAL423";
  case CLASSICAL333:
    return "CLASSICAL333";
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
  case FAST343_29_234:
    return "FAST343_29_234";
  case SMIRNOV333_23_128:
    return "SMIRNOV333_23_128";
  case SMIRNOV333_23_139:
    return "SMIRNOV333_23_139";
  case SMIRNOV336_40_960:
    return "SMIRNOV336_40_960";
  case SMIRNOV363_40_960:
    return "SMIRNOV363_40_960";
  case SMIRNOV633_40_960:
    return "SMIRNOV633_40_960";
  case SMIRNOV54:
    return "SMIRNOV54";
  case HK332_15_94:
    return "HK332_15_94";
  case HK323_15_94:
    return "HK323_15_94";
  case HK323_15_84:
    return "HK323_15_84";
  case STRASSEN:
    return "STRASSEN";
  case SCHONHAGE333_21_117_APPROX:
    return "SCHONHAGE333_21_117_APPROX";
  case FAST422_14_84:
    return "FAST422_14_84";
  case FAST424_26_257:
    return "FAST424_26_257";
  case FAST442_26_257:
    return "FAST442_26_257";
  case FAST424_26_206:
    return "FAST424_26_206";
  case FAST522_18_99:
    return "FAST522_18_99";
  case FAST252_18_99:
    return "FAST252_18_99";
  default:
    throw std::logic_error("Unknown algorithm type!");
  }
}

#endif  // _ALL_ALGORITHMS_HPP_
