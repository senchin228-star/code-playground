#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry{
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable{
    Entry **buckets;
    size_t capacity;
    size_t size;
} HashTable;

unsigned long hash_function(const char *str, size_t capacity)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;   // hash * 33 + c
    }
    return hash % capacity;
}

HashTable* ht_create(size_t capacity)
{
    HashTable *HT = malloc(sizeof(HashTable));
    if (HT == NULL) return NULL;
    HT->buckets = calloc(capacity, sizeof(Entry*));
    HT->capacity = capacity;
    HT->size = 0;
    return HT;
}
void ht_insert(HashTable *HT, const char *key, int val)
{
    unsigned long hash = hash_function(key, HT->capacity);

    Entry *cur = HT->buckets[hash];
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            cur->value = val;
            return;
        }
        cur = cur->next;
    }

    Entry *NewEntry = malloc(sizeof(Entry));
    if (NewEntry == NULL) {
        printf("MEMORY ERR");
        return;
    }
    NewEntry->key = strdup(key);
    if (NewEntry->key == NULL) {
        free(NewEntry);
        printf("MEMORY ERR");
        return;
    }
    NewEntry->value = val;
    NewEntry->next = HT->buckets[hash];
    HT->buckets[hash] = NewEntry;
    HT->size++;
}

int ht_get(HashTable *HT, const char *key, int *out_value)
{
    unsigned long hash = hash_function(key, HT->capacity); 

    Entry *cur = HT->buckets[hash];
    while (cur != NULL){
        if (strcmp(cur->key, key) == 0){
            *out_value = cur->value;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
void ht_free(HashTable *HT)
{
    for (size_t i = 0; i < HT->capacity; i++){
        Entry *cur = HT->buckets[i];
        while(cur){
            Entry *tmp = cur;
            free(cur->key);
            cur = cur->next;
            free(tmp);
        }
    }
    free(HT->buckets);
    free(HT);
}

int ht_remove(HashTable *HT, char *key)
{
    unsigned long hash = hash_function(key, HT->capacity);
    
    Entry *cur = HT->buckets[hash];
    Entry *prev = NULL;
    while(cur){
        if (strcmp(cur->key, key) == 0){
            if(prev == NULL){
                HT->buckets[hash] = NULL;
            }
            else{
                prev->next = cur->next;
            }
            free(cur->key);
            free(cur);
            HT->size--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

int main(){}



