#PBS -q debug
#PBS -l mppwidth=24
#PBS -l walltime=00:10:00
#PBS -N TEST_PAR_FAST_MATMUL
#PBS -e error
#PBS -o 433.test2

cd $PBS_O_WORKDIR

export OMP_STACKSIZE=64M
export OMP_NUM_THREADS=24

export OMP_NUM_THREADS=24
echo "HYBRID 24"
aprun -n 1 -d 24 -cc none ./build/matmul_bench_hybrid -ts_square_test_par 1

