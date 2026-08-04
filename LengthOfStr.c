#include <stdio.h>
int main()
{
    int c;
    int length = 0;
    while((c = getchar()) != EOF){
        if (c == '\n'){
            printf("Length Of String: %d\n", length);
            length = 0;
        }
        else{
            length++;
        }
    }
    return 0;
}
