#PBS -q debug
#PBS -l mppwidth=24 
#PBS -l walltime=00:30:00
#PBS -N my_job
#PBS -e error
#PBS -o dgemm_curves.par

cd $PBS_O_WORKDIR

# parallel
export OMP_NUM_THREADS=24
./build/dgemm_curves_par 1 1
./build/dgemm_curves_par 2 1
./build/dgemm_curves_par 3 1

# sequential
#./build/dgemm_curves_seq 1
#./build/dgemm_curves_seq 2
#./build/dgemm_curves_seq 3
