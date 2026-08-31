#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc == 4 && strcmp(argv[1], "en" ) != 0){
        if (argc != 3) return 1;
    }
    const char mathurl[] = "https://gdz.ru/class-10/algebra/alimov-15/";
    const char rusurl[] = "https://reshak.ru/otvet/otvet14.php?otvet1=";
    const char enurl[] = "https://reshak.ru/otvet/otvet_txt.php?otvet1=/spotlight10/images/";
    char command[512] = "echo 'invalid argument'";

    if (strcmp(argv[1], "math") == 0){
        snprintf(command, sizeof(command), "xdg-open %s%s-nom/", mathurl, argv[2]);
    }
    if (strcmp(argv[1], "rus") == 0){
        snprintf(command, sizeof(command), "xdg-open %s%s", rusurl, argv[2]);
    }
    if (strcmp(argv[1], "en") == 0){
        snprintf(command, sizeof(command), "xdg-open %smodule%s/%s/1", enurl, argv[2], argv[3]);
    }

    system(command);
    return 0;
}


            
