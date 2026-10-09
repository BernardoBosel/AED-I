int removerPares(Head *lista) {
    if (lista == NULL) return 0;
    int removidos = 0;
    Nodo *ant = NULL;
    Nodo *atual = lista->pFirst;

    while (atual != NULL) {
        if (atual->info.valor % 2 == 0) { 
            Nodo *aRemover = atual;
            atual = atual->prox;
            if (ant == NULL) {
                lista->pFirst = atual;
            } else {
                ant->prox = atual;
            }
            free(aRemover);
            removidos++;
        } else { 
            ant = atual;
            atual = atual->prox;
        }
    }
    return removidos;
}