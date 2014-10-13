#PBS -q debug
#PBS -l mppwidth=1
#PBS -l walltime=00:05:00
#PBS -N test8000
#PBS -e test8000.error.1
#PBS -o test8000.out.1

cd $PBS_O_WORKDIR

aprun -n 1 ./simple_dgemm

