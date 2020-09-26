/* faça um programa que leia a altura em centímetros de uma pessoa e exiba-a em metros e centimetros*/

#include<stdio.h>
//entrada:altura
//saida: converter para metros e cm
#include<locale.h>

int main(void){

    int altura,metro, centi; //primeiro: declara variáveis
    setlocale(LC_ALL,"Portuguese");//configura para caracteres locais
    printf("Informe a altura(cm)"); //entrada usuário
    scanf("%i", &altura);//armazena o dado com o operador e indica endereço na memória
    metro= altura/100;
    centi=altura%100;
    printf("A altura será %i m e %i centimentos", metro,centi);
    return 0;
}