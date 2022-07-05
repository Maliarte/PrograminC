/********************************************************************************************

	FPR - Manhã
	Professor Leonardo Vianna
	2021/2
	Data: 03/11/2021
	
	Lista de Exercícios VI
	
	Questão 05:
	Dada uma string s, desenvolver uma função recursiva que determine se s é ou não um palíndromo.
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int palindromo (char s[]);
                                                                        //assumem condição de contadores("i")("j")
                                                                        //posicao inicial e posicao final
int palindromoAux (char s[], int pos1, int pos2);

//função main
void main ()
{
	//declaração de variáveis
	char string[30];
	int resp;
	
	//inicializando a string
	strcpy (string, "ABCDCBA");
	
	//chamando a função
	resp = palindromo (string);
			
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
int palindromo (char s[])
{
	return palindromoAux (s, 0, strlen(s)-1);
}

int palindromoAux (char s[], int pos1, int pos2)
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
	    	return palindromoAux (s, pos1+1, pos2-1);
		}
	}
	else					//caso base (pos1 >= pos2)
	{
		return TRUE;
	}
}