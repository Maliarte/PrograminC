/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	
	Data: 13/10/2021
	
	Lista de exercícios V: STRINGS
	
	Questão 01:
	Suponha que não existissem as funções strlen, strcpy, strcat e strcmp. Pede-se, então, a implementação 
	de funções que tenham o mesmo objetivo daquelas.
	
	Observação: continuação da implementação iniciada na aula de 07/10.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração dos protótipos
int  quantidadeCaracteres (char str[]);			//strlen
void copiarString (char s1[], char s2[]);		//strcpy
void concatenarString (char s1[], char s2[]);	//strcat
int  compararString (char s1[], char s2[]);		//strcmp

//main
void main ()
{
	//declaração de variáveis
	char str1[30], str2[30], str3[30], str4[30];
	
	//testando as funções copiarString e quantidadeCaracteres
	copiarString (str1, "TESTANDO");
	printf ("\nstr1: %s (%d caracteres)\n", str1, quantidadeCaracteres(str1));
	
	//testando a função de concatenação
	copiarString (str2, "ALGORITMOS");
	concatenarString (str1, str2);
	printf ("\nstr1: %s (%d caracteres)\n", str1, quantidadeCaracteres(str1));
	printf ("\nstr2: %s (%d caracteres)\n", str2, quantidadeCaracteres(str2));
	
	//testando a função de comparação
	copiarString (str3, str2);
	copiarString (str4, "ALGUEM");
	printf ("\nComparando a string %s com %s: %d\n", str1, str2, compararString (str1, str2));
	printf ("\nComparando a string %s com %s: %d\n", str3, str1, compararString (str3, str1));
	printf ("\nComparando a string %s com %s: %d\n", str3, str2, compararString (str3, str2));	
	printf ("\nComparando a string %s com %s: %d\n", str2, str4, compararString (str2, str4));	
}

//implementação das funções
int quantidadeCaracteres (char str[])
{
	//declaração de variáveis
	int i;
	
	for (i=0;str[i]!='\0';i++);

	//retornando o resultado
	return i; 
}

void copiarString (char s1[], char s2[])		//strcpy
{
	//declaração de variáveis
	int i;
	
	//percorrendo todas as posições da string s2
	for (i=0;s2[i]!='\0';i++)
	{
		s1[i] = s2[i];
	}
	
	//não esquecer de armazenar o \0 na última posição de s1
	s1[i] = '\0';
}

void concatenarString (char s1[], char s2[]) //strcat
{
	//declaração de variáveis
	int j;
	int quant;
	
	//armazenando a quantidade de caracteres de s1
	quant=quantidadeCaracteres(s1);
	
	//copiando os caracteres de s2 para o final de s1
	for(j=0;s2[j]!='\0';j++)
	{
		s1[quant+j]=s2[j];
	}
	
	//não esquecer de armazenar o \0 na última posição de s1
	s1[quant+j] = '\0';
}

/*
Outra forma de implementar a função 'concatenarString'

void concatenarString (char s1[], char s2[]) //strcat
{
	//declaração de variáveis
	int i, j;
	int quant;
	
	//armazenando a quantidade de caracteres de s1
	quant=quantidadeCaracteres(s1);
	
	//copiando os caracteres de s2 para o final de s1
	for(i=quant,j=0;s2[j]!='\0';j++,i++)
	{
		s1[i]=s2[j];
	}
	
	//não esquecer de armazenar o \0 na última posição de s1
	s1[i] = '\0';
}
*/

int  compararString (char s1[], char s2[])		//strcmp
{
	//declaração de variáveis
	int i;
	
	//percorrendo as strings até que uma delas ou as duas terminem
	for (i=0;(s1[i] != '\0') && (s2[i] != '\0');i++)
	{
		//encontrar caracteres distintos: não será 0.
		if (s1[i] != s2[i])
		{    
			// EX:A(65) - H(72) = -7
			return (s1[i]-s2[i]); 

			/* 
				Versão 1: válida;

				//testando se dois caracteres distintos foram encontrados. Se sim, concluímos que as strings não são iguais
				if (s1[i] != s2[i])
				{
					//se o caracter da primeira string for menor (alfabeticamente, conforme a tabela ASCII) 
					//do que o da segunda, conclui-se que um número negativo deve ser retornado

					//EX:A(65) H(72) - TABELA ASCII

					if (s1[i] < s2[i])
					{
						return -1;
					}
					else
					{
						//retornando positivo, pois concluiu-se que a segunda string vem antes da primeira, alfabeticamente
						return 1;
					}
				}
			*/

		}
	}	
	return (s1[i]-s2[i]);
	//fim do for condição falha. uma das strings  terminou. 


			/* continuação Versão 1: válida;

					//testando se as duas strings terminaram; se sim, elas são iguais
					if ((s1[i] == '\0') && (s2[i] == '\0'))
					{
						return 0; // ex: s1: |C|A|S|A|\0 s2: |C|A|S|A\0 return '\0'-'\0'= 0 - 0 = 0

					}
					else
					{
						//testando se apenas a primeira terminou: ex:  |c|a|s|a|\0 x |c|a|s|a|r|ã|o|\0 return '\0' - 'R' = 0-82 =-82
						if (s1[i] == '\0')
						{
							return -1;
						}
						else
						{
							//apenas a segunda terminou: ex: |c|a|s|a|r|ã|o|\0 x |c|a|s|a|\0 return 'R'-'\0' = 82 -0 =82
							return 1;
						}
					}
			*/
}