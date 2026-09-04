#include <stdio.h> 

void troca_vizinhos(int *a, int *b) { 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp;
} 

int main(void) { 
    int v[] = {10, 20, 30, 40, 50, 60}; 
    int n = 6; 

    for(int i = 0; i < n; i += 2) { 
        troca_vizinhos(&v[i], &v[i + 1]); 
    } 

    for(int i = 0; i < n; i++) { 
        printf("%d ", v[i]); 
    } 

    printf("\n"); 
    return 0; 
}