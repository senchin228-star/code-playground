#include <stdio.h>
#include <stdlib.h>
#define START_CAPACITY 1
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynArray;

void da_init(DynArray *arr)
{
    arr->size = 0;
    arr->capacity = START_CAPACITY;
    arr->data = malloc(arr->capacity * sizeof(int));
    if (arr->data == NULL) return; 
}

int da_push(DynArray *arr, int val)
{
    if (arr->size >= arr->capacity){
        int *tmp = realloc(arr->data, arr->capacity * 2 * sizeof(int));
        if (tmp == NULL) return 0;
        arr->data = tmp;
        arr->capacity = arr->capacity * 2;
    }
    arr->data[arr->size] = val;
    arr->size++;
    return 1;
}
int  da_get(DynArray *arr, size_t index, int *out)
{
    if (index >= arr->size) return 0;
    *out = arr->data[index];
    return 1;
}
void da_free(DynArray *arr)
{
    free(arr->data);
    arr->data = NULL;
}
void da_random(DynArray *arr)
{
    if (arr == NULL || arr->size <= 1) return;
    
    for (size_t i = arr->size - 1; i > 0; i--) {
        size_t index = rand() % (i + 1);

        int tmp = arr->data[index];
        arr->data[index] = arr->data[i];
        arr->data[i] = tmp;
    }
}

        
