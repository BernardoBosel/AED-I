#include <stdio.h> 

void min_max(int *v, int n, int *min, int *max) { 
    int menor = *v; 
    int maior = *v; 
    int *p = v + 1; 

    while(p < v + n) { 
        if(*p < menor){ 
            menor = *p; 
        } 

        if(*p > maior){ 
            maior = *p; 
        } 

        p++; 
    } 

    *min = menor; 
    *max = maior; 
} 

int main(void) {
    int v[] = {7, 2, 9, 1, 6}; 
    int n = 5; 
    int min; 
    int max; 

    min_max(v, n, &min, &max);
    printf("min = %d\n", min);
    printf("max = %d\n", max);

    return 0; 
}