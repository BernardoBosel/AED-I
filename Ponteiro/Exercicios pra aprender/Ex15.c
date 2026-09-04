#include <stdio.h> // inclui printf e scanf
#include <stdlib.h> // inclui malloc, realloc e free

typedef struct { // inicia a estrutura Produto
    char nome[50]; // guarda o nome
    float preco; // guarda o preco
    int quantidade; // guarda a quantidade
} Produto; // cria o tipo Produto

int inserir_produto(Produto **estoque, int *n, Produto novo) { // recebe endereco do vetor, tamanho e produto
    Produto *temporario = realloc(*estoque, sizeof(Produto) * (*n + 1)); // aumenta o vetor em uma posicao
    if (temporario == NULL) { // verifica falha do realloc
        return 0; // informa que a insercao falhou
    } // termina a verificacao
    temporario[*n] = novo; // coloca o novo produto na antiga primeira posicao livre
    *estoque = temporario; // atualiza o ponteiro do vetor
    *n = *n + 1; // aumenta a quantidade
    return 1; // informa sucesso
} // termina inserir_produto

void mostrar_estoque(Produto *estoque, int n) { // recebe o vetor e seu tamanho
    for (int i = 0; i < n; i++) { // percorre todos os produtos
        printf("%s %.2f %d\n", estoque[i].nome, estoque[i].preco, estoque[i].quantidade); // mostra o produto
    } // termina o percurso
} // termina mostrar_estoque

int main(void) { // inicia o programa
    Produto *estoque = NULL; // inicia o vetor vazio
    int n = 0; // inicia a quantidade em zero
    char continuar = 's'; // controla a repeticao do cadastro

    while (continuar == 's') { // continua enquanto o usuario responder s
        Produto novo; // cria o produto que sera inserido
        printf("nome: "); // pede o nome
        scanf("%49s", novo.nome); // le o nome
        printf("preco: "); // pede o preco
        scanf("%f", &novo.preco); // le o preco
        printf("quantidade: "); // pede a quantidade
        scanf("%d", &novo.quantidade); // le a quantidade
        if (inserir_produto(&estoque, &n, novo) == 0) { // tenta inserir e verifica falha
            printf("erro ao alocar memoria\n"); // informa o erro
            free(estoque); // libera o que ja foi alocado
            return 1; // encerra com erro
        } // termina a verificacao
        printf("\nestoque:\n"); // mostra o titulo
        mostrar_estoque(estoque, n); // mostra o estoque atualizado
        printf("deseja inserir outro produto? (s/n): "); // pergunta se continua
        scanf(" %c", &continuar); // le a resposta
    } // termina o cadastro
    free(estoque); // libera o vetor
    return 0; // encerra com sucesso
} // termina main