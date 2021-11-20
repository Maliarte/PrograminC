/* Faça um programa que mostre o sucessor e o antecessor de um número inteiro fornecido pelo usuário*/

#include <stdio.h>

int main(void) {

  int atual,antecessor, sucessor;

  printf("Digite um numero: \n");

  scanf("%d",&atual);

  antecessor=atual-1;
  sucessor=atual+1;

  printf("O numero digitado e: %d. Seu antecessor e: %d. Seu sucessor e: %d.\n",atual,antecessor,sucessor);


  return 0;
}
