% All plots for the PPoPP paper

% dgemm curves
if 0
dgemm_curves2();
end

if 0
    comp_perf2();
end

% Matrix additions and common subexpression elimination
if 0
paper_add_cse_perf();
end

% Sequential performance plots
if 0
paper_edison_square();
end
if 0
paper_edison_tssquare();
end
if 0
paper_edison_outer();
end

% Parallel performance plots
if 0
square6_perf();
square24_perf();
end
if 0
outer6_perf();
outer24_perf();
end
if 1
tssquare6_perf();
tssquare24_perf();
end

% performance plot of different parallel algorithms (BFS, DFS, HYBRID)
if 0
comparison_tssquare();
comparison_outer();
comparison_square();
end


