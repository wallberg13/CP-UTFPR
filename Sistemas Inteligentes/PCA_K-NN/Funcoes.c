#include "headers.h"

/**
  Função que irá fazer importação do arquivo em questão.
*/

#define infinito 99999.0
#define k 3
#define n_class 3
#define k_met 3

void import(char *arq){
  double **mtz;
  int dim[2];
  mtz = load(arq,dim);
  K_NN(mtz,dim);
}

/** Vetor especifico para este caso para fazer os rotulos
  0 - 49 ==> 0
  50 - 99 ==> 1
  100 - 149 ==>2
*/
int* vet_Rot(int *dim){
  int i;
  int *vet = (int *)malloc(dim[0]*sizeof(int));

  for(i = 0; i < dim[0]; i++){
    if(i >= 0 && i <= 49)
      vet[i] = 1;
    if(i >=50 && i <= 99)
      vet[i] = 2;
    if(i >= 100 && i <= 149)
      vet[i] = 3;
  }
  return vet;
}

void K_NN(double **iris,int *dim){
  // double **met;
  // int dimMet[2];
  // dimMet[0] = k_met;
  // dimMet[1] = dim[1];
  //met = cria_Matriz_Metricas(dimMet);
  /* Tem que ver quem é melhor */
  //metrica(iris,met,dim,dimMet);
  //normalize(iris,met,dim,dimMet);
  int *rot = vet_Rot(dim);

  int sol[dim[0]];
  Dist dist[dim[0]];
  int i,j;
  for(j = 0; j < dim[0]; j++){
    dist[j].dist = 0.0;
    dist[j].pos = 0;
    for(i = 0; i < dim[0]; i++){
      if(i != j){
        dist[i].dist = distEucl(iris[j],iris[i],dim);
        dist[i].pos = i;
      }
    }
    Merge_sort(dist,0,dim[0]-1);
    sol[j] = classifica(rot,dist);
  }
  //printDist(dist, iris);
  printSol(sol,rot,dim);
  printf("Porcentagem de Acerto: %.3f %% \n\n",contPerAcert(sol,rot,dim)*100.0);
  printf("Matriz de Confusão: \n");
  mtzConfu(sol,rot,dim);
  print_vet_arq(sol,dim[0]);
}

int classifica(int *rot, Dist *dist){
  int i;
  int x[n_class];
  vetZeros(x);
  for(i = 0; i < k; i++){
    x[rot[dist[i+1].pos] - 1]++;
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

double contPerAcert(int *sol, int *rot, int *dim){
  double soma = 0;
  int i;
  for(i = 0; i < dim[0]; i++){
    if(sol[i] == rot[i])
      soma++;
  }
  printf("Quant: %.1f Total: %d\n",soma, dim[0]);
  return (double)(soma/dim[0]);
}

/**
  Eixo J: Valor Certo
  Eixo I: Valor previsto.
*/
void mtzConfu(int *sol, int *rot, int *dim){
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
      for(z = 0; z < dim[0]; z++){
        if(sol[z] == j + 1 && rot[z] == i + 1)
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

void printSol(int *sol, int *rot, int *dim){
  int i;
  for(i = 0; i < dim[0]; i++){
    printf("Pos: %2d \tSol: %d Iris: %d \n",i,sol[i], rot[i]);
  }
}

void print_vet_arq(int *sol, int x){
  FILE *file = fopen("out.txt","w+");
  int i;
  for(i = 0; i < x; i++){
    fprintf(file,"%d\n",sol[i]);
  }
  fclose(file);
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
