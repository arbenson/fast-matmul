#PBS -q regular
#PBS -l mppwidth=6
#PBS -l walltime=16:00:00
#PBS -N COMPARISON_BENCH
#PBS -e error.comparison.square6
#PBS -o comparison.square6

cd $PBS_O_WORKDIR

export OMP_STACKSIZE=64M

export OMP_NUM_THREADS=6
echo "DFS 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_dfs -square_test_par 1
echo "BFS 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -square_test_par 1
echo "HYBRID 6"
aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -square_test_par 1
