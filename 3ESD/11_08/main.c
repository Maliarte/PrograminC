/*
Construa um programa que tendo como entrada três pontos quaisquer do plano que formam um triângulo
(ou seja, as coordenadas x e y do ponto A ,do ponto B e do ponto C calcule e mostre o perímetro deste
triângulo calculado por:

( d(A,B) + d(A,C) + d(B,C)

A fórmula da distância euclidiana é:

d² = (Xa-Xb)² + (Ya-Yb)².

A saída deve ter o seguinte formato:

=================================

=================================

Perimetro: xxx.xx

=================================

=================================

e: ponto a coordenada x: ... y:...
e: ponto b coordenada x: ... y:...
e: ponto c coordenada x: ... y:...

s: perimetro: xxx.xx
*/

#include <stdio.h>
#include "funcAux.h"

void exibeSaida(float perim){
  exibeMold();
  printf("\n\tPerímetro: %.2f", perim);
  exibeMold();
}
int main(void) {
  float xA,yA,xB,yB,xC,yC,perim;
  int i;
  for(i=0;i<3;i++){
    obtemPonto('A', &xA, &yA);
    obtemPonto('B', &xB, &yB);
    obtemPonto('C', &xC, &yC);
    perim=calPerimTri(xA,yA,xB,yB,xC,yC);
    exibeSaida(perim);
  }
 
}


 