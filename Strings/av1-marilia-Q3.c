/*
    FPR - Fundamentos de Programação
    Professor Leonardo Vianna
    Discente: Marília Silva

                                Data: 11/11/2021
                                AV1 - Q3

Questão 03:

    Desenvolver uma função que, dada uma string s, e dada uma posição p desta string
    crie duas novas strings: s1 com os caracteres de s das posições 0 a p-1; e s2 
    com os caracteres de s da posição p à ultima.

    Observações: 
    caso p seja um posição invalida, a função deverá retornar o valor 0; caso contrário
    procederá com a criação das duas strings e retornará o valor 1.

                            Exemplos:
                            s: ALGORITMOS 
                            p: 3

                            novastring1 S1: ALGO
                            novastring2 S2: RITMOS 

*/
//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração dos protótipos
int novaS(char s[], int p, char s1[], char s2[]);


//main
void main()
{
    //declaração de variáveis
    char s[30], s1[30],s2[30];
    int p;
    //inicializando a string
    strcpy(s, "ALGORITMOS");
    
    fflush(stdin);
    printf("entre com a posicao: ");
    scanf("%d", &p);

    printf("string original: %s\n", s);
    //testando a função

    novaS(s, p, s1,s2);

    //printf("\nposicao = %d\n", p); 
    printf("str1:%s\nstr2:%s", s1, s2);
}  
//implementação das funções
int novaS(char s[], int p, char s1[], char s2[])
{
    //posicao valida 
    if ( p < strlen(s)) {

    //declaração de variáveis
    /*                                          correçao 18.11.21
        criados na main, passados por parametro

        char s1[30];
        char s2[30];
    */
        int i, j;

    
        //s1 com os caracteres de s das posições 0 a p-1; 
        for(i = 0; i < p - 1; i++) {

            s1[i] = s[i];
            
        } s1[i] = '\0';

        //s2 com os caracteres de s da posição p à ultima.
        for(j = 0; j < strlen(s); j++) {

            s2[j] = s[j];
            
        }s2[j]='\0';

        return 1;

    }
    else 
    {
        return 0;
    }
}