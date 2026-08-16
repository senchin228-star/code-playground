#include <stdio.h>

#define CAPACITY 100

typedef struct {
    int data[CAPACITY];
    int top;
} Stack;

void stack_init(Stack *s)
{
    s->top = -1;
}

int stack_push(Stack *s, int val)
{
    if (s == NULL) return 0;
    if (s->top >= CAPACITY - 1) return 0;
    s->top++;
    s->data[s->top] = val;
    return 1;
}
int stack_pop(Stack *s, int *val)
{
    if (s == NULL) return 0;
    if (s->top == -1) return 0;
    *val = s->data[s->top];
    s->top--;
    return 1;
}

int stack_is_empty(Stack *s){
    if (s == NULL) return 1;
    return s->top == -1;
}

int stack_peek(Stack *s, int *val)
{
    if (s == NULL) return 0;
    if (s->top == -1) return 0;
    *val = s->data[s->top];
    return 1;
}


int main()
{
    Stack s;
    stack_init(&s);

    printf("is_empty: %d (ожидаем 1)\n", stack_is_empty(&s));

    stack_push(&s, 10);
    stack_push(&s, 20);
    stack_push(&s, 30);

    printf("is_empty: %d (ожидаем 0)\n", stack_is_empty(&s));

    int top;
    int ok = stack_peek(&s, &top);
    printf("peek: ok=%d value=%d (ожидаем 1, 30)\n", ok, top);

    int val;
    ok = stack_pop(&s, &val);
    printf("pop: ok=%d value=%d (ожидаем 1, 30)\n", ok, val);

    ok = stack_pop(&s, &val);
    printf("pop: ok=%d value=%d (ожидаем 1, 20)\n", ok, val);

    ok = stack_pop(&s, &val);
    printf("pop: ok=%d value=%d (ожидаем 1, 10)\n", ok, val);

    printf("is_empty: %d (ожидаем 1)\n", stack_is_empty(&s));

    ok = stack_pop(&s, &val);
    printf("pop на пустом: ok=%d (ожидаем 0)\n", ok);

    // проверка переполнения
    int overflow_hit = 0;
    for (int i = 0; i < CAPACITY + 5; i++) {
        if (!stack_push(&s, i)) {
            overflow_hit = 1;
            printf("переполнение поймано на i=%d (ожидаем 100)\n", i);
            break;
        }
    }
    printf("overflow_hit: %d (ожидаем 1)\n", overflow_hit);

    return 0;
}
