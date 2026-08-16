#include <stdio.h>

#define CAPACITY 100

typedef struct {
    int data[CAPACITY];
    int front;
    int count;
} Queue;

void queue_init(Queue *q)
{
    q->front = 0;
    q->count = 0;
}
int  queue_push(Queue *q, int val)
{
    if (q->count  >= CAPACITY) return 0;
    int tail = (q->count + q->front) % CAPACITY;
    q->data[tail] = val;
    q->count++;
    return 1;
}
int  queue_pop(Queue *q, int *out)
{
    if (q->count == 0) return 0;
    *out  = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->count--;
    return 1;
}
int  queue_is_empty(Queue *q)
{
    if (q == NULL) return 1;
    return q->count == 0;
}

int main()
{}

