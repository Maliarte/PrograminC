/* 
Dado o programa abaixo, pede-se avaliar a
sua execução e, ao final, informar o valor que
é exibido. Para isto, é obrigatório apresentar
o passo a passo de sua execução, com a
sequência de chamadas à função, assim
como o valor retornado por cada uma delas.




*/

#include <stdio.h>
int funcao(int a, int b)
{
    if (a > 0) //caso geral
    {
        if (a > b)
        {
            return funcao(a - 1, b + 2) + funcao(b - a, b);
        }
        else
        {
            return funcao(a - 2, b);
        }
    }
    else //caso base explícito
    {
        return b;
    }
}
void main()
{
    printf("Resposta = %d", funcao(10, 5));
}

/* 

				                main:	funcao (10, 5)	16 + 5 = 21			
					                            a=10; b=5				
									
	9 + 7 = 16	funcao (10-1,5+2)			+			                    funcao (5-10,5)	5
		a=9; b=7						                                    a=-5; b=5	
									
9	                funcao (9-1,7+2)	+	funcao (7-9,7)	7					
	                        a=8; b=9		a=-2; b=7						
									
9	funcao (8-2,9)								
	a=6; b=9								
									
9	funcao (6-2,9)								
	a=4; b=9								
									
9	funcao (4-2,9)								
	a=2; b=9								
									
9	funcao (2-2,9)								
	a=0; b=9					


    logo (a = 16) + (b = 5) = 21				

 */