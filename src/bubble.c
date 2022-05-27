#include "bubble.h"

void InterativeBubbleSort(Fila *f, int n) {
    
    Item vector[n];
    Block *aux;
    aux = f->first->prox;
    Item aux2;

    for(int i=0; i < n; i++){
        vector[i] = aux->data;
        aux = aux->prox;
    }

    for(int i=1; i<n; i++){ 
        for(int j=0; j<n-i; j++){
            if(vector[j].distancia > vector[j+1].distancia){
                aux2 = vector[j];
	            vector[j] = vector[j+1];
	            vector[j+1] = aux2;
			}
        }
	}

    aux = f->first->prox;
    for(int i=0; i < n; i++){
        aux->data = vector[i];
        aux = aux->prox;
    }
}