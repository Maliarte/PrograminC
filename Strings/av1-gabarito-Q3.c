/**********************************************************  Gabarito *******************************************************


	Desenvolver uma função, em C, que, dada uma string s e dada uma posição p desta 
	string, crie duas novas strings: s1 com os caracteres de s das posições 0 a p-1; 
	e s2 com os caracteres de s da posição p à última.

	Nota: Caso p seja uma posição inválida, a função deverá retornar o valor 0; 
	caso contrário, procederá com a criação das duas strings e retornará o valor 1.

*****************************************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipo da função
int questao03(char s[], int p, char s1[], char s2[]);

//main
void main()
{
    //declaração de variáveis
    char str[30], str1[30], str2[30];
    int retorno;

    //inicializando a string str
    strcpy(str, "ALGORITMOS");

    //chamando a função
    retorno = questao03(str, 9, str1, str2);

    //exibindo o resultado
    if (retorno == 0)
    {
        printf("\nPosicao invalida");
    }
    else
    {
        printf("\nstr: %s", str);
        printf("\nstr1: %s", str1);
        printf("\nstr2: %s", str2);
    }
}

//implementação da função
int questao03(char s[], int p, char s1[], char s2[])
{
    //declaração de variáveis
    int i, j;

    //verificando se a posição 'p' é inválida
    if ((p < 0) || (p >= strlen(s)))
    {
        return 0;
    }
    else
    {
        //criando a string s1
        for (i = 0; i < p; i++)
        {
            s1[i] = s[i];
        }

        s1[i] = '\0';

        //criando a string s2
        for (i = p, j = 0; i < strlen(s); i++, j++)
        {
            s2[j] = s[i];
        }

        s2[j] = '\0';

        return 1;
    }
}