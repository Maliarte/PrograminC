/* A radio Maliarte (https://anchor.fm/maliarte) está comemorando Aniversario! Como presente a  radio disponibilizará um pequeno questionario promocional, seguido da opiniao do publico computada de acordo com o seguinte rótulo: 
1.Ótimo, 2.Regular, 3.Bom, 4.Ruim. Para parcipar, o ouvinte fornece idade, 
sexo (1.FEMININO, 2.MASCULINO) e localizacao de acordo com o Hemisferio geográfico em que reside (1.HEMISFERIO NORTE, 2.HEMISFERIO SUL). 

Termino da entrada de dados: idade <0.

Inscrição promocional:
"Informe o nome da Radio que te leva para Marte em 2022" informando como
entrada de dados: (1.Maliarte 2.Outros) 

Para validar a resposta, esta deve ser para a respectiva Radio(maliarte) e deverá vir  acompanhada com o voto de qualidade da programaçao, só concorrerá ao sorteio o ouvinte que qualificar a programação como positiva (boa ou ótima).

Ao final sao exibidos:

Percentual de ouvintes que gostaram e que não gostaram (ótimo e bom = Gostaram/Regular e ruim = não gostaram)
Qts homens escutam no hemisferio norte
Qts mulheres escutam do hemisferio sul
Qts sao menores de idade
Quantos ouvintes votaram
Qual o ouvinte mais novo
A média etária dos ouvintes

*/


#include <stdio.h>
#include <locale.h>

void validaDadosAva(int avaliacao) {
	while (avaliacao<1 || avaliacao>4 ) {
		printf("Informe sua Avaliação:\n1.Ótimo\n2.Bom\n3.Regular\n4.Ruim\n");
		scanf("%i", &avaliacao);
    return avaliacao;
	}
}

void validaDados() {
  int promocional;
  printf("Informe o nome da Radio que te leva para Marte em 2022\n1.Maliarte, 2.Outros\n");
	scanf("%i", &promocional);
	while(promocional != 1) {
		printf("Informe o nome da Radio que te leva para Marte em 2022\n1.Maliarte, 2.Outros\n");
		scanf("%i", &promocional);
    return;
	}

	return;
} 


float percentual (int x, int y){
  float z = ((float)x /(float)y)*100.0;
  return z;
}

int main(void) {
  int age, hemisferio, sexo, ctFemme=0, ctHomme=0, totHuman=0, menorAge=0, totAge=0, avaliacao, avaliacaoPositiva=0, avaliacaoNegativa=0, maisNovo=1000,promocional;
  
  float percentualBom, percentualRuim, mediaEtaria;
    
  setlocale(LC_ALL,"Portuguese");

  printf("Seja bem vindo ao Aniversário da rádio mais querida dos Brasilerescos!\n");
  
  printf("Informe o nome da Radio que te leva para Marte em 2022\n1.Maliarte, 2.Outros\n");
  scanf("%d", &promocional);
  validaDados(promocional);

  printf("Informe sua idade: ou digite 0 para encerrar.\n");
  scanf("%d", &age);

  while (age>0) {
    if (age<maisNovo){
      maisNovo=age;
    }
    printf("De qual metade da esfera chamada Mundo você curte Maliarte?\n1.Hemisferio Norte\n2.Hemisferio sul\n");
    scanf("%d", &hemisferio);  
    /*if (hemisferio!=1 && hemisferio!=2) {
        printf("Resposta Invalida, valor não computado.\n");
    }*/
    printf("Informe seu Sexo\n1.feminino \n2.masculino\n");
    scanf("%d", &sexo);
   /* if (sexo=2 && hemisferio=1) {
        printf("Qual a radio te leva para Marte em 2022?\n"); 
    }*/ 
    
    if (hemisferio==1&&sexo==2){
      ctHomme++;
    } else {
      ctFemme++;
    }

    printf("Informe sua Avaliação:\n1.Ótimo\n2.Bom\n3.Regular\n4.Ruim\n");
    scanf("%i", &avaliacao);
    validaDadosAva(avaliacao);
    if (avaliacao==1||avaliacao==2){
      avaliacaoPositiva++;
      printf("Parabéns e Boa Sorte em Marte!");
    } else {
      avaliacaoNegativa++;
      printf("Obrigado por sua Avaliação vamos melhorar para atende-lo melhor!");
    }
    totAge+=age;
    totHuman++;
    printf("\nSeja bem vindo ao Aniversário da rádio mais querida dos Brasilerescos!\n");
    printf("\nInforme sua idade: ou digite 0 para encerrar\n");
    scanf("%d", &age);
  }
    percentualBom=percentual (avaliacaoPositiva,totHuman);
    percentualRuim=percentual (avaliacaoNegativa,totHuman);  
    mediaEtaria=(float)totAge/(float)totHuman;

  printf("===============\nRESULTADO\n===============");
  
  
  printf("\nTotal de Ouvintes: %i", totHuman);
  printf("\nAvaliaçao Positiva: %.0f%%", percentualBom);
  printf("\nAvaliação Negativa: %.0f%%", percentualRuim);
  printf("\nOuvintes homens no hemisfério norte: %i", ctHomme);
  printf("\nOuvintes mulheres no hemisfério sul: %i", ctFemme);
  printf("\nFaixa etária média dos ouvintes: %.0f anos", mediaEtaria);
  printf("\nOuvinte mais novo: %i", maisNovo);
  
  return 0;
}