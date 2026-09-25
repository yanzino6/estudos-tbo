#include "UF.h"
#include <stdlib.h>

static int *id;
static int *sz;

void UF_init(int N)
{
    id = malloc (N*sizeof(int));
    sz = malloc (N*sizeof(int));
    for (int i = 0; i < N; i++)
    {
        id[i]=i;
        sz[i]=1;
    }
    
}

// Adiciona uma conexao entre p e q.
void UF_union(int p, int q)
{   
    int proot = UF_find(p);
    int qroot = UF_find(q);



    if (sz[proot]<sz[qroot])
    {
        id[proot]=qroot;
        sz[qroot]+=sz[proot];
    }
    else
    {
        id[qroot]=proot;
        sz[proot]+=sz[qroot];  
    }
    
}

// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(int p)
{

    while (p!=id[p])
    {
        id[p]=id[id[p]];
        p=id[p];
    }
    return p;
    
}

// Os objetos p e q estao no mesmo componente?
bool UF_connected(int p, int q)
{
    if (UF_find(p)==UF_find(q))
    {
        return true;
    }
    return false;
    
}