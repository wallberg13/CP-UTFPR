/**
 * Funções das Hash Table!!!!
 */

#ifndef WALLV05_H
#define WALLV05_H

#define MAX_HASHTABLE 127

typedef struct noLista{
	char chave[30];
	double valor;
	struct noLista *link;
}no_lista;

typedef struct{
	no_lista* tabela[MAX_HASHTABLE];
	int cont; //não faz parte, é só curiosidade.
} descr_hashtable;

int hash(char* texto);

//Inicializa a Tabela
void inicializa_hashtable(descr_hashtable *table);

//Insere um valor double associado a uma string;
void insere_hashtable(descr_hashtable *table, char* texto, double valor);

//Recupera o valor de uma string ou retorna NaN se não existe (NaN = not-a-number)
double consulta_hastable(descr_hashtable *table, char *texto);

//desasspcoa p textp dp valor (remove da tabela)
void removeH(descr_hashtable *table, char* texto);

//destroi_hastable
void destroi_hastable(descr_hashtable *table);



#endif //WALLV05_H