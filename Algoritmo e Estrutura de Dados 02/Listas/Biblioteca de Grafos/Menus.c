#ifndef MENUS_C_INCLUDED
#define MENUS_C_INCLUDED

#include "Biblio.h"
#include "Grafos.c"
#include "Buscas.c"
/**
 * Menus.c tem como função a exibição de todo o programa, é quem dá
 * a interface para o programa, ele apenas chama as funções para serem 
 * executadas.
 */
void menu(){
  Grafo grafo;
  inicia_grafo(&grafo);
  
  int i = 1;
  
  while(i!=0){
    clear();
    printf("----->TRABALHO SOBRE GRAFOS - WALL BERG MORAIS <-----\n");
    printf("Menu!\n");
    printf("01 - Adicionar Vertices no Grafo. \n");
    printf("02 - Adicionar Arestas no Grafo. \n");
    printf("03 - Remover Vertices no Grafo. \n");
    printf("04 - Remover Arestas no Grafo. \n");
    printf("05 - Exibir Grafo. \n");
    printf("06 - Menu de Busca em Largura. \n");
    printf("07 - Verificar se o Grafo é Conexo. \n");
    printf("08 - Mostrar Grafo em Matriz de Adjacencias. \n");
    printf("09 - Executar o busca em Profundidade. \n");
    printf("10 - Gerar caminho Minimo. Alg. de Dijkstra. \n");
    printf("11 - Arvore Geradora Minima. Alg. de Primm. \n");
    printf("12 - \"Importar\" Grafo proposto para correção. \n");
    printf("00 - Sair \n\n");
    printf("\nOpção desejada: ");
    scanf("%d",&i);
    buffer();
    
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
      case 6:
	interface6(&grafo);
	break;
      case 7:
	interface7(&grafo);
	break;
      case 8:
	interface8(&grafo);
	break;
      case 9:
	interface9(&grafo);
	break;
      case 10:
	interface10(&grafo);
	break;
      case 11:
	interface11(&grafo);
	break;
      case 12:
	interface12(&grafo);
	break;
      case 0:
	break;
      default:
	printf("Opção Invalida\n");
    }
  }
}

/** Adiciona Vertices no Grafo **/
void interface1(Grafo *grafo){
  int i = 1;
  while(i!=0){
    clear();
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
  buffer();
  aperta();
}

/** Adiciona Arestas no Grafo **/
void interface2(Grafo *grafo){
  int i = 1,j,k;
  while(i!=0){
    clear();
    printf("---->Adicionando Arestas no Grafo<----\n");
    
    
    printf("Digite a vertice de inicio: ");
    scanf("%d",&i);
    
    printf("Digite a vertice de chegada: ");
    scanf("%d",&j);
	
    do{
      printf("Digite o peso da aresta: ");
      scanf("%d",&k);
      if(k<0)
	printf("Não existe Peso Negativo, digite novamente!! \n");
      
    }while(k<0);
    
    if(add_arestas(grafo,i,j,k))
      printf("Aresta adicionada com sucesso!! \n");
    else
      printf("Não foi possivel adicionar a aresta!! \n");
    
    printf("Deseja adicionar outra aresta? \n0 - Não \n1 a 9 - Sim \n");
    printf("Opção: ");
    scanf("%d",&i);
  }
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** Remove Vertices no Grafo **/
void interface3(Grafo *grafo){
  int i;
  clear();
  printf("---->Removendo Vertices do Grafo<----\n");
  printf("Digite a vertice que você deseja remover: ");
  scanf("%d",&i);
  
  if(remover_vertices(grafo,i))
    printf("Vertice removido com sucesso!! \n");
  else
    printf("Não foi possivel remover o vertice!!\n");
  
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** Remove Arestas no Grafo **/
void interface4(Grafo *grafo){
  int i, j;
  clear();
  printf("---->Removendo Arestas do Grafo<----\n");
  printf("Digite a vertice de inicio: ");
  scanf("%d",&i);
  printf("Digite a vertice de chegada: ");
  scanf("%d",&j);
  
  if(remover_arestas(grafo,i,j))
    printf("Aresta removida com sucesso!! \n");
  else
    printf("Não foi possivel remover a aresta!!\n");

  printf("\nAperte qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();  
}

/** Imprimir Grafos*/
void interface5(Grafo *grafo){
  clear();
  printf("Numero de Vertices: %d \nNumero de Arestas: %d \n",grafo->quant_vertices,grafo->quant_arestas);
  imprime_vertices_grafo_original(&grafo->vert);
  printf("\nAperte qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** Menu para Busca em Largura*/
void interface6(Grafo *grafo){
  int i;
  i = 1;
  while(i!=0){
    clear();
    printf("---->Menu Busca em Largura<----\n");
    printf("1 - Gerar e Imprimir Grafo de Busca em Largura\n");
    printf("0 - Voltar ao Menu Anterior\n");
    printf("Resposta: ");
    scanf("%d",&i);
    buffer();
    
    switch(i){
      case 1:
	sub_interface1(grafo);
	break;
      case 2:
	break;
      case 0:
	break;
      default:
	break;
    }
  }
}

/** Item 1 do menu de Busca em Largura */
void sub_interface1(Grafo *grafo){
  int i;
  clear();
  printf("---->Gerando e Imprimindo um Subgrafo Busca em Largura<----\n");
  printf("Digite o vertice de origem do grafo: ");
  scanf("%d",&i);
  
  if(!imprime_vertices_grafo_largura(grafo,i))
    printf("Não foi Possivel Gerar o Grafo!!\n");
  
  printf("\nAperte qualquer tecla para voltar ao menu anterior!!\n ");
  buffer();
  aperta();
}

/** Função de exibição para mostrar se o grafo é ou não conexo. */
void interface7(Grafo *grafo){
  clear();
  printf("---->Verificando se o Grafo é Conexo<----\n");
  
  if(grafo->vert != NULL){
    if(verifica_conexo(grafo))
      printf("O Grafo é Conexo!!\n");
    else
      printf("O grafo não é Conexo!!\n");
  }else
    printf("Grafo Vazio!!\n");
  
  printf("\nAperte qualquer tecla para voltar para o menu!!\n");
  buffer();
  aperta();
}

/**
 *Função de exibição para mostrar o grafo em forma de matriz de
 * adjacencias.
 */
void interface8(Grafo *grafo){
  clear();
  printf("---->Mostrar Grafo em Matriz de Adjacencias<----\n");
  gerar_matriz(grafo);
  printf("\nAperte qualquer tecla para voltar para o menu!!\n");
  buffer();
  aperta();
}

/** Função de exibição da floresta gerada pelo o grafo de busca em Profundidade.*/
void interface9(Grafo *grafo){
  clear();
  printf("---->Gerar Grafo de Busca em Profundidade<----\n");
  
  if(!imprime_busca_em_profundidade(grafo))
    printf("Não foi possivel Gerar a Floresta de busca em Profundidade. \n");
  
  printf("\nAperte qualquer tecla para voltar para o menu. \n");
  buffer();
  aperta();
}

/** 
 * Função que chama o algorimo de Dijkstra, dando um caminho inicial e final.
 */
void interface10(Grafo *grafo){
  clear();
  printf("---->Caminho Minimo/Alg. de Dijkstra<----\n");
  int i, j;
  
  do{
    printf("Digite a Vertice de inicio: ");
    scanf("%d",&i);
    if(i<0)
      printf("Digite Novamente! \n");
  }while(i<0);
  
  do{
    printf("Digite a Vertice de Chegada: ");
    scanf("%d",&j);
    if(j<0)
      printf("Digite Novamente! \n");
  }while(i<0);
  
  if(!CaminhoMinimo(grafo,i,j))
    printf("Erro ao executar o algoritmo.\n");
  
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
}

/**
 * Função que chama o algorimo de Primm.
 */
void interface11(Grafo *grafo){
  clear();
  printf("---->Arvore Geradora Minima/Alg. de Primm<----\n");
  
  if(!arvore_minima(grafo))
    printf("Erro ao executar o algoritmo. \n");
  
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
}

/** 
 * Função para não precisar adicionar aresta por aresta e vertice por vertice
 * o grafo proposto.
 * 
 */
void interface12(Grafo *grafo){
  clear();
  add_vertices(grafo,1);
  add_vertices(grafo,2);
  add_vertices(grafo,3);
  add_vertices(grafo,4);
  add_vertices(grafo,5);
  add_vertices(grafo,6);
  add_vertices(grafo,7);
  add_vertices(grafo,8);
  add_vertices(grafo,9);
  add_vertices(grafo,10);
  add_arestas(grafo,1,2,7);
  add_arestas(grafo,1,4,9);
  add_arestas(grafo,1,5,10);
  add_arestas(grafo,1,6,8);
  add_arestas(grafo,1,8,9);
  add_arestas(grafo,1,10,8);
  add_arestas(grafo,2,3,4);
  add_arestas(grafo,2,4,5);
  add_arestas(grafo,2,10,9);
  add_arestas(grafo,2,9,9);
  add_arestas(grafo,3,4,1);
  add_arestas(grafo,3,5,4);
  add_arestas(grafo,4,5,3);
  add_arestas(grafo,5,6,18);
  add_arestas(grafo,6,7,9);
  add_arestas(grafo,7,8,3);
  add_arestas(grafo,7,9,6);
  add_arestas(grafo,8,10,2);
  add_arestas(grafo,8,9,4);
  add_arestas(grafo,9,10,2);
  printf("Grafo \"importado\" com sucesso. ");
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
  
}

#endif