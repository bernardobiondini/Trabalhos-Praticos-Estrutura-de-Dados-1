#ifndef corretor_h
#define corretor_h

typedef struct instrucao Instrucao;

Instrucao *alocaInstrucoes(Instrucao *instrucao, int n);
Instrucao *liberaInstrucoes(Instrucao *instrucao);
void leQuantasInstrucoes(int *n);
void leInstrucao(Instrucao *instrucao, int n);
int paraIncorretos(Instrucao *instrucao, int n);
int paraCorretos(Instrucao *instrucao, int n);
int confereSeAcrescenta20(Instrucao *instrucao, int n, int i);
int quantosCorretos(Instrucao *instrucao, int n);
void imprimeResultado(int submissoesCorretas, int tempoTotal);

#endif