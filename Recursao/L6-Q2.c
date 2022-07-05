					
/*
Data: 28/10/2021
Lista de Exercícios VI

Questão 02: Desenvolver uma função recursiva que exiba todos os múltiplos do número N,
inferiores ou iguais ao valor V.

Exemplo:
N = 5 e V = 34
Resposta: 0, 5, 10, 15, 20, 25, 30


----

x = funcao (32,6);	1+1+1+1+1+0 = 5		Retorna o valor de A / B (divisão inteira)					
A=32, B=6								

	1 + funcao (26,6);	1+1+1+1+0						   
	A=26, B=6							   
   
		1 + funcao (20,6);	1+1+1+0					
		A=20, B=6						   
			1 + funcao (14,6);	1+1+0				   
			A=14, B=6					  
				1 + funcao (8,6);	1+0			      
				A=8, B=6				   
					1 + funcao (2,6);	0		
					A=2, B=6			


*/




//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibirMultiplos (int N, int V);

//função main
void main ()
{
	exibirMultiplos (5, 34);
}
									
												//versão iterativa
						/*
							void exibirMultiplos (int N, int V)
							{
										//declaração de variáveis
										int i;

								//variando os números do intervalo de 0 a N
								for (i=0;i<=V;i++)
								{
									//verificando se cada valor do intervalo é múltiplo de N
									if (i%N==0)
									{
										printf ("%d ", i);
									}
								}
							}*/
//versão recursiva
void exibirMultiplos (int N, int V)
{
	if (V >= 0) //caso geral
	{
		exibirMultiplos (N, V-1); //nesta posição, mostra-se os números em ordem crescente
		if (V%N==0)
		{
			printf ("%d ", V);
		}
			//exibirMultiplos (N, V-1); //nesta posiçao mostra-se os números em ordem decrescente
	}
			//else //caso base: V < 0 (implícito)
			//{
			//}
}