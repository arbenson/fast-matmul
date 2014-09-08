#PBS -q regular
#PBS -l mppwidth=6
#PBS -l walltime=10:00:00
#PBS -N PAR_OUTER_BENCH
#PBS -e error.outer
#PBS -o all.outer.6

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=6
export OMP_STACKSIZE=64M

echo "DFS 6"
for i in `seq 0 0`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_dfs -outer_prod_like $i
done

echo "HYBRID 6"
for i in `seq 1 8`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -outer_prod_like $i
done

echo "BFS 6"
for i in `seq 1 8`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -outer_prod_like $i
done
