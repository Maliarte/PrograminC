/* Faça um programa para mostrar o valor total a pagar por um produto em promoção. O valor básico do produto e percentual de desconto são obtidos do código do produto que possui 4 algarismos de acordo com a seguinte regra: 
Código do produto: xxyy
 Preço básico: XX*15,00 + YY
 Percentual de desconto: YY 
Por exemplo: código do produto: 2314
Preço : 23*15,00 + 14,00 = 359,00 
Desconto: 14% 
Total a pagar: 308,74 
Lembre-se que: 32/10 🡪 3  (quociente da divisão inteira) e  32%10🡪 2( resto da divisão inteira)
*/
#include <stdio.h>

int main(void) {
  
  float precoBasico, desconto, precoTotal;
  
  int cod;

  printf("Digite o codigo do produto com quatro digitos numericos (exemplo: 1234) \n");

  scanf("%d",&cod);

  precoBasico=(cod/100)*15+cod%100;

  printf("Preco basico: %f.2\n",precoBasico);

  desconto=cod%100;

  printf("Percentual de desconto: %.0f\n",desconto);

  precoTotal=precoBasico*(1-(desconto/100));

  printf("Preco total a pagar: %.2f\n", precoTotal);

  return 0;
}