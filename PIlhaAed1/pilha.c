#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    Elem dado;
    struct no *prox;
} No;

struct pilha {
    No *topo;
    int quantidade;
};

Pilha *create(void) {
    Pilha *pilha = malloc(sizeof(Pilha));

    if (pilha == NULL) {
        return NULL;
    }

    reset(pilha);

    return pilha;
}

void destroy(Pilha *pilha) {
    if (pilha != NULL) {
        clear(pilha);
        free(pilha);
    }
}

void reset(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->quantidade = 0;
}

int empty(Pilha *pilha) {
    return pilha->topo == NULL;
}

int size(Pilha *pilha) {
    return pilha->quantidade;
}

void push(Pilha *pilha, Elem elem) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }

    novo->dado = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->quantidade++;
}

Elem pop(Pilha *pilha) {
    Elem elem = {'\0'};

    if (empty(pilha)) {
        printf("Erro: pilha vazia!\n");
        return elem;
    }

    No *aux = pilha->topo;

    elem = aux->dado;
    pilha->topo = aux->prox;

    free(aux);
    pilha->quantidade--;

    return elem;
}

void top(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elemento do topo: %c\n", pilha->topo->dado.carac);
}

void clear(Pilha *pilha) {
    while (!empty(pilha)) {
        pop(pilha);
    }
}

void print(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    No *aux = pilha->topo;

    printf("Pilha (topo -> base): ");

    while (aux != NULL) {
        printf("%c ", aux->dado.carac);
        aux = aux->prox;
    }

    printf("\n");
}