#ifndef ordenacao_h
#define ordenacao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int ouros,
        prata,
        bronze;
}Pais;

Pais *alocaPais(Pais *m, int n);

void lePais(Pais *m, int n);

void trocaPais(Pais *m1, Pais *m2);

void ordenaPais(Pais *m, int n);

void printaPaises(Pais *m, int n);

Pais *desalocaPais(Pais *m);


#endif