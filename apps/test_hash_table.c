#include "hash_table.h"
#include <stdio.h>

int main (void) {
	HashTable *table = createHashTable(127);

	insertElement(table, 1, "Evandro", 8.31);
	insertElement(table, 2, "João", 8.35);
	insertElement(table, 3, "Maria", 4.31);
	insertElement(table, 4, "José", 8.61);
	insertElement(table, 5, "Pedro", 2.09);
	insertElement(table, 6, "Samuel", 3.76);

	printHashTable(table);

	searchStudent(table, "Pedro");
	removeHashTable(table);

	return 0;
}
