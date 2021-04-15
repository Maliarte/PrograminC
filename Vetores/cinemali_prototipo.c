/* 1. Devido ao afastamento social em decorrência da pandemia, a sessão de Cinema "Maliarte conta +1História" 
 * optou por oferecer conforto e segurança aos seus assinantes.
Para isso disponibilizou o  dowload de filmes. 

O acervo conta com  10 obras, com as seguintes informações:

Numero  do Filme:  110, 120, 130, 140, 150, 160, 170, 180, 190, 200
com os seguintes títulos:

* 110 - O cachorro Muito Louco 
* 120 - Operação Storm
* 130 - Aranha da Janela
* 140 - Entre santos e desencantos 
* 150 - As estrelas tambem morrem, todavia não fazem upload
* 160 - Raspadinha 
* 170 - Matrix 
* 180 - Sempre tem um 
* 190 - Pedra Lascada 
* 200- Fome Castiga

* Escreva um programa que mediante a inserção do título o usuário informa a origem do conhecimento do mesmo:

* 1) Indicação da plataforma;
* 2) Outra origem;

* 
* 
* Após isso, registre: 
* a quantidade de downloads de cada título.
*
* O relatório final do programa deve: 
* a)exibir o título mais baixado (desconsidere empates) e o título menos baixado (no  vetor acumulador);
* b)exiba a quantidade de filmes que foram baixados com indicação da plataforma (no vetor plataforma);
* c) e de outra forma (no vetor outro);


*/

#include <stdio.h>

#define TAM 10

void preencheVetor(int vetor[], int valor);
int valida(int referencia);
void exibe(int vAcumulador[]);
void moldura();

int main(void){
	int vFilme[TAM] = {110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
	int vPlataforma[TAM];
	int vOutro[TAM];
	int vAcumulador[TAM];
	
	int login;
	int indicacao;

	int cod;
	int pos;
	////
	int download,maior,menor;
  int i;
	
	preencheVetor(vPlataforma, 0);
	preencheVetor(vOutro, 0);
	preencheVetor(vAcumulador, 0);
	moldura();
	printf("Digite o login ou 0 para sair:\n");
  moldura();
	scanf("%i", &login);
	
	while(login > 0){
		cod = valida(1);
		
		pos = (cod / 10) - 11; //define padrão math para acesso direto
		
		indicacao = valida(2);
		
		if(indicacao == 1){
			vPlataforma[pos]++;
		}       else{
			            vOutro[pos]++;
		        }
		
		vAcumulador[pos]++;
		
		moldura();
		printf("\nDigite o login ou 0 para sair:\n");
		scanf("%i", &login);
    moldura();
	}
	
	
/*	
	for(int i = 0; i < TAM; i++){
		printf("Filme %d\n", vFilme[i]);
	}
	
	for(int i = 0; i < TAM; i++){
		printf("Plataforma %d\n", vPlataforma[i]);
	}
	
	for(int i = 0; i < TAM; i++){
		printf("outro %d\n", vOutro[i]);
	}
	
	for(int i = 0; i < TAM; i++){
		printf("Acumulador %d\n", vAcumulador[i]);
	}
*/

//////////// qtd dowload de cada título, tenho variavel cod que armazena o cod do filme que o usuario deseja preciso relacionar com o vFilme?



for(i = 0 ; i < TAM; i++) {
  download += vAcumulador[i];
}
exibe(vAcumulador);   

///////////////////////Throne/////////////////////

maior = vAcumulador[0]; //inicializa variavel maior com 1ºvalor do vetor
//logo controler começa da proxima posição do vetor
      for ( i=1; i<TAM; i++) {
            if (vAcumulador[i] > maior) {
            maior = vAcumulador[i]; //substitui
            }
            pos = vAcumulador[i]++;
      }
                                      //exibe//
       printf("\n||Maior: %d||\n| HIT: %d", maior, pos);
///////////////Menor download/////////////////////
menor = vAcumulador[0]; //inicializa variavel menor com 1ºvalor do vetor

//logo controler começa da proxima posição do vetor
      for ( i=1; i<TAM; i++) {
            if (vAcumulador[i] < menor) {
            menor = vAcumulador[i]; //substitui
            }
            pos = vAcumulador[i]++;
      }
                                      //exibe//

       printf("\n||Menor: %d||\n| MISS: %d", menor, pos);
      
	
  
  
  
  
  
  
  
  
  
  return 0;





}/////////////////////// FIM MAIN/////////////////////








/////////////////////////////////////////////////////////////
void preencheVetor(int vetor[], int valor){
	
	for(int i = 0; i < TAM; i++){
		
		vetor[i] = valor;
	}

}
/////////////////////////////////////////////////////////////
int valida(int referencia){
	int cod;
	int indicacao;
	int valor;
	
	if(referencia == 1){// valida codigo do filme
    moldura();
		printf("Informe o código do filme:\n110 - O cachorro Muito Louco \n120 - Operação Storm\n130 - Aranha da Janela\n140 - Entre santos e desencantos \n150 - As estrelas tambem morrem, todavia não fazem upload\n160 - Raspadinha \n170 - Matrix \n180 - Sempre tem um \n190 - Pedra Lascada \n200 - Fome Castiga\n");
    moldura();
		scanf("%i", &cod);
		while( (cod < 110 || cod > 200) || cod%10 != 0){
      moldura();
			printf("Digitação Inválida. Confirme o valor e tente novamente.");
			printf("Informe o código do filme:\n110 - O cachorro Muito Louco \n120 - Operação Storm\n130 - Aranha da Janela\n140 - Entre santos e desencantos \n150 - As estrelas tambem morrem, todavia não fazem upload\n160 - Raspadinha \n170 - Matrix \n180 - Sempre tem um \n190 - Pedra Lascada \n200 - Fome Castiga\n");
      moldura();
			scanf("%i", &cod);
		}
		valor = cod;
	}else{// valida indicacao
  moldura();
		printf("Informe a origem da indicação:\n");
		printf("1 - plataforma\n");
		printf("2 - outro\n");
  moldura();
		scanf("%i", &indicacao);
		while(indicacao < 1 || indicacao > 2){
      moldura();
			printf("Digitação Inválida. Tente novamente.");
      moldura();
			printf("Informe a origem da indicação:\n");
			printf("1 - plataforma\n");
			printf("2 - outro\n");
      moldura();
			scanf("%i", &indicacao);
		}
		valor = indicacao;
	}
	
	return valor;
}
/////////////////////////////////////////////////////////////

void exibe(int vAcumulador[]){
    printf("=======RELATÓRIO DOWNLOAD FILMES:========\n");
    printf("110 - O cachorro Muito Louco    | %d download.\n", vAcumulador[0]);
    printf("120 - Operação Storm            | %d download.\n", vAcumulador[1]);
    printf("130 - Aranha da Janela          | %d download.\n", vAcumulador[2]);
    printf("140 - Entre santos e desencantos| %d download.\n", vAcumulador[3]);
    printf("150 - As estrelas tambem morrem | %d download.\n", vAcumulador[4]);
    printf("160 - Raspadinha                | %d download.\n", vAcumulador[5]);
    printf("170 - Matrix                    | %d download.\n", vAcumulador[6]);
    printf("180 - Sempre tem um             | %d download.\n", vAcumulador[7]);
    printf("190 - Pedra Lascada             | %d download.\n", vAcumulador[8]);
    printf("200- Fome Castiga               | %d download.\n", vAcumulador[9]);
    printf("==========================================\n");
}

//////////////////////// moldura////

void moldura(){
  printf("===============");
  printf("===============");
  printf("===============\n");
}