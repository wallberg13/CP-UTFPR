#include <stdio.h>
#include <stdlib.h>
#include <Limits.h>
#include "Listas.h"
#include "Estruturas.h"
#include "Util.h"
#include "Construcao.h"

void constroi_solucao(int n, int *s, float **distancia)
{
    for (int j=0; j < n; j++) s[j] = j;
}


/* Constroi uma solucao de forma gulosa, no caso,
   implementa o Metodo construtivo do vizinho mais proximo */
void constroi_solucao_gulosa_vizinho_mais_proximo(int n, int *s, float **d)
{
    struct lista *inicio_LC, *final_LC, *nao_visitada;
    int tamanho_LC;

    /* Inicio da Fase de Construcao de uma solucao */
    printf("\n Construindo nova solucao ...\n");
    inicio_LC = final_LC = NULL;
    for (int j=1; j<n; j++){
      nao_visitada = (struct lista *)malloc(sizeof(struct lista));
      if (!nao_visitada) {
         printf("Faltando memoria ...\n");
         exit(1);
      }
      /* vou inserir um registro no final de uma lista  */
      nao_visitada->campo1 = j;
      nao_visitada->campo2 = 0;
      insere_final_lista(nao_visitada, &inicio_LC, &final_LC);
      tamanho_LC = tamanho_lista(&inicio_LC, &final_LC);
      //printf("Tamanho da LC = %2d \n", tamanho_LC);
      //mostra_lista(&inicio_LC, &final_LC);
    }
    s[0]=0;  /* A cidade origem é a cidade 0 */

    int j = 1;
    int mais_proxima;
    float dist;
    while (j < n){
      dist = INT_MAX;
      struct lista *registro = inicio_LC;
      int pos = 1;
      while (registro) {
//        printf("L[%2d]   campo1 = %2d  campo2 = %2d  \n",
//               pos, registro->campo1, registro->campo2);
        if (d[s[j-1]][registro->campo1] < dist){
          dist = d[s[j-1]][registro->campo1];
          mais_proxima = registro->campo1;
        }
        registro = registro->proximo;   // obtem próximo endereço
        pos++;
      }
      /* Insere a cidade mais proxima apos a ultima cidade inserida*/
      s[j] = mais_proxima;
      /* Apaga a cidade mais_proxima da lista de nao visitadas */
      registro = encontra_registro(mais_proxima, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);
//      mostra_lista(&inicio_LC, &final_LC);
      j++;
    }
}




/* Constroi uma solucao de forma aleatoria */
void constroi_solucao_aleatoria(int n, int *s, float **d)
{
    struct lista *inicio_LC, *final_LC, *nao_visitada;
    int tamanho_LC;

    /* Inicio da Fase de Construcao de uma solucao */
    inicio_LC = final_LC = NULL;
    for (int j=1; j<n; j++){
      nao_visitada = (struct lista *)malloc(sizeof(struct lista));
      if (!nao_visitada) {
         printf("Faltando memoria ...\n");
         exit(1);
      }
      /* vou inserir um registro no final de uma lista  */
      nao_visitada->campo1 = j;
      nao_visitada->campo2 = 0;
      insere_final_lista(nao_visitada, &inicio_LC, &final_LC);
    }
    s[0]=0;  /* A cidade origem é a cidade 0 */

    int j = 1;
    int cidade_escolhida;
    while (j < n){
      struct lista *registro = inicio_LC;
      tamanho_LC = tamanho_lista(&inicio_LC,&final_LC);
      //printf("Tamanho da lista = %d \n",tamanho_LC);
      int posicao_escolhida = random(tamanho_LC);
      registro = encontra_registro_lista(posicao_escolhida,&inicio_LC);
      cidade_escolhida = registro->campo1;
      /* Insere a cidade escolhida apos a ultima cidade inserida*/
      s[j] = cidade_escolhida;
      /* Apaga a cidade escolhida da lista de nao visitadas */
//      registro = encontra_registro(cidade_escolhida, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);
      j++;
    }
}




/* Constroi uma solucao parcialmente gulosa pelo metodo do vizinho mais proximo */
void constroi_solucao_parcialmente_gulosa_vizinho_mais_proximo(int n, int *s, float **d, float alpha)
{
    struct lista *inicio_LC, *final_LC, *nao_visitada;
    int tamanho_LC;

    /* Inicio da Fase de Construcao de uma solucao */
    inicio_LC = final_LC = NULL;
    for (int j=1; j<n; j++){
      nao_visitada = (struct lista *)malloc(sizeof(struct lista));
      if (!nao_visitada) {
         printf("Faltando memoria ...\n");
         exit(1);
      }
      /* vou inserir um registro no final de uma lista  */
      nao_visitada->campo1 = j;
      nao_visitada->campo2 = 0;
      insere_final_lista(nao_visitada, &inicio_LC, &final_LC);
    }
    s[0]=0;  /* A cidade origem é a cidade 0 */

    int j = 1;
    int cidade_escolhida;
    while (j < n){
      struct lista *registro = inicio_LC;
      tamanho_LC = tamanho_lista(&inicio_LC,&final_LC);
      //printf("Tamanho da lista de candidatos = %d \n",tamanho_LC);
      /* Ordenando a lista encadeada   */
      struct lista *inicio_LC_ordenada, *final_LC_ordenada;
      inicio_LC_ordenada = final_LC_ordenada = NULL;

      while (registro){
        nao_visitada = (struct lista *)malloc(sizeof(struct lista));
        if (!nao_visitada) {
           printf("Faltando memoria ...\n");
           exit(1);
        }
        nao_visitada->campo1 = registro->campo1;
        nao_visitada->campo2 = registro->campo2;
        nao_visitada->campo3 = d[s[j-1]][nao_visitada->campo1];
        /* vou inserir um registro de forma ordenada em uma lista  */
        insere_ordenado_lista(nao_visitada, &inicio_LC_ordenada, &final_LC_ordenada);
        registro = registro->proximo;   /* obtem próximo endereço */
      }
      //mostra_lista(&inicio_LC_ordenada, &final_LC_ordenada);

      int tamanho_LRC = MAX(1, alpha * tamanho_LC);

      //printf("Tamanho da lista restrita de candidatos = %d \n",tamanho_LRC);
      int posicao_escolhida = random(tamanho_LRC);
      registro = encontra_registro_lista(posicao_escolhida,&inicio_LC_ordenada);
      cidade_escolhida = registro->campo1;
      //printf("Cidade escolhida = %d \n\n",cidade_escolhida);

      /* Apaga a lista de candidatos ordenada */
      apaga_lista(&inicio_LC_ordenada, &final_LC_ordenada);

      /* Insere a cidade escolhida apos a ultima cidade inserida*/
      s[j] = cidade_escolhida;
      /* Apaga a cidade escolhida da lista de nao visitadas */
      registro = encontra_registro(cidade_escolhida, 0, &inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);
      j++;
    }
}



/* Constroi uma solucao pela inserção mais barata */
void constroi_solucao_gulosa_insercao_mais_barata(int n, int *s, float **d)
{
    struct lista *inicio_LC, *final_LC, *nao_visitada;
    struct lista *registro;
    int tamanho_LC;

    int j = 1;
    int mais_proxima;
    float dist;

    int cid_i, cid_j, cid_k, pos;
    int melhor_i, melhor_j, melhor_k;
    float sij, melhor_sij;

    for (int i=0; i<n;i++) s[i]=-1;

    /* Inicio da Fase de Construcao de uma solucao */
    inicio_LC = final_LC = NULL;
    for (int i=1; i<n; i++){
      nao_visitada = (struct lista *)malloc(sizeof(struct lista));
      if (!nao_visitada) {
         printf("Faltando memoria ...\n");
         exit(1);
      }
      /* vou inserir um registro no final de uma lista  */
      nao_visitada->campo1 = i;
      nao_visitada->campo2 = 0;
      insere_final_lista(nao_visitada, &inicio_LC, &final_LC);
      tamanho_LC = tamanho_lista(&inicio_LC, &final_LC);
//      printf("Tamanho da LC = %2d \n", tamanho_LC);
//      mostra_lista(&inicio_LC, &final_LC);
    }
    s[0]=0;  /* A cidade origem é a cidade 0 */


    /* Insere as duas proximas cidades pela heurística do vizinho mais próximo */
    while (j < 3){
      dist = INT_MAX;
      registro = inicio_LC;
      int pos = 1;
      while (registro) {
        if (d[s[j-1]][registro->campo1] < dist){
          dist = d[s[j-1]][registro->campo1];
          mais_proxima = registro->campo1;
        }
        registro = registro->proximo;   // obtem próximo endereço
        pos++;
      }
      /* Insere a cidade mais proxima apos a ultima cidade inserida*/
      s[j] = mais_proxima;
      //imprime_rota(s,n);
      /* Apaga a cidade mais_proxima da lista de nao visitadas */
      registro = encontra_registro(mais_proxima, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);
      j++;
    }


   /* Formada uma subrota inicial com tres cidades, aplicar o metodo da
      insercao mais barata para decidir qual cidade inserir entre cada
      par de cidades i e j. A cidade k escolhida sera aquela que minimizar
      custo(k) = d(i,k) + d(k,j) - d(i,j) */

    while (j < n) {

      registro = inicio_LC;
      melhor_sij = INT_MAX;

      /* Calcula os custos para cada cidade k ser inserida entre as cidades i e j */
      while (registro) {
        cid_k = registro->campo1;
        for (int i = 0; i < j; i++) {
	  cid_i = s[i];
          if ((i+1) != j) cid_j = s[i+1];
          else cid_j = 0;
          sij = d[cid_i][cid_k] + d[cid_k][cid_j] - d[cid_i][cid_j];

          if (sij < melhor_sij) {
 	    melhor_i = cid_i;
            //melhor_j = cid_j;
            melhor_k = cid_k;
            melhor_sij = sij;
          }
        }
        registro = registro->proximo;
      }

      /* procura a posição do vetor a ser inserida a cidade */
      for (int i = 0; i < j; i++)
        if (s[i] == melhor_i) pos = i+1;

      /* Adiciona cada nova cidade k entre as cidades i e j que produzir a inserção mais barata */
      insere_meio_vetor(s,melhor_k,pos,j);

      //imprime_rota(s,n);

      /* Apaga a cidade mais barata da lista de nao visitadas */
      registro = encontra_registro(melhor_k, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);

      j++;
    }
}


 /*  HA ERRO NO METODO ABAIXO !!!!!!!!!!!!!!!! */
/* Constroi uma solucao parcialmente gulosa com base no metodo da insercao mais barata */
void constroi_solucao_parcialmente_gulosa_insercao_mais_barata(int n, int *s, float **d, float alpha)
{
    struct lista *inicio_LC, *final_LC, *nao_visitada;
    int tamanho_LC;
    struct lista *registro;

    int j = 1;
    int mais_proxima;
    float dist;

    int cid_i, cid_j, cid_k, pos;
    int melhor_i, melhor_j, melhor_k;
    float sij, melhor_sij;

    /* Inicio da Fase de Construcao de uma solucao */
    inicio_LC = final_LC = NULL;
    for (int j=1; j<n; j++){
      nao_visitada = (struct lista *)malloc(sizeof(struct lista));
      if (!nao_visitada) {
         printf("Faltando memoria ...\n");
         exit(1);
      }
      /* vou inserir um registro no final de uma lista  */
      nao_visitada->campo1 = j;
      nao_visitada->campo2 = 0;
      insere_final_lista(nao_visitada, &inicio_LC, &final_LC);
    }
    s[0]=0;  /* A cidade origem é a cidade 0 */


    /* Constrói uma subrota com 3 cidades pela heurística do vizinho mais próximo */
    while (j < 3){
      dist = INT_MAX;
      registro = inicio_LC;
      int pos = 1;
      while (registro) {
        if (d[s[j-1]][registro->campo1] < dist){
          dist = d[s[j-1]][registro->campo1];
          mais_proxima = registro->campo1;
        }
        registro = registro->proximo;   // obtem próximo endereço
        pos++;
      }
      /* Insere a cidade mais proxima apos a ultima cidade inserida*/
      s[j] = mais_proxima;
      /* Apaga a cidade mais_proxima da lista de nao visitadas */
      registro = encontra_registro(mais_proxima, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);
      j++;
    }

    int cidade_escolhida, cidade_i;

    while (j < n){
      registro = inicio_LC;
      tamanho_LC = tamanho_lista(&inicio_LC,&final_LC);
      melhor_sij = INT_MAX;

      /* Ordenando a lista encadeada em função do custo de inserção */

      struct lista *inicio_LC_ordenada, *final_LC_ordenada;
      inicio_LC_ordenada = final_LC_ordenada = NULL;

      while (registro){
        nao_visitada = (struct lista *)malloc(sizeof(struct lista));
        if (!nao_visitada) {
           printf("Faltando memoria ...\n");
           exit(1);
        }

        /* Calcula os custos para cada cidade k ser inserida entre as cidades i e j */
        cid_k = registro->campo1;

        for (int i = 0; i < j; i++) {
	  cid_i = s[i];
          if ((i+1) != j) cid_j = s[i+1];
          else cid_j = 0;
          sij = d[cid_i][cid_k] + d[cid_k][cid_j] - d[cid_i][cid_j];

          if (sij < melhor_sij) {
 	    melhor_i = cid_i;
            melhor_sij = sij;
          }
        }

        nao_visitada->campo1 = registro->campo1;
        nao_visitada->campo2 = melhor_i;
        nao_visitada->campo3 = -melhor_sij; /* Como a ordenacao é crescente,
                                               põe-se o sinal de menos para
                                               indicar que a primeira da lista
                                               é a que tem a maior economia */
        /* vou inserir um registro de forma ordenada em uma lista  */
        insere_ordenado_lista(nao_visitada, &inicio_LC_ordenada, &final_LC_ordenada);
        registro = registro->proximo;   /* obtem próximo endereço */
      }

      int tamanho_LRC = MAX(1, alpha * tamanho_LC);
      int posicao_escolhida = random(tamanho_LRC);
      registro = encontra_registro_lista(posicao_escolhida,&inicio_LC_ordenada);
      cidade_escolhida = registro->campo1;
      cidade_i = registro->campo2;

      /* Apaga a lista de candidatos ordenada */
      apaga_lista(&inicio_LC_ordenada, &final_LC_ordenada);

      /* procura a posição do vetor a ser inserida a cidade */
      for (int i = 0; i < j; i++)
        if (s[i] == cidade_i) pos = i+1;

      /* Adiciona cada nova cidade k entre as cidades i e j que produzir a inserção mais barata */
      insere_meio_vetor(s,cidade_escolhida,pos,j);

      /* Apaga a cidade mais barata da lista de nao visitadas */
      registro = encontra_registro(cidade_escolhida, 0,&inicio_LC);
      apaga_registro(registro,&inicio_LC,&final_LC);

      j++;
    }
}


