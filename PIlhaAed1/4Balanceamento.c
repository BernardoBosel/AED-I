#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = create();

    if (pilha == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 1;
    }

    char expressao[500];
    int balanceada = 1;

    printf("Digite a expressao matematica: ");

    if (fgets(expressao, sizeof(expressao), stdin) == NULL) {
        destroy(pilha);
        return 1;
    }

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        // Empilha os simbolos de abertura 
        if (c == '(' || c == '{' || c == '[') {
            Elem elem;
            elem.carac = c;
            push(pilha, elem);
        }

        // Verifica os simbolos de fechamento
        else if (c == ')' || c == '}' || c == ']') {

            // Fechamento sem abertura correspondente
            if (empty(pilha)) {
                balanceada = 0;
                break;
            }

            Elem elem = pop(pilha);

            // Verifica se os simbolos correspondem
            if ((c == ')' && elem.carac != '(') ||
                (c == '}' && elem.carac != '{') ||
                (c == ']' && elem.carac != '[')) {

                balanceada = 0;
                break;
            }
        }
    }

    // Se restarem aberturas, a expressao nao esta balanceada
    if (!empty(pilha)) {
        balanceada = 0;
    }

    if (balanceada) {
        printf("A expressao esta corretamente balanceada.\n");
    } else {
        printf("A expressao nao esta corretamente balanceada.\n");
    }

    destroy(pilha);

    return 0;
}