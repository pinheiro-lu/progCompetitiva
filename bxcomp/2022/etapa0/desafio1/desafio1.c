#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    float a1, a2, v1, v2, resp = 0.14, alcool, porcent;

    scanf ("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%f" , &v1);
        scanf("%f" , &a1);
        scanf("%f" , &v2);
        scanf("%f" , &a2);

        if ((a1 > resp && a2 > resp) || (a1 < resp && a2 < resp)){
            printf("Mo comedia essa mistura, presta nao\n");
        }else {
            alcool = ((v1*a1) + (v2*a2));
            porcent = alcool/(v1+v2);
            if (porcent == resp){
                printf("Bao demais que esse ta no ponto, vai ate esquentar\n");
            } else if(porcent < resp){
                if(a2 > a1){
                    printf("Arriegua tonhao, mistura tudo, o que sobrar de 1 vou estourar na garganta\n");
                } else {
                    printf("Arriegua tonhao, mistura tudo, o que sobrar de 2 vou estourar na garganta\n");
                }
            } else {
                if (a2 > a1){
                    printf("Arriegua tonhao, mistura tudo, o que sobrar de 2 vou estourar na garganta\n");
                } else {
                    printf("Arriegua tonhao, mistura tudo, o que sobrar de 1 vou estourar na garganta\n");
                }
            }
        }
    }

    return 0;
}