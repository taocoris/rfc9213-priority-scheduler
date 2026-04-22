#include "heap_manager.h"
#include <stdlib.h>
#include <string.h>

PriorityQueue* create_queue(int initial_capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (HttpRequest*)malloc(sizeof(HttpRequest) * initial_capacity);
    pq->size = 0;
    pq->capacity = initial_capacity;
    return pq;
}

void swap(HttpRequest* a, HttpRequest* b) {
    HttpRequest temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue* pq, HttpRequest req) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->heap = (HttpRequest*)realloc(pq->heap, sizeof(HttpRequest) * pq->capacity);
    }

    pq->heap[pq->size] = req;
    int i = pq->size++;

    while (i != 0 && pq->heap[(i - 1) / 2].urgency > pq->heap[i].urgency) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HttpRequest pop(PriorityQueue* pq) {
    HttpRequest root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];

    int i = 0;
    while (2 * i + 1 < pq->size) {
        int smallest = 2 * i + 1;
        if (smallest + 1 < pq->size && pq->heap[smallest + 1].urgency < pq->heap[smallest].urgency)
            smallest++;
        
        if (pq->heap[i].urgency <= pq->heap[smallest].urgency) break;
        
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return root;
}

void free_queue(PriorityQueue* pq) {
    free(pq->heap);
    free(pq);
}