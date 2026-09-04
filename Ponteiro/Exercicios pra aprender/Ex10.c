#include <stdio.h> // inclui printf
#include <stdlib.h> // inclui malloc e free

int *intercalar(int *v1, int *v2, int n, int *n3) { // recebe os vetores, tamanho e endereco do tamanho final
    *n3 = n * 2; // calcula o tamanho do resultado
    int *novo = malloc(sizeof(int) * (*n3)); // aloca o resultado

    if (novo == NULL) { // verifica falha
        *n3 = 0; // informa que nao ha resultado
        return NULL; // retorna NULL
    } // termina a verificacao

    for (int i = 0; i < n; i++) { // percorre os dois vetores
        novo[2 * i] = v1[i]; // coloca v1 na posicao par
        novo[2 * i + 1] = v2[i]; // coloca v2 na posicao seguinte
    } // termina a intercalacao

    return novo; // retorna o vetor criado
} // termina a funcao

int main(void) { // inicia o programa
    int n = 3; // tamanho dos vetores
    int n3; // recebera o tamanho do resultado
    int *v1 = malloc(sizeof(int) * n); // aloca v1
    int *v2 = malloc(sizeof(int) * n); // aloca v2

    if (v1 == NULL || v2 == NULL) { // verifica falha nas alocacoes
        free(v1); // libera v1
        free(v2); // libera v2
        return 1; // encerra com falha
    } // termina a verificacao

    v1[0] = 10; // preenche v1
    v1[1] = 20; // preenche v1
    v1[2] = 30; // preenche v1
    v2[0] = 40; // preenche v2
    v2[1] = 50; // preenche v2
    v2[2] = 60; // preenche v2

    int *novo = intercalar(v1, v2, n, &n3); // cria o vetor intercalado

    if (novo == NULL) { // verifica falha
        free(v1); // libera v1
        free(v2); // libera v2
        return 1; // encerra com erro
    } // termina a verificacao

    for (int i = 0; i < n3; i++) { // percorre o resultado
        printf("%d ", novo[i]); // mostra cada elemento
    } // termina a exibicao

    printf("\n"); // pula linha
    free(v1); // libera v1
    free(v2); // libera v2
    free(novo); // libera o resultado
    return 0; // encerra com sucesso
} // termina main