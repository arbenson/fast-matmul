#PBS -q regular
#PBS -l mppwidth=1
#PBS -l walltime=01:30:00
#PBS -N my_job
#PBS -e error
#PBS -o smirnov.seq

cd $PBS_O_WORKDIR

aprun -n 1 -d 1 -cc none ./build/matmul_benchmarks -outer_prod_like 9
aprun -n 1 -d 1 -cc none ./build/matmul_benchmarks -ts_square_like 9
