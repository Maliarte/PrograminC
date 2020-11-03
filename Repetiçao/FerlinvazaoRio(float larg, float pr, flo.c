#include<stdio.h>
#include<locale.h>

int vazaoRio(float lar, float prof, float velo){
float vazao;
vazao = (lar * lar) * prof * velo;
return vazao;
}

float notaRio (float lar, float prof, float velo){
float nota,vaz;

	vaz = vazaoRio(lar,prof,velo);

	if (lar<15 || prof<6) {
    		return 0;
	} 	
		else if ( lar <=30){
     				if(vaz < 5000) {
        		 	nota = 5 + vaz / 2700;
   					}  else if (vaz>=5000) {
					 		nota =  5 + vaz / 2500;
						}
		}
	
	if (lar>=30){nota = 5 +vaz/2000;}
							
return nota;
	   
}


int main(void){

float lar, prof, velo;
int cidade, rios, totRios=0, totRiosViaveis=0, AcumRio=0, AcumCity=0;
setlocale(LC_ALL,"portuguese");

	printf("Entre com a quantidade de cidades ou Zero para Encerrar\n");
	scanf("%d", &cidade);
	
	while (AcumCity < cidade) {

		printf("Entre com a quantidade de rios: \n");
		scanf("%d", &rios);
		
			while(AcumRio < rios){
				
				printf("Digite a largura do rio em metros:\n");
				scanf("%f", &lar);
				printf("Digite a profundidade do rio em metros:\n");
				scanf("%f", &prof);
				printf("Digite a velocidade do rio em segundos:\n");
				scanf("%f", &velo);
			
				vazaoRio(lar,prof,velo);
				notaRio(lar,prof,velo);
	
					if (notaRio>=7){
							totRiosViaveis++;
							printf("Alternativa viavel\n");
					}

			
			AcumRio++;
			
		printf("Entre com a quantidade de Cidades: \n");
		scanf("%d", &cidade);

			} //fimWhileRios

		
	
	AcumCity++;

	} //fimWhileCity
	
		printf("\n\nPara %d Cidade(s) a quantidade de Rios Viaveis %d:rios\n", AcumCity, totRiosViaveis);
	
	 return 0;
}