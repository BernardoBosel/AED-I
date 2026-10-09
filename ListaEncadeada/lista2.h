#ifndef LISTA2_H
#define LISTA2_H

typedef struct {
    int valor;
} Info;

typedef struct Nodo {
    Info info;
    struct Nodo *prox;
    struct Nodo *ant;
} Nodo;

typedef struct {
    Nodo *pFirst;               
    Nodo *pLast;
} Head;

Head *criaLista();
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Info dado);
void inserirFinal(Head *lista, Info dado);
int removerInicio(Head *lista);
int removerFinal(Head *lista);
int buscar(Head *lista, int valor, Info *resultado);
void imprimirLista(Head *lista);
void imprimirInverso(Head *lista);
void liberaLista(Head *lista);

#endif