#ifndef MENUS_C_INCLUDED
#define MENUS_C_INCLUDED

#include "Biblio.h"
#include "Grafos.c"

void menu(){
  Grafo grafo;
  inicia_grafo(&grafo);
  
  int i = 1;
  
  while(i!=0){
    system("clear");
    printf("----->TRABALHO SOBRE GRAFOS - WALL BERG MORAIS <-----\n");
    printf("Menu!\n");
    printf("1 - Adicionar Vertices no Grafo! \n");
    printf("2 - Adicionar Arestas no Grafo! \n");
    printf("3 - Remover Vertices no Grafo! \n");
    printf("4 - Remover Arestas no Grafo! \n");
    printf("5 - Exibir Grafo! \n");
    printf("0 - Sair \n\n");
    printf("\nOpção desejada: ");
    scanf("%d",&i);
    __fpurge(stdin);
    
    switch(i){
      case 1:
	interface1(&grafo);
	break;
      case 2:
	interface2(&grafo);
	break;
      case 3:
	interface3(&grafo);
	break;
      case 4:
	interface4(&grafo);
	break;
      case 5:
	interface5(&grafo);
	break;
      case 0:
	break;
    }
  }
}

void interface1(Grafo *grafo){
  int i = 1;
  while(i!=0){
    system("clear");
    printf("---->Adicionando Vertices no Grafo<----\n");
    printf("Digite o numero do vertice: ");
    scanf("%d",&i);
    
    if(add_vertices(grafo,i))
      printf("Vertice adicionado com sucesso!! \n");
    else
      printf("Não foi possivel adicionar o vertice!! \n");
  
    printf("Deseja adicionar outro vertice?\n0 - Não\n1 a 9 - Sim\n");
    printf("Resposta: ");
    scanf("%d",&i);
  }
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  __fpurge(stdin);
  aperta();
}

void interface2(Grafo *grafo){
  int i = 1,j;
  while(i!=0){
    system("clear");
    printf("---->Adicionando Arestas no Grafo<----\n");
    printf("Digite a vertice de inicio: ");
    scanf("%d",&i);
    printf("Digite a vertice de chegada: ");
    scanf("%d",&j);
    
    if(add_arestas(grafo,i,j))
      printf("Aresta adicionada com sucesso!! \n");
    else
      printf("Não foi possivel adicionar a aresta!! \n");
    
    printf("Deseja adicionar outra aresta? \n0 - Não \n1 a 9 - Sim \n");
    printf("Opção: ");
    scanf("%d",&i);
  }
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  __fpurge(stdin);
  aperta();
}

void interface3(Grafo *grafo){
  int i;
  system("clear");
  printf("---->Removendo Vertices do Grafo<----\n");
  printf("Digite a vertice que você deseja remover: ");
  scanf("%d",&i);
  
  if(remover_vertices(grafo,i))
    printf("Vertice removido com sucesso!! \n");
  else
    printf("Não foi possivel remover o vertice!!\n");
  
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  __fpurge(stdin);
  aperta();
}

void interface4(Grafo *grafo){
  int i, j;
  system("clear");
  printf("---->Removendo Arestas do Grafo<----\n");
  printf("Digite a vertice de inicio: ");
  scanf("%d",&i);
  printf("Digite a vertice de chegada: ");
  scanf("%d",&j);
  
  if(remover_arestas(grafo,i,j))
    printf("Aresta removida com sucesso!! \n");
  else
    printf("Não foi possivel remover a aresta!!\n");

  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  __fpurge(stdin);
  aperta();  
}

void interface5(Grafo *grafo){
  system("clear");
  imprime_vertices(&grafo->vert);
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  __fpurge(stdin);
  aperta();
}

#endif