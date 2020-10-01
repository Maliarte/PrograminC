/* 
Nome: Marilia Silva Cardoso dos Santos 
Atividade para nota AV1


Uma lanchonete aceita 4 formas de pagamento: cartão de crédito, cartão de débito, dinheiro e ticket refeição. Faça um programa em C para exibir o valor a ser devolvido (troco) aos clientes ou a mensagem “Não há troco”. Para cada cliente, o seu programa deverá ler o valor da despesa a ser paga (real) pelo cliente e o tipo de pagamento (inteiro): 1 para cartão de débito, 2 para cartão de crédito, 3 para dinheiro ou 4 para ticket. Se o pagamento for realizado por cartão (débito ou crédito), não há troco. Para os demais tipos de pagamento, pode ou não haver troco. Se for pagamento em dinheiro, será lido, também, o valor pago. Se o pagamento for com tickets, devem ser lidos a quantidade de tickets e o valor de cada ticket (repare que os valores podem ser diferentes). Término da leitura dos clientes: valor da despesa = 0.


*/

#include <stdio.h>
#include <locale.h>

int main(void) {
    float despesa, valorRecebido, valorTic;
    int payForm, ctTick;
    totValor = 0;
    cont = 0;

    printf("Informe o valor a ser pago: ");
    scanf("%f", &despesa);
    printf("Informe o tipo de pagamento: \n 1.Cartao de Credito 2.Cartao de Debito 3.Dinheiro 4.Ticket Refeicao ");
    scanf("%d", &payForm);
    if (payForm == 1) {
        printf("Pagamento efetuado em cartao de credito. \n ");
    }   else if (payForm == 2) {
        printf("Pagamento efetuado em cartao de debito. \n ")
        }
            else if (payForm == 3) {
            printf(" Informe o valor recebido: ");
            scanf("%f", &valorRebido);
            troco = despesa - valorRecebido;
            printf("O troco eh de: R$ %.2f ", troco);
            }   else {
                        Printf("Quantos tickets ?");
                        Scanf("%d", &ctTick);
                            While(cont < ctTick) {
                            printf("Informe valor do ticket: ", cont + 1);
                            scanf("%f", &valorTic);
                            totValor += valorTic;
                            cont++;
                            troco = totValor - despesa;
                            printf("O valor a ser pago eh: %.2f", troco);
                        }
        
    }
return 0;
}