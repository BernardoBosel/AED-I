#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

static Nodo *criaNodo(Info dado) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    if (novo == NULL) return NULL;                    
    novo->info = dado;                                
    novo->prox = NULL;                                
    novo->ant = NULL;                                 
    return novo;
}

Head *criaLista() {
    Head *lista = (Head *) malloc(sizeof(Head));      
    if (lista == NULL) return NULL;
    lista->pFirst = NULL;                             
    lista->pLast = NULL;                              
    return lista;
}

int listaVazia(Head *lista) {
    return (lista == NULL || lista->pFirst == NULL);  
}

void inserirInicio(Head *lista, Info dado) {
    if (lista == NULL) return;
    Nodo *novo = criaNodo(dado);                      
    if (novo == NULL) return;

    novo->prox = lista->pFirst;                       
    if (lista->pFirst != NULL) {                      
        lista->pFirst->ant = novo;                    
    } else {                                          
        lista->pLast = novo;                          
    }
    lista->pFirst = novo;                             
}

void inserirFinal(Head *lista, Info dado) {
    if (lista == NULL) return;
    Nodo *novo = criaNodo(dado);
    if (novo == NULL) return;

    novo->ant = lista->pLast;                         
    if (lista->pLast != NULL) {                       
        lista->pLast->prox = novo;                    
    } else {                                          
        lista->pFirst = novo;                         
    }
    lista->pLast = novo;                              
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) return 0;                  
    Nodo *aux = lista->pFirst;                        
    lista->pFirst = aux->prox;                        
    if (lista->pFirst != NULL) {                      
        lista->pFirst->ant = NULL;                    
    } else {                                          
        lista->pLast = NULL;                          
    }
    free(aux);                                        
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) return 0;
    Nodo *aux = lista->pLast;                         
    lista->pLast = aux->ant;                          
    if (lista->pLast != NULL) {                       
        lista->pLast->prox = NULL;                    
    } else {                                          
        lista->pFirst = NULL;                         
    }
    free(aux);                                        
    return 1;
}

int buscar(Head *lista, int valor, Info *resultado) {
    if (lista == NULL) return 0;
    Nodo *p = lista->pFirst;                          
    while (p != NULL) {
        if (p->info.valor == valor) {                 
            if (resultado != NULL) *resultado = p->info;   
            return 1;
        }
        p = p->prox;
    }
    return 0;
}

void imprimirLista(Head *lista) {
    if (lista == NULL) { printf("NULL\n"); return; }
    Nodo *p = lista->pFirst;                          
    while (p != NULL) {
        printf("[%d] <-> ", p->info.valor);           
        p = p->prox;
    }
    printf("NULL\n");
}

void imprimirInverso(Head *lista) {
    if (lista == NULL) { printf("NULL\n"); return; }
    Nodo *p = lista->pLast;                           
    while (p != NULL) {
        printf("[%d] <-> ", p->info.valor);
        p = p->ant;                                   
    }
    printf("NULL\n");
}

void liberaLista(Head *lista) {
    if (lista == NULL) return;
    Nodo *p = lista->pFirst;
    while (p != NULL) {
        Nodo *prox = p->prox;
        free(p);
        p = prox;
    }
    free(lista);
}