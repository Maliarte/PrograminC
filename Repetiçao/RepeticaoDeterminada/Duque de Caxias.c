/*Duque de Caxias é uma cidade enorme (com quase 800 mil habitantes), dividida em 4 distritos: 1-Centro, 2-Campos Elíseos, 3-Imbariê e 4-Xerém. Josycarla e Beatriz são proprietárias de uma loja virtual bastante conhecida do segmento de vestuário da cidade citada. Com o intuito de poder melhorar as vendas de seu e-commerce e fidelizar seus clientes, elas gostariam de modernizar seu sistema de vendas. As métricas do seu negócio são:

- Frete grátis para compradores do primeiro distrito, acréscimo de 5% para os compradores do segundo distrito e acréscimo de 10% para os compradores do terceiro e quarto distrito. Para moradores de fora da cidade, duas opções: 15% para compradores das cidades da Baixada Fluminense e 20% para compradores das demais cidades.
- Formas de pagamento: desconto de 10% para pagamento em boleto a vista, calculado em cima do valor acrescido do frete (caso tenha). Não há desconto para pagamentos em cartões de crédito.

Faça um programa em linguagem C que calcule o número de vendas feitos no dia e mostre os seguintes resultados:

- Quantidade de vendas totais realizadas;
- Porcentagem das vendas totais realizadas para fora da cidade (independente se for na Baixada ou fora dela);
- Maior e menor venda realizada; 
- Faturamento total do dia.

Deverá ser informado pelo usuário: Valor da compra, localização do comprador e meio de pagamento. O programa deverá retornar as informações solicitadas se o valor da compra for 0.

=============================================== CÓDIGO COMEÇA AQUI ============================================ */

#include <stdio.h>
#include <locale.h>

int main (void) {

float valorInicialVenda, valorVendaFrete, valorVendasTotais = 0, vendaFinal = 0, cidadeForaBaixada, porcVendaForaBaixada, maiorVenda, menorVenda = 100000;
int localizacao, meioPagamento;
int contLocal1=0, contLocal2=0, contLocal3E4=0, contLocal5=0, qtdVendasRealizadas=0;

setlocale(LC_ALL,"Portuguese");

printf("Sejam bem-vindas ao programa de relatório de caixa da loja!\n\n");
printf("Informe o valor da venda realizada, ou informe 0 para poder encerrar o programa: ");
scanf("%f", &valorInicialVenda);

while (valorInicialVenda != 0)
{
    printf("\nCódigos de distritos da cidade de Duque de Caxias e outras localizações:\n");
    printf("1- Centro, 2- Campos Elíseos, 3- Imbariê, 4- Xerém, 5- Demais Cidades. \n");
    printf("\nAgora, informe a localidade do(a) cliente: ");
    scanf("%i", &localizacao);

    if (localizacao == 1) {
        valorVendaFrete=valorInicialVenda;
        contLocal1++;
    }
    if (localizacao == 2) {
        valorVendaFrete=valorInicialVenda*1.05;
        contLocal2++;
    }
    if ((localizacao == 3) || (localizacao == 4)) {
        valorVendaFrete=valorInicialVenda*1.1;
        contLocal3E4++;
    }
    if (localizacao == 5) {
        printf("\nCidade dentro ou fora da baixada?\nDigite 1 para cidade dentro da Baixada ou 2 para cidade fora da Baixada: ");
        scanf("%i", &cidadeForaBaixada);
        if (cidadeForaBaixada == 1) {
            valorVendaFrete=valorInicialVenda*1.15;
        }
        else {
            valorVendaFrete=valorInicialVenda*1.20;
        }
        contLocal5++;
    }

    printf("\nQual foi o meio de pagamento da venda?\nDigite 1 para boleto bancário ou 2 para cartões de crédito/débito: ");
    scanf("%i", &meioPagamento);

    if(meioPagamento == 1)
        vendaFinal=valorVendaFrete*0.9;
    else
        vendaFinal=valorVendaFrete;
        
    if (vendaFinal > maiorVenda)
    maiorVenda = vendaFinal;
    
    if (vendaFinal < menorVenda)
    menorVenda = vendaFinal;

    valorVendasTotais=vendaFinal+valorVendasTotais;
    qtdVendasRealizadas=contLocal1+contLocal2+contLocal3E4+contLocal5;
    perVendaForaBaixada=(contLocal5*100)/qtdVendasRealizadas;

printf("\nInforme o valor da venda realizada, ou informe 0 para poder encerrar o programa: ");
scanf("%f", &valorInicialVenda);
}

printf("\nQuantidade de vendas realizadas no dia: %i.", qtdVendasRealizadas);
printf("\nValor total das vendas realizadas: R$%.2f.", valorVendasTotais);
printf("\nPorcentagem das vendas realizadas para fora da Baixada: %.1f %%.", porcVendaForaBaixada);
printf("\nValor da maior venda realizada: R$%.2f.", maiorVenda);
printf("\nValor da menor venda realizada: R$%.2f.", menorVenda);

return 0;
}
