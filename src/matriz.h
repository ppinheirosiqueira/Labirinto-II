#ifndef MATRIZ_H 
#define MATRIZ_H

#include"fila.h"

int** geraMatriz(int *n);
void imprimeMatriz(int **matriz, int n);
void limpaMatriz(int **matriz, int n);

float distanciaEuclidiana(int n, int linha, int coluna);
float distanciaManhattan(int n, int linha, int coluna);

#endif