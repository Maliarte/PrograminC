/*

origem: https://www.ic.unicamp.br/~norton/disciplinas/mc1022s2005/03_11.html

ALOCAÇÃO DINÂMICA

    Até agora tínhamos que declarar todas as variáveis que íamos usar no programa, 
    para que o computador pudesse alocar memória para elas. A questão então era: 
    há um modo de eu criar uma variável, ou seja, definí-la, enquanto o programa 
    roda (sem ter que tê-la incluido no código)? A resposta é: não exatamente.
    Não há como declarar a variável enquanto o programa roda. O que dá para fazer 
    é alocar memória para uma variável enquanto o programa roda.

    E qual a vantagem disso? 
    Poupa memória. Porém isso vem com um preço (como tudo na computação) - gasta mais processamento.

    E como fazemos isso? 
    Com a função malloc e free. 

    Malloc aloca um determinado número de bytes na memória, 
    retornando um ponteiro para o primeiro byte alocado, ou NULL caso não tenha conseguido alocar. 

    Free, por outro lado, libera o espaço alocado. 
    Ambas funções pertencem à biblioteca stdlib.h. 

Veja um exemplo:
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *c; /* o ponteiro para o espaço alocado */

	
	c = (char *)malloc(1); // aloco um único byte na memória 

	/* vejo se conseguiu alocar */
	if (!c) {
		printf("Não conseguiu alocar a memória\n");
		exit(1);
	}

	/* carrego um valor na região de memória alocada */
	*c = 'd';

	/* escrevo este valor */
	printf("%c\n",*c);

	/* libero a memória alocada */
	free(c);

/*		
Agora vamos por partes. De início, o que fizemos? Declaramos um ponteiro para caracter. 
Logo em seguida, usamos malloc para alocar um byte na memória. 
Por que 1 byte? Porque este é o tamanho de um caracter.

Mas não foi somente isso que fizemos. Quando malloc aloca a memória, ela não faz 
idéia do que será posto lá - se é inteiro, caracter, float ou o que for. 
Então ela retorna um ponteiro genérico (void *). 

Isso só é possível porque ponteiros são endereços de memória e, 
como tal, possuem sempre o mesmo tamanho, não importando o tipo para o qual eles apontam.

Contudo, como já vimos, o C precisa que o ponteiro tenha um tipo, 
para poder executar operações de aritmética de ponteiros. 

Por isso temos que fazer um cast no retorno de malloc para o tipo de ponteiro. 
No nosso caso, como queríamos um ponteiro para caracter, forçamos a saída de malloc a ser "char *".

E por que testamos c acima? 

Lembra que malloc retorna NULL se não alocar memória? 
Pois bem, NULL tem valor zero, ou seja, falso. 

Então a gente tem somente que testar o ponteiro onde guardamos o endereço da variável supostamente alocada. Se esse ponteiro for NULL, então houve erro. O código:
*/
	if (!c)
}
/*		
                equivale a:

                    if (c == NULL)
		
    No caso de c ser NULL, damos uma mensagem de erro e encerramos o programa. 
    Se c não for NULL, então ele contém o endereço na memória onde cabe um caracter. 
    Agora é só agir como faríamos com um ponteiro que apontou para uma variável char, 
    guardando um valor na região de memória apontada e lendo o valor de lá.
    Após tudo isso, temos que liberar a memória alocada, usando free. 
    Note que free recebe o ponteiro para a região de memória alocada. 
    Embora seja ótima prática sempre desalocar a memória alocada, 
    no exemplo acima ela é desnecessária, uma vez que, após o termino do 
    programa, o computador desaloca qualquer memória alocada por ele.

Mas veja que há algo estranho. 

Se o C desaloca a memória automaticamente ao fim do programa, 
não seria melhor ter apenas definido um char e usado? 
Pouparia a memória reservada para o ponteiro, além do tempo gasto na alocação e liberação da memória.

Certamente, no exemplo acima fizemos um programa que fica mais lento 
e ocupa mais memória que se fizéssemos ele sem alocação. 
Contudo, imagine uma situação onde você tem um mínimo de memória 
e precisa usar uma variável (um double, por exemplo) somente no início do programa. 
Se o seu programa for grande o suficiente, você vai declarar este double no início, 
usar, e segurar a memória alocada até o fim. Um jeito de minimizar este problema 
seria declarar um ponteiro para double, alocá-lo, e depois de usar, liberá-lo. 
Assim:
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
	double *n; /* o ponteiro para o espaço alocado */

	n = (double *)malloc(???);

	/* vejo se conseguiu alocar */
	if (!n) {
		printf("Não conseguiu alocar a memória\n");
		exit(1);
	}

	/* uso o double */
	...

	/* libero a memória alocada */
	free(n);

	/* o programa continua */
	...
}
/*		
    Perfeito. Agora a memória que ocupamos para n é o suficiente para caber um ponteiro, 
    que é menor que o double.
    Mas espere. O programa acima não funciona... não dissemos qual o tamanho de um double. 
    O que fazemos agora? Um jeito é consultar uma tabela e por o número de bytes de um double. 
    Mas isso é meio contra-produtivo. O outro modo é usar a função sizeof. Sizeof retorna o 
    número de bytes de um determinado tipo (inteiro, float, estrutura, o que for - exceto 
    vetores, strings e matrizes):
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	double *n; /* o ponteiro para o espaço alocado */

	n = (double *)malloc(sizeof(double));

	/* vejo se conseguiu alocar */
	if (!n) {
		printf("Não conseguiu alocar a memória\n");
		exit(1);
	}

	/* uso o double */
	

	/* libero a memória alocada */
	free(n);

	/* o programa continua */
	
}
/*		
Assim, podemos reescrever nosso programa do caracter acima:
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *c; /* o ponteiro para o espaço alocado */

	/* aloco um único byte na memória */
	c = (char *)malloc(sizeof(char));

	/* vejo se conseguiu alocar */
	if (!c) {
		printf("Não conseguiu alocar a memória\n");
		exit(1);
	}

	/* carrego um valor na região de memória alocada */
	*c = 'd';

	/* escrevo este valor */
	printf("%c\n",*c);

	/* libero a memória alocada */
	free(c);
}
		
//Mas e sizeof funciona somente para tipos? Nããão! Ele funciona também para variáveis:

int main() {
	int x;

	printf("Tamanho do x = %d\n",sizeof(x));
	printf("Tamanho do int = %d\n",sizeof(int));
}
		
/*E isso imprime:

Tamanho do x = 4
Tamanho do int = 4
		
                Alocação Dinâmica de Estruturas
                Conforme vimos, podemos também alocar estruturas inteiras. 
                Por exemplo, considere nossa estrutura para definir um círculo:
*/
struct s_pos {
	int x;
	int y;
};

struct s_circulo {
	struct s_pos c; /* centro do círculo */
	float r;        /* seu raio */
};
		
//Como faríamos para alocar um círculo? Da mesma forma que faríamos com uma variável comum:

#include <stdio.h>
#include <stdlib.h>

struct s_pos {
	int x;
	int y;
};

struct s_circulo {
	struct s_pos c; /* centro do círculo */
	float r;        /* seu raio */
};

int main() {
	struct s_circulo *p; /* o ponteiro para o espaço alocado */

	/* aloco espaço para um struct s_circulo */
	p = (struct s_circulo *)malloc(sizeof(struct s_circulo));

	/* vejo se conseguiu alocar */
	if (!p) {
		printf("Não conseguiu alocar a memória\n");
		exit(1);
	}

	/* carrego um valor na região de memória alocada */
	p->c.x = 2;
	p->c.y = 4;
	p->r = 3.2;

	/* escrevo a estrutura */
	printf("x = %d\n",p->c.x);
	printf("y = %d\n",p->c.y);
	printf("r = %f\n",p->r);

	/* libero a memória alocada */
	free(p);
}
		
/*Note o uso do operador -> com ponteiros para estruturas.


    Alocação Dinâmica de Vetores, Strings e Matrizes

*        Alocação Dinâmica de Vetores
        Vamos retornar ao nosso velho e bom vetor de notas. 
        Suponha que você quer tirar a média sobre n notas entradas 
        pelo usuário, como você faria? Pediria o n e então as n notas, 
        certo? E como guardaria? Até agora, tínhamos que declarar um mega 
        vetor e rezar para que n não fosse maior que nosso vetor. 
        Mas agora seus problemas acabaram! Veja como:
*/
int main() {
	float *v;   /* vetor de notas */
	int i;      /* contador */
	int n;      /* número de elementos do vetor */
	float nota; /* uma nota */

	/* peço o número de notas */
	printf("Qual o número de notas? ");
	scanf("%d",&n);

	/* aloco espaço suficiente para o vetor de n notas */
	if (!(v = (float *)malloc(n * sizeof(float)))) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}

	/* carrego o vetor de notas */
	for (i=0; i<n; i++) {
		printf("Entre a nota: ");
		scanf("%f",¬a);
		v[i] = nota;
	}

	/* imprimo o vetor */
	for (i=0; i<n; i++)
		printf("Nota: %f\n",v[i]);

	/* desaloco o vetor */
	free(v);
}
		
//Nassa! Novamente, vamos por partes...

/*Primeiro declaramos um ponteiro para float. Lembra o que

	float v[10];
		
    faz? Aqui o compilador aloca espaço na memória suficiente para guardar 10 floats, 
    guardando o endereço do primeiro (de fato, do primeiro byte do primeiro float)
    no ponteiro v. Ou seja, na declaração acima, v nada mais é que "float *" - ponteiro para float.

    Sendo assim, se declararmos um ponteiro para float, tudo que temos que 
    fazer para transformá-lo em um vetor é apontá-lo para um grupo seqüencial 
    de floats na memória. Bom, ao fazermos:*/

	v = (float *)malloc(n * sizeof(float)
    
    /*		
    é exatamente isso que estamos fazendo. Note que pegamos o tamanho de um 
    float e multiplicamos pelo número de floats (n) que o vetor conterá, 
    ou seja, calculamos o tamanho em bytes de n floats. Agora, por que fizemos isso:
    */

	if (!(v = (float *)malloc(n * sizeof(float)))) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}
		
//Por economia de espaço. O código acima é exatamente igual a este:

	v = (float *)malloc(n * sizeof(float));
	if (!v) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}
		
//Agora atente para esta parte do código:

	//carrego o vetor de notas 
	for (i=0; i<n; i++) {
		printf("Entre a nota: ");
		scanf("%f",¬a);
		v[i] = nota;
	}
		
/*Quando vimos ponteiros, também vimos que ao fazermos "v[i]" estamos fazendo, na verdade, "*(v+i)". 
Por isso pudemos tratar nosso ponteiro como um vetor comum.

Por fim, para desalocar nosso vetor, bastou passar o ponteiro v como parâmetro de malloc.

Alocação Dinâmica de Strings
O mesmo procedimento pode ser usado com strings. Strings nada mais são que vetores 
de caracteres terminados por '\0'. Então, para alocar um string, você deve fazer como 
em vetores, tomando apenas o cuidado adicional de levar o '\0' em conta:
*/
int main() {
	char *s;   /* o string */
	int n;     /* número de caracteres do string */

	/* peço o número de caracteres */
	printf("Qual o tamanho de seu string? ");
	scanf("%d",&n);

	/* limpo o buffer do lixo deixado pelo scanf */
	getchar();

	/* aloco espaço suficiente para o vetor de n notas */
	if (!(s = (char *)malloc((n+1) * sizeof(char)))) {
		printf("Não foi possível alocar o string\n");
		exit(0);
	}

	/* carrego o string */
	printf("Entre o string: ");
	gets(s);

	/* imprimo o string */
	printf("String: %s\n",s);

	/* desaloco o vetor */
	free(s);
}
		
/*Isso imprime:

Qual o tamanho de seu string? 5
Entre o string: abaco
String: abaco
		
Note que 5 foi o número de letras, de caracteres. O '\0' levamos em conta ao alocar (n+1) 
caracteres para o string.

Alocação Dinâmica de Matrizes
Como fazemos com matrizes? Apesar de matrizes serem vetores, o C complica nossa vida aqui. 
O problema é que o C exige saber das dimensões da matriz... e isso não é dado abaixo:
*/
int main() {
	int *m; /* matriz de inteiros */


	/* aloco espaço suficiente para a matriz 2 × 3 */
	if (!(m = (int *)malloc(2 * 3 * sizeof(int)))) {
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}

	/* carrego um elemento na matriz */
	m[1][1] = 2;

	/* desaloco a matriz */
	free(m);
}
		
/*Naturalmente, você pode substituir o "2*3" por "6". 
A multiplicação foi escrita para mostrar como calculamos o número de elementos. 
Ao compilar temos o seguinte erro:

error: subscripted value is neither array nor pointer
		
Como fazemos, então? Coxambramos: passamos o ponteiro como parâmetro para uma função 
(note que a função deve definir o tamanho da matriz):
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Pede ao usuário os elementos de uma matriz 2 × 3.

	Param:
		m - a matriz a ser carregada
*/
void carregaMatriz(int m[2][3]) {
	int i; /* contador */
	int j; /* contador */

	/* carrego a matriz */
	for (i=0; i<2; i++)
		for (j=0; j<3; j++) {
			printf("Entre m[%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
}

/*
	Escreve uma matriz 2 × 3 na tela.

	Param:
		m - a matriz
*/
void imprimeMatriz(int m[2][3]) {
	int i; /* contador */
	int j; /* contador */

	/* escreve a matriz */
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
}

int main() {
	int *m; /* matriz de inteiros */

	/* aloco espaço suficiente para a matriz 2 × 3 */
	if (!(m = (int *)malloc(2 * 3 * sizeof(int)))) {
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}

	/* carrego a matriz */
	carregaMatriz(m);

	/* imprimo a matriz */
	imprimeMatriz(m);

	/* desaloco a matriz */
	free(m);
}
		
/*Isso funciona, embora no gcc você vá ver a seguinte mensagem de advertência:

warning: passing arg 1 of `carregaMatriz' from incompatible pointer type
warning: passing arg 1 of `imprimeMatriz' from incompatible pointer type
		
Bom, é só ignorar essa mensagem, pois o programa está correto 
(alguns compiladores nem mostrarão a mensagem).

Mas e qual a vantagem disso? A mesma de alocar dinamicamente uma variável: 
se o código for grande e a matriz for usada somente no começo, é melhor 
declarar somente o ponteiro, já que, dependendo da matriz, ele pode ocupar 
BEM menos memória que se a matriz fosse toda declarada.

Tudo bem, mas isso é um caso especial. E se eu quisesse pedir ao usuário 
o número de linhas e colunas da matriz? Aí danou-se! Vai ter que trabalhar 
com aritmética de ponteiros, em vez de usar a sintaxe de matriz.

Lembra que quando fazemos "matriz[linha][coluna]" estamos, na verdade, 
fazendo "*(matriz + (linha*comprimento_da_linha) + coluna)", 
ou seja, "*(matriz + (linha*número_de_colunas) + coluna)"? 
Então, é assim que teremos que agir:
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Escreve uma matriz l × c na tela.

	Param:
		m - a matriz
		l - número de linhas
		c - número de colunas
*/
void imprimeMatriz(int *m, int l, int c) {
	int i; /* contador */
	int j; /* contador */

	/* escreve a matriz */
	for (i=0; i<l; i++) {
		for (j=0; j<c; j++)
			printf("%d\t", *(m + (i * c) + j));
		printf("\n");
	}
}

int main() {
	int *m; /* matriz de inteiros */
	int l;  /* número de linhas */
	int c;  /* número de colunas */
	int i;  /* contador */
	int j;  /* contador */

	/* peço o número de linhas e colunas */
	printf("Entre o número de linhas: ");
	scanf("%d", &l);
	printf("Entre o número de colunas: ");
	scanf("%d", &c);

	/* aloco espaço suficiente para a matriz l × c */
	if (!(m = (int *)malloc(l * c * sizeof(int)))) {
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}

	/* carrego a matriz */
	for (i=0; i<l; i++)
		for (j=0; j<c; j++) {
			printf("Entre m[%d][%d]: ",i,j);
			scanf("%d",(m + (i * c) + j));
		}

	/* imprimo a matriz */
	imprimeMatriz(m,l,c);

	/* desaloco a matriz */
	free(m);
}
/*		
Notou o uso do ponteiro tanto no corpo do programa quanto na função? 
A função caregaMatriz foi removida tão somente para exemplificar o uso no corpo principal. 
Ela poderia ter sido mantida.

Note também como passamos o elemento da matriz que queríamos carregar ao scanf: "(m + (i * c) + j)". 
Não precisamos usar o &. Por que? Porque ao usarmos o & com uma variável passávamos o endereço da 
variável. Pois bem, "(m + (i * c) + j)" já é um ponteiro para o elemento [i][j] da matriz, ou seja, 
já é seu endereço.

Mas espere... a matriz não é alocada como um mega vetor, onde as linhas vêm uma em seguida da outra?
Então podemos por um ponteiro no início da matriz e corrê-la como um vetor, não? O seguinte programa 
faz exatamente a mesma coisa que o anterior, só que sem usar que 

matriz[linha][coluna] → *(matriz + (linha*comprimento_da_linha) + coluna):
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Escreve uma matriz l × c na tela.

	Param:
		m - a matriz
		l - número de linhas
		c - número de colunas
*/
void imprimeMatriz(int *m, int l, int c) {
	int i;  /* contador */
	int j;  /* contador */
	int *p; /* auxiliar */

	/* aponto p para o primeiro elemento da matriz */
	p = m;

	/* escreve a matriz */
	for (i=0; i<l; i++) {
		for (j=0; j<c; j++) {
			printf("%d\t", *p);
			p++;
		}
		printf("\n");
	}
}

int main() {
	int *m; /* matriz de inteiros */
	int l;  /* número de linhas */
	int c;  /* número de colunas */
	int i;  /* contador */
	int j;  /* contador */
	int *p; /* auxiliar */

	/* peço o número de linhas e colunas */
	printf("Entre o número de linhas: ");
	scanf("%d", &l);
	printf("Entre o número de colunas: ");
	scanf("%d", &c);

	/* aloco espaço suficiente para a matriz l × c */
	if (!(m = (int *)malloc(l * c * sizeof(int)))) {
		printf("Não foi possível alocar a matriz\n");
		exit(0);
	}

	/* aponto p para o primeiro elemento da matriz */
	p = m;

	/* carrego a matriz */
	for (i=0; i<l; i++)
		for (j=0; j<c; j++) {
			printf("Entre m[%d][%d]: ",i,j);
			scanf("%d",p); /* note que passei p, ou seja, o endereço */
			p++;
		}

	/* imprimo a matriz */
	imprimeMatriz(m,l,c);

	/* desaloco a matriz (poderia ser free(p), tanto faz) */
	free(m);
}
/*
		
Essa versão, apesar de ocupar mais memória (o ponteiro auxiliar), é mais rápida, pois poupa as multiplicações (i * c), além não precisar sempre buscar i, c e j na memória (o que também gasta tempo).

Note também que poderíamos ter substituido o*/

	for (i=0; i<l; i++)
		for (j=0; j<c; j++)
		
//Por um mero

	for (i=0; i<(l*c); i++)
		
//E como essa versão funciona? Pelo modo como o C aloca uma matriz. Quando fazemos

	int m[2][3];
		
//o C aloca espaço suficiente para 6 inteiros, um ao lado do outro:


//Uma atribuição do tipo

	m[1][1] = 3;
		
/*só funciona se o compilador conhecer o comprimento da linha, aí ele sabe que tem que andar, 
no caso acima, uma linha inteira mais 2 casas, ou seja, cairá em:


o que corresponde a *(m + 1 * 3 + 1) → *(m + 4). Por isso se colocarmos um ponteiro no início 
da matriz, podemos correr com ele e estaremos percorrendo a matriz. O truque é saber quando a 
linha termina (múltiplos do número de colunas).

Retorno de Ponteiros
Agora imagine que queiramos fazer uma função que aloque a matriz, 
inicialize seus dados, e a libere para uso do programa. Como fazemos? 
Já vimos que não podemos retornar uma matriz... poderíamos passar como parâmetros... 
mas opa! Quando passávamos a matriz como parâmetro já a tínhamos alocada 
(de fato, neste caso teríamos que passar um ponteiro para o ponteiro da matriz!). 
Então como fazer o programa tomar conhecimento dela? Simples... basta retornar o 
ponteiro para a matriz. Veja:
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Cria e zera uma matriz. Retorna um ponteiro para a matriz recebida ou NULL em caso de erro.

	Param:
		l - o número de linhas
		c - o número de colunas
*/
int *criaMatriz(int l, int c) {
	int *p; /* a matriz */
	int *q; /* auxiliar */
	int i;  /* contador */

	/* aloco a matriz */
	p = (int *)malloc(l * c * sizeof(int));

	/* se não conseguiu, acuso erro */
	if (!p) return(NULL);

	/* zero a matriz */
	q = p;
	for (i=0; i<(l*c); i++, q++)
		*q = 0;

	/* retorno a matriz */
	return(p);
}

/*
	Escreve uma matriz l × c na tela.

	Param:
		m - a matriz
		l - número de linhas
		c - número de colunas
*/
void imprimeMatriz(int *m, int l, int c) {
	int i; /* contador */
	int j; /* contador */

	/* escreve a matriz */
	for (i=0; i<l; i++) {
		for (j=0; j<c; j++)
			printf("%d\t", *(m + (i * c) + j));
		printf("\n");
	}
}

int main() {
	int *m; /* matriz de inteiros */
	int l;  /* número de linhas */
	int c;  /* número de colunas */
	int i;  /* contador */
	int j;  /* contador */

	/* peço o número de linhas e colunas */
	printf("Entre o número de linhas: ");
	scanf("%d", &l);
	printf("Entre o número de colunas: ");
	scanf("%d", &c);

	/* crio a matriz */
	m = criaMatriz(l,c);

	/* vejo se houve problema */
	if (!m) {
		printf("Erro na criação da matriz\n");
		exit(1);
	}

	/* imprimo a matriz */
	imprimeMatriz(m,l,c);

	/* desaloco a matriz */
	free(m);
}
/*		
Agora repare na função criaMatriz. Por que usei um q? Porque se eu incrementar p, 
ele não mais apontará para o início da matriz, ou seja, ao final da operação de 
zerar a matriz, teria que voltar com ele, o que não é muito seguro.

Note também que a função retorna um ponteiro para inteiro, ou seja, seu tipo de retorno é "int *".

Mas espere... não é verdade que ao sairmos da função toda a memória que ela alocou 
será desalocada? Sim, mas isso vale apenas para definições de variáveis! 
Vamos olhar mais de perto o segmento abaixo:
*/

int *criaMatriz(int l, int c) {
	int *p; /* a matriz */
	int *q; /* auxiliar */
	int i;  /* contador */

	/* aloco a matriz */
	p = (int *)malloc(l * c * sizeof(int));

	/* se não conseguiu, acuso erro */
	if (!p) return(NULL);

	/* zero a matriz */
	q = p;
	for (i=0; i<(l*c); i++, q++)
		*q = 0;

	/* retorno a matriz */
	return(p);
}
/*		
Quando fazemos malloc, pedimos ao sistema operacional para alocar memória. 
Este aloca e nos dá um ponteiro a ela. 
Ao final do nosso programa o sistema operacional irá desalocar toda memória que alocou para o programa. 

Por isso o free antes do final do main não era necessário (embora seja boa prática). 
Dessa forma, a memória alocada por malloc somente será liberada ao final do programa, 
ou ao darmos um free.

E o que será desalocado dentro de criaMatriz? 
Toda e qualquer variável ou parâmetro alocados por ela. 
No caso acima, l, c, p, q e i serão desalocados. 
Por isso retornamos o conteúdo de p (o endereço da matriz). 
Ao retornarmos p, estamos copiando o conteúdo de p para fora da função. 
Ou seja, neste caso, estamos copiando o endereço do primeiro byte da matriz (o conteúdo de p) 
para fora da função.

*/
