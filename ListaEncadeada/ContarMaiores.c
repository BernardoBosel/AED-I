int contarMaiores(Head *lista, int valor) {
    if (lista == NULL) return 0;
    int cont = 0;
    Nodo *p = lista->pFirst;
    while (p != NULL) {
        if (p->info.valor > valor) {
            cont++;
        }
        p = p->prox;
    }
    return cont;
}