/*
Questão 05:

Desenvolver uma função recursiva que, dado um vetor V com quant números inteiros, 
determine se seus elementos estão dispostos de maneira a representar uma progressão aritmética.

        definição: 
        Uma progressão aritmetica é uma sequência numérica em que cada termo, 
        a partir do segundo, é igual à soma do termo anterior com uma constante r.

Exemplo:
	
        DEFINE quant 5

		v[quant] = {1, 3, 5, 7, 9}
		r = 2
		
		pg: 2  6  18  54  162

*/
/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII
	
	Questão 05:
	Desenvolver uma função recursiva que, dado um vetor V com quant números inteiros, determine se seus elementos estão dispostos de maneira a representar uma progressão aritmética.		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int PA (int vetor[], int quant);
int PA_aux (int vetor[], int quant, int razao, int pos);

//main
void main ()
{
	//declaração de variáveis
	//int vetor[6] = {1,4,7,10,13,16};
	int vetor[6] = {1,4,7,11,13,16};
	int resp;
	
	//chamando a função
	resp = PA (vetor, 6);
	
	//exibindo o resultado
	if (resp == TRUE)
	{
		printf ("\nE' uma PA");		
	}
	else
	{
		printf ("\nNao e' uma PA");
	}
}

//implementação das funções
int PA (int vetor[], int quant)
{
	return PA_aux (vetor, quant, vetor[1] - vetor[0], 1);
}

int PA_aux (int vetor[], int quant, int razao, int pos)
{
	//verificando se todo o vetor já foi percorrido
	if (pos == quant-1)		//caso base: o vetor foi totalmente percorrido e não encontramos elementos que descaracterizassem a PA
	{
		return TRUE;
	}
	else
	{
		if (vetor[pos+1] - vetor[pos] != razao)	//caso base: elementos que não caracterizam a PA
		{
			return FALSE;
		}
		else
		{
			return PA_aux (vetor, quant, razao, pos+1);
		}
	}
}