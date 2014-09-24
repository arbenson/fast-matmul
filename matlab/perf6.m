function P = perf6(U, V, W, X, Y, Z)
P = max(max(max(max(max(perf(U), perf(V)), perf(W)), perf(X)), perf(Y)), perf(Z));