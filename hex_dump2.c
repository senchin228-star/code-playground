#include <stdio.h>
#include <stdlib.h>

void print_hex_dump(const void *ptr, size_t size) 
{
    unsigned char *p = (unsigned char *)ptr;
    size_t i = 0;
    for (i = 0; i < size; i++) {
        if (i % 16 == 0) {
            if (i != 0) {
                printf("\n");
            }
            printf("%08zx  ", i);
        }
        printf("%x ", *p);
        p++;
    }
    printf("\n%08zx  ", i);
}
int main()
{
    int c,n;
    char* string = malloc(256 * sizeof(char));
    n =0;
    while ((c = getchar()) != EOF){
        string[n] = c;
        n++; 
    }
    print_hex_dump(string, n);
    return 0;
}


