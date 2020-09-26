/* Um professor, sabendo que a dose diária de água é individual,resolveu calcular a quantidade mínima de litros de água que deve ser ingerida  por cada um dos seus n (lido) alunos de uma turma.
Esta medida é calculada por:
 	litros de água/dia  =  35ml de água  * peso corporal/1000
Faça um programa que inicialmente  obtenha a quantidade  de alunos da turma (n).  A seguir, para cada um dos alunos, obtenha o  peso  e mostre a quantidade mínima de litros que o aluno deve consumir.

Modifique o programa para processar as m (perguntado ao usuário) turmas do professor */
#include<stdio.h>
#include<locale.h>
int main (void){
 
    int alunos, x = 0;
    float peso, litrosPorDia;
     
    printf ("Digite a quantidade de alunos na sala: ");
    scanf ("%d", &alunos);   
    
    while (x < alunos) {
        printf ("\nDigite o peso do aluno: ");
        scanf ("%f", &peso);
        litrosPorDia = 35 * (peso/1000) ;
        (int)litrosPordia%1000
        printf ("\nQuantida de litros por dia necessaria: %.3f l\n", litrosPorDia);
       
        x = x+1;
    }
    return 0;
}