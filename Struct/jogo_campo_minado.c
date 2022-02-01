// variáveis globais
Celula jogo[10][10]; //kda posiccao da matriz tera 3 campos
int l, c, tam = 10;


typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;
/*
Antes de iniciar nosso jogo precisamos inicializar nossa matriz, ou seja, dizer que:
– todas as posições estão fechadas;
– não há bombas;
– e zero bombas vizinhas.
Agora podemos criar uma matriz de células. Assim, cada posição da nossa matriz terá três campos. 
Esta matriz será uma variável global.
*/
// procedimento para inicializar a matriz do jogo
void inicializarJogo(){
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}

/*
            Com a matriz inicializada precisamos agora sortear bombas. 
            Para isso vamos elaborar um procedimento que sorteia n bombas 
            para nosso jogo campo minado. Como as coordenadas podem ser 
            sorteadas mais de uma vez (se repetir), para garantir que sejam 
            sorteadas exatamente n bombas verificamos se a coordenada sorteada 
            já é uma bomba, se for, decrementamos a variável i, para que outra 
            coordenada seja sorteada.
*/

// procedimento para sortear n bombas
void sortearBombas(int n){
    int i;

    srand(time(NULL));

    for(i = 1; i <= n; i++){
        l = rand() % tam;
        c = rand() % tam;
        if(jogo[l][c].eBomba == 0)
            jogo[l][c].eBomba = 1;
        else
            i--;
    }
}

////////////////////////////MAIN/////////////////////////
int main() {
    /* v.1
    inicializarJogo();
    sortearBombas(20);
    return 0;
    */
    int opcao;

    do {
        inicializarJogo();
        sortearBombas(20);
        contarBombas();
        printf("\n\t\t\tCAMPO MINADO\n");
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
} ///////////////////END MAIN/////////////////





/*              Para descobrir a quantidade de bombas vizinhas à uma posição é necessário olhar para seus quatro vinhos, 
                acima, abaixo, à direita e à esquerda. Para isso desenvolveremos algumas funções adicionais que ajudarão 
                a resolver este problema.

                A primeira função que desenvolveremos é para verificar se uma 
                determinada coordenada é válida ou não. Imagine a posição 0 0. 
                A coordenada acima seria -1 0. Contudo, esta coordenada é inválida. 
                Precisamos prever isso. A função a seguir faz exatamente isso. 
                Retorna 1 se a coordenada for válida e 0 caso contrário.
*/

/*
    função que diz se um par de coordenadas é válido ou não
    1 - é válido
    0 - não é válido
*/
int coordenadaEhValida(int l, int c){
    if(l >= 0 && l < tam && c >= 0 && c < tam)
        return 1;
    else
        return 0;
}

/*
    Agora vamos implementar uma função para contar a quantidade de bombas 
    na vizinhança de uma coordenada. A próxima função verifica os quatro 
    vizinhos de uma coordenada,conta a quantidade de bombas e retorna este valor.




    função que retorna a quantidade de bombas na vizinhança de l c
    n - quantidade de bombas
*/
int quantBombasVizinhas(int l, int c){
    /*  l - 1 e c
        l + 1 e c
        l e c + 1
        l e c - 1
    */
    int quantidade = 0;

    if(coordenadaEhValida(l - 1, c) && jogo[l-1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida(l + 1, c) && jogo[l+1][c].eBomba)
        quantidade++;
    if(coordenadaEhValida(l, c + 1) && jogo[l][c+1].eBomba)
        quantidade++;
    if(coordenadaEhValida(l, c - 1) && jogo[l][c-1].eBomba)
        quantidade++;
    return quantidade;
}




/*
    Por fim, vamos agora implementar um procedimento que irá percorrer toda a 
    matriz e, para cada posição,fará uso da função anterior para descobrir 
    a quantidade de bombas na vizinhança daquela posição.

*/

// procedimento para contar as bombas vizinhas
void contarBombas(){
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++)
            jogo[l][c].vizinhos = quantBombasVizinhas(l, c);
    }
}


// procedimento para imprimir o jogo
void imprimir(){

    printf("\n\n\t    ");
    for(l = 0; l < tam; l++)
        printf(" %d  ", l); // índices das colunas
    printf("\n\t   -----------------------------------------\n");
    for(l = 0; l < tam; l++){
        printf("\t%d  |", l); // índices das linhas
        for(c = 0; c < tam; c++){
            if(jogo[l][c].estaAberta){
                if(jogo[l][c].eBomba)
                    printf(" * "); // se for bomba, imprime *
                else
                    printf(" %d ", jogo[l][c].vizinhos); // imprime quantidade de bombas vizinhas
            }
            else
                printf("   "); // imprime três espaços quando está fechada
            printf("|"); // barra que forma as linhas verticais
        }
        printf("\n\t   -----------------------------------------\n");
    }
}


/*  Outro detalhe importante é que cada célula pode ser aberta apenas uma vez. 
    Assim, também precisamos verificar se a coordenada jogada ainda está fechada. 
    A leitura de uma coordenada deverá se repetir até que seja digitada uma
    coordenada válida e ainda fechada 
*/
// procedimento jogar que faz a leitura das coordenadas
void jogar(){
    int linha, coluna;

    do{
        printf("\nDigite as coordenadas de linha e coluna: ");
        scanf("%d%d", &linha, &coluna);

        if(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
            printf("\nCoordenada invalida ou ja aberta!");
    }while(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);

    abrirCelula(linha, coluna);
}

//Agora que temos uma coordenada válida e fechada, precisamos abrir essa posição. Abrir uma posição é basicamente 
//atribuir 1 ao campo estaAberta
/*
Ao abrir uma posição, caso ela possua zero bombas na vizinhança, 
precisamos também  abrir seus vizinhos. Isso pode ser feito com quatro 
chamadas recursivas, uma para cada vizinho. 

Como os índices desses vizinhos são obtidos por meio de somas e subtrações, 
é algumas situações teremos índices inválidos. 

Para identificar esses índices, precisamosnovamente verificar 
se são válidos e se estão fechados (no início do procedimento), 
senão teremos erros e/ou loops infinitos nesse passo.

*/
// procedimento para abrir a coordenada digitada pelo usuário
void abrirCelula(int l, int c){
    if(coordenadaEhValida(l, c) == 1 && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if(jogo[l][c].vizinhos == 0){
            /*
                l-1 e c acima
                l+1 e c abaixo
                l e c+1 direita
                l e c-1 esquerda
            */
            abrirCelula(l-1, c);
            abrirCelula(l+1, c);
            abrirCelula(l, c+1);
            abrirCelula(l, c-1);
        }
    }
}

// procedimento para abrir a coordenada digitada pelo usuário
void abrirCelula(int l, int c){
    if(coordenadaEhValida(l, c) == 1 && jogo[l][c].estaAberta == 0){
        jogo[l][c].estaAberta = 1;
        if(jogo[l][c].vizinhos == 0){
            /*
                l-1 e c acima
                l+1 e c abaixo
                l e c+1 direita
                l e c-1 esquerda
            */
            abrirCelula(l-1, c);
            abrirCelula(l+1, c);
            abrirCelula(l, c+1);
            abrirCelula(l, c-1);
        }
    }
}

// procedimento jogar que faz a leitura das coordenadas
void jogar(){
    int linha, coluna;

    do{
        printf("\nDigite as coordenadas de linha e coluna: ");
        scanf("%d%d", &linha, &coluna);

        if(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
            printf("\nCoordenada invalida ou ja aberta!");
    }while(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);

    abrirCelula(linha, coluna);
}

/* 
Para identificar vitória é necessário que esteja claro 
o que significa a vitória no Jogo Campo Minado. 
O jogador ganha no Campo Minado quando ele consegue 
abrir todas as posições que não são bombas
. Assim, para saber se o jogador venceu, 
basta contarmos a quantidade de casas fechadas que ñ sao bombas
se esse valor for exatamente zero entao o jogador ganhou.

Ou seja, a função abaixo verifica a vitória 
(conta a quantidade de casas fechadas que não são bombas)
    n > 0 - não ganhou ainda
    0 - ganhou
*/
int ganhou(){
    int quantidade = 0;

    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            if(jogo[l][c].estaAberta == 0 && jogo[l][c].eBomba == 0)
                quantidade++;
        }
    }
    return quantidade;
}


/* 
    Vamos agora atualizar nosso procedimento jogar. 
    A leitura de coordenadas e a abertura de cada coordenada precisa acontecer 
    até que o jogador vença ou até que uma bomba seja aberta. 
    Para isso, vamos colocar mais uma estrutura de repetição do tipo faça enquanto. 
    Outra alteração é a retirada do procedimento imprimir do main, que agora 
    ficará dentro desta nova repetição, para imprimir novamente o tabuleiro a cada 
    nova coordenada digitada

Quando a repetição terminar, significa que ou o jogador ganhou ou ele abriu uma bomba. 
Usamos um if para descobrir o que aconteceu e imprimir uma mensagem na tela.
*/
// procedimento jogar que faz a leitura das coordenadas
void jogar(){
    int linha, coluna;

    do{
        imprimir();
        do{
            printf("\nDigite as coordenadas de linha e coluna: ");
            scanf("%d%d", &linha, &coluna);

            if(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
                printf("\nCoordenada invalida ou ja aberta!");
        }while(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);

        abrirCelula(linha, coluna);
    }while(ganhou() != 0 && jogo[linha][coluna].eBomba == 0);

    if(jogo[linha][coluna].eBomba == 1)
        printf("\n\tQue pena! Voce perdeu!!!\n");
    else
        printf("\n\tPARABENS! VOCE GANHOU!!!\n");

    imprimir();
}