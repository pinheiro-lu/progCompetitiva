for ((i = 1; i <= 3; ++i)) do
    echo $i
    time ./sol < penaltisCasosTeste/entradas/entrada$i.in > out
    diff -w out penaltisCasosTeste/saídas/saida$i.out || break

done
