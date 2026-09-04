#include <stdio.h> // inclui printf e scanf
#include <stdlib.h> // inclui malloc e free

typedef struct { // inicia a estrutura Ponto
    int x; // guarda a coordenada x
    int y; // guarda a coordenada y
} Ponto; // cria o tipo Ponto

Ponto *criar_ponto(int x, int y) { // recebe as coordenadas e retorna um ponteiro
    Ponto *p = malloc(sizeof(Ponto)); // aloca memoria para um Ponto
    if (p == NULL) { // verifica se malloc falhou
        return NULL; // informa a falha
    } // termina a verificacao
    p->x = x; // coloca x no campo x
    p->y = y; // coloca y no campo y
    return p; // retorna o endereco do ponto
} // termina criar_ponto

void destruir_ponto(Ponto *p) { // recebe o endereco do ponto
    free(p); // libera a memoria alocada
} // termina destruir_ponto

int main(void) { // inicia o programa
    int x; // guarda x
    int y; // guarda y
    printf("digite x: "); // pede x
    scanf("%d", &x); // le x
    printf("digite y: "); // pede y
    scanf("%d", &y); // le y
    Ponto *p = criar_ponto(x, y); // cria o ponto dinamicamente
    if (p == NULL) { // verifica falha
        printf("erro ao alocar memoria\n"); // mostra o erro
        return 1; // encerra com erro
    } // termina a verificacao
    printf("ponto: (%d, %d)\n", p->x, p->y); // mostra o ponto
    destruir_ponto(p); // libera a memoria
    return 0; // encerra com sucesso
} // termina main