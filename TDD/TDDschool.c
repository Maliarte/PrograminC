/* Escreva um programa que leia do teclado as duas notas de um aluno, calcule e exiba a média aritmética das notas. O programa deve, adicionalmente, exibir uma mensagem de parabéns caso o aluno esteja aprovado (média superior ou igual a 6,0). 
 Altere o programa de modo que para ser aprovado um aluno tenha de ter média superior ou igual a 6,0 e nenhuma das duas notas inferior a 3,0. 
 Altere o programa do exercício 1.a de modo que um aluno aprovado seja convidado a ser monitor no próximo semestre caso sua média seja superior a 7.5. 
Altere o programa do exercício 1.a de modo que um aluno aprovado seja convidado a ser monitor no próximo semestre caso sua média seja superior a 7.5 e nenhuma de suas notas seja inferior a 7
Altere o programa do exercício 1.a de modo que um aluno aprovado seja convidado a ser monitor no próximo semestre caso sua média seja superior a 7.5 e pelo menos uma de suas notas seja superior a 9
Altere o programa 1.b para que leia do teclado as duas notas de um aluno e o seu número de faltas. O programa deve calcular e exibir a média aritmética das notas, além de exibir uma mensagem de parabéns caso o aluno esteja aprovado (média superior ou igual a 6,0 e número de faltas < 15). Caso esse aluno tenha sido aprovado com média superior a 7.5 ele deve ser convidado a ser monitor no próximo semestre.
Altere o programa 1.e para que exiba a situação do aluno: aprovado (média superior ou igual a 6,0 e número de faltas < 15) ou não aprovado (demais casos)*/
#include <stdio.h>
#include <locale.h>

int main(void) {
//declara variaveis
    float nota1, nota2, media;
    int faltas;
//configura linguagem pt br
    setlocale(LC_ALL, "portuguese"); 

// entrada  e saida
    printf("Informe a primeira nota: "); 
    scanf("%f", &nota1);
    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);
    printf("Insira faltas: ");
    scanf("%i", &faltas);

//processamento

    media = nota1+nota2/2;
    printf("A media do aluno é %f", media);

  /*  if  ( faltas < 15 && (media  >= 6 && nota1 >=3 && nota2>=3)){
        printf("Aluno aprovado. \n");
  //para convidar para monitoria e preciso ter sido aprovado, logo este if vem aninhado ao primeiro.
        if (media >=7.5 && nota1 >=7 && nota2>=7) {
            printf("Venha ser monitor!");
        } 
//sintaxe do if exige () 
        if ( faltas < 15 && media >=7.5 && (nota1 >=9 || nota2>=9)) {
            printf("Venha ser monitor!");
        }
        else
        {
            printf("Não está aprovado! \n");
        }*/

    //aprovados
if ( faltas < 15) {
            
            if (media >=6 && (nota1 >=3 || nota2>=3)) {
            printf("parabens!!");
                if ( media >=7.5 && (nota1 >=9 || nota2>=9)) {
            printf("Venha ser monitor!\n");
        }
    }
 }
            else {
                    if (media < 4) { 
                    printf("Reprovado por RM");
                        else {
                        printf("em final!");
                            }
                    
                    }
                 }
            
else
{
 printf("reprovado por faltas! \n");
}
  
return 0;

}