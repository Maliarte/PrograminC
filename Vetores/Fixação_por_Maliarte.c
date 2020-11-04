/* Captura os valores do teclado e armazenando-os em um vetor */

#include <stdio.h>
#include <locale.h>


/* 2. mostre o produto interno de dois vetores. Esta função deve preencher dois vetores X e Y com os dados do teclado.
Exemplo para vetores que possuem 4 elementos
Exemplo:
X = (1,2,3,4) Y = (4,3,2,1) ===> X.Y = 1*4 + 2*3 + 3*2 + 4*1 = 20

*/
void Exercicio2() {
  int i; //panóptico
  int vetorX[2] = {2, 1}; //o nome do meu vetor já é onde  meu vetor começa, ou seja onde está armazenado meu primeiro elemento.
  int vetorY[2] = {3, 4};

  /* Imprimindo o valor em cada posição*/

  for( i=0; i<2; i++){

    printf("\n\nQ2.Exibição númerica do primeiro vetor: %i\n\nExibição númerica do segundo vetor: %i", vetorX[i], vetorY[i]);
  }
  

 /* for (i=0;i<3;i++){
    printf("\nDigite um numero para o vetor X: ");
    scanf("%i", &vX[i]);
  }
  for (i=0;i<3;i++){
  printf("\nDigite um numero para o vetor Y: ");
  scanf("%i", &vY[i]);
  }
  for(i=0;i<3;i++){
    produto+=(vX[i]*vY[i]); //produto = produto + expressao
  }
  printf("\nO produto dos vetores X e Y é %i", produto); */
  return;
}




/*1.Capture os valores do teclado e armazenando-os em um vetor*/

void Exercicio1() {

/*cria 10 variaveis inteiras onde acesso cada posição pelo indice [posicao i] */

int vetor[10]; 
int i;
for (i=0; i < 10; i++){
  printf("\n Marília Sabe:\n\nQ1.Informe o valor da posição %i do vetor: ",i);
  scanf("%i", &vetor[i]);
}
/*exibindo os pares
for (i=0; i < 10; i+=2){
  printf( "%i - ", vetor[i]);
} */
  return;
}

int main (void){
  int i, vetor[10]; /*
  
  setlocale(LC_ALL, "portuguese");

  for (pos=0;pos<5;pos++){//inicialização-teste-atualização

    printf("\nDigite um numero: ");//sublinhado verde=logica, vermelho=sintaxe
    scanf("%i", &vetor[pos]);
    
  }*/

  Exercicio1();
  Exercicio2();
  
  return 0;
}

