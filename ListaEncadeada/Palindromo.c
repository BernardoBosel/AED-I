int ehPalindromo(Head *lista) {
    if (lista == NULL) return 1;                      
    Nodo *i = lista->pFirst;                          
    Nodo *j = lista->pLast;                           

    while (i != j && j->prox != i) {                  
        if (i->info.valor != j->info.valor) {         
            return 0;                                 
        }
        i = i->prox;                                  
        j = j->ant;                                   
    }
    return 1;                                         
}