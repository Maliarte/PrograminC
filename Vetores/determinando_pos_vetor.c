

/*
Para determinar a posição  do vetor:

métodos:
* Acesso direto: quando o dado pode ser transformado matematicamente em pos

* Busca:ao contrário do acesso direto, neste caso a lista de valores deve estar disponível em outro vetor.


Ex: Acesso direto

O dia de matricula dos calouros depende do curso desejado. 
Há 34 cursos identificados sequencialmente 1 a 34.
Faça um programa que capture o número do curso e o dia do mês de janeiro que os alunos deste curso deverão fazer matrícula.
A seguir, para cada aluno aprovado(matrícula e curso) exiba na tela sua matrícula, curso e dia que deverá comparecer para se inscrever.

*/
#include <stdio.h>
#include <stdlib.h>

#define DIM 14

int main(void){
    float vdias[DIM];
    int matr, curso, pos;

    for (i=0, i < 34, i++)
    {
    printf("Informe número do curso:\n");
    scanf("%i", &curso);
    printf("Informe dia do mês:\n");
    scanf("%i", &vdias[curso - 1]);
    }

return 0;
}