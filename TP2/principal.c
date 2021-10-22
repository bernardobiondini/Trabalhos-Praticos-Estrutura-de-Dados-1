#include "ordenacao.h"

int main(){
    int n;
    Pais *pais;

    scanf("%d", &n);

    pais = alocaPais(pais, n);

    lePais(pais, n);
    ordenaPais(pais, n);

    printaPaises(pais, n);

    pais = desalocaPais(pais);
    pais = NULL;

    return 0;
}