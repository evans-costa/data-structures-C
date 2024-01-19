#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>

typedef struct _double_linked_list DoubleLinkedList;
typedef struct _node Node;

Node *createNode(int val);
DoubleLinkedList *createDoubleLinkedList();

void removeDoubleLinkedList(DoubleLinkedList **list_ref);
bool doubleLinkedListIsEmpty(const DoubleLinkedList *list);
void addNodeAtBegin(DoubleLinkedList *list, int val);
void printDoubleLinkedList(const DoubleLinkedList *list);
void printReverseDoubleLinkedList(const DoubleLinkedList *list);
void addNodeAtEnd(DoubleLinkedList *list, int val);
void removeNode(DoubleLinkedList *list, int val);


#endif

