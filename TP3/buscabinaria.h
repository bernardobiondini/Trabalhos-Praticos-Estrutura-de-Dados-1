#ifndef buscabinaria_h
#define buscabinaria_h

#include <stdio.h>
#include <stdlib.h>


double buscaBinaria(int *v, long int n, long int a);
int possivel(int *v, long int n, long int a);
double top(int *v, long int n, long int a);
void ordenacao(int *v, long int n);
void MERGE(int *v, int l, int m, int r);

#endif