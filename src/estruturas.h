#ifndef ESTRUTURAS_H 
#define ESTRUTURAS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>

typedef struct Item Item;
typedef struct Block Block;

struct Item{
	int linha;
    int coluna;
	float distancia;
};

struct Block{
	Item data;
	Block *prox;
};

#endif