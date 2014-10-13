#PBS -q regular
#PBS -l mppwidth=6
#PBS -l walltime=16:00:00
#PBS -N PAR_SQUARE_BENCH
#PBS -e error.square
#PBS -o all.square.6.bfs

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=6
export OMP_STACKSIZE=64M

#echo "DFS 6"
#for i in `seq 0 0`;
#do
#    aprun -n 1 -d 6 -cc none ./build/matmul_bench_dfs -square $i
#done
#
#echo "HYBRID 6"
#for i in `seq 1 21`;
#do
#    aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -square $i
#done
#
echo "BFS 6"
for i in `seq 8 21`;
do
    aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -square $i
done
