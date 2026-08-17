#include <stdio.h>
#include <stdlib.h>

void print_hex_dump(const char *ptr, int shift, int count) 
{
    unsigned char *p = (unsigned char *)ptr;
    int i = 0;
    printf("%08x  " ,shift * 16);
    for (i = 0; i < count; i++) {
        printf("%02x ", *p);
        if ( *p == '\n') *p = '.';
        if ( *p == 0) *p = '.';
        p++;
    }
    printf("[%.*s]",count, ptr);
    printf("\n");
}
int main()
{
    int c,n,line;
    char* string = malloc(16 * sizeof(char));
    n =0;
    line = 0;
    if (!string) return 1;
    while ((c = getchar()) != EOF){
        string[n] = c;
        n++;
        if (n == 16){
            print_hex_dump(string, line, 16);
            free(string);
            string = malloc(16 *sizeof(char));
            line++;
            n = 0;
        }
    }
    if ( n > 0 ) print_hex_dump(string, line, n);
    free(string);
    return 0;
}


