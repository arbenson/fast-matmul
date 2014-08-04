#include "common.hpp"
#include "fast_qr.hpp"
#include "linalg.hpp"

#include <vector>

int main(int argc, char **argv) {
  auto opts = GetOpts(argc, argv);
  int m = GetIntOpt(opts, "m", 10000);
  int n = GetIntOpt(opts, "n", m);
  int blocksize = GetIntOpt(opts, "blocksize", 1600);
  std::cout << "Factoring " << m << " x " << n << " matrix with blocksize "
			<< blocksize << std::endl;

  Matrix<double> A = RandomMatrix<double>(m, n);
  Matrix<double> B = A;

  std::vector<double> tau(A.n());
  Time([&] { QR(A, tau); }, "Classical QR");
  Time([&] { FastQR(B, tau, blocksize); }, "Fast QR");

  return 0;
}
