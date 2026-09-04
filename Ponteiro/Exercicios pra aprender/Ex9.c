#include <stdio.h> // inclui printf
#include <stdlib.h> // inclui realloc e free

int remover(int **v, int *n, int posicao) { // recebe o endereco do ponteiro, tamanho e posicao
    if (posicao < 0 || posicao >= *n) { // verifica se a posicao e invalida
        return 0; // nao altera o vetor em posicao invalida
    } // termina a verificacao

    for (int i = posicao; i < *n - 1; i++) { // percorre a partir da posicao removida
        (*v)[i] = (*v)[i + 1]; // desloca o proximo elemento para a esquerda
    } // termina o deslocamento

    *n = *n - 1; // diminui a quantidade

    if (*n == 0) { // verifica se o vetor ficou vazio
        free(*v); // libera a memoria
        *v = NULL; // atualiza o ponteiro para NULL
        return 1; // informa sucesso
    } // termina o caso vazio

    int *temporario = realloc(*v, sizeof(int) * (*n)); // reduz a memoria alocada

    if (temporario == NULL) { // verifica falha do realloc
        return 0; // informa falha
    } // termina a verificacao

    *v = temporario; // atualiza o endereco do vetor
    return 1; // informa sucesso
} // termina a funcao

int main(void) { // inicia o programa
    int n = 5; // tamanho inicial
    int *v = malloc(sizeof(int) * n); // aloca o vetor

    if (v == NULL) { // verifica falha
        return 1; // encerra com erro
    } // termina a verificacao

    v[0] = 10; // preenche o vetor
    v[1] = 20; // preenche o vetor
    v[2] = 30; // preenche o vetor
    v[3] = 40; // preenche o vetor
    v[4] = 50; // preenche o vetor

    int resultado = remover(&v, &n, 2); // passa o endereco de v para permitir sua alteracao

    if (resultado == 1) { // verifica se removeu
        for (int i = 0; i < n; i++) { // percorre o vetor resultante
            printf("%d ", v[i]); // mostra o elemento
        } // termina a exibicao
        printf("\n"); // pula linha
    } // termina a verificacao

    free(v); // libera o vetor, mesmo se estiver NULL
    return 0; // encerra com sucesso
} // termina main