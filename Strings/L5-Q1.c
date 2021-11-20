/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	
	Data: 07/10/2021
	
	Lista de exercícios V: STRINGS
	
	Questão 01:
	Suponha que não existissem as funções strlen, strcpy, strcat e strcmp. Pede-se, então, a implementação 
	de funções que tenham o mesmo objetivo daquelas.


    comparar e copiar -> mesmo indice (i)
    
     concatenar ->  dois indices (i) (j)

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
	char str1[30], str2[30], str3[30];
	
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
	printf("\nComparando a string %s com %s: %d\n", str1, str2,  compararString (str1, str2));
	printf("\nComparando a string %s com %s: %d\n", str3, str1,  compararString (str3, str1));
	printf("\nComparando a string %s com %s: %d\n", str3, str2,  compararString (str3, str2));
	
	
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

void copiarString (char s1[], char s2[])		//strcpy s2 para s1
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
	
	//percorrendo o s2 e parando quando este for '\0'
	for(j=0;s2[j]!='\0';j++)
	{
        //copiando os caracteres de s2 para o final de s1
		s1[quant+j]=s2[j];
	}
	
	//não esquecer de armazenar o \0 na última posição de s1
	s1[quant+j] = '\0';
}

int  compararString (char s1[], char s2[])		//strcmp
{
    int i;

    //percorrendo as strings até que uma delas ou as duas terminem
	for (i=0; (s1[i] != '\0' && s2[i] != '\0'); i++)
	{	
		//testando se dois caracteres distintos foram encontrados. Caso sim, as strings são diferentes.
		if(s1[i] != s2[i])
		{
			//se o caractere da primeira string é menor que o da 2ª na tabela asc ex: 'S' => 83 'V' => 86
			if(s1[i] < s2[i])
			{
				return -1;
			}	// é maior
				else
				{
					//retorna positivo; pois conclui-se que a segunda string vem antes da primeira alfabeticamente
					return 1;
				}
		}
	}
	//testando se as duas strings terminaram; se sim: elas são iguais.
	if ((s1[i] == '\0' && s2[i] == '\0'))
	{ 
		return 0;
	}
	//saber qual string terminou  
	else 
	{
		//testando se apenas a primeira terminou
		if(s1[i]== '\0')
		{
			return -1;

		}	else
		{
			//apenas a segunda string terminou
			return 1;
		}
	}
}