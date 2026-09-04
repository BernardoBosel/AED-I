#include <stdio.h> // inclui printf e scanf
#include <stdlib.h> // inclui malloc e free

typedef struct { // inicia a estrutura Produto
    char nome[50]; // guarda o nome
    float preco; // guarda o preco
    int quantidade; // guarda a quantidade
} Produto; // cria o tipo Produto

Produto **criar_estoque_ptrs(int n) { // retorna vetor de ponteiros para Produto
    Produto **estoque = malloc(sizeof(Produto *) * n); // aloca n ponteiros
    if (estoque == NULL) { // verifica falha
        return NULL; // retorna NULL
    } // termina a verificacao
    for (int i = 0; i < n; i++) { // percorre as posicoes
        estoque[i] = malloc(sizeof(Produto)); // aloca um Produto para a posicao
        if (estoque[i] == NULL) { // verifica falha da alocacao atual
            for (int j = 0; j < i; j++) { // percorre produtos ja criados
                free(estoque[j]); // libera cada produto anterior
            } // termina a liberacao parcial
            free(estoque); // libera o vetor de ponteiros
            return NULL; // informa a falha
        } // termina a verificacao
        printf("nome do produto %d: ", i + 1); // pede o nome
        scanf("%49s", estoque[i]->nome); // le o nome
        printf("preco do produto %d: ", i + 1); // pede o preco
        scanf("%f", &estoque[i]->preco); // le o preco
        printf("quantidade do produto %d: ", i + 1); // pede a quantidade
        scanf("%d", &estoque[i]->quantidade); // le a quantidade
    } // termina o preenchimento
    return estoque; // retorna o vetor de ponteiros
} // termina criar_estoque_ptrs

void liberar_estoque_ptrs(Produto **estoque, int n) { // recebe o vetor e a quantidade
    if (estoque == NULL) { // verifica se o vetor nao existe
        return; // nao ha nada para liberar
    } // termina a verificacao
    for (int i = 0; i < n; i++) { // percorre os ponteiros
        free(estoque[i]); // libera cada Produto
    } // termina a liberacao dos produtos
    free(estoque); // libera o vetor de ponteiros
} // termina liberar_estoque_ptrs

int main(void) { // inicia o programa
    int n; // guarda a quantidade
    printf("quantos produtos: "); // pede a quantidade
    scanf("%d", &n); // le a quantidade
    if (n <= 0) { // verifica quantidade invalida
        return 1; // encerra com erro
    } // termina a verificacao
    Produto **estoque = criar_estoque_ptrs(n); // cria o estoque
    if (estoque == NULL) { // verifica falha
        printf("erro ao alocar memoria\n"); // informa o erro
        return 1; // encerra com erro
    } // termina a verificacao
    for (int i = 0; i < n; i++) { // percorre os produtos
        printf("%s %.2f %d\n", estoque[i]->nome, estoque[i]->preco, estoque[i]->quantidade); // mostra os dados
    } // termina a exibicao
    liberar_estoque_ptrs(estoque, n); // libera produtos e vetor
    return 0; // encerra com sucesso
} // termina main