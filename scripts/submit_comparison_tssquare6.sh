#PBS -q regular
#PBS -l mppwidth=6
#PBS -l walltime=03:30:00
#PBS -N COMPARISON_BENCH_TSS
#PBS -e error.comparison.tss.3000.6
#PBS -o comparison.tss.3000.6

cd $PBS_O_WORKDIR

export OMP_STACKSIZE=64M

export OMP_NUM_THREADS=6
echo "DFS 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_dfs -ts_square_test_par 1
echo "BFS 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -ts_square_test_par 1
echo "HYBRID 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -ts_square_test_par 1
