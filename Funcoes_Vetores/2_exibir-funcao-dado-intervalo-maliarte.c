/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
    
	Data: 01/09/2021
	
	Revisão: funções
	
	Exemplo 2: desenvolver uma função que exiba os números de 'num1' a 'num2'
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void exibir (int num1, int num2);

//main
void main ()
{
	//declaração de variáveis
	int valor1, valor2;
	
	//leitura dos valores que representarão o intervalo a ser exibido
	printf ("Entre com um valor: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro valor: ");
	scanf ("%d", &valor2);
	
	//chamando a função
	exibir (valor1, valor2);
	
	//exibir (554,6254);
}

//implementação das funções
void exibir (int num1, int num2)
{
	//declaração de variáveis
	int i;
	
	for (i=num1;i<=num2;i++)
	{
		printf ("%d ", i);
	}
    
}