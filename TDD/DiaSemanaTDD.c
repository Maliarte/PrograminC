/* Escreva um programa que dado um número entre 1 e 7, imprima se é um dia de semana ou final de semana. Assuma que o primeiro dia da semana (1) é domingo
Modifique o programa anterior para exibir a mensagem nos dias de nossa aula: 
“Delícia!!! Hoje tem AL1”
*/
#include <stdio.h>
#include <locale.h>


int main(){
int diaSemana;

printf("Digite o numero correspondente ao dia da semana");
scanf("%i", &diaSemana);
 if (diaSemana==1 || diaSemana ==7) {
        printf("\n Final de Semana! \n");
    }
    else {
        printf("\n Dia de Semana! \n");
            if (diaSemana ==4) {
                printf("Hoje tem FAC! \n");
        }
    
    }
    

return 0;
}