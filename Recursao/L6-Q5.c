/********************************************************************************************

	FPR - Manhã
	Professor Leonardo Vianna
	2021/2
	Data: 03/11/2021
	
	Lista de Exercícios VI
	
	Questão 05:
	Dada uma string s, desenvolver uma função recursiva que determine se s é ou não um 
	palíndromo.
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int palindromo (char s[], int pos1, int pos2);

//função main
void main ()
{
	//declaração de variáveis
	char string[30];
	int resp;
	
	//inicializando a string
	strcpy (string, "ABCDXBA");
	
	//chamando a função
	resp = palindromo (string, 0, strlen(string)-1);
		//na chamada inicial, pos1 = 0, pos2 = strlen(string)-1
	
	//testando o retorno
	if (resp == TRUE)
	{
		printf ("A string %s e' um palindromo", string);
	}
	else
	{
		printf ("A string %s nao e' um palindromo", string);
	}
}
	
//implementação das funções
int palindromo (char s[], int pos1, int pos2)
{	
	if (pos1 < pos2)		//caso geral
	{	
		//verificando se dois caracteres distintos foram encontrados
		if (s[pos1] != s[pos2])
		{
	        //não é um palíndromo
	        return FALSE;
	    }
	    else
	    {	
	    	return palindromo (s, pos1+1, pos2-1);
		}
	}
	else					//caso base (pos1 >= pos2)
	{
		return TRUE;
	}
}