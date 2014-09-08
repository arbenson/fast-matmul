#PBS -q debug
#PBS -l mppwidth=6
#PBS -l walltime=00:30:00
#PBS -N PAR_OUTER_PRODUCT_BENCH
#PBS -e error.outer
#PBS -o all.outerprod.par6

cd $PBS_O_WORKDIR

export OMP_NUM_THREADS=6
export OMP_STACKSIZE=64M
aprun -n 1 -d 6 -cc none ./build/matmul_bench_hybrid -outer_prod_like 1
