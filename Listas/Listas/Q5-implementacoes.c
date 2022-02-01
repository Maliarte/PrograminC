/*

    FAETERJ-Rio

    Fundamentos de Programação - FPR - Manhã

    Data: 18/12/2021

1
2
3 TRUE
4 FALSE
    

    Lista de Exercícios X:

    

    QUESTÃO 05:

    Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique 

    se elas possuem os mesmos elementos, independente da ordem na qual apareçam.    


struct ((remover)free), listaEncadeada(inserir(malloc)) ponteiro, arquivo

*/



int funcaoAuxiliar (TLista listaA, TLista listaB)

{

    //declaração de variáveis

    TLista aux1 = listaA, aux2 = listaB;

    int cont=0;



    //percorrendo a listaA

    while(aux1 !=NULL)

    {

        //percorrendo a listaB

        while(aux2 !=NULL)

        {

            //verificando quantas vezes cada elemento da listaA aparece na listaB

            if(aux1->valor==aux2->valor)

            {

                 cont++;

            }

            

            aux2=aux2->prox;

        }

    

        //se o elemento da listaA não aparecer na listaB, as listas não possuem os mesmos elementos

        if(cont==0)

        {

            return 0;

        }

        else 

        {

            //continuar a busca indo para o próximo elemento da listaA

            cont=0;

            aux1=aux1->prox;

            aux2=listaB;

        }

    }

    

    //se chegou aqui, todos os elementos da listaA estão na listaB

    return 1;

}



int questao5 (TLista L1, TLista L2)

{

    /*
     EQUIVALENTE AO  return (funcaoAuxiliar (L1, L2)) && (funcaoAuxiliar (L2, L1));  
    int resp1, resp2;

    

    resp1 = funcaoAuxiliar (L1, L2);

    resp2 = funcaoAuxiliar (L2, L1);

    

    if ((resp1 != 0) && (resp2 != 0))

    {

        return 1;

    }

    else

    {

        return 0;

    }*/

    

    return (funcaoAuxiliar (L1, L2)) && (funcaoAuxiliar (L2, L1));    

}