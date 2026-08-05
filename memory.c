#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* GetMemTotal()
{
    FILE* f;
    char* string = malloc(30 * sizeof(char));
    char* memory = malloc(9 * sizeof(char));
    f = fopen("/proc/meminfo", "r");
    if (f == NULL) {
        perror("/proc/meminfo");
        return NULL;
    }
    int index_mem = 0;
    while ((fgets(string, 30, f)) != NULL){
        if(!strncmp(string, "MemTotal", 8)) {
            for ( int i = 0; string[i] != '\n' && string[i] != '\0'; i++){
                if (string[i] >= '0' && string[i] <= '9') {
                    memory[index_mem++] = string[i];
                }
            }
            break;
        } 
    }
    memory[index_mem] = '\0';
    if (fclose(f) != 0) {
        perror("fclose");
    }
    free(string);
    return memory;
}
int main(){
    char* memstr = GetMemTotal();
    int mem = 0;
    for (int a = 0; memstr[a] != '\0'; a++) {
    mem = mem * 10 + (memstr[a] - '0');
    }
    free(memstr);
    printf("%d", mem);
    return 0;
}
