#include <stdio.h> // inclui printf e scanf
#include <stdlib.h> // inclui malloc e free

typedef struct { // inicia a estrutura Produto
    char nome[50]; // guarda o nome
    float preco; // guarda o preco
    int quantidade; // guarda a quantidade
} Produto; // cria o tipo Produto

Produto *criar_estoque(int n) { // recebe a quantidade de produtos
    Produto *estoque = malloc(sizeof(Produto) * n); // aloca n Produtos
    if (estoque == NULL) { // verifica falha
        return NULL; // retorna NULL em caso de erro
    } // termina a verificacao
    Produto *p = estoque; // aponta para o primeiro produto
    for (int i = 0; i < n; i++) { // percorre os n produtos
        printf("nome do produto %d: ", i + 1); // pede o nome
        scanf("%49s", p->nome); // le o nome
        printf("preco do produto %d: ", i + 1); // pede o preco
        scanf("%f", &p->preco); // le o preco
        printf("quantidade do produto %d: ", i + 1); // pede a quantidade
        scanf("%d", &p->quantidade); // le a quantidade
        p++; // avanca para o proximo Produto
    } // termina o preenchimento
    return estoque; // retorna o endereco do primeiro produto
} // termina criar_estoque

void mostrar_estoque(Produto *estoque, int n) { // recebe vetor e tamanho
    Produto *p = estoque; // inicia o ponteiro no primeiro produto
    for (int i = 0; i < n; i++) { // percorre todos os produtos
        printf("%s %.2f %d\n", p->nome, p->preco, p->quantidade); // mostra o produto
        p++; // avanca para o proximo
    } // termina o percurso
} // termina mostrar_estoque

int main(void) { // inicia o programa
    int n; // guarda a quantidade
    printf("quantos produtos: "); // pede a quantidade
    scanf("%d", &n); // le a quantidade
    if (n <= 0) { // verifica quantidade invalida
        return 1; // encerra com erro
    } // termina a verificacao
    Produto *estoque = criar_estoque(n); // cria o vetor dinamico
    if (estoque == NULL) { // verifica falha
        printf("erro ao alocar memoria\n"); // informa o erro
        return 1; // encerra com erro
    } // termina a verificacao
    mostrar_estoque(estoque, n); // mostra os produtos
    free(estoque); // libera o vetor inteiro
    return 0; // encerra com sucesso
} // termina main