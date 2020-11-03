/* Um restaurante oferece 4 tipos de entrada, 10 pratos principais  e 5 tipos de sobremesa.Se um fregues deste restaurante decide tentar uma refeição diferente a cada noite, quanto tempo levará para esgotar todas as possibilidades. Temos para PFC ou Princípio multiplicativo que parte do enunciado: tendo  N maneiras de realizar tarefas distintas, sucessivas e dependente de etapas utiliza-se o produto das possibilidades*/

#include <stdio.h>
int entrada, pf, sobremesa, maneiras, meses, dias;

int main () {
    printf("Escolha a entrada: 1.EntradaA 2.EntradaB 3.EntradaC 4.EntradaD 5.EntradaE");
    scanf("%d",&entrada);
    printf("Escolha Prato: 1.PA 2.PB 3.PC 4.PD 5.PE 6.PF 7.PH 8.PI 9.PJ 10.PK");
    scanf("%d",&pf);
    printf("Escolha a Sobremesa: 1.SobremesaA 2.SobremesaB 3.SobremesaC 4.SobremesaD 5.SobremesaE");
    scanf("%d",&sobremesa);

    maneiras = 4*10*5; //cada maneira por noite, logo 200 dias.
    meses = maneiras/30;
    dias = maneiras%30;
    printf("Essas são  %d  maneiras e %d meses e %d dias", maneiras,meses   , dias);
    




}