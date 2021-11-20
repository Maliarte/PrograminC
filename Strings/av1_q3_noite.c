/*****************************************************************************************************************

	FAETERJ-Rio
	FPR - 2021/2 - Noite
	Professor Leonardo Vianna
	
	Prova a compor a AV1 - aplicada em 08/11/2021
	
	Questão 03 [2,5 pontos]:
	Desenvolver uma função, em C, que remova de uma string s os caracteres compreendidos entre as posições 
	p1 e p2. 
	Caso p1 ou p2 seja uma posição inválida, a função deverá retornar o valor 0 e a remoção de caracteres 
	solicitada não será realizada; caso contrário, deverá retornar 1 e proceder com o que foi pedido.

*****************************************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração de protótipos
int questao03 (char s[], int p1, int p2);

//main
void main ()
{
	//declaração de variáveis
	int retorno;
	char s[30];
	
	//inicializando a string
	strcpy (s, "ALGORITMOS");
	
	//chamando a função
	retorno = questao03 (s, 0, 9);
	
	//exibindo o resultado
	if (retorno == 0)
	{
		printf ("\nPosicao invalida.");
	}
	else
	{
		printf ("\nString apos remocao dos caracteres: %s", s);
	}
}

//implementação das funções
int questao03 (char s[], int p1, int p2)
{
	//declaração de variáveis
	int tamanho, i, j;
	
	//verificando se p1 ou p2 é inválida
	tamanho = strlen (s);
	if ((p1 < 0) || (p1 >= tamanho) || (p2 < 0) || (p2 >= tamanho))
	{
		return 0;
	}
	else
	{
		//removendo os caracteres das posições 'p1' a 'p2'
		for (i=p1,j=p2+1;s[j] != '\0';i++,j++)
		{
			s[i] = s[j];
		}
		
		s[i] = '\0';
		
		return 1;
	}
}