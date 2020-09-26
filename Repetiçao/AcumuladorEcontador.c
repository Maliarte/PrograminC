/*considere que dentro de um conjunto de informações referentes a sexo e idade de 50 pessoas, desejamos saber quantas dessas pessoas são do sexo feminino e possuem 18 anos ou mais. Para isso é necessário inserir um contador para armazenar a quantidade de ocorrencias da condição definida no enunciado. Esse contador deve ser inicializado com 0 e incrementado em 1 sempre que o sexo for feminino e a idade maior que 18  */

#include <stdio.h>
#include <locale.h>

/*int main (void) {

    int idade, c;
    char sexo;

    c = 0; //contador inicializado
    setlocale(LC_ALL, "portuguese");
    printf("Entre com o gênero: (f)Feminino (m)Masculino ");
    scanf("%c", &sexo);
    printf("Entre com a idade: ");
    scanf("%i", &idade);
    if (sexo="f" && idade >= 18) {
     c = c+1;
    }
    printf("A quantidade de pessoas do sexo feminino é:  %c", c);
    return 0;
}

*/

/*escreva um algoritmo que imprima 0 inclusive e 10 inclusive em ordem decrescente

int main (void) { 
int ct;

ct=10;
while (ct > 0) {
    printf("%i \n", ct);
    ct=ct-1;
    }
    return 0;
}


//escreva um algoritmo que imprima os numeros menores que 100 de 10 em 10

int main (void){
int ct;

ct = 100;

while (ct>0) {
    printf("%i \n", ct);
    ct = ct - 10;
    }
    return 0;
} 
//escreva um algoritmo para ler 10 valores, calcular e escrever a media aritmetica desses valores

int main (void) {
float  n, media;
int soma, ct;
soma=0;
ct=0;
    while (ct < 10){
    printf("Escreva o valor: ");
    scanf("%f", &n);
    soma = soma + n;
    ct=ct+1;
    }
    media = soma/ct;
    printf("A media aritmetica e %f", media);
    
    return 0;
}
*/

