#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = create();

    if (pilha == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    Elem elem;

    elem.carac = 'A';
    push(pilha, elem);

    elem.carac = 'B';
    push(pilha, elem);

    elem.carac = 'C';
    push(pilha, elem);

    printf("Pilha inicial:\n");
    print(pilha);

    printf("Quantidade de elementos: %d\n", size(pilha));

    top(pilha);

    printf("\nRemovendo elemento do topo:\n");

    elem = pop(pilha);
    printf("Elemento removido: %c\n", elem.carac);

    printf("\nPilha apos a remocao:\n");
    print(pilha);

    printf("Quantidade de elementos: %d\n", size(pilha));

    printf("\nVerificando se a pilha esta vazia:\n");

    if (empty(pilha)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }

    printf("\nLimpando a pilha...\n");
    clear(pilha);

    print(pilha);

    printf("Quantidade de elementos: %d\n", size(pilha));

    destroy(pilha);

    return 0;
}
