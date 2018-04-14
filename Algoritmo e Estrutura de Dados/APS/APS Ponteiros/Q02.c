#include<stdio.h>

int main(){
    int Int;
    char *p_Char;

    Int = 0x5A5958;
    p_Char = &Int;

    printf("%X %X %X", *p_Char,*p_Char + 1,*p_Char + 2);

}
