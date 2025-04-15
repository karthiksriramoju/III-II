#!/usr/bin/bash

echo "Enter a directory name:"
read dname

echo "The list of directory files in the directory $dname are:"
cd "$dname"
ls -l | grep '^d'
