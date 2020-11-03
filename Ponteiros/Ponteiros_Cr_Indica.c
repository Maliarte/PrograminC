/*1. Recomendam-se estudantes para bolsas de estudos em função de seu desempenho
anterior. A natureza das recomendações é baseada na seguinte tabela:
CR                     | Recomendação Mínima |   Recomendação Máxima

Maior ou igual a 9.0   |       30 %          |  TecCient 40% | Humanas 35%

Entre 8.0(inclusive)e 9|       10 %          |  TecCient 15% | Humanas 12%

Entre 7.0(inclusive)e 8|       5 %           | 5%

Menor que 7            |       0 %           | 0%

Para cada solicitante de bolsa há uma entrada com: matrícula, CR e número de
disciplinas cursadas. 

Faça um programa, utilizando as funções abaixo, que leia os
dados dos alunos solicitantes de bolsa e informe para os alunos o percentual
recomendado de bolsa. No final deve ser exibido a quantidade de alunos que
receberam bolsa, o percentual médio de bolsas, qual foi o maior percentual
fornecido (e DESAFIO: quantos alunos obtiveram este percentual)
Término da leitura: matrícula 0. 

O cálculo do percentual de bolsa é realizado de acordo com a seguinte fórmula:
Percentual de bolsa: percentual mínimo + 0,05*número de disciplinas cursadas
desde que não ultrapasse o máximo estabelecido na tabela acima

A matrícula tem a seguinte formação: NDXXX,
onde N: representa a área: 1 – Técnico Científico
 2 - Humanas
D: número entre 1 e 9, representando o curso na área
XXX : número sequencial entre 1 e 999

	 * A matrícula tem a seguinte formação: NDXXX,
	 * onde N: representa  a área:
	 * 1 – Técnico Científico
	 * 2 -  Humanas
	 * D:  número entre 1 e 9,  representando o curso na área
	 * XXX : número sequencial entre 1 e 999
	 
 */

#include <stdio.h>
void quebraMatr(int num, int*pArea, int*pCurso,int *pX){
   (*pArea) = num /10000;
   (*pCurso)= num/1000%10;
   (*pX)=num%10000;
  return ;
}
void fazRecomendacao(int area,float cr,int *rMin,int *rMax){

	if(cr >= 9.0){
		(*rMin) = 30;
		if(area == 1){
			(*rMax) = 40;
		}else{
			(*rMax) = 35;
		}

	}else{
		if(cr >= 8.0){
			(*rMin) = 10;
			if(area == 1){
				(*rMax) = 15;
			}else{
				(*rMax) = 12;
			}
		}else{
			if(cr >= 7.0){
				(*rMin) = (*rMax) = 5;
			}else{
				(*rMin) = (*rMax) = 0;
			}
		}
	}
}


int main (void){

	int matricula, nDisciplina, rMin, rMax, area,curso,x;
	float cr, bolsa;

	printf("Informe a matrícula ou zero para sair: ");
	scanf("%i", &matricula);
    //redundante todo valor quando zero em C retorna falso 
	while(matricula!=0){
		printf("Informe o CR: ");
		scanf("%f", &cr);
		printf("Informe o número de disciplinas cursadas: ");
		scanf("%i", &nDisciplina);
/*Lei de formação de uma string numerica*/
		quebraMatr(matricula,&area,&curso,&x);
		fazRecomendacao(area, cr, &rMin, &rMax);

		bolsa = rMin + (0.05 * nDisciplina);

		if(bolsa > rMax){
			bolsa = rMax;
		}
		printf("A bolsa terá um desconto de %.2f %%\n", bolsa);
		printf("Informe a próxima matrícula ou zero para sair: ");
		scanf("%i", &matricula);
	}// Fim do while

	return 0;
}