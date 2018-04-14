#ifndef POKEAGENDA_H_INCLUDED
#define POKEAGENDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POKEMAX 152

typedef struct{
    int numero;
    char tipo; // N)ormal A)gua F)ogo G)grama T)erra R)ocha E)letrico V)eneno P)siquico I)nseto H)gelo
    char nome[15];
} PokeRegistro;

typedef struct{
    PokeRegistro lista[POKEMAX];
    int top;
} PokeAgenda;

// inicializa a lista
void inicializar_lista(PokeAgenda *lista){
    lista->top = 0;
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


int pos_inser(PokeRegistro vetor[],PokeRegistro pokemon, int top){
    int i;
    for(i = 0; (pokemon.numero>vetor[i].numero)&&(i<top); i++);
    return i;
}

/**
 * Função para inserir na lista do tipo PokeAgenda por ordem de numero do Pokemon;
 * Retorna -1 caso a lista estiver cheia!!
 */
int inserir_lista(PokeAgenda *pLista, PokeRegistro *pokemon){
    int i = pLista->top;
    int j;
    if(i != POKEMAX){ //Verificação se não esta cheia;
        if(i == 0){
            pLista->lista[i] = *pokemon; //Se o top da lista for zero, não precisa organizar toda a lista
        }else{ //Senão, ele deslocara todo o vetor para poder inserir na posição certa
            int k = pos_inser(pLista->lista,*pokemon,i); //Variavel da posição
	    for(j = i; j > k; j--){ //Deslocando...
                    pLista->lista[j] = pLista->lista[j-1];
            }
            pLista->lista[k] = *pokemon;
        }
    }else{
        return -1;
    }
    pLista->top++;
    return pLista->top; //Retorna o novo top da lista
}

/**
 * Função de importar lista, onde sera feita a leitura de um arquivo e 
 * os seus dados ira ser jogado para a lista.
 * Retorna -1 em caso de falha
 */
int importar_lista(PokeAgenda *lista, char *nome_arquivo){
    // abre o arquivo para leitura ("r" - read)
    FILE *arquivo = fopen(nome_arquivo,"r");
    int status;
    PokeRegistro pokemon;
    
    while ((status = fscanf(arquivo, "%d %c %s",&pokemon.numero,&pokemon.tipo,pokemon.nome)) != EOF){
      if((status == 3) && (lista->top < POKEMAX -1))
	inserir_lista(lista,&pokemon);
      else
	return -1;
    }    
    fclose(arquivo); // fecha arquivo
    return(lista->top);
}

/**
 * Função que mostra toda a lista do tipo PokeAgenda.
 */
int listar_pokemon(PokeAgenda *lista){
  for(int i = 0; i<lista->top; i++){
    char tipo = lista->lista[i].tipo;
    printf("#%03d %-15s %s\n",lista->lista[i].numero , lista->lista[i].nome,tipo_pokemon(tipo));
  }
}

/*
 * Função que praticamente faz a mesma coisa que a função listar_pokemon,
 * pois as duas vão varrer a lista, a diferença é que tem uma condição, e sendo
 * ela quando os tipo do pokemon bater com o exigido, se sim, adiciona-se parametro PokeRegistro
 * parametro na Variavel pokemon, e no final retorna 1 caso a lista for preenchida, e 
 * -1 caso não for nenhum pokemon para a sub_lista
 */
int sub_lista(PokeAgenda *lista1, char tipo, PokeAgenda *lista2){
  int i;
  PokeRegistro pokemon;
  for(i = 0; i < lista1->top; i++){
    if(lista1->lista[i].tipo == tipo){
      strcpy(pokemon.nome,lista1->lista[i].nome);
      pokemon.tipo = lista1->lista[i].tipo;
      pokemon.numero = lista1->lista[i].numero;
      inserir_lista(lista2,&pokemon);
    }
  }
  if(lista2->top != 0)
    return(1);
  else
    return(-1);
}

#endif // POKEAGENDA_H_INCLUDED
