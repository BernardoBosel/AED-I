int contarElementos(Head *lista) {
    if (lista == NULL) return 0;
    int cont = 0;
    No *p = lista->pFirst;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }
    return cont;
}