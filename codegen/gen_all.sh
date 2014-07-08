# Re-generate all of the header files.  This can be useful for changes to the code generator.

SCRIPT=gen.py
OUT_DIR=../algorithms

# 5,2,2
python ${SCRIPT} grey522-18-99 5,2,2 ${OUT_DIR}/fast522_18_99.hpp

# 4,4,2
python ${SCRIPT} grey442-26-257 4,4,2 ${OUT_DIR}/fast442_26_257.hpp
python ${SCRIPT} grey424-26-257 4,2,4 ${OUT_DIR}/fast424_26_257.hpp

# 4,3,3
python ${SCRIPT} grey433-29-234 4,3,3 ${OUT_DIR}/fast433_29_234.hpp

# 4,3,2
python ${SCRIPT} grey432-20-144 4,3,2 ${OUT_DIR}/fast432_20_144.hpp
python ${SCRIPT} grey423-20-144 4,2,3 ${OUT_DIR}/fast423_20_144.hpp
python ${SCRIPT} grey324-20-144 3,2,4 ${OUT_DIR}/fast324_20_144.hpp
python ${SCRIPT} grey342-20-144 3,4,2 ${OUT_DIR}/fast342_20_144.hpp
python ${SCRIPT} grey234-20-144 2,3,4 ${OUT_DIR}/fast234_20_144.hpp
python ${SCRIPT} grey243-20-144 2,4,3 ${OUT_DIR}/fast243_20_144.hpp

# 4,2,2
python ${SCRIPT} grey422-14-84 4,2,2 ${OUT_DIR}/fast422_14_84.hpp

# 3,3,3
python ${SCRIPT} grey333-23-152 3,3,3 ${OUT_DIR}/fast333_23_152.hpp
python ${SCRIPT} smirnov333-23-139 3,3,3 ${OUT_DIR}/smirnov333_23_139.hpp
python ${SCRIPT} classical333-27-81 3,3,3 ${OUT_DIR}/classical333.hpp

# 3,3,2
python ${SCRIPT} grey332-15-103 3,3,2 ${OUT_DIR}/fast332_15_103.hpp
python ${SCRIPT} grey323-15-103 3,2,3 ${OUT_DIR}/fast323_15_103.hpp
python ${SCRIPT} hk332-2 3,3,2 ${OUT_DIR}/hk332.hpp

# 3,2,2
python ${SCRIPT} grey322-11-50 3,2,2 ${OUT_DIR}/fast322_11_50.hpp
python ${SCRIPT} bini322 3,2,2 ${OUT_DIR}/bini322.hpp

# 2,2,2
python ${SCRIPT} strassen 2,2,2 ${OUT_DIR}/strassen.hpp
python ${SCRIPT} classical222-8-24 2,2,2 ${OUT_DIR}/classical222.hpp
