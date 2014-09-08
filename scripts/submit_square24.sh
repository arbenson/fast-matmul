#PBS -q regular
#PBS -l mppwidth=24
#PBS -l walltime=04:00:00
#PBS -N PAR_SQUARE_BENCH
#PBS -e error.square
#PBS -o all.square.24.part5

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=24
export OMP_STACKSIZE=64M

#echo "DFS 24"
#for i in `seq 14 14`;
#do
#    aprun -n 1 -d 24 -cc none ./build/matmul_bench_dfs -square $i
#done

echo "HYBRID 24"
for i in `seq 14 16`;
do
    aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -square $i
done

#echo "BFS 24"
#for i in `seq 12 21`;
#do
#    aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -square $i
#done
