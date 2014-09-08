#PBS -q debug
#PBS -l mppwidth=1
#PBS -l walltime=00:30:00
#PBS -N my_job
#PBS -e error
#PBS -o square54.bfs.13000.both2

cd $PBS_O_WORKDIR

#export OMP_NUM_THREADS=6
#aprun -n 1 -d 6 -cc none ./build/square54_benchmark -smirnov54 1
export OMP_NUM_THREADS=24
export OMP_STACKSIZE=128M
aprun -n 1 -d 24 -cc none ./build/square54_benchmark -smirnov54 1

#aprun -n 1 -d 1 -cc none ./build/square54_benchmark -strassen 1
#aprun -n 1 -d 1 -cc none ./build/square54_benchmark -mkl 1
