/* Faça um programa que, a partir das temperaturas mínima e máxima ocorridas,  mostre a temperatura média de n(lido) dias.  As temperaturas devem ser geradas automaticamente com valores entre -10 e +45 */
#include <stdio.h>
#include <locale.h>
#include <stdlib.h> //biblioteca necessária para a funçao rand
#include <time.h>

int main(void){
    float tempMin, tempMax, tempMedia;
    int nDias
    printf("Informe a temperatura mínima:\n");
    scanf("%f", &tempMin);
    printf("Informe a temperatura maxima:\n");
    scanf("%f", &tempMax);
    printf("Informe período:\n");
    scanf("%i", &nDias);
    for (i=0;i<10; i++); {
        printf("%d \n\n\n\n\n",rand() % 100);

    }
    return 0;
}



/*
float mediaTemp (float temp1, float temp2)
{
    media = (temp1+temp2)/2;
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
    temp1 = -10 + rand() %45;
    temp2 = -10 + rand() %45;


    contDias = 1;

    while (contDias>=numDias)
    {
       mediaTemp (float temp1, float temp2);
       printf ("\nNo dia %i média de temperatura foi de %.2f",contDias, media);
       contDias = contDias+1;
    }




    return 0;

}
 */