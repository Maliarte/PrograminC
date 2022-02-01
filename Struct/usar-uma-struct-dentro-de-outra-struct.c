/* 
        De quanta memória uma STRUCT precisa?
*/

#include <stdio.h>
#include <stdlib.h>

// tipo data de nascimento
typedef struct{
    int dia, mes, ano;
}TData;

// tipo pessoa agora com uma data de nascimento
typedef struct{
    TData born;
    int idade;
    char sexo;
    char nome[30];
}TPessoa;

void main() {
    TPessoa pessoa;
    TData born;

    TPessoa pessoa;

    printf("%d\n", sizeof(TPessoa)); // tamanho do tipo Pessoa
    printf("%d\n", sizeof(pessoa)); // tamanho de uma variável do tipo Pessoa

}