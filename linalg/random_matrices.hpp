#ifndef _RANDOM_MATRICES_HPP_
#define _RANDOM_MATRICES_HPP_

#include <random>

// These are several tools for generating random matrices.  Unfortunately, they
// can be quite slow, so they are only intended for generating smallish matrices.


// Generate a m x n matrix with entries ~ Uniform(a, b).
template <typename Scalar>
Matrix<Scalar> UniformRandomMatrix(int m, int n, double a, double b) {
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(a, b);
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A(i, j) = distribution(generator);
    }
  }  
  return A;
}


// Generate a m x n matrix with entries ~ N(mu, sigma).
template <typename Scalar>
Matrix<Scalar> NormalRandomMatrix(int m, int n, double mu, double sigma) {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mu, sigma);
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A(i, j) = distribution(generator);
    }
  }  
  return A;
}

#endif  // _RANDOM_MATRICES_HPP_
