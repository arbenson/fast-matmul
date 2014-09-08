#PBS -q regular
#PBS -l mppwidth=24
#PBS -l walltime=04:00:00
#PBS -N my_job
#PBS -e error
#PBS -o classical.test.all

cd $PBS_O_WORKDIR

OMP_SET_NUM_THREADS=24
export OMP_STACKSIZE=64M
aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -outer_prod_like 10
aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -ts_square_like 10
aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -square 22

OMP_SET_NUM_THREADS=6
aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -outer_prod_like 10
aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -ts_square_like 10
aprun -n 1 -d 6 -cc none ./build/matmul_bench_bfs -square 22




