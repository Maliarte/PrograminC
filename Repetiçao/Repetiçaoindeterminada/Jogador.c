#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int jog1, cpu, partidas, cont=0;
    int qtJOG=0, qtCPU=0;
    srand(time(NULL));
    printf("Digite o numero de partidas: ");
    scanf("%i", &partidas);
    while(cont != partidas){
      printf("\nDigite a escolha do jogador: \n");
      printf("\n1 - Pedra");
      printf("\n2 - Tesoura");
      printf("\n3 - Papel\n\n");
      scanf("%i", &jog1);
      
      cpu = rand() % 3+1;
      printf("CPU escolheu: %i\n", cpu);
      if (jog1==cpu){
        printf("\nEmpate");
      }
      else{
        if (jog1==3 || cpu==3){
            if (cpu ==1){
              printf("\nJogador venceu");
              qtJOG++;
            }
            else{
              if (cpu==2){
                printf("\nComputador venceu");
                qtCPU++;
              }
              else{
                  if (jog1 ==2){
                    printf("\nJogador venceu");
                    qtJOG++;
                  }
                else{
                   printf("\nComputador venceu");
                   qtCPU++;
                }


              }
            }

        }
        else{
            if (jog1 < cpu){
                printf("\nJogador venceu");
                qtJOG++;
            }
            else{
                printf("\nComputador venceu");
                qtCPU++;
            }


        }
      }
      
      cont++;
}
printf("Jogador: %d x Computador: %d",qtJOG,qtCPU);
return 0;
}
