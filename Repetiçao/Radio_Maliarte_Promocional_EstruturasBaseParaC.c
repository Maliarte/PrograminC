/*Você construir um enunciado e resolvê-lo.
Neste enunciado deve haver:
- 2 escolhas independentes com pelo menos 4 alternativas e pelo menos uma delas com sub-casos 
- 1 seleção (escolha)
- 1 repetição ( while)

- Pelo menos ¨5 resumos,  1 de cada tipo: percentual, contagem,totalização, média, maior/menor

EXTRA- Repetições aninhadas com totalizações em ambos os níveis

A radio Maliarte (https://anchor.fm/maliarte) está comemorando Aniversario! Para comemorar, a radio disponibilizará um pequeno questionario promocional, seguido da opiniao do publico. 
"Informe o nome da Radio que te leva para Marte em 2022". Para validar a resposta, esta deve ser acompanhada com o voto de qualidade da programaçao. 

Para parcipar o ouvinte fornece idade, sexo, e localizacao hemisferial. 

Esta ultima o ouvinte informa se escuta do hemisferio norte ou hemisferio sul.A opiniao de n(espectadores) é computada de acordo com este rótulo: 1.Ótimo, 2. regular, 3.bom, 4.ruim.  Termino da entrada de dados: idade =0.

Ao final sao exibidos 
Qts ouvintes responderam: otimo, bom, regular e ruim.
Qts homens escutam no hemisferio norte
Qts mulheres escutam do hemisferio sul
Qts sao menores de idade
o percentual de pessoas que responderam regular entre todos espectadores
a  media etária dos ouvintes

Se o ouvinte for  menor de idade e morar no hemisferio norte deve-se perguntar se o responsavel aprova a viagem espacial. */

#include <stdio.h>
#include <locale.h:

int main(void) {
int humam, alien;
int age, hemisferio, sexo, ctFemme =0, ctHomme=0, totFemme=0,totHomme=0, menorAge;
    
    setlocale(LC_ALL,"Portuguese");
    
    printf("Informe sua espécie espacial: 1.terraqueo 2.alien");
    scanf("%d", &especime);
    if (especime == 1) {
        printf("Parabens Humano!sua viagem espacial pode ter hora marcada. Responda questionário até o final e participe de nossa campanha Marte22");
    } else {
        printf("Aliens não concorrerão a viagem espacial, porem continue acompanhando nossa programação!");
}

printf("Seja bem vindo ao Aniversário da rádio mais querida dos Brasilerescos!");
printf("Informe sua idade: ");
scanf("%d", &age);

    if (age > 0 ) {
    printf("De qual metade da esfera chamada Mundo você curte Maliarte? : 1.Hemisferio Norte 2.Hemisferio sul: ");
    scanf("%d", &hemisferio);
    while (hemisferio == 1) {
        printf("Informe seu Sexo: 1.femme 2.homme");
        scanf("%d", &sexo);
        
        if (sexo == 1){
            ctFemme++;
            totFemme=ctFemme+1;

        } else
        {
            ctHomme++;
            totHomme=ctHomme+1;
        }
        while (hemisferio == 2) {
        printf("Informe seu Sexo: 1.femme 2.homme");
        scanf("%d", &sexo);
        
        if (sexo == 1){
            ctFemme++;
            totFemme=ctFemme+1;

        } else
        {
            ctHomme++;
            totHomme=ctHomme+1;
        }
        
        








    else {
        printf("O programa foi encerrado.");
    }
    return 0;
}