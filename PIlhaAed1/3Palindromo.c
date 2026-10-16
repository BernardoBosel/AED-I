#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = create();

    if (pilha == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    char palavra[256];
    int palindromo = 1;

    printf("Digite uma palavra: ");

    if (scanf("%255s", palavra) != 1) {
        destroy(pilha);
        return 1;
    }

    int tamanho = strlen(palavra);

    // Insere os caracteres na pilha
    for (int i = 0; i < tamanho; i++) {
        Elem elem;
        elem.carac = (char)tolower((unsigned char)palavra[i]);
        push(pilha, elem);
    }

    // Compara a palavra original com os caracteres desempilhados
    for (int i = 0; i < tamanho; i++) {
        Elem elem = pop(pilha);

        if ((char)tolower((unsigned char)palavra[i]) != elem.carac) {
            palindromo = 0;
            break;
        }
    }

    // Exibe o resultado
    if (palindromo) {
        printf("%s e um palindromo.\n", palavra);
    } else {
        printf("%s nao e um palindromo.\n", palavra);
    }

    destroy(pilha);

    return 0;
}