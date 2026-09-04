#include <stdio.h> // inclui scanf e printf
#include <stdlib.h> // inclui malloc realloc e free

int main(void) { // inicia o programa
    int *vetor = malloc(sizeof(int)); // comeca com espaco para um elemento
    int n = 0; // conta os elementos realmente armazenados
    int valor; // guarda o valor digitado
    int *temporario; // guarda temporariamente o resultado do realloc

    if (vetor == NULL) { // verifica a primeira alocacao
        printf("erro ao alocar memoria\n"); // informa o erro
        return 1; // encerra com falha
    } // termina a verificacao

    while (1) { // continua ate o valor de parada
        printf("digite um valor (-1 para parar): "); // pede um valor
        scanf("%d", &valor); // le o valor

        if (valor == -1) { // verifica o sinal de parada
            break; // termina sem armazenar -1
        } // termina a verificacao

        if (n > 0) { // se a primeira posicao ja foi usada
            temporario = realloc(vetor, sizeof(int) * (n + 1)); // aumenta o vetor em uma posicao

            if (temporario == NULL) { // verifica falha do realloc
                printf("erro ao realocar memoria\n"); // informa o erro
                free(vetor); // libera o bloco ainda acessivel
                return 1; // encerra com falha
            } // termina a verificacao

            vetor = temporario; // atualiza o endereco depois do sucesso
        } // termina a condicao

        vetor[n] = valor; // coloca o novo valor na primeira posicao livre
        n++; // aumenta a quantidade armazenada
    } // termina a leitura

    if (n > 0) { // verifica se houve valores
        int menor = vetor[0]; // inicia o menor com o primeiro valor
        int maior = vetor[0]; // inicia o maior com o primeiro valor

        for (int i = 1; i < n; i++) { // percorre os demais valores
            if (vetor[i] < menor) { // verifica se encontrou menor
                menor = vetor[i]; // atualiza o menor
            } // termina o if
            if (vetor[i] > maior) { // verifica se encontrou maior
                maior = vetor[i]; // atualiza o maior
            } // termina o if
        } // termina o percurso

        printf("valores: "); // inicia a exibicao
        for (int i = 0; i < n; i++) { // percorre os valores
            printf("%d ", vetor[i]); // mostra cada valor
        } // termina a exibicao

        printf("\n"); // pula linha
        printf("quantidade: %d\n", n); // mostra a quantidade
        printf("menor: %d\n", menor); // mostra o menor
        printf("maior: %d\n", maior); // mostra o maior
    } else { // caso nenhum valor tenha sido armazenado
        printf("nenhum valor armazenado\n"); // informa vetor vazio
    } // termina a verificacao

    free(vetor); // libera a memoria
    return 0; // encerra com sucesso
} // termina main