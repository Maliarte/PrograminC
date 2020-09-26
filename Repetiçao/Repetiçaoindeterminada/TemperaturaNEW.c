#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

float mediaTemp (float temp1, float temp2)
{
    float media = (temp1+temp2)/2;
    return media;
}

int main (void)
{
    float temp1, temp2, media;
    int contDias, numDias;

    setlocale (LC_ALL, "portuguese");

    printf("\nQuantidade de dias: ");
    scanf("%i", &numDias);

    srand(time(NULL));
    


    contDias = 1;

    while (contDias<=numDias)
    {
       temp1 = -10 + rand() %56; /* 0 a 55 */
       temp2 = -10 + rand() %56;
       media=mediaTemp (temp1,temp2);
       printf("\n%f %f\n",temp1,temp2);
       printf ("\nNo dia %i média de temperatura foi de %.2f",contDias, media);
       contDias = contDias+1;
    }




    return 0;

}
