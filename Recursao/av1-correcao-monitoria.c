/*
    Matheus

Desenvolver uma função recursiva, em C, que, dado um
número inteiro N, exiba as sequências de 1 a N (crescente)
e de N a 1 (decrescente), intercaladas, como no exemplo
abaixo. Além disso, deve ser retornada a soma de todos os
elementos apresentados.

Exemplo:
    N=5
    1 5 2 4 3 3 4 2 5 1

RETORNO: 30

Basicamente, essa função deve exibir de forma intercadala os valores de 
1 até 'n' e 'n' até 1.

São apresentadas duas soluções para efeitos de comparação:
Uma recursiva - sendo esta a solução correta para a questão
Uma Iterativa - esta apenas para ilustrar a solução acima

APENAS A SOLUÇÃO RECURSIVA É ACEITA COMO SOLUÇÃO VÁLIDA PARA ESTA QUESTÃO!!!

PENSANDO UMA SOLUÇÃO RECURSIVA:

Bom, será preciso o parâmetro 'n' e mais outro para que seja possível somar os termos.
Chamarei este outro parâmetro de 'i'.
Então vou percorrer, com a própria variável 'n', os valores de 'n' até 1.
E também os valores de 1 até n, que serão representados por 'i'.
Ora, se eu quero que 'i' comece com 1, isto significa que ao invocar a função, o parâmetro 'i' deve ser 1.
Ao decorrer da função, precisarei somar 'n' e 'i' repetidas vezes, como um acumulador.
Entretando, uma função recursiva, de certa forma, se porta como um acumulador.
------------
1 - Pensando no caso base: quando a função deve acabar?
R: quando 'n' for menor que 1, pois isto significa que que 'n' já foi decrementado até 1. 

Ok, já tenho o caso base. E agora?

2 - Escrevo os valores de i e n, respectivamente.

3 - Agora é preciso acumular os valores da soma de ambos, porém,
uma variável acumuladora não serve para funções recursivas, visto que a cada chamada o valor será sobrescrito pelo inicial.

Então basta:
return i + n + funcaoRecursiva(n - 1, i + 1);
Sim, porque i + n são os acumulos dessas somas.
a nova chamada da função é para continuar iterando sobre os valores.
só que ao invés de j-- e i++, usamos os próprios parâmetros da função para isso.
n - 1 e i + 1.
*/

//Importação de Bibliotecas
#include <stdio.h>

//Protótipo de funções
int funcaoRecursiva(int n, int i);
int funcaoIterativa(int n);

int main()
{
    /***
     * A função é invocada abaixo passando como parâmetros os valores:
     * 5, como no exemplo dado.
     * 1, porque como dito na explicação acima, preciso que 'i' comece em 1 e vá até n.
    ***/

    printf("\nRetorno: %d\n", funcaoRecursiva(5, 1)); //Exibindo o retorno
    printf("\nRetorno: %d", funcaoIterativa(5));      //Exibindo o retorno
    return 0;
}
//Função recursiva
int funcaoRecursiva(int n, int i)
{
    if (n < 1) //1 - Caso base
    {
        return 0;
    }
    else
    {
        printf("%d %d ", i, n);                       //2 - Exibindo os valores
        return i + n + funcaoRecursiva(n - 1, i + 1); //3 - Acumulando os valores e chamando a função novamente.
    }
}
int funcaoIterativa(int n)
{
    int i, j, cont = 0;

    /*
     * Repare que a condição de permanência do for abaixo
     * é o INVERSO do caso base da função recursiva.
     * OBS: entenda "INVERSO" como menor/igual, porque para que n < 1 seja falso, há duas possibilidades:
     * n == 1 E n > 1
     * 
     * 'j' recebe o valor de n.
     * 'i' começa em 1.
     * 
     * 'j' é decrementado (como em n - 1 da recursiva)
     * 'i' é incrementado (como em i + 1 da recusiva)
     */
    for (i = 1, j = n; i <= n; j--, i++)
    {
        printf("%d %d ", i, j); // 2 - Exibindo os valores
        cont += i + j;          // 3 - Acumulado os valores
    }

    return cont; // 3.1 - Retornando o valor acumulado
}