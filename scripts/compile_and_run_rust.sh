#!/bin/bash
if [[ $# -eq 0 ]] ; then
	echo "You must pass the C file path";
	exit 0;
fi
echo "Compiling: $1";
rustc $1.rs -o outputs/$1 && ./outputs/$1

