/*1.	Faça um programa que pergunte a matrícula a nota1 e a nota2 dos alunos de uma turma. Mostre a média aritmética e se o alunos está aprovado ( média >=6) ou não. A entrada de dados é finalizada quando uma matrícula ≤ 0 for digitado. */
#include <stdio.h>
#include <stdio.h>
int mediaArit(int x, int y){
    int media;
    media = (x+y)/2;
    return media;
}
/* 
obtém nota
while  a nota digitada estiver errada
    mensagem ...
    pedir um novo valor de nota
*/  
int obterNotaValida(int num){
  int nota;
  printf("Digite a nota %i: ",num);
  scanf("%i", &nota);
  while ( nota <0 || nota >10){
    printf("\nNota inválida. Digite um valor entre 0 e 10");
    printf("\nDigite a nota %i: ",num);
    scanf("%i", &nota);
   }
   return nota;
}


int main(){
    int nota1,nota2,matric,media;
    printf("Digite a 1ª matrícula ou 0 para finalizar: ");
    scanf("%i", &matric);

    while(matric > 0){

        nota1=obterNotaValida(1);
        nota2=obterNotaValida(2);
        media = mediaArit(nota1, nota2);

        if(media >= 6)
                printf("Você foi aprovado\n");

        else
                printf("Você foi reprovado\n");
        printf("Digite a próxima matrícula ou 0 para finalizar: ");
        scanf("%i", &matric);
    }
    return 0;
}



/* 

#include <stdio.h>
#include <stdio.h>
int mediaArit(int x, int y){
    int media;
    media = (x+y)/2;
    return media;
}

int main(){
    int nota1,nota2,matric,media;
    printf("Digite a 1ª matrícula ou 0 para finalizar: ");
    scanf("%i", &matric);

    while(matric > 0){

        printf("Digite sua primeira nota: ");
        scanf("%i", &nota1);
        printf("Digite sua segunda nota: ");
        scanf("%i", &nota2);
        media = mediaArit(nota1, nota2);

        if(media >= 6)
                printf("Você foi aprovado\n");

        else
                printf("Você foi reprovado\n");
        printf("Digite a próxima matrícula ou 0 para finalizar: ");
        scanf("%i", &matric);
    }
    return 0;
}




return 0;
}
====================tamis=========================
#include <stdio.h>

int main (void){
    int matricula;
    float nota1, nota2, media;
    printf ("Digite a matricula do aluno:");
    scanf ("%d", &matricula);
    
    while (matricula > 0){
        printf ("Digite a primeira nota do aluno: ");
        scanf ("%f", &nota1);
        printf ("Digite a segunda nota do aluno: ");
        scanf ("%f", &nota2);
        printf ("Media do aluno: %.1f", media = (nota1 + nota2) / 2);
        if (media > 6) printf ("\nAluno aprovado\n\n");
        else 
else printf ("\nAluno reprovado\n\n");
        printf ("Digite a matricula do aluno:");
        scanf ("%d", &matricula);
        }
        printf ("FIM");
        return 0;
}           */