/*  
P2 - Marilia Silva - Turma B

O banco de investimentos BBCC oferece um tipo de aplicação especial para os estudantes com rendimento mensal, atualizado no 1º dia útil do mês.  O banco possui capacidade para 40 clientes (no máximo) e armazena as seguintes informações de cada cliente:
* código do cliente (inteiro);
* tempo em meses da aplicação (inteiro)
* valor na aplicação (real);

Complete a main de um programa que  é executado no 1º dia útil do mês. 
* Portanto, inicialmente deve calcular o novo valor das aplicações (usando a função da questão 2, mesmo que vc não a tenha desenvolvido). Após o cálculo do novo valor, o programa deve permitir que os clientes saibam seu saldo, realizem resgates ou aportes em suas aplicações.  

* Para isso, o cliente digita seu código e o tipo de operação: 1- para saber seu saldo, 2 - para resgatar um valor, 3 - para adicionar um valor em sua aplicação (aporte). 

 Para resgates ou aportes deve ser capturado, também, o valor da operação.  O seu programa deve realizar a operação desejada ou exibir a razão pela qual a operação não foi realizada, isto é, algum código errado ou o valor de uma retirada maior do que o valor aplicado.  No final do processamento, seu programa mostrar os dados (com a situação final das aplicações) de cada cliente.

Término da entrada de dados: código == 0.
Observações:
Obrigatoriamente, o seu programa deve utilizar mais uma função feita por você, além das já exigidas. Essa função deve realizar uma tarefa realmente importante para o funcionamento do programa como um todo.
Sinta-se à vontade para criar mais funções auxiliares, de acordo com a sua necessidade.

int main(void){
	int vCod[40]={24,34,12,1,16,94,18}; //vetorCodigo tamanho 40 sendo ocupadas sete posições

    int vTempo[40]={10,20,30,10,20,20,40}; vetorTempo tamanho 40 sendo ocupadas sete posições
    
	float vValAplic[40]={800,1000,1000,2000,2000,15000,20000};


Faça a função calculos que recebe um valor de aplicação e o tempo desta aplicação e o endereço de duas variáveis. 

Esta função calcula e preenche as variáveis com o valor do rendimento e do imposto de renda.

O valor do rendimento é calculado de acordo com a fórmula e as informações da tabela abaixo:
Rendimento = Alíquota * (Valor aplicado + Bônus)
Bônus  = tempo em meses * R$10,00 até um máximo (teto)  de R$200,00

* Valor do Rendimento

	Rendimento = Alíquota * (Valor aplicado + Bônus)
	Bônus  = tempo em meses * R$10,00 até um máximo (teto)  de R$200,00


* Valor Aplicado 

Até 1.000,00
* Alíquota 5% sobre o valor originalmente aplicado



De 1.000,00 até 3.000,00
* Alíquota 8% sobre o valor originalmente aplicado



Acima de  3.000,00
* Alíquota 15% sobre o valor originalmente aplicado


*** Imposto de renda 

* Valor Aplicado: ATÉ R$10.000,00

|| Tempo de Aplicação até 12 meses        || Aliquota do IR sobre o rendimento é de 27%.

|| Tempo de Aplicação 12 meses à 24 meses || Aliquota do IR sobre o rendimento é de 20%.

|| Tempo de Aplicação acima de 24 meses   || Aliquota do IR sobre o rendimento é de 15%.


* Valor Aplicado: ACIMA R$10.000,00

|| Tempo de Aplicação até 30 meses       || Aliquota do IR sobre o rendimento é de 27%.

|| Tempo de Aplicação acima de 30 meses  || Aliquota do IR sobre o rendimento é de 15%.



//
/*
Faça uma função ajustaAplicações que recebe um vetor de reais com os valores aplicados, um vetor de inteiros com o tempo de aplicação e um inteiro representando a quantidade de posições ocupadas nestes vetores. Esta função deve calcular os rendimentos e atualizar os valores aplicados e o tempo de aplicação para cada cliente.
obs:  a) o novo valor da aplicação é calculado da seguinte forma:    
novo valor =  valor antigo + rendimento – imposto de renda do mês
tempo de aplicação é incrementado de uma unidade
b) o rendimento e o imposto de renda são calculados de acordo com as regras da questão 1.  Você deve chamar obrigatoriamente a função da questão 1, mesmo que não a tenha desenvolvido.


void ajustaAplicações(vValoresAplicados[], vInteirosTempoAplicaçao[], int n)
**calcular rendimentos
novo valor =  valor antigo + rendimento – imposto de renda do mês
**Atualizar valores Aplicados
**Incrementar tempo


*/


#include <stdio.h>
#include <stdlib.h>

//prototipos

//Q1//
void calculos(int tempo, float valorAplic, float *rend, float *ir);

//recebe: vetor de valores aplicaçao e o tempo desta aplicação 
//e endereço de duas variaveis.
//esta função preenche as variaveis com o valor do rendimento e do ir


//Q2//
void ajustaAplicacoes(float valAp[], int vTemp[], int ocup);

//recebe: vetor de valores aplicados, vetor com o tempo de aplicação 
//e um inteiro representando a qtd de posicões ocupadas nestes vetores.
//esta função calcula os rendimentos e atualiza os valores aplicados
//e o tempo de aplicação para cada cliente.


//Q3//
int busca(int arrayCode[], int code, int preenche);



int main(void)

//calcular o novo valor das aplicações (usando a função da questão 2, mesmo que vc não a tenha desenvolvido)

{
    int vCod[40] = {24, 34, 12, 1, 16, 94, 18};// vetor codigo com lista de valores
    int vTempo[40] = {10, 20, 30, 10, 20, 20, 40};
    float vValAplic[40] = {800, 1000, 1000, 2000, 2000, 15000, 20000}, saque, aporte;
    // variaveis aux.
    int i, code, preenche = 7, index, op; //preenche as posicoes ocupadas nos v de sete pos

    ajustaAplicacoes(vValAplic, vTempo, preenche);

    printf("\nDigite sua Identificação bancária\n\n||24||\n||34||\n||12||\n||1||\n||16||\n||94||\n||18||\n\n");
    scanf("%i", &code);

    while (code != 0)
    {
        index = busca(vCod, code, preenche);
        if (index != -1)
        {
            printf("Digite o numero da operação desejada\n1 - SALDO\n2 - SAQUE\n3 - APORTE:\n\n ");
            scanf("%i", &op);
            if (op == 1)
            {
                printf("\nSeu saldo é:\n||R$ %.2f||", vValAplic[index]);
            }
            else
            {
                if (op == 2)
                {
                    printf("\nInforme valor Saque\n(R$ %.2f disponíveis) ", vValAplic[index]);
                    scanf("%f", &saque);

                    if (aporte < vValAplic[index])
                    {
                        vValAplic[index] = vValAplic[index] - saque;
                        printf("\nOperação efetuada.\n||SALDO: R$ %.2f||", vValAplic[index]);
                    }
                    else
                    {
                        printf("\nOperação Não Realizada.\nSaldo Insuficiente.");
                    }
                }
                else
                {
                    printf("\nInforme valor para Aporte: R$");
                    scanf("%f", &aporte);
                    if (aporte > 0)
                    { 
                        
                        vValAplic[index] = vValAplic[index] + aporte;
                        printf("\nOperação Efetuada.\nSaldo Atual: R$ %.2f", vValAplic[index]);
                    }
                    else
                    {
                        printf("\nOperação Não Realiza\nDigitação Incorreta.");
                    }
                }
            } 
        } else {
              printf("\nCódigo Inválido");
            }
        printf("\nDigite seu código ou 0 para terminar: ");
        scanf("%i", &code);
    }

     for (i = 0; i < 7; i++)
     {
         printf("\nCodigo: %i\nTempo: %i\nValor aplicado: %.2f", vCod[i], vTempo[i], vValAplic[i]);
     }
    return 0;
}


//calcula rendimento e imposto de renda
void calculos(int tempo, float valorAplic, float *rendimento, float *ir)
{
    float aliquota, bonus;

    bonus = tempo * 10.00;

    if (bonus > 200)
    {
        bonus = 200;
    }
    if (valorAplic <= 1000)
    {
        aliquota = 0.05; //5%
    }
    else
    {
        if (valorAplic <= 3000)
        {
            aliquota = 0.08;//8%
        }
        else
        {
            aliquota = 0.15; //15%
        }
    }

    //atualiza valor da variavel
    (*rendimento) = aliquota * (valorAplic + bonus);  

    //estrutura de seleção: o tempo está em função do valor aplicado.

    if (valorAplic < 10000)
    {
        if (tempo <= 24)
        {
            if (tempo <= 12)
            {
                (*ir) = (*rendimento) * 0.27;
            }
            else
            {
                (*ir) = (*rendimento) * 0.20;
            }
        }
        else
        {
            (*ir) = (*rendimento) * 0.15;
        }
    }
    else
    {
        if (tempo <= 30)
        {
            (*ir) = (*rendimento) * 0.27;
        }
        else
        {
            (*ir) = (*rendimento) * 0.15;
        }
    }
    return;
}

void ajustaAplicacoes(float valAp[], int vTemp[], int ocup)
{
    int i; //controler (percorre vetores)
    float rend, ir, novoVal;

    //enquanto o valor do controler for inferior as pos ocupadas
    for (i = 0; i < ocup; i++)
    {

        calculos(vTemp[i], valAp[i], &rend, &ir);
        vTemp[i]++; //atualiza tempo
        valAp[i] = valAp[i] + (rend - ir); //atualiza valor aplicado

        printf("\n\n||Renda: %.2f|| ", rend);
        printf("\n\n||Imposto sobre Renda: %.2f|| ", ir);
        printf("\n\n||Valor Aplicado: %.2f|| ", valAp[i]);
        printf("\n||Novo valor: %.2f||\n\n ", novoVal);
    }

    return;
}
int busca(int arrayCode[], int code, int preenche)
{
    int i;

    for (i = 0; i < preenche; i++)
    {
        if (arrayCode[i] == code)
            return i;
    }

    return -1;
}
