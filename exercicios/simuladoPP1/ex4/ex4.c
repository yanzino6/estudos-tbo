#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 18
int stcrmp (char *a, char *b)
{
    int i = 0;
    while (a[i]==b[i]&&a[i+1]!='\0'&&b[i+1]!='\0')
    {
        i++;
    }
    return (unsigned char)b[i] - (unsigned char) a[i];
}

void swap (char *a, char *b)
{
    for (int i = 0; i < N; i++)
    {
        char temp = a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}
void copy (char *dest, char *font)
{
    for (int i = 0; i < N; i++)
    { 
        dest[i]=font[i];
    }
}

void sort(char a[M][N]) {
    int min=0;
    for (int i = 0; i < M; i++)
    {
        if (stcrmp(a[i],a[min])>0)
        {
            min=i;
        }
        
    }
    swap(a[0],a[min]);
    char sent[N];
    for (int i = 2; i < M; i++)
    {
        copy(sent,a[i]);
        int j;
        for (j= i; j > 0 && stcrmp(sent,a[j-1])>0; j--)
        {
            copy(a[j],a[j-1]);
        }
        copy(a[j],sent);
    }
    

}

int main() {
    char a[M][N];

    // Le a entrada.
    for (int i = 0; i < M; i++) {
        fscanf(stdin,"%s", a[i]);
    }

    // Ordena.
    sort(a);

    // Exibe o resultado.
    for (int i = 0; i < M; i++) {
        printf("%s\n", a[i]);
    }
}
