#!/bin/bash

if test ! -f file
then
    echo 0 > file
fi

if ln file file.lock # lock
then
    for i in `seq 1 100`
    do
        last=`tail -1 file`
        new=$((last+1))
        echo $new >> file
    done
    rm file.lock # unlock
fi