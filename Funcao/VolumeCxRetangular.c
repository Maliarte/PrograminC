/* Escreva uma função para calcular e retornar o volume de uma caixa retangular. Esta função deverá receber os valores dos lados a e b e altura h e retornar o valor do volume. (Vcaixa = a * b * h) */

int volume( int a, int b, int h) {
    int valor = (a * b * h);
    return valor;
}
int main(void) {
int a, b, h, valor;
printf("Entre com o valor Lado A: ");
scanf(" %i", &a);
printf("Entre com o valor Lado B: ");
scanf(" %i", &b);
printf("Entre com o valor Altura: ");
scanf(" %i", &h);
valor = volume(a, b, h);
printf ("O volume de uma caixa retangular vale %i \n\n", valor);
    return 0;
}

