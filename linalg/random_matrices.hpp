#ifndef _RANDOM_MATRICES_HPP_
#define _RANDOM_MATRICES_HPP_

#include <chrono>
#include <random>

// These are several tools for generating random matrices.  Unfortunately, they
// can be quite slow, so they are only intended for generating smallish matrices.


// Generate a m x n matrix with entries ~ Uniform(a, b).
template <typename Scalar>
Matrix<Scalar> UniformRandomMatrix(int m, int n, double a, double b) {
  std::random_device rdev;
  std::default_random_engine generator(rdev());
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
  std::random_device rdev;
  std::default_random_engine generator(rdev());
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


// Generate a m x n matrix with entries A_{ij} ~ i^2 * Uniform(a, b)
template <typename Scalar>
Matrix<Scalar> SkewedUniformRandomMatrix1(int m, int n, double a, double b) {
  std::random_device rdev;
  std::default_random_engine generator(rdev());
  std::uniform_real_distribution<double> distribution(a, b);
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A(i, j) = distribution(generator) * (i + 1) * (i + 1);
    }
  }  
  return A;
}


// Generate a m x n matrix with entries A_{ij} ~ i * j * Uniform(a, b)
template <typename Scalar>
Matrix<Scalar> SkewedUniformRandomMatrix3(int m, int n, double a, double b) {
  std::random_device rdev;
  std::default_random_engine generator(rdev());
  std::uniform_real_distribution<double> distribution(a, b);
  Matrix<Scalar> A(m, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A(i, j) = distribution(generator) * (i + 1) * (j + 1);
    }
  }  
  return A;
}


// Generate a n x n matrix with entries K_{ij} = n / |i - j|
template <typename Scalar>
Matrix<Scalar> KernelMatrix1(int n) {
  Matrix<Scalar> A(n, n);
  double x_step = 1.0 / n;
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      if (i == j) {
	A(i, j) = 0;
      } else {
	A(i, j) = 1.0 / std::abs(x_step * (i - j));
      }
    }
  }  
  return A;
}


// Generate a n x n matrix with entries K_{ij} = (n / (i - j))^2
template <typename Scalar>
Matrix<Scalar> KernelMatrix2(int n) {
  Matrix<Scalar> A(n, n);
  double x_step = 1.0 / n;
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      if (i == j) {
	A(i, j) = 0;
      } else {
	Scalar val = std::abs(x_step * (i - j));
	A(i, j) = 1.0 / (val * val);
      }
    }
  }  
  return A;
}


// cos((i + j) * freq / n)
template <typename Scalar>
Matrix<Scalar> OscillatoryMatrix1(int n, double freq, double scale) {
  Matrix<Scalar> A(n, n);
  // We can use fancier C++11 random number generators, but they are
  // still slow on some systems.
  for (int j = 0; j < A.n(); ++j) {
    for (int i = 0; i < A.m(); ++i) {
      A(i, j) = scale * cos((i + j) * freq / n);
    }
  }  
  return A;
}

#endif  // _RANDOM_MATRICES_HPP_
