/* Uma loja vende seus produtos no sistema entrada mais duas prestações, sendo a entrada maior do que ou igual às duas prestações, que devem ser iguais, inteiras e as maiores possíveis. Por exemplo, se o valor da mercadoria for R$ 270,00 a entrada e as duas prestações são iguais a R$ 90,00; se o valor da mercadoria for R$ 302,75, a entrada é de R$ 102,75 e as duas prestações são a iguais a R$ 100,00. Escreva um programa   que pergunte o valor da mercadoria e forneça o valor da entrada e das duas prestações, de acordo com as regras acima no documento.
Dica: transforme o valor em inteiro e use a divisão inteira por 3
Observe que uma justificativa para a adoção desta regra é que ela facilita a confecção e o consequente pagamento dos boletos das duas prestações.
*/
//pensar a saida, depois a entrada 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//usar acentuação conforme orientação geográfica

int main() {
    
    float valor, prest,entrada;

    printf("Valor do produto é: R$ "); //entrada
    scanf("%f",&valor);
    prest = (int)valor/3; /* divisão do valor para descobrir prest com operacao typecast */
    entrada = valor-2*prest;

   printf("\n A entrada %.2f, a prestaçao será de 2x R$ %.2f parcelas\n",entrada, prest);
   
    return (0);
}