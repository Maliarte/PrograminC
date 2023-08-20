#include "jogos.h"
#include <stdio.h>


int main(void) {
  int totalUsuarios = 40;
  
  Candidato candidatos[totalUsuarios];
  int totalAprovados = 0;

  sorteioCandidatos(candidatos, totalUsuarios);

  // Filtrar apenas os candidatos aprovados
  Candidato candidatosAprovados[totalUsuarios];
  int index = 0;
  for (int i = 0; i < totalUsuarios; i++) {
    if (candidatos[i].distancia >= 0) {
      candidatosAprovados[index] = candidatos[i];
      index++;
      totalAprovados++;
    }
  }

  // Ordenar os candidatos aprovados por distância
  bubbleSort(candidatosAprovados, totalAprovados);

  // Exibir os candidatos selecionados
  mostrarCandidatos(candidatosAprovados, totalAprovados);

  return 0;
}