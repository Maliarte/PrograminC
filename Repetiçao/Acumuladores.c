#include<stdio.h>
#include<locale.h>

int main (void) {
int c, soma, valor;
c=0;
soma=0;
  printf("informe numero: ");
  scanf("%i", &valor);
    while (c < 10) {
        soma = valor +1;
        c = c+1;
    }
printf("A soma é %d", soma);
return 0;
}
  /*     int c;
    char nome;
    c=0;
    printf("informe nome: ");
    scanf("%c",&nome);
        while (c < 10) {
            printf("%c", nome);
            c = c+1;
     return 0;      
 }
} 
 float valor, valorItemA, valorItemB, valorItemC, total;
    total=0;

    printf("Entre com o valor do Item A: ");
    scanf("%f", valorItemA);
    printf("Entre com o valor do Item B: ");
    scanf("%f", valorItemB);
    printf("Entre com o valor do Item C: ");
    scanf("%f", valorItemC);

    valor = (valorItemA+valorItemB+valorItemC)

    total=total+valor;
    
 printf("O valor total é de R$:%f ", total);
    return 0; */



