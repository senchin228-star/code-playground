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
    free(memory);
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
    free(memory);
    return mem;
}
int GetDelay(){
    FILE* cnf = fopen("config.txt", "r");
    if (cnf == NULL) return 0;
    char* string = malloc(30 * sizeof(char));
    char* delstr = malloc(10 * sizeof(char));
    int delstrpos = 0;
    while (fgets(string, 30, cnf)){
        if (!strncmp(string, "delay", 5)){
            for(int i = 0; string[i] != '\n' && i < 30; i++){
                if (string[i] >= '0' && string[i] <= '9'){
                    delstr[delstrpos] = string[i];
                    delstrpos++;
                }
            }
        }
    }
    int delay = 1;
    if (delstrpos > 0) {
        delstr[delstrpos] = '\0';
        delay = atoi(delstr);
    }
    free(delstr);
    free(string);
    fclose(cnf);

    return delay;
}

int main(){
    int delay = 1;
    int first_run = 1;
    FILE* conf = fopen("config.txt", "r");
    if (conf == NULL) {
        conf =  fopen("config.txt", "w");
        if(conf){
            fputs("delay = 1\n", conf);
            fclose(conf);
        }
    }
    else{
        fclose(conf);
    }
    delay = GetDelay();
    while(1){
        if (!first_run) {
            printf("\033[2A");
        }
        first_run = 0;
        int total_mem = GetMemTotal();
        int available_mem = GetMemAvailable();
        printf("\033[KTotal Memory: %d MB\n",total_mem / 1024);
        printf("\033[KAvailable Memory: %d MB\n", available_mem / 1024);
        FILE* f = fopen("Memory.txt", "a");
        fprintf(f, "Total Memory: %d MB\nAvailable Memory: %d MB\n",total_mem / 1024, available_mem / 1024);
        if (fclose(f)) perror("fclose");
        sleep(delay);
    }
    return 0;
}
