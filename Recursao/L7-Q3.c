/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII
	
	Questão 03:
	Considere a função cuja assinatura é apresentada a seguir:

				int pesquisa (char s1[], char s2[], int ordem)

	onde:
		s1		string contendo diversas informações sobre uma pessoa, separadas pelo 
				caracter | (também termina com |)
		s2		uma informação a ser buscada em s1
		ordem	ordem na qual s2 deve ser buscada em s1. Por exemplo, se for igual a 3, 
				a função deve verificar se s2 é a terceira informação dentro de s1.   

	Pede-se a implementação desta função, sabendo que ela deve retornar 1 se s2 estiver 
	em s1 na posição definida por ordem; caso contrário, deve retornar 0.
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int pesquisa (char s1[], char s2[], int ordem);

//main
void main ()
{
	//declaração de variáveis
	char str1[100], str2[30];
	int resp, ordem;
	
	//inicializando as strings
	strcpy (str1, "JOAO DA SILVA|123.456.789-00|06/11/1980|GERENTE|");
	strcpy (str2, "06/11/1980");
	
	//inicializando a ordem
	ordem = 5;
	
	//chamando a função
	resp = pesquisa (str1, str2, ordem);
	
	//exibindo o resultado
	if (resp == 1)
	{
		printf ("\nA string %s esta' na posicao %d de %s.", str2, ordem, str1);
	}
	else
	{
		printf ("\nA string %s nao esta' na posicao %d de %s.", str2, ordem, str1);
	}
}

//implementação das funções
int pesquisa (char s1[], char s2[], int ordem)
{
	//declaração de variáveis
	int i, pos, cont = 1;
	char nova[30];
	
	//posicionando o 'i' no primeiro caracter que está na posição 'ordem' de 's1'
	for (i=0;(cont<ordem)&&(s1[i]!='\0');i++)  //ou vai parar quando chegar ao final da string 's1'
	{
		//sempre que encontrar o caracter '|', chegou-se a uma nova informação
		if (s1[i] == '|')
		{
            //o for  determina posicao da informação da posicao ordem 
			cont++;
		}
	}
	
	//testando se chegou ao final da string 's1'
	if (s1[i] == '\0')
	{
		return 0;
	}
	else
	{
		//montando uma string com a informação de 's1' que está na posição 'ordem'
		pos=0;
		do
		{
			nova[pos] = s1[i];
			pos++;
			i++;
		}
		while (s1[i] != '|');	//quando parar a repetição, o 'i' estará na posição do próximo '|'
		
		//finalizando a string 'nova'
		nova[pos] = '\0';
		
		//comparando 'nova' com a string 's2'
		if (strcmp (nova, s2) == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}