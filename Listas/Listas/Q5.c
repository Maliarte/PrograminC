/* Comentarios*/

L1: 1 2 3 4		TRUE
L2: 1 2 3 4

L1: 4 1 3 2		TRUE
L2: 1 2 3 4

L1: 3 2 1 4 1 3 2		TRUE
L2: 1 2 3 4

//verifica se todo mundo de l1 ta l2 ERROR
L1: 1 2 3		FALSE
L2: 3 |4| 2 1

//CORRETO compara a L2 com L1 tb
L1: 1 2 3 1 2 3		FALSE
L2: 3 4 2 1


/* E SE... restrição coloca lista maior na frente

lista maluca 

L1: 1 2 3 1 2 3		FALSE
L2: 3 4 2 1

*/