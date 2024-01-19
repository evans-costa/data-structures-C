#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct _student {
	int registration;
	char name[30];
	float number;
} Student;

typedef struct _hash HashTable;

HashTable *createHashTable(int size);
Student *createStudent(int registration, char *name, float number);

void handleCollisionLinearProbing(HashTable *table, int index, Student *student);

void insertElement(HashTable *table, int registration, char *name, float number);

bool searchStudent(HashTable *table, char *name);

void printHashTable(HashTable *table);

void removeHashTable(HashTable *hashTable);

#endif
