#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d, int *contagem){
	f->last->prox = (Block*) malloc (sizeof(Block));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
	*contagem = *contagem + 1;
}

void Desenfileira(Fila *f){
	Block *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	free(aux);
}


void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("Linha: %d Coluna: %d Distância: %f\n", aux->data.linha, aux->data.coluna, aux->data.distancia);
		aux = aux->prox;
	}

}

void FAndarBaixo(int **matriz, Fila *f, int n, int *contagem, int opcao){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.linha + 1;
	if(aux < n && matriz[aux][f->first->prox->data.coluna] == 0){
		matriz[aux][f->first->prox->data.coluna] = 1;
		NovoItem.linha = f->first->prox->data.linha + 1;
		NovoItem.coluna = f->first->prox->data.coluna;
		if (opcao == 3)
			NovoItem.distancia = distanciaEuclidiana(n, NovoItem.linha, NovoItem.coluna);
		else if (opcao == 4)
			NovoItem.distancia = distanciaManhattan(n, NovoItem.linha, NovoItem.coluna);
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarCima(int **matriz, Fila *f, int n, int *contagem, int opcao){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.linha - 1;
	if(aux > 0 && matriz[aux][f->first->prox->data.coluna] == 0){
		matriz[aux][f->first->prox->data.coluna] = 1;
		NovoItem.linha = f->first->prox->data.linha -1;
		NovoItem.coluna = f->first->prox->data.coluna;
		if (opcao == 3)
			NovoItem.distancia = distanciaEuclidiana(n, NovoItem.linha, NovoItem.coluna);
		else if (opcao == 4)
			NovoItem.distancia = distanciaManhattan(n, NovoItem.linha, NovoItem.coluna);
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarDireita(int **matriz, Fila *f, int n, int *contagem, int opcao){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.coluna + 1;
	if(aux < n && matriz[f->first->prox->data.linha][aux] == 0){
		matriz[f->first->prox->data.linha][aux] = 1;
		NovoItem.linha = f->first->prox->data.linha;
		NovoItem.coluna = f->first->prox->data.coluna + 1;
		if (opcao == 3)
			NovoItem.distancia = distanciaEuclidiana(n, NovoItem.linha, NovoItem.coluna);
		else if (opcao == 4)
			NovoItem.distancia = distanciaManhattan(n, NovoItem.linha, NovoItem.coluna);
		Enfileira(f, NovoItem, contagem);
	}
}

void FAndarEsquerda(int **matriz, Fila *f, int n,  int *contagem, int opcao){
	int aux;
	Item NovoItem;
	aux = f->first->prox->data.coluna - 1;
	if(aux > 0 && matriz[f->first->prox->data.linha][aux] == 0){
		matriz[f->first->prox->data.linha][aux] = 1;
		NovoItem.linha = f->first->prox->data.linha;
		NovoItem.coluna = f->first->prox->data.coluna - 1;
		if (opcao == 3)
			NovoItem.distancia = distanciaEuclidiana(n, NovoItem.linha, NovoItem.coluna);
		else if (opcao == 4)
			NovoItem.distancia = distanciaManhattan(n, NovoItem.linha, NovoItem.coluna);
		Enfileira(f, NovoItem, contagem);
	}
}

void FilaAnda(int **matriz, Fila *f, int n, int *contagem, int opcao){

	FAndarBaixo(matriz, f, n, contagem, opcao);
	FAndarDireita(matriz,f, n, contagem, opcao);
	FAndarCima(matriz,f, n, contagem, opcao);
	FAndarEsquerda(matriz,f, n, contagem, opcao);
	Desenfileira(f);
}