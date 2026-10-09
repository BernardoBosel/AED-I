void inverterPrimeirosN(Head *lista, int n) {
    if (lista == NULL || lista->pFirst == NULL) return;
    if (n <= 1) return;                           

    Nodo *primeiro = lista->pFirst;               
    Nodo *ant = NULL;                             
    Nodo *atual = primeiro;
    Nodo *prox = NULL;
    int i = 0;

    while (atual != NULL && i < n) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
        i++;
    }
    primeiro->prox = atual;
    lista->pFirst = ant;
}