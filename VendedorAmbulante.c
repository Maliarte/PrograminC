/* Um vendedor ambulante utiliza concentrado de uva para produzir suco e refresco de uva. Ele utiliza as seguintes proporções para o preparo do suco e do refresco: 
suco: 1 de concentrado para 2 de água; 
refresco: 1 de concentrado para 4 de água. 
O vendedor utiliza copos de 100 ml. 
Faça um programa que leia a litragem do concentrado que o vendedor irá comprar e o preço pago por este concentrado e informe ao vendedor ambulante: 
quantos litros de refresco de uva podem ser produzidos com todo o concentrado; 
quantos litros de suco uva podem ser produzidos com todo o concentrado; 
quanto ele irá receber  transformando o concentrado em suco de uva, considerando  R$2,00 por copo de suco; 
quanto ele irá receber transformando o concentrado em refresco de uva, considerando R$1,00 por copo de refresco; 
o percentual de lucro do suco; (valor recebido-custo)/valor recebido
o percentual de lucro do refresco (valor recebido-custo)/valor recebido
 
Ex: concentrado:1,5l	valor:10,00
	Com suco: 4,5l 🡪 45 copos 🡪 90,00 🡪  lucro: 88.9%
	Com refresco: 7,5l 🡪 75 copos 🡪 75,00🡪  lucro: 86.7%
 */
#include <stdio.h>

int main(void) {
  float custo,prodRef,prodSuco,receitaSuco,receitaRef,percSuco,percRef,copo=0.1,custoTotal,litragem;
  
  int aguaRef, aguaSuco;

  printf("Digite quantos litros deseja comprar de concentrado e pressione ENTER\n");
  
  scanf("%f",&litragem);

  printf("Digite o preco pago pelo concentrado informado acima e pressione ENTER\n"); 

  scanf("%f",&custo);

  aguaRef=litragem*4;
  
  prodRef=aguaRef*litragem;
  
  printf("Podem ser produzidos %.2f L de refresco\n",prodRef);

  aguaSuco=litragem*2;
  
  prodSuco=aguaSuco*litragem;
  
  printf("Podem ser produzidos %.2f L de suco.\n",prodSuco);

  receitaSuco=prodSuco/copo*2;

  printf("A receita com a venda de sucos eh de %.2f reais",receitaSuco);
  
  receitaRef=prodRef/copo*1;

  printf("A receita com a venda de refrescos eh de %.2f reais",receitaRef);

  custoTotal=litragem*custo;
  
  percSuco=(receitaSuco-custoTotal)/receitaSuco;
 
  printf("O percentual de lucro do suco eh: %.2f\n",percSuco);

  percRef=(receitaRef-custoTotal)/receitaRef;

  printf("O percentual de lucro do refresco eh: %.2f\n",percRef);
  
  return 0;
}