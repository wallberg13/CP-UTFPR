#include "Funcoes.h"
#include<stdlib.h>
#include<stdio.h>

int main(){
	PokeAgenda *l;
	int i;
	char arquivo[]="pokemon.txt";
	char merda[]="Chanse";
	inicializar_lista(&l);
	importar_lista(&l,arquivo);
	listar_pokemon_decrescente(&l);
	printf("\n\n\n");
	listar_pokemon_crescente(&l);
	printf("\n\n\n");
	pesquisar_poke_nome(&l,merda);
	printf("\n\n\n");
	char merda1[] = "Pikachu";
	pesquisar_poke_nome(&l,merda1);
	printf("\n\n\n");
	i = remover_por_numero(&l,150);
	if(i!=0)
		printf("Removido");
	else
		printf("Não Removido");
	printf("\n\n\n");
	i = remover_por_numero(&l,151);
	if(i!=0)
		printf("Removido");
	else
		printf("Não Removido");
	printf("\n\n\n");
	listar_pokemon_crescente(&l);
	destruir_pokedex(&l);
	printf("Lista Destruida!! \n\n");
	listar_pokemon_crescente(&l);
}