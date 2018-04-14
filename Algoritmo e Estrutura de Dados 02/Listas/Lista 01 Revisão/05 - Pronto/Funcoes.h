/** Considerando-se os exemplos a seguir, crie estruturas com hierarquias:
(a) motor (parafuso, marca, dimensoes, eixo, material de cada parte, .....)
(b) carro (motor, potencia, velocidade, .....)
(c) casa (tipo de madeira usada para porta e janela, definicao dos quartos, sala, proprietario, etc...)
(d) cadastro de pessoas (idade, sexo, altura, profissao,...)
(e) cadastro de produtos de um mercado (data de validade, preco, nome, ....)
(f) primitivas geometricas (ponto, linha, circulo, .....)
(g) relogio (engrenagens, hora atual, ponteiros, .....) */

//Letra A

typedef struct{
  int altura, largura, comprimento;
}dimensoes;

typedef struct{
  char tipo[30];
  dimensoes tamanho;
}parafuso;

typedef struct{
  char marca[30];
  dimensoes dimensoes_motor;
  parafuso parafuso_motor;
  int eixo;
  char material[5][30];
}motor;

//Letra B

typedef struct{
  motor motor_carro;
  int potencia; //Em HP
  int velocidade_max;
  char marca[30];
  char cor[20];
}carro;

//Letra C

typedef struct{
  dimensoes tamanho; //Estrutura da letra A
  char madeira[30];
}porta_janela;

typedef struct{
  int largura, comprimento;
  char cor[30];
}quartos;

typedef struct{
  int largura, comprimento;
  char cor[30];
  int quant_moveis;
}sala;

typedef struct{
  char proprietario[50];
  porta_janela porta_janela_casa[]; //É um vetor, pq o usuario define quantos janelas ou portas terá a casa
  quartos quartos_casa[];
  sala sala_casa[];
}casa;

//Letra D

typedef struct{
  char nome[50];
  int idade;
  char sexo[1];
  float altura;
}pessoa;

//Letra E (e) cadastro de produtos de um mercado (data de validade, preco, nome, ....)

typedef struct{
  int dia, mes, ano;
}data;

typedef struct{
  char nome[30];
  data data_vencimento;
  char setor[30];
  float preco;
}produto;

//Letra F primitivas geometricas (ponto, linha, circulo, .....)



//Letra G relogio (engrenagens, hora atual, ponteiros, .....) */
