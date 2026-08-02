#include <stdio.h>
#include <stdlib.h>
char* reverse(const char *str)
{
    struct ListNode {
        char sym;
        struct ListNode* next;
    };
    int i;
    char * res;
    struct ListNode* stack = NULL;
    for (i = 0; str[i]; i ++){
        struct ListNode* tmp = malloc(sizeof(struct ListNode));
        tmp->sym = str[i];
        tmp->next = stack;
        stack = tmp; 
    }
    int a = 0;
    struct ListNode* tmp;
    res = malloc((i + 1) * sizeof(char));
    while (stack != NULL) {
        res[a] = stack->sym;
        a++;
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    res[a] = '\0';
    return res;
}

int main()
{
    char* word = malloc(3 * sizeof(char));
    word[0] = 'H';
    word[1] = 'i';
    word[2] = '\0';
    char * drow = reverse( word);
    printf("%s\n", drow);
    return 0;
}



