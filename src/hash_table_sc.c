#include "hash_table_sc.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 13

static size_t loseloseHashCode(char *str) {
    size_t hash = 0;
	int i;

    for (i = 0; str[i]; i++)
        hash += str[i];

    return hash % TABLE_SIZE;
}

NodeTable **createNodeList(HashTable *table) {
	NodeTable **buckets = (NodeTable**) calloc(table->size, sizeof(NodeTable*));
	
	if (buckets == NULL) {
		free(buckets);
		return NULL;
	}

	for (int i = 0; i < table->size; i++) {
		buckets[i] = NULL;
	}

	return buckets;
}

HashTable *createHashTableSc(size_t size) {
	HashTable *tableSeparate = (HashTable*) calloc(1, sizeof(HashTable));
	
	if (tableSeparate == NULL) {
		free(tableSeparate);
		return NULL;
	}

	tableSeparate->size = size;
	tableSeparate->qty = 0;
	tableSeparate->buckets = createNodeList(tableSeparate);
	
	return tableSeparate;
}

NodeTable *createNodeTable(char *name, float grade) {
	NodeTable *node = (NodeTable*) calloc(1, sizeof(NodeTable));
	
	if (node == NULL) {
		free(node);
		return NULL;
	}

	node->name = (char*) calloc(strlen(name) + 1, sizeof(char));
	strcpy(node->name, name);
	node->grade = grade;
	node->next = NULL;

	return node;
}

void insertTableNode(char *name, float grade, HashTable *table) {
	NodeTable *addNode = createNodeTable(name, grade);

	int index = loseloseHashCode(name);

	if (table->buckets[index] == NULL) {
		table->buckets[index] = addNode;
	} else {
		NodeTable *current = table->buckets[index];

		while(current->next != NULL) {
			current = current->next;
		}

		if (strcmp(current->name, name) == 0) {
			current->grade = grade;
		} else {
			current->next = addNode;
		}
	}
	table->qty++;
}

void deleteTableNode(HashTable *table, char *name) {
	size_t index = loseloseHashCode(name);

	if (table->buckets[index] == NULL) {
		return;

	} else {

		if (table->buckets[index]->next == NULL && strcmp(table->buckets[index]->name, name) == 0) {
			free(table->buckets[index]->name);
			free(table->buckets[index]);
			table->buckets[index] = NULL;
		
		} else {

			NodeTable *current = table->buckets[index]; 
			NodeTable *previous = NULL;

			while (current) {

				if (strcmp(current->name, name) == 0) {

					if (previous == NULL) {
						previous = current;
						current = current->next;
						free(previous);
						table->buckets[index]->next = current;
					} else  {
						previous->next = current->next;
						current->next = NULL;
						free(current);
					}
				}
				current = current->next;
				previous = current;
			}
		}
		table->qty--;
	}
}

void freeNodes(NodeTable *node) {
	NodeTable *current = node;
	NodeTable *previous = NULL;

	while(current != NULL) {
		previous = current;
		current = current->next;
		free(previous->name);
		free(previous);
	}
}

void freeHashTable(HashTable *table) {
	NodeTable **buckets = table->buckets;

	for (int i = 0; i < table->size; i++) {
		freeNodes(buckets[i]);
	}

	free(buckets);
	free(table);
}
