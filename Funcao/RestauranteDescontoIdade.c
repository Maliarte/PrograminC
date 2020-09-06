/* Um restaurante decidiu fazer uma promoção para seus clientes, usando os seguintes critérios:  (imagem)
Escreva um programa utilizando funções (modularizado) que pergunte o valor da  conta, nº de pratos e bebidas consumidos e exiba o montante a ser pago na conta atual e o vale desconto (se houver). A idade do cliente só deve ser perguntada se necessário.
Faça uma função para calcular o desconto da conta atual
Faça uma função para calcular o Vale desconto */
#include <stdio.h>
#include <locale.h>

float valeDescAge(int idoso,float valorConta,int nPratos, int nDrink);
float valorContaDescAge;
if (valorConta >= 300) {
    valorContaDescAge = valorConta - (valorConta*0.25);
}
if (valorConta >= 100) {
    valorContaDescAge = valorConta - (valorConta*0.15);

return valorContaDescAge;
}

float valeDescFd(int nPratos, int ndrink);
float valorContaDescF;
if (valorConta >= 400)  {
    valorContaDescF = 100;
}
if (valorConta < 400 && >= 150) {
    if nPratos >= 3 && nDrink >=6{
        valorContaDescF = 50;
    }
}
if (valorConta <=150 &&  nPratos>=1 && nDrink >=1) {
        valorContaDescF = 10;
    }
    return valorContaDescF;
}

int main() {
float valorConta, montante1, montante2, valorContaDescAge,valorContaDescF;
int nPratos, nDrink, idoso;
tx = 0;

printf("Entre com o valor da Conta: ");
scanf("%f", &valorConta);
printf("Entre com a quantidade de Pratos: ");
scanf("%i", &nPratos);
printf("Entre com a quantidade de Bebidas: ");
scanf("%i", &nDrink);
montante1 = valorConta - valeDescFd(float valorConta,int nPratos, int nDrink);
if (valorConta > 100) {
    printf("Parabéns, você está apto ao Desconto por Idade. Caso deseje Participar digite:1 para sim e 2 para não");
    scanf("%i", &idoso);
    if (idoso==1) {
            montante2 = valorConta - valeDescAge(int idoso, float valorConta,int nPratos, int nDrink);
        }
        else {
            tx =0;
        }

printf("\nO valor da conta atual é de: %.2f ", valorConta); 
printf("\n O vale desconto para pratos ficou em: %.2f", montante1);
printf("\n o desconto bonus caso idade acima de 50: %.2f", montante2);

return 0;


}