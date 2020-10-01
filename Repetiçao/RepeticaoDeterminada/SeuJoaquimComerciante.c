/* Seu Joaquim, um pequeno comerciante, deseja um lucro de 45% se o valor de custo do produtofor < 20,00$, caso contrario o lucro sera de 30%. Faca um programa que capture a quantidade de produtos comercializados. A seguir, para um dos produtos, o programa obtem do Seu Joaquim o valor de custo e lhe mostra o valor de venda (um por um). No final seu programa deve mostrar o preço medio de venda 
Repeticao Determinada. Repetir um numero conhecido de vezes. Controle de repeticao: por contagem das execucoes do bloco (interrompe quando atinge meta)
structure: int jafiz;
jafiz=0;
while (jafiz<meta) {
    jafiz = jafiz + 1 (incrementacao)
    } 
*/

    #include <stdio.h>
    #include <setlocale.h>

    int precovenda(float custo) {
        float perc;
       if (valorCusto < 20) {
            perc = 1.45;
        }
        else {
            perc = 1.3;
        }
        return custo * perc;
    }

    int main () {
        
        float custo, venda, totvenda, precovenda media;
        int n, jafiz;

        printf("Quantidade Produtos Comercializados: ");
        scanf("%d",&n);

        jafiz = 0;
        totvenda=0;

        while (ja fiz < n)
        {
            printf("CUSTO Produtos Comercializados: ");
            scanf("%d",&custo);
            venda = precovenda(custo);
            printf ("Vender a %.2f", venda);
            totvenda=totvenda+venda;
            jafiz = jafiz + 1;
        }

        media = totvenda/n
        printf("\nMedia de Preco: %.2f, media");
    
return 0;
        
    }