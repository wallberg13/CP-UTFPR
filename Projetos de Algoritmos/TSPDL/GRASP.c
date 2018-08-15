#include "headers.h"

/**
  Arquivo que irá contemplarar apenas da fase de contrução do
  GRASP que servirá como entrada do Simulated annealing
*/

void sorteio(){
  srand(time(NULL));
}

int* construcao(TSP *tsp, int **mtz, int n, double alpha){
  int *sol;
  sol = cria_vetor(n); //Solução começa vazia

  int i = 0; //Posição atual do vetor.
  int y = 0; //Posição vertical atual.
  int x = 0; //Posição horizontal.

  int dmd = cal_demand(tsp,n);
  zera_visita(tsp,n);

  while(dmd != 0 && i < n){
    //Atualiza a posição (pois ele retorna a prox posição)
      x = const_lrc(tsp,n,mtz,y,dmd,alpha);
      tsp[y].visited = 1;
      sol[i] = y;
      y = x;
      dmd--;
      i++;
  }
  sol[i] = y;

  return sol;
}

/**
  Construção de lista para ser ordenada.
  lrc   : Estrutura que irá receber a lista.
  n     : Tamanho da lista.
  mtz   : Matriz que contem os pesos que seram inseridos na lista.
  y     : Posição Y da matriz que será usada para popular a lista.
  dms   : Demanda atual.

  1° Conta a quantidade disponivel.
  2° Cria vetor com a quantidade certa.
  3° Adiciona os valores no vetor.
  4° Quebra o vetor com o alpha.

  POR ENQUANTO NÃO ESTA SENDO CONSIDERADO A POSIÇÃO QUE ELE
  ESTÁ, E SIM TODO O VETOR, OU SEJA, CONSIDERANDO A ORIGEM

  Retorno: Posição que será inserida na solução.
*/
int const_lrc(TSP *tsp, int n, int **mtz, int y, int dmd, double alpha){
  LRC *lrc;
  int i,j,quant;

  quant = cont_lrc(tsp,n,dmd,y);
  cria_lrc(&lrc,quant);

  for(i = 0, j = 0; i < n && j < n; i++){
    if(!tsp[i].visited && tsp[i].draft >= dmd && i!=y){
      lrc[j].prox = i;
      lrc[j].peso = mtz[y][i];
      j++;
    }
  }

  Merge_sort(lrc,0,quant-1);

  //Sorteia o kra que será inserido no vetor da solução.
  return lrc[cont_lrc_alpha(lrc,quant,alpha)].prox;
}

/**
  Função que conta a quantidade de lugares disponivel para
  visita.
  Ele vai levar em conta o limite do calado, e se ele já foi visitado
  ou não.
  Retorno: Tamanho do vetor que será o LRC.
*/
int cont_lrc(TSP *tsp,int n, int dmd, int y){
  int i,j;

  for(i = 0, j = 0; i < n; i++){
    if(!tsp[i].visited && tsp[i].draft >= dmd && i!=y){
      j++;
    }
  }

  return j;
}

/**
  Algoritmo para definir a ultima posição que faz parte
  da lista restrita de candidatos, pois assim, o sorteio
  se limitará a esta posição.
  Como o alpha é um float, é considerado a parte inteira do limite
  definido.
*/
int cont_lrc_alpha(LRC *lrc, int n, double alpha){
  int i,x;
  double beta = 1.0/alpha;
  int limite = lrc[0].peso * beta;
  for(i = 0; lrc[i].peso < limite && i < n;i++);

  if(i!=0)
    x = 0 + rand()%(i);
  else
    x = 0;
  return x;
}

/*
  Um algoritmo com complexidade n*log n é ideal para
  poder ordernar um vetor. (TOTALMENTE COPIADO DA INTERNET)

  Parametros:
  mtz   : Matriz com os pesos
  v     : Vetor para ser ordenado
  p,q,r : Não me lembro, esse codigo foi feito já faz um bom tempo
  y     : Posição vertical atual.

*/
void Merge(LRC *lrc, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  LRC L[n1 + 1], R[n2 + 1];
  int i, j, k;

  for(i = 0; i < n1; i++){
    L[i].peso = lrc[p+i].peso;
    L[i].prox = lrc[p+i].prox;
  }

  for(j = 0; j < n2; j++){
    R[j].peso = lrc[q + j + 1].peso;
    R[j].prox = lrc[q + j + 1].prox;
  }

  L[n1].peso = infinito;
  R[n2].peso = infinito;

  j=i=0;

  for(k = p; k <= r; k++){
    if(L[i].peso <= R[j].peso){
      lrc[k].peso = L[i].peso;
      lrc[k].prox = L[i].prox;
      i++;
    }else{
      lrc[k].peso = R[j].peso;
      lrc[k].prox = R[j].prox;
      j++;
    }
  }
}

/**
  Argumentos da função:
  mtz : matriz com os pesos
  lrc : Vetor com a lista candidata
  p   : Posição inicial
  r   : Posição final (do vetor, pois é recursivo a função)
  y   : Posição vertical atual
*/
void Merge_sort(LRC *lrc, int p, int r){
  int q;
  if(p < r){
    q = (p+r)/2;
    Merge_sort(lrc,p,q);
    Merge_sort(lrc,q+1,r);
    Merge(lrc,p,q,r);
  }
}
