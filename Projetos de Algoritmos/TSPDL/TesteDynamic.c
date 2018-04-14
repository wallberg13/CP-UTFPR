#include "headers.h"

void mtz1(){
  int **mtz = cria_matriz(5);

  mtz[0][0] = 0;
  mtz[0][1] = 82;
  mtz[0][2] = 167;
  mtz[0][3] = 114;
  mtz[0][4] = 8;

  mtz[1][0] = 82;
  mtz[1][1] = 0;
  mtz[1][2] = 240;
  mtz[1][3] = 151;
  mtz[1][4] = 29;

  mtz[2][0] = 167;
  mtz[2][1] = 240;
  mtz[2][2] = 0;
  mtz[2][3] = 63;
  mtz[2][4] = 253;

  mtz[3][0] = 114;
  mtz[3][1] = 151;
  mtz[3][2] = 63;
  mtz[3][3] = 0;
  mtz[3][4] = 146;

  mtz[4][0] = 8;
  mtz[4][1] = 29;
  mtz[4][2] = 253;
  mtz[4][3] = 146;
  mtz[4][4] = 0;

  //tsp_dynamic(mtz,5);
}

void mtz2(){
  int **mtz = cria_matriz(6);

  mtz[0][0] = 0;
  mtz[0][1] = 3;
  mtz[0][2] = 10;
  mtz[0][3] = 11;
  mtz[0][4] = 7;
  mtz[0][5] = 25;

  mtz[1][0] = 3;
  mtz[1][1] = 0;
  mtz[1][2] = 8;
  mtz[1][3] = 12;
  mtz[1][4] = 9;
  mtz[1][5] = 26;

  mtz[2][0] = 10;
  mtz[2][1] = 8;
  mtz[2][2] = 0;
  mtz[2][3] = 9;
  mtz[2][4] = 4;
  mtz[2][5] = 20;

  mtz[3][0] = 11;
  mtz[3][1] = 12;
  mtz[3][2] = 9;
  mtz[3][3] = 0;
  mtz[3][4] = 5;
  mtz[3][5] = 15;

  mtz[4][0] = 7;
  mtz[4][1] = 9;
  mtz[4][2] = 4;
  mtz[4][3] = 5;
  mtz[4][4] = 0;
  mtz[4][5] = 18;

  mtz[5][0] = 25;
  mtz[5][1] = 26;
  mtz[5][2] = 20;
  mtz[5][3] = 15;
  mtz[5][4] = 18;
  mtz[5][5] = 0;

//  tsp_dynamic(mtz,6);
}