#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int valor;
} Info;

typedef struct No {
    Info info; 
    struct No *prox;
} No;

typedef struct {
    No *pFirst;               
} Head;                         

Head *criaLista();                           
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Info dado);
void inserirFinal(Head *lista, Info dado);
int removerInicio(Head *lista);             
int removerFinal(Head *lista);               
int buscar(Head *lista, int valor, Info *resultado);
void imprimirLista(Head *lista);  
void liberaLista(Head *lista);

#endif