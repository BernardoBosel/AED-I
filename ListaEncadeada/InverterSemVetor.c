void inverterLista(Head *lista) {
    if (lista == NULL) return;
    Nodo *ant = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    lista->pFirst = ant;
}