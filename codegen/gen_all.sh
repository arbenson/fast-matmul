# Re-generate all of the header files.  This can be useful for changes to the code generator.

SCRIPT=gen.py
OUT_DIR=..

# 4,3,3
python ${SCRIPT} grey433-29-234 4,3,3 ${OUT_DIR}/grey-fast433.hpp

# 4,3,2
python ${SCRIPT} grey432-20-144 4,3,2 ${OUT_DIR}/grey-fast432.hpp
python ${SCRIPT} grey423-20-144 4,2,3 ${OUT_DIR}/grey-fast423.hpp
python ${SCRIPT} grey324-20-144 3,2,4 ${OUT_DIR}/grey-fast324.hpp
python ${SCRIPT} grey342-20-144 3,4,2 ${OUT_DIR}/grey-fast342.hpp
python ${SCRIPT} grey234-20-144 2,3,4 ${OUT_DIR}/grey-fast234.hpp
python ${SCRIPT} grey243-20-144 2,4,3 ${OUT_DIR}/grey-fast243.hpp

# 3,3,3
python ${SCRIPT} grey333-23-152 3,3,3 ${OUT_DIR}/grey-fast333.hpp

# 3,3,2
python ${SCRIPT} grey332-15-103 3,3,2 ${OUT_DIR}/grey-fast332.hpp
python ${SCRIPT} hk332-2 3,3,2 ${OUT_DIR}/hk332.hpp

# 3,2,2
python ${SCRIPT} grey322-11-50 3,2,2 ${OUT_DIR}/grey-fast322.hpp
python ${SCRIPT} bini322 3,2,2 ${OUT_DIR}/bini322.hpp

# 2,2,2
python ${SCRIPT} strassen 2,2,2 ${OUT_DIR}/strassen.hpp
python ${SCRIPT} classical 2,2,2 ${OUT_DIR}/classical.hpp


