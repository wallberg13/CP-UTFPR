#ifndef POKEAGENDA_H_INCLUDED
#define POKEAGENDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = 0;

typedef struct{
    int numero;
    char tipo; // N)ormal A)gua F)ogo G)grama T)erra R)ocha E)letrico V)eneno P)siquico I)nseto H)gelo
    char nome[15];
} PokeRegistro;

typedef struct Poke{
    PokeRegistro pokemon;
	 struct Poke *ant;
	 struct Poke *prox;
} PokeAgenda;

// inicializa a lista
void inicializar_lista(PokeAgenda **l){
	*l = NULL;
}

char* tipo_pokemon(char tipo){
    switch (tipo){
        case 'A': return "Agua";
        case 'F': return "Fogo";
        case 'D': return "Dragao";
        case 'E': return "Eletrico";
        case 'G': return "Gelo";
        case 'I': return "Inseto";
        case 'N': return "Normal";
        case 'P': return "Psiquico";
        case 'R': return "Rocha";
        case 'T': return "Terra";
        case 'V': return "Veneno";
        default : return "Desconhecido";
    }
}

/**
 * Função que mostra toda a lista do tipo PokeAgenda.
 */
int listar_pokemon_crescente(PokeAgenda **l){
	PokeAgenda *aux;
	aux = *l;
	while(aux != NULL){
		char tipo = aux->pokemon.tipo;
		printf("#%03d %-15s %s\n",aux->pokemon.numero , aux->pokemon.nome, tipo_pokemon(tipo));
		aux = aux->prox;
	}
	return 1;
}

int listar_pokemon_decrescente(PokeAgenda **l){
	PokeAgenda *aux;
	aux = *l;
	while(aux->prox != NULL) //Percorre ate o final da lista, para depois, de lá, volta imprimindo
		aux = aux->prox;
	while(aux != NULL){
		char tipo = aux->pokemon.tipo;
		printf("#%03d %-15s %s\n",aux->pokemon.numero , aux->pokemon.nome, tipo_pokemon(tipo));
		aux = aux->ant;
	}
}

int inserir_lista_ordenado(PokeAgenda **l, PokeRegistro *pokemon){
	PokeAgenda *aux1, *n, *aux2;
	n = (PokeAgenda *)malloc(sizeof(PokeAgenda));
	n->pokemon = *pokemon;
	if(*l == NULL){
		n->prox = NULL;
		n->ant = NULL;
		*l = n;
	}else{
		aux1 = *l;
		aux2 = NULL;
		while((n->pokemon.numero > aux1->pokemon.numero)&&(aux1 != NULL)){
			aux2 = aux1;
			aux1 = aux1->prox;
			if(aux1 == NULL) //Gambiarra!! Tive que colocar porque 
				break; 		  //sem ela,o primeiro pokemon do arquivo iria ficar
		}						  //sempre na primeira posição pq não foi feito a comparação
		if(aux2 == NULL){ //Se aux2 == NULL, é por que é para inserir no inicio
			n->prox = *l;
			n->ant = NULL;
			(*l)->ant = n;
			*l = n;
		}else{ //Insere em qualquer posição
			n->prox = aux1;
			aux2->prox = n;
			n->ant = aux2;
			if(aux1 != NULL) // Tratamento para quando o aux1 estiver no final da fila
				aux1->ant = n;//pq se não da segfault 
		}
	}
}


int remover_por_numero(PokeAgenda **l, int num){
	PokeAgenda *aux;
	aux = *l;
	while((aux->prox != NULL)&&(aux->pokemon.numero != num))
		aux = aux->prox;
	if(*l != NULL){
		if(aux == *l){
			aux->prox->ant = NULL;
			*l = aux->prox;
		}else{
			if(aux->prox == NULL){ //Se tive no final, tem que ter condição para não dar segfault
				aux->ant->prox = NULL;
			}else{
				aux->prox->ant = aux->ant;
				aux->ant->prox = aux->prox;
			}
		}
		free(aux);
		return num;
	}else
		return 0;
}


int importar_lista(PokeAgenda **l, char *nome_arquivo){
    // abre o arquivo para leitura ("r" - read)
    FILE *arquivo = fopen(nome_arquivo,"r");
    int status;
    PokeRegistro pokemon;
    
    while ((status = fscanf(arquivo, "%d %c %s",&pokemon.numero,&pokemon.tipo,pokemon.nome)) != EOF){
      if(status == 3){
			inserir_lista_ordenado(l,&pokemon);
		}else
			return -1;
    }    
    fclose(arquivo); // fecha arquivo
    return(1);
}

int pesquisar_poke_nome(PokeAgenda **l, char nome[]){
	PokeAgenda *aux;
	aux = *l;
	while((aux->prox != NULL)&&(strcmp(aux->pokemon.nome,nome))){
		aux = aux->prox;
	}
	if(aux->prox == NULL){
		printf("Pokemon não encontrado!! \n");
		return 0;
	}else{
		char tipo = aux->pokemon.tipo;
		printf("#%03d %-15s %s\n",aux->pokemon.numero , aux->pokemon.nome, tipo_pokemon(tipo));
		return 1;
	}
}

int destruir_pokedex(PokeAgenda **l){
	PokeAgenda *aux; aux = *l;
	while(*l != NULL){
		aux = (*l)->prox;
		free(*l);
		*l = aux;
	}
}
#endif // POKEAGENDA_H_INCLUDED
