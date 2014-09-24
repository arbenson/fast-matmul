function P = perf4(W, X, Y, Z)
%P = max(max(max(perf(W), perf(X)), perf(Y)), perf(Z));
P = max(perf(W), perf(X));