#!/bin/bash

make part2
echo "Compilation Completed"
echo "."
echo "."
ls
echo "."
echo "."
echo "Testing Multiple Children Processes"
./part2_multichild 2
echo "."
echo "."
./part2_multichild 4
echo "."
echo "."
./part2_multichild 8
echo "."
echo "."
echo "."
echo "."
echo "Testing Chain Processes"
./part2_chainproc 2
echo "."
echo "."
./part2_chainproc 4
echo "."
echo "."
./part2_chainproc 8
