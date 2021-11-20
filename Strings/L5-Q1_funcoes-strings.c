/*
	FPR - Fundamentos de Programação
	
    Marília Silva | https://maliarte.com.br  
    
    * Apoie o projeto de educação tecnológica no Brasil 
    * deixe uma estrela e saiba mais no instagram @maliartemar!
	
	STRINGS
	
	Exemplo: uso de funções de manipulação de strings (strlen, strcpy, strcat, strcmp).		

	obs: por default na chamada passa-se os argumentos na declaracao os parametros

*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//main
void main ()
{
	printf("\n||||||||||||||||||||||||||||||| STRLEN ()||||||||||||||||||||||||||||||||||||||\n\n");
									//exemplo de uso da função strlen:


	//declaração de variáveis
	char str1[30], str2[30], str3[30];
	int quant;
	
	//lendo a primeira string
	fflush (stdin);
	printf ("Entre com uma string: ");
	gets (str1);
	
	//exibindo a string lida e a quantidade de caracteres dela (uso da função strlen)
	quant = strlen (str1);

    printf("\nUtilizando a funcao strlen();");
	printf ("\nA String:[%s] possui %d caracteres\n", str1, quant);
	printf ("\nString: %s (%d caracteres)\n", str1, strlen (str1));
	
	printf("\n||||||||||||||||||||||||||||||||||STRCPY ()|||||||||||||||||||||||||||||||||||");
	

									//exemplo de uso da função strcpy:

    printf("\nUtilizando a funcao strcpy;");
    
	printf ("\nStr2:%s (%d caracteres)", str2, strlen(str2)); //lixo

    //primeiro argumento recebe o valor do segundo: 
	strcpy (str2, str1);	
	printf ("\nStr2: %s - strcpy(str2,str1)\n", str2);			//válido
	strcpy (str2, "TESTE");										//válido
	printf ("\nStr2: %s - strcpy(str2,string)\n", str2);	

	//strcpy ("TESTE", str2); inválido! o primeiro argumento precisa ser uma variável
		

	printf("\n|||||||||||||||||||||||||||||||||||STRCAT|||||||||||||||||||||||||||||||||||||");


								//exemplo de uso da função strcat

	printf ("\nExemplo do uso de strcat:\n");

	printf ("\nStr3: %s (%d caracteres)\n", str3, strlen(str3)); //lixo de memória

	strcpy (str3, str1);			//copia o conteúdo de str1 para str3

	printf ("\nStr3: %s (%d caracteres)\n", str3, strlen(str3));

	strcat (str3, str2);			//concatena o conteúdo de str2 à string str3

	printf ("\nStr3: %s (%d caracteres)\n", str3, strlen(str3));
	

	printf("\n||||||||||||||||||||||||||||||||||STRCMP||||||||||||||||||||||||||||||||||||||");
								//exemplo de uso da função strcmp

	/* strcmp
			Sintaxe:

			variável do tipo inteiro = strcmp(string1, string2);

			Compara o conteúdo de duas strings;

			Possíveis valores de retorno:

			0: conteúdo das strings são iguais

			< 0: conteúdo da string1 é menor do que string2

			> 0: conteúdo da string1 é maior do que string2

			Comparação em relação à TABELA ASC (INTEIROS) e retorna a diferença

	*/

	printf ("\nExemplo do uso de strcmp:\n");
	strcpy (str1, "ALGORITMOS");
	strcpy (str2, str1);
	strcpy (str3, "TESTE");
	
	printf ("str1: %s", str1);
	printf ("\nstr2: %s", str2);
	printf ("\nstr3: %s", str3);
	
	printf ("\n\nComparando str1 e str2: %d", strcmp(str1,str2));
	printf ("\n\nComparando str1 e str3: %d", strcmp(str1,str3));
	printf ("\n\nComparando str3 e str2: %d", strcmp(str3,str2));	
}
