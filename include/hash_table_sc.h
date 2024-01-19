#ifndef HASH_TABLE_SC_H
#define HASH_TABLE_SC_H

#include <stddef.h>

typedef struct _nodeTable {
	char *name;
	float grade;
	struct _nodeTable *next;
} NodeTable;


typedef struct _hashTable {
	int size;
	int qty;
	NodeTable **buckets;
} HashTable;

NodeTable **createNodeList(HashTable *table);
HashTable *createHashTableSc(size_t size);
NodeTable *createNodeTable(char *name, float grade);

void insertTableNode(char *name, float grade, HashTable *table);

void deleteTableNode(HashTable *table, char *name);

void freeNode(NodeTable *nodes);
void freeHashTable(HashTable *table);



#endif
