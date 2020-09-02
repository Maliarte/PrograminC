/* Escreva uma função para calcular e retornar o perímetro de um retângulo. Esta função deverá receber os valores das duas dimensões (base e altura) e retornar o valor do perímetro.
Perímetro: valor encontrado quando se soma os quatro lados da figura. É expresso pela fórmula: 2(b + h). Assim, ele corresponde a soma de duas vezes a base e a altura (2b + 2h).
*/
int calculaperimetro ( int base, int altura) {
    int perimetro = (2 * base + 2 *altura);
    return perimetro;
}
int main(void) {
int base, altura,perimetro;
printf("Entre com o valor da Base do Retangulo: ");
scanf(" %i", &base);
printf("Entre com o valor da Altura do Retangulo: ");
scanf(" %i", &altura);
perimetro = calculaperimetro(base, altura);
printf ("O Perimetro do retangulo vale %i \n\n", perimetro);
    return 0;
}

