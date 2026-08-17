#include <stdio.h>
#include <stdlib.h>
void print_binary(unsigned char byte)
{
    for (int i = 7; i>= 0; i--){
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}

int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        print_binary(c);
    }
    return 0;
}
