/*
	FPR - Fundamentos de Programação

	Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
    
	Data: 01/09/2021
	
	Revisão: funções
	
	Exemplo 2: desenvolver uma função que exiba os números de 'num1' a 'num2'
	
	IMPLEMENTAÇÃO SEM USO DE PARÂMETROS, LIMITANDO O USO DA FUNÇÃO.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void exibir ();

//main
void main ()
{
	//chamando a função
	exibir ();
}

//implementação das funções
void exibir ()
{
	//declaração de variáveis
	int i, num1, num2;

	/* NO MOMENTO QUE OPTA-SE POR FAZER A LEITURA (VIA TECLADO) DOS VALORES,
	O USO DA FUNÇÃO É LIMITADO. OU SEJA, SÓ CONSEGUE TRABALHAR SOBRE VALORES 
    LIDOS A PARTIR DO TECLADO. */

    //leitura dos valores que representarão o intervalo a ser exibido
	printf ("Entre com um valor: ");
	scanf ("%d", &num1);
	
	printf ("Entre com outro valor: ");
	scanf ("%d", &num2);
	
		
	for (i=num1;i<=num2;i++)
	{
		printf ("%d ", i);
	}
}