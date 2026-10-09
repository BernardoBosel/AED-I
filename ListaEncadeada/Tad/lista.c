#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


static No *criaNo(Info dado) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->info = dado;
    novo->prox = NULL;
    return novo;
}

Head *criaLista() {
    Head *lista = (Head *) malloc(sizeof(Head));
    if (lista == NULL) {
        return NULL;
    }
    lista->pFirst = NULL;
    return lista;
}

int listaVazia(Head *lista) {
    return (lista == NULL || lista->pFirst == NULL);
}

void inserirInicio(Head *lista, Info dado) {
    if (lista == NULL) return;
    No *novo = criaNo(dado);
    if (novo == NULL) return;
    novo->prox = lista->pFirst;
    lista->pFirst = novo;
}

void inserirFinal(Head *lista, Info dado) {
    if (lista == NULL) return;
    No *novo = criaNo(dado);
    if (novo == NULL) return;

    if (lista->pFirst == NULL) {
        lista->pFirst = novo;
        return;
    }

    No *p = lista->pFirst;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) return 0;
    No *aux = lista->pFirst;
    lista->pFirst = aux->prox;
    free(aux);
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) return 0;

    if (lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }

    No *ant = NULL;
    No *atual = lista->pFirst;
    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = NULL;
    free(atual);
    return 1;
}

int buscar(Head *lista, int valor, Info *resultado) {
    if (lista == NULL) return 0;
    No *p = lista->pFirst;
    while (p != NULL) { 
        if (p->info.valor == valor) {
            if (resultado != NULL) {
                *resultado = p->info;
            }
            return 1;
        }
        p = p->prox;
    }
    return 0;
}
void imprimirLista(Head *lista) {
    if (lista == NULL) {
        printf("NULL\n");
        return;
    }
    No *p = lista->pFirst;
    while (p != NULL) {
        printf("[%d] -> ", p->info.valor);
        p = p->prox;
    }
    printf("NULL\n");
}


void liberaLista(Head *lista) {
    if (lista == NULL) return;
    No *p = lista->pFirst;
    while (p != NULL) {
        No *prox = p->prox;
        free(p);
        p = prox;
    }
    free(lista);
}