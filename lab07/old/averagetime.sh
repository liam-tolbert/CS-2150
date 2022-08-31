#!/bin/bash

echo "enter the exponent for counter.cpp"
read e

if [[ $e == "quit" ]]
then
    exit 4
fi

sum=0
for ((i==0; i<=e; i++))
do
    RUNNING_TIME=`./a.out $e`
    echo "Running iteration ${i}"
    echo "time taken = ${RUNNING_TIME} ms"
    sum=$(($sum+$RUNNING_TIME))
done
echo "${e} iterations took ${sum} ms"
echo "Average time was $((sum/5)) ms"

