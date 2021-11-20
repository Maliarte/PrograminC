/*
                    FPR - Fundamentos de Programação

                                STRINGS
                        
                        Inverter uma string.
Exemplo:
                        string inicialmente: ABCDE
                        string ao final: EDCBA
*/
//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//declaração de protótipos
void inverterString(char str[]);
int quantidadeCaracteres(char str[]);
//main
void main()
{
    //declaração de variáveis
    char str[30];
    //lendo a string
    fflush(stdin);
    printf("Entre com uma palavra/frase: ");
    gets(str); //get string - lê uma string, independente do
    tamanho e dos caracteres que a compõem
        //exibindo a string antes da chamada à função
        printf("\nstring inicialmente: %s\n", str);
    //chamando a função
    inverterString(str);
    //exibindo a string após a chamada à função
    printf("\nstring apos a chamada: %s\n", str);
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
void inverterString(char str[])
{
    //declaração de variáveis
    int quant, i, j;
    char aux;
    //determinando a quantidade de caracteres da string
    quant = quantidadeCaracteres(str);
    for (i = 0, j = quant - 1; i < j; i++, j--) //i: começa na
        primeira posição;
j:
    começa na última posição
    {
        aux = str[j];
        str[j] = str[i];
        str[i] = aux;
    }
}