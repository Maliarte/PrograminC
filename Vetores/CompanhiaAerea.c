/* Malas de passageiros são sempre colocadas em esteiras de bagagens após a chegada de cada voo. Toda mala tem um identificador onde os 2 últimos algarismos representam a companhia aérea na qual o passageiro voou. O setor de achados e perdidos do aeroporto armazena as bagagens não retiradas destas esteiras em uma de suas 5 salas.  A sala escolhida está relacionada com a companhia aérea usada pelo passageiro. 

a) Faça um programa, com pelo menos duas funções além da main, que inicialmente leia:
para cada uma das companhias aéreas ( no máximo 20):
o código da companhia aérea (número qualquer entre 0 e 99. Código 0 significa fim da entrada de dados) 
o número da sala no setor de achados e perdidos onde guardam as bagagens não retiradas da esteira desta companhia aérea.
Em seguida, para cada passageiro que tentar encontrar uma bagagem leia o identificador de bagagem do passageiro e exibe a sala onde se encontra a mala ou uma mensagem “MALA NAO ENCONTRADA”.
O término da entrada de dados ocorre ao ser lido o valor o (zero) para o código da companhia aérea. 
Versão b) Faça um programa, com pelo menos duas funções além da main, que inicialmente leia:
para cada uma das companhias aéreas ( exatamente 20):
o código da companhia aérea (número qualquer entre 10 e 39). Código 0 significa fim da entrada de dados) 
o número da sala no setor de achados e perdidos onde guardam as bagagens não retiradas da esteira desta companhia aérea.

Em seguida, para cada passageiro que tentar encontrar uma bagagem leia o identificador de bagagem do passageiro e exibe a sala onde se encontra a mala ou uma mensagem “MALA NAO ENCONTRADA”.
O término da entrada de dados ocorre ao ser lido o valor o (zero) para o código da companhia aérea. 


*/
#define <stdio.h>
#define TAM 20

int defineCia(codCia[TAM], int n);
indice =0;
printf("Informe o número da companhia aérea: ");
scanf("%d", &Cia);

int main{
/* temos vinte companhias aereas, logo preciso de um vetor capaz de armazenar 20 valores entre 1 e 99, sendo 0 encerramento.
são cinco salas no seter de achados e perdidos.
*/
int codCia[TAM];
int numSala[5]={1,2,3,4,5,6}



    return 0;
}
