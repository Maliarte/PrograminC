#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que receba para cada uma das n (fornecidos pelo usuário) partidas de uma
 rodada do campeonato municipal de futebol, o código e o número de gols feitos por um dos times e o
 código e o número de gols feitos pelo outro time da partida, mostrando, para cada partida, o código do
 time vencedor ou a mensagem empate. estrutura de repetição determinada necessariamente tem que ter o contador?  controla por contagem*/

int main()
{
int partidas, cont;
int codigo;
int codTime1, codTime2;
int golsTime1, golsTime2;

printf("Digite a quantidade de partidas:");
scanf("%d", &partidas);

cont = 0;
while (cont < partidas){

    printf("\nDigite o Codigo do primeiro time");
    scanf("%d", &codTime1);
    printf("\nDigite a quantidade de gols primeiro time");
    scanf("%d", &golsTime1);
    printf("\nDigite o Codigo do segundo time");
    scanf("%d", &codTime2);
    printf("\nDigite a quantidade de gols marcados pelo segundo time");
    scanf("%d", &golsTime2);

    if (golsTime1 == golsTime2){

        printf("\n jogo foi empate");
    }
    else{
        if(golsTime1 > golsTime2) {
            codigo=codTime2;
        }
    }
    
    else{
        printf("O time vencedor foi: %i",codigo);

    }
cont++;    
   
}
return o; //programa retorna sem erro
}
