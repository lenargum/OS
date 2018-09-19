#!/bin/bash
while true; do
    if ! ln numbers numbers.lock
    then
       sleep 1
    else
        if [ ! -f numbers ]; then echo 0 > numbers; fi
        count=0
        touch numbers
        while [[ $count != 100 ]]; do
            count=`expr $count + 1`
            n=`tail -1 numbers`
            expr $n + 1 >> numbers
        done
        rm numbers.lock
        break
    fi
done