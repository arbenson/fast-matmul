#PBS -q debug
#PBS -l mppwidth=24
#PBS -l walltime=00:30:00
#PBS -N PAR_SQUARE_BENCH
#PBS -e error
#PBS -o square.all.big

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=24
export OMP_STACKSIZE=64M
aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -square_all 1
