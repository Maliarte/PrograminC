///////////////////////////////////////////////////////////////////////////////
//////////////////////////  DESCRIÇÃO DO PROBLEMA  ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
 * Uma grande rede supermercadista destinou uma parte de suas gôndolas para que alguns pequenos
 * comerciantes locais pudessem colocar seus produtos à venda. Nessa estratégia foram 
 * disponibilizadas 10 seções com códigos sequenciais. Em cada uma destas seções o interessado 
 * deve informar a quantidade de produtos a venda e o valor desses produtos. As 10 posições 
 * disponíveis podem ou não ser todas ocupadas.
 * 
 * Após a inserção dos dados devem ser exibidos alguns relatórios:
 * a) Quantidade de posições ocupadas;
 * b) Posição com mais ítens para venda;
 * c) Produto com maior valor;
 * d) Média de valor dos produtos inseridos;
 * e) Valor total de produtos e quantidades;
 * f) Quantidade de produtos com valor maior que a média
 * 
 */

///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define SIZE 10

void iniciaVetor(int v[], int num);

void preencheValor(float v[], float valor);

int buscaVetor(int v[], int num);

int validaCodigo(void);

int buscaMaior(int v1[], int ref);

float buscaMaiorValor(float v[], int ref);

float somaValor(float v[], int ref);

float somaVlrTotal(float venda[], int quantidade[], int ref);

int buscaFloat(float v[], int ref);

void listarEstoque(int cod[], int qtd[], float venda[]);


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////  INÍCIO DA MAIN  ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(void){
	
	int vCod[SIZE] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int vQtd[SIZE];
    float vVenda[SIZE];
    
    int qtdOcupado = 0;
    int codProduto, pos, listar, qtdProduto, maxDisponivel, qtdMaiorMedia, maxValor;
    float pProduto, somaVlr, vlrTotalProduto;
       
    iniciaVetor(vQtd, 0);
    preencheValor(vVenda, 0.00);
    
    codProduto = validaCodigo();
    
    while(codProduto > 0 && qtdOcupado < 10){
		pos = codProduto - 101;
		
		if(vQtd[pos] > 0){
			printf("Posição já ocupada. Selecione outra posição\n\n");
		}else{
			printf("Informe o preço de venda: ");
			scanf("%f", &pProduto);
			vVenda[pos] = pProduto;
			
			printf("Informe a quantidade disponível: ");
			scanf("%i", &qtdProduto);
			vQtd[pos] = qtdProduto;
			printf("\n");
			qtdOcupado++;
		}
		if(qtdOcupado < 10){
			codProduto = validaCodigo();
		}	
	}
	
	maxDisponivel = buscaMaior(vQtd, SIZE);
	maxValor = buscaMaiorValor(vVenda, SIZE);
	somaVlr = somaValor(vVenda, SIZE);
	vlrTotalProduto = somaVlrTotal(vVenda, vQtd, SIZE);
	qtdMaiorMedia = buscaFloat(vVenda, somaVlr);
	
	printf("\nDADOS ESTATÍSTICOS\n");
	
	printf("Total de posições ocupadas: %i\n", qtdOcupado);
	printf("Posição com mais ítens a venda: %i ... %i itens\n", vCod[maxDisponivel], vQtd[maxDisponivel]);
	printf("Produto de valor mais alto: %i ... R$ %.2f\n", vCod[maxValor], vVenda[maxValor]);
	printf("Média de valor dos produtos: R$ %.2f\n", somaVlr);
	printf("Valor total dos produtos: R$ %.2f\n", vlrTotalProduto);
	printf("Quantidade de produtos com valor mais alto que o produto médio: %i\n", qtdMaiorMedia);
	
	printf("\nDeseja listar todos os produtos? (1)SIM / (0)NÃO: ");
	scanf("%i", &listar);
	if(listar){
		listarEstoque(vCod, vQtd, vVenda);
	}
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////  FUNÇÕES AUXILIARES  /////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void iniciaVetor(int v[], int num){

	for(int i = 0; i < SIZE; i++){
		v[i] = num;
	}
}
////////////////////////////////////////////////////////////////////////////////
void preencheValor(float v[], float valor){
	
	for(int i = 0; i < SIZE; i++){
		v[i] = valor;
	}
	
}
////////////////////////////////////////////////////////////////////////////////
int validaCodigo(void){
	int cod;
	
	printf("Informe o código (101 a 110) ou 0 para sair: ");
    scanf("%i", &cod);
        while((cod < 101 && cod != 0)|| cod > 110){
		printf("Erro! Informe o código (101 a 110) novamente: ");
		scanf("%i", &cod);
	}
	
	return cod;
}
////////////////////////////////////////////////////////////////////////////////
int buscaMaior(int v1[], int ref){
	int max = 0;
	int maxIndice;
	
	for(int i = 0; i < ref; i++){
		if(v1[i] > max){
			max = v1[i];
			maxIndice = i;
		}
	}
	
	return maxIndice;
}
///////////////////////////////////////////////////////////////////////////////
float buscaMaiorValor(float v[], int ref){
	float max = 0.00;
	int maxIndice;
	
	for(int i = 0; i < ref; i++){
		if(v[i] > max){
			max = v[i];
			maxIndice = i;
		}
	}
	return maxIndice;
}
///////////////////////////////////////////////////////////////////////////////
float somaValor(float v[], int ref){
	float soma = 0.00;
	int qtd = 0;
	
	
	for(int i = 0; i < ref; i++){
		if(v[i] != 0.00){
			qtd++;
			soma+=v[i];
		}
	}
		
	return (soma/qtd);
}
///////////////////////////////////////////////////////////////////////////////
float somaVlrTotal(float venda[], int quantidade[], int ref){
	int i;
	float total = 0.00;
	
	for(i = 0; i < ref; i++){
		total = total + (venda[i] * quantidade[i]);
	}
	
	return total;
}
///////////////////////////////////////////////////////////////////////////////
int buscaVetor(int v[], int num){

	for(int i = 0; i < SIZE; i++){
		if(num == v[i]){
			return i;
		}
	}
	
	return -1;
}
///////////////////////////////////////////////////////////////////////////////
int buscaFloat(float v[], int ref){
	int qtd = 0;
	
	for(int i = 0; i < SIZE; i++){
		if(ref < v[i]){
			qtd++;
		}
	}
	
	return qtd;
}
///////////////////////////////////////////////////////////////////////////////
void listarEstoque(int cod[], int qtd[], float venda[]){
	int i;
	
	printf("\n***********************************************\n");
	printf("   CÓDIGO   -   QTD   -   VENDA   -    TOTAL\n");
	for(i = 0; i < SIZE; i++){
		printf("%8i", cod[i]);
		printf(" %9i", qtd[i]);
		printf("      R$ %5.2f", venda[i]);
		printf("    R$ %5.2f\n", qtd[i]*venda[i]);
	}
	printf("***********************************************\n\n");
	
	return;
}
///////////////////////////////////////////////////////////////////////////////