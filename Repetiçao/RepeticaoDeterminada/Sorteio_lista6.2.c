/*  Faça um programa que obtenha do teclado a quantidade N de valores a serem sorteados entre 0 e 100.   Seu programa deve exibir, para cada número sorteado, se ele está dentro ou fora do intervalo [1..15]
Número sorteado está dentro ou fora do intervalo
Quantos sorteados caíram dentro do intervalo
Qual a Soma de todos os números sorteados?
Qual o Valor médio dos números sorteados
 Qual o Valor médio dos números sorteados fora do intervalo?
 Para 1 lote (rodada) de valores sorteados, o programa pergunta a quantidade de valores e  responde:
Número sorteado está dentro ou fora do intervalo?
Quantos sorteados caíram dentro do intervalo?
Quantos sorteados caíram dentro do intervalo?
Qual a Soma de todos os números sorteados?
Qual o Valor médio dos números sorteados?
Qual o Valor médio dos números sorteados fora do intervalo?
 Considere que serão realizadas 3 rodadas.  No final da 3ª rodada, exibir:
A soma dos números sorteados em todas as rodadas

Para 1 lote (rodada) de valores sorteados, o programa pergunta a quantidade de valores e  responde:
Número sorteado está dentro ou fora do intervalo?
Quantos sorteados caíram dentro do intervalo?
Quantos sorteados caíram dentro do intervalo?
Qual a Soma de todos os números sorteados?
Qual o Valor médio dos números sorteados?
Qual o Valor médio dos números sorteados fora do intervalo?
Qual o Menor Número sorteado no intervalo --> DESAFIO

Considere que serão realizadas 3 rodadas. No final da 3ª rodada, exibir a soma dos números sorteados em todas as rodadas

*/

#include <stdio.h>
#include <stdlib.h> // funcoes rand() e srand()
#include <time.h> // funcao time()
#include <locale.h>

int main (void ) {
int N, n, i=0;

printf("\nInforme a quantidade a ser sorteada entre 0 e 100: ");
scanf("%i", &n);   
srand(time(NULL)); 
N = (rand()%100);

while (i < N) {
    num = rand()%100;
    printf("%i",n); i++;   
}


    return 0;
}