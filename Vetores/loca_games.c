/* SRAND

 3.Uma locadora  de jogos deseja  realizar uma promoção  na qual, para cada 10 jogos  retirados, o cliente tem direito a uma locação grátis.  
 Para realizar esta promoção entre seus 10 clientes, registrou no mês de setembro,  o número do cliente (valor entre 1 e 10),  dia da retirada  e quantidade de jogos retirados por ele 
 neste dia. O mesmo cliente pode realizar várias retiradas no mês de setembro.
  
 a) Faça um programa que implemente a promoção da locadora, mostrando na tela, a quantidade de
 locações gratuitas  que cada cliente tem direito. 
 
 Mostre, também, ao final, o número médio de retiradas por dia do mês, qual(is) o(s) dia(s)
com menor retirada.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXDIA 30
#define TAM 10

void preencheArray(int v[], int valor);
void processaLocacao(int vMes[], int vAlugado[], int ref);
void mediaLocacao(int vMes[]);
void menorDia(int vMes[]);

int main(void){
	int vMes[MAXDIA];
	int vAlugado[TAM];
	int diaMes = 1;
	
	srand(time(NULL));
	
	preencheArray(vAlugado, TAM);
	preencheArray(vMes, MAXDIA);
		
	while(diaMes <= MAXDIA){
		printf("Dia %i\n", diaMes);
		processaLocacao(vMes, vAlugado, diaMes);
		diaMes++;
	}
	
	printf("\n////////////////////////////////////////////////////////");
	printf("\n////////////////// DADOS ESTATÍSTICOS //////////////////");
	printf("\n////////////////////////////////////////////////////////\n\n");
	
	for(int i = 1; i <= TAM; i++){
		printf("Cliente %2i ... %2i Locações bônus\n", i, vAlugado[i-1]/10);
	}
	
	printf("\n");
	
	mediaLocacao(vMes);
	menorDia(vMes);

	
	return 0;
}

////////////////////////////////////////////////////////
///////////////// FUNÇÕES AUXILIARES ///////////////////
////////////////////////////////////////////////////////

void preencheArray(int v[], int valor){
	
	for(int i = 0; i < valor; i++){
		v[i] = 0;
	}
}

///////////////////////////////////////////////////////
void processaLocacao(int vMes[], int vAlugado[], int ref){
	int qtd = 1;
	int aleatorio, cliente, alugado;
	
	aleatorio = rand()%10; // Define quantas locações serão feitas no dia. Apenas para teste
	while(qtd <= aleatorio){
		cliente = (rand()%TAM) + 1;
		printf("Cliente %2i - ", cliente);
		alugado = (rand()%5) + 1;
		printf("Jogos alugados: %2i\n", alugado);
		vAlugado[cliente-1] += alugado;
		vMes[ref-1]+= alugado;
		qtd++;
	}
	qtd = 1;
		
	printf("\n");
}

///////////////////////////////////////////////////////
void mediaLocacao(int vMes[]){
	float media = 0;
	
	for(int i = 0; i < MAXDIA; i++){
		media += vMes[i];
	}
	media /= MAXDIA;
	printf("Média de locações no mês: %.1f\n", media);
}


void menorDia(int vMes[]){
	int minDia = -1;
	
	for(int i = 0; i < MAXDIA; i++){
		if(minDia == -1){
			minDia = vMes[i];
		}
		if(vMes[i] < minDia){
			minDia = vMes[i];
		}
	}
	printf("Menor locação: %i\n", minDia);
	printf("Dia(s) em que ocorreu: ");
	for(int i = 0; i < MAXDIA; i++){
		if(vMes[i] == minDia){
			printf("(%i) ", i+1);
		}
	}
	printf("\n\n");
}