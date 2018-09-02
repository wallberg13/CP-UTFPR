#ifndef LISTAESPARSA_H
#define LISTAESPARSA_H

#define MAX_MATRIZ 100

typedef struct noMatriz {
    int lin, col;
    double valor;
    struct noMatriz *abaixo;
} no_matriz;

typedef struct {
    no_matriz* colunas[MAX_MATRIZ];
} descr_matriz;

// inicializa uma a matriz esparsa
void inicializa_matriz(descr_matriz *matriz);

// insere o elemento valor na posi��o x,y da matriz
void insere_matriz(descr_matriz *matriz, int x, int y, double valor);

// recupera o valor na posi��o x,y da matriz - retorna zero se n�o existe
double consulta_matriz(descr_matriz *matriz, int x, int y);

// remove, se existir, o elemento na posi��o x,y
void exclui_matriz(descr_matriz *matriz, int x, int y);

// lista a matriz no formato tabular
void imprime_matriz(descr_matriz *matriz);

#endif // LISTAESPARSA_H
