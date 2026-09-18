#include <stdio.h>
#include <stdlib.h>

void print_post_order(int *pre, int *in, int N) {
    if (N==1)
    {
        printf("%d\n",in[0]);
        return;
    }

    int i=0;

    while (in[i]!=pre[0])
    {
        i++;
    }
    print_post_order(&pre[1],in,i);
    print_post_order(&pre[i+1],&in[i+1],N-i-1);
    
}

int main() {
    // Le a entrada.
    int N;
    scanf("%d\n", &N);
    int *pre = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
    }
    int *in = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }

    // Calcula e exibe a saida.
    print_post_order(pre, in, N);
    printf("\n");
    free(pre);
    free(in);
}
