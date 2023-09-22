#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.000001

/*Se houver memória suficiente, cria uma matriz de double com l linhas e c colunas e devolve um ponteiro para a matriz.
Se não houver memória suficiente, ela devolve um ponteiro nulo*/
double **criaMatriz(int l, int c){

	// ponteiro que aponta para outro ponteiro do tipo double
	double **m;
	int i, j; // contador para o laço
	//aqui vai alocar dinamicamente a matriz na varivel m
	m = malloc(sizeof(double*)*l);

	//teste se há memória
	if(m==NULL){
		return NULL;
	}

	for(i=0;i<l;i++){
		m[i]=malloc(sizeof(double)*c);

		if(m[i] == NULL){
			for(j=0;j<i;j++){
				free(m[j]);
			}free(m);
			printf("%d\n", i);
			 return NULL;
		}
	}
	return m;




}// fim criaMatriz

/*lê valores para uma matriz de double com l linhas e c colunas alocada dinamicamente*/
void leMatriz(double **m, int l, int c){

	int i, j;

	for(i=0;i<l;i++){

		for(j=0;j<c;j++){

			printf("m[%d][%d]: ", i+1, j+1);
			scanf("%lf", &m[i][j]);
		}
	}

}// fim leMatriz



/*Imprime o conteúdo de uma matriz de double com l linhas e c colunas alocada dinamicamente*/
void imprimeMatriz(double **m, int l, int c){

	int i, j;

	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%10.3lf ", m[i][j]);
		}
		printf("\n");
	}

}// Fim imprimeMatriz




/*função sretro - Recebe m, a matriz aumentada de um SL TS com n variáveis. Se o SL for determinado, armazena em x a solução do SL
e devolve 0; Se for indeterminado, armazena em x uma solução e devolve 1; Se for incompatível, devolve 2. */

int sRetro(double **m, int n, double x[]){

	int i, j, tipo = 0; double soma;

	// classificação do SL
	for(i=n-1; i>=0; i--){
		soma = 0;
		for(j=i+1; j<n; j++){
			soma = soma + m[i][j]*x[j];
		}
		if(m[i][i] == 0){
			if (fabs(m[i][n] - soma) < EPSILON){ // x[i] é variável livre
				x[i] = 0;
				tipo = 1;
			}
			else{
				return 2; /*SL incompatível*/
			}
		}
		else{
			x[i] = (m[i][n] - soma)/m[i][i];
		}
	}
	return tipo; // SL determinado
} // fim sRetro


/*Recebe m, a matriz aumentada de um SL com n variáveis e transforma m na matriz aumentada de um SL TS equivalente*/

void Gauss(double **m, int n){
	int i, j, k; double mult, *aux;

	// caso o pivô seja nulo
	for(i=0;i<n-1;i++){
		if(m[i][i]==0){
			j = i+1;
			while(j<n && m[j][i] == 0){
				j++;

			}
			if(j<n){ // troca de linhas
				aux = m[i];
				m[i] = m[j];
				m[j] = aux;
				
				printf("Troquei a linha\n");
			}
		}
		if(m[i][i]!= 0){ // resolução do SL sem os empecilhozinhos
			for(j=i+1;j<n;j++){
				mult= -m[j][i]/m[i][i];
				m[j][i]=0;
				for(k=i+1;k<=n;k++){
					m[j][k] = m[j][k] + mult*m[i][k];
				}
			}
		}
	}
} // Fim Gauss

// código main
int main(){

	int i, n, tipo; double **m, *x;
	printf("QUANTIDADE DE VARIAVEIS: ");
	scanf("%d", &n);

	m = criaMatriz(n, n+1);
	x = malloc(sizeof(double)*n);

	if(m == NULL||x == NULL){
	 /*falta de memória*/
		printf("NAO DEU CERTO\b!\n FALTA DE MEMORIA\n");
		return 1;
}
	leMatriz(m, n, n+1);
	imprimeMatriz(m, n, n+1);
	Gauss(m, n);
	printf("SL TS: \n");
	imprimeMatriz(m, n, n+1);
	tipo = sRetro(m, n, x);

	if(tipo == 2){
		printf("SL incompativel\n");
	}
	else{
		printf("SL %sDETERMINADO\n", tipo?"IN":" "); //ifAndElse ABREVIADO! DEPOIS VEJA.
		for(i=0; i<n;i++){
			printf("x[%d]:  %10.3lf\n", i+1, x[i]);
		}
	}

	return 0;

} // fim main




/* bizu: \b dá um bip no programa, só pra chamar a atenção do usuário */






