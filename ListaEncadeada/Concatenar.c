void concatenar(Head *l1, Head *l2) {
    if (l1 == NULL || l2 == NULL) return;
    if (l2->pFirst == NULL) return;

    if (l1->pFirst == NULL) { 
        l1->pFirst = l2->pFirst;
    } else {
        Nodo *p = l1->pFirst;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = l2->pFirst;
    }
    l2->pFirst = NULL;
}