#include <stdio.h>
void sum_ints(void *acc, const void *elem)
{
    *(int*)acc = *(int*)acc + *(const int*)elem;
}
void max_ints(void *acc, const void *elem)
{
    if (*(const int*)elem > *(int*)acc) *(int*)acc = *(const int*)elem;
}

void generic_reduce(const void *base, size_t n, size_t elem_size,
                     void *accumulator,
                     void (*reducer)(void *acc, const void *elem))
{
    const char *arr = (const char*) base;
    for (size_t i = 0; i < n; i++){
        const char *elem_i = arr + i * elem_size;
        reducer(accumulator, elem_i);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int total = arr[0];
    generic_reduce(arr, 5, sizeof(int), &total, max_ints);
    printf("%d\n", total);   // 15
}
