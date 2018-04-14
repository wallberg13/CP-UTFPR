#include "headers.h"
#include<math.h>

/** Estudar condições de desempenho para cada instancia*/
#define T_ini 1000000.0
//#define alpha 0.65
#define piora 20
#define inc_t 0.3
#define TAXA_QUEDA 30
#define COND 2
#define semMud 60
/**

  Solução de entrada é uma solução feita na fase de
  construção do GRASP.
    TSP *tsp    : Conjunto de todos os verficies do grafo.
    int *sol_i  : Solução inicial obtida a partir da fase de
                  construção do GRASP.
    int **mtz   : Matriz de pesos.
    int *sol_ini: Solução inicial gerado por qualquer metodo
                  que gere uma solução, neste caso será o GRASP.

*/
int SA(TSP *tsp, int **mtz, int n, int *sol_ini){
  int *novo = cria_vetor(n), *best = cria_vetor(n);
  int vc,vn,vb;
  double T = T_ini,t = 0.0;
  int contRuim, contMud;

  vc = valorSol(sol_ini,n,mtz);
  update(best,sol_ini,n);
  vb = vc;
  while(T > COND){
    contRuim = 0;
    contMud = 0;
    while(contRuim < piora && contMud < semMud){
      neighborhood(novo,tsp,sol_ini,n);
      vn = valorSol(novo,n,mtz);
      if(vn < vc){
        update(sol_ini,novo,n);
        vc = vn;
        contMud = 0;
        if(vc < vb){
          update(best,sol_ini,n);
          vb = vc;
        }
      }else{
        if(probSort() < probP(vc,vn,T)){
          update(sol_ini,novo,n);
          vc = vn;
          contRuim++;
          contMud = 0;
        }else{
          contMud++;
        }
      }
    };
    t += inc_t;
    T = novoT(t);
  }

  limpa_vetor(novo);
  limpa_vetor(best);
  limpa_vetor(sol_ini);
  return vb;
}

int update(int *sol, int *novo, int n){
  int i;
  for(i = 0; i < n; i++){
    sol[i] = novo[i];
  }
}

/**
  O Algoritmo do Simulated annealing precisa sempre atualizar o
  valor de temperatura com o decorrer do tempo, como um boa
  escolha de função, sendo ela a mais linda da matematica, o exp(x),
  foi decido o uso da mesma para fazer o decaimento da temperatura.
*/
double novoT(double t){
  return T_ini*exp(-t/TAXA_QUEDA);
}

/**
  Primeiro, sorteia-se a primeira posição para sorteio.
  Se está posição tiver restrição de calado (tem posição minima para)
  que seja sorteado, o proximo sorteio será da posição minima com
  que pode ser trocado até o fim do vetor.
*/
int* neighborhood(int *nov,TSP *tsp, int *sol,int n){
  int x = 0,y = 0;
  update(nov,sol,n);
  int no1,no2;


  while(1){
    x = 1 + rand()%(n-1);
    no1 = sol[x];
  }
  while(x==y || !verPosDes(y,no1,tsp,n) && !verPosDes(x,no2,tsp,n)){
    x = 1 + rand()%(n-1); //Posição 1 na solução

    no1 = sol[x]; //Vertice
    no2 = sol[y]; //Vercice
    if(x != y && verPosDes(y,no1,tsp,n) && verPosDes(x,no2,tsp,n))
        troca(nov,x,y);
  }

  return nov;
}

int posMin(TSP  *tsp, int n, int y){
  return n - tsp[y].draft;
}

int troca(int *sol,int x, int y){
  int aux;
  aux = sol[x];
  sol[x] = sol[y];
  sol[y] = aux;
}

double probP(int vc, int vn, double T){
  double x = exp((double)(vc-vn)/T);
  return x;
}
