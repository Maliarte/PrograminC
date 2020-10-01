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

float mediaFinal(float x, float y) {
    float calc = x * 0.85 + y * 0.15;
    return calc;
}

float mediaGeral(float a, int b)
{
    float mg = a / b;
    return mg;
}
int main(void)
{
    int Matr, Media7 = 0, Media3 = 0, ctAlunos = 0;
    float pr, trab, media, mediaTurma, ctMedTurma = 0;
    float notaMaior = 0, notaMenor = 10; 

    setlocale(LC_ALL, "portuguese");

    printf("\nDigite a matrícula ou 0 para encerrar: ");
    scanf("%i", &Matr);

    while (Matr > 0){

        printf("\nDigite a nota da prova: ");
        scanf("%f", &pr);
        printf("\nDigite a media dos trabalhos: ");
        scanf("%f", &trab);

        media = mediaFinal(pr, trab);

        ctAlunos++; //Incrementa contagem de alunos 

        ctMedTurma = ctMedTurma + media; 

        
        if (media > 7){
            Media7++;
        }
        else if (media < 3) {
                Media3++;
        }
        
       
        if (media > notaMaior) {
            notaMaior = media;
        }
        if (media < notaMenor) {
            notaMenor = media;
        }
        
        printf("\nMedia aluno: %.2f", media);
        printf("\n\nDigite sua matricula ou 0 para encerrar: ");
        scanf("%i", &matr);
    }

    mediaTurma = mediaGeral(ctMedTurma, ctAlunos);

    printf("\n Media da Turma %.2f", mediaTurma);
    printf("\nAlunos com nota acima de 7: %i", Media7);
    printf("\nAlunos com nota abaixo de 3: %i", Media3);
    printf("\nA maior nota da turma foi: %.2f", ctNotaMaior);
    printf("\nA menor nota da turma foi: %.2f", ctNotaMenor);
    return 0;
}