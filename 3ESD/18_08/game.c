/* Parte I
* Uma equipe de desenvolvimento de jogos deseja selecionar um grupo de usuários para os testes iniciais de um novo jogo.
* Para isso elaborou um questionário onde o usuário informa sua idade, gênero(1-F,2-M,3-X) e atribui uma nota entre 0 e 10 a dois jogos já existentes no mercado. Considerando que o testador ideal é o usuário que deu nota 5 ao primeiro jogo e nota 8 ao segundo jogo, mostre todos os candidatos que estão próximos do testador ideal, isso é, cuja distância é de até 1,5 do testador ideal
* Construa uma função para o cálculo da distância euclidiana entre dois pontos
* Construa uma função booleana para que retorne 1 se o usuário é candidato a testar o jogo ou 0, caso contrário.
 *
 */

#include <stdio.h>
#include <math.h>

float calcDist(float x1, float y1, float x2, float y2);
int validaCandidato(float nota1, float nota2);

int main(void) {

  int idade;
  int gen;
  float notaJogo1, notaJogo2;
  
  printf("Entre com a idade: ");
  scanf("%d", &idade);
  printf("Entre com o genero: 1-F | 2-M | 3-X\n");
  scanf("%d", &gen);
  printf("Nota Jogo 1: ");
  scanf("%f", &notaJogo1);
  printf("Nota Jogo 2: ");
  scanf("%f", &notaJogo2);

  if (validaCandidato(notaJogo1, notaJogo2)) {
    printf("O candidato eh adequado para testar o jogo.\n");
  } else {
    printf("O candidato nao eh adequado para testar o jogo.\n");
  }
  
  return 0;
}

// Calcula distância entre dois pontos
// E: coordenadas do ponto1 e do ponto2
// S: distância entre os pontos recebidos
float calcDist(float x1, float y1, float x2, float y2){
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int validaCandidato(float nota1, float nota2){
  float idealNotaJogo1 = 5.0;
  float idealNotaJogo2 = 8.0;
  
  float dist = calcDist(nota1, nota2, idealNotaJogo1, idealNotaJogo2);
  
  if (dist <= 1.5) {
    return 1;
  } else {
    return 0;
  }
}
