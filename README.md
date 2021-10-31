

# PrograminC
### Uma abordagem: strings em C 
 
![GitHub language count](https://img.shields.io/github/languages/count/maliarte/PrograminC?style=plastic)
![GitHub top language](https://img.shields.io/github/languages/top/maliarte/PrograminC)

![](https://github.com/Maliarte/images/blob/master/new-writter-maliarte.jpg)

Linguagem de baixo nível com um mínimo de abstrações em relação a Assembly. Concomitantemente ela é suficientemente expressiva, de modo a elucidar ideias gerais aplic[aveis a todas as linguagens de programação, exemplo: sistemas de tipos ou polimorfismo.

C não oferece quase nenhuma abstração sobre a memória, portanto a tarefa de gerenciamento de memória é de responsabilidade do programador. De modo diferente das linguagens de alto nivel como C# ou Java, o programer deve alocar e liberar a memoria reservada por conta propria, em vez de contar com um sistema automatizado de coleta de lixo (garbage collection)

C é portatil, sendo escrito corretamente podera ser .exe em outras arquiteturas depois de uma simples recompilação. Devido o modelo de computacao em C é pratimente igual ao velho e bom von Neumann, o que o torna muito parecido com os modelos de programacao da maioria dos processadores.

Quando aprender C lembre-se: apesar da ilusão de ser uma linguagem de alto nivel, ela nao tolera erros e nem sempre esses são avisados.

Estrutura do programa

QQr programa em C constitui-se de
- Definicoes de tipos de dados (estruturas, tipos novos etc) baseados em outros tipos existentes.
-Variaveis globais (declaradas out Funcao). Por exemplo, podemos criar uma variavel global i_am_global_girl do tipo int, inicializada com 42, fora do escopo de qqr funcao. Observacao: variaveis globais sao inicializadas apenas com valores constantes.
int i_am_global_girl = 42;

- Funcoes. Por exemplo, uma funcao chamada square, que aceite um argumento x do tipo int e devolva o seu quadrado: 

int square(int x){ return x*x;}

- Comentarios /* livreiro */ //resumao 

- Diretivas de pré-processador e de compilador, da-lhe tralha #
#define I_GIRL = 42
#define ADD(x,y) (x) + (y)

-Inside função pode-se definir variaveis ou tipos de dados locais a essas funcoes ou executar ações. Cada ação é uma instrução e eh encerrada com ;

-Nao cabe recursividade (f:f)

- As instrucoes declaram variaveis, fazem calculos e atribuicoes e executam diferentes ramos de codigo, dependendo de condicoes. Um caso especial eh um bloco entre chaves {}, usado para agrupar instrucoes. 

- A funcao printf eh usada para exibir strings nos stdout. Esta tem algumas partes basicas, como o especificador de formatos (%here)

- N use printf para formatar saidas sempre que possivel utiliza puts no lugar de printf. Esta funcao e capaz de exibir apenas uma string (e faz com que ela termine com uma quebra de linha ); nenhum espeficador de formato sera considerado. Ela nao so e mais rapida como tamvem funciona uniformemente com todas as strings, alem de nao ter as falhas de seguranca.

- Por enquanto iniciarei meus programas com a a diretiva #include<stdio>. Ela nos permite acessar uma parte da biblioteca-padrao de C. Contudo, afirmamos peremptoriamente que esse nao e nenhum tipo de importacao de bibliotexa e jamais devera ser tratado como uma.

-Um literal e uma sequencia de caracteres no codigo-fonte, representando um valor imediato. Em C ha literais para

-inteiros, por ex, 42; ...Pesquise neste repositorio.../helloCompiler.c
- numeros de ponto flutuante como 42.0;
-caracteres de codigo ASCII escritos entre aspas simples, 'a';
-ponteiros para strings terminadas com nulo, por ex: "abcde".

A .exe de qqr programin C eh essencialmente uma manipulacao de dados. 

A maquina abstrata de C tem uma arquitetura de Von neumann. Isso foi feito de proposito porque C e uma linguagem que deve ser o maximo possivel proxima do hardware. As variaveis sao armazenadas na memoria linear, e cada uma delas tem um endereco de inicio.

Podemos pensar nas variaveis como rotulos, (labels) em Assembly.

- Tipos de Dados:
Tudo que ocorre eh uma manipulacao de dados, a natureza desses dados eh de interesse particular para nos. Todo dado em C tem um tipo, o que significam que ele se enquadra em uma das categoriais (em geral) distintas. A tipagem em C eh fraca e estatica.

Tipagem estatica significa que todos os tipos sao conhecidos em tempo de compilacao. Nao pode haber absolutamente nenhuma incerteza sobre os tipos de dados. Independentemente de voce estar usando uma variavel, um literak ou uma expressao mais complexa avaliada como algum dado, seu tipo sera conhecido.

Tipagem Fraca significa que as vezes, um elemento de dado podera ser implicitamente convertido em outro tipo quando apropriado.

Como exemplo, ao aavaliar 1 + 3.0, esta claro que esses dois numeros tem tipos diferentes. Um deles eh int e o outro float, numero real. Nao podemos soma-los diretamente porque sua representacao binaria difere. Eh necessario converte-los para o mesmo tipo ( provavelmente, para um numero de ponto flutuante). Somente entao poderemos efetuar uma adicao. Em linguagens fortemente tipadas, como OCalm, essa operacao nao eh permitida, em vez disso, ha duas operacoes distintas para somar numeros: uma que atua em inteiros( escrita com +) e outra para numeros reais escrita com +. em OCaml)

A tipagem fraca esta presente em C por um motivo conhecido: em Assembly, eh totalmente possivel tomar praticamente qualquer dadoe interpreta-lo como um dado de outro tipo(um ponteiro como um inteiro, parte de uma string como um inteiro etc.) Para ver oq acontece quando tentamos exibir um valor de ponto flutuante como um inteiro (ver_programinC_/float_reinterpret.c)

Para esta seçao introdutoria consideramos que qualquer tipo em C se enquadra em uma das seguintes categorias:

-num. int (int, char...);
-num.float(double e float);
-tipos ponteiro;
-tipos compostos:estruturas(strutures) e unioes(unions)
-enumeracoes;

Se vc tem experiencia anterior com alguma linguagem de alto nivel, talvez perceba similaridades, que nao foram aqui expostas.
Infelizmente nao ha strings nem tipos booleanos em C

Controle de Fluxo

De acordo com os principios de Von Neumann, a .exe do programa eh sequencial. Cada instrucao eh .executada uma apos outra. Porem ha varias instrucoes para alterar o controle do fluxo.

Ifzao, do corason (Ver_LanguageC_TDD_if_example.c)
 
 
 Referencias
 
 http://files.dtsilva.webnode.pt/200000087-adb28aeac7/Sebenta_C.pdf
