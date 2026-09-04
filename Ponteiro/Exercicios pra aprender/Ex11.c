#include <stdio.h> // inclui scanf e printf
#include <stdlib.h> // inclui malloc e free

int soma_diagonal(int **mat, int n) { // recebe a matriz e seu tamanho
    int soma = 0; // inicia a soma

    for (int i = 0; i < n; i++) { // percorre os indices da diagonal
        soma = soma + mat[i][i]; // soma o elemento da diagonal principal
    } // termina o percurso

    return soma; // retorna a soma
} // termina a funcao

void liberar_matriz(int **mat, int n) { // recebe a matriz e o numero de linhas
    for (int i = 0; i < n; i++) { // percorre todas as linhas
        free(mat[i]); // libera a linha atual
    } // termina a liberacao das linhas

    free(mat); // libera o vetor de ponteiros
} // termina a funcao

int main(void) { // inicia o programa
    int n; // guarda o tamanho da matriz

    printf("digite n: "); // pede o tamanho
    scanf("%d", &n); // le o tamanho

    if (n <= 0) { // verifica tamanho invalido
        return 1; // encerra com erro
    } // termina a verificacao

    int **mat = malloc(sizeof(int *) * n); // aloca os ponteiros das linhas

    if (mat == NULL) { // verifica falha
        printf("erro ao alocar memoria\n"); // informa o erro
        return 1; // encerra com falha
    } // termina a verificacao

    for (int i = 0; i < n; i++) { // percorre as linhas
        mat[i] = malloc(sizeof(int) * n); // aloca os elementos da linha

        if (mat[i] == NULL) { // verifica falha na linha
            for (int j = 0; j < i; j++) { // percorre linhas ja alocadas
                free(mat[j]); // libera cada linha criada
            } // termina a liberacao parcial

            free(mat); // libera o vetor de ponteiros
            return 1; // encerra com falha
        } // termina a verificacao
    } // termina a alocacao

    for (int i = 0; i < n; i++) { // percorre as linhas para preencher
        for (int j = 0; j < n; j++) { // percorre as colunas
            printf("mat[%d][%d]: ", i, j); // pede o elemento
            scanf("%d", &mat[i][j]); // armazena o elemento
        } // termina as colunas
    } // termina o preenchimento

    printf("matriz:\n"); // mostra o titulo

    for (int i = 0; i < n; i++) { // percorre as linhas para mostrar
        for (int j = 0; j < n; j++) { // percorre as colunas
            printf("%d ", mat[i][j]); // mostra o elemento
        } // termina a linha
        printf("\n"); // pula para a proxima linha
    } // termina a exibicao

    int resultado = soma_diagonal(mat, n); // calcula a diagonal principal
    printf("soma da diagonal: %d\n", resultado); // mostra a soma

    liberar_matriz(mat, n); // libera todas as alocacoes
    return 0; // encerra com sucesso
} // termina main