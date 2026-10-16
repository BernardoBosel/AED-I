#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char carac;
} Elem;

typedef struct pilha Pilha;

void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);
Pilha *create(void);
void destroy(Pilha *pilha);

#endif