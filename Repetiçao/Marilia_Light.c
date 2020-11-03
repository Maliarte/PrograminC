/* As bandeiras tarifárias de energia elétrica são classificadas pela LIGHT por cores (verde, amarela e vermelha) e indicam o valor do quilowatt-hora (KWH) a pagar mensalmente, conforme abaixo:

Verde R$ 3,20
Amarela R$ 4,50
Vermelha Residencial R$ 6,00 Não Residencial R$ 5,00

Alem disso, nas bandeiras amarela e vermelha, eh cobrada uma taxa extra sobre o valor da conta a pagar, caso o consumo mensal seja superior a 100 quilowatts-hora. Ou seja, o valor total da conta a pagar é:

valor do KWH * consumo mensal (em KWH) + taxa extra (se for o caso)

Abaixo os percentuais para o calculo da taxa extra:

Residencial e Não Residencial Até 100 KWH: 0%  
Residencial Acima de 100 KWH: 50%
Não Residencial Acima de 100KWH 
Até 100 funcionários 3% 
Acima de 100 funcionários 2%

Faça um programa em C que leia as informações sobre o consumo de energia de usuários  da LIGHT  em n(lido) cidades e imprima, para cada um,  o valor total da conta a pagar. 

Deverão ser lidas as seguintes informações:
cor da bandeira: inteiro (1-verde, 2-amarela, 3-vermelha);
tipo do usuário: inteiro (1-residencial, 2-não residencial);

consumo  mensal em KWH: real.
Para cada cidade deve ser exibido:
     Montante total  recebido

Para todas as cidades:
      Montante total recebido

Observações: 
A entrada de dados dos usuários de uma cidade é finalizada quando  for digitada uma cor de bandeira inválida.
O número de funcionários só deve ser lido quando necessário!!!
Obrigatoriamente, o seu programa deve utilizar as funções abaixo, feitas por você:
determina_valorKWH: recebe o tipo do usuário e a cor da bandeira e retorna o valor do KWH;
Protótipo da função: float determina_valorKWH (int usuario, int bandeira);

calcula_TaxaExtra: recebe o valor da conta e o tipo do usuário e retorna o valor da taxa extra;
Protótipo da função: float calcula_TaxaExtra (float valorConta, int usuario);

calcula_conta: recebe a cor da bandeira, o tipo do usuário, o valor do KWH para aquela bandeira e o consumo mensal em KWH e retorna o valor total da conta a pagar;
Protótipo da função: float calcula_Conta (int bandeira, int usuario, float valorKWH, float consumo); 
*/

#include <stdio.h>

float determina_valorKWH(int usuario, int bandeira) {
    float kwHr;

    if (bandeira == 1) {
        kwHr = 3.2;
    } else   if (bandeira == 2) {
        kwHr = 4.50;
    } else {
        if (usuario == 1) {
            kwHr = 6.0;
        }
        else  kwHr = 5.0;
        
    }
    return kwHr;
}
float calcula_TaxaExtra(float consumo, int usuario){
    float txExtra;
    int nFuncionarios;
    if (consumo > 100){
        if (usuario == 1){
            txExtra = 0.5;
    }
    else
    {
        printf("\nQuantos funcionarios?\n");
        scanf("%d", &nFuncionarios);
    }
    if (nFuncionarios <= 100)
    {
        txExtra = 0.03;
    }
    else {
        txExtra = 0.02;
    }
}
else txExtra = 0;

return txExtra;
}


float calcula_Conta(float kwHr, float txExtra, float consumo){
    float conta = kwHr * consumo;
    float valorConta;

    valorConta = conta + (txExtra * conta);

    return valorConta;
}

int main() {
    int bandeira, usuario, cidades, countCity = 1;

    float consumo, kwHr, valorConta, taxa=0, somaConta=0, totSoma=0;

    printf("\nEntre com o numero de cidades: ");
    scanf("%d", &cidades);

    while (countCity <= cidades) {
        printf("\n|CIDADE %d|\n", countCity);
        printf("\nDigite o valor da bandeira: \n||1.Verde| |2.Amarelo| |3.vermelho||\n");
        scanf("%d", &bandeira);

        while (bandeira >= 1 && bandeira <= 3){
            
            printf("\nDigite o tipo de consumidor \n|1.residencial| |2.nao residencial|\n");
            scanf("%d", &usuario);
            printf("Informe o valor do consumo em KWH.\n");
            scanf("%f", &consumo);

            kwHr = determina_valorKWH(usuario, bandeira);

            if (bandeira == 2 ||bandeira == 3) {
                taxa = calcula_TaxaExtra(consumo, usuario);
            }
            else {
                taxa = 0;
            }

            valorConta = calcula_Conta(kwHr, consumo, taxa);

            printf("\n|Valor da conta: R$%.2f|\n", valorConta);

            somaConta = somaConta + valorConta;

            printf("\nEntre com a Bandeira ou informe valor invalido para encerrar.\n|1.Verde| |2.Amarelo| |3.vermelho|\n");
            scanf("%d", &bandeira);
        }

        printf("\n>>>Total contabilizado na cidade %d:R$ %.2f\n", countCity, somaConta);
        countCity++;
        totSoma = totSoma + somaConta;
        somaConta = 0; 
    }
    printf("\n>>>Total arrecadado por todas as cidades: R$ %.2f\n\n", totSoma);

    return 0;
}
