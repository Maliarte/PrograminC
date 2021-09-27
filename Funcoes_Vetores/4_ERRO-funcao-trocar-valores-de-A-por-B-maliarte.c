/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 02/09/2021
	
	Revisão: funções
	
	Exemplo 4: desenvolver uma função que troque os valores de 'A' e 'B'
	
	[ERRO: NÃO FORAM UTILIZADOS PARÂMETROS POR REFERÊNCIA (PONTEIROS)]
    Logo não houve alteração após a chamada da função!
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void trocar (int A, int B);

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
	
	//chamada à função
	trocar (valor1, valor2);
	
	//exibindo os valores após a chamada à função
	printf ("Depois: valor1 = %d e valor2 = %d\n", valor1, valor2);	
}

//implementação das funções
void trocar (int A, int B)
{
	//declaraçaõ de variáveis
	int aux;
	
	aux = A;
	A = B;
	B = aux;
}