
/*
     Como criar uma struct com dados lidos do teclado
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int idade;
    char sexo;
    char nome[100];
} TPessoa;

int main() {
    TPessoa pessoa;

    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);

    scanf("%c"); //fflush?

    printf("Digite f ou m para o sexo:");
    scanf("%c", &pessoa.sexo);

    printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoa.nome, pessoa.idade, pessoa.sexo);

    return 0;
}