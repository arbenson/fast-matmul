#PBS -q regular
#PBS -l mppwidth=24
#PBS -l walltime=04:00:00
#PBS -N COMPARISON_BENCH
#PBS -e error.comparison.square24
#PBS -o comparison.square24

cd $PBS_O_WORKDIR

export OMP_STACKSIZE=64M

export OMP_NUM_THREADS=24
echo "DFS 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_dfs -square_test_par 1
echo "BFS 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -square_test_par 1
echo "HYBRID 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -square_test_par 1
