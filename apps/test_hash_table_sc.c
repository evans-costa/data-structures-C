#include "hash_table_sc.h"

int main(void) {
	HashTable *tableSepChain = createHashTableSc(13);

	insertTableNode("Evandro", 9.0 , tableSepChain);
	insertTableNode("Jose", 9.0 , tableSepChain);
	insertTableNode("Maria", 9.0 , tableSepChain);
	insertTableNode("Pedro", 9.0 , tableSepChain);
	insertTableNode("Suellen", 9.0 , tableSepChain); 
	insertTableNode("Natalia", 9.0 , tableSepChain);

	deleteTableNode(tableSepChain, "Pedro");	

	freeHashTable(tableSepChain);	


	return 0;
}
