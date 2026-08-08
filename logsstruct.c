struct log{
    int id;
    char message[128];
    struct log* next;
}

int push_front(struct log** head, int new_id, const char* new_msg)
{
    struct log* tmp = malloc(sizeof(struct log));
    if (tmp == NULL) return -1;

    tmp->id = new_id;
    strncpy(tmp->message, new_msg, sizeof(tmp->message) - 1);
    tmp->message[sizeof(tmp->message) - 1] = '\0';
    tmp->next = *head;
    *head = tmp;
    return 0;
}
int print_logs(struct log* head)
{
    struct log* tmp = head;
    while(tmp != NULL){
        printf("message: %s\n",tmp->message);
        tmp = tmp->next;
    }
    return 0;
}

int pop_oldest(struct log** head)
{
    struct log* tmp = *head;
    if (head == NULL || *head == NULL) return -1;
    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return 0;
    }
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    return 0;
}
int free_logs(struct log** head)
{
    if (head == NULL) return =1;
    while(*head != NULL){
        struct log* tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}


