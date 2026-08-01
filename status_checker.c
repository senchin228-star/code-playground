#include <stdio.h>
#include <stdlib.h>
enum state {
    ERR_MEMORY_FAIL = -2,
    ERR_INVALID_INPUT = -1,
    STATE_SUCCESS =2};

int StatusPrint(enum state Status) 
{
    switch (Status) {
        case ERR_MEMORY_FAIL:
            printf("Memory Error \n");
            break;
        case ERR_INVALID_INPUT:
            printf("Invalid input \n");
            break;
        case STATE_SUCCESS:
            printf("Success \n");
            break;
        default:
            printf("Unknown status");
            return 1;
            break;
    }
    return 0;
}

enum state ArrayCreate(int size, int ** out_arr) 
{
    if (size < 0) {
        return ERR_INVALID_INPUT;
    }
    *out_arr = (int*) malloc (size * sizeof(int));
    if (*out_arr == NULL) {
       return ERR_MEMORY_FAIL;
    } 
    return STATE_SUCCESS;
}

int main()
{
    int Size = 42;
    int * my_arr;
    enum state result = ArrayCreate(Size, &my_arr);
    StatusPrint(result);
    return 0;
}

