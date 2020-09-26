#include <stdio.h>
#include <locale.h>

float calcDescAtual(float valorConta){
	float valorContaDesc=0;
	int idade;
	if (valorConta >= 300) {
    		valorContaDesc =(valorConta*0.25);
	}
    //estrutura de condição exclusiva aninhada

	else{
		if (valorConta >= 100) {
			printf("Parabéns, você está apto ao Desconto por Idade. Quantos anos vc tem?");
			scanf("%d",&idade);
			if (idade >50){
    				valorContaDesc = (valorConta*0.15);
			}
		}

    return valorContaDescAge;
}

// instrução operando operador operando

float calcVale(int nPratos, int ndrink){
    float valorVale=0;
    if (valorConta >= 400)  {
        valorCVale = 100;
    }
    else{
       if (valorConta >= 150)  {
            if ( nPratos >=6 && ndrink >=3){
                valorVale=50
            }
            else{
                if (nPratos >= 3){
                    valorCVale = 20;
                }
                else {
                    if (ndrink >= 3){
                        valorCVale = 10;
                    } 
                }
            }
       }
       else {
            if (nPratos>=1 && nDrink >=1) {
                valorVale = 10;
            }  
       }
    }
    return valorVale;
}

int main() {
    float valorConta, montante1, montante2, valorContaDescAge,valorContaDescF;
    int nPratos, nDrink, idoso;
    tx = 0;

    printf("Entre com o valor da Conta: ");
    scanf("%f", &valorConta);
    printf("Entre com a quantidade de Pratos: ");
    scanf("%i", &nPratos);
    printf("Entre com a quantidade de Bebidas: ");
    scanf("%i", &nDrink);
    montante1 = valorConta - calcDescAtual(valorConta);
    montante2= calcVale(nPratos,nDrink);
    printf("\nO valor da conta atual é de: %.2f ", montante1); 
    printf("\n O vale desconto para próxima: %.2f", montante2);
    return 0;

}