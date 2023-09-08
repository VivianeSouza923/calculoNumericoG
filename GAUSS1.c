#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	
}

double ** criaMatriz(int l, int c){
	/*Se houver mem�ria dispon�vel, cria uma matriz de double com l linhas e c colunas e devolve o endere�o base da matriz. Caso contr�rio, devolve nulo*/
	
	int i, j;
	double **m;
	
	m = malloc(sizeof(double *) * l);
	if(m == NULL){ // falta de mem�ria
		return NULL;
	}
	
	for(i = 0; i < l; i++){
		m[i] = malloc(sizeof(double)* c);
		if(m[i] == NULL){
			// falta de mem�ria
			for(j = 0; j < i; j++){
				free(m[j]);
				
			}
			free(m);
			return NULL;
		}
	}
	return m;	
}
// FIM DA FUN��O CRIAMATRIZ

void leMatriz(double **m, int l, int c){
	/*L� valores para uma matriz de double com l linhas e c colunas alocada dinamicamente*/
	
	int i, j;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("m[%d][%d]: ", i + 1, j + 1);
			scanf("%lf", &m[i][j]);
		}
	}
}
// FIM DA FUN��O LEMATRIZ

void imprimeMatriz(double **m, int l, int c){
	/*imprime o conte�do de uma matriz de double com l linhas e c colunas, alocada dinamicamente*/
	
	int i, j;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; i++){
			printf("%10.3lf ", m[i][j])
		}
		printf("\n");
	}
}
// FIM DA FUN��O IMPRIMEMATRIZ
