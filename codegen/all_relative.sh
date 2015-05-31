# Compute relative quantities for several algorithms.

SCRIPT="python relative_quantities.py"
DIR="algorithms"
$SCRIPT $DIR/classical222-8-24 2,2,2
$SCRIPT $DIR/strassen 2,2,2
$SCRIPT $DIR/grey322-11-50 3,2,2
$SCRIPT $DIR/madan232-11-48 2,3,2
$SCRIPT $DIR/grey422-14-84 4,2,2
#242
$SCRIPT $DIR/grey323-15-103 3,2,3
$SCRIPT $DIR/grey332-15-103 3,3,2
$SCRIPT $DIR/smirnov333-23-139 3,3,3
$SCRIPT $DIR/grey234-20-144 2,3,4
$SCRIPT $DIR/grey424-26-257 4,2,4
$SCRIPT $DIR/grey343-29-234 3,4,3
$SCRIPT $DIR/grey442-26-257 4,4,2
$SCRIPT $DIR/grey433-29-234 4,3,3
$SCRIPT $DIR/smirnov336-40-960 3,3,6
$SCRIPT $DIR/smirnov363-40-960 3,6,3


