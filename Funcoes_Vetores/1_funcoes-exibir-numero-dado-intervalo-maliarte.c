/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	Data: 01/09/2021
	
	Revisão: funções
	
	Exemplo 1: desenvolver uma função que exiba os números de 1 a 1000

    Para exibir uma função que tenha o limite definido à 1000, deve-se inserir o operador lógico '<=" à operação.
*/
//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void exibirNum()
{
    int i;
    for (i = 1; i <= 1000; i++)
    {
        printf("%d\n", i);
    }
}
//main
void main()
{
    exibirNum();
}