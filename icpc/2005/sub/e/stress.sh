#!/usr/bin/bash

for ((i = 1; ; i++)); do
	echo "Iteration: $i"
	python3 gen.py > in.in
	./a.out < in.in > test.out
	./brute < in.in > out.out
	if ! diff test.out out.out; then
		echo "Error"
		exit 1
	fi
done
