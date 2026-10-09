Head *copiarLista(Head *origem) {
    if (origem == NULL) return NULL;
    Head *copia = criaLista();
    if (copia == NULL) return NULL;

    Nodo *p = origem->pFirst;
    Nodo *ultimo = NULL;
    while (p != NULL) {
        ultimo = anexarNoFim(copia, ultimo, p->info);
        p = p->prox;
    }
    return copia;
}