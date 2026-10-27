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
struct pq{
    Event **eventArr;
    int sz;
    int cap;
};

// ###implementando as funcoes especificas de min-heap###

void swap(PQ *pq, int i, int j)
{
    Event *aux = pq->eventArr[i];
    pq->eventArr[i]=pq->eventArr[j];
    pq->eventArr[j]=aux;
}

void fix_up (PQ *pq, int k)
{
    while (k>1 && compare(pq->eventArr[k/2],pq->eventArr[k])>0)
    {
        swap(pq,k,k/2);
        k=k/2;
    }
    
}

void fix_down (PQ *pq, int k)
{
    while (2*k<=pq->sz)
    {
        int j=k*2;
        if (j<pq->sz&&compare(pq->eventArr[j],pq->eventArr[j+1])>0)
        {
            j++;
        }
        if (compare(pq->eventArr[k],pq->eventArr[j])<=0)
        {
            break;
        }
        swap(pq,k,j);
        k=j;
        
    }
    
}
// ###implementando as funcoes especificas de min-heap###

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.
    PQ *queue = malloc(sizeof(PQ));
    queue->sz=0;
    queue->eventArr=malloc((max_N+1)*sizeof(Event*));
    queue->cap=max_N+1;
    return queue;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    int i;
    for ( i = 1; i <= pq->sz; i++)
    {
        destroy_event(pq->eventArr[i]);
    }
    free(pq->eventArr);
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
    if (pq->sz<pq->cap-1)
    {
        pq->sz++;
        pq->eventArr[pq->sz]=e;
        fix_up(pq,pq->sz);
    }
    
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    if (!PQ_is_empty(pq))
    {
        Event *min = pq->eventArr[1];
        swap(pq,1,pq->sz);
        pq->sz--;
        fix_down(pq,1);
        return min;
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
    // TODO: Implemente essa função.
    return pq->sz;
}
