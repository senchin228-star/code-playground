#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque
{
    Node *head;
    Node *tail;
} Deque;

void deque_init(Deque *deq)
{
    if (deq  == NULL) return;
    deq->head = NULL;
    deq->tail = NULL;
}

void push_front(Deque *dq, int val)
{
    if (dq == NULL) return;

    Node *tmp = malloc(sizeof(Node));
    if (tmp == NULL) return;
    tmp->prev = NULL;
    tmp->data = val;

    if (dq->head == NULL || dq->tail == NULL){
        tmp->next = NULL;
        dq->head = tmp;
        dq->tail = tmp;
    }
    else{
        dq->head->prev = tmp;
        tmp->next = dq->head;
        dq->head = tmp;
    }
}

void push_back(Deque *dq, int value){
    if (dq == NULL) return;
    Node *tmp = malloc(sizeof(Node));
    if (tmp == NULL) return;
    tmp->next = NULL;
    tmp->data = value;

    if (dq->head == NULL || dq->tail == NULL){
        tmp->prev = NULL;
        dq->head = tmp;
        dq->tail = tmp;
    }
    else{
        tmp->prev = dq->tail;
        dq->tail->next = tmp;
        dq->tail = tmp;
    }
}

int pop_front(Deque *dq)
{
    if (dq == NULL) return -1;
    if (dq->head == NULL ||  dq->tail == NULL) return -1;
    
    Node *tmp = dq->head;
    int val = tmp->data;
    
    if(dq->head == dq->tail){
        dq->head = NULL;
        dq->tail = NULL;
    }else{
        dq->head = dq->head->next;
        dq->head->prev = NULL;
    }
    free(tmp);
    return (val);
}
int pop_back(Deque *dq)
{
    if (dq == NULL) return -1;
    if(dq->head == NULL || dq->tail == NULL) return -1;

    Node *tmp = dq->tail;
    int val = tmp->data;
    
    if (dq->head == dq->tail){
        dq->head = NULL;
        dq->tail = NULL;
    }
    else{
        dq->tail = dq->tail->prev;
        dq->tail->next  = NULL;
    }
    free(tmp);
    return(val);
}

void clear(Deque *dq)
{
    if (dq == NULL) return;
    while(dq->head != NULL){
        Node *tmp = dq->head;
        dq->head = dq->head->next;
        free(tmp);
    }
    dq->head = NULL;
    dq->tail = NULL;
    return;
}

int main(){
    Deque my_dq;
    deque_init(&my_dq);
    push_front(&my_dq, 42);
    push_front(&my_dq, 67);
    push_back(&my_dq, 1337);
    while(my_dq.head != NULL){
        int i = pop_front(&my_dq);
        printf("%d\n", i);
    }
}


