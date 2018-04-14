#include <stdio.h>
#include "Menus.h"


/* Menu principal */
int menu_principal(void)
{
  int escolha;

  do {
    printf("\n*******************Menu Principal************************* \n");
    printf("ATENCAO: Necessario gerar solucao inicial antes de refinar\n");
    printf("                1. Gere solucao inicial \n");
    printf("                2. Descida \n");
    printf("                3. Descida randomica \n");
    printf("                4. Descida com Primeiro de Melhora \n");
    printf("                5. Multi-Start \n");
    printf("                6. Simulated Annealing \n");
    printf("                7. Busca Tabu \n");
    printf("                8. ILS \n");
    printf("                9. GRASP \n");
    printf("               10. VND \n");
    printf("               11. VNS \n");
    printf("               12. Algoritmos Geneticos \n");
    printf("               13. Algoritmos Memeticos \n");
    printf("               14. Colonia de Formigas \n");
    printf("                0. Sair \n");
    printf("                Escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 0 || escolha > 14);
  return escolha;
}


/* Menu de geracao de uma solucao inicial */
int menu_solucao_inicial(void)
{
  int escolha;

  do {
    printf("\n************Geracao da Solucao Inicial**************** \n");
    printf("                1. Gulosa (Vizinho mais proximo) \n");
    printf("                2. Parcialmente gulosa (Vizinho mais proximo) \n");
    printf("                3. Gulosa (Insercao Mais Barata) \n");
    printf("                4. Parcialmente gulosa (Insercao Mais Barata) \n");
    printf("                5. Aleatoria \n");
    printf("                escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 1 || escolha > 5);
  return escolha;
}


/* Menu GRASP */
int menu_GRASP(void)
{
  int escolha;

  do {
    printf("\n*******************Menu GRASP************************* \n");
    printf("                1. Vizinho Mais Proximo \n");
    printf("                2. Insercao Mais Barata \n");
    printf("                Escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 1 || escolha > 2);
  return escolha;
}


/* Menu Algoritmos Geneticos */
int menu_AG(void)
{
  int escolha;

  do {
    printf("\n****************Menu Algoritmos Geneticos********************** \n");
    printf("                1. Operador OX \n");
    printf("                2. Operador ERX \n");
    printf("                Escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 1 || escolha > 2);
  return escolha;
}

