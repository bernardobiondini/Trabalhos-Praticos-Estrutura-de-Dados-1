/*
Usar busca binaria sem ordenar as alturas?
ordenando:
->altura necessaria = maior altura das tiras
->verifica se com essa altura da pra chegar a area
->diminui um da altura necessaria
->procurar alturas maiores que a altura necessaria (busca binaria)
->verifica se a soma das areas de (altura da tira - altura necessaria) = a
*/

#include "buscabinaria.h"

int main(){
    long int a, n, c;

    while(1 == 1){
        scanf("%ld %ld", &n, &a);
        //printf("%ld %ld\n", n, a);
        
        if(n == 0 && a == 0) break;

        int *v = (int *)malloc(n * sizeof(int));
        double area = 0;

        for (int i = 0; i < n; i++){
            scanf("%ld", &c);
            v[i] = c;
        }
        ordenacao(v, n);
        
        if(!possivel(v, n, a)){
            printf("-.-\n");
        }
        else if(top(v, n, a) !=- 1){
            printf("%.4lf\n:D\n", top(v, n, a));
        }
        else{
            area = buscaBinaria(v, n, a);
            printf("%.4lf\n", area);
        }

        free(v);
    }

    return 0;
}