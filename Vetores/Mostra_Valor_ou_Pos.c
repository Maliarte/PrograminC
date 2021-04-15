/ *
* Receba um array e peça ao usuário o número da posição e mostre seu valor. Termina quando o
 * posição é inválida.
 * /

# inclui  < stdio.h >
# inclui  < stdlib.h >
# inclui  < time.h >

# define  CONTROL  20  // Elemento de divisão em rand ()

int  creatArray ( int ve [], int tamanho);
void  showArray ( int array [], elementos int );
vazio  showArrayPosition ( int v [], int posição, int tamanho);

int  main ( void ) {
	tamanho interno ;
	posição interna ;

	srand ( tempo ( NULL ));
	
	printf ( " Digite o tamanho do array ou 0 para sair do programa: " );
	scanf ( " % d " , & size);
	int a [tamanho];
	enquanto (tamanho> 0 ) {
		a [tamanho] = creatArray (a, tamanho);
		
		printf ( " [ " );
	
		para ( int i = 0 ; i <tamanho; i ++) {
			if (i == size- 1 ) {
				printf ( " % d ] " , a [i]);
			} else  printf ( " % d , " , a [i]);
		} 
		
		printf ( " \ n " );
		
		printf ( " Insira a posição da matriz: " );
		scanf ( " % i " , & posição);
		
		showArrayPosition (a, posição, tamanho);
		
		printf ( " \ n " );
		printf ( " Digite o tamanho da próxima matriz ou 0 para sair do programa: " );
		scanf ( " % d " , & size);
	}
	
	return  0 ;
}

// ////////////////////////////////////////////////////// /////////////////////
// /////////////////////////////// FUNCTIONS ////////////////////// /////////
// ////////////////////////////////////////////////////// /////////////////////
int  creatArray ( int v [], int size) {
		
	para ( int i = 0 ; i <tamanho; i ++) {
		v [i] = rand ()% CONTROLE;
	}
		
	retornar v [tamanho];
}
// ////////////////////////////////////////////////////// /////////////////////
void  showArray ( int array [], int elements) {
	
	printf ( " [ " );
	
	para ( int i = 0 ; i <elementos; i ++) {
		if (i == elementos- 1 ) {
			printf ( " % d ] " , array [i]);
		} else  printf ( " % d , " , array [i]);
	} 
	
	printf ( " \ n " );
	
	retorno ;
}
// ////////////////////////////////////////////////////// /////////////////////
vazio  showArrayPosition ( int ve [], int posição, int tamanho) {
	condição interna = ((posição <tamanho) && (posição> = 0 ));
	
	while (condição) {
		printf ( " a [ % i ] = % i \ n " , posição, ve [posição]);
		printf ( " Insira a próxima posição da matriz: " );
		scanf ( " % i " , & posição);
		condição = ((posição <tamanho) && (posição> = 0 ));
	}
		
	if (! condição) {
		printf ( " Posição inválida \ n " );
	}
		
	retorno ;
}
// ////////////////////////////////////////////////////// /////////////////////
