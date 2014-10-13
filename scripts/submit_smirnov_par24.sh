#PBS -q regular
#PBS -l mppwidth=24
#PBS -l walltime=01:30:00
#PBS -N my_job
#PBS -e error
#PBS -o smirnov.par24

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=24
aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -outer_prod_like 9
aprun -n 1 -d 24 -cc none ./build/matmul_bench_dfs    -outer_prod_like 9

aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -ts_square_like 9
aprun -n 1 -d 24 -cc none ./build/matmul_bench_dfs -ts_square_like 9


#export OMP_NUM_THREADS=6
#aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -outer_prod_like 9
#aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs    -outer_prod_like 9
#
#aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -ts_square_like 9
#aprun -n 1 -d 24 -cc none ./build/matmul_bench_bfs -ts_square_like 9
#

