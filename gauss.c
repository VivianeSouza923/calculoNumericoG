#include<stidio.h>
#include<stdlib.h>
//#include<math.h>

/*Se houver mem�ria suficiente, cria uma matriz de double com l linhas e c colunas e devolve um ponteiro para a matriz. Se n�o houver mem�ria suficiente, ela devolve um ponteiro nulo*/
double **criaMatriz(int l, int c){
	
	double **m; 
	int i; // contador para o la�o
	m = malloc(sizeof(double*)*l);
	
	//teste se h� mem�ria
	if(m==NULL){
		return NULL;
	}
	
	for(i=0;i<l;i++){
		m[i]=malloc(sizeof(double)*c);
		
		if(m[i] == NULL){
			for(j=0;j<i;j++){
				free(m[j]);
			}free(m);
			 return NULL;
		}
	}
	return m;
	
	
	
	
}// fim criaMatriz

/*l� valores para uma matriz de double com l linhas e c colunas alocada dinamicamente*/
void leMatriz(double **m, int l, int c){
	
	int i, j;
	
	for(i=0;i<l<i++){
		
		for(j=0;j<c;j++){
			
			printf("m[%d][%d]: ", i+1, j+1);
			scanf("%lf", &m[i][j]);
		}
	}
	
}// fim leMatriz



/*Imprime o conte�do de uma matriz de double com l linhas e c colunas alocada dinamicamente*/
void imprimeMatriz(double **m, int l, int c){
	
	int i, j;
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%10.3lf ", m[i][j]);
		}
		printf("\n");
	}
	
}// Fim imprimeMatriz

	
	
	
	
	
	
	
	

