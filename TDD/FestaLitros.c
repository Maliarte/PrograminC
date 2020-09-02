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

int main (void) {

int convidados, quantAguaA, quantRefri2;
int quantAgua, quantSuco, quantRefri;

setlocale(LC_ALL,"portuguese");
printf("Digite o número de convidados: ");
scanf ("%i", &convidados);

quantAgua = (convidados * 0.5);
quantSuco = (convidados * 0.4);
quantRefri2 = ((convidados * 0.75)/2);
quantRefri = ((convidados * 0.4) /2); //qts garras inteiras vou precisar por convidado
if (quantAgua != convidados * 0.5) {
	quantAgua=quantAgua + 1;
}
if (quantRefri != (convidados * 0.4) /2) {
    quantRefri ++; //incrementa valor em uma unidade
}

if (quantSuco != convidados * 0.4){
quantSuco += 1; //atribuiçao composta atualiza variavel correponte ao valor atribuido
}
// se só servisse refri calcula qtd refri inteiros
if (quantRefri2 != (convidados * 0.75) /2){
    quantRefri2 ++;
}

printf("\n Numero de convidados: %i \n\n",  convidados);
printf ("Garrafas de agua: %i \n", quantAgua);
printf ("Garrafas de refrigerante: %i \n", quantRefri);
printf ("Garrafas de suco: %i \n", quantSuco);
printf ("Garrafas de refrigerante (sem suco): %i \n", quantSuco);
//perceba que a receita para calculo é a mesma(dividir, testar e somar, logo poderia ser uma função)

return 0;
}