#include <stdio.h>                      // printf
#include "lista.h"                      // a TAD

int main() {
    Head *lista = criaLista();
    if (lista == NULL) {
        printf("Erro ao criar lista\n");
        return 1;
    }

    printf("Vazia? %d\n", listaVazia(lista));

    Info a = {10};
    Info b = {20};
    Info c = {5};
    inserirFinal(lista, a);
    inserirFinal(lista, b);
    inserirInicio(lista, c);
    imprimirLista(lista);

    Info achado;
    if (buscar(lista, 10, &achado)) {
        printf("Achou: %d\n", achado.valor);
    }
    if (!buscar(lista, 99, &achado)) {
        printf("99 nao existe\n");
    }

    removerInicio(lista);
    removerFinal(lista);
    imprimirLista(lista);
    removerFinal(lista);
    imprimirLista(lista);
    printf("Remover de vazia: %d\n", removerInicio(lista));

    liberaLista(lista);
    return 0;
}