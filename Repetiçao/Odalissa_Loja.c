#include <stdio.h>
#include <stdlib.h>
/*Na loja virtual Novelos&Lãs as clientes podem escolher seus novelos por:
- Opção de cor
- Opção de metragem
Cada tipo de novelo pertence a uma marca, que possui características próprias de cor, sendo que a metragem sera escolhida
dentro da opção da marca. Cada novelo terá um código de quatro dígitos relacionado a sua marca e metragem,
em que o custo seria dez por cento do valor do código. A cliente decidirá quando terminar suas compras e se comprar mais
de 10 novelos terá desconto de quinze por cento.*/
float obterCusto (int codd){

float custo;
custo = codd*0.01;

custo ++;

return custo;

}

int main()
{

   int c1, cm1, cm2, qtcompra;
   float vcompra, vtotal;
   vtotal = vcompra = 0;
   qtcompra = 0;

   printf("Seja bem-vinda(o)! Você está na loja Novelos&Lãs!\n");
   printf("Quer comprar? Aperte qualquer número positivo ou 0 para terminar sua compra.\n");
   scanf("%d", &qtcompra);


     while(qtcompra!=0){

      printf("\nEscolha qual cor deseja:\n1 básica\n2 viva\n");
      scanf("i", &c1);

           if(c1==1){

           printf("Excelente escolha! A marca Círculo possui as cores e metragens:\n");
           printf("11 preta\n13 marrom\n15 branca\n19 azul-marinho\n");
           printf("E as metragens\n20 100 metros\n40 250 metros\n");
           printf("Digite os dois dígitos da cor junto com os dois dígitos da metragem.\n");
           scanf("%i", &cm1);

         vcompra = obterCusto(cm1);



          if(c1==2){

          printf("Excelente escolha! A marca Pingouim possui as cores e metragens:\n");
          printf("11 vermelho\n13 amarelo\n15 rosa\n19azul-claro\n");
          printf("E as metragens\n20 100 metros\n40 250 metros\n");
          printf("Digite os dois dígitos da cor junto com os dois dígitos da metragem.");
          scanf("%i", &cm2);

          vcompra = obterCusto(cm2);

          vcompra+=1;
          qtcompra++;

          printf("Quer comprar? Aperte qualquer número positivo ou 0 para terminar sua compra.");
          scanf("%d", &qtcompra);
          }
          }
          }

                 if(qtcompra>5){

                 vtotal = vtotal -(vtotal*0.15);

        printf("\nParabéns! Você comprou %i novelos, então terá 15%% de desconto. Pagará só R$: %.2f", qtcompra, vtotal);

          }else{

            vtotal = vcompra;

            printf("\nParabéns! Você comprou %i novelos, e pagará %.2f", qtcompra, vtotal);

          }


    return 0;
}