#include <stdio.h>

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
    print_hex_dump("HelloHelloHelloHelloHelloHelloHi", 32);
    return 0;
}

