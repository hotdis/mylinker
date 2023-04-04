#!/bin/bash

path=$(dirname "$0")
out=$path/../out
tests=$(ls $path)
num_successed=0
num_total=0

mkdir -p $out
touch tmp

for c in ${tests}
do
    if [ $c != $(basename $0) ] ; then 
        obj=$(basename $c .c)
        gcc $path/$c -o $out/$obj 
        echo "Testing: " $obj 
        $path/../main $out/$obj > tmp

        cat tmp | while read rows 
        do
        echo -e "\e[33m$rows\e[0m"
        done

        if [ $? -eq 0 ] ; then 
            num_successed=$((num_successed + 1))
            echo -e "\e[32mOK\e[0m"
        else 
            echo -e "\033[0;1;31mFAIL\033[0m"
        fi
        num_total=$((num_total + 1))
    fi
done

if [ $num_successed -eq $num_total ] ; then 
    echo -e "\e[32mPassed all tests($num_successed/$num_total)\e[0m"
else 
    echo -e "\033[0;1;31mPassed part of tests($num_successed/$num_total)\033[0m"
fi 

rm tmp
