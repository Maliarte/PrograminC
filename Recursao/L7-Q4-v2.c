
//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void exibirInvertido(char s[]);
void exibirInvertidoAux(char s[], int pos);

//função main
void main()
{
    exibirInvertido("ALGORITMOS");
}

//implementação das funções
void exibirInvertido(char s[])
{
    //passando, inicialmente, a primeira posição da string
    exibirInvertidoAux(s, 0);
}

void exibirInvertidoAux(char s[], int pos)
{
    if (pos < strlen(s))
    {
        exibirInvertidoAux(s, pos + 1);
        printf("%c", s[pos]);