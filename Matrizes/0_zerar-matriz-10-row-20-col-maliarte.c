/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @barbarostecnologicos!
    
	MATRIZES
	
	Exemplo 1: desenvolver um programa que zere todas as posições de uma matriz M10x20.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 10
#define C 20

//main
void main ()
{
	//declaração da matriz
	int m[L][C];
	
	//zerando a matriz
	for (i=0;i<L;i++)		//variando as linhas
	{
		for (j=0;j<C;j++)	//variando as colunas
		{
			m[i][j] = 0;
		}
	}
}
