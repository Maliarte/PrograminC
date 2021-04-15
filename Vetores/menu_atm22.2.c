#include <stdio.h>

#define SIZE 10573

int validaConta(int array[], int ref);
void criarConta(int array[], int ref, int controle);
void operaConta(int vNome[], int ref, float vValor[]);
int encontraIndice(int array[], int ref);
void inicializaConta(int vConta[]);
void inicializaSaldo(float vSaldo[]);

int main(void){
    int opcao, num, aceito;
    int i = 0;
    int vConta[SIZE];
    float vSaldo[SIZE];

    inicializaConta(vConta);
    inicializaSaldo(vSaldo);

    printf("Informe a opção desejada\n");
    printf("0 - Sair do programa.\n");
    printf("1 - Criar conta.\n");
    printf("2 - Realizar operação.\n");
    printf("OPÇÃO: ");
    scanf("%i", &opcao);

    while(opcao == 1 || opcao == 2){
        switch(opcao){
        case 1:
            printf("\nInforme o número da conta1: ");
            scanf("%i", &num);
            aceito = validaConta(vConta, num);
            if(aceito != 0){
                criarConta(vConta, aceito, i);
                printf("PARABÉNS\n");
                printf("Conta %i criada com sucesso\n\n", vConta[i]);
                i++;
            }else{
                printf("\nERRO!!!\n");
                printf("Conta já existe.\n\n");
            }
            break;
        case 2:
            printf("\nInforme o número da conta: ");
            scanf("%i", &num);
            aceito = validaConta(vConta, num);
            if(aceito == 0){
                operaConta(vConta, num, vSaldo);
            }else{
                printf("\nERRO!!!\n");
                printf("Conta não encontrada.\n\n");
            }
            break;
        }
        printf("Informe a opção desejada:\n");
        printf("0 - Sair do programa.\n");
        printf("1 - Criar conta.\n");
        printf("2 - Realizar operação.\n");
        printf("OPÇÃO: ");
        scanf("%i", &opcao);
    }

    return 0;
}

//////////////////////////////////////////////////////////
int validaConta(int array[], int ref){
    for(int i = 0; i < SIZE; i++){
        if(ref == array[i]){
            return 0;
        }
    }
    return ref;
}

//////////////////////////////////////////////////////////
void criarConta(int array[], int ref, int controle){
    array[controle] = ref;
    return;
}

//////////////////////////////////////////////////////////
void operaConta(int vNome[], int ref, float vValor[]){
    int indice, op;
    float quantia;
    indice = encontraIndice(vNome, ref);

    printf("Selecione a operação desejada\n");
    printf("1 - Sacar ou Depositar valor.\n");
    printf("2 - Verificar Saldo.\n");
    scanf("%i", &op);
    while(op == 1 || op == 2){
        if(op == 1){
            printf("Informe um valor + para depósito ou - para saque: ");
            scanf("%f", &quantia);
            if( (quantia + vValor[indice]) >= 0 ){
                vValor[indice]+=quantia;
            }else{
                printf("Saldo insuficiente\n\n");
            }
        }else{
            printf("O saldo da conta %i é = R$ %.2f\n\n", ref, vValor[indice]);
        }
        printf("Selecione a operação desejada\n");
        printf("0 - Sair da seção.\n");
        printf("1 - Sacar ou Depositar valor.\n");
        printf("2 - Verificar Saldo.\n");
        scanf("%i", &op);
    }
    return;
}

//////////////////////////////////////////////////////////
int encontraIndice(int array[], int ref){
    for(int i = 0; i < SIZE; i++){
        if(ref == array[i]){
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////////////////////////
void inicializaConta(int vConta[]){
    for(int i = 0; i < SIZE; i++){
        vConta[i] = 0;
    }
}

//////////////////////////////////////////////////////////
void inicializaSaldo(float vSaldo[]){
    for(int i = 0; i < SIZE; i++){
        vSaldo[i] = 0.0;
    }
}
//////////////////////////////////////////////////////////
