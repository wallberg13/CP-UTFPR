#include "stdio.h"
int main (void){
    int i;
    //12 meses com três caracteres cada
    char nomeMes[12][4] = {"jan", "fev", "mar", "abr", "mai",
    "jun", "jul", "ago", "set", "out", "nov", "dez"};
    for (i=0; i<12; i++){
        printf("%2d - %s\n", i+1,nomeMes[i]);
    }
}
