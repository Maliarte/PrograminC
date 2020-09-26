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
    int conta;
    int contaPar;
    float perc;
    int totNum;

    setlocale (LC_ALL, "portuguese");
    printf("Digite um número positivo ou 0 para finalizar: ");
    scanf("%i", &numX);
    conta=0;
    contaPar=0;
    totNum=0;
    while (numX>0)
    {
       totNum+=numX; /* totNum=totNum+numX; */
       conta=conta+1;
       if (numX %2 ==0){
         contaPar++;
       }
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
    printf("Qt de valores tabuados: %d",conta);
    printf("Qt de valores pares tabuados: %d",contaPar);
    perc=contaPar*100.0/conta ;
    printf("Perc: %.1f %%",perc);
    printf("Soma dos valores digitados %d ",totNum);
    printf("Média dos valores digitados %.1f",totNum/conta);


    return 0;
}
