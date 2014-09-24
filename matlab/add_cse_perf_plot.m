function add_cse_perf_plot(WO_NO_CSE, WO_YES_CSE, ST_NO_CSE, ST_YES_CSE, ...
    PW_NO_CSE, PW_YES_CSE, title_str, file_name, use_legend)

dims = WO_NO_CSE(:, 1);

lw = 1.75;      % LineWidth
msz = 14;       % MarkerSize

width = 4.5; height = 4.5;
make_plot_pre(width, height);
plot(dims, perf(WO_NO_CSE), 'g+-', ...
     dims, perf(WO_YES_CSE), 'bs--', ...
     dims, perf(ST_NO_CSE), 'r>-', ...
     dims, perf(ST_YES_CSE), 'm<--', ...
     dims, perf(PW_NO_CSE), 'c*-', ...
     dims, perf(PW_YES_CSE), 'kp--', ...
     'LineWidth', lw, 'MarkerSize', msz);
 ylim([10, 27]);

 if use_legend
    legend('Write-once', 'Write-once+CSE', 'Streaming', 'Streaming+CSE', 'Pairwise', 'Pairwise+CSE', 'Location', 'SouthEast');
 end
xlabel('Dimension (N)');
ylabel('Effective GFLOPS');
title(title_str);
make_plot_post(width, height);

% save figure to disk
out = sprintf('fast-matmul_paper_figs/%s.eps', file_name);
print(out, '-depsc', '-r300');