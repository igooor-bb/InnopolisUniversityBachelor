#!/bin/bash

((size=64))
for i in {1..10}
do
    rm -f fileB.txt
    echo
    echo "Buffer size: $size"
    gcc -DBUF_SIZE=$size copy.c -o copy
    time ./copy fileA.txt fileB.txt
    ((size = size * 2))
done
