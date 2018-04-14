#include<stdlib.h>
#include<stdio.h>

#define JOINHA 1

/**
 * Na mochila que será inserida, o peso, será o quanto é permitido
 * para ser inserido.
 */
typedef struct No{
  struct No *link;
  char desc;
  int peso;
  int lucro;
  double custo_bene; //razão entre o custo e o peso.
}Item;

typedef struct {
  int peso_suportado;
  int peso_ocupado;
  int lucro;
  Item *item;
}Mochila;

//Cabeçalho das funções
int importar_arquivo_item(Item **bag, char *arquivo);
int add_Item(Item **bag, Item *item);
void inicializa_item(Item **bag);
int add_item_mochila(Mochila **bag, Item *item);
void inicializa_mochila(Mochila *mochila, int peso_suportado);
//Funções para importar arquivo

void inicializa_item(Item **item){
  *item = NULL;
}

void inicializa_mochila(Mochila *mochila, int peso_suportado){
  mochila->peso_suportado = peso_suportado;
  inicializa_item(&mochila->item);
  mochila->lucro = 0;
  mochila->peso_ocupado = 0;
}

int importar_arquivo_item(Item **bag,char *arquivo){
  FILE *file = fopen(arquivo,"r");
  int status;
  Item item;
  
  while((status = fscanf(file,"%c %d %d",&item.desc,&item.lucro,&item.peso)) != EOF){
    if(status == 3){
      add_Item(bag,&item);
    }
  }
  fclose(file);
  return (JOINHA);
  
}

/**
 * Função que adiciona os elementos na mochila (Os itens pré-definidos)
 * em ordem decrescente de custo beneficio.
 */
int add_Item(Item **bag, Item *item){
  Item *n, *p, *aux;
  n = (Item *)malloc(sizeof(Item));
  n->desc = item->desc;
  n->peso = item->peso;
  n->lucro = item->lucro;
  n->custo_bene = item->lucro/(double)item->peso;
  if(*bag == NULL){
    *bag = n;
    n->link = NULL;
  }else{
    p = *bag;
    aux = NULL;
    while((p!=NULL)&&(n->custo_bene < p->custo_bene)){
      aux = p;
      p = p->link;
    }
    if(p==*bag){
      n->link = *bag;
      *bag = n;
    }else{
      n->link = p;
      aux->link = n;
    }
  }
  return(JOINHA);
}

int imprimir_lista(Item **bag){
  Item *aux;
  aux = *bag;
  
  printf("Desc \t Peso \t Lucro \t Custo Bene \n");
  while(aux != NULL){
     printf("%c \t %.2d \t %.2d \t %.3f \n", aux->desc,aux->peso,aux->lucro,aux->custo_bene);
     aux = aux->link;
  }
}

/**
 * Função para fazer todo o procedimento da mochila, 
 * onde ira procurar a melhor forma de preencher a mochila;
 * Neste caso, não é preciso mostrar o custo beneficio, então não é preciso "setar"
 * ele no codigo.
 * Como este item sempre estara sendo adicionado no inicio, 
 * então em relação ao peso, pode ser comparado direto.
 */

int sub_main(Item **item_bag){
  Mochila bag; 
  Item *aux;
  aux = *item_bag;
  int peso;
  
  do{
    printf("Digite o valor que a sua mochila suporta: ");
    scanf("%d",&peso);
  }while(peso<=0);
  
  inicializa_mochila(&bag,peso);
  while(bag.peso_suportado > bag.peso_ocupado && aux != NULL){
    if(bag.peso_ocupado + aux->peso > bag.peso_suportado)
      break;
    bag.peso_ocupado += aux->peso;
    bag.lucro += aux->lucro;
    add_Item(&bag.item, aux);
    aux = aux->link;
  }
  imprimir_lista(&bag.item);
  printf("Lucro total: %d \n",bag.lucro);
  printf("Peso ocupado: %d \n",bag.peso_ocupado);
}