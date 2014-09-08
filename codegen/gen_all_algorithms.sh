# Re-generate all of the header files.  This can be useful for changes to the
# code generator.  Usage:
#
#           ./gen_all_algorithms.sh adds_type
#
# adds_type is the type of matrix additions to use.  It is one of {0, 1, 2}:
#    0: write-once additions
#    1: streaming additions
#    2: pairwise additions

# Where the U, V, W versions of the algorithms live
ALGS_DIR=algorithms
ELIM_DIR=${ALGS_DIR}/eliminated

# Where we are going to place the generated code.
OUT_DIR=../algorithms

# For now, the only option is the type of additions.
OPTIONS=$1

SCRIPT=gen.py

# 3,3,6
python ${SCRIPT} ${ALGS_DIR}/smirnov336-40-960 3,3,6 ${OUT_DIR}/smirnov336_40_960.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/smirnov363-40-960 3,6,3 ${OUT_DIR}/smirnov363_40_960.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/smirnov633-40-960 6,3,3 ${OUT_DIR}/smirnov633_40_960.hpp ${OPTIONS}

# 5,2,2
python ${SCRIPT} ${ALGS_DIR}/grey522-18-99 5,2,2 ${OUT_DIR}/fast522_18_99.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey252-18-99 2,5,2 ${OUT_DIR}/fast252_18_99.hpp ${OPTIONS}

# 4,4,2
python ${SCRIPT} ${ALGS_DIR}/grey442-26-257 4,4,2 ${OUT_DIR}/fast442_26_257.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey424-26-257 4,2,4 ${OUT_DIR}/fast424_26_257.hpp ${OPTIONS}
python ${SCRIPT} ${ELIM_DIR}/grey424-26-206 4,2,4 ${OUT_DIR}/fast424_26_206.hpp ${OPTIONS}

# 4,3,3
python ${SCRIPT} ${ALGS_DIR}/grey433-29-234 4,3,3 ${OUT_DIR}/fast433_29_234.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey343-29-234 3,4,3 ${OUT_DIR}/fast343_29_234.hpp ${OPTIONS}

# 4,3,2
python ${SCRIPT} ${ALGS_DIR}/grey432-20-144 4,3,2 ${OUT_DIR}/fast432_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey423-20-144 4,2,3 ${OUT_DIR}/fast423_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey324-20-144 3,2,4 ${OUT_DIR}/fast324_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey342-20-144 3,4,2 ${OUT_DIR}/fast342_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey234-20-144 2,3,4 ${OUT_DIR}/fast234_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey243-20-144 2,4,3 ${OUT_DIR}/fast243_20_144.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/classical423-24-72 4,2,3 ${OUT_DIR}/classical423.hpp ${OPTIONS}

# 4,2,2
python ${SCRIPT} ${ALGS_DIR}/grey422-14-84 4,2,2 ${OUT_DIR}/fast422_14_84.hpp ${OPTIONS}

# 3,3,3
python ${SCRIPT} ${ALGS_DIR}/grey333-23-152 3,3,3 ${OUT_DIR}/fast333_23_152.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey333-23-221 3,3,3 ${OUT_DIR}/fast333_23_221.hpp ${OPTIONS}
python ${SCRIPT} ${ELIM_DIR}/grey333-23-125 3,3,3 ${OUT_DIR}/fast333_23_125.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/smirnov333-23-139 3,3,3 ${OUT_DIR}/smirnov333_23_139.hpp ${OPTIONS}
python ${SCRIPT} ${ELIM_DIR}/smirnov333-23-128 3,3,3 ${OUT_DIR}/smirnov333_23_128.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/classical333-27-81 3,3,3 ${OUT_DIR}/classical333.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/schonhage333-21-117-approx 3,3,3 ${OUT_DIR}/schonhage333_21_117_approx.hpp ${OPTIONS}

# 3,3,2
python ${SCRIPT} ${ALGS_DIR}/grey332-15-103 3,3,2 ${OUT_DIR}/fast332_15_103.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/grey323-15-103 3,2,3 ${OUT_DIR}/fast323_15_103.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/hk332-15-94 3,3,2 ${OUT_DIR}/hk332_15_94.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/hk323-15-94 3,2,3 ${OUT_DIR}/hk323_15_94.hpp ${OPTIONS}
python ${SCRIPT} ${ELIM_DIR}/hk323-15-84 3,2,3 ${OUT_DIR}/hk323_15_84.hpp ${OPTIONS}
python ${SCRIPT} ${ELIM_DIR}/grey323-15-89 3,2,3 ${OUT_DIR}/fast323_15_89.hpp ${OPTIONS}

# 3,2,2
python ${SCRIPT} ${ALGS_DIR}/grey322-11-50 3,2,2 ${OUT_DIR}/fast322_11_50.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/bini322 3,2,2 ${OUT_DIR}/bini322.hpp ${OPTIONS}

# 2,2,2
python ${SCRIPT} ${ALGS_DIR}/strassen 2,2,2 ${OUT_DIR}/strassen.hpp ${OPTIONS}
python ${SCRIPT} ${ALGS_DIR}/classical222-8-24 2,2,2 ${OUT_DIR}/classical222.hpp ${OPTIONS}
