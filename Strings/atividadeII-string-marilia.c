 /*

Implementar uma função que, dadas duas strings s1 e s2, determinar o número de 
caracteres comuns entre elas (com o cuidado de que o mesmo caracter não seja contabilizado 
mais de uma vez).

 exemplos:                                      
                                    ->    s1: “CEU”
                                    ->   s2: “CADERNO”

                                    <- 2 caracteres comuns
                                      [neste caso, os caracteres ‘C’ e ‘E’]

                                    
                                    ->    s1: “CASA”
                                    ->    s2: “CADERNO”
                                      
                                    <-    2 caracteres comuns
                                        [neste caso, os caracteres ‘C’ e ‘A’; cuidado para 
                                        não contabilizar 2 vezes o caracter ‘A’]


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipo da função
int contabilizaStr(char *string1, char *string2);
//void repetidos(char *string, char *stringSemRepeticao);

void main()
{
  char string1[30];
  char string2[30];
  int quant;

  //limpa buffer de entrada
  fflush(stdin);
  printf("Entre com a primeira Palavra: ");
  gets(string1);

  fflush(stdin);
  printf("Entre com a segunda Palavra: ");
  gets(string2); //guarda caracteres especiais

  quant = contabilizaStr(&string1, &string2);

  //exibindo resultado
  printf("\n A palavra %s e a palavra %s possuem [%d] caracteres iguais.\n", string1, string2, quant);
}

int contabilizaStr(char *string1, char *string2)
{
  int i, j, cont=0;
 // char repetidos[30];

  //percorrendo a primeira palavra
  for (i = 0; string1[i] != '\0'; i++)
  {
    //percorrendo a segunda palavra
    for (j = 0; string2[j] != '\0'; j++)

      //verificando cada caracter igual
      if (string1[i] == string2[j])
      {
        cont += 1;        
      }
  }
return cont;
  
}
///////////// kokokoko

#include <stdio.h>
#include <stdlib.h>

void main(){

#define TAM 100


int contador=0;
char encontrados[TAM];
char palavras[TAM];


for(int i=0;palavras[i]!='\0';i++){
    for(int j=0;palavras[j]!='\0';j++){
        for(int z=0;i<contador;z++){
            if(palavras[i]==palavras[j] && i!=j && palavras[i]==encontrados[z]){
                break;
            }
        }
        if(palavras[i]==palavras[j] ){
            contador++;
            break;
        }
    }
}
}

*/
int main() {
    char vetorA[] = "AABBCCDDEE";
    int tam = strlen(vetorA);
    char vetorB[tam];
    //Um vetorB[] que recebe o vetorA[] utilizando a biblioteca strcpy(vetorB, vetorA);
    strcpy(vetorB, vetorA);

    int i = 0, j = 1;

    while(i < tam) {
        if(vetorA[i] == vetorB[j])
            vetorA[i] = vetorB[j];
        else {
            vetorA[i+1] = vetorB[j];
            i++;
        }
        j++;

    }
    //A saída será ABCDE
    printf("\n\n%s\n", vetorA);
   
}