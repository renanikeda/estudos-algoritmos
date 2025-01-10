#!/bin/bash
if [[ $# -eq 0 ]] ; then
	echo "You must pass the C file path";
	exit 0;
fi
echo "Compiling: $1";
gcc $1.c -o outputs/$1
./outputs/$1

