function Y = perf_MKL(X, MKL)
Y = perf(X) ./ perf(MKL);