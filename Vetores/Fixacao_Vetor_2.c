/* Captura os valores do teclado e armazenando-os em um vetor */

#include <stdio.h>
#include <locale.h>

int main (void){
  int pos, vetor[5];
  
  setlocale(LC_ALL, "portuguese");

  for (pos=0;pos<5;pos++){//inicialização-teste-atualização

    printf("\nDigite um numero: ");//sublinhado verde=logica, vermelho=sintaxe
    scanf("%i", &vetor[pos]);
    
  }
  return 0;
}
