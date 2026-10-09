int removerPrimeiraOcorrencia(Head *lista, int valor) {
    if (lista == NULL) return 0;
    Nodo *p = lista->pFirst;
    while (p != NULL && p->info.valor != valor) {
        p = p->prox;
    }
    if (p == NULL) return 0;

    if (p->ant == NULL) { 
        lista->pFirst = p->prox;
    } else {
        p->ant->prox = p->prox;
    }

    if (p->prox == NULL) { 
        lista->pLast = p->ant; 
    } else { 
        p->prox->ant = p->ant;
    }

    free(p);
    return 1;
}