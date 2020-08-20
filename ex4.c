/* faça um programa que leia a altura em centímetros de uma pessoa e exiba-a em metros e centimetros*/

#include<stdio.h>
//entrada:altura
//saida: converter para metros e cm
#include<locale.h>

int main(void){

    setlocale(LC_ALL,"Portuguese");
    int altura,metro, centi;
    
    printf("Informe a altura(cm)");
    scanf("%f", &altura);
    metro= altura/100;
    centi=altura%100;
    printf("A altura será %i metros e %.3f centimentos", metro,centi);
    return 0;
}