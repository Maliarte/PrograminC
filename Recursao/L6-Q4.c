
/********************************************************************************************

	FPR - Manhã
	Professor Leonardo Vianna
	2021/2
	Data: 03/11/2021
	
	Lista de Exercícios VI
	
	Questão 04: Pede-se a implementação de uma função recursiva que exiba os n primeiros 
	termos de uma PG (Progressão Geométrica), onde a1 é o seu primeiro termo e q a razão.

	Observação: uma PG consiste em uma sequência de valores, iniciadas pelo valor a1. 
	Os demais elementos são definidos como o anterior multiplicado pela razão.			
	
	Exemplo:
	
		n = 5
		a1 = 2
		q = 3
		
		pg: 2  6  18  54  162
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void PG (float a1, float q, int n);

//função main
void main ()
{
	PG (1, 2, 10);
}
	
//implementação das funções
void PG (float a1, float q, int n)
{
	if (n > 0)			//caso geral
	{
		printf ("%.1f  ", a1);
		
		PG (a1*q, q, n-1);
	}
	//caso base implícito: n <= 0
}