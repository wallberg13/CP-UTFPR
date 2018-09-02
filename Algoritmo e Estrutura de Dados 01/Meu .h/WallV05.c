#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "WallV05.h"

void carrega(descr_hashtable *tabela){
	FILE *arquivo = fopen("./dados.txt","r");
	while(!feof(arquivo)){
		char nome[30];
		double valor;
		fscanf(arquivo, "%lf %[^\n]s", &valor, nome);
		insere_hashtable(tabela, nome, valor);
		puts(nome);
	}
	fclose(arquivo);
}

int main(){
	descr_hashtable tabela;
	inicializa_hashtable(&tabela);
	carrega(&tabela);
}

//Calcula o Hash
int hash(char* texto){
	int soma;
	for(soma = 0; *texto != '\0'; texto++){
		soma += texto[0];
	}
	return soma % MAX_HASHTABLE;
}

//Inicializa a Tabela
void inicializa_hashtable(descr_hashtable *table){
	for(int i = 0; i<MAX_HASHTABLE; i++){
		table->tabela[i] = NULL;
	}
	table->cont = 0;
}

//Insere um valor double associado a uma string;
void insere_hashtable(descr_hashtable *table, char* texto, double valor){
	//calcula o hash
	int h = hash(texto);
	
	//localiza na lista
	if(table->tabela[h] == NULL){
		no_lista *no = malloc(sizeof(no_lista));
		strcpy(no->chave,texto);
		no->valor = valor;
		no->link = NULL;
		table->tabela[h] = no;
		table->cont++;
	}else{ //senão, localiza na lista
		no_lista *aux = table->tabela[h];
		no_lista *ant = NULL;
		
		while(aux != NULL && strcmp(aux->chave, texto) < 0){
			ant = aux;
			aux = aux->link;
		}
		
		//se achou, atualiza o valor
		if(aux != NULL && strcmp(aux->chave, texto) == 0){
			aux->valor = valor;
		}else{ //Não existe, Inclui
			//Cria um no
			no_lista *no = malloc(sizeof(no_lista));
			strcpy(no->chave,texto);
			no->valor = valor;
			table->cont++;
			
			//senão inclui um novo
			if(ant == NULL){
				table->tabela[h] = no;
			}
			else{
				ant->link = no;
			}
			no->link = aux;
		}
	}
}

//Recupera o valor de uma string ou retorna NaN se não existe (NaN = not-a-number)
double consulta_hastable(descr_hashtable *table, char *texto){
	int h = hash(texto);
	
	if(table->tabela[h] == NULL)
		return nan(""); //não achou!!
	
	
	no_lista *aux = table->tabela[h];
	while(strcmp(aux->chave, texto) != 0){
		aux = aux->link;
	}
	if(aux != NULL)
		return aux->valor;
	else
		return nan(""); //não achou

}

//desasspcoa p textp dp valor (remove da tabela)
void removeH(descr_hashtable *table, char* nome){
	
}

//destroi_hastable
void destroi_hastable(descr_hashtable *table){
	
}
