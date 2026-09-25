#include <stdio.h>

int stcrmp (char *a, char *b)
{
    int i = 0;
    while (a[i]==b[i]&&a[i+1]!='\0'&&b[i+1]!='\0')
    {
        i++;
    }
    return (unsigned char)a[i] - (unsigned char) b[i];
}

int main ()
{
    char nome1[18];
    char nome2[18];

    scanf("%s\n",nome1);
    scanf("%s\n",nome2);

    printf("%d", stcrmp(nome1,nome2));


   return 0;
}