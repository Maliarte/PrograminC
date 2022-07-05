/********************************************************************************************

	FPR - Manhã
	Professor Leonardo Vianna
	2021/2
	Data: 04/11/2021
	
	Lista de Exercícios VII
	
	Questão 04:
	Desenvolver uma função recursiva que, dada uma string, exiba-a invertida.
		

        ex: TESTE
            ETSET
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void exibirInvertido(char s[]); // buscar modificadores de acesso em C esse seria publico
void exibirInvertidoAux(char s[], int pos); //private

//função main
void main()
{
    exibirInvertido("ALGORITMOS");
}

//implementação das funções
void exibirInvertido(char s[])
{
    //passando, inicialmente, a última posição da string
    exibirInvertidoAux(s, strlen(s) - 1);
}

void exibirInvertidoAux(char s[], int pos)
{
    if (pos >= 0)
    {
        printf("%c", s[pos]); //printando o ultimo elemento, e chamando a funcao recursiva para os demais elementos,
        exibirInvertidoAux(s, pos - 1);
    }
}