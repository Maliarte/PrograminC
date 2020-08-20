/* Uma loja vende seus produtos no sistema entrada mais duas prestações, sendo a entrada maior do que ou igual às duas prestações, que devem ser iguais, inteiras e as maiores possíveis. 
Por exemplo, se o valor da mercadoria for R$ 270,00, a entrada e as duas prestações são iguais a R$ 90,00; se o valor da mercadoria for R$ 302,75, a entrada é de R$ 102,75 e as duas prestações são a iguais a R$ 100,00. Escreva um programa   que pergunte o valor da mercadoria e forneça o valor da entrada e das duas prestações, de acordo com as regras acima no documento.
Dica: transforme o valor em inteiro e use a divisão inteira por 3
Observe que uma justificativa para a adoção desta regra é que ela facilita a confecção e o consequente pagamento dos boletos das duas prestações.
*/

#include <stdio.h>

#include <stdlib.h>

#include <locale.h>//usar acentuação

int main()

{

    //habilita a acentuação para o portugues

    setlocale(LC_ALL,"Portuguese");

    int parteint;

    float valor, entrada, parcelas, calculo, partedec;

    printf("Valor do produto é: R$ ");

    scanf("%f",&valor);

    //aqui verifica se o valor digitado é inteiro

    //fazendo a subtração do valor menos a sua parte inteira

    //caso seja um float, se der 0 é inteiro

    if ((valor-(int)valor)==0)

    {

        calculo=valor/3;

        printf("\nA entrada e as duas prestacoes sao iguais a: R$%.2f \n", calculo);

    }

    else

    {

        parteint=(int)valor;

        partedec=valor-(int)valor;

        entrada=(parteint/3)+partedec;

        parcelas=(int)parteint/3;

        printf("A entrada é de R$%.2f, e as duas prestacoes sao iguais a R$%.2f \n", entrada, parcelas);

    }

    system("PAUSE");

    return 0;