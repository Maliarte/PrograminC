/*Para resolver o abastecimento de água de uma grande cidade, o governo avalia a largura (em metros), a profundidade (em metros) e a vazão (litros/segundo) de um rio da região. 

A nota da avaliação do rio é calculada de acordo com as regras abaixo:

Para largura inferior a 15 m, a nota é zero; (larg<15m nota0) //
Para profundidade inferior a 6 m, a nota é zero; (prof<6m nota0)

Para largura entre 15 e 30 m (incluindo os extremos) e profundidade maior ou igual a 6 m, há 2 possibilidades:
Para vazão inferior a 5000 l/s, a nota é: 5 + vazão / 2700;
Para vazão maior ou igual a 5000 l/s, a nota é: 5 + vazão / 2500;


Para largura superior a 30 m e profundidade maior ou igual a 6 m, a nota é:
5 + vazão / 2000.

1) Faça a função vazaoRio que recebe como parâmetros a largura, a profundidade e a velocidade do rio e retorna a vazão de acordo com a seguinte fórmula: 
Vazão = Largura2 x Profundidade x Velocidade.
Protótipo da função:

float vazaoRio (float largura,float profundidade, float velocidade);

2) Faça a função notaRio que recebe como parâmetros a largura, a profundidade e a velocidade do rio e, utilizando, obrigatoriamente, a função do item a), retorna a nota de acordo com as regras acima. Protótipo da função:
//teste : selecao, tdd, escolha 

float notaRio (float largura, float profundidade, float velocidade);

3) Faça um programa que leia a largura, a profundidade e a velocidade da água de n (lido) rios de m (lido) cidades, utilizando as funções vazaoRio e notaRio, exiba sua nota. O programa deverá exibir também a mensagem “Alternativa viável”, APENAS quando o rio for uma alternativa viável, isto é, a sua nota for maior ou igual a sete (7).

Inicialmente, deve ser obtido a quantidade m de cidades e para cada cidade a quantidade n de rios. No final deve ser exibido:
Para cada cidade: quantidade de rios viáveis
Para todas as  cidades:  o percentual  de rios viáveis

Resolução: Marília Silva 

|| Maliarte https://maliarte.com.br

*/
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

	if (lar < 15 || prof < 6) {
    		nota = 0;
	} 	
		else if (lar>=15 && lar<=30){
     		if(vaz < 5000) {
        	nota = 5 + vaz / 2700;
   			}   else if (vaz>=5000) {
					nota =  5 + vaz / 2500;
				}
		}
		else {
			nota = 5 +vaz/2000;
		}							
return nota;	   
}
int main(void) {

float lar, prof, velo, teste, percentualViavel;
int nCity, nRios, totRios=0, totRiosViaveis=0, countCity=1;

setlocale(LC_ALL,"portuguese");

	printf("Entre com a quantidade de cidades ou Zero para Encerrar\n");
	scanf("%d", &nCity);
	
	while (countCity <= nCity) {

		printf("\nInforme a Quantidade de rios para |Cidade %i|\n", countCity);
		scanf("%d", &nRios);
		totRios+=nRios; //totRios = totRios+nRios sofre incremento da qtRios digitada

    	int rioViavel=0, countRio=1; 

			while(countRio <= nRios) {
				
				printf("\nDigite a largura do rio em metros:\n",countRio);
				scanf("%f", &lar);
				printf("Digite a profundidade do rio em metros:\n",countRio);
				scanf("%f", &prof);
				printf("Digite a velocidade do rio em segundos:\n",countRio);
				scanf("%f", &velo);
			
				teste = notaRio(lar,prof,velo);
				printf("\nNota do rio %i: %.2f\n",countRio,teste);
	
					if (teste>=7){
							rioViavel++;
							printf("|Alternativa viavel|\n");
					}
				countRio++;
			} 	
    printf("\n| Cidade %i | %i rios viáveis|\n", countCity, rioViavel);
    totRiosViaveis+=rioViavel;
    countCity++;
	} 
percentualViavel=((float)totRiosViaveis/(float)totRios)*100.0;
printf("\n\nPercentual de Rios viáveis em %i cidade(s)%.2f %% \n", nCity, percentualViavel);

  return 0;

}