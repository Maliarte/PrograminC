/* Para ter uma ideia da quantidade de bebidas não alcoólicas a ser comprada para uma festa considera-se as seguintes quantidades:
Água com ou sem gás - 500 ml por pessoa
Refrigerantes e sucos - 400 ml por pessoa. Caso haja apenas refrigerante, o cálculo passa a ser de 750 ml por pessoa.
Construa um programa em C para mostrar:
a quantidade de garrafas de 1L de água a ser comprada e o quanto custará;
a quantidade de garrafas de 2L de refrigerante e a quantidade de garrafas de 1L de suco a serem comprados bem como quanto custarão (juntos), se ambos forem servidos;
a quantidade de garrafas de 2   L de refrigerante a ser comprado e o quanto custará, se for servido apenas refrigerante.
O número de pessoas da festa deve ser perguntado ao usuário. O valor do litro de água é R$ 4,00, do refrigerante é 5,40 e do suco é R$ 6,00

Exemplo: 
	Número de pessoas: 23
	Quantidade de garrafas de 1 litro de água: 12
	Quantidade de garrafas de refrigerante: 5 e de suco: 10
  Quantidade de garrafas só de refrigerante: 9

*/
#include<stdio.h>
#include<locale.h>
/*a sequencia de instruçoes dividir testar e somar sera chamada de calculaGarrafas*/

int calculaGarrafas( int npessoas, float consumo,  float volume){
/*litragem total*/
    int quantG = (npessoas * consumo)/volume; 
/*se a parte inteira e diff da div total e pq faltou garrafa logo compra mais uma.*/
        if (quantG != (npessoas * consumo)/volume) {
	        quantG ++;
        }
    return quantG; //produz essa saida atraves do calc
}
/*o codigo começa pela main*/
int main (void) {

int convidados;
int quantAgua, quantSuco, quantRefri, quantRefri2;

setlocale(LC_ALL,"portuguese");
printf("Digite o número de convidados: ");
scanf ("%i", &convidados);
printf("\n Numero de convidados: %i \n\n", convidados);
/*executa roteiro do calc de garrafas*/
quantAgua = calculaGarrafas(convidados, 0.5,1); /*consumo e volume*/
quantSuco = calculaGarrafas(convidados, 0.4,1);
quantRefri = calculaGarrafas(convidados, 0.4,2);  
/* se só servisse refri */
quantRefri2 = calculaGarrafas(convidados,0.75,2); /*calcula qtd refri inteiros*/

printf ("Garrafas de agua: %i \n\n", quantAgua);
printf ("Garrafas de refrigerante: %i \n\n", quantRefri);
printf ("Garrafas de suco: %i \n\n", quantSuco);
printf ("Garrafas de refrigerante (sem suco): %i \n\n", quantSuco);
return 0;
}
