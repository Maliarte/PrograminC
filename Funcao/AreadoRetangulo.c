/* Escreva uma função para calcular e retornar a área de um retângulo. Esta função deverá receber os valores das duas dimensões (base e altura) e retornar o valor da área.*/

#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){

float base, altura, area;

printf("Entre com o valor da Base do Retangulo: ");
scanf("%f", &base);
printf("Entre com o valor da Altura do Retangulo: ");
scanf("%f", &altura);
area = base*altura;
printf("A area do Retangulo %.1f", area);









    return 0;
}