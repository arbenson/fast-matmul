#PBS -q debug
#PBS -l mppwidth=24
#PBS -l walltime=00:30:00
#PBS -N dgemm_par
#PBS -e 
#PBS -o 

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=24
aprun -n 1 -d 24 -cc none ./simple_dgemm_par
