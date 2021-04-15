#include <stdio.h>

/*
Programa que funcione como um sistema de vendas e estoque e emita relatórios.
 O sistema deve primeiramente pedir para que sejam inseridos produtos em seu cadastro. 
 void cadastraProduto

 Cada produto é composto por um código de 5 dígitos em que os dois primeiros representam
 a categoria do produto e os outros três a referência do produto propriamente dita.
 O sistema deve ainda, armazenar o valor de compra e de venda de cada produto, além das
 informações de estoque.
 Quando o usuário escolher um produto que não tenha no estoque ele deve ser informado.
 O administrador deve poder consultar relatórios de quantidade de produto em estoque,
 valor total vendido, valor total vendido de cada produto, além de mostrar o produto mais 
 vendido.
 */

#define SIZE 100

//declara protótipo das funções

void exibeMensagem(int ref);

void preencheVetor(int v[], int num);

void preencheValor(float v[], float num);

void cadastraProduto(int codigo[], int qtd[], float compra[], float venda[], int *ref);

int validaCodigo();

int menu(int codCliente, int autoridade);

void cadastraAdm(int *adm, int *pwd);

int buscar(int v[], int valor, int ref);

void listarProduto(int vCod[], int vQtd[], float vVenda[], int ref);

void listarCategoria(int codigo[], int qtd[], float venda[], int ref);

void comprarProduto(int codigo[], int qtd[], float venda[], int qtdVenda[], float acumVenda[], int ref);

void modificarProduto(int codigo[], int qtd[], float compra[], float venda[], int ref);

void excluirProduto(int codigo[], int qtd[], float compra[], float venda[], int ref);

void listarEstoque(int codigo[], int qtd[], float compra[], float venda[], int ref);

void apresentarDados(int codigo[], float compra[], float venda[], int qtdVenda[], float acumVenda[], int ref);

int maior(int v[], int ref);

float somaValor(float v[], int ref);

////////////////////////////////////////////////////////////////////////////
/////////////////////////// Início da Função main //////////////////////////
////////////////////////////////////////////////////////////////////////////
int main(void){

//declara variaveis

    int vCod[SIZE];
    int vQtd[SIZE];
    float vCompra[SIZE];
    float vVenda[SIZE];
    int vQtdVenda[SIZE];
    float vAcumVenda[SIZE];
    int qtdProduto = 0; //inicializa variavel com zero
    int codCliente, codAdm = 0, pwdAdm, opcao, validaPwd;
    int autoridade = 0;


    preencheVetor(vCod, -1);
    preencheVetor(vQtd, -1);
    preencheVetor(vQtdVenda, 0);

    preencheValor(vAcumVenda, 0.00);
    preencheValor(vCompra, -1);
    preencheValor(vVenda, -1);

    exibeMensagem(1);

    printf("\n");
    exibeMensagem(2);
    printf("\n");
    cadastraAdm(&codAdm, &pwdAdm);
    exibeMensagem(3);
    printf("\n");
    cadastraProduto(vCod, vQtd, vCompra, vVenda, &qtdProduto);
    while(qtdProduto == 0){
		exibeMensagem(5);
		cadastraProduto(vCod, vQtd, vCompra, vVenda, &qtdProduto);
	}
    
	printf("\nInforme o código do cliente ou o código do admnistrador ou 0 para sair:\n");
	scanf("%i", &codCliente);
	while(codCliente > 0){
		if(codCliente == codAdm){
			printf("Informe a senha de Administrador: ");
			scanf("%i", &validaPwd);
			if(validaPwd == pwdAdm){
				autoridade = 2;
				opcao = menu(codCliente, autoridade);
			}else{
				int count=3;
				printf("Senha inválida você tem mais %i tentativas.\n", count);
				printf("Informe a senha de Administrador: ");
				scanf("%i", &validaPwd);
			
				while(count > 1 || (validaPwd == pwdAdm)){
					count--;
					printf("Senha inválida você tem mais %i tentativas.\n", count);
					printf("Informe a senha de Administrador: ");
					scanf("%i", &validaPwd);
				}
				if(validaPwd == pwdAdm){
				autoridade = 2;
				opcao = menu(codCliente, autoridade);
				}else{
					codCliente = 0;
					opcao = 0;
				}
			}
			
			while(opcao > 0){
				switch(opcao){
				case 4:
					cadastraProduto(vCod, vQtd, vCompra, vVenda, &qtdProduto);
					break;
				case 5:
					listarEstoque(vCod, vQtd, vCompra, vVenda, qtdProduto);
					break;
				case 6:
					modificarProduto(vCod, vQtd, vCompra, vVenda, qtdProduto);
					break;
				case 7:
					excluirProduto(vCod, vQtd, vCompra, vVenda, qtdProduto);
					break;
				case 8:
					apresentarDados(vCod, vCompra, vVenda, vQtdVenda, vAcumVenda, qtdProduto);
				}
				opcao = menu(codCliente, autoridade);
			}
			
		}else{
			autoridade = 1;
			opcao = menu(codCliente, autoridade);
			while(opcao > 0){
				switch(opcao){
				case 1:
					listarProduto(vCod, vQtd, vVenda, qtdProduto);
					break;
				case 2:
					listarCategoria(vCod, vQtd, vVenda, qtdProduto);
					break;
				case 3:
					comprarProduto(vCod, vQtd, vVenda,  vQtdVenda, vAcumVenda, qtdProduto);
					break;
				}
				opcao = menu(codCliente, autoridade);
			}
		}
		printf("\nInforme o código do cliente ou o código do admnistrador ou 0 para sair:\n");
		scanf("%i", &codCliente);
	}
    
    
    

    return 0;
}
/*chamada da mesma função com os parametros distintos.
preencheVetor(vCod, -1);
preencheVetor(vQtd, -1);
preencheVetor(vQtdVenda, 0);

*/
void preencheVetor(int v[], int num){
    for(int i = 0; i < SIZE; i++){
        v[i] = num;
    }
    
    return;
}
//////////////////////////////////////////////////////////////////////////////
void preencheValor(float v[], float num){
    for(int i = 0; i < SIZE; i++){
        v[i] = num;
    }
    
    return;
}
//////////////////////////////////////////////////////////////////////////////
int buscar(int v[], int valor, int ref){
	int i;
	
	for(i = 0; i < ref; i++){
		if(valor == v[i]){
			return i;
		}
	}
	
	return -1;
}
//////////////////////////////////////////////////////////////////////////////
void cadastraProduto(int codigo[], int qtd[], float compra[], float venda[], int *ref){
    int cod, qtdProd, busca, alerta = 0;
    float vlCompra, vlVenda;
    
    exibeMensagem(15);
   
    cod = validaCodigo();
 
    while(cod > 0){
		if((*ref) > 0){
			busca = buscar(codigo, cod, (*ref));
			if(busca > -1){
				exibeMensagem(4);
				alerta = 1;
			}
		}
		
		if(!alerta){
			codigo[(*ref)] = cod;
			printf("Informe a quantidade de produtos no estoque: ");
			scanf("%i", &qtdProd);
			qtd[(*ref)] = qtdProd;
			printf("Informe o valor de compra do produto: ");
			scanf("%f", &vlCompra);
			compra[(*ref)] = vlCompra;
			printf("Informe o valor de venda do produto: ");
			scanf("%f", &vlVenda);
			venda[(*ref)] = vlVenda;
			
			printf("\n*****************************\n");
			printf("Produto %i cadastrado\n", codigo[(*ref)]);
			printf("Quantidade em estoque: %i\n", qtd[(*ref)]);
			printf("Valor de compra: R$ %.2f\n", compra[(*ref)]);
			printf("Valor de venda: R$ %.2f\n", venda[(*ref)]);
			printf("*****************************\n");
			(*ref)++;
		}
		alerta = 0;
		printf("\n");
		cod = validaCodigo();
	}
	if(cod == 0 && (*ref) == 0){
		printf("Não há produtos cadastrados no sistema\n\n");
	}
    
    return;
}
//////////////////////////////////////////////////////////////////////////////
int validaCodigo(){
    int cod, cat;

    printf("Informe um código de 2 dígitos (10 a 99) para a Categoria do Produto ou 0 para sair: ");
    scanf("%i", &cat);
    if(cat == 0){
		return 0;
    }
    else{
        while((cat < 10 && cat!= 0) || cat > 99){
            printf("ERRO!\n");
            printf("Informe um código de 2 dígitos (10 a 99) para a Categoria do Produto ou 0 para sair: ");
            scanf("%i", &cat);
        }
        if(cat > 0){
			printf("Informe um código de 3 dígitos (100 a 999) para o Produto: ");
			scanf("%i", &cod);
			while(cod < 100 || cod > 999){
				printf("ERRO!\n");
				printf("Informe um código de 3 dígitos (100 a 999) para o Produto: ");
				scanf("%i", &cod);
			}
		}
        
    
		cod = (cat * 1000) + cod;
        return cod;
    }
    
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
void cadastraAdm(int *adm, int *pwd){
    int pwdVerifica;

    printf("Informe seu codigo de 5 digitos para administrador: ");
    scanf("%i", &(*adm));
    while((*adm) < 10000 || (*adm) > 99999){
        printf("ERRO!!!\n");
        printf("Informe seu codigo de 5 digitos para administrador: ");
        scanf("%i", &(*adm));
    }
    do{
        printf("Informe sua senha de administrador com 5 digitos: ");
        scanf("%i", &(*pwd));
        while((*pwd) < 10000 || (*pwd) > 99999){
            printf("ERRO!!!\n");
            printf("Informe sua senha de administrador com 5 digitos: ");
            scanf("%i", &(*pwd));
        }
        printf("Informe novamente sua senha de administrador com 5 digitos: ");
        scanf("%i", &pwdVerifica);
        if((*pwd) != pwdVerifica){
            printf("As senhas não conferem!!!");
        }
    }while((*pwd) != pwdVerifica);
    
    return;
}
//////////////////////////////////////////////////////////////////////////////
void listarProduto(int vCod[], int vQtd[], float vVenda[], int ref){
    int cod, busca;
	
	exibeMensagem(11);
	
    printf("Informe o código do produto ou 0 para sair: ");
    scanf("%i", &cod);
    while(cod > 0){
		busca = buscar(vCod, cod, ref);
		if(busca > -1){
			printf("\n*****************************\n");
			printf("Produto %i\n", vCod[busca]);
			printf("Quantidade disponível: %i\n", vQtd[busca]);
			printf("Preço unitário: R$ %.2f\n", vVenda[busca]);
			printf("*****************************\n\n");
		}else{
			exibeMensagem(10);
		}
		
		printf("Informe novo código do produto ou 0 para sair: ");
		scanf("%i", &cod);
	}
	
	return;
}
//////////////////////////////////////////////////////////////////////////////
void listarCategoria(int codigo[], int qtd[], float venda[], int ref){
	int cat, encontrado = 0;
	
	exibeMensagem(12);
	
	printf("Informe a categoria do produto ou 0 para sair: ");
	scanf("%i", &cat);
	while(cat > 0){
		printf("\n**********************************\n");
		printf("   CÓDIGO   -   QTD   -   VENDA   \n");
		for(int i = 0; i < ref; i++){
			
			if(cat == (codigo[i]/1000)){
				printf("%8i", codigo[i]);
				printf(" %9i", qtd[i]);
				printf("      R$ %4.2f\n", venda[i]);
		
				encontrado = 1;
			}
		}
		printf("**********************************\n\n");
		
		if(!encontrado){
			exibeMensagem(10);
		}
		encontrado = 0;
		printf("Informe nova categoria ou 0 para sair: ");
		scanf("%i", &cat);
	}
		
	return;
}
//////////////////////////////////////////////////////////////////////////////
void comprarProduto(int codigo[], int qtd[], float venda[], int qtdVenda[], float acumVenda[], int ref){
	int qtdCompra, busca, cod, alarme = 0;
	
	exibeMensagem(14);
	
	printf("Informe o código do produto ou 0 para sair: ");
    scanf("%i", &cod);
    while(cod > 0){
		busca = buscar(codigo, cod, ref);
		if(busca > -1){
			printf("Informe a quantidade desejada: ");
			scanf("%i", &qtdCompra);
			if(qtdCompra > qtd[busca]){
				exibeMensagem(16);
				printf("Quantidade disponível em estoque: %i\n\n", qtd[busca]);
				alarme = 1;
			}
			if(!alarme){
				exibeMensagem(17);
				printf("Total da compra: R$ %.2f\n\n", qtdCompra * venda[busca]);
				qtdVenda[busca] = qtdVenda[busca] + qtdCompra;
				acumVenda[busca] = qtdVenda[busca] + (qtdCompra * venda[busca]);
			}
			alarme = 0;
			
		}else{
			exibeMensagem(10);
		}
		
		printf("Informe o próximo código do produto ou 0 para sair: ");
		scanf("%i", &cod);
	}
		
	return;
}
//////////////////////////////////////////////////////////////////////////////
void modificarProduto(int codigo[], int qtd[], float compra[], float venda[], int ref){
	int cod, busca;
	
	exibeMensagem(8);
	
	printf("Informe o código do produto ou 0 para sair: ");
	scanf("%i", &cod);
	while(cod > 0){
		busca = buscar(codigo, cod, ref);
		if(busca > -1){
			printf("Informe a nova quantidade: ");
			scanf("%i", &qtd[busca]);
			printf("\nInforme o novo valor de compra: R$ ");
			scanf("%f", &compra[busca]);
			printf("\nInforme o novo valor de venda: R$ ");
			scanf("%f", &venda[busca]);
			
			printf("\n*****************************\n");
			printf("Produto %i cadastrado\n", codigo[busca]);
			printf("Quantidade em estoque: %i\n", qtd[busca]);
			printf("Valor de compra: R$ %.2f\n", compra[busca]);
			printf("Valor de venda: R$ %.2f", venda[busca]);
			printf("\n*****************************\n\n");
		}else{
			exibeMensagem(10);
		}
				
		printf("Informe o novo código ou 0 para sair: ");
		scanf("%i", &cod);
	}
	
	return;	
}
//////////////////////////////////////////////////////////////////////////////
void excluirProduto(int codigo[], int qtd[], float compra[], float venda[], int ref){
	int excluir, cod, busca;
	
	exibeMensagem(13);
	
	printf("Atenção! Esta operação não pode ser desfeita.\n");
	printf("Deseja realmente excluir um produto do sistema? (1) SIM / (0) NÃO: ");
	scanf("%i", &excluir);
	
	if(excluir){
		printf("Informe o código do produto ou 0 para sair: ");
		scanf("%i", &cod);
		while(cod > 0){			
			busca = buscar(codigo, cod, ref);
			if(busca > -1){
				codigo[busca] = qtd[busca] = compra[busca] = venda[busca] = -1;
				exibeMensagem(9);
			}else{
				exibeMensagem(10);
			}
			
			printf("Informe o novo código ou 0 para sair: ");
			scanf("%i", &cod);
		}
		
	}
	
	return;
}
//////////////////////////////////////////////////////////////////////////////
void listarEstoque(int codigo[], int qtd[], float compra[], float venda[], int ref){
	
	exibeMensagem(6);

	printf("   CÓDIGO   -   QTD   -   COMPRA   -   VENDA   \n");
	for(int i = 0; i < ref; i++){
		printf("%8i", codigo[i]);
		printf(" %9i", qtd[i]);
		printf("      R$ %4.2f", compra[i]);
		printf("     R$ %4.2f\n", venda[i]);
		
	}
	
	return;
}
//////////////////////////////////////////////////////////////////////////////
/*O administrador deve poder consultar relatórios de quantidade de produto em estoque,
 * valor total vendido, valor total vendido de cada produto, além de
 * mostrar o produto mais vendido.*/
void apresentarDados(int codigo[], float compra[], float venda[], int qtdVenda[], float acumVenda[], int ref){
	float totalVenda;
	int maisVendido, individual;
	
	totalVenda = somaValor(acumVenda, ref);
	maisVendido = maior(qtdVenda, ref);
	
	printf("TOTAL DE VENDAS: R$ %.2f\n", totalVenda);
	printf("PRODUTO MAIS VENDIDO: %i ... %i VENDAS\n", codigo[maisVendido], qtdVenda[maisVendido]);
	
	printf("Deseja ver relatório individual de vendas? (1)SIM / (2)NÃO: ");
	scanf("%i", &individual);
	if(individual == 1){
		for(int i = 0; i < ref; i++){
			printf("PRODUTO %i .... TOTAL VENDIDO %i .... VALOR R$ %.2f\n", codigo[i], qtdVenda[i], acumVenda[i]);
			
		}
	}
	
}
//////////////////////////////////////////////////////////////////////////////
float somaValor(float v[], int ref){
	float soma=0.00;
	
	for(int i = 0; i < ref; i++){
		soma+=v[i];
	}
	return soma;
}

//////////////////////////////////////////////////////////////////////////////
int maior(int v[], int ref){
	int maior=0;
	int maxIndice;
	
	for(int i = 0; i < ref; i++){
		if(v[i] > maior){
			maior = v[i];
			maxIndice = i;
		}
	}
	return maxIndice;
}

//////////////////////////////////////////////////////////////////////////////
void exibeMensagem(int ref){

    switch(ref){
    case 1:
        printf("************* BEM VINDO AO GESTUDO *************\n");
        printf("*********** Sistema de Gestão Global ***********\n");
        printf("************************************************\n");
        break;
    case 2:
        printf("\n********************* Atenção *********************\n");
        printf("***  Não há administrador cadastrado no sistema ***\n");
        printf("***************************************************\n");
        break;
    case 3:
        printf("\n******************** Atenção ********************\n");
        printf("*  Não há nenhum produto cadastrado no sistema  *\n");
        printf("*************************************************\n");
        break;
    case 4:
        printf("\n******************** Atenção ********************\n");
        printf("********** Código já cadastrado no sistema ******\n");
        printf("*************************************************\n");
        break;
    case 5:
		printf("\n******************************* Atenção *****************************\n");
		printf("* O sistema precisa ter pelo menos um produto válido em seu cadastro *\n");
		printf("**********************************************************************\n\n");
		break;
	case 6:
		printf("\n***********************************************\n");
		printf("******* Produtos cadastrados no Sistema *******\n");
		printf("***********************************************\n\n");
		break;
	case 7:
		printf("\n***********************************************\n");
		printf("******* Perfil Administrador do Sistema *******\n");
		printf("***********************************************\n\n");
		break;
	case 8:
		printf("\n***********************************************\n");
		printf("***** Modificação de Produto no Sistema *******\n");
		printf("***********************************************\n\n");
		break;
	case 9:
		printf("\n***********************************************\n");
		printf("********* Produto Retirado do Sistema *********\n");
		printf("***********************************************\n\n");
		break;
	case 10:
		printf("\n***********************************************\n");
		printf("***** Produto não Encontrado no Sistema *******\n");
		printf("***********************************************\n\n");
		break;
	case 11:
		printf("\n***********************************************\n");
		printf("******** Busca de Produto pelo Código *********\n");
		printf("***********************************************\n\n");
		break;
	case 12:
		printf("\n***********************************************\n");
		printf("******* Busca de Produto pela Categoria *******\n");
		printf("***********************************************\n\n");
		break;
	case 13:
		printf("\n***********************************************\n");
		printf("******* Exclusão de Produto no Sistema ********\n");
		printf("***********************************************\n\n");
		break;
	case 14:
		printf("\n***********************************************\n");
		printf("******** Sessão de Compra de Produtos *********\n");
		printf("***********************************************\n\n");
		break;
    case 15:
		printf("\n***********************************************\n");
		printf("****** Cadastro de Produtos no Sistema ********\n");
		printf("***********************************************\n\n");
		break;
	case 16:
		printf("\n***********************************\n");
		printf("****** COMPRA NÃO EFETUADA ********\n");
		printf("***********************************\n\n");
		break;
	case 17:
		printf("\n***********************************\n");
		printf("*** COMPRA EFETUADA COM SUCESSO ***\n");
		printf("***********************************\n\n");
		break;
	}
    
    return;
}
//////////////////////////////////////////////////////////////////////////////
int menu(int codCliente, int autoridade){
    int opcao;
    
    if(autoridade == 2){
		exibeMensagem(7);
        printf("Informe a opção desejada ou 0 para sair:\n");
        printf("4 - Cadastrar produto\n");
        printf("5 - Listar estoque\n");
        printf("6 - Modificar Produto\n");
        printf("7 - Excluir Produto\n");
        printf("8 - Visualizar estatísticas do sistema\n");
        scanf("%i", &opcao);
        if(opcao != 0){
			while((opcao < 4 && opcao != 0) || opcao > 8){
				printf("ERRO!!!\n");
				printf("Informe a opção desejada ou 0 para sair:\n");
				printf("4 - Listar estoque\n");
				printf("5 - Modificar Produto\n");
				printf("6 - Excluir Produto\n");
				printf("7 - Excluir Produto\n");
				printf("8 - Visualizar estatísticas do sistema\n");
				scanf("%i", &opcao);
			}
		}
	}else{
		printf("\n*************************\n");
		printf("**** Bem vindo (%i)! ****\n", codCliente);
		printf("*************************\n\n");
        printf("Informe a opção desejada ou 0 para sair:\n");
        printf("1 - Buscar produto pelo código\n");
        printf("2 - Buscar produto pela categoria\n");
        printf("3 - Comprar produto\n");
        scanf("%i", &opcao);
        if(opcao != 0){
			while((opcao < 1 || opcao > 3)){
				printf("ERRO!!!\n");
				printf("Informe a opção desejada ou 0 para sair:\n");
				printf("1 - Buscar produto pelo código\n");
				printf("2 - Buscar produto pela categoria\n");
				printf("3 - Comprar produto\n");
				scanf("%i", &opcao);
			}
		}
	}
    
    return opcao;
}
