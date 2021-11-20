/* Três copos de água de 200ml em temperaturas diferentes foram misturados em um recipiente isolado e, após certo tempo, alcançaram o equilíbrio térmico (média aritmética das 3 temperaturas).
a) Faça uma função que recebe como parâmetros o equilíbrio térmico e a temperatura de um dos copos de água e retorna a diferença entre o equilíbrio térmico e a temperatura do copo. Seu protótipo é:
float calcula_diferenca(float equil, float temp);

b) Faça uma função que recebe como parâmetros um valor inteiro representando o número do copo e um valor real representando a diferença entre o equilíbrio térmico e a temperatura do copo e mostra na tela uma das 3 mensagens abaixo. Seu protótipo é:
void exibe_mensagem(int copo, float difer);

Mensagens possíveis:
“A água do copo Nº DO COPO perdeu X graus” 🡪 caso tenha cedido calor aos demais
“A água do copo Nº DO COPO ganhou X graus” 🡪 caso tenha recebido calor dos demais
“A água do copo Nº DO COPO manteve sua temperatura” 🡪 caso a temperatura do copo lida seja igual ao equilíbrio térmico.

Observação: se a diferença entre o equilíbrio térmico e a temperatura do copo for positiva, a água deste copo recebeu calor; se for negativa, a água deste copo cedeu calor; se for nula, a água deste copo não recebeu nem cedeu calor.

c) Faça um programa que leia a temperatura da água de cada copo, calcule o equilíbrio térmico (média aritmética das 3 temperaturas) e exiba, para cada copo, uma das 3 mensagens acima.


Desenvolvimento Marília Silva  */

#include <stdio.h>
#include <locale.h>


void exibe_mensagemA(int copo, float difeA);{ 
   copoA = 1;
    printf("A água do copo %d perdeu x graus", copoA, difeA); 
    /*caso tenha cedido calor aos demais*/
   /* printf("A água do copo %d ganhou X graus"); 
    caso tenha recebido calor dos demais
    printf("A água do copo %d manteve sua temperatura") 
    caso a temperatura do copo lida seja igual ao equilíbrio térmico.*/
return;

}

/*void exibe_mensagemA(int copo, float difeB);
void exibe_mensagemA(int copo, float difeC);*/


float calcula_diferencaC(float equil, float tempC) {
    float  difC;
    difC = (equil - tempC);
    return difC;
   
}
float calcula_diferencaB(float equil, float tempB) {
    float  difB;
    difB = (equil - tempB);
    return difB;
   
}

float calcula_diferencaA(float equil, float tempA) {
    float  difA;
    difA = (equil - tempA);
    return difA ;
}
int main () {

float tempA, tempB, tempC, equil, difeA, difeB, difeC, cedeA;
//int copo;
setlocale(LC_ALL,"portuguese");

    printf("Entre com a temperatura do Copo A(200ml): \n");
    scanf("%f", &tempA);
    printf("Entre com a temperatura do Copo B(200ml): \n");
    scanf("%f", &tempB);
    printf("Entre com a temperatura do Copo C:(200ml) \n");
    scanf("%f", &tempC);
    equil = (tempA + tempB +tempC)/3 ;
    difeA = calcula_diferencaA(equil, tempA);
    difeB = calcula_diferencaB(equil, tempB);
    difeC = calcula_diferencaC(equil, tempC);

    printf("\nEquilibrio termico eh atingido em %.1f graus.\nEquilibrio Termico x Temperatura |COPO A: %.2f graus|COPO B: %.2f graus|COPO C: %.2f graus\n", equil, difeA, difeB,difeC);

    if (tempA > tempB)  {
        cedeA = exibe_mensagemA(copo, difeA);
    }
    
    /*exibe_mensagem(copo = 2,difeB);
    exibe_mensagem(copo = 3,difeC);*/
    
    
return 0;


}

/*Faça um programa que gere uma quantidade indeterminada de valores entre 1 e 90 (num). Para cada valor gerado o programa deve mostrar os valores múltiplos de 3 entre 1 e num. Caso não haja um múltiplo de 3 no intervalo [1,num], escrever a mensagem” Não há múltiplos de 3 no intervalo”.
 Ao final, deve ser exibido:
Soma dos valores pares
Maior valor múltiplo de 7 gerado
Percentual de números ímpares
Término da geração de valores:  número gerado é múltiplo de 25 

Incomplete


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int num,fator, maxImpar=-1, contNum=0, contImpar=0, acumImpar=0;
	float pCentoImp, somaPar;
	fator = 1;
	srand(time(NULL));
	num = rand()%90 + 1;
	
	while(num != 25){
		while(fator <= num){
			if(num % fator == 0){
				printf("%i eh multiplo de 3\n", num);
			}
			fator++;
		}
		if(num % 2 == 1){
			contImpar++;
			acumImpar+=num;
				
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
	somaPar = acumPar / contPar * 1.00;
	perCentoImpar = (100.00*maxImpar)/contNum;
	printf("Soma dos valores pares %.2f\n", somaPar);
	printf("Percentual Impar = %i\n", perCentoImpar);
	
	
	return 0;
}

*/



