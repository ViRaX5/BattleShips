#!/bin/bash
#  in terminal: chmod +x test_leaks.sh
#   ./test_leaks.sh
# 

LOG_FILE="stress_test_results.log"
TARGET="./battleships" # Make sure this matches your executable name

# Clear the old log
echo "--- Battleship Stress Test Log ---" > $LOG_FILE
echo "Running 100 iterations..."

for i in {1..100}
do
    echo "Iteration $i/100..."
    # Run valgrind in quiet mode, append output to log
    valgrind --leak-check=full --error-exitcode=1 $TARGET >> $LOG_FILE 2>&1
    echo "-----------------------------------" >> $LOG_FILE
done

echo "Done! Summary of failures:"
echo "--------------------------"
# Count how many times "ERROR SUMMARY" was NOT 0
grep "ERROR SUMMARY" $LOG_FILE | grep -v "0 errors"
# Look for memory leaks specifically
grep "definitely lost" $LOG_FILE | grep -v "0 bytes"

echo "Full details saved in $LOG_FILE"