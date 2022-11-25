for ((i = 1; i <= 30; ++i)) do
    echo $i
    time ./a < input/A_$i > out
    diff -w out output/A_$i || break

done