/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 01/09/2021
	
	Revisão: funções
	
	Exemplo 3: desenvolver uma função que some os números de 'num1' a 'num2'
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
int somar (int num1, int num2);

//main
void main ()
{
	//declaração de variáveis
	int valor1, valor2, resultado;
	
	//leitura dos valores que representarão o intervalo a ser exibido
	printf ("Entre com um valor: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro valor: ");
	scanf ("%d", &valor2);
	
	//chamando a função e atribuindo o retorna à uma nova variavel
	resultado = somar (valor1, valor2);
	
	//exibindo o resultado
	printf ("\nA soma do intervalo entre %d e %d = %d", valor1, valor2, resultado);
	
}

//implementação das funções
int somar (int num1, int num2)
{
	//declaração de variáveis
	int i, soma = 0;
	
	//variando os elementos do intervalo e acumulando-os na variável 'soma'
	for (i=num1;i<=num2;i++)
	{
		soma = soma + i;   // soma += i;
	}
	
	//retornando o resultado
	return soma;
}