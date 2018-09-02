#include "headers.h"

/**
  Função que irá fazer importação do arquivo em questão.
*/

#define n 150
#define infinito 99999.0
#define k 19
#define n_class 3

/**
  Fase de testes
*/
void K_NN(IRIS *iris){
  int sol[n];
  Dist dist[n];
  int i,j;
  for(j = 0; j < n; j++){
    dist[j].dist = 0.0;
    dist[j].pos = 0;
    for(i = 0; i < n; i++){
      if(i != j){
        //dist[i].dist = distMahalanobis(iris[j],iris[i],met);
        dist[i].dist = distEucl(iris[j],iris[i]);
        dist[i].pos = iris[i].pos;
      }
    }
    Merge_sort(dist,0,n-1);
    sol[j] = classifica(iris,dist);
  }
  //printDist(dist, iris);
  printSol(sol,iris);
  printf("Porcentagem de Acerto: %.3f %% \n\n",contPerAcert(sol,iris)*100.0);
  printf("Matriz de Confusão: \n");
  mtzConfu(sol,iris);
}

int classifica(IRIS *iris, Dist *dist){
  int i;
  int x[n_class];
  vetZeros(x);
  for(i = 0; i < k; i++){
    x[iris[dist[i+1].pos].clas - 1]++;
  }
  return pega_maior(x)+1;
}

/**
  Vetor do tamanho de n_class que inicia com zeros
*/
void vetZeros(int *j){
  int i;
  for(i = 0; i < n_class; i++){
    j[i] = 0;
  }
}

/**
  Pega o maior do vetor que quero que no caso seria
  de tamanho n_class;
*/
int pega_maior(int *vet){
  int maior = 0, i,j = 0;
  for(i = 0; i < n_class; i++){
    if(vet[i] >= maior){
      maior = vet[i];
      j = i;
    }
  }
  return j;
}

double contPerAcert(int *sol, IRIS *iris){
  double soma = 0;
  int i;
  for(i = 0; i < n; i++){
    if(sol[i] == iris[i].clas)
      soma++;
  }
  return (double)(soma/n);
}

/**
  Eixo J: Valor Certo
  Eixo I: Valor previsto.
*/
void mtzConfu(int *sol, IRIS *iris){
  int **mtz;
  mtz = cria_matriz(n_class);
  int cont,i,j,z;
  printf("\t Valor Real\nV.P.\t");
  for(i = 0; i < n_class; i++){
    printf("%d\t",i+1);
  }
  printf("\n");
  for(i = 0; i < n_class; i++){
    printf("%d: \t",i+1);
    for(j = 0; j < n_class; j++){
      cont = 0;
      for(z = 0; z < n; z++){
        if(sol[z] == j + 1 && iris[z].clas == i + 1)
          cont++;
      }
      mtz[i][j] = cont;
      printf("%d \t",mtz[i][j]);
    }
    printf("\n");
  }
}

int** cria_matriz(int x){
  int i;
  int **mtz;
  mtz = (int **)malloc(x*sizeof(int *));

  for(i = 0; i < x; i++){
    mtz[i] = (int *)malloc(x*sizeof(int));
  }
  return mtz;
}

void import(char *arq){
  FILE *file = fopen(arq,"r+");
  IRIS iris[n];
  int i = 0;

  while(i < n && !feof(file)){
    fscanf(file,"%lf %lf %lf %lf %d",&(iris[i].f1),&(iris[i].f2),&(iris[i].f3),&(iris[i].f4),&(iris[i].clas));
    iris[i].pos = i;
    i++;
  }
  K_NN(iris);
}


double distEucl(IRIS i1, IRIS i2){
  return sqrt(pow(i1.f1 - i2.f1,2) + pow(i1.f2 - i2.f2,2) + pow(i1.f3 - i2.f3,2) + pow(i1.f4 - i2.f4,2));
}

double distMahalanobis(IRIS i1, IRIS i2, Metrica met){
  return sqrt(pow(i1.f1 - i2.f1,2)/pow(met.dp1,2) + pow(i1.f2 - i2.f2,2)/pow(met.dp2,2) + pow(i1.f3 - i2.f3,2)/pow(met.dp3,2) + pow(i1.f4 - i2.f4,2)/pow(met.dp4,2));
}

/**
  Função para tirar metricas de todos os atributos
*/
void normalize(IRIS *iris, Metrica met){
  int i;

  for(i = 0; i < n; i++){
    iris[i].f1 = (iris[i].f1 - met.menorf1)/(met.maiorf1 - met.menorf1);
    iris[i].f2 = (iris[i].f2 - met.menorf2)/(met.maiorf2 - met.menorf2);
    iris[i].f3 = (iris[i].f3 - met.menorf3)/(met.maiorf3 - met.menorf3);
    iris[i].f4 = (iris[i].f4 - met.menorf4)/(met.maiorf4 - met.menorf4);
  }
}

void metrica(IRIS *iris, Metrica *met){

  met->maiorf1 = 0.0;
  met->menorf1 = 999.0;
  met->maiorf2 = 0.0;
  met->menorf2 = 999.0;
  met->maiorf3 = 0.0;
  met->menorf3 = 999.0;
  met->maiorf4 = 0.0;
  met->menorf4 = 999.0;
  met->mediaf1 = 0.0;
  met->mediaf2 = 0.0;
  met->mediaf3 = 0.0;
  met->mediaf4 = 0.0;
  met->dp1 = 0.0;
  met->dp2 = 0.0;
  met->dp3 = 0.0;
  met->dp4 = 0.0;

  int i;
  for(i = 0; i < n; i++){

    if(iris[i].f1 >= met->maiorf1){
      met->maiorf1 = iris[i].f1;
    }
    if(iris[i].f2 >= met->maiorf2){
      met->maiorf2 = iris[i].f2;
    }
    if(iris[i].f3 >= met->maiorf3){
      met->maiorf3 = iris[i].f3;
    }
    if(iris[i].f4 >= met->maiorf4){
      met->maiorf4 = iris[i].f4;
    }
    if(iris[i].f1 <= met->menorf1){
      met->menorf1 = iris[i].f1;
    }
    if(iris[i].f2 <= met->menorf2){
      met->menorf2 = iris[i].f2;
    }
    if(iris[i].f3 <= met->menorf3){
      met->menorf3 = iris[i].f3;
    }
    if(iris[i].f4 <= met->menorf4){
      met->menorf4 = iris[i].f4;
    }
    met->mediaf1 += iris[i].f1;
    met->mediaf2 += iris[i].f2;
    met->mediaf3 += iris[i].f3;
    met->mediaf4 += iris[i].f4;
  }
  met->mediaf1 = met->mediaf1/n;
  met->mediaf2 = met->mediaf2/n;
  met->mediaf3 = met->mediaf3/n;
  met->mediaf4 = met->mediaf4/n;

  for(i = 0; i < n; i++){
    met->dp1 += pow(iris[i].f1 - met->mediaf1,2);
    met->dp2 += pow(iris[i].f2 - met->mediaf2,2);
    met->dp3 += pow(iris[i].f3 - met->mediaf3,2);
    met->dp4 += pow(iris[i].f4 - met->mediaf4,2);
  }
  met->dp1 = sqrt(met->dp1/n);
  met->dp2 = sqrt(met->dp2/n);
  met->dp3 = sqrt(met->dp3/n);
  met->dp4 = sqrt(met->dp4/n);
}

/**
  Função de testes para printar o vetor de distâncias
*/
void printDist(Dist *dist, IRIS *iris){
  int i;
  for(i = 0; i < n; i++){
    printf("Pos: %.2d \t  Dist: %.3f \tIris: %d \n",dist[i].pos, dist[i].dist, iris[dist[i].pos].clas);
  }
}

void printIris(IRIS *iris){
  int i;
  for(i = 0; i < n; i++){
    printf("%d %.2f %.2f %.2f %.2f %d \n",iris[i].pos, iris[i].f1, iris[i].f2, iris[i].f3, iris[i].f4, iris[i].clas);
  }
}

void printSol(int *sol, IRIS *iris){
  int i;
  for(i = 0; i < n; i++){
    printf("Sol: %d Iris: %d \n",sol[i], iris[i].clas);
  }
}

void Merge(Dist v[], int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  Dist L[n1 + 1], R[n2 + 1];
  int i, j, x;

  for(i = 0; i < n1; i++){
    L[i].dist = v[p+i].dist;
    L[i].pos = v[p+i].pos;
  }

  for(j = 0; j < n2; j++){
    R[j].dist = v[q + j + 1].dist;
    R[j].pos = v[q + j + 1].pos;
  }

  L[n1].dist = infinito;
  R[n2].dist = infinito;

  j=i=0;

  for(x = p; x <= r; x++){
    if(L[i].dist <= R[j].dist){
      v[x].dist = L[i].dist;
      v[x].pos = L[i].pos;
      i++;
    }else{
      v[x].dist = R[j].dist;
      v[x].pos = R[j].pos;
      j++;
    }
  }
}

void Merge_sort(Dist v[], int p, int r){
  int q;
  if(p < r){
    q = (p+r)/2;
    Merge_sort(v,p,q);
    Merge_sort(v,q+1, r);
    Merge(v,p,q,r);
  }
}
