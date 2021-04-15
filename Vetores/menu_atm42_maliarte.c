/*
Escreva um programa que imprime na tela um menu simulando as seguintes operações em um caixa 
 eletrônico de um banco: 
 "Digite a opcao da operacao que deseja fazer:
 * 				1 para ver o saldo atual da conta,
 * 				2 para fazer um deposito;
 * 				3 para fazer um saque.
 * 				4  para finalizar
 
 * Inicialmente, seu programa deve solicitar ao usuário como entrada, via teclado, sua conta e 
 * o saldo inicial da conta.
 
 * Após o saldo fornecido, o programa deve imprimir o menu acima e executar a opção selecionada 
 até a opção 4 ser digitada.
 
 * Após o término da execução de cada  operação de depósito e saque, o saldo atual deve ser impresso.
  
 * Obrigatoriamente, seu programa deve definir uma função para o menu.
 
 * função: resp-menu
 *  A função  mostra as opções do menu, captura e valida a opção escolhida, 
 * retornando-a
 
 * MODIFIQUE seu programa para processar vários clientes. Término: conta == 0
 */
 
#include <stdio.h>

int menu();
void mostraSaldo(int *conta, float *saldo);
void operaConta(int *conta, float *saldo, int op);


int main(void){
	int conta;
	float saldo;
	int operacao;
	
	printf("Informe o número de sua conta: ");
	scanf("%i", &conta);
	printf("Informe o valor do saldo inicial da conta: ");
	scanf("%f", &saldo);
	
	operacao = menu();
	while(operacao != 4){
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


int menu(){
	int opcao;
	
	printf("\nDigite a opcao da operacao que deseja fazer:\n");
	printf("1 - para ver o saldo atual da conta\n");
	printf("2 - para para fazer um depósito\n");
	printf("3 - para fazer um saque\n");
	printf("4 - para finalizar\n");
	
	scanf("%d", &opcao);
	while(opcao < 1 || opcao > 4){
		printf("\nERRO! A opção digitada é inválida.\n\n");
		printf("Digite a opcao da operacao que deseja fazer:\n");
		printf("1 - para ver o saldo atual da conta\n");
		printf("2 - para para fazer um depósito\n");
		printf("3 - para fazer um saque\n");
		printf("4 - para finalizar\n");
		
		scanf("%d", &opcao);		
	}
	
	return opcao;
}


void mostraSaldo(int *conta, float *saldo){
	
	printf("Saldo atual da conta (%d): R$ %.2f\n\n", *conta, *saldo);
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
