#include <stdio.h>
int resp_menu(void){

    int escolha;
    printf("\nESCOLHA UMA OPCAO ABAIXO:\n[1] PARA CONSULTAR O SALDO\n[2] PARA CONSULTAR\n[3] PARA FAZER UM SAQUE\n[4] PARA FINALIZAR\nESCOLHA:");
    scanf ("%d", &escolha);
    while (escolha > 4 || escolha < 1){
            printf("Numero digitado invalido, Por favor escolhar uma opcao valida:\n");
            printf("\nESCOLHA UMA OPCAO ABAIXO:\n[1] PARA CONSULTAR O SALDO\n[2] PARA CONSULTAR\n[3] PARA FAZER UM SAQUE\n[4] PARA FINALIZAR\nESCOLHA:");
            scanf ("%d", &escolha);
    }   
    return escolha;
   
}
float processa(float saldo){
  int escolha;
  float deposito, saque;
  escolha = resp_menu();
  while(escolha != 4){
        
           if (escolha == 1){
                printf("\nO SEU SALDO ATUAL E : %f", saldo);
            }else if (escolha == 2){
                printf("\nDIGITE QUANTO VC QUER DEPOSITAR:");
                scanf("%f", &deposito);
                saldo += deposito;
                printf("\n PARABENS DEPOSITO EFETUADO\n SALDO ATUAL: %f", saldo);
            }else{
                printf("\nDIGITE O QUANTO VC QUER SACAR:");
                scanf("%f", &saque);
                saldo -= saque;
                printf("SAQUE EFETUADO, SALDO ATUAL: %f", saldo);
            }
            escolha = resp_menu();
}
return saldo;




}
int main()
{

int escolha;
char letnome;
float saldo, deposito, saque;


saldo = 0;
printf("DIGITE O SEU NOME:");
scanf("%c" , &letnome);


while(letnome != ' '){
    printf("DIGITE O SEU SALDO:");
    scanf("%f", &saldo);
    saldo=processa(saldo);
    printf("%c -  seu saldo final:R$ %.2f",letnome,saldo);
    printf("\nDIGITE O NOME DO PROXIMO CLIENTE OU VAZIO PARA FINALIZAR:");
    scanf(" %c", &letnome);


}
    return 0;
}
