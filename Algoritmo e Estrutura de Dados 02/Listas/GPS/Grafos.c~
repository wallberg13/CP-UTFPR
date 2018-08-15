#ifndef GRAFOS_C_INCLUDED
#define GRAFOS_C_INCLUDED

#include "Biblio.h"


//Inicializa grafo apontando para um vertice;
void inicia_grafo(Grafo *grafo){
  grafo->vert = NULL;
  grafo->quant_arestas = 0;
  grafo->quant_vertices = 0;
}

/** PARTE PARA ADICIONAR!!! */
int add_vertices(Grafo *grafo,int desc,char nome[50]){
  /**
   * Para não precisar carregar toda uma notação de ponteiros, como: grafo->vert->link
   * no caso de percorrer a lista, a função add_vert, que é a função que trabalha com a
   * lista de vertices(que no caso é a lista de locais)
   * dentro do grafo, faz todo o serviço e economiza "codigo"
   * ao percorrer a lista e vertices.
   * 
   * Se tudo correr bem, a quantidade de vertices no grafo ira ter um acrescimo, 
   * para dizer quantos locais possui no GPS.
   */
  if(add_vert(&grafo->vert,desc,nome))
    grafo->quant_vertices++;
  else
    return 0;
  return 1;
}

/**
 * Função para pesquisar vertices, tem a mesma funcionalidade da função: add_vertices.
 * que no caso é economizar codigo.
 * ela retorna o que o pesq_vert retorna para uma camada superior.
 * Esta função sera utilizada na função de add_vert, para assim, não ser permitido 
 * vertices com ID iguais.
 */
int pesquisa_vert(Grafo *grafo,int desc){
  return pesq_vert(&grafo->vert,desc);
}

/** É a mesma coisa de add em lista encadeada, a diferença é que não 
 pode ser adicioando vertice que já existe */
int add_vert(Vertices **vert, int desc,char nome[50]){
  Vertices *v, *aux;
  
  if(pesq_vert(vert,desc) != 0)
    return 0;
  
  v = (Vertices *)malloc(sizeof(Vertices));
  v->Vert = desc;
  v->link = NULL;
  v->arest = NULL;
  v->Grau = 0;
  strcpy(v->nome,nome);
  
  if(*vert == NULL){
    *vert = v;
  }else{
    aux = *vert;
    while(aux->link != NULL)
      aux = aux->link;
    aux->link = v;
  }
  return 1;
}

/** 
 * Função que verifica se o vertice existe, retorna a descrição do vertice caso
 * ele exista, e 
 */
int pesq_vert(Vertices **vert, int desc){
  Vertices *aux;
  aux = *vert;
  while(aux != NULL && aux->Vert != desc) //Percorre a lista ate achar o vertice com o mesmo
  //ID, que no caso é o que esta sendo procurado, se ele existir, retorna o proprio
   //ID do local, caso contrario, retorna 0.
    aux = aux->link;
  if(aux != NULL)
    return desc;
  else
    return 0;
}

/**
 * Função que exibe todos os vertices com os seus vizinhos.
 * Nesta função, ocorre de percorrer todos o elementos da lista de vertices
 * que esta na struct do grafo, e imprimir o que cada um tem.
 */
int imprime_vertices_grafo(Grafo *grafo){
  Vertices *aux,*aux2;
  aux = grafo->vert;
  Arestas *aux1;
  if(aux == NULL){
    printf("Grafo Vazio!! \n");
    return 0;
  }
  
  
  printf("ID   Local\n");
  while(aux != NULL){
    aux1 = aux->arest;
    printf("%02d - %s \n",aux->Vert,aux->nome);
    if(aux1 != NULL) printf("Vizinhos:\n");
    /**
     * Este laço interno é para percorrer a lista de vizinhos(a lista de adjacencias)
     * que cada vertice possui.
     * A unica informação que é usada do elemento da lista de arestas, é o vertice de 
     * chegada, onde na struct so possui o ID dele, mas para mostrar o nome, é utilizada
     * a função get_vertices() que tem como entrada o grafo, e a descrição do vertice
     * e retorna o endereço de memoria onde esta alocado o vertice de interesse, assim
     * sendo possivel assim poder acessar o nome do vertice de interresse.
     */
    while(aux1 != NULL){
      aux2 = get_vertices(&grafo->vert,aux1->desc);
      printf("\t-> %s. Distancia: %d m.\n",aux2->nome,aux1->peso);
      aux1 = aux1->link;
    }
    printf("\n");
    aux = aux->link;
  };
}

/**
 * Função que adiciona vizinhos entre os locais, tendo como algumento o
 * 	ini = ID do vizinho de inicio.
 * 	fim = ID do vizinho de chegada
 * 	peso = é a distancia entre os dois locais.
 * Neste caso, não faz diferença de na hora de adicionar, vc trocou a ordem, pois
 * como é um grafo não orientado, ter um vizinho A->B é equivalente a ter B->A,
 * por isso que eu preciso adicionar esse vizinho tanto na lista de vizinhos do
 * local ini, como tambem do local fim.
 */
int add_arestas(Grafo *grafo, int ini, int fim,int peso){
  Vertices *v1, *v2;
  
  /*
   * Se os locais propostos não existir, ele retorna 0, assim dando erro na hora 
   * de adicionar as arestas.
   */
  int i = pesquisa_arestas(grafo,ini,fim);
  if(i || i == -1)
    return 0;
  
  /*
   * O inicio e o fim não podem ser iguais, caso isso aconteça, retorna um erro tambem.
   */
  if(ini == fim){
    return 0;
  }else{
    v1 = get_vertices(&grafo->vert,ini);
    v2 = get_vertices(&grafo->vert,fim);
    
    /**
     * Como um local não pode ter mais de 5 vizinhos, aqui ele retorna
     * 0 dizendo que não é possivel add mais arestas. Esse grau é o que vai 
     * dizer quantos vizinhos tem cada Local.
     */
    if(v1->Grau == MAX || v2->Grau == MAX)
      return 0;
    
    v1->Grau++;
    v2->Grau++;
    //Aqui é onde sera adicionado de fato na lista de vizinhos(arestas) dentro
    //de cada local.
    add_arest(&v1->arest,fim,ini,peso);
    add_arest(&v2->arest,ini,fim,peso);
    
  }
  grafo->quant_arestas++;
  return 1;    
}

/** 
 * É o mesmo sistema para adicionar algum elemento em uma lista encadeada,
 * é apenas manipulação de ponteiros. Um detalhe é que essa lista vai adicionando em 
 * ordem crescente de distancia.
 */
int add_arest(Arestas **arest,int desc,int ini,int peso){
  Arestas *aux, *v,*aux1;
  
  v = (Arestas *)malloc(sizeof(Arestas));
  v->desc = desc;
  v->peso = peso;
  v->ini = ini;
  v->cong = 0;


  if(*arest == NULL){
    *arest = v;
    v->link = NULL;
  }else{
    aux = *arest;
    aux1 = NULL;
    while(aux != NULL && aux->peso <= peso){
      aux1 = aux;
      aux = aux->link;
    }
    if(aux1 == NULL){
      v->link = aux;
      *arest = v;
    }else{
      v->link = aux;
      aux1->link = v;
    }
    
    
  }
  return 1;
}

/**
 * Função de pesquisa, ela verifica a existencia de uma aresta,
 * esta função será usada quando for adicionar arestas, pois se uma aresta
 * já existe, não é permitido que adicione, assim retornando uma mensagem de erro.
 * Esta função apenas trata os erros.
 */
int pesquisa_arestas(Grafo *grafo, int ini, int fim){
  Vertices *v;
  
  v = grafo->vert;
  while(v!=NULL && v->Vert != ini)
    v = v->link;
  
  if(v == NULL)
    return -1;
  
  int i = pesq_arest(&v->arest,fim);
    
  v = grafo->vert;
  while(v != NULL && v->Vert != fim)
    v = v->link;
  
  if(v == NULL)
    return -1; // Não existe o vertice
  
  int j = pesq_arest(&v->arest,ini);
  
  //Se j e i que são resutados de uma busca dentro da lista for diferente de zero
  //é porque a aresta existe.
  if(j != 0 && i != 0)
    return 1; //Se achar, retorna verdadeiro
  else
    return 0; //Se não, retorna falso;
}

/**
 * A função que realmente realiza a pesquisa. 
 */
int pesq_arest(Arestas **arest,int desc){
  Arestas *v;
  v = *arest;
  
  while(v != NULL && v->desc != desc)
    v = v->link;
  if(v == NULL)
    return 0;
  else
    return desc;
}

/**
 * Função que faz a remoção de aresta acontecer na lista de arestas(vizinhos)
 * do local desejado.
 * Basicamente, essa função é apenas manipulação de ponteiros, retorna 0 caso a 
 * lista estiver vazia.
 */
int rem_arest(Arestas **arest, int desc){
  Arestas *v,*aux1;
  v = *arest;
  aux1 = NULL;
  
  if(*arest == NULL)
    return 0;
  
  while((v != NULL)&&(v->desc != desc)){
    aux1 = v;
    v = v->link;
  }
  
  if(aux1 == NULL){
    *arest = v->link;
    free(v);
    return 1;
  }else{
    if(v!=NULL){
      aux1->link = v->link;
      free(v);
      return 1;
    }else
      return 0;
  }
  
}

/**
 * Função que faz a verificação de remoção das arestas, caso a 
 * aresta existir, será possivel remover, caso contrario, retorna mensagem de erro.
 */
int remover_arestas(Grafo *grafo,int ini, int fim){
  Vertices *vert1, *vert2;
  int i = pesquisa_arestas(grafo,ini,fim);
  if(i){
    vert1 = get_vertices(&grafo->vert,ini);
    if(rem_arest(&vert1->arest,fim))
      vert1->Grau--;
    
    
    vert2 = get_vertices(&grafo->vert,fim);
    if(rem_arest(&vert2->arest,ini))
      vert2->Grau--;
    
  }else{
    //Condição que ira dizer que a aresta não existe, assim
    //retornando 0 para dizer que não foi possivel remover a aresta.
    if(i == -1 || !i) 
      return 0;
  }
  grafo->quant_arestas--;
  return 1;
}

/**
 * Função já mensionada antes, ela retorna um ponteiro de vertices, caso 
 * ele não existir, ira retornar nulo.
 * Com o inicio da lista de locais(a lista que esta na struct Grafo) e com
 * o ID do local, é possivel acessar este local, assim podendo "ver" o conteudo 
 * contido nele.
 */
Vertices* get_vertices(Vertices **vert,int desc){
  Vertices *v;
  v = *vert;
  while(v != NULL && v->Vert != desc)
    v = v->link;
  if(v != NULL)
    return v;
  else
    return NULL;
}

/**
 * Função para remover Vertices(Locais),
 * No começo é feito uma verificação para ver se o vertice existe, ou se 
 * o grafo tem algum elemento contido nele, caso essa condição for obedecida, a função
 * ira retornar 0, pois não é possivel remover o que não existe.
 * Depois, todas os outros locais que tem como vizinho este local que eu quero remover,
 * este local será excluido da lista de vizinhos de todos os outros locais.
 * O resto da função é manipulação de ponteiros, onde a lista sera percorrida ate onde
 * eu quero excluir, é feita uma manipulação para manter a integridade da lista de vertices
 * e no final tem como retorno 1, para dizer que deu tudo certo.
 * 
 */
int remover_vertices(Grafo *grafo,int Vert){
  Vertices *v,*aux;
  v = grafo->vert;
  Arestas *aux1;
  
  if(v == NULL || !pesquisa_vert(grafo,Vert))
    return 0;
  else{
    //Removendo dos locais quem tem esse local que eu quero remover como vizinho.
    while(v != NULL){ 
      if(rem_arest(&v->arest,Vert))
	v->Grau--;
      v = v->link;
    }
    
    /*
     * Para não ter vazamento de memoria, este trecho limpa toda a lista de vizinho
     * do vertice que eu quero excluir.
     */
    aux = get_vertices(&grafo->vert,Vert);
    aux1 = aux->arest;
    while(aux1 != NULL){
      rem_are(&aux1);
    }
    
    //Agora é feito a manipulação de ponteiros para remover o vertice desejado 
    //Da lista.
    v = grafo->vert;
    aux = NULL;
    while((v != NULL) && (v->Vert != Vert)){
      aux = v;
      v = v->link;
    }
    if(aux == NULL){
      grafo->vert = v->link;
      free(v);
    }else{
      aux->link = v->link;
      free(v);
    }
    grafo->quant_vertices--;
    return 1;
  }
}

/**
 * Função que adiciona ou remove congestionamento, fazendo assim dobrar o valor do
 * peso ou dividir.(só ira dividir por dois o vertice que tiver congestionado.).
 */
int adiciona_remove_congestionamento(Grafo *grafo,int flag,int i, int j){
  Vertices *v1, *v2;
  Arestas *aux,*aux2;
  //Flag -> 1 - Add Congestionamento, 0 - Remover Congestionamento
  v1 = get_vertices(&grafo->vert,i);
  v2 = get_vertices(&grafo->vert,j);
  if(v1 == NULL || v2 == NULL) //Primeiro Verifica se o vertice existe.
    return 0;
  
  //Laço para procurar v2 na lista de arestas de v1.
  aux = v1->arest;
  while(aux != NULL && aux->desc != v2->Vert){
    aux = aux->link;
  }
  
  //Laço para procurar v1 na lista de arestas de v2.
  aux2 = v2->arest;
  while(aux2 != NULL && aux2->desc != v1->Vert){
    aux2 = aux2->link;
  }
  
  //Se algum dos ponteiros aux ou aux2 for nulo, é porque os dois locais não são 
  //vizinhos entre si, e se isso acontece, retorna 0 como erro.
  if(aux2 == NULL || aux == NULL)
    return 0;
  
  //Se o usuario manda congestionar se ja tiver congestionado, ele retorna 
  //zero para não acontecer de congestionar mais de uma vez. o mesmo na hora de
  //tirar o congestionamento.
  if(aux->cong == flag || aux2->cong == flag){
    return 0;
  }
  
  //Chama-se a função para mudar o peso entre os vizinhos, tem como argumento
  //um ponteiro de arestas, que é justamente o local que ira ter o seu vizinho alterado.
  muda_peso(aux,flag);//Isso aconteceu na lista de adjancias do local de inicio
  muda_peso(aux2,flag);//Isso aconteceu na lista de adjancias do local final.
  
  return 1;
    
}

/**
 * Função para mudar os pesos de acordo com a flag desejada.
 * Muda o peso da aresta desejada pelo o usuario.
 */
int muda_peso(Arestas *arest,int flag){
  if(flag){
    arest->cong = flag;
    arest->peso = (arest->peso)*2;
  }else{
    arest->cong = flag;
    arest->peso = (arest->peso)/2;
  }
}

/**
 * Função para auxiliar na hora que for preciso fazer alguma operação, pois
 * todas as operações pede o ID do local e não o nome, pois pelo o ID
 * é mais facil de identificar todo mundo e ate na hora das manipulações.
 */
void print_vertice(Grafo *grafo){
  
  Vertices *aux;
  aux = grafo->vert;
  while(aux != NULL){
    printf("%02d - %s \n",aux->Vert,aux->nome);
    aux = aux->link;
  }

}

/**
 * Função que é executada ao sair do programa, assim limpando toda a memoria
 * que o programa precisou para ser executado.
 */
void destroi_grafo(Grafo *g){
  if(g->vert != NULL){
    while(g->vert!=NULL){
      while(g->vert->arest != NULL)
	rem_are(&g->vert->arest);
      remover_vertices(g,g->vert->Vert);
    }
  }
}

/**
 * Função justamente para limpar a lista de vizinhos(arestas) de cada local.
 */
void rem_are(Arestas **arest){
  Arestas *aux;
  if(*arest != NULL){
    aux = (*arest)->link;
    free(*arest);
    *arest = aux;
  }
}



#endif //GRAFOS_C_INCLUDED
