#include "Funcoes.h"
#include<stdio.h>
#include<stdlib.h>

int main(void){
	Me me, me1,me2;
	inicializa_matriz(&me,11,11);
	inicializa_matriz(&me1,11,11);
	inicializa_matriz(&me2,11,11);
	
	sorteio_posicoes(&me);
	printf("MATRIZ 1\n");
	mostrar_matriz(&me);
	printf("\n");
	
	printf("MATRIZ 2\n");
	sorteio_posicoes(&me1);
	mostrar_matriz(&me1);
	printf("\n");
	
	printf("SOMA\n");
	soma_matriz(&me,&me1,&me2);
	mostrar_matriz(&me2);
	printf("\n");
	
	
}

/**int Menu(){
	Me me, me1, me2;
	char resp;
	int i,j;
	
	printf("Insira as dimensões da Matriz!!");
	printf("Quantidade de Linhas: ");
	scanf("%d",&i);
	
	
	while(resp != '0'){
		system("clear");
		printf("********T3 - Wall Berg********");
		printf("1 - Adicionar Elemento \n");
		printf("2 - Remover Elemento \n");
		printf("3 - Verificar Elemento \n");
		printf("4 - Gerar uma Matriz Soma e Imprimir as 3 Matrizes(m1,m2, ms)\n");
		printf("5 - Mostrar Matriz");
		printf("0 - Sair \n\n");
		printf("Sua Resposta: ");
		//__fpurge(stdin);
		scanf("%c",&resp);
		
		switch (resp){
			case '1':
		}
		
	}
}*/

