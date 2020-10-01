/* 
Marilia Silva eh Maliarte Brasil

Em uma eleição presidencial existem quatro candidatos. Os votos são informados através de códigos. Os dados utilizados para a contagem dos votos obedecem à seguinte codificação:
- 1,2,3,4 = voto para os respectivos candidatos; 
- 5 = voto nulo;
- 6 = voto em branco;
Construa um programa que leia o código do candidado em um voto. Calcule e escreva: - total de votos para cada candidato;
- total de votos nulos;
- total de votos em branco;
Como término do conjunto de votos, tem-se o valor 0.*/

#include <stdio.h>
#include <locale.h>
int main(void)
{
    int voto, cont1 = 0, acumVotoCA = 0, cont2 = 0, acumVotoCB = 0, cont3 = 0, acumVotoCC = 0, cont4 = 0, acumVotoCD = 0, cont5 = 0, acumVotoNulo = 0, cont6 = 0, acumVotoBranco = 0;

    setlocale(LC_ALL, "portuguese");

    printf("ELEICAO PRESIDENCIAL 2020\nDigite:\n1.Candidado A \n 2.Candidado B \n 3.Candidado C \n 4.Candidado D \n 5.VOTO NULO \n 6. VOTO BRANCO \n digite 0 para encerrar");
    scanf("%d", &voto);

    while (voto > 0)
    {
        if (voto == 1)
        {
            acumVotoCA = voto + 1;
            cont1++;
           
        }
        else if (voto == 2)
        {
            acumVotoCB = voto + 1;
            cont2++;
           
        }
        else if (voto == 3)
        {
            acumVotoCC = voto + 1;
            cont3++;
           
        }
        else if (voto == 4)
        {
            acumVotoCD = voto + 1;
            cont4++;
        
        }
        else if (voto == 5)
        {
            acumVotoNulo = voto + 1;
            cont5++;
            
        } else 
        {
                acumVotoBranco = voto + 1;
                cont6++;  
        }

    printf("~~~~ELEICAO PRESIDENCIAL~~~~\n1.Candidado A \n2.Candidado B \n3.Candidado C\n4.Candidado D\n5.NULO\n6. VOTO BRANCO \nou 0 para encerrar.  ");
    scanf("%d", &voto);
    }
    if (voto == 0) {
    printf("Foram computados os seguintes dados:\nVotos Brancos: %d; \nCandidado A:  %d; \nCandidado B: %d;\nCandidado C: %d;\nCandidado D: %d; \nVotos Nulos: %d; ",cont6,cont1,cont2,cont3,cont4, cont5);

    }



        return 0;
}