/*  Faça um programa que calcule o tempo (em anos e meses completos)que uma pessoa irá demorar para poupar R$ 1.000.000,00 (Um Milhão de Reais). O usuário informa o salário mensal e o total de despesas mensais.*/
#include<stdio.h>
#include<locale.h>
//#define MILHAO 1000000;

int main(void) {
int tempo;
float poupa,sal, desp;
int anos, meses;
setlocale(LC_ALL,"Portuguese");
    printf("Digite salário mensal: ");
    scanf("%f", &sal);
    printf("Digite despesas: ");
    scanf("%f", &desp);
    poupa= sal - desp;
    tempo = 1000000/poupa;
    anos = tempo/12;
    meses = tempo%12;
    printf("\n Poupa: R$ %.2f -->  %i anos e %i meses \n",poupa,anos, meses);

    return 0;
}