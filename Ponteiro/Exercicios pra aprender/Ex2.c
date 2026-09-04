#include <stdio.h>

    int soma(int *v, int n){
        int r = 0;
        int *p = v;

        for(int i = 0; i < n; i++){
            r = r + *p;
            p++;
        }
    return r;
}

int main(){
    int v[] = {30, 40, 10, 20};
    int n = 4;
    int r = soma(v, n);

    printf("%d\n", r);
    return 0;
}