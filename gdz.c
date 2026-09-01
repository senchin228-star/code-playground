#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc <= 2){
        printf("insufficient arguments");
        return 1;
    }

    const char mathurl[] = "https://gdz.ru/class-10/algebra/merzlyak-nomirovskij-uglublennij/";
    const char geomurl[] = "https://gdz.ru/class-10/geometria/atanasyan-10-11/10-class-";
    const char rusurl[] = "https://reshak.ru/otvet/reshebniki.php?otvet=";
    const char enurl[] = "https://reshak.ru/otvet/otvet_txt.php?otvet1=/spotlight10/images/";
    char command[512];

    if (strcmp(argv[1], "math") == 0 && (argc >= 4)){
        snprintf(command, sizeof(command), "%s%s-item-%s/", mathurl, argv[2], argv[3]);
        printf("%s\n", command);
    }
    else if (strcmp(argv[1], "geom") == 0){
        snprintf(command, sizeof(command), "%s%s/", geomurl, argv[2]);
        printf("%s\n", command);
    }
    else if (strcmp(argv[1], "rus") == 0){
        snprintf(command, sizeof(command), "%s%s&predmet=ribchenkova10-11", rusurl, argv[2]);
    }
    else if (strcmp(argv[1], "en") == 0){
        snprintf(command, sizeof(command), "%smodule%s/%s/1", enurl, argv[2], argv[3]);
    }
    else return 1;

    char *args[] = {"xdg-open", command, NULL};
    execvp(args[0], args);
    return 0;
}


            
