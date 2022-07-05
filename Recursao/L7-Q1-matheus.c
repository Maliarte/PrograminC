/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII
	
	Questão 01:
	Desenvolver uma função recursiva que determine o número de caracteres comuns entre 
	duas strings s1 e s2.
	
	Observação: não se preocupar se o mesmo caracter aparecer mais de uma vez na string s1.
	
	Exemplo:
	
		s1:	CASA
		s2:	CADERNO	
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções

//função main
void main ()
{
	//declaração de variáveis
	char str1[30], str2[30];
	int resp;
	
	//inicializando as strings
	//strcpy (str1, "CASA");
	//strcpy (str2, "CADERNO");
	
	//strcpy (str1, "CADERNO");
	//strcpy (str2, "CASA");
	
	strcpy (str1, "CAIPORA");
	strcpy (str2, "CAIPIRA");
	
	//chamando a função
	resp = caracteresComuns (str1, str2, 0, 0);
	
	//exibindo o resultado
	printf ("\nForam encontrados %d caracteres comuns entre as strings %s e %s.", resp, str1, str2);
}
	
//implementação das funções
int caracteresComuns (char s1[], char s2[], int pos1, int pos2)
{
	if (pos1 == strlen(s1))			//caso base - cheguei ao final da string s1 (ou seja, no \0)
	{
		return 0;   //cont = 0
	}
	else
	{
		if (pos2 == strlen(s2))		//caso geral 1: cheguei ao final de s2; portanto, deve-se seguir para o próximo caracter de s1
		{
			return caracteresComuns (s1, s2, pos1+1, 0);
		}
		else
		{
			//verificando se os caracteres são iguais
			if (s1[pos1] == s2[pos2])
			{
                //'return 1' é o contador que irá somar aos 'pendentes' caracteres comuns será somado.
				return 1 + caracteresComuns (s1, s2, pos1, pos2+1);
			}
			else
			{
				return caracteresComuns (s1, s2, pos1, pos2+1);
			}
		}
	}
}

/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII
	
	Questão 01:
	Desenvolver uma função recursiva que determine o número de caracteres comuns entre 
	duas strings s1 e s2.
	
	Observação: não se preocupar se o mesmo caracter aparecer mais de uma vez na string s1.
	
	Exemplo:
	
		s1:	CASA
		s2:	CADERNO	
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções

//função main
void main ()
{
	//declaração de variáveis
	char str1[30], str2[30];
	int resp;
	
	//inicializando as strings
	//strcpy (str1, "CASA");
	//strcpy (str2, "CADERNO");
	
	//strcpy (str1, "CADERNO");
	//strcpy (str2, "CASA");
	
	strcpy (str1, "CAIPORA");
	strcpy (str2, "CAIPIRA");
	
	//chamando a função
	resp = caracteresComuns (str1, str2, 0, 0);
	
	//exibindo o resultado
	printf ("\nForam encontrados %d caracteres comuns entre as strings %s e %s.", resp, str1, str2);
}
	
//implementação das funções
int caracteresComuns (char s1[], char s2[], int pos1, int pos2)
{
	if (pos1 == strlen(s1)) //if (s1[pos1] == '\0') | ou if (!s1[pos1])
	{
		return 0;   //cont = 0
	}
     // Se entrou aqui, é porque há posições válidas em s1.
	else
	{
		if (pos2 == strlen(s2))//if (s2[pos2] == '\0') | ou if (!s2[pos2])
		{
			return caracteresComuns (s1, s2, pos1+1, 0);
		}
        // Se entrou aqui, é porque há posições válidas em s2.
		else 
		{
			//verificando se os caracteres são iguais
			if (s1[pos1] == s2[pos2])
			{
                //'return 1' é o contador que irá somar aos 'pendentes' caracteres comuns será somado.
				return 1 + caracteresComuns (s1, s2, pos1, pos2+1); //Incrementando 1 e progredindo em s2.
			}
			else
			{
				return caracteresComuns (s1, s2, pos1, pos2+1); //progredindo em s2.
			}
		}
	}
}