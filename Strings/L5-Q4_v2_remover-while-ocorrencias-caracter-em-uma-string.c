/*
FPR - Fundamentos de Programação

STRINGS
Exemplo 5: Remover todas as ocorrências de determinado
caracter em uma string.
Exemplo:
                                string inicialmente: ALGORITMOS
                                caracter a ser removido: O
                                string ao final: ALGRITMS

versão 2: usando 'while' no lugar do 'for'
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//declaração de protótipos
int quantidadeCaracteres(char str[]);
int removerCaracter(char str[], char caracter);
//main
void main()
{
    //declaração de variáveis
    char str[30];
    char caracter;
    int quantidade;
    //lendo a string
    fflush(stdin);
    printf("Entre com uma palavra/frase: ");
    gets(str); //get string - lê uma string, independente do
    tamanho e dos caracteres que a compõem
        //lendo o caracter a ser removido da string
        fflush(stdin);
    printf("Entre com o caracter a ser removido: ");
    caracter = getche();
    //exibindo a string antes da chamada à função
    printf("\n\nstring inicialmente: %s", str);
    //chamando a função
    quantidade = removerCaracter(str, caracter);
    //exibindo a string após a chamada à função
    printf("\nstring apos a chamada: %s", str);
    printf("\nForam feitas %d remocoes.", quantidade);
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
//remove todas as ocorrências de 'caracter' na string 'str',
retornando a quantidade de remoções realizadas int removerCaracter(char str[], char caracter)
{
    //declaração de variáveis
    int i, quant, pos, cont = 0;
    //armazenando em 'quant' a quantidade de caracteres da string
    'str' quant = quantidadeCaracteres(str);
    //percorrendo a string
    i = 0;
    while (i < quant)
    {
        //verificando se o 'caracter' foi encontrado
        if (str[i] == caracter)
        {
            //deslocando os caracteres além daquele que
            será removido uma posição para a esquerda(incluindo o próprio \0) for (pos = i + 1; pos <= quant; pos++)
            {
                str[pos - 1] = str[pos];
            }
            //atualizar o valor de 'quant'
            quant--;
            //atualizando a quantidade de remoções
            realizadas
                cont++;
        }
        else
        {
            i++;
        }
    }
    //retornando a quantidade de remoções realizadas
    return cont;
}