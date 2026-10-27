#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.

typedef struct node {
    Event *e;
    struct node *next;
}node;

node *cria_node (Event *e){
    node *n =malloc(sizeof(node));
    n->next=NULL;
    n->e=e;
    return n;
}

void destroy_node(node *n)
{
    free(n);
}

struct pq
{
    int sz;
    int lim;
    node *first;
};


/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    PQ *queue = malloc(sizeof(PQ));
    queue->lim=max_N;
    queue->sz=0;
    queue->first=NULL;
    return queue;

}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    if (!PQ_is_empty(pq))
    {
        node *aux=pq->first;
        while (aux!=NULL)
        {
            destroy_event(PQ_delmin(pq));
            aux=pq->first;
        }
    }
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if (pq->sz<pq->lim)
    {
        node *new = cria_node(e);

        if (pq->first==NULL)
        {
            pq->first=new;
        }
        
        else 
        {
            node *aux = pq->first;
            node *ant = NULL;

            while (aux!=NULL&& get_time(e)>get_time(aux->e))
            {
                ant=aux;
                aux=aux->next;
            }
            
            if (ant==NULL)
            {
                new->next=pq->first;
                pq->first=new;
            }
            else
            {
                ant->next=new;
                new->next=aux;
            }
            

        }
        pq->sz++;
    }
    
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    if (!PQ_is_empty(pq))
    {
        node *aux=pq->first;
        Event *e = aux->e;
        pq->first=pq->first->next;
        free(aux);
        pq->sz--;
        return e;
    }
    return NULL;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    
    return pq->sz==0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->sz;
}
