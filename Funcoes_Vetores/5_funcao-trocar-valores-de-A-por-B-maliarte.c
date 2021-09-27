/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 02/09/2021
	
	Revisão: funções
	
	Exemplo 4: desenvolver uma função que troque os valores de 'A' e 'B'
	
	[NESTA VERSÃO, O ERRO FOI CORRIGIDO, ADOTANDO O USO DE PONTEIROS]
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void trocar (int *A, int *B);

//main
void main ()
{
	//declaração de variáveis
	int valor1, valor2;
	
	//leitura dos valores 
	printf ("Entre com um valor: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro valor: ");
	scanf ("%d", &valor2);
	
	//exibindo os valores antes da chamada à função
	printf ("Antes: valor1 = %d e valor2 = %d\n", valor1, valor2);
	
	//chamada à função com o endereço das variaveis
	trocar (&valor1, &valor2);
	
	//exibindo os valores após a chamada à função
	printf ("Depois: valor1 = %d e valor2 = %d\n", valor1, valor2);	
}

//implementação das funções passando como argumentos ponteiros A e B são ponteiros para (*int). 
// Ou seja, armazenam endereços de memória nos quais encontram-se números inteiros.
void trocar (int* A, int* B)

{
	//declaração de variáveis
	int aux;
	
	aux = *A;       //A:  endereço de memória no qual está armazenado um nº inteiro
	                //*A: conteúdo de A; ou seja, o inteiro que está armazenado no endereço A
	*A = *B;
	*B = aux;
}