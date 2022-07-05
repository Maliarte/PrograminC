/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 18/05/2022
	
	Recursividade
	
	Potencia: implementações iterativa e recursiva
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int potenciaI (int base, int expoente);
int potenciaR (int base, int expoente);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int x = 2, y = 15;
	
	printf ("versao iterativa: %d^%d = %d\n\n", x, y, potenciaI (x,y));
	
	system ("pause");
	
	printf ("versao recursiva: %d^%d = %d\n\n", x, y, potenciaR (x,y));
}

//implementações das funções
int potenciaI (int base, int expoente)
{
	//declaração de variáveis
	int i, pot = 1;
	
	//gerando iterativamente o valor de 'base' elevado a 'expoente'
	for (i=1;i<=expoente;i++)
	{
		pot *= base;
	}
	
	//retornando o resultado
	return pot;
}

int potenciaR (int base, int expoente)
{
	//caso base
	if (expoente == 0)
	{
		return 1;
	}
	else
	{
		//caso geral
		return base * potenciaR (base, expoente-1);
	}
}