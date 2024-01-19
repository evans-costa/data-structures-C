#include "hash_table.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 127

// loselose Hashing takes the ASCII values of each char,
// sums, and take the remainder of division for table size
size_t loseloseHashCode(char *str) {
    size_t hash = 0;
	int i;

    for (i = 0; str[i]; i++)
        hash += str[i];

    return hash % TABLE_SIZE;
}

typedef struct _hash {
    int qty;
    int size;
    struct _student **items;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *table = (HashTable *)calloc(1, sizeof(HashTable));
    if (table != NULL) {
        table->size = size;
        table->items = (Student **)calloc(table->size, sizeof(Student *));

        if (table->items == NULL) {
            free(table);
            return NULL;
        }

        table->qty = 0;
    }
    return table;
}

Student *createStudent(int registration, char *name, float number) {
    Student *student = (Student *)calloc(1, sizeof(Student));

    student->registration = registration;
    strcpy(student->name, name);
    student->number = number;

    return student;
}

// In Linear probing, we add one if there are a colision in a certain index 
void handleCollisionLinearProbing(HashTable *table, int index,
                                  Student *student) {
    while (table->items[index] != NULL) {
        index++;
    }

    table->items[index] = student;
}

void insertElement(HashTable *table, int registration, char *name,
                   float number) {
    Student *student = createStudent(registration, name, number);

    int index = loseloseHashCode(name);

    Student *currentStudent = table->items[index];

    if (currentStudent == NULL) {
        if (table->qty == table->size) {
            printf("Hash Table is full\n");
            free(student);
            return;
        }
        table->items[index] = student;
        table->qty++;

    } else {
        if (strcmp(currentStudent->name, name) == 0) {
            table->items[index]->registration = student->registration;
            table->items[index]->number = student->number;
            return;
        } else {
            handleCollisionLinearProbing(table, index, student);
            return;
        }
    }
}

bool searchStudent(HashTable *table, char *name) {
    int index = loseloseHashCode(name);

    Student *findStudent = table->items[index];

    if (findStudent != NULL) {
        if (strcmp(findStudent->name, name) == 0) {
            printf("Student %s find!\n", findStudent->name);
            return true;
        }
    }
    return false;
}

void printHashTable(HashTable *table) {
    printf("Hash Table\n-----------------\n");

    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index: %d, Registration: %d, Name: %s, Grade: %.2f\n", i,
                   table->items[i]->registration, table->items[i]->name,
                   table->items[i]->number);
        }
    }

    printf("-----------------\n");
}

void removeHashTable(HashTable *table) {
    if (table != NULL) {
        int i = 0;
        for (i = 0; i < table->size; i++) {
            if (table->items[i] != NULL) {
                free(table->items[i]);
            }
        }
        free(table->items);
        free(table);
    }
}
