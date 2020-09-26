#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int gerarNum (int numMin, int numMax){
    return (numMin + (rand ( ) % numMax));
}

void fazerFrase (int s, int c){
    if (s < c) printf ("\nVocê perdeu!\n▬▬▬▬▬▬▬▬▬▬▬▬\nCOMPUTADOR: %d\nSUA PONTUAÇÃO: %d\n▬▬▬▬▬▬▬▬▬▬▬▬", c, s);
    else printf ("\nVocê venceu!\n▬▬▬▬▬▬▬▬▬▬▬▬\nCOMPUTADOR: %d\nSUA PONTUAÇÃO: %d\n▬▬▬▬▬▬▬▬▬▬▬▬", c, s);
}

 int main (void){
     int rodadas, comp, contador = 1, vet [0], i, soma, novoContador,
     resposta, a = 0, contadorDois = 1;
     
     setlocale (LC_ALL, "Portuguese");
     printf ("      •ೋೋ JOGO DOS 50 PONTOS •ೋೋ\n"
             "VENÇA O COMPUTADOR, MAS CUIDADO PARA NÃO ESTOURAR 50 PONTOS!\n\n");
     printf ("Quantas rodadas gostaria de jogar? ");
     scanf ("%d", &rodadas);  
     
     srand (time(NULL));  
     printf ("▬▬▬▬▬▬▬▬▬▬▬▬\nCOMPUTADOR: %d PONTOS\n▬▬▬▬▬▬▬▬▬▬▬▬\n\n", comp = gerarNum (1, 50)); 
     
     while (contador <= rodadas){
      printf ("%dª rodada: %d\n", contador, vet [i] =gerarNum (1, 5));
      contador = contador + 1;
      soma = soma + vet [i]; 
     }
     printf ("\nTOTAL DE PONTOS: %d\n", soma);
     
     if (soma > comp)
         printf ("Parabéns! Você fez mais pontos que o computador em apenas %d rodadas!", contador = contador -1);
         
     else {
         printf ("\nDeseja pedir mais rodadas?\n[Você tem direito a mais %d rodadas]\n", novoContador = (contador - 1)*2);
         printf ("\nDigite 1 para SIM e 0 para NÃO: ");
         scanf ("%d", &resposta);
         
         if (resposta == 1) {
             while (a < novoContador && resposta == 1){
                  a = a + 1;
                  printf ("\n===================\n");
                  printf ("%dª rodada extra: %d\n", contadorDois, vet [i] =gerarNum (1, 5));
                  
                  if (vet [i] == soma/8 && resposta == 1) {
                      soma = (soma + vet [i]) - 20;
                      printf ("Perca 20 pontos!\n");
                      printf ("\nTOTAL DE PONTOS: %d", soma);
                      printf ("\n===================\n\n");                      
                      if (a < novoContador ){
                          printf ("Deseja continuar? ");
                          printf ("\nDigite 1 para SIM e 0 para NÃO: ");
                          scanf ("%d", &resposta);                          
                      }
                      else if (a > contador || resposta == 0){
                          printf ("Limite de rodadas atingido!"); 
                      }            
                  }
                      else if (vet [i] != soma/8 && resposta == 1) {  
                          soma = soma + vet [i]; 
                          printf ("\nTOTAL DE PONTOS: %d", soma);
                          printf ("\n===================\n\n"); 
                          if (a < novoContador){
                          printf ("Deseja continuar? ");
                          printf ("\nDigite 1 para SIM e 0 para NÃO: ");
                          scanf ("%d", &resposta);
                          }
                          else if (a > novoContador || resposta == 0){
                              printf ("Limite de rodadas atingido!");
                              fazerFrase (soma, comp);
                          }
                  }               
              contadorDois = contadorDois + 1;   
              }
              fazerFrase (soma, comp);
       }
      else fazerFrase (soma, comp);
    }
    return 0;
}  
