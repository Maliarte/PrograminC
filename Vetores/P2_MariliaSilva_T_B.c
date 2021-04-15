/*  

///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Q1///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
// 
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





#include <stdio.h>

//prototipos q1//

void BIS(int timeAplicado);
void calcula_aliquotaVA(float valorAplicado);
void calcula_aliquotaIR(float valorAplicado, int timeAplicado);
void calcula_IR(float valorAplicado, int timeAplicado);
void calculos (float valorAplicado, int timeAplicado,  int *a, int b) ;

int main(void) {

float aliquotaVA, valorAplicado;
int timeAplicado, vA[], vB[];

    printf("Informe o valor Aplicado: R$ ");
    scanf("%f", &valorAplicado);

    aliquotaVA = calcula_aliquotaVA(valorAplicado);

    printf("Informe o tempo da Aplicação: R$ ");
    scanf("%f", &timeAplicado);

    calculos(valorAplicado,timeAplicado, &a, &b);

    return 0;
}
/////// funções auxiliartes Q1 //////
void BIS(int timeAplicado)
{ float bonus;

    bonus = timeAplicado * 10;

    if (bonus > 200) {
        bonus = 200;
    }
    return bonus;
}

void calcula_aliquotaVA(float valorAplicado)
{
 if (valorAplicado <=1000){
        aliquota = aliquota * 0.05;
    }   
        else if (valorAplicado > 1000 && valorAplicado <=3000){
            aliquota = aliquota * 0.08;
        }   
            else {
                aliquota = aliquota * 0.15;
            }

return aliquota;
}

void calcula_aliquotaIR(float valorAplicado, int timeAplicado)
{
float aliquotaIR;
if (valorAplicado < 10.000 && timeAplicado<=12)
{
     aliquotaIR = aliquotaIR *0.12;  

        else if (timeAplicado >=13 && <=24) 
        {
            aliquotaIR = aliquotaIR * 0.2;
        } 
        else {
            aliquotaIR = aliquotaIR * 0.15;
        }
    
}
else if (valorAplicado > 10.000 && timeAplicado <=30)
{
    aliquotaIR = aliquotaIR * 0.27;
}   else {
            aliquotaIR = aliquotaIr * 0.15;
    }

return aliquotaIR;
}


void calcula_IR(float valorAplicado, int timeAplicado) {

    calcula_aliquotaIR(valorAplicado, timeAplicado);

} else if (valorAplicado > 10.000) {

}

    return IR;
}

//calcula e preenche as variáveis com o valor do rendimento e do imposto de renda.
}
void calculos (float valorAplicado, int timeAplicado,  int *a, int b) 
{
   float rendimentoApli, IR;

    rendimentoApli = calcula_aliquota(valorAplicado)*valorAplicado+BIS(timeAplicado); 
    IR = calcula_IR(valorAplicado, timeAplicado);

    a = 
    
}
///////  fim funções auxiliartes Q1 //////


*/

///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// fim Q1//////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Q2///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
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


void preencheArray(int v[], int valor){
	
	for(int i = 0; i < valor; i++){
		v[i] = 0;
	}
}




*/



///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// FIM Q2//////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Q3///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/*

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

return 0;
}

* Para os valores aplicados:

Cod tempo valorAplicado
24   10      800
34   20      1000
12   30      1000
1    10      2000
16   20      2000
94   20      15000
18   40      200000

* Após a atualização do início do mês:

Cod tempo valorAplicado
24   11      832.85
34   21      1076.80
12   31      1081.6
1    11      2122.64
16   21      2140.8
94   21      1666440
18   41      22575.50


//////////////////////////INFOS/////////////////////////////////

//calcular o novo valor das aplicações
ajustAplica(vAplicados, vTime, n) Considere n quantidade Pos Ocupadas


ajustAplica()
float Aplicacao, Rendimento;
int tempo++

return novoValue;





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

////////PROTÓTIPOS//////

int menu();
void mostraSaldo(int *conta, float *saldo);
void operaConta(int *conta, float *saldo, int op);
int validaConta(int array[], int ref);

/////////////////q2///////////////

void ajustaAplica(float vValoresAp, int tempo, int n);


///////////////////q1//////////////////

void calculos(float valor, int tempo, float *rendimento, float *bis);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// inicio MAIN //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int conta;
	float saldo;
	int operacao;

    //
    int opcao, num, aceito;
    int i = 0;
    int vConta[SIZE];
    float vSaldo[SIZE]

    ///////////vetores//////////
    int vConta[SIZE];

    //

	int vCod[40]={24,34,12,1,16,94,18};
    int vTempo[40]={10,20,30,10,20,20,40};
	float vValAplic[40]={800,1000,1000,2000,2000,15000,20000};

    ///////// condiçao de inicio da main /////

ajustaAplica(float vValoresAp(calculos()), int tempo, int n)

	
	printf("Informe o código de sua conta: ");
	scanf("%i", &conta);
    
	operacao = menu();

    
/////////////////

    printf("\nINFORME A OPERAÇÃO DESEJADA:\n");
	printf("1 - SALDO\n");
	printf("2 - SAQUE\n");  //para para fazer um depósito\n"
	printf("3 - APORTE\n"); //para fazer um saque\n"
	printf("4 - FINALIZAR\n");



////////////////
	while(operacao != 0) {
		switch(operacao){
			case 1:
			mostraSaldo(&conta, &saldo);
			break;
			
			case 2:
			operaConta(&conta, &saldo, 2); // 2 -> deposito
			break;
			
			case 3:
			operaConta(&conta, &saldo, 3); // 3 -> saque
			break;
		}
		operacao = menu();
	}
	
	return 0;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// FIM MAIN //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// FUNÇÕES AUXILIARES DA MAIN



/////////////////////////// MENU ///////////////////////////////

int menu(){
	int opcao; //variavel local
	
	printf("\nINFORME A OPERAÇÃO DESEJADA:\n");
	printf("1 - SALDO\n");
	printf("2 - SAQUE\n");  //para para fazer um depósito\n"
	printf("3 - APORTE\n"); //para fazer um saque\n"
	printf("4 - FINALIZAR\n");
	
	scanf("%d", &opcao);
	while(opcao < 1 || opcao > 4){
		printf("\nERRO!\nConfira os dados informados.\n");
		printf("\nINFORME A OPERAÇÃO DESEJADA:\n");
		printf("1 - VER O SALDO\n");
		printf("2 - REALIZAR SAQUE\n");
		printf("3 - FAZER APORTE\n");
		printf("4 - ENCERRAR\n");
		
		scanf("%d", &opcao);		
	}
	
	return opcao;
}

// FIM FUNÇÃO MENU 



//////////////////////////// FUNÇÃO EXIBE SALDO //////////////////////////////

void mostraSaldo(int *conta, float *saldo){
	
	printf("SALDO DISPONÍVEL: (%d): R$ %.2f\n\n", *conta, *saldo);
}


void operaConta(int *conta, float *saldo, int op){
	float valor;
	
	if(op == 2){
		printf("Informe o valor do depósito ... R$ ");
		scanf("%f", &valor);
		*saldo+=valor;
	}else{ // op == 3
		printf("Informe o valor do saque ... R$ ");
		scanf("%f", &valor);
		*saldo-=valor;	
	}
	mostraSaldo(&(*conta), &(*saldo));
}

// FIM EXIBE SALDO 


///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// FIM Q3//////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
