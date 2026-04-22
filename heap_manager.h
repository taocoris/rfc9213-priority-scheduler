#ifndef HEAP_MANAGER_H
#define HEAP_MANAGER_H

typedef struct {
    int urgency; 
    char request_id[50];
} HttpRequest;

typedef struct {
    HttpRequest* heap;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* create_queue(int initial_capacity);
void push(PriorityQueue* pq, HttpRequest req);
HttpRequest pop(PriorityQueue* pq);
void free_queue(PriorityQueue* pq);

#endif