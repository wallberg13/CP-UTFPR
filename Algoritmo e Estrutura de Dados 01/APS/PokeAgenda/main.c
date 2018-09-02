#include <stdio.h>
#include <stdlib.h>
#include "pokeagenda.h"
#include <string.h>

int main(){
  char arquivo[]="pokemon.txt";
  PokeAgenda pokedex, sub_pokedex;
  inicializar_lista(&pokedex);
  inicializar_lista(&sub_pokedex);
  importar_lista(&pokedex,arquivo);
  listar_pokemon(&pokedex);
  sub_lista(&pokedex,'F',&sub_pokedex);
  printf("\n\n\n\n\n\n\n\n\n");
  listar_pokemon(&sub_pokedex);
}