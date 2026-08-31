#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc != 3) return 1;
    const char mathurl[] = "https://gdz.ru/class-10/algebra/";
    char command[512] = "pwd";

    if (strcmp(argv[1], "math") == 0){
        snprintf(command, sizeof(command), "chromium %s", mathurl);
    }
    printf("argv[1] : %s, command: %s", argv[1], command);
    system(command);
    return 0;
}


            
