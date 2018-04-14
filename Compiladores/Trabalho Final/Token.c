#ifndef TOKEN_C_INCLUDED
#define TOKEN_C_INCLUDED

#include "headers.h"

void initialize(Token **token){
	*token = NULL;
}

/**
	Função que adiciona Tokens no fim.
*/
int add_token(Token **token,char *tkn,int num){
	Token *aux, *aux2;
	aux = (Token*)malloc(sizeof(Token));
	aux->n_token = (char *)malloc((strlen(tkn)+1)*sizeof(char));
	aux->n_token = tkn;
	//strcpy(aux->n_token,tkn);
	aux->prox = NULL;
	aux->num = num;

	if(*token == NULL)
		*token = aux;
	else{
		aux2 = *token;
		while(aux2->prox != NULL)
			aux2 = aux2->prox;
		aux2->prox = aux;
	}
	return 1;
}

/**
	Função que remove tokens no inicio.
	No analisador sintatico, a lista de tokens será a fila
	de entrada.
*/
int rem_inic(Token **token){
	Token *aux;
	if(*token != NULL){
		aux = (*token)->prox;
		free(*token);
		*token = aux;
		return 1;
	}else{
		return 0;
	}
}

/**
	Função que adiciona tokens no inicio.
	Como a estrutura que será utilizada será a mesma para a pilha e
	fila, mudando somente os elementos.
	Neste caso não preciso do numero do token, pois o mesmo só é usado na
	analise semantica.
*/
int add_ini(Token **token, char *tkn, int num){
	Token *aux;
	aux = (Token *)malloc(sizeof(Token));
	aux->n_token = (char *)malloc((strlen(tkn)+1)*sizeof(char));
	aux->n_token = tkn;
	aux->num = num;
	aux->prox = *token;
	*token = aux;
}


void print_token_list(Token **token){
	Token *aux;
	aux = *token;
	if(aux == NULL){
		printf("Lista de Tokens vazia. \n");
		return;
	}
	while(aux != NULL){
		if(aux->num != 0)
			printf("<%s,%d>",aux->n_token,aux->num);
		else
			printf("<%s>",aux->n_token);
		aux = aux->prox;
	}
	printf("\n");

}

int search(Token **token,char *tkn){
	Token *aux;
	aux = *token;
	if(aux == NULL)
		return 0;

	while(aux!=NULL){
		if(!strcmp(tkn,aux->n_token))
			return aux->num;
		aux = aux->prox;
	}
	return 0;
}
#endif //HEADERS_H_INCLUDED
