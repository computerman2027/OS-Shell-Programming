#!/bin/bash

# Start first infinite loop in background
while true
do
    echo "Process 1 running..."
    sleep 1
done &
PID1=$!

# Start second infinite loop in background
while true
do
    echo "Process 2 running..."
    sleep 1
done &
PID2=$!

echo "PId 1 = $PID1"
echo "pid 2 = $PID2"
# Let the processes run for a few seconds
sleep 15

# Terminate both infinite loops
echo "Terminating processes..."
kill $PID1
kill $PID2

echo "Processes terminated."
