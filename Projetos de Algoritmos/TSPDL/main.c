#include "headers.h"

int main(int argc, char *arg[]){
  sorteio();
  if(argc > 2){
    import(arg[1],arg[2]);
  }
}
