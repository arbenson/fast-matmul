#PBS -q debug
#PBS -l mppwidth=1
#PBS -l walltime=00:30:00
#PBS -N my_job
#PBS -e error

cd $PBS_O_WORKDIR

aprun -n 1 ./build/matmul_benchmarks -square ${WHICH}

