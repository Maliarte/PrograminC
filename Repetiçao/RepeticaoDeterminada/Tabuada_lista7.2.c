/* Mostrar a tabuada de números  informados pelo usuário. A entrada de dados é finalizada quando um número ≤ 0 for digitado. No final, o programa deve mostrar:
   *  quantidade de números  digitados (ct ocorrencias?contador)
   * quantidade de números pares digitados(A variavel qtpares deve ter seu valor atualizado em uma unidade toda vez que numPar for digitado)
   * % de números pares digitados (numPar*100/totNum)
   * maior valor digitado e posição do maior valor digitado (cont,variavelFke While cont<)

https://www.youtube.com/watch?v=hDBRQuhTyTk
https://www.youtube.com/watch?v=4w6paceAyMc
*/
#include <stdio.h>
#include <locale.h>

void obterTabuada(int num)
{
    int x = 1, tab;
    while (x < 11)
    {
        tab = num * x;
        printf("%i x %i = %i\n", num, x, tab);
        x = x + 1; //ou x++
    }
    return;
}
void TabuadaDiv(int num)
{
    int x = 1, tab;
    while (x < 11)
    {
        tab = num / x;
        printf("%i / %i = %i\n", num, x, tab);
        x = x + 1; //ou x++
    }
    return;
}
void TabuadaSoma(int num)
{
    int x = 1, tab;
    while (x < 11)
    {
        tab = num + x;
        printf("%i + %i = %i\n", num, x, tab);
        x = x + 1; //ou x++
    }
    return;
}
void TabuadaSub(int num)
{
    int x = 1, tab;
    while (x < 11)
    {
        tab = num - x;
        printf("%i - %i = %i\n", num, x, tab);
        x = x + 1; //ou x++
    }
    return;
}

int main(void) {

    int num,  operacao;
    setlocale(LC_ALL, "portuguese");

    printf("===== TABUADA =====\n\n");
    printf("Digite um numero positivo ou 0 para terminar:  ");
    scanf("%i", &num);

    while (num > 0)
    {

        printf("Informe a operacao aritmetica a ser realizada com o numero %i informado. \n\n1.multiplicacao 2.divisao 3.soma 4.subtracao:  ",num);
        scanf("%i", &operacao);

        if (operacao == 1){
            obterTabuada(num);
        }
        else if (operacao == 2){
            TabuadaDiv(num);
        }
        else if (operacao == 3){
            TabuadaSoma(num);
        }
        else{
            TabuadaSub(num);
        }

   // printf("\nDigite um novo numero positivo ou 0 Encerrar:");
   //scanf("%i", &resp);
      
return 0;
}
}
