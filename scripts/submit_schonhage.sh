#PBS -q regular
#PBS -l mppwidth=1
#PBS -l walltime=01:30:00
#PBS -N my_job
#PBS -e error
#PBS -o all.schonhage2

cd $PBS_O_WORKDIR

#aprun -n 1 ./build/matmul_benchmarks -square 21
aprun -n 1 ./build/matmul_benchmarks -outer_prod_like 8
aprun -n 1 ./build/matmul_benchmarks -ts_square_like 8
 

