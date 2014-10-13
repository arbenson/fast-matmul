function Y = perf(X)
gflop = X(:, 1) .* X(:, 3) .* (2 * X(:, 2) - 1) / 1e9;
secs = X(:, 5) / 1e3;
Y = gflop ./ secs;
