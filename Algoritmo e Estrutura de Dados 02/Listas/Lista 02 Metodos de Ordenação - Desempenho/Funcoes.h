#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define infinito 10001


/** 1° Questão*/
void bublesort(int v[], int tam){
  int aux;
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam - 1; j++){
      if(v[j] > v[j+1]){
	aux = v[j];
	v[j] = v[j+1];
	v[j+1] = aux;
      }
    }
  }
}

void QuickSort(int v[], int ini, int fim){
  int i, j, pivo, aux;
  
  i = ini;
  j = fim;
  pivo = v[(ini + fim)/2];
  do{
    while((v[i] < pivo) && (i<fim)) i++;
    while((v[j] > pivo) && (j>ini)) j--;
    
    if(i <= j){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  }while(i <= j);
  if(j > ini)
    QuickSort(v,ini,j);
  if(i < fim)
    QuickSort(v,i,fim);
}

void Merge(int v[], int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1], R[n2 + 1];
  int i, j, k;
  
  for(i = 0; i < n1; i++)
    L[i] = v[p+i];
  
  for(j = 0; j < n2; j++)
    R[j] = v[q + j + 1];
  
  L[n1] = infinito;
  R[n2] = infinito;
  
  j=i=0;
  
  for(k = p; k <= r; k++){
    if(L[i] <= R[j]){
      v[k] = L[i];
      i++;
    }else{
      v[k] = R[j];
      j++;
    }
  }
}

void Merge_sort(int v[], int p, int r){
  int q;
  if(p < r){
    q = (p+r)/2;
    Merge_sort(v,p,q);
    Merge_sort(v,q+1, r);
    Merge(v,p,q,r);
  }
}

/** 2° Questão */
void sorteio(){
  srand(time(NULL));
}

void povoando_vetor(int v[],int tam){
  for(int i = 0; i < tam; i++)
    v[i] = 1 + rand()%(1000);
}

void copia_vetor(int v_original[], int v_copia[], int tam){
  for(int i = 0; i < tam; i++)
    v_copia[i] = v_original[i];
}


void sub_main(){
  int tam,resp;
  FILE *arquivo;
  arquivo = fopen("arquivo.txt","w");
  
  fprintf(arquivo,"Tempo de Execução dos Metodos de Ordenação!!\n");
  do{
    system("clear");
    printf("Digite o tamanho do vetor: "); //2° Questão
    scanf("%d",&tam);
    
    fprintf(arquivo,"tamanho: %d",tam);
    int quick[tam], buble[tam], merge[tam];
    
    int v[tam];
    povoando_vetor(v,tam); //3° Questão
    copia_vetor(v,quick,tam);
    copia_vetor(v,buble,tam);
    copia_vetor(v,merge,tam);
    
    clock_t t;
    t = clock();
    QuickSort(quick,0,tam);
    t = clock() - t;
    printf("Tempo do Quick: %.4f \n",((float)t)/CLOCKS_PER_SEC);
    fprintf(arquivo,"Tempo do Quick: %.4f \n",((float)t)/CLOCKS_PER_SEC);
    
    t = clock();
    bublesort(buble,tam);
    t = clock() - t;
    printf("Tempo do Buble: %.4f \n",((float)t)/CLOCKS_PER_SEC);
    fprintf(arquivo,"Tempo do Buble: %.4f \n",((float)t)/CLOCKS_PER_SEC);
   
    t = clock();
    Merge_sort(merge,0,tam);
    t = clock() - t;
    printf("Tempo do Merge: %.4f \n",((float)t)/CLOCKS_PER_SEC);
    fprintf(arquivo,"Tempo do Merge: %.4f \n",((float)t)/CLOCKS_PER_SEC);
   

    printf("Deseja adicionar outro tamanho (0 para fechar o programa, qualquer numero pra continuar): ");
    scanf("%d",&resp);
  }while(resp != 0);
  fclose(arquivo);
}	

