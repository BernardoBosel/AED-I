static No *anexarNoFim(Head *lista, No *ultimo, Info dado) {
    No *novo = criaNo(dado);                  
    if (novo == NULL) return ultimo;
    if (ultimo == NULL) { 
        lista->pFirst = novo;
    } else {
        ultimo->prox = novo;
    }
    return novo; 
}

void separarPosicoes(Head *origem, Head *impares, Head *pares) {
    if (origem == NULL || impares == NULL || pares == NULL) return;
    No *p = origem->pFirst;
    No *ultImpar = NULL;
    No *ultPar = NULL;
    int pos = 1;

    while (p != NULL) { 
        if (pos % 2 == 1) {
            ultImpar = anexarNoFim(impares, ultImpar, p->info);
        } else {
            ultPar = anexarNoFim(pares, ultPar, p->info);
        }
        p = p->prox;
        pos++;
    }
}