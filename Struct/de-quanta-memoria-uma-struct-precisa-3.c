/* 
        De quanta memória uma STRUCT precisa?


#include <stdio.h>
#include <stdlib.h>


// tipo pessoa agora com uma data de nascimento
typedef struct{
    int idade;
    char sexo;
    char nome[30];
}TPessoa;

void main() {
    TPessoa pessoa;

    printf("%d\n", sizeof(TPessoa));                    // tamanho do tipo Pessoa
    printf("%d\n", sizeof(pessoa));                     // tamanho de uma variável do tipo Pessoa
    printf("%d", sizeof(pessoa.idade));                 // tamanho da variavel idade do tipo Pessoa
}

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia, mes, ano;
}DataNas;

typedef struct {
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[30];
}Pessoa;

void main() {
    Pessoa pessoa;
    DataNas data;

    printf("==========================================\n");
    printf("Tamanho variavel [data] tipo DataNas: %d bytes\n", sizeof(data));
    printf("Tamanho variavel [pessoa] tipo Pessoa: %dbytes\n", sizeof(pessoa));
    printf("==========================================\n");
    printf("\n\nDigite seu nome: ");
    fgets(pessoa.nome, 30, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);

    scanf("%c");
    printf("Digite f ou m para o sexo:");
    scanf("%c", &pessoa.sexo);

    printf("Digite sua data de nascimento no formato dd mm aaaa:\n");
    scanf("%d%d%d", &pessoa.dataNas.dia, &pessoa.dataNas.mes, &pessoa.dataNas.ano);

    printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoa.nome, pessoa.idade, pessoa.sexo);
    printf("Data de nasc.: %d/%d/%d\n", pessoa.dataNas.dia, pessoa.dataNas.mes, pessoa.dataNas.ano);

}