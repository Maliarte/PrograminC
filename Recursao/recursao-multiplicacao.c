/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 18/05/2022
	
	Recursividade
	
	Multiplicação: calcular a x b a partir de sucessivas somas (ou seja, somar o valor de 'a' 'b' bezes).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int multiplicacao (int a, int b);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int x = 2, y = 100;
	
	printf ("%d x %d = %d", x, y, multiplicacao (x,y));	
}

//implementações das funções
int multiplicacao (int a, int b)
{
	//caso base
	if (b == 0)
	{
		return 0;
	}
	else
	{
		//caso geral
		return a + multiplicacao (a, b-1);
	}
}