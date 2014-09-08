#PBS -q debug
#PBS -l mppwidth=24 
#PBS -l walltime=00:30:00
#PBS -N my_job
#PBS -e error
#PBS -o adds.423.2.short

cd $PBS_O_WORKDIR

aprun -n 1 ./build/cse_add_perf_benchmarks -423 2
