/*
 * Nome: Gilmar Ribeiro Santana
 * Turma: A
 * Turno: Noite
 * Questão 1
 * 
 * 1.Um atelier deseja cobrir todas as faces de caixas retangulares com 
 * retângulos de cartolina colorida. Faça um programa, utilizando 
 * obrigatoriamente as funções abaixo, que capture a altura, largura e 
 * comprimento da caixa e a largura e comprimento do retângulo de cartolina, 
 * calculando e exibindo a quantidade necessária de retângulos de cartolina 
 * para cobrir todas as faces da caixa.

 a) calcula_area: Recebe as medidas dos lados de um retângulo e retorna a 
 * área do mesmo. Obs.: Toda área neste programa tem que ser calculada 
 * usando esta função.

 b) calcula_quantidadeLado; Recebe  a área de um lado da caixa e a área do 
 * retângulo de cartolina, retorna a quantidade de retângulos de cartolina 
 * necessários para preenchê-lo. Lembre-se que não é possível retornar uma 
 * quantidade fracionada de retângulos

 c) calcula_quantidadeCaixa; Recebe as 3 dimensões da caixa e a área dos 
 * retângulos de cartolina e retorna a quantidade necessária de retângulos 
 * de cartolina para cobrir todas as faces da caixa.
 * 
 * 
 */
 
 #include <stdio.h>
 int calculaArea(int lado1, int lado2);
 int calculaQuantidadeLado(int valorCaixa, int valorCartolina);
 int calculaQuantidadeCaixa(int a1Caixa, int a2Caixa, int a3Caixa, int aCartolina);
 
 
 int main(){
	 int caixaAltura, caixaLargura, caixaComprimento, area1, area2, area3;
	 int l1Cartolina, l2Cartolina, areaCartolina, lA, lB, lE;
	 int totalCaixa;

	 
	 printf("Informe a altura da caixa: ");
	 scanf("%i", &caixaAltura);
	 printf("Informe a largura da caixa: ");
	 scanf("%i", &caixaLargura);
	 printf("Informe o comprimento da caixa: ");
	 scanf("%i", &caixaComprimento);
	 area1 = calculaArea(caixaAltura, caixaLargura);
	 area2 = calculaArea(caixaAltura, caixaComprimento);
	 area3 = calculaArea(caixaLargura, caixaComprimento);
	 printf("Informe a largura da cartolina: ");
	 scanf("%i", &l1Cartolina);
	 printf("Informe o comprimento da cartolina: ");
	 scanf("%i", &l2Cartolina);
	 areaCartolina = calculaArea(l1Cartolina, l2Cartolina);
	 lA = calculaQuantidadeLado(area1, areaCartolina);
	 lB = calculaQuantidadeLado(area2, areaCartolina);
	 lE = calculaQuantidadeLado(area3, areaCartolina);
	 printf("Faces da caixa\n"); 
	 printf("Face A = Face C = %i quadrados de cartolina\n", lA);
	 printf("Face B = Face D = %i quadrados de cartolina\n", lB);
	 printf("Face E = Face F = %i quadrados de cartolina\n", lE);
	 
	 totalCaixa = calculaQuantidadeCaixa(area1, area2, area3, areaCartolina);
	 printf("\nA caixa precisará de %i retangulos de cartolina\n", totalCaixa);
	 
	return 0;
 }
 
   

 int calculaArea(int lado1, int lado2){
	 int area = lado1 * lado2;
	 return area;
 }
 
 int calculaQuantidadeLado(int valorCaixa, int valorCartolina){
	 int quantidade;
	 quantidade = valorCaixa / valorCartolina;
	 if(valorCaixa % valorCartolina != 0){
		 quantidade = quantidade + 1;
	 }
	 
	 return quantidade;
 }
 
 int calculaQuantidadeCaixa(int a1Caixa, int a2Caixa, int a3Caixa, int aCartolina){
	 int retangulo;
	 
	 retangulo = (a1Caixa*2)+(a2Caixa*2)+(a3Caixa*2);
	 retangulo = retangulo / aCartolina;;
	 if(retangulo % aCartolina != 0){
		 retangulo = retangulo + 1;
	 }
	 	 
	 return retangulo;
 }


************************************************************************************
************************************************************************************
************************************************************************************

/*
 * Nome: Gilmar Ribeiro Santana
 * Turma: A
 * Turno: Noite
 * Questão 2
 * 
 * 2.Uma loja oferece um bônus para seus clientes no ato de uma compra. 
 * O valor desse bônus depende do valor da última compra (uc) do cliente 
 * e de quando esta compra foi realizada. A regra para o cálculo do bônus 
 * é a seguinte:
 * •	Se uc realizada há no máximo 3 meses, o valor do bônus será igual 
 * a 20% do valor da uc;
 * •	Se uc realizada entre 4 e 6 meses atrás, o valor do bônus será 
 * igual a 10% do valor da uc;
 * •	Se uc realizada há mais de 6 meses, o valor do bônus será igual 
 * a 5% do valor da uc.
 * 
 * Observação: Caso o valor do bônus seja maior do que o valor da compra atual,
 * o valor a ser pago será igual a zero.
 * Escreva um programa que leia o valor da compra atual, o valor da última 
 * compra e há quantos meses essa compra foi realizada, e exiba o valor 
 * que será efetivamente pago pelo cliente, com duas casas decimais. 
 * O seu programa deverá usar, obrigatoriamente, as funções bonusCliente 
 * e calculaValorComBonus, que serão implementadas por você.
 * 
 * A função bonusCliente receberá como parâmetros o valor da última compra 
 * e há quantos meses ela foi realizada, e retornará o valor do bônus.
 * 
 * A função calculaValorComBonus receberá como parâmetros o valor da última 
 * compra, há quantos meses ela foi realizada e o valor da compra atual, 
 * e retornará o valor a ser efetivamente pago pelo cliente, que será igual 
 * ao valor da compra atual menos o valor do bônus. 
 * 
 * A função calculaValorComBonus terá de chamar a função bonusCliente para 
 * realizar o cálculo do valor a ser pago.
 * 
 */

#include <stdio.h>

float bonusCliente(float valor, int periodo);
float calculaValorComBonus(float valor1, int parametro, float valor2);

int main(){
	float uc, compAtual,vlComBonus, finalCompra;
	int mesCompra;
	
	printf("informe o valor da compra atual: ");
	scanf("%f", &compAtual);
	printf("informe o valor da última compra: ");
	scanf("%f", &uc);
	printf("Há quantos meses foi sua última compra? ");
	scanf("%i", &mesCompra);
	vlComBonus = calculaValorComBonus(uc, mesCompra, compAtual);
	
	if(vlComBonus > compAtual){
		finalCompra = 0;
	}else{
		finalCompra = vlComBonus;
	}
	
	printf("Valor a pagar ..... R$ %.2f\n", finalCompra);
	
	return 0;
}


float bonusCliente(float valor, int periodo){
	float bonus;
	if(periodo <= 3){
		bonus = valor * (20/100.00);
	}else{
		if(periodo <= 6){
			bonus = valor * (10/100.00);
		}else{
			bonus = valor * (5/100.00);
		}
	}
	return bonus;
}

float calculaValorComBonus(float valor1, int parametro, float valor2){
	float valor, bonus;
	
	bonus = bonusCliente(valor1, parametro);
	printf("Bonus = %.2f\n", bonus);
	valor = valor2 - bonus;
	
	return valor;
}


************************************************************************************
************************************************************************************
************************************************************************************

/*
 * Nome: Gilmar Ribeiro Santana
 * Turma: A
 * Turno: Noite
 * Questão 3
 * 
 * 3.Faça um programa que gere uma quantidade indeterminada de valores 
 * entre 1 e 90. Para cada valor gerado o programa deve mostrar seus divisores. 
 * Ao final, deve ser exibido:
 * Média dos valores pares
 * Maior valor ímpar gerado
 * Percentual de valores pares múltiplos de 5
 * Término da geração de valores:  número gerado é múltiplo de 30
 * 
 * 
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int num,fator, maxImpar=-1, contNum=0, contPar=0, acumPar=0, cont5=0;
	float pCento5, mediaPar;
	fator = 1;
	srand(time(NULL));
	num = rand()%90 + 1;
	
	while(num != 30){
		while(fator <= num){
			if(num % fator == 0){
				printf("%i é divisível por %i\n", num, fator);
			}
			fator++;
		}
		if(num % 2 == 0){
			contPar++;
			acumPar+=num;
			if(num % 5 == 0){
				cont5++;	
			}
		}else{
			if(num > maxImpar){
				maxImpar = num;
			}		
		}
		fator = 1;
		contNum++;
		num = rand()%90 + 1;
	}
	mediaPar = acumPar / contPar * 1.00;
	pCento5 = (100.00*cont5)/contNum;
	printf("Média dos valores pares = %.2f\n", mediaPar);
	printf("Maior valor ímpar = %i\n", maxImpar);
	printf("Percentual de valores pares múltiplos de cinco = %.2f%%\n", pCento5);
	
	return 0;
}

