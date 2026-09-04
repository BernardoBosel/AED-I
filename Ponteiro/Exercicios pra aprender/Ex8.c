#include <stdio.h> // inclui printf
#include <stdlib.h> // inclui realloc e free

int *inserir(int *v, int *n, int valor) { // recebe vetor, endereco do tamanho e novo valor
    int *temporario = realloc(v, sizeof(int) * (*n + 1)); // aumenta uma posicao

    if (temporario == NULL) { // verifica falha
        return v; // conserva o vetor original
    } // termina a verificacao

    temporario[*n] = valor; // coloca o valor no fim antigo
    *n = *n + 1; // atualiza a quantidade
    return temporario; // retorna o endereco atual
} // termina a funcao

int main(void) { // inicia o programa
    int n = 3; // quantidade inicial
    int *v = malloc(sizeof(int) * n); // aloca o vetor

    if (v == NULL) { // verifica falha
        return 1; // encerra com erro
    } // termina a verificacao

    v[0] = 10; // preenche o primeiro elemento
    v[1] = 20; // preenche o segundo elemento
    v[2] = 30; // preenche o terceiro elemento

    v = inserir(v, &n, 40); // insere 40 e atualiza o ponteiro

    for (int i = 0; i < n; i++) { // percorre o vetor
        printf("%d ", v[i]); // mostra o elemento
    } // termina a exibicao

    printf("\n"); // pula linha
    free(v); // libera a memoria
    return 0; // encerra com sucesso
} // termina main