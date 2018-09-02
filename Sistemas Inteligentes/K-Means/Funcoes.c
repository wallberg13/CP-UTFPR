#include "headers.h"

/**
  Função que irá fazer importação do arquivo em questão.
*/

#define n 150
#define infinito 99999.0
#define k 3
#define AMOSTRA 5000

void sorteio(){
  srand(time(NULL));
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

  double **mtz = cria_matriz(k), **mtzBest = cria_matriz(k);

  int *rotList = (int *)malloc(n*sizeof(int)), *rotBest = (int *)malloc(n*sizeof(int));

  double *dist, *distBest;

  distBest = (double *)malloc(2*sizeof(double));

  K_Means(iris,mtz,rotList);
  while(verf_neg(mtz)){
    K_Means(iris,mtz,rotList);
  }
  cop_Matriz(mtz,mtzBest);
  cop_vet(rotList,rotBest);

  distBest = val_obj(mtz);
  for(i = 0; i < AMOSTRA; i++){
    if(!verf_neg(mtz)){
      dist = val_obj(mtz);
      if(dist[0] < distBest[0] && dist[1] > dist[1]){
        printf("%d \n",i);
        cop_vet(rotList,rotBest);
        cop_Matriz(mtz,mtzBest);
        distBest[0] = dist[0];
        distBest[1] = dist[1];
      }
    }
    K_Means(iris,mtz,rotList);
  }
  print_vet(rotBest);
  print_Matriz(mtzBest);
}

void cop_Matriz(double **org, double **dest){
  int i,j;
  for(i = 0; i < k; i++){
    for(j = 0; j < k; j++){
      dest[i][j] = org[i][j];
    }
  }
  printf("\n");
}

void cop_vet(int *org, int *dest){
  int i;
  for(i = 0; i < n; i++){
    dest[i] = org[i];
  }
}

void K_Means(IRIS *iris, double **mtz, int *rotList){
  Metrica met;
  normalize(iris,&met);
  metrica(iris,&met);
  double distMen = 10, dist;
  int rot = 0;
  int mud = 1;
  int i,j;
  for(i = 0; i < n; i++) rotList[i] = -1;

  CM *cm = (CM *)malloc(k*sizeof(CM));;
  inicia_cm(cm, iris);

  double soma1, soma2, soma3, soma4;

  while(mud != 0){
    mud = 0;
    for(j = 0; j < n; j++){
      distMen = 99;
      for(i = 0; i < k; i++){
        dist = distEucl2(iris[j],cm[i]);
        if(dist < distMen){
          distMen = dist;
          rot = cm[i].rot;
        }
      }
      if(rotList[j] != rot){
        mud++;
      }
      rotList[j] = rot;
    }

    // Recalcula os centros de massa
    for(i = 0; i < k; i++){
      soma1 = 0.0; soma2 = 0.0; soma3 = 0.0; soma4 = 0.0;
      int x = 0;
      for(j = 0; j < n; j++){
        if(cm[i].rot == rotList[j]){
          soma1 += iris[j].f1;
          soma2 += iris[j].f2;
          soma3 += iris[j].f3;
          soma4 += iris[j].f4;
          x++;
        }
      }
      cm[i].p1 = soma1/x;
      cm[i].p2 = soma2/x;
      cm[i].p3 = soma3/x;
      cm[i].p4 = soma4/x;
    }
  }
  mtz_distancias(iris,rotList,mtz);
}

/**
Aloca memoria para o centro de massa como também
faz o sorteio, sempre lembrando que a base já está normalizada
*/
void inicia_cm(CM *cm, IRIS *iris){
  int i;
  int x;
  for(i = 0; i < k; i++){
    x = rand()%n;
    cm[i].p1 = iris[x].f1;
    cm[i].p2 = iris[x].f2;
    cm[i].p3 = iris[x].f3;
    cm[i].p4 = iris[x].f4;
    cm[i].rot = i;
  }
}

void print_vet(int *vet){
  int i;
  for(i = 0; i < n; i++){
    printf("Pos: %d Rot: %d \n",i,vet[i]);
  }
}

void print_CM(CM *cm){
  int i;
  for(i = 0; i < k; i++){
    printf("P1: %.2f P2: %.2f P3: %.2f P4: %.2f Rot: %d \n",cm[i].p1,cm[i].p2,cm[i].p3,cm[i].p4,cm[i].rot);
  }
}

/*
  Vai somando as distancias da seguinte maneira:
  Euclediana entre cada um, mas tendo em base em relação a
  qual cluster eu to querendo.
*/
double distancias_cluster(IRIS *iris, int *rotList, int x, int y){
  int i,j;
  int cont = 0;
  double soma = 0.0;
  for(i = 0; i < n; i++){
    for(j = 0; j < n && rotList[i] == x; j++){
      if(rotList[j] == y){
        soma += distEucl(iris[i],iris[j]);
        cont++;
      }
    }
  }
  if(soma == 0.0)
    return -1;
  return (soma)/(cont);
}

double distEucl(IRIS i1, IRIS i2){
  return sqrt(pow(i1.f1 - i2.f1,2) + pow(i1.f2 - i2.f2,2) + pow(i1.f3 - i2.f3,2) + pow(i1.f4 - i2.f4,2));
}

double distEucl2(IRIS i1, CM cm){
  return sqrt(pow(i1.f1 - cm.p1,2) + pow(i1.f2 - cm.p2,2) + pow(i1.f3 - cm.p3,2) + pow(i1.f4 - cm.p4,2));
}

double distMahalanobis(IRIS i1, IRIS i2, Metrica met){
  return sqrt(pow(i1.f1 - i2.f1,2)/pow(met.dp1,2) + pow(i1.f2 - i2.f2,2)/pow(met.dp2,2) + pow(i1.f3 - i2.f3,2)/pow(met.dp3,2) + pow(i1.f4 - i2.f4,2)/pow(met.dp4,2));
}

double distMahalanobis2(IRIS i1, CM cm, Metrica met){
  return sqrt(pow(i1.f1 - cm.p1,2)/pow(met.dp1,2) + pow(i1.f2 - cm.p2,2)/pow(met.dp2,2) + pow(i1.f3 - cm.p3,2)/pow(met.dp3,2) + pow(i1.f4 - cm.p4,2)/pow(met.dp4,2));
}

/**
  Função para tirar metricas de todos os atributos
*/
void normalize(IRIS *iris, Metrica *met){
  int i;
  metrica(iris,met);
  for(i = 0; i < n; i++){
    iris[i].f1 = (iris[i].f1 - met->menorf1)/(met->maiorf1 - met->menorf1);
    iris[i].f2 = (iris[i].f2 - met->menorf2)/(met->maiorf2 - met->menorf2);
    iris[i].f3 = (iris[i].f3 - met->menorf3)/(met->maiorf3 - met->menorf3);
    iris[i].f4 = (iris[i].f4 - met->menorf4)/(met->maiorf4 - met->menorf4);
  }
  metrica(iris,met);
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

void print_Matriz(double **mtz){
  int i,j;
  printf("\t\t");
  for(i = 0; i < k; i++)
    printf("%d\t\t",i);
  printf("\n");
  for(i = 0; i < k; i++){
    printf("%d:\t",i);
    for(j = 0; j < k; j++){
      printf("%.4f\t\t",mtz[i][j]);
    }
    printf("\n");
  }
}

void mtz_distancias(IRIS *iris, int *rotList, double **mtz){
  int i,j;
  for(i = 0; i < k; i++){
    for(j = 0; j < k; j++){
      mtz[i][j] = distancias_cluster(iris,rotList,i,j);
    }
  }
}

double** cria_matriz(int x){
  double **mtz;
  mtz = (double **)malloc(x*sizeof(double));
  int i;
  for(i = 0; i < x; i++)
    mtz[i] = (double *)malloc(x*sizeof(double));
  return mtz;
}

/**
  Retorna um vetor com duas posições, e uma
  deve ser maximizada e a outra minimizada.
  Pos 0 --> Soma Intra
  Pos 1 --> Soma Inter
*/
double* val_obj(double **mtz){
  double *vet = (double *)malloc(2*sizeof(double));
  double somaInter = 0.0, somaIntra = 0.0;
  int i,j;
  for(i = 0; i < k; i++){
    for(j = 0; j < k; j++){
      if(i = j)
        somaIntra += mtz[i][j];
      else
        somaInter += mtz[i][j];
    }
  }
  somaInter = somaInter/2;
  vet[0] = somaIntra;
  vet[1] = somaInter;
  return vet;
}

/**
  Se tiver algum valor negativo na matriz de distancias,
  ele vai ignorar a amostra, pois significa que o algoritmo
  separou as instancias em uma quantidade de grupos inferior
  ao que foi solicitado
*/
int verf_neg(double **mtz){
  int i,j;
  for(i = 0; i < k; i++){
    for(j = 0; j < k; j++){
      if(mtz[i][j] < 0)
        return 1;
    }
  }
  return 0;
}
