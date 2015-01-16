#include "linalg.hpp"
#include "strassen.hpp"
#include "random_matrices.hpp"
#include "scaling.hpp"

#include <iostream>

int main(int argc, char **argv) {
  int m = 256;
  int k = 256;
  int n = 256;
  int numsteps = 3;

  Matrix<double> A = UniformRandomMatrix<double>(m, k, 0.0, 1.0);
  Matrix<double> B = SkewedUniformRandomMatrix1<double>(k, n, 0.0, 1.0);
  Matrix<double> C(m, n);
  // Compute "ground truth".
  MatMul(A, B, C);

  // Fast matrix multiplication without scaling.
  Matrix<float> A_flt = DoubleToFloat(A);
  Matrix<float> B_flt = DoubleToFloat(B);

  // Norm information
  std::cout << "BEFORE SCALING" << std::endl;
  std::cout << "||A||_1   = " << A_flt.OneNorm() << std::endl
            << "||A||_inf = " << A_flt.InfNorm() << std::endl
            << "||B||_1   = " << B_flt.OneNorm() << std::endl
            << "||B||_inf = " << B_flt.InfNorm() << std::endl; 

  Matrix<float> C_fast(m, n);
  strassen::FastMatmul(A_flt, B_flt, C_fast, numsteps);

  // Fast matrix multiplication without scaling.
  int max_steps = 5;
  std::vector<float> r_vals, s_vals;
  int scaling_type = INNER_OUTER;
  Scaling<float>(A_flt, B_flt, max_steps, r_vals, s_vals, scaling_type);

  // Norm information
  std::cout << "AFTER SCALING" << std::endl;
  std::cout << "||A||_1   = " << A_flt.OneNorm() << std::endl
            << "||A||_inf = " << A_flt.InfNorm() << std::endl
            << "||B||_1   = " << B_flt.OneNorm() << std::endl
            << "||B||_inf = " << B_flt.InfNorm() << std::endl; 

  Matrix<float> C_fast_scale(m, n);
  strassen::FastMatmul(A_flt, B_flt, C_fast_scale, numsteps);
  PostProcessScaling(C_fast_scale, r_vals, s_vals);

  Matrix<double> C_fast_dbl = FloatToDouble(C_fast);
  Matrix<double> C_fast_scale_dbl = FloatToDouble(C_fast_scale);

  Matrix<double> Diff_scale = Diff(C, C_fast_scale_dbl);
  Matrix<double> Diff_no_scale = Diff(C, C_fast_dbl);

  NormType norm = NormType::MAX;
  
  std::cout << "||C_comp - C|| / (||A|| ||B||) (no scaling): "
            << Diff_no_scale.Norm(norm) / (A.Norm(norm) * B.Norm(norm))
            << std::endl;

  std::cout << "||C_comp - C|| / (||A|| ||B||) (w/ scaling): "
            << Diff_scale.Norm(norm) / (A.Norm(norm) * B.Norm(norm))
            << std::endl;

  return 0;
}
