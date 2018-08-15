#ifndef MENUS_C_INCLUDED
#define MENUS_C_INCLUDED

#include "Biblio.h"

int x = 0;
/**
 * Menus.c tem como função a exibição de todo o programa, é quem dá
 * a interface para o programa, ele apenas chama as funções para serem 
 * executadas.
 */
void menu(){
  Grafo grafo;
  inicia_grafo(&grafo);
  
  int i = 1;
  
  while(i!=0){
    clear();
    printf("-----> GPS v.1.0 <-----\n");
    printf("01 - Adicionar Locais. \n");
    printf("02 - Adicionar vizinhos nos locais. \n");
    printf("03 - Remover Locais. \n");
    printf("04 - Remover vizinhos. \n");
    printf("05 - Exibir GPS \n");
    printf("06 - Traçar Rota. \n");
    printf("07 - Adicionar ou Remover Congestionamento.\n");
    if(!x) printf("08 - \"Importar\" GPS proposto. \n"); //esse X é para permintir que o codigo para importar o GPS proposto seja executado
    //apenas uma vez.
    
    printf("00 - Sair \n\n");
    printf("\nOpção desejada: ");
    scanf("%d",&i);
    buffer();
    
    switch(i){
      case 1:
	interface1(&grafo); //Adicionar Locais
	break;
      case 2:
	interface2(&grafo); //Adicionar vizinhos nos locais
	break;
      case 3:
	interface3(&grafo); //Remover Locais
	break;
      case 4:
	interface4(&grafo); //Remover Vizinhos
	break;
      case 5:
	interface5(&grafo); //Exibir GPS
	break;
      case 6:
	interface6(&grafo); //Traça Rota
	break;
      case 7:
	interface7(&grafo); //Adicionar ou Remover Congestionamento
	break;
      case 8:
	if(!x) interface8(&grafo); //"Importa" o GPS proposto
	break;
      case 0:
	destroi_grafo(&grafo); //Chama a função para destruir todo o grafo.(Limpar a memoria usada no programa);
	break;
      default:
	printf("Opção Invalida\n");
    }
  }
}

/** Adiciona Local no GPS **/
void interface1(Grafo *grafo){
  int i = 1;
  char nome[50];
  while(i!=0){
    clear();
    printf("---->Adicionando Locais no GPS<----\n");
    printf("Digite o ID do Local: ");
    scanf("%d",&i);
    buffer();
    printf("Digite o nome do Local: ");
    scanf("%[^\n]s",nome); //Modo de como se ler uma String
    buffer();
    
    //A função add vertice tem 1 como retorno se a execução deu certo,e 0 
    //se não deu certo.
    if(add_vertices(grafo,i,nome)) 
      printf("Local adicionado com sucesso!! \n");
    else
      printf("Não foi possivel adicionar o local!! \n");
  
    printf("Deseja adicionar outro local?\n0 - Não\n1 a 9 - Sim\n");
    printf("Resposta: ");
    scanf("%d",&i);
  }
  printf("\nAperte para qualquer tecla para voltar para o menu. \n");
  buffer();
  aperta();
}

/** Adiciona vizinhos nos locais do GPS **/
void interface2(Grafo *grafo){
  int i = 1,j,k;
  while(i!=0){
    clear();
    printf("---->Adicionando vizinhos no GPS<----\n");
    
    
    printf("Digite o ID do local de inicio: ");
    scanf("%d",&i);
    
    printf("Digite o ID do local de chegada: ");
    scanf("%d",&j);
	
    do{
      printf("Digite a distancia(m) entre os locais: ");
      scanf("%d",&k);
      if(k<0)
	printf("A distancia deve ser positiva, digite novamente!! \n");
      
    }while(k<0);
    
    if(add_arestas(grafo,i,j,k))
      printf("Vizinho adicionado com sucesso!! \n");
    else
      printf("Não foi possivel adicionar o vizinho!! \n");
    
    printf("Deseja adicionar outro vizinho? \n0 - Não \n1 a 9 - Sim \n");
    printf("Opção: ");
    scanf("%d",&i);
  }
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** Remove Locais no GPS **/
void interface3(Grafo *grafo){
  int i;
  clear();
  printf("---->Removendo Locais do GPS<----\n");
  print_vertice(grafo);
  printf("Digite o ID do local que você deseja remover: ");
  scanf("%d",&i);
  
  //A remover vertice retorna 1 se conseguir remover e retorna 0 caso contrario.
  if(remover_vertices(grafo,i))
    printf("Local removido com sucesso!! \n");
  else
    printf("Não foi possivel remover este local!!\n");
  
  printf("\nAperte para qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** Remove vizinhos no GPS **/
void interface4(Grafo *grafo){
  int i, j;
  clear();
  printf("---->Removendo Vizinhos do GPS<----\n");
  print_vertice(grafo);
  printf("Digite o ID local de inicio: ");
  scanf("%d",&i);
  printf("Digite o ID local de chegada: ");
  scanf("%d",&j);
  
  if(remover_arestas(grafo,i,j))
    printf("Vizinho removido com sucesso!! \n");
  else
    printf("Não foi possivel remover o vizinho!!\n");

  printf("\nAperte qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();  
}

/** Imprimir Grafos*/
void interface5(Grafo *grafo){
  clear();
  imprime_vertices_grafo(grafo);
  printf("\nAperte qualquer tecla para voltar para o menu! \n");
  buffer();
  aperta();
}

/** 
 * Interface de usuario para traçar rota entre locais.
 * Foi utilizado o algoritmo de Dijkstra para obter o menor caminho.
 */
void interface6(Grafo *grafo){
  clear();
  int i, j,flag,k, resp;
  Vertices *aux;
  
  //Não se pode tracar uma rota de não tiver pelo menos 2 elementos no grafo
  if(grafo->vert == NULL || grafo->quant_vertices < 2){ 
    printf("---->Traçar Rota<----\n");
    if(grafo->vert == NULL)
      printf("GPS Vazio!\n");
    else 
      printf("GPS com poucos locais!"); //Poucos locais é pq não possui mais de 2 locais para 
      //poder traçar uma rota.
    
    printf("\nAperte qualquer tecla para voltar para o menu.\n");
    buffer();
    aperta();
    return ; //Este return sem nada só esta aqui para encerrar a função.
  }
  
  
  //Laço de repetição contando com tratamentos de erros.
  do{
    clear();
    printf("---->Traçar Rota<----\n");
    print_vertice(grafo);
    printf("Digite o ID do Local de inicio: ");
    scanf("%d",&i);
    if(i<0)
      printf("Digite Novamente! \n"); //Se o i<0, é por que o usuario colocou
      //um ID negativo, mas não existe ID negativo, portanto o programa ira pedir
      //para digitar o ID novamente.
    else{
      aux = get_vertices(&grafo->vert,i); //Função que retorna um ponteiro de vertices
      //Esse ponteiro vai dizer se o vertice existe ou não, caso ele não existir, o
      //programa ira mostrar uma mensagem de erro dizendo que não é possivel executar o programa.
      if(aux != NULL){
	//Caso o vertice exista, ou seja, aux != NULL, será exibido a descrição do
	//vertice e logo em seguida sera feita uma pergunta, verificando se é o local
	//que o usuario deseja.
	printf("%02d - %s \n",aux->Vert,aux->nome);
	do{
	  printf("Este é o local que deseja?\n1 - Sim\n0 - Não\nResp: ");
	  scanf("%d",&resp);
	  if(resp != 0 && resp != 1) //Tratamento de erro.
	    printf("Digite novamente!! \n");
	}while(resp != 0 && resp != 1);
      }else
	resp = 1; //Como o usuario digitou um ID não existente, para sair do laço,
	//o resp tem que ser diferente de 0.
    }
  }while(i<0 || resp == 0);
  
  if(aux == NULL){ //como o usuario digitou um vertice inexistente, logo aqui aparece
    //a mensagem de erro e volta para o menu anterior.
    printf("Erro ao executar o programa. \n");
    printf("\nAperte qualquer tecla para voltar para o menu.\n");
    buffer();
    aperta();
    return ;
  }
  
  do{
    clear();
    printf("---->Traçar Rota<----\n");
    printf("Deseja ter um ponto intermediario?\n1 - Sim\n0 - Não\nResp: ");
    scanf("%d",&flag);
    if(flag!=0 && flag != 1)
      printf("Digite novamente!\n"); //Se ele errar aqui, volta para o começo do laço.
    else{
      if(flag){ //Se a flag = 1, significa que o usuario quer o local intermediario
		//então ele ira tentar colocar o local intermediario, caso contrario,
		//não sera executado todo codigo a seguir.
	do{
	  clear();
	  //Esse preço de colocar o Local intermediario ou ate o local de chegada,
	  //fazem exatamente a mesma coisa que faz o algoritmo acima de colocar um valor
	  //no caminho inicial.
	  printf("---->Traçar Rota<----\n");
	  print_vertice(grafo);
	  printf("Digite o ID do Local intermediario: ");
	  scanf("%d",&k);
	  if(k<0)
	    printf("Digite Novamente! \n");
	  else{
	    aux = get_vertices(&grafo->vert,k);
	    if(aux != NULL){
	      printf("%02d - %s \n",aux->Vert,aux->nome);
	      do{
		printf("Este é o local que deseja?\n1 - Sim\n0 - Não\nResp: ");
		scanf("%d",&resp);
		if(resp != 0 && resp != 1)
		  printf("Digite novamente!! \n");
	      }while(resp != 0 && resp != 1);
	    }else
	      resp = 1;
	  }
	}while(i<0 || resp == 0);
      }
    }
  }while(flag!=0 && flag != 1);
  
  if(aux == NULL){
    printf("Erro ao executar o programa. \n");
    printf("\nAperte qualquer tecla para voltar para o menu.\n");
    buffer();
    aperta();
    return ;
  }
  
  //É a mesma coisa que acontece quando for escolher o local de inicio e o 
  //local intermediario.
  do{
    clear();
    printf("---->Traçar Rota<----\n");
    print_vertice(grafo);
    printf("Digite o ID do Local de Chegada: ");
    scanf("%d",&j);
    if(j<0)
      printf("Digite Novamente! \n");
    else{
      aux = get_vertices(&grafo->vert,j);
      if(aux != NULL){
	printf("%02d - %s \n",aux->Vert,aux->nome);
	do{
	  printf("Este é o local que deseja?\n1 - Sim\n0 - Não\nResp: ");
	  scanf("%d",&resp);
	  if(resp != 0 && resp != 1)
	    printf("Digite novamente!! \n");
	}while(resp != 0 && resp != 1);
      }else
	resp = 1;
    }
  }while(i<0 || resp == 0);
  
  if(aux == NULL){
    printf("Erro ao executar o programa. \n");
    printf("\nAperte qualquer tecla para voltar para o menu.\n");
    buffer();
    aperta();
    return ;
  }
  
  //Como o retorno da funcao dentro do IF é 0 ou 1, o if trata como se fosse 
  //verdadeiro ou falso, assim, de for !0 (não falso que é verdadeiro), é exibido uma
  //mensagem de erro ao executar o programa. Algo do tipo de ter adicionado algum 
  //local que não exite, ou se o local que vc que esta fora do grafo em questão.
  if(!CaminhoMinimo(grafo,i,j,flag,k))
    printf("Erro ao executar o algoritmo.\n");
  
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
}

/**
 * Interface de usuario para adicionar ou remover um congestionamento
 */
void interface7(Grafo *grafo){
  clear();
  int i, j,flag,resp;
  Vertices *aux;
  
  /**
   * Neste trecho, essa flag em questão, é para saber se quer add ou remover
   * congestionamento, lembrando que não é permitido congestionar um trecho 2 vezes.
   * A flag que diz se o trecho esta ou não consestionado, é aquela tem o nome de
   * cong na struct Arestas.
   */
  do{
    printf("---->Adicionar ou Remover Congestionamento<----\n");
    printf("O que deseja fazer? \n1 - Adicionar\n0 - Remover\nResp: ");
    scanf("%d",&flag);
    if(flag != 0 && flag != 1)
      printf("Digite novamente, Somente 0 ou 1 \n");
  }while(flag != 0 && flag != 1);
  
  
  do{
    /**
     * O algoritmo de tratamento de erros utilizado no menu do caminho minimo, é
     * praticamente igual nessa parte. Se ele não encontrar o vertice digitado, o
     * programa mostra uma mensagem de erro, caso contrario, executa normalmente o 
     * programa.
     */
    clear();
    printf("---->Adicionar ou Remover Congestionamento<----\n");
    print_vertice(grafo);
    printf("Digite o local inicial: ");
    scanf("%d",&i);
    
    aux = get_vertices(&grafo->vert,i);
    if(aux != NULL){
      printf("%02d - %s \n",aux->Vert,aux->nome);
      do{
	printf("Este é o vertice que deseja?\n1 - Sim\n0 - Não\nResp: ");
	scanf("%d",&resp);
	if(resp != 0 && resp!= 1)
	  printf("Digite Novamente! \n");
      }while(resp != 0 && resp!= 1);
    }else{
      resp = 1;
    }
  }while(resp == 0);
  if(aux != NULL){
    do{
      clear();
      printf("---->Adicionar ou Remover Congestionamento<----\n");
      print_vertice(grafo);
      printf("Digite o local final: ");
      scanf("%d",&j);
      
      aux = get_vertices(&grafo->vert,j);
      if(aux != NULL){
	printf("%02d - %s \n",aux->Vert,aux->nome);
	do{
	  printf("Este é o vertice que deseja?\n1 - Sim\n0 - Não\nResp: ");
	  scanf("%d",&resp);
	  if(resp != 0 && resp!= 1)
	    printf("Digite Novamente! \n");
	}while(resp != 0 && resp!= 1);
      }else{
	resp = 1;
      }
    }while(resp == 0);
    /**
     * A função adiciona_remove_congestionamento tem como retorno 1 se 
     * tudo ocorrer bem, e 0 se algum erro acontecer, se acontecer algum erro, 
     * o que vem a seguir analisa a flag, e mostra a mensagem dependendo da operação
     * que o usuario desejou fazer.
     */
    if(!adiciona_remove_congestionamento(grafo,flag,i,j)){
      if(flag)
	printf("Erro ao tentar adicionar o congestionamento.\n ");
      else
	printf("Erro ao tentar remover o congestionamento.\n ");
    }else
      printf("Operação bem sucedida. \n");
  }else{
    printf("Erro ao tentar realizar operação.\n");
  }
  
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
}

/** 
 * Função para não precisar adicionar aresta por aresta e vertice por vertice
 * o grafo proposto.
 * 
 */
void interface8(Grafo *grafo){
  clear();
  add_vertices(grafo,1,"PATIO BETEL");
  add_vertices(grafo,2,"HOSPITAL SANTA CRUZ");
  add_vertices(grafo,3,"RAUSE CAFE-NEX");
  add_vertices(grafo,4,"QUINTANDA");
  add_vertices(grafo,5,"CASTELO DO BATEL");
  add_vertices(grafo,6,"PRAÇA DO JAPAO");
  add_vertices(grafo,7,"ARMAZEM ITALIANO");
  add_vertices(grafo,8,"KANDOO");
  add_vertices(grafo,9,"BAROLO TRATTORIA");
  add_vertices(grafo,10,"EMPORIO KAMINSKI");
  add_vertices(grafo,11,"CLUBE CURITIBANO");
  add_vertices(grafo,12,"SHOPPING CRYSTAL PLAZA");
  add_vertices(grafo,13,"PORCIN TRATTORIA");
  add_vertices(grafo,14,"SLAVIERO EXECUTIVE BATEL");
  add_vertices(grafo,15,"TAISHO");
  add_vertices(grafo,16,"ARENA DA BAIXADA");
  add_vertices(grafo,17,"ACADEMIA FITNESS CENTER");
  add_vertices(grafo,18,"JARDINS GRILL");
  add_vertices(grafo,19,"Z E N MASSAGENS");
  add_vertices(grafo,20,"PULSE CLUB");
  add_vertices(grafo,21,"MULTI EVENTOS FORMATURAS");
  add_vertices(grafo,22,"PRAÇA OUVIDOR PARDINHO");
  add_vertices(grafo,23,"SANTA CASA");
  add_vertices(grafo,24,"REI DO PAO");
  add_vertices(grafo,25,"RESTAURANTE JAPONES MIYAKO");
  add_vertices(grafo,26,"UNIVERSIDADE TECNOLOGICA FEDERAL DO PARANA");
  add_vertices(grafo,27,"JAPAN GAMES");
  add_vertices(grafo,28,"TABACARIA CENTRAL");
  add_vertices(grafo,29,"HOTEL NIKKO");
  add_vertices(grafo,30,"SHOPPING ESTAÇAO");
  add_vertices(grafo,31,"FACULDADE PEQUENO PRINCIPE");
  add_vertices(grafo,32,"VICTORIA VILLA HOTEL");
  add_vertices(grafo,33,"CORREIOS");
  add_vertices(grafo,34,"BAR BRAHMA");
  add_arestas(grafo,1,2,100);
  add_arestas(grafo,1,4,200);
  add_arestas(grafo,2,3,200);
  add_arestas(grafo,2,6,300);
  add_arestas(grafo,3,4,100);
  add_arestas(grafo,3,6,200);
  add_arestas(grafo,4,5,200);
  add_arestas(grafo,4,12,400);
  add_arestas(grafo,5,6,200);
  add_arestas(grafo,5,14,300);
  add_arestas(grafo,6,7,300);
  add_arestas(grafo,6,8,200);
  add_arestas(grafo,7,17,600);
  add_arestas(grafo,8,9,100);
  add_arestas(grafo,8,10,100);
  add_arestas(grafo,9,18,800);
  add_arestas(grafo,10,11,100);
  add_arestas(grafo,10,15,500);
  add_arestas(grafo,11,21,1000);
  add_arestas(grafo,11,16,700);
  add_arestas(grafo,12,13,100);
  add_arestas(grafo,12,20,500);
  add_arestas(grafo,13,14,100);
  add_arestas(grafo,14,17,200);
  add_arestas(grafo,15,19,300);
  add_arestas(grafo,16,21,400);
  add_arestas(grafo,17,20,400);
  add_arestas(grafo,17,24,500);
  add_arestas(grafo,17,18,200);
  add_arestas(grafo,18,19,100);
  add_arestas(grafo,18,26,500);
  add_arestas(grafo,18,31,800);
  add_arestas(grafo,19,22,300);
  add_arestas(grafo,20,23,200);
  add_arestas(grafo,21,22,100);
  add_arestas(grafo,22,25,100);
  add_arestas(grafo,22,31,400);
  add_arestas(grafo,23,28,300);
  add_arestas(grafo,24,26,100);
  add_arestas(grafo,24,27,200);
  add_arestas(grafo,25,34,600);
  add_arestas(grafo,26,27,200);
  add_arestas(grafo,26,30,100);
  add_arestas(grafo,27,28,100);
  add_arestas(grafo,27,30,200);
  add_arestas(grafo,28,29,100);
  add_arestas(grafo,29,32,400);
  add_arestas(grafo,30,32,300);
  add_arestas(grafo,30,33,500);
  add_arestas(grafo,31,33,200);
  add_arestas(grafo,32,33,300);
  add_arestas(grafo,33,34,200);
  x = 1;
  printf("Grafo \"importado\" com sucesso. ");
  printf("\nAperte qualquer tecla para voltar para o menu.\n");
  buffer();
  aperta();
  
}

#endif
