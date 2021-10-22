#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct instrucao{
    char identificador;
    int tempo;
    char situacao[15];
};
Instrucao *alocaInstrucoes(Instrucao *instrucao, int n){
    instrucao = (Instrucao*) malloc(n * sizeof(Instrucao));
    if(instrucao == NULL){
        exit(1);
    }
    return instrucao;
}
Instrucao *liberaInstrucoes(Instrucao *instrucao){
    free(instrucao);
    instrucao = NULL;
    return instrucao;
}
void leQuantasInstrucoes(int *n){
    scanf("%d", n);
}
void leInstrucao(Instrucao *instrucao, int n){
    for (int i = 0; i < n; i++){
        scanf(" %c", &instrucao[i].identificador);
        scanf("%d", &instrucao[i].tempo);
        scanf(" %s", instrucao[i].situacao);
    }
}

int paraIncorretos(Instrucao *instrucao, int n){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if(strcmp(instrucao[i].situacao, "incompleto")==0){
            cont += confereSeAcrescenta20(instrucao, n, i);
        }
    }
    return cont;  
}
int paraCorretos(Instrucao *instrucao, int n){
    int totalDoTempo = 0;
    for (int i = 0; i < n; i++){
        if(strcmp(instrucao[i].situacao, "correto")==0){
            totalDoTempo += instrucao[i].tempo;
        }
    }
    return totalDoTempo;
}
int confereSeAcrescenta20(Instrucao *instrucao, int n, int i){
    int cont = 0;
    char c = instrucao[i].identificador;
    for (int j = i; j < n; j++){
        if(c == instrucao[j].identificador && strcmp(instrucao[j].situacao, "correto")==0){
            return 1;
        }
    }
    return cont;
}
int quantosCorretos(Instrucao *instrucao, int n){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if(strcmp(instrucao[i].situacao, "correto") == 0){
            cont++;
        }
    }
    return cont;
}
void imprimeResultado(int submissoesCorretas, int tempoTotal){
    printf("%d %d\n", submissoesCorretas, tempoTotal);
}
/*
    //deixar em funcoes diferentes pois precisaremos de fazer mais coisa dentro dos ifs
    //temos o tempo total que sera o tempo de uma submissao + o tempo da outra
    //o tempo total sera sempre o que foi colocado na entrada.... + os 20 de erro
    //na funcao de erro tera que se analisar o proximo comando
    //*fazer só uma funcao para conferir se é incompleto?? já que o tempo total seria 
    //*o que foi colocado na entrada?? e só acrescentaria + 20 se o problema fosse realmente correto??
    //fazer um for e se o identificador, ao percorrer todas as instrucoes, encontar um correto soma 20?
    //funcao para ver quantas submissoes corretas
    for(int i = 0; i < n; i++){
        if(strcmp(instrucao[i]->situacao, correto)){
            instrucao[i]->total = instrucao[i]->tempo;
        }
        else{
            instrucao[i]->parcial += 20;
        }
    }
*/