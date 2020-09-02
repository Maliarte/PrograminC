/* Uma loja dá desconto aos seus clientes  em duas situações:
20% sobre o valor total de uma compra, quando esta for superior a 100,00; 10% sobre o valor total de uma compra, quando forem compradas mais de 15 unidades. Caso o cliente tenha direito aos dois tipos de descontos, deve-se calcular primeiro o desconto em relação às unidades e sobre o valor resultante, o desconto em relação a quantidade de unidades.
Por exempo, João comprou 30 unidades de chocolates, cada uma custando R$  4,00
Total Compra: 120,00
Desconto pelas unidades: 12,00  (10% de 120,00)
Desconto pelo montante: 21,60  (20% de 108,00 (120,00 - 12,00))
Total a Pagar: 86,40
Faça um programa, que após perguntar a quantidade comprada e o valor unitário do produto,  mostre o valor total da compra e o valor total a pagar ( com o desconto) 
 */


#include <stdio.h>
#include <locale.h>

int main (void) {

float valorProduto, valorCompra, quantidade;
setlocale(LC_ALL, "portuguese"); 

//entrada
printf("Informe a quantidade de canecas: ");
scanf("%d", &quantidade);
printf("Informe o Valor unitário do Produto: ");
scanf("%f", &valorProduto);

valorCompra = quantidade * valorProduto;

printf("O total é %.2f", &valorCompra);

    return 0;
}