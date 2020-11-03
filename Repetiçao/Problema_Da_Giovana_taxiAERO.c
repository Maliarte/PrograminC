//Marcos possui uma empresa de taxi aéreo e decidiu criar um programa para que seus clientes possam alugar os voos de forma remota. Cada avião transporta no máximo 20 pessoas. Os voos podem ser realizados nos períodos da manhã, tarde, noite e madrugada nos sete dias da semana. Nos horários diurnos (manhã e tarde) o preço por passageiro é de R$ 400,00 e nos noturnos (noite e madrugada) é R$ 300,00, sendo que no final de semana (sexta à domingo) há uma taxa extra de R$ 100,00 por passageiro. Passageiros com idade maior ou igual à 60 ou menor que 12 tem direito a meia passagem. No final o programa deve mostrar ao cliente: Total a pagar; Idade média dos passageiros; Quantos pagam meia; Percentual de meia passagem; Maior idade no voo.
#include <stdio.h>
#include <locale.h>
float verificarVoo (int h, int d){
  float p;
  if (h==1||h==2){
    p=400.0;
  }
  else {
    p=300.0;
  }
  if (d>=5&&d<=7){
    p+=100.0;
  }
  return  p;
}
int verificarPass (int x){
  while (x>20 || x<1){
    printf("Numero de passageiros inválido, o voo transporta entre 1 e 20 passageiros");
    printf("\nNúmero de passageiros: ");
    scanf ("%i", &x);
  }
  return x;
}
int main (void){
  int hora, dia, pass,passVoo=1, idade, mIdade=0, totIdade=0, passMeia=0;
  float valPass, totValor, medIdade, perMeia;
  setlocale(LC_ALL, "portuguese");
  printf ("Escolha o dia do voo:\n1 - Segunda\n2 - Terça\n3 - Quarta\n4 - Quinta\n5 - Sexta\n6 - Sábado\n7 - Domingo\n");
  scanf ("%i", &dia);
  printf ("Escolha o horário:\n1 - Manhã\n2 - Tarde\n3 - Noite\n4 - Madrugada\n");
  scanf ("%i", &hora);
  printf("Número de passageiros: ");
  scanf ("%i", &pass);
  if (pass>20||pass<1){
    pass=verificarPass(pass);
  }
  while (passVoo<=pass) {
    valPass=verificarVoo (hora, dia);
    printf("Digite a idade do passgeiro %i: ", passVoo);
    scanf("%i", &idade);
    if (idade<12||idade>=60){
      totValor+=valPass/2;
      passMeia++;
    }
    else{
      totValor+=valPass;
    }
    if (idade>mIdade){
      mIdade=idade;
    }
    totIdade+=idade;
    passVoo++;
  }
  printf("\nTotal a pagar: %.2f", totValor);
  medIdade=(float)totIdade/(float)pass;
  printf("\nMedia de idade dos passageiros: %.2f", medIdade);
  printf("\nPassageiros que pagam meia: %i", passMeia);
  perMeia= ((float) passMeia/(float) pass)*100;
  printf("\nPercentual de meia passagem: %.2f", perMeia);
  printf("\nPassageiro de maior idade: %i", mIdade);
  return 0;
}