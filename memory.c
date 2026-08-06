#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int GetMemTotal()
{
    FILE* f;
    char* string = malloc(30 * sizeof(char));
    char* memory = malloc(9 * sizeof(char));
    f = fopen("/proc/meminfo", "r");
    if (f == NULL) {
        perror("/proc/meminfo");
        return 1;
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
    int mem = atoi(memory);
    free(string);
    return mem;
}
int GetMemAvailable()
{
    FILE* f;
    char* string = malloc(30 * sizeof(char));
    char* memory = malloc(9 * sizeof(char));
    f = fopen("/proc/meminfo", "r");
    if (f == NULL) {
        perror("/proc/meminfo");
        return 1;
    }
    int index_mem = 0;
    while ((fgets(string, 30, f)) != NULL){
        if(!strncmp(string, "MemAvailable", 12)) {
            for ( int i = 0; string[i] != '\n' && string[i] != '\0'; i++){
                if (string[i] >= '0' && string[i] <= '9') {
                    memory[index_mem++] = string[i];
                }
            }
            break;
        } 
    }
    memory[index_mem] = '\0';
    if (fclose(f)) {
        perror("fclose");
    }
    int mem = atoi(memory);
    free(string);
    return mem;
}
int main(){
    int first_run = 1;
    while(1){
        if (!first_run) {
            printf("\033[2A");
        }
        first_run = 0;
        int total_mem = GetMemTotal();
        int available_mem = GetMemAvailable();
        printf("\033[KTotal Memory: %d MB\n",total_mem / 1024);
        printf("\033[KAvailable Memory: %d MB\n", available_mem / 1024);
        fflush(stdout);
        FILE* f = fopen("Memory.txt", "w");
        fprintf(f, "Total Memory: %d MB\nAvailable Memory: %d MB\n",total_mem / 1024, available_mem / 1024);
        if (fclose(f)) perror("fclose");
        sleep(1);
    }
    return 0;
}
