/ *
 * Mostra a matriz recebida na ordem inversa
 * /
 
# inclui  < stdio.h >

void  reverseArray ( int array [], int size);
 
int  main ( void ) {
	int v1 [ 5 ];
	tamanho interno ;
	para ( int i = 0 ; i < 5 ; i ++) {
		printf ( " Insira o valor do array: " );
		scanf ( " % i " , & v1 [i]);
	} 
	
	size = ( sizeof (v1)) / ( sizeof (v1) [ 0 ]);
	reverseArray (v1, tamanho);
	 
	return  0 ;
}

void  reverseArray ( int array [], int size) {
	
	printf ( " Matriz original \ n [ " );
	
	para ( int i = 0 ; i <tamanho; i ++) {
		if (i == tamanho - 1 ) {
			printf ( " % d ] " , array [i]);
		} else  printf ( " % d , " , array [i]);
	} 
	
	printf ( " \ n Array em modo reverso \ n [ " );
	
	para ( int i = tamanho- 1 ; i> = 0 ; i -) {
		if (i == ( 0 )) {
			printf ( " % d ] " , array [i]);
		} else  printf ( " % d , " , array [i]);
	} 
	retorno ;
}