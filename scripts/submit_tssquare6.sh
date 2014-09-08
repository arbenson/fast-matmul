#PBS -q regular
#PBS -l mppwidth=6
#PBS -l walltime=08:00:00
#PBS -N PAR_TSS_BENCH
#PBS -e error.tssquare
#PBS -o all.tssquare.6

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=6
export OMP_STACKSIZE=64M

echo "DFS 6"
for i in `seq 0 0`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_dfs -ts_square_like $i
done

echo "HYBRID 6"
for i in `seq 1 8`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -ts_square_like $i
done

echo "BFS 6"
for i in `seq 1 8`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -ts_square_like $i
done
