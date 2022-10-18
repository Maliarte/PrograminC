/*
Desenvolver uma função que, dada uma string
s, determine se todos os seus caracteres são
distintos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definições de constantes
#define TRUE 1
#define FALSE 0

int determinaChar(char string[]);
int quantidadeCaracteres(char str[]);

void main(){
//cacau\0
    char string[5];
    strcpy(string, "cacau");

    determinaChar(string);

    //chamando a função
    if (determinaChar(string) == TRUE)
    {
        printf("A palavra %s possui todos caracteres distintos", string);
    }
    else
    {
        printf("A palavra %s nao possui oa caracteres distintos!", string);
    }
}

int determinaChar(char string[]){

     //declaração de variáveis
    int quant, i, j;

    //determinando a quantidade de caracteres da string
    quant = quantidadeCaracteres(string);
    
    for (i = 0, j = quant - 1; i < j; i++, j--) //i: começa na primeira posição;j:começa na última posição
    {
        //verificando se os caracteres nas posições i e j da string são distintos 
        if(string[i] != string[j])
        {
            //todos sao distintos
            return TRUE;
        }
    }
    //concluindo que nao sao todos distintos
    return FALSE;
}

int quantidadeCaracteres(char str[])
{
    //declaração de variáveis
    int i; 
    for (i = 0; str[i] != '\0'; i++);

    //retornando o resultado
    return i; 
}