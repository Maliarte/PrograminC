int comparaListas(TLista L1, TLista L2)
{
    TLista aux1 = L1;
    TLista aux2 = L2;

    while (aux1 != NULL && aux2 != NULL)
    //while (aux1 && aux2)
    {
        //compara dois numeros sendo analisados sincronamente
        if (aux1->valor != aux2->valor)
        {
            return 0;
        } //else elipsado 
        //atualizacao
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