/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 18/05/2022
	
	Recursividade
	
	Fatorial: implementações iterativa e recursiva
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int fatorialI (int n);
int fatorialR (int n);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int numero = 10;
	
	printf ("versao iterativa: %d! = %d\n\n", numero, fatorialI(numero));
	
	system ("pause");
	
	printf ("versao recursiva: %d! = %d\n\n", numero, fatorialR(numero));
}

//implementações das funções
int fatorialI (int n)
{
	int i, fat = 1;

	for (i=2;i<=n;i++)
	{
		fat *= i;
	}
		
	return fat;
}

int fatorialR (int n)
{
	if (n == 0)		//caso base
	{
		return 1;
	}
	else						//caso geral
	{
		return n * fatorialR (n-1);
	}
}