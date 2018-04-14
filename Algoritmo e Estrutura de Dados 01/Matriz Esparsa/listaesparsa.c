#include <stdio.h>
#include "listaesparsa.h"

// inicializa uma a matriz esparsa
void inicializa_matriz(descr_matriz *matriz){
	for(int i = 0; i<MAX_MATRIZ; i++){
		matriz->colunas[i] = NULL;
	}
}

// insere o elemento valor na posição x,y da matriz
void insere_matriz(descr_matriz *matriz, int x, int y, double valor){
	if(valor == 0.0) return;
	
	//insere o elemento na lista encadeada da colunas
	
	no_matriz *no = malloc(sizeof(no_matriz));
	no->col = x;
	no->lin = y;
	no->valor = valor;
	no->abaixo = NULL;
	
	//insere na colunas
	if(matriz->colunas[x] == NULL){
		matriz->colunas[x] == no;
	}else{
		no_matriz *aux = matriz->colunas[x];
		no_matriz *ant = NULL;
		
		while(aux->abaixo != NULL && aux->valor < no->valor){
			ant = aux;
			aux = aux->abaixo;
		}
		
		if(ant == NULL){
			matriz->colunas[x] = no;
		}else{
			ant->abaixo = no;
		}
		
		no->abaixo = aux;
		
		if(aux == NULL){ //Inserir no fim
			
		}
	}
}

// recupera o valor na posição x,y da matriz - retorna zero se não existe
double consulta_matriz(descr_matriz *matriz, int x, int y){
    return 0;
}

// remove, se existir, o elemento na posição x,y
void exclui_matriz(descr_matriz *matriz, int x, int y){
}

// lista a matriz no formato tabular
void imprime_matriz(descr_matriz *matriz){
	for(int i = 0; i<MAX_MATRIZ; i++){
		if(matriz->colunas[x] != NULL){
			no_matriz *aux = matriz->colunas[x];
			while(aux != NULL){
				printf("(%3d,%3d) %.2f\n", aux->col, aux->lin, aux->valor);
				aux = aux->abaixo;
			}
		}
	}
}
