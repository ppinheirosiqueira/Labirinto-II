#ifndef PILHA_H 
#define PILHA_H

#include"estruturas.h"

typedef struct Pilha Pilha;

struct Pilha{
	Block *base;
	Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d, int *contagem);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);

bool PAndarBaixo(int **matriz, Pilha *p, int n, int *contagem);
bool PAndarCima(int **matriz, Pilha *p, int *contagem);
bool PAndarDireita(int **matriz, Pilha *p, int n, int *contagem);
bool PAndarEsquerda(int **matriz, Pilha *p, int *contagem);


#endif
