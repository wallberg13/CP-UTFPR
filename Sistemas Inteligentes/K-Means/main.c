#include "headers.h"

int main(int argc, char *arg[]){
  sorteio();
  if(argc > 1){
    import(arg[1]);
  }
}
