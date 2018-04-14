#include "sm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sm_t sm1;
unsigned char data[] = {'a','3','1',0x02, 0x0A, 0x00, 5, 't', 'e', 's', 't',
'e', 0x34};

unsigned char data2[] = {0x02, 0x0A, 0x00, 3, 's', 'a', 'c', 0x23};

void PrintResult(unsigned char *string){
  printf("%s \n", string);
}

void main(void){
  initSM(&sm1, 10, PrintResult);
  ExecSM(&sm1, data, 13);
  printf("\n");
  ExecSM(&sm1, data2, 8);
}
