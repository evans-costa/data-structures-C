#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <stdbool.h>

typedef struct _node {
  int val;
  struct _node *prev;
  struct _node *next;
} Node;

typedef struct _circular_list CircularList;

CircularList *createCircularList();
Node *createCircularNode(int val);

void addLastCircularList(CircularList *list, int val);
void addLastCircularList(CircularList *list, int val);

void printCircularList(const CircularList *list);
void printInvertedCircularList(const CircularList *list);

void removeCircularNodeByValue(CircularList *list, int val);
void removeCircularNode(Node **node_ref);
void removeCircularList(CircularList **list_ref);

bool circularListIsEmpty(const CircularList *list);

#endif
