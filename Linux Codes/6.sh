#!/usr/bin/bash

for fname in "$@"; do
    if [ -f "$fname" ]; then
        echo "$fname is a file"
        echo "Number of lines in $fname:"
        wc -l "$fname"
    elif [ -d "$fname" ]; then
        echo "$fname is a directory"
    else
        echo "$fname does not exist"
    fi
done
