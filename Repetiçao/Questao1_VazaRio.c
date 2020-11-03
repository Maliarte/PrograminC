/*
Para resolver o abastecimento de água de uma grande cidade, o governo avalia a largura (em metros), a profundidade (em metros) e a vazão (litros/segundo) de um rio da região. 

A nota da avaliação do rio é calculada de acordo com as regras abaixo:

Para largura inferior a 15 m, a nota é zero; (larg<15m nota0) //
Para profundidade inferior a 6 m, a nota é zero; (prof<6m nota0)

Para largura entre 15 e 30 m (incluindo os extremos) e profundidade maior ou igual a 6 m, há 2 possibilidades:
Para vazão inferior a 5000 l/s, a nota é: 5 + vazão / 2700;
Para vazão maior ou igual a 5000 l/s, a nota é: 5 + vazão / 2500;


Para largura superior a 30 m e profundidade maior ou igual a 6 m, a nota é:
5 + vazão / 2000.

1) Faça a função vazaoRio que recebe como parâmetros a largura, a profundidade e a velocidade do rio e retorna a vazão de acordo com a seguinte fórmula: 
Vazão = Largura2 x Profundidade x Velocidade.
Protótipo da função:

float vazaoRio (float largura,float profundidade, float velocidade);

2) Faça a função notaRio que recebe como parâmetros a largura, a profundidade e a velocidade do rio e, utilizando, obrigatoriamente, a função do item a), retorna a nota de acordo com as regras acima. Protótipo da função:
//teste : selecao, tdd, escolha 

float notaRio (float largura, float profundidade, float velocidade);

3) Faça um programa que leia a largura, a profundidade e a velocidade da água de n (lido) rios de m (lido) cidades, utilizando as funções vazaoRio e notaRio, exiba sua nota. O programa deverá exibir também a mensagem “Alternativa viável”, APENAS quando o rio for uma alternativa viável, isto é, a sua nota for maior ou igual a sete (7).

Inicialmente, deve ser obtido a quantidade m de cidades e para cada cidade a quantidade n de rios. No final deve ser exibido:
Para cada cidade: quantidade de rios viáveis
Para todas as  cidades:  o percentual  de rios viáveis
*/

#include<stdio.h>
#include<locale.h>

float vazaoRio(float x, float y, float z);
float vazao = (x * y * z);
return vazao;


float notaRio (float x, float y, float z);

if (larg<15 || prof<6) {
    printf("Nota 0");
} else if (larg>=15 && larg <=30) && (prof >=6){
     if(vazaoRio < 5000) {
         notaRio = 5 + vazao / 2700;
    } 
     else(vazaoRio>=5000){
        notaRio =  5 + vazao / 2500;
} else if (larg > 30 && prof >= 6) {
    notaRio = 5 + vazao/2000;
}

return notaRio;

}


int main () {
float larg, prof, veloc,vaz, not;


    printf("Entre com a largura do Rio(m): \n");
    scanf("%f", &larg);
    printf("Entre com a profundidade do Rio(m): \n");
    scanf("%f", &prof);
    printf("Entre com a velocidade do Rio(l/s): \n");
    scanf("%f", &veloc);
    
    vaz = vazaoRio(larg,prof,veloc);
    not = notaRio(larg,prof,veloc);



    return 0;
}