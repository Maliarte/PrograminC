#include<stdio.h>
  #include<stdlib.h>
  #include<locale.h>

void modifica_passagem (float lug_ocup, float capacidade, float *preco_atual, int hora){
    float perc_ocup, v_passagem, reajuste;
    int cont, qtd_reajuste;
    

    perc_ocup = (lug_ocup / capacidade)*100;
    

    if (hora> 10 && hora <16){
        v_passagem = *preco_atual * 1.15;
    }
    else if (hora>15 && hora<22){
            if(perc_ocup>39){
                v_passagem = *preco_atual * 1.30;
            }
            else{
                v_passagem = *preco_atual;
            }
    }
    else {
        if(perc_ocup>59){
            v_passagem = *preco_atual *1.40;
        }
        else{
            v_passagem = *preco_atual;
        }
    }

    reajuste = v_passagem - *preco_atual;
   

printf("\nO percentual de ocupação do ônibus é de %.2f %%\n", perc_ocup);
printf("O valor da passagem é: R$ %.2f \n", v_passagem);
printf("O valor do reajuste da passagem foi: R$ %.2f \n", reajuste);

qtd_reajuste = qtd_reajuste + (0<reajuste);
printf("\nQuantas linhas de ônibus tiveram sua passagem reajustada: %d\n", qtd_reajuste); 

return;
}


int main (void) {
int hora, linha, tot_bus, cont=0,qtd_reajuste=0;
float PO_bus, LO_bus, C_bus, preco_p, pa_bus, reajuste, ptr;
setlocale(LC_ALL,"Portuguese");

printf("\nInforme a quantidade de ônibus: ");
scanf("%d", &tot_bus);
for (cont=0; cont<tot_bus; cont++){
    printf("\nInforme a linha do ônibus: ");
    scanf("%d", &linha);
    printf("Informe a capacidade em lugares do ônibus: ");
    scanf("%f", &C_bus);
    printf("Informe o total de lugares ocupados do ônibus: ");
    scanf("%f", &LO_bus);
    printf("Informe o preço atual do ônibus: ");
    scanf("%f", &preco_p);
    printf("Informe a hora da partida do ônibus: ");
    scanf("%d", &hora);

      modifica_passagem (LO_bus, C_bus, &preco_p, hora);


}





return 0;

}