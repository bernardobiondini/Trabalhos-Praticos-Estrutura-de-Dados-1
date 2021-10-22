#include "ordenacao.h"

Pais *alocaPais(Pais *m, int n){
    m = (Pais*) malloc(n * sizeof(Pais));
    if(m == NULL){
        exit(1);
    }
    return m;
}

void lePais(Pais *m, int n){
    for (int i = 0; i < n; i++){
        scanf("%s %d %d %d", m[i].nome, &m[i].ouros, &m[i].prata, &m[i].bronze);
    }
}


void trocaPais(Pais *m1, Pais *m2){
    Pais aux;

    aux = *m1;
    *m1 = *m2;
    *m2 = aux;
}


void ordenaPais(Pais *m, int n){
    Pais aux;
    int troca;
    for (int i =  0; i < n; i++){
        for (int j = 1; j < n-i; j++){
            if (m[j].ouros > m[j-1].ouros){
                trocaPais(&m[j], &m[j-1]);
            }
            else if(m[j].ouros == m[j-1].ouros){
                if(m[j].prata > m[j-1].prata){
                    trocaPais(&m[j], &m[j-1]);
                }
                else if(m[j].prata == m[j-1].prata){
                    if(m[j].bronze > m[j-1].bronze){
                        trocaPais(&m[j], &m[j-1]);
                    }
                    else if(m[j].bronze == m[j-1].bronze){
                        if(strcmp(m[j].nome, m[j-1].nome) < 0){
                            trocaPais(&m[j], &m[j-1]);
                        }
                    }
                }
            }
        }
    }
}

void printaPaises(Pais *m, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d\n", m[i].nome, m[i].ouros, m[i].prata, m[i].bronze);
    }
}

Pais *desalocaPais(Pais *m){
  free(m);
  m = NULL;
  return m;
}