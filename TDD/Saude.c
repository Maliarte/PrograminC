/* Um plano de saúde cobra as seguintes mensalidades:
Até 10 anos: R$ 30,00
Acima de 10 até 29 anos: R$ 60,00
Acima de 29 até 45 anos: R$ 120,00
Acima de 45 até 59 anos: R$ 150,00
Acima de 59 até 65 anos: R$ 250,00
Maior que 65 anos: R$ 400,00
Para as pessoas fumantes, com mais de 29 anos, é cobrada uma taxa extra de R$30,00
Escreva um programa em C que pergunte a idade de uma pessoa e exiba o valor que ela deverá pagar. A pergunta sobre ser fumante só deve ser realizada quando necessária.
*/
#include <stdio.h>
#include <locale.h>

int main (void) {

    int idade;
    float valor; 
    
    taxa=0;

setlocale(LC_ALL, "portuguese");

printf("\n digite a idade: ");
scanf(" %i",&idade);

    if (idade > 29) {
printf("\n Digite para (1) fumante ou (2) para não fumante: ");
scanf(" %i", &fumante);
        if (fumante==1) {
            taxa=30;
        }
        else {
        taxa=0;
        }
        if (idade <=45){
            valor=120;
        }
        else {
            if (idade <=59) {
                valor=150;
            }
        }
             else {
                  if (idade<=65) {
                        valor=250;
             }
        }
            else {
                    valor = 400;
            }
    }

printf (" %f R$: .2f", valor + taxa);

    return (0);

 }   
    