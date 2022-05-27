#include "pilha.h"

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d, int *contagem){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
	*contagem = *contagem + 1;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("Linha: %d Coluna: %d\n", aux->data.linha, aux->data.coluna);
		aux = aux->prox;
	}

}

bool PAndarBaixo(int **matriz, Pilha *p, int n, int *contagem){
	int aux;
	Item NovoItem;
	aux = p->top->data.linha + 1;
	if(aux < n && matriz[aux][p->top->data.coluna] == 0){
		matriz[aux][p->top->data.coluna] = 1;
		NovoItem.linha = p->top->data.linha + 1;
		NovoItem.coluna = p->top->data.coluna;
		Push(p, NovoItem, contagem);
		return true;
	}
	return false;
}

bool PAndarCima(int **matriz, Pilha *p, int *contagem){
	int aux;
	Item NovoItem;
	aux = p->top->data.linha - 1;
	if(aux > 0 && matriz[aux][p->top->data.coluna] == 0){
		matriz[aux][p->top->data.coluna] = 1;
		NovoItem.linha = p->top->data.linha -1;
		NovoItem.coluna = p->top->data.coluna;
		Push(p, NovoItem, contagem);
		return true;
	}
	return false;
}

bool PAndarDireita(int **matriz, Pilha *p, int n, int *contagem){
	int aux;
	Item NovoItem;
	aux = p->top->data.coluna + 1;
	if(aux < n && matriz[p->top->data.linha][aux] == 0){
		matriz[p->top->data.linha][aux] = 1;
		NovoItem.linha = p->top->data.linha;
		NovoItem.coluna = p->top->data.coluna + 1;
		Push(p, NovoItem, contagem);
		return true;
	}
	return false;
}

bool PAndarEsquerda(int **matriz, Pilha *p, int *contagem){
	int aux;
	Item NovoItem;
	aux = p->top->data.coluna - 1;
	if(aux > 0 && matriz[p->top->data.linha][aux] == 0){
		matriz[p->top->data.linha][aux] = 1;
		NovoItem.linha = p->top->data.linha;
		NovoItem.coluna = p->top->data.coluna - 1;
		Push(p, NovoItem, contagem);
		return true;
	}
	return false;
}