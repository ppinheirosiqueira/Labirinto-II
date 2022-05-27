#include "fila.h"
#include "pilha.h"
#include "matriz.h"
#include "bubble.h"

int main(){
	int **matriz;
	int n, numIteBFS, numIteDFS, numIteA1 = 0, numIteA2 = 0, opcao = 0, auxBubble;
	bool possivel = true, pAndou = false;
	Fila f;
	Pilha p;
	Item iAux;

	matriz = geraMatriz(&n);

	matriz[0][0] = 1;

	printf("Essa é a matriz inicialmente: \n");
	imprimeMatriz(matriz, n);
	printf("\n\n");
	printf("------------------------------------------------------------------------------------------\n\n");

	while(opcao != 5){	
		printf("Qual método deseja testar? (Digite o número)\n");
		printf("1 - BFS\n2 - DFS\n3 - A* Euclidiana\n4 - A* Manhattan\n5 - Sair\n");
		scanf("%d", &opcao);
	
		switch(opcao){ 
		
			case 1:
				// BFS
				limpaMatriz(matriz, n);
				matriz[0][0] = 1;
				FFVazia(&f);
				numIteBFS = 0;
				iAux.linha = 0;
				iAux.coluna = 0;
				Enfileira(&f, iAux, &numIteBFS);
				
				while(matriz[n-1][n-1] != 1){
					FilaAnda(matriz, &f, n, &numIteBFS, opcao);

					if(f.first == f.last || f.first->prox == NULL){
						possivel = false;
						break;
					}
				}

				printf("Essa é a matriz final do BFS: \n");
				imprimeMatriz(matriz, n);

				if(possivel)
					printf("O número de iterações feitas pela fila até encontrar N,N foi igual a: %d\n\n", numIteBFS);
				else
					printf("Impossível chegar onde você quer!\n\n");
				printf("------------------------------------------------------------------------------------------\n\n");
				break;

			case 2:
				// DFS
				limpaMatriz(matriz, n);
				matriz[0][0] = 1;
				FPVazia(&p);
				numIteDFS = 0;
				possivel = true;
				iAux.linha = 0;
				iAux.coluna = 0;
				Push(&p, iAux, &numIteDFS);

				limpaMatriz(matriz,n);

				matriz[0][0] = 1;

				while(matriz[n-1][n-1] != 1){
					pAndou = PAndarBaixo(matriz, &p, n, &numIteDFS);
					if (!pAndou)
						pAndou = PAndarDireita(matriz, &p, n, &numIteDFS);
					if (!pAndou)
						pAndou = PAndarCima(matriz, &p, &numIteDFS);
					if (!pAndou)
						pAndou = PAndarEsquerda(matriz, &p, &numIteDFS);
					if (!pAndou){
						Pop(&p, &iAux);
						matriz[iAux.linha][iAux.coluna] = 3;
					}
					if(p.base == p.top){
						possivel = false;
						break;
					}
				}

				printf("Essa é a matriz final do DFS: \n");
				imprimeMatriz(matriz, n);
				if(possivel)
					printf("O número de iterações feitas pela pilha até encontrar N,N foi igual a: %d\n\n", numIteDFS);
				else
					printf("Impossível chegar onde você quer!\n\n");

				printf("------------------------------------------------------------------------------------------\n\n");
				break;

			case 3:
				// A* - Euclidiana
				limpaMatriz(matriz, n);
				matriz[0][0] = 1;
				FFVazia(&f);
				numIteA1 = 0;
				iAux.linha = 0;
				iAux.coluna = 0;
				Enfileira(&f, iAux, &numIteA1);
				auxBubble = 0;
				
				while(matriz[n-1][n-1] != 1){
					FilaAnda(matriz, &f, n, &numIteA1, opcao);

					auxBubble++;

					InterativeBubbleSort(&f, numIteA1 - auxBubble);

					if(f.first == f.last || f.first->prox == NULL){
						possivel = false;
						break;
					}
				}

				printf("Essa é a matriz final do A* Euclidiana: \n");
				imprimeMatriz(matriz, n);

				if(possivel)
					printf("O número de iterações feitas pela fila até encontrar N,N foi igual a: %d\n\n", numIteA1);
				else
					printf("Impossível chegar onde você quer!\n\n");
				printf("------------------------------------------------------------------------------------------\n\n");
				break;

			case 4:
				// A* - Manhattan
				limpaMatriz(matriz, n);
				matriz[0][0] = 1;
				FFVazia(&f);
				numIteA2 = 0;
				iAux.linha = 0;
				iAux.coluna = 0;
				Enfileira(&f, iAux, &numIteA2);
				auxBubble = 0;
				
				while(matriz[n-1][n-1] != 1){
					FilaAnda(matriz, &f, n, &numIteA2, opcao);
					auxBubble++;

					InterativeBubbleSort(&f, numIteA2 - auxBubble);

					if(f.first == f.last || f.first->prox == NULL){
						possivel = false;
						break;
					}
				}

				printf("Essa é a matriz final do A* Manhattan: \n");
				imprimeMatriz(matriz, n);

				if(possivel)
					printf("O número de iterações feitas pela fila até encontrar N,N foi igual a: %d\n\n", numIteA2);
				else
					printf("Impossível chegar onde você quer!\n\n");
				printf("------------------------------------------------------------------------------------------\n\n");
				break;
		}
	}

	return 0;
}