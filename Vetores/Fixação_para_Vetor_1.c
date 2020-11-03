#include <stdio.h>
#include <locale.h>

int main (void) {
  int pos, mat, vGab[5], vRes[5], ponto;
  setlocale(LC_ALL, "portuguese");

//inicializacao, teste e atualizaçao na mesma linha.
  for (pos=0; pos<5;pos++){ 

    printf("\nProfessor, digite a resposta certa da questão %i: ", pos+1);
    scanf("%i", &vGab[pos]);
  }

  printf("Aluno, digite sua matricula: ");
  scanf("%i", &mat);

  for (pos=0;pos<5;pos++){
    printf("\nAluno, digite a resposta da questão %i: ", pos+1);
    scanf("%i", &vRes[pos]);
    if(vRes[pos]==vGab[pos]){
      ponto++;
    }
  }
  printf("\nO aluno de matricula %i acertou %i questões.", mat, ponto);

  return 0;

}