#include <stdio.h> // inclui printf
#include <stdlib.h> // inclui malloc e free

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) { // recebe os vetores e o endereco do tamanho final
    *n3 = n1 + n2; // calcula o tamanho total
    int *novo = malloc(sizeof(int) * (*n3)); // aloca o vetor resultante

    if (novo == NULL) { // verifica falha
        *n3 = 0; // indica que nao houve resultado
        return NULL; // retorna NULL
    } // termina a verificacao

    for (int i = 0; i < n1; i++) { // percorre o primeiro vetor
        novo[i] = v1[i]; // copia o primeiro vetor
    } // termina a copia

    for (int i = 0; i < n2; i++) { // percorre o segundo vetor
        novo[n1 + i] = v2[i]; // coloca v2 depois de v1
    } // termina a copia

    return novo; // devolve o vetor criado
} // termina a funcao

int main(void) { // inicia o programa
    int n1 = 3; // tamanho de v1
    int n2 = 2; // tamanho de v2
    int n3; // recebera o tamanho final
    int *v1 = malloc(sizeof(int) * n1); // aloca v1
    int *v2 = malloc(sizeof(int) * n2); // aloca v2

    if (v1 == NULL || v2 == NULL) { // verifica as alocacoes
        free(v1); // libera v1 se necessario
        free(v2); // libera v2 se necessario
        return 1; // encerra com falha
    } // termina a verificacao

    v1[0] = 10; // preenche v1
    v1[1] = 20; // preenche v1
    v1[2] = 30; // preenche v1
    v2[0] = 40; // preenche v2
    v2[1] = 50; // preenche v2

    int *novo = concatenar(v1, n1, v2, n2, &n3); // cria o resultado

    if (novo == NULL) { // verifica falha da funcao
        free(v1); // libera v1
        free(v2); // libera v2
        return 1; // encerra com falha
    } // termina a verificacao

    for (int i = 0; i < n3; i++) { // percorre o resultado
        printf("%d ", novo[i]); // mostra o elemento
    } // termina a exibicao

    printf("\n"); // pula linha
    free(v1); // libera v1
    free(v2); // libera v2
    free(novo); // libera o resultado
    return 0; // encerra com sucesso
} // termina main