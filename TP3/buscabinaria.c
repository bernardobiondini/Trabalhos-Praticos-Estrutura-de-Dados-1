#include "buscabinaria.h"

double buscaBinaria(int *v, long int n, long int a){
    double i, esq, dir, area;

    esq = 0;
    dir = v[n - 1];

    do{
        area = 0;
        i = (esq + dir) / 2;
        for (int j = 0; j < n; j++){
            if(v[j] > i) area += v[j] - i;
        }

        if(a < area) esq = i + ((double)1/1000000);
        else dir = i - ((double)1/1000000);
        
    }while(esq <= dir);
    
    return i;
}
int possivel(int *v, long int n, long int a){
    double area = 0;

    for (int i = 0; i < n; i++){
        area += v[i];
    }

    if(area < a) return 0;
    return 1;
}

double top(int *v, long int n, long int a){
    double area;

    for (int i = 0; i < n; i++){
        area += v[i];
    }

    if(area == a) return area;
    return -1;
}

void ordenacao(int *v, long int n){
    int l = 0, r = n;
    int b, esq, dir;
    b = 1;
    while(b < n){
        esq = 0;
        while (esq + b < n){
            dir = esq + 2 * b;
            if (dir > n) dir = n;
            MERGE(v, esq, esq + b - 1,dir - 1);
            esq = esq + 2 * b;
        }
        b = b * 2;
    }
}
void MERGE(int *v, int l, int m, int r){
    int size_l, size_r, i, j;
    size_l = (m - l + 1);
    size_r = (r - m);
    int *vetL = (int *)malloc(size_l * sizeof(int));
    int *vetR = (int *)malloc(size_r * sizeof(int));
    for(i = 0; i < size_l; i++) vetL[i] = v[i + l];
    for(j = 0; j < size_r; j++) vetR[j] = v[m + j + 1];
    i = 0;
    j = 0;
    for(int k = l; k <= r; k++){
        if (i == size_l) v[k] = vetR[j++];
        else if (j == size_r) v[k] = vetL[i++];
        else if (vetL[i] <= vetR[j]) v[k] = vetL[i++];
        else v[k] = vetR[j++];
    }
    free(vetL);
    free(vetR);
}