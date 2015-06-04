/**
   Copyright (c) 2014-2015, Sandia Corporation
   All rights reserved.

   This file is part of fast-matmul and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause.
*/

#include "common.hpp"
#ifdef __INTEL_MKL__
# include "mkl.h"
#endif

#include "fast333_23_152.hpp"
#include "strassen.hpp"

#include "linalg.hpp"
#include "random_matrices.hpp"
#include "quadmatmul.hpp"
#include "scaling.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

void WriteErrorVec(std::vector<double>& err_vec, std::string name) {
  std::cout << name << " = [ ";
  for (double err : err_vec) {
    std::cout << err << " ";
  }
  std::cout << " ];" << std::endl;
}

void Benchmark(int m, int k, int n, std::vector<int>& num_steps) {
  Matrix<double> A = UniformRandomMatrix<double>(m, k, 0, 1);
  Matrix<double> B = UniformRandomMatrix<double>(m, k, 0, 1);
  //Matrix<double> A = SkewedUniformRandomMatrix5<double>(m, k, 0, 1);
  //Matrix<double> B = SkewedUniformRandomMatrix6<double>(m, k, 0, 1);

  // Inside scaling
  Matrix<double> A_i = A;
  Matrix<double> B_i = B;
  std::vector<double> r_i, s_i;
  Scaling(A_i, B_i, 1, r_i, s_i, INSIDE);

  // Outside scaling
  Matrix<double> A_o = A;
  Matrix<double> B_o = B;
  std::vector<double> r_o, s_o;
  Scaling(A_o, B_o, 1, r_o, s_o, OUTSIDE);

  // Inside-outside scaling
  Matrix<double> A_io = A;
  Matrix<double> B_io = B;
  std::vector<double> r_io, s_io;
  Scaling(A_io, B_io, 1, r_io, s_io, INSIDE_OUTSIDE);

  // Outside-inside scaling
  Matrix<double> A_oi = A;
  Matrix<double> B_oi = B;
  std::vector<double> r_oi, s_oi;
  Scaling(A_oi, B_oi, 1, r_oi, s_oi, OUTSIDE_INSIDE);

  // Repeated outside-inside scaling
  Matrix<double> A_roi = A;
  Matrix<double> B_roi = B;
  std::vector<double> r_roi, s_roi;
  Scaling(A_roi, B_roi, 5, r_roi, s_roi, OUTSIDE_INSIDE);

  std::vector<double> err_c(num_steps.size());    // classical
  std::vector<double> err_s(num_steps.size());    // strassen
  std::vector<double> err_i(num_steps.size());    // strassen inside
  std::vector<double> err_o(num_steps.size());    // strassen outside
  std::vector<double> err_io(num_steps.size());   // strassen inside-outside
  std::vector<double> err_oi(num_steps.size());   // strassen outside-inside
  std::vector<double> err_roi(num_steps.size());  // strassen repeated outside-inside

  std::cout << "Quad matmul..." << std::endl;
  Matrix<__float128> C(A.m(), B.n());
  QuadMatmul(A.data(), B.data(), C.data(), A.m(), A.n(), B.n());
  std::cout << "Done...";
  // Convert back to double
  Matrix<double> C_dbl(A.m(), B.n());
  for (int j = 0; j < C.n(); ++j) {
    for (int i = 0; i < C.m(); ++i) {
      C_dbl(i, j) = C(i, j);
    }
  }

  Matrix<double> C1(m, n);
  for (int i = 0; i < num_steps.size(); ++i) {
    std::cout << "step " << i << std::endl;

    MatMul(A, B, C1);
    err_c[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A, B, C1, num_steps[i]);
    err_s[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A_i, B_i, C1, num_steps[i]);
    err_i[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A_o, B_o, C1, num_steps[i]);
    PostProcessScaling(C1, r_o, s_o);
    err_o[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A_io, B_io, C1, num_steps[i]);
    PostProcessScaling(C1, r_io, s_io);
    err_io[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A_oi, B_oi, C1, num_steps[i]);
    PostProcessScaling(C1, r_oi, s_oi);
    err_oi[i] = MaxRelativeDiff(C_dbl, C1);

    strassen::FastMatmul(A_roi, B_roi, C1, num_steps[i]);
    PostProcessScaling(C1, r_roi, s_roi);
    err_roi[i] = MaxRelativeDiff(C_dbl, C1);
  }
 
  WriteErrorVec(err_c, "err_c");
  WriteErrorVec(err_s, "err_n");
  WriteErrorVec(err_i, "err_i");
  WriteErrorVec(err_o, "err_o");
  WriteErrorVec(err_io, "err_io");
  WriteErrorVec(err_oi, "err_oi");
  WriteErrorVec(err_roi, "err_roi");
}

int main(int argc, char **argv) {
  int m = 4000;
  int k = 4000;
  int n = 4000;
  std::vector<int> num_steps = {1, 2, 3, 4, 5, 6};
  
  Benchmark(m, k, n, num_steps);

  return 0;
}
