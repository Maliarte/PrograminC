#include <stdio.h>
#include <locale.h>
#include <math.h>
/* programa de multiplos e submultiplos e sistema de representação. Algoritmo pensado e desenvolvido por Marilia Silva https://maliarte.com.br */

int main(void) {

    float valor; //declara variaveis para definir o escopo do programa
    //char extenso, simbolo, prefixo;
    double potencia;

    setlocale(LC_ALL,"portuguese"); //determina grafia baseado geolocalizacao

    printf("Informe o decimal que vá de 0.000.000.000.000.000.001 quintilionesimo ate 1.000.000.000.000.000.000 quintilhão \n");
    scanf("%f", &valor);
    potencia = pow(valor,valor);
    printf(" O num é: %.00f",potencia);

    return(0);
}