/* 
    Todo programa deve começar 
    ...
    Com um comentário, seguido da data e o horário. sqn

    31/01/22 - Rio,
    "Seu sonho é sua vida, e sem vida se morre, se mata"

    Entenda a memória de uma vez por todas (dial) - meid 
    ("espaço para programas - CONVENÇÃO src") 
                                            
          _______________________________
        |   programas nativos DRIVES     |
        |   0xFFFFFFFF                   |
        |                                |                                 
        |    k. space                    |
        | _______________________________                              
        |                                |
        |                                |
        |        stack                   |
        |                                |      middle: o mais obvio pode ser substancialmente o mais devastador
        |                                |
        | _______________________________|                              
        |         HEAP                   |
        |                                |
        |    a. (*-*) users              |
        |    0x00000000                  |
          _______________________________

-> AQUI para quem veio do escopo_funcao (record)
* signed int: -9.076
* unsigned int:4.294.958.220
* |1|1111111111111111101110010001100 
* |1| no  inicio..:
ENDEREÇO NEGATIVO || Trata-se da parte mais alta da memoria (stack?)(pilha?) maybe. 

* 11111111111111111111111111 [64* HIGH LEVEL]   |
* 00000000000000000000000000 [64* LOW LEVEL]    |

 ~~~~~~~~~ Mensure a dimensão; console pow ~~~~~~~~~
ISA 
Set Instruction Archtecture

            OLD MACHINES SET: X32
                2³²  = 4.294.967.296 bytes = 4 GB

            NEW MACHINES SET X64
                2^64 = (2³²)² : Não dobramos a capacidade de memória, a quadruplicamos, ou seja ^ 4.
            
                    MAX_THEORY..:
                    2^64 =   18.446.744.073.709.551.616 bytes  =  16 exabytes (*) append para bts

     (?) - nenhum chip que a intel ou AMD fabriquem suportam mapear esse TAM
     Costumam ser "capados" em 42 || 48 bits - ao enves de 64

---- o sistema operacional, mente, portanto, com o aval da VM.
Ele faz que é "tudo akilo"
mas só possui parte dessa pompa.
*/