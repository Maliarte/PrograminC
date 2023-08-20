/*
* Construa um programa para simular o problema descrito, considerando 40 usuários.
*Obs: Utilize a função sorteio fornecida para simular a idade, nota ao jogo 1, nota ao jogo 2 e gênero

Sorteia  um número inteiro entre lInf e lSup inclusive

int sorteio(int lInf,int lSup){
  return (rand()%((lSup-lInf)+1))+lInf;
}
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sorteio(int Inf, int Sup);
float calcDist(float x1, float y1, float x2, float y2);
int validaCandidato(float nota1, float nota2);

int main(void) {
  int totalUsuarios = 40;
  int idade, genero;
  float notaJogo1, notaJogo2;
  
  srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
  
  for (int i = 1; i <= totalUsuarios; i++) {
    idade = sorteio(10, 50); // Sorteia idade entre 10 e 50
    genero = sorteio(1, 3); // Sorteia gênero: 1, 2 ou 3
    
    // Sorteia notas para os jogos entre 0 e 10
    notaJogo1 = sorteio(0, 10);
    notaJogo2 = sorteio(0, 10);
    
    printf("Usuário %d:\n", i);
    printf("Idade: %d\n", idade);
    printf("Gênero: %d\n", genero);
    printf("Nota Jogo 1: %.2f\n", notaJogo1);
    printf("Nota Jogo 2: %.2f\n", notaJogo2);

    if (validaCandidato(notaJogo1, notaJogo2)) {
      printf("O candidato eh adequado para testar o jogo.\n");
    } else {
      printf("O candidato não eh adequado para testar o jogo.\n");
    }
    
    printf("\n");
  }
  
  return 0;
}

int sorteio(int Inf, int Sup) {
  return (rand() % ((Sup - Inf) + 1)) + Inf;
}

float calcDist(float x1, float y1, float x2, float y2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int validaCandidato(float nota1, float nota2) {
  float idealNotaJogo1 = 5.0;
  float idealNotaJogo2 = 8.0;
  
  float dist = calcDist(nota1, nota2, idealNotaJogo1, idealNotaJogo2);
  
  if (dist <= 1.5) {
    return 1;
  } else {
    return 0;
  }
}
