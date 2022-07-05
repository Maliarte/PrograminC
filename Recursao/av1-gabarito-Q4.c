/**************************************************** gabarito *************************************************************

	Desenvolver uma função recursiva, em C, que, dado um número inteiro N, exiba as sequências de 1 a N 
	(crescente) e de N a 1 (decrescente), intercaladas, como no exemplo abaixo. Além disso, deve ser 
	retornada a soma de todos os elementos apresentados.

	Exemplo:	N=5
				1  5  2  4  3  3  4  2  5  1
				                        i  j

*****************************************************************************************************************/

//importação de bibliotecas
#include <stdio.h>

//protótipo da função
int funcao_aux (int i, int j);
int funcao (int n);

//main
void main ()
{
	//declaração de variáveis
	int soma;
	
	//chamando a função
	soma = funcao (8);
	
	//exibindo o valor da soma
	printf ("\n\nSoma: %d", soma);
	
}

int funcao (int n)
{
	return funcao_aux (1, n);
}

int funcao_aux (int i, int j)
{
	//caso geral
	if (j >= 1)
	{
		printf ("%d %d ", i, j);
		return i + j + funcao_aux (i+1,j-1);
	}
	else
	{
		//caso base (j < 1)
		return 0;
	}
}