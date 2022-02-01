/*função 1: retorna a quantidade de elementos da lista que são múltiplos de A

função 2: retorna a quantidade de elementos da lista L1 que possuem múltiplos em L2


nt listasiguais (TLista L1, TLista L2){
TLista aux1=L1, aux2=L2,cont=0;

while(aux1!=NULL){
if(aux1->valor == aux2->valor){
    cont++;
}
else {
    return 0;
}
aux1=aux1->prox;
aux2=aux2->prox;
}
return cont;
}
ANDRÉ SANTOS10:16
int comparaListas(TLista L1, TLista L2)
{
    TLista aux1 = L1;
    TLista aux2 = L2;
    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->numero != aux2->numero)
        {
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    if (aux1 == NULL && aux2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


*/