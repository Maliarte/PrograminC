#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarTemp(int tempMin, int tempMax){
	return (tempMin + (rand() % tempMax));
}

int main(void){
	int dias, contador = 1, temp1, temp2, media;
	printf ("Digite o numero de dias que deseja analisar as temperaturas: ");
	scanf ("%d", &dias);
	srand(time(NULL));
	
	while (contador <= dias){
	printf("Primeira temperatura do %do dia: %d°C\n", contador,  temp1 = gerarTemp(-10, 45));
	printf("Segunda temperatura do %do dia: %d°C\n", contador, temp2 = gerarTemp(-10, 45));
	printf ("Temperatura Média do %do dia: %d°C\n\n", contador, media = (temp1 + temp2)/2);
	contador = contador + 1;
	}
	return 0;
}