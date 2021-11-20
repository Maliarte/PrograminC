/*
                FPR - Fundamentos de Programação

                STRINGS
Exemplo 2: Determinar o número de ocorrências de um caracter em determinada string.

Versão 2: contabilizando o número de ocorrências da letra, independente se aparece na string como maiúscula ou minúscula.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//declaração de protótipos
int quantidadeLetra(char palavra[], char letra);
//main
void main()
{
    //declaração de variáveis
    char letra, str[30];
    int quant;
    //lendo a string
    fflush(stdin);
    printf("Entre com uma palavra/frase: ");
    gets(str); //get string - lê uma string, independente do
    tamanho e dos caracteres que a compõem
        //lendo a letra a ser buscada na string
        fflush(stdin);
    printf("Entre com uma letra: ");
    letra = getche(); //getche - leitura de um
    caracter
        // ou: scanf ("%c", &letra);
        //chamando a função
        quant = quantidadeLetra(str, letra);
    //exibindo o resultado
printf ("\nForam encontradas %d ocorrencias da letra %c na
string %s.", quant, letra, str);
}
//implementação das funções
int quantidadeLetra(char palavra[], char letra)
{
    //declaração de variáveis
    int i, cont = 0;
    //percorrendo a string
    for (i = 0; palavra[i] != '\0'; i++)
    {
        //verificando se a letra foi encontrada na string
        if (toupper(palavra[i]) == toupper(letra))
        {
            cont++;
        }
    }

    //retornando a quantidade de ocorrências da letra na string
    return cont;
}