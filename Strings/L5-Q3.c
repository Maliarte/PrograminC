/*
    FPR - Fundamentos de Programação
    Professor Leonardo Vianna

Data: 14/10/2021
Lista de exercícios V: STRINGS

Questão 03:
    Desenvolver uma função que, dada uma string s, crie uma
    substring que inicie na posição p de s
    e contenha n caracteres.
    Observações:

    i) se p e/ou n forem inválidos, a substring será vazia;
    ii) se s não possuir n caracteres além de p, a substring a ser criada começará em p e terminará no final de s.

Exemplos:
 3
s: ALGORITMOS substring:
ORIT
p: 3
n: 4
Observação i): p<0 ou p>=tamanho da string
n<=0 ou n>tamanho da
string
Observação ii):
 7
s: ALGORITMOS substring: MOS
p: 7
n: 6
*/
//importação de bibliotecas
#include <stdio.h>
#include <string.h>
//declaração dos protótipos
void substring(char s[], int p, int n, char subs[]);
//main
void main()
{
    //declaração de variáveis
    char str[30], sub[30];
    //inicializando a string
    strcpy(str, "FUNDAMENTOS DE PROGRAMACAO");
    

    printf("string original: %s\n", str);
    //testando a função
    substring(str, 5, 4, sub);
    printf("\nposicao = 5, n caracteres = 4: %s\n", sub); //MENT

    substring(str, 50, 4, sub);
    printf("\nposicao = 50, n caracteres = 4: 'STRING VAZIA' - posicao invalida %s\n", sub); //STRING VAZIA substring invalido

    substring(str, 5, 40, sub);
    printf("\nposicao = 5, n caracteres = 40: 'STRING VAZIA' - n invalido %s\n", sub); //STRING VAZIA n- invalido

    substring(str, 10, 20, sub);
    printf("\nposicao = 10, n caracteres = 20: %s\n", sub); //S DE PROGRAMACAO
}
//implementação das funções
void substring(char s[], int p, int n, char subs[])
{
    //declaração de variáveis
    int i, j;
                                                            //validando os valores de p e de n
                                                            //p válido: de 0 a strlen(s)-1
                                                            //n válido: de 1 a strlen(s)

    //testando se a posição e o n - o tamanho da string é válido
    if ((p < 0) || (p >= strlen(s)) || (n <= 0) || (n > strlen(s)))
    {
        strcpy(subs, ""); //i) se p e/ou n forem inválidos, a substring será vazia;
        
        //ou: subs[0] = '\0';
    }
    else
    {
        //criando a substring
        //indice da string original i na posicao p e j na pos 0 da substring,
        for (i = p, j = 0; (j < n) && (s[i] != '\0'); i++, j++)
        {
            subs[j] = s[i];
        }
        //não esquecer de terminar a substring com '\0'
        subs[j] = '\0';
    }
}