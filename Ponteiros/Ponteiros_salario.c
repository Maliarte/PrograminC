/* A empresa XPTO possui as seguintes informações dos seus departamentos:  
Código do departamento (inteiro); 
Quantidade de funcionários do departamento (inteiro);  
Para cada funcionário do departamento:
* Matrícula (inteiro);
* Quantidade de dependentes (inteiro);
* Salário (real).

a)Faça a função um_departamento que receba como parâmetros a quantidade (n) de
funcionários do departamento e dois ponteiros para inteiro. Esta função deverá ler os
dados dos n funcionários do departamento e armazenar, nas variáveis cujos endereços são
fornecidos na chamada da função, a quantidade de funcionários com até 5 dependentes
que ganham mais de 5000,00 e a quantidade de funcionários com mais de 5 dependentes
que ganham mais de 5000,00.
Protótipo da função:
void um_departamento (int n, int *qtate5, int *qtacima);

entrada: quantidade (n) de
funcionários do departamento

b) Faça um programa que leia os dados dos departamentos ( término nº do departamento ==
0) e, utilizando a função acima, exiba a quantidade de funcionários com até 5 dependentes
que ganham mais de 5000,00 e a quantidade de funcionários com mais de 5 dependentes
que ganham mais de 5000,00. 
*/




#include <stdio.h>

int qtd_5_Dpt, qtd_Acima,  matr, qtdDepen,  qtdFun=0;
float sal;

void um_departamento (int qtdFun, int *qtd_5_Dpt, int *qtd_Acima);
  printf ("Informe a Matrícula: ");
  scanf("%d", &matr);
  while(matricula!=0){
  qtdFun++;
		printf("Quantidade de dependentes: ");
		scanf("%d", &qtdDepen);
		printf("Informe o Salário R$: ");
		scanf("%f", &sal);
      if (qtd_Depen <= 5 && sal > 5.000) {
                  qtd_5_Dpt =+ qtd_5_Dpt + 1;
      } else if (qtd_Depen > 5 && sal > 5.000) {
                  qtd_Acima =+ qtd_Acima + 1
          }
return;


int main(void) {
 int codDpt, qtdFun;
 

 printf("Entre com o Número do Departamento ou digite 0 para Encerrar \n ");
 scanf("%i", &codDpt);
 while(codDpt!=0){
	
um_departamento(qtdFun, *pt1, *pt2)
printf("\n O Nº de Funcionarios que ganha mais do que R$ 5.000,00 com até 5 dependentes é: \n %d", *pt1);
printf("\n O Nº de Funcionarios que ganha mais do que R$ 5.000,00 com + 5 dependentes é: \n %d", *pt2);


  return 0;
}