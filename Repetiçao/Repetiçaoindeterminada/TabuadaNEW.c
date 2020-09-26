#include <stdio.h>
#include <locale.h>
void tabuada(int num){
  int mult=1;
  int res;
  while(mult <=10){
    res=num*mult;
    printf("\n%2d X %2d = %3d",mult,num,res);
    mult++;
  }
  return;
}
void tabuadaDivisao(int num){
  float mult=1;
  float res;
  while(mult <=10){
    res=num/mult;
    printf("\n%2d / %.0f = %.2f",num,mult,res);
    mult++;
  }
  return;
}
int main (void)
{
    int numX,op;

    setlocale (LC_ALL, "portuguese");
    printf("Digite um número positivo ou 0 para finalizar: ");
    scanf("%i", &numX);

    while (numX>0)
    {
       printf("Tabuada de mult- 1 ou div-2 ? ");
       scanf("%i",&op);
       if (op ==1){
          tabuada(numX);
       }
       else{
         tabuadaDivisao(numX);
       }
        printf("\nDigite um número positivo ou 0 para finalizar: ");
        scanf("%i", &numX);
    }



    return 0;
}
