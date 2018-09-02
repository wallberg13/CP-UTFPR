/* Insere um registro de forma ordenada (pelo campo 1)
   em uma lista duplamente encadeada ordenada */
void insere_ordenado_lista(struct lista *i,    /* novo elemento */
                           struct lista **inicio, /* primeiro elemento da lista */
                           struct lista **final);  /* último elemento da lista */


/* Insere o registro i no final de uma lista duplamente encadeada */
void insere_final_lista(struct lista *i,
                        struct lista **inicio,
		        struct lista **final);


/* Mostra o conteudo da lista completa */
void mostra_lista(struct lista **inicio, /* primeiro elemento da lista */
	          struct lista **final);  /* último elemento da lista */


/* Mostra o comprimento da lista completa */
int tamanho_lista(struct lista **inicio, /* primeiro elemento da lista */
                  struct lista **final);  /* último elemento da lista */


/* Encontra o registro de numero posicao */
struct lista *encontra_registro_lista(int posicao,
                                               struct lista **inicio);

/* Encontra o registro em uma lista duplamente encadeada */
struct lista *encontra_registro(int campo1,
                                int campo2,
                                struct lista **inicio);

/* Remove o elemento registro da lista */
void apaga_registro(struct lista *registro,
                    struct lista **inicio,
                    struct lista **final);

/*  Apaga uma lista duplamente encadeada */
void apaga_lista(struct lista **inicio,
                 struct lista **final);




