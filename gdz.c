#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc < 2){
        printf("insufficient arguments");
        return 1;
    }
    if (argc == 4 && strcmp(argv[1], "en" ) != 0){
        if (argc != 3) return 1;
    }
    const char mathurl[] = "https://gdz.ru/class-10/algebra/alimov-15/";
    const char rusurl[] = "https://reshak.ru/otvet/otvet14.php?otvet1=";
    const char enurl[] = "https://reshak.ru/otvet/otvet_txt.php?otvet1=/spotlight10/images/";
    char command[512];

    if (strcmp(argv[1], "math") == 0){
        snprintf(command, sizeof(command), "%s%s-nom/", mathurl, argv[2]);
    }
    if (strcmp(argv[1], "rus") == 0){
        snprintf(command, sizeof(command), "%s%s", rusurl, argv[2]);
    }
    if (strcmp(argv[1], "en") == 0){
        snprintf(command, sizeof(command), "%smodule%s/%s/1", enurl, argv[2], argv[3]);
    }
    char *args[] = {"xdg-open", command, NULL};
    execvp(args[0], args);
    return 0;
}


            
