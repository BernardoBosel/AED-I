#include <stdio.h> 
#include <stdlib.h> 

int *copia_vetor(int *v, int n){ 
    int *novo = malloc(sizeof(int) * n); 

    if (novo == NULL){ 
        return NULL; 
    }

    for (int i = 0; i < n; i++) {
        novo[i] = v[i];
    }

    return novo;
}

int main(){
    int v[] = {10, 20, 30, 40};
    int n = 4;
    int *copia = copia_vetor(v, n);

    if(copia == NULL){ 
        printf("erro ao alocar memoria\n"); 
        return 1;
    } 

    for(int i = 0; i < n; i++){
        printf("%d ", copia[i]);
    }

    printf("\n");
    free(copia);
    return 0;
}