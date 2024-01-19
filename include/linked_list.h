#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _node Node;
typedef struct _linked_list LinkedList;

Node *createNode(int val);

LinkedList *createLinkedList();
void addFirst(LinkedList *list, int val);
void addLast(LinkedList *list, int val);
void printLinkedList(const LinkedList *list);
bool linkedListIsEmpty(const LinkedList *list);
void removeNode(LinkedList *list, int val);
void removeLinkedList(LinkedList **list);
int sizeLinkedList(const LinkedList *list);
int firstElement(const LinkedList *list);
int lastElement(const LinkedList *list);
int getElement(const LinkedList *list, int index);

#endif
