#!/bin/bash

# chmod +x stress_test.sh
# . /stress_test.sh

LOG_FILE="stress_test_results.log"
TARGET="./battleships"
LIMIT=100
spinner=('-' '/' '|' '\')

echo "--- Battleships Stress Test ---" > $LOG_FILE
echo -n "Running 100 tests...  "

for i in $(seq 1 $LIMIT); do
    # Animation logic
    printf "\b${spinner[$i % 4]}"
    
    # Run Valgrind and append to log
    echo "--- Test #$i ---" >> $LOG_FILE
    valgrind --leak-check=full --error-exitcode=1 $TARGET >> $LOG_FILE 2>&1
done

echo -e "\n\n Done! 100 runs logged to $LOG_FILE"
echo "------------------------------------------"
echo "Scanning for errors/leaks..."

# Search for any line that doesn't say "0 errors" or "0 bytes"
ISSUES=$(grep -E "definitely lost|ERROR SUMMARY" $LOG_FILE | grep -v "0 bytes" | grep -v "0 errors")

if [ -z "$ISSUES" ]; then
    echo " STATUS: PERFECT. No leaks or malfunctions detected."
else
    echo " STATUS: Issues found! Check the log."
    echo "$ISSUES" | sort -u
fi