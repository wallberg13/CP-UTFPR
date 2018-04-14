#include "headers.h"

#define INFINITO 99999

/**
  Metodo guloso para o caso estudado.
  Complexidade: O(n²)
*/
int greedy_algorithm(TSP *tsp,int **mtz,int n){
  int y,x,i=0; //Estados atuais.
  int dmd = cal_demand(tsp,n);
  y = 0; //Linha atual
  x = 0; //Coluna atual.
  int *sol;
  sol = cria_vetor(n);
  zera_visita(tsp,n);

  while(dmd != 0){
    x = pegar_menor(tsp,mtz,n,dmd,y);
    tsp[y].visited = 1;
    sol[i] = y;
    y = x;
    dmd--;
    i++;
  }
  sol[i] = y;

  //print_vetor(sol,n);
  int solr = valorSol(sol,n,mtz);
  //printf("Sol: %d\n",solr);

  limpa_vetor(sol);
  return solr;
}


int pegar_menor(TSP *tsp,int **mtz, int n, int carga, int y){
  int i,menor = INFINITO;
  int j;

  for(i = 0,j=0; i < n; i++){
    if(mtz[y][i] < menor && tsp[i].draft >= carga && !tsp[i].visited && y != i){
      menor = mtz[y][i];
      j = i;
    }
  }

  return j;
}
