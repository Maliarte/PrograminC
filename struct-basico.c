//importacao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    float peso;
    int idade;
    float altura;
} pessoa;

void main(){

    pessoa.peso = 80;   
    pessoa.idade = 27; 
    pessoa.altura = 1.75; 

    printf("Idade: %d | Altura: %.2f | Peso: %.2f\n", pessoa.idade, pessoa.altura, pessoa.peso);
}