#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

int compare_by_age(const void *a, const void *b)
{
    Person *p1 = (Person*)a;
    Person *p2 = (Person*)b;
    return p1->age - p2->age;
}

int compare_by_age_desc(const void *a, const void *b)
{
    Person *p1 = (Person*)a;
    Person *p2 = (Person*)b;
    return p2->age - p1->age;
}

int compare_by_name(const void *a, const void *b)
{
    Person *p1 = (Person*)a;
    Person *p2 = (Person*)b;
    return strcmp(p1->name, p2->name);
}

void print_people(Person *arr, int n)
{
    for (int i = 0; i < n; i++){
        printf("Name: %s Age: %d\n", arr[i].name, arr[i].age);
    }
}


int main()
{
    Person people[5] = {
    {"Bob", 25},
    {"Ann", 19},
    {"Max", 40},
    {"Zoe", 19},
    {"Kai", 33}
    };
    qsort(people, 5, sizeof(Person), compare_by_age_desc);
    print_people(people, 5);
    return 0;
}
