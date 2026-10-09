void intercalar(Head *l1, Head *l2) {
    if (l1 == NULL || l2 == NULL) return;
    Nodo *a = l1->pFirst;
    Nodo *b = l2->pFirst;

    if (a == NULL) {
        l1->pFirst = b;
        l2->pFirst = NULL;
        return;
    }

    while (a != NULL && b != NULL) {
        Nodo *proxA = a->prox;
        Nodo *proxB = b->prox;
        a->prox = b;
        if (proxA == NULL) {
            break;
        }
        b->prox = proxA;
        a = proxA;
        b = proxB;
    }
    l2->pFirst = NULL;
}