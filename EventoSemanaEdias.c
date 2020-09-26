/*
Faça um programa que leia o número de dias decorrido em um evento e exiba na tela o mesmo valor
expresso em números de semanas e número de dias. Por exemplo, se um usuário fornecer o valor 19, o
programa deve exibir: “2 semanas e 5 dias”.
*/
#include <stdio.h>

int main(void) {
  int d,semanas, dias;
  
  printf("Digite o numero de dias: \n");
  
  scanf("%d",&d);

  semanas=d/7;
  dias=d%7;

  printf("%d semanas e %d dias.\n",semanas,dias);


  return 0;
}