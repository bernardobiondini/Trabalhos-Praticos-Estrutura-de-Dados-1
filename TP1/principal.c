#include "corretor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    Instrucao* instrucao;
    int submissoesCorretas, tempoTotal, numeroSubmissoes;
    
    leQuantasInstrucoes(&numeroSubmissoes);
    instrucao = alocaInstrucoes(instrucao, numeroSubmissoes);
    leInstrucao(instrucao, numeroSubmissoes);

    submissoesCorretas = quantosCorretos(instrucao, numeroSubmissoes);
    tempoTotal = (paraIncorretos(instrucao, numeroSubmissoes) * 20) + paraCorretos(instrucao, numeroSubmissoes);
    
    imprimeResultado(submissoesCorretas, tempoTotal);
    
    instrucao = liberaInstrucoes(instrucao);
    
    return 0;
}