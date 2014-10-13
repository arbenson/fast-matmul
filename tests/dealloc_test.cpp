#include <chrono>
#include <iostream>
#include <vector>

double fill(int M, int N, double *data) {
  for (int i = 0; i < M * N; ++i) {
    data[i] = 1.0 / (i);
  }
}

double *memory(int M, int N) {
  int tot = M * N;
  double *data = new double[tot];
  return data;
}

// icpc -fopenmp -std=c++11 -O3 dealloc_test.cpp -o dealloc_test_par
void run() {
  using FpMilliseconds =
      std::chrono::duration<float, std::chrono::milliseconds::period>;
  static_assert(std::chrono::treat_as_floating_point<FpMilliseconds::rep>::value, 
		"Rep required to be floating point");
  int m = 22000;
  int k = 2000;
  int n = 22000;
  double *A = memory(m, k);
  double *B = memory(k, n);
  double *C = memory(m, n);

  std::vector<double *> data;
  for (int i = 0; i < 26; ++i) {
    data.push_back(memory(m / 4, n / 4));
  }
  for (int i = 0; i < 26; ++i) {
    #pragma omp task
    fill(m / 4, n / 4, data[i]);
  }
  #pragma omp taskwait

  auto t1 = std::chrono::high_resolution_clock::now();
  for (double *p : data) {
    #pragma omp task
    delete [] p;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  auto time_ms = FpMilliseconds(t2 - t1);
  std::cout << "time: " << time_ms.count() << " ms" << std::endl;
}

int main(int argc, char **argv) {
  #pragma omp parallel
  {
    #pragma omp single
    {
      run();
    }
  }
}
