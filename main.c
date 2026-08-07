#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    CONFIG_OK = 0,
    CONFIG_ERR_FILE_NOT_FOUND,
    CONFIG_ERR_READ_FAIL
} ConfigStatus;

typedef struct {
    int delay;
    int max_memory;
    int core_numbers;
    int core_frequency;
} Config

int getValue(char* string)
{
    char value[50];
    int last_sym = 0;
    for (int i = 0; string[i] != '\n' && string[i]; i++){
        if (string[i] >= '0' && string[i] <= '9'){
            value[last_sym++] = string[i];
        }
    }
    if (last_sym == 0) return 0;
    value[last_sym] = '\0';
    return atoi(value);
} 
ConfigStatus GetConfig(Config* cnf)
{
    char string[51];
    FILE* f = fopen("config.txt", "r");
    if (f == NULL){
        f = fopen("config.txt", "w");
        if (f != NULL) {
            fclose(f);}
        return CONFIG_ERR_FILE_NOT_FOUND;
    }
    while (fgets(string, 51, f){
            sscanf(string, "delay = %d", &cnf->delay);
            sscanf(string, "max_memory = %d", &cnf->max_memory);
            sscanf(string, "core_numbers = %d", &cnf->core_numbers);
            sscanf(string, "core_frequency = %d", &cnf->core_frequency);
            }


