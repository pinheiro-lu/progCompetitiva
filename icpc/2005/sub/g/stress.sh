#!/usr/bin/bash

for ((i=1; ; i++)); do
	echo $i
	python3 gen.py > inp.txt
	time ./a.out < inp.txt > out1.txt || break
done
