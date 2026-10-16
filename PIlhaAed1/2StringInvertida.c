#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = create();

    if (pilha == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    char texto[256];
    char invertida[256];

    printf("Digite uma string: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL) {
        destroy(pilha);
        return 1;
    }

    // Remove o caractere de nova linha, se existir
    texto[strcspn(texto, "\n")] = '\0';

    // Insere cada caractere na pilha
    for (int i = 0; texto[i] != '\0'; i++) {
        Elem elem;
        elem.carac = texto[i];
        push(pilha, elem);
    }

    // Remove os caracteres para formar a string invertida
    int i = 0;

    while (!empty(pilha)) {
        Elem elem = pop(pilha);
        invertida[i] = elem.carac;
        i++;
    }

    invertida[i] = '\0';

    printf("String original: %s\n", texto);
    printf("String invertida: %s\n", invertida);

    destroy(pilha);

    return 0;
}
