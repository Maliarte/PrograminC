/*Um professor, sabendo que a dose diária de água é individual,resolveu calcular a
quantidade mínima de litros de água que deve ser ingerida por cada um dos alunos de uma turma. Esta medida é calculada por:
º litros de água/dia = 35ml de água * peso corporal/1000

A seguir, para cada um dos alunos, obtenha o peso e mostre a quantidade mínima de litros
que o aluno deve consumir. Término da entrada de dados: peso<=0
Seu programa deve responder:

V1- Quantos alunos desta turma ingerem menos de 2 L de água?

#include <stdio.h>
#include <locale.h>

int main(void){
    int i = 0;
    float peso, litrosPorDia;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o peso do aluno ou zero para sair: ");
    scanf("%f", &peso);
    while (peso > 0){
        litrosPorDia = 35 * (peso / 1000);
        printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
        if (litrosPorDia <= 1.9) i = i + 1;
        printf("Digite o peso do próximo aluno ou zero para sair: ");
        scanf("%f", &peso);
    }
    printf("\n\nNúmero de alunos que ingerem menos de 2L por dia igual a %d", i);
    return 0;
} 

//v2 - Qual o percentual de alunos desta turma que ingerem menos de 2L?
//conta2L*100/número de alunos (n)

#include <stdio.h>
#include <locale.h>

int main(void){
    int i = 0, numAlunos = 0, percentual;
    float peso, litrosPorDia;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o peso do aluno ou zero para sair: ");
    scanf("%f", &peso);
    while (peso > 0){
        litrosPorDia = 35 * (peso / 1000);
        printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
        if (litrosPorDia <= 1.9) i = i + 1;
        printf("Digite o peso do próximo aluno ou zero para sair: ");
        scanf("%f", &peso);
        numAlunos = numAlunos + 1;
    }
    percentual = (i * 100) / numAlunos;
    printf("\n\nPercentual de alunos que ingerem menos de 2L por dia igual a %d%%", percentual);
    return 0;
}
/*
// V3- Qual o total de litros de água consumidos pela turma?

#include <stdio.h>
#include <locale.h>

int main(void){
    float peso, litrosPorDia, soma = 0;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o peso do aluno ou zero para sair: ");
    scanf("%f", &peso);
    while (peso > 0){
        litrosPorDia = 35 * (peso / 1000);
        printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
        soma = soma + litrosPorDia;
        printf("Digite o peso do próximo aluno ou zero para sair: ");
        scanf("%f", &peso);
    }
    printf("\n\nTotal de água a ser consumida igual a %.1f", soma);
    return 0;
}


//V4- Qual a quantidade média de litros de água por aluno nesta turma?

#include <stdio.h>
#include <locale.h>

int main(void){
    int i=0;
    float peso, litrosPorDia, soma = 0, media;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o peso do aluno ou zero para sair: ");
    scanf("%f", &peso);
    while (peso > 0){
        litrosPorDia = 35 * (peso / 1000);
        printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
        soma = soma + litrosPorDia;
        printf("Digite o peso do próximo aluno ou zero para sair: ");
        scanf("%f", &peso);
        i = i + 1;
    }
    media = soma / i;
    printf("\n\nQuantidade média de litros de água por aluno igual a %.1fL", media);
    return 0;
}

//V5- Qual o peso médio dos alunos desta turma que consomem mais que 3l?
//soma dos pesos que consomem mais que 3l/qt de alunos que consomem mais que 3l

#include <stdio.h>
#include <locale.h>

int main(void){
    int i = 0;
    float peso, litrosPorDia, soma = 0, media;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o peso do aluno ou zero para sair: ");
    scanf("%f", &peso);
    while (peso > 0){
        litrosPorDia = 35 * (peso / 1000);
        printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
        if (litrosPorDia > 3){
            i = i + 1;
            soma = soma + peso;
            media = soma / i;
        }
        printf("Digite o peso do próximo aluno ou zero para sair: ");
        scanf("%f", &peso);
    }
    printf("\n\nPeso médio dos alunos desta turma que consomem mais que 3L igual a %.1f Kg.", media);
    return 0;
}

//V6 - Considere 3 turmas de alunos deste professor//repetir 3 x o processamento de uma turma

#include <stdio.h>
#include <locale.h>

int main(void){
    int i = 0, cont = 1;
    float peso, litrosPorDia;
    setlocale(LC_ALL, "Portuguese");

    while (cont <= 3){
        printf("\n%dª TURMA\n", cont);
        printf("Digite o peso do aluno ou zero para ir para a proxima turma: ");
        scanf("%f", &peso);
        while (peso > 0){
            litrosPorDia = 35 * (peso / 1000);
            printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
            if (litrosPorDia <= 1.9)
                i = i + 1;
            printf("Digite o peso do próximo aluno ou zero para ir para proxima turma: ");
            scanf("%f", &peso);
        }
        cont = cont + 1;
    }
    printf("\n\nNúmero de alunos que ingerem menos de 2L por dia igual a %d", i);
    return 0;
}

//V7 - Qual o total de litros ingeridos pelas turmas deste professor?
//totLitros da Turma 1 + totLitros da Turma 2 + totLitros da Turma 3

#include <stdio.h>
#include <locale.h>

int main(void){
    int cont = 1;
    float peso, litrosPorDia, soma;
    setlocale(LC_ALL, "Portuguese");

    while (cont <= 3){
        printf("\n%dª TURMA\n", cont);
        printf("Digite o peso do aluno ou zero para ir para a proxima turma: ");
        scanf("%f", &peso);
        while (peso > 0){
            litrosPorDia = 35 * (peso / 1000);
            printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
            soma = soma + litrosPorDia;
            printf("Digite o peso do próximo aluno ou zero para ir para proxima turma: ");
            scanf("%f", &peso);
        }
        cont = cont + 1;
    }
    printf("\n\nTotal de litros ingeridos pelas turmas igual a %.1fL", soma);
    return 0;
}


//V8 - DESAFIO: Qual a maior quantidade individual ingerida em cada turma?

#include <stdio.h>
#include <locale.h>

int main(void){
    int cont = 1;
    float peso, litrosPorDia, menorQuant=1000;
    setlocale(LC_ALL, "Portuguese");

    while (cont <= 3){
        printf("\n%dª TURMA\n", cont);
        printf("Digite o peso do aluno ou zero para ir para a proxima turma: ");
        scanf("%f", &peso);
        while (peso > 0){
            litrosPorDia = 35 * (peso / 1000);
            printf("Quantidade de litros/dia necessária: %.1fL\n\n", litrosPorDia);
            if (litrosPorDia < menorQuant) menorQuant = litrosPorDia; 
            printf("Digite o peso do próximo aluno ou zero para ir para proxima turma: ");
            scanf("%f", &peso);
        } 
        printf ("Menor quantidade ingerida na turma igual a %.1f\n\n", menorQuant);
        menorQuant = 1000;
        cont = cont + 1;    
    }
    return 0;
} */