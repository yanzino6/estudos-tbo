#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float f_C(int N) {
    float vet[N+1];

    vet[0]=1;

    for (int i = 1; i <= N; i++)
    {   float iFloat=(float)i;
        float val = 0;
        for (int j = 1; j <= i; j++)
        {
            val += vet[i-j] + vet[j-1];
        }
        vet[i]= iFloat + (val/iFloat);
    }
    return vet[N];

}



int main() {
    int N;
    // Le a entrada.
    scanf("%d\n", &N);
    // Calcula e exibe a saida.
    float res = f_C(N);
    printf("%f\n", res);
}
