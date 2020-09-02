/* Escreva uma função para calcular e retornar a área de um círculo. Esta função deverá receber o valor do raio como parâmetro e retornar o valor da área.
A área de um círculo é pi vezes o raio elevado ao quadrado (A = π r²).
Efetue o calculo da area elevando o valor do raio ao quadrado e multiplicando por pi =3.14159*/
#include<stdio.h>
#include<locale.h>

float calculoarea (float raio, float pi){
float area = pi * (raio*raio);
return area;
}
int main () {
float raio, area;
float pi = 3.14159;

setlocale(LC_ALL, "portuguese");


printf("Entre com o valor do raio \n");
scanf("%f", &raio);
area = calculoarea(raio,pi);
printf("O valor da area de um circulo é: %.4f", area);
    return 0;
}