/* 
Faça um programa que gere uma quantidade indeterminada de valores entre 1 e 90 (num). Para cada valor gerado o programa deve mostrar os valores múltiplos de 3 entre 1 e num. Caso não haja um múltiplo de 3 no intervalo [1,num], escrever a mensagem” Não há múltiplos de 3 no intervalo”.
 Ao final, deve ser exibido:
Soma dos valores pares
Maior valor múltiplo de 7 gerado
Percentual de números ímpares
Término da geração de valores:  número gerado é múltiplo de 25

*/

#include <stdlib.h>
#include <time.h>

void moldura()
{
    printf("\n================================================\n");
    return;
}

int geraNum()
{
    int num = rand() % 90 + 1;
    return num;
}

float perc(int total, int parc)
{

    float perc = (float)parc / (float)total * 100.0;

    return perc;
}
int main(void)
{

    int num, counterTotal = 0, counterPar = 0, counterImpar = 0, counterMultiplos = 0, counterM3 = 0, maiorM7 = 0, contM7 = 0;

    srand(time(NULL));

    num = geraNum();
    while (num % 25 != 0)
    {
        moldura();
        printf("NUM %i", num);
        moldura();

        if (num % 2 == 0)
        {

            counterPar++;
        }
        else
        {
            counterImpar++;
        }

        if (num % 7 == 0)
        {
            while (contM7 < 1)
            {
                maiorM7 = num;
                contM7++;
            }
            if (num > maiorM7)
            {
                maiorM7 = num;
            }
        }
        counterMultiplos = 0;
        counterM3 = 0;
        while (num > counterMultiplos)
        {
            if ((counterMultiplos + 1) % 3 == 0)
            {
                moldura();
                printf("%i é multiplo de 3", counterMultiplos + 1);
                counterM3++;
            }

            counterMultiplos++;
        }
        if (counterM3 == 0)
        {

            moldura();
            printf("Não há múltiplos de 3 no intervalo");
        }

        num = geraNum();
        counterTotal++;
    }
    moldura();
    printf("\n%i é múltiplo de 25", num);
    moldura();
    printf("\nNumeros pares: %i", counterPar);
    printf("\nMaior valor múltiplo de 7 gerado: %i", maiorM7);
    printf("\nPercentual de números ímpares: %.1f%%", perc(counterTotal, counterImpar));

    return 0;
}


