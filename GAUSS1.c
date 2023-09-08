#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	
}

double ** criaMatriz(int l, int c){
	/*Se houver memória disponível, cria uma matriz de double com l linhas e c colunas e devolve o endereço base da matriz. Caso contrário, devolve nulo*/
	
	int i, j;
	double **m;
	
	m = malloc(sizeof(double *) * l);
	if(m == NULL){ // falta de memória
		return NULL;
	}
	
	for(i = 0; i < l; i++){
		m[i] = malloc(sizeof(double)* c);
		if(m[i] == NULL){
			// falta de memória
			for(j = 0; j < i; j++){
				free(m[j]);
				
			}
			free(m);
			return NULL;
		}
	}
	return m;	
}
// FIM DA FUNÇÃO CRIAMATRIZ

void leMatriz(double **m, int l, int c){
	/*Lê valores para uma matriz de double com l linhas e c colunas alocada dinamicamente*/
	
	int i, j;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("m[%d][%d]: ", i + 1, j + 1);
			scanf("%lf", &m[i][j]);
		}
	}
}
// FIM DA FUNÇÃO LEMATRIZ

void imprimeMatriz(double **m, int l, int c){
	/*imprime o conteúdo de uma matriz de double com l linhas e c colunas, alocada dinamicamente*/
	
	int i, j;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; i++){
			printf("%10.3lf ", m[i][j])
		}
		printf("\n");
	}
}
// FIM DA FUNÇÃO IMPRIMEMATRIZ
