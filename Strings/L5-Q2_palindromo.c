/*
                                        FPR - Fundamentos de Programação
                                        
                                        STRINGS

Exemplo 3: Verificar se uma string é um palíndromo.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//definições de constantes
#define TRUE 1
#define FALSE 0
//declaração de protótipos
int quantidadeCaracteres(char str[]);
int palindromo(char string[]);
//main
void main()
{
    //declaração de variáveis
    char str[30];
    //lendo a string
    fflush(stdin);
    printf("Entre com uma palavra/frase: ");
    gets(str); //get string - lê uma string, independente do tamanho e dos caracteres que a compõem
        
    //chamando a função
    if (palindromo(str) == TRUE)
    {
        printf("A palavra %s e' um palindromo!", str);
    }
    else
    {
        printf("A palavra %s nao e' um palindromo!", str);
    }
}
//implementação das funções
int quantidadeCaracteres(char str[])
{
    //declaração de variáveis
    int i; //, cont = 0;
    for (i = 0; str[i] != '\0'; i++)
        ;
    //{
    //cont++;
    //}
    //retornando o resultado
    return i; //cont;
}
int palindromo(char string[])
{
    //declaração de variáveis
    int quant, i, j;
    //determinando a quantidade de caracteres da string
    quant = quantidadeCaracteres(string);
    
    for (i = 0, j = quant - 1; i < j; i++, j--) //i: começa na primeira posição;j:começa na última posição
    {
        //verificando se os caracteres nas posições i e j da string são distintos if (string[i] != string[j])
        if(string[i] != string[j])
        {
            //não é um palíndromo
            return FALSE;
        }
    }
    //concluindo que é um palíndromo
    return TRUE;
}



/* com a funçao strlen

int palindromo(char string[])
{
    //declaração de variáveis
    int quant, i, j;
    
	//determinando a quantidade de caracteres da string
    quant = strlen(string);
    
	for (i = 0, j = quant - 1; i < j; i++, j--) //i: começa na primeira posição;j:começa na última posição
    {
        //verificando se os caracteres nas posições i e j da string são distintos if (string[i] != string[j])
        {
            //não é um palíndromo
            return FALSE;
        }
    }
  
	//concluindo que é um palíndromo
    return TRUE;
}
*/