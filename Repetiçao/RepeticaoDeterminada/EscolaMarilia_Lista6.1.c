/* Faça um programa que obtenha a matrícula , a nota da prova e a média dos trabalhos dos alunos de uma turma, mostrando a média final de cada um. O término da entrada de dados ocorre quando for introduzido 0 como número de matrícula.
A média de um aluno é calculada da seguinte forma:
		 0.85*nota da prova+ 0.15*média dos trabalhos 

Seu programa deve responder:
    V1- Quantos alunos com nota acima de 7 e quantos alunos com nota abaixo de 3?        
    v2 - Qual a média da turma?
    V3 - Qual a menor nota? Quantos alunos com a menor nota?
    V4 - Qual a maior nota? Quantos alunos com a maior nota?
*/

#include<stdio.h>
#include <locale.h>

float sys (int matr, int nAlunos){
float notaProva, mediaTrab,mediaF;
int matr,nAlunos
    while (matr > 0) {
        
        printf ("Informe a nota da Prova AV1: ");
        scanf  ("%f", &notaProva);
        printf ("Informe a media dos Trabalhos: ");
        scanf ("%f", &mediaTrab);
        mediaAtv = media(notaProva, mediaTrab);

        return mediaAtv;
}



void moldura (void) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~");
    printf("~~~~~~~~~~~~~~~~~~~~~~~");
    printf("~~~~~~~~~~~~~~~~~~~~~~~");
}

float somatorio (float somaMedia, int nAlunos) {
float mediaTurma, float somaMed;
int nAlunos;

somaMedia = somaMedia+1;

    mediaTurma = somaMedia/nAlunos;
    return mediaTurma;
}

float Mais7 (float notaProva){
float alunosUp;
    if (notaProva >=7){
        alunosUp = alunosUp +1;
        return alunosUp;
    }
}
float Menos3 (float notaProva){
float alunosDown;
    if (notaProva < 3) {
        alunosDown = alunosDown +1;
        return alunosDown;
    }
}

float media( float notaProva, float mediaTrabalho) {
    float mediaF;
    mediaF =(0.85*notaProva) + (0.15 * mediaTrabalho);
    return mediaF; 
}

int main (void) {
    float notaProva, mediaTrab, mediaF,somaMedia, mediaTurma, alunosUp, somatorio,medAtv;
    int  matr, jafiz, nAlunos, aprovados;


    somaMedia = 0;

    setlocale(LC_ALL,"portuguese");

    printf ("Quantos Alunos na Turma?: ");
    scanf("%d", &nAlunos);
    printf ("Informe a matricula: ");
    scanf("%d", &matr);

   
        
        printf ("\nA media final: %.2f \n", mediaF);
        printf ("\nAlunos com nota acima de 7: %.2f \n", alunosUp);
        printf ("\nAlunos com nota abaixo de 3: %.2f \n", alunosDown);
        printf ("\nMedia da Turma: %.2f \n", mediaTurma);

        printf("\n\nInforme a matricula ou digite 0 para encerrar \n");
        scanf("%d", &matr);
   
    }  

    return 0;
}
