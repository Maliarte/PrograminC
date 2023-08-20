#include "funcAux.h"
#include <stdio.h>
#include <math.h>

// Calcula distância entre dois pontos
//   E: coordenadas do ponto1 e do ponto2
//   S: distância entre os pontos recebidos
float calcDist(float x1,float y1,float x2,float y2){
  return sqrt(pow((x2-x1),2) + pow((y1-y2),2));
}


// Calcula perímetro de um triângulo dados os pontos
//   E: coordenadas do ponto1 , ponto2 e ponto 3
//   S: perímetro do tri
float calPerimTri(float xA,float yA,float xB,float yB,float xC, float yC){
  return calcDist(xA,yA,xB,yB)+calcDist(xA,yA,xC,yC)+calcDist(xC,yC,xB,yB);
}



// Mostra duas linhas
//   E: -
//   S: exibe na tela duas linhas
void exibeMold(void){
  printf("\n==============================");
  printf("\n==============================");
}



// Obtém as coordenadas de um ponto
//    E: nome do ponto
//    S: x,y do ponto
void obtemPonto(char pto,float *px,float *py){
  printf("\n Ponto %c",pto);
  printf("\n Coordenada x: ");
  scanf("%f", px);
  printf("\n Coordenada y: ");
  scanf("%f", py);
  return;
}
    