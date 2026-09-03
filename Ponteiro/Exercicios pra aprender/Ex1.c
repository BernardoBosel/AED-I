#include <stdio.h> 

void inverter(int *v, int n) { 
    int *inicio = v; 
    int *fim = v + n - 1; 
    int temporario; 

    while (inicio < fim) { 
        temporario = *inicio; 
        *inicio = *fim; 
        *fim = temporario; 
        inicio++; 
        fim--; 
    } 
} 

int main() { 
    int v[] = {10, 20, 30, 40, 50}; 
    int n = 5; 

    inverter(v, n); 

    for (int *p = v; p < v + n; p++) { 
        printf("%d ", *p); 
    } 

    printf("\n"); 
    return 0;
}
