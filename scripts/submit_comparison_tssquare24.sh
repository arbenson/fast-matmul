#PBS -q regular
#PBS -l mppwidth=24
#PBS -l walltime=01:15:00
#PBS -N COMPARISON_BENCH_TSS
#PBS -e error.comparison.tss.3000.24
#PBS -o comparison.tss.3000.24

cd $PBS_O_WORKDIR

export OMP_STACKSIZE=64M

export OMP_NUM_THREADS=24
echo "DFS 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_dfs -ts_square_test_par 1
echo "BFS 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -ts_square_test_par 1
echo "HYBRID 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -ts_square_test_par 1
