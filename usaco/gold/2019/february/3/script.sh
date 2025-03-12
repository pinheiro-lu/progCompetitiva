for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > in.in
	./a.out < in.in > test.out
	./brute < in.in > out.out
	diff -w test.out out.out || break
done
