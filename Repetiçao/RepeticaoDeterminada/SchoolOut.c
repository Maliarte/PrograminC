/* Faça um programa que obtenha a matrícula , a nota da prova e a média dos trabalhos dos alunos de uma turma, mostrando a média final de cada um. O término da entrada de dados ocorre quando for introduzido 0 como número de matrícula.
A média de um aluno é calculada da seguinte forma:
		 0.85*nota da prova+ 0.15*média dos trabalhos 

Seu programa deve responder:
    V1- Quantos alunos com nota acima de 7 e quantos alunos com nota abaixo de 3?        
    v2 - Qual a média da turma?
    V3 - Qual a menor nota? Quantos alunos com a menor nota?
    V4 - Qual a maior nota? Quantos alunos com a maior nota?
*/


#include <stdio.h>
#include <locale.h>

float fazerMedia(int m)
{
    float nP, nT, mediaAluno;
    printf("\nDigite a nota da prova do aluno: ");
    scanf("%f", &nP);
    printf("Agora, informe a média dos trabalhos: ");
    scanf("%f", &nT);
    printf("\nA média do aluno é %.1f.\n", mediaAluno = ((0.85 * nP) + (0.15 * nT)));
    return mediaAluno;
}

int main(void) {
    float mediaAluno;
    int numMatricula, alunosAprov = 0, alunosReprov = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("Informe a matrícula do aluno, ou 0 para encerrar o programa: ");
    scanf("%d", &numMatricula);

    while (numMatricula > 0){
        mediaAluno = fazerMedia(numMatricula);
        if (mediaAluno > 7)
            alunosAprov++;

        else if (mediaAluno < 3)
            alunosReprov++;

        printf("\nInforme a matrícula do aluno, ou 0 para encerrar o programa: ");
        scanf("%d", &numMatricula);
    }
    printf("\nAlunos com media acima de 7: %d", alunosAprov);
    printf("\nAlunos com media abaixo de 3: %d", alunosReprov);
    printf("\n\nPrograma encerrado.\n");
    return 0;
}