#include "jogos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct {
  int idade;
  int genero;
  float notaJogo1;
  float notaJogo2;
  float distancia;
} Candidato;

int sorteio(int Inf, int Sup) {
  return (rand() % ((Sup - Inf) + 1)) + Inf;
}

void sorteioCandidatos(Candidato candidatos[], int totalUsuarios) {
  srand(time(NULL));
  
  for (int i = 0; i < totalUsuarios; i++) {
    
    candidatos[i].idade = sorteio(10, 50);
    candidatos[i].genero = sorteio(1, 3);
    candidatos[i].notaJogo1 = sorteio(0, 10);
    candidatos[i].notaJogo2 = sorteio(0, 10);
    
    if (validaCandidato(candidatos[i].notaJogo1, candidatos[i].notaJogo2)) {
      candidatos[i].distancia = calcDist(candidatos[i].notaJogo1, candidatos[i].notaJogo2, 5.0, 8.0);
    } else {
      candidatos[i].distancia = -1.0; // Marca como inválido
    }
  }
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

//ordenamento do array de Candidato com base na distância
void bubbleSort(Candidato array[], int tam) {
  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - i - 1; j++) {
      //comparando elementos dentro do array e verificando se a distancia é maior que o proximo, caso seja troca
      if (array[j].distancia > array[j + 1].distancia) {
        Candidato temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void mostrarCandidatos(Candidato candidatos[], int totalAprovados) {
  printf("Candidatos selecionados para os testes:\n");
  for (int i = 0; i < totalAprovados; i++) {
    printf("Idade: %d, Genero: %d, Nota Jogo 1: %.2f, Nota Jogo 2: %.2f, Distancia: %.2f\n",
           candidatos[i].idade, candidatos[i].genero,
           candidatos[i].notaJogo1, candidatos[i].notaJogo2, candidatos[i].distancia);
  }
}