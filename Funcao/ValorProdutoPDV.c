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
  
  float precoBasico, desconto, precoTotal, xx, yy;
  int codProduto;

  printf("Digite o codigo do produto com quatro digitos numericos (exemplo: 1234) \n");

  scanf("%d",&codProduto);

  xx=codProduto/100;
  yy=codProduto%100;

  precoBasico = (xx *15.00)+yy;
  desconto = precoBasico*(yy/100);
  precoTotal = precoBasico- desconto;


  printf("Preco basico: %.2f R$\n",precoBasico);
  printf("Percentual de desconto: %.0f %%\n",desconto);
  printf("Preco total a pagar:R$ %.2f\n", precoTotal);

  return 0;
}
