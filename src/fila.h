#ifndef FILA_H 
#define FILA_H

#include "estruturas.h"
#include "matriz.h"

typedef struct Fila Fila;

struct Fila{
	Block *first;
	Block *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d, int *contagem);
void Desenfileira(Fila *f);
void FImprime(Fila *f);

void FAndarBaixo(int **matriz, Fila *f, int n, int *contagem, int opcao);
void FAndarCima(int **matriz, Fila *f, int n, int *contagem, int opcao);
void FAndarDireita(int **matriz, Fila *f, int n, int *contagem, int opcao);
void FAndarEsquerda(int **matriz, Fila *f, int n, int *contagem, int opcao);

void FilaAnda(int **matriz, Fila *f, int n, int *contagem, int opcao);

#endif