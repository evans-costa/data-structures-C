#ifndef LINKED_LIST_EXERCISE_H
#define LINKED_LIST_EXERCISE_H

#include <stdbool.h>

typedef struct _product {
  int id;
  char name[64];
  float price;
} Product;

typedef struct _node Node;
typedef struct _list List;

Product *createProduct(int id, const char *name, float price);
Node *createNode(int id, const char *name, float price);
List *createList();

bool listIsEmpty(const List *list);

void addAtEnd(List *list, int id, const char *name, float price);

void removeProduct(Product **product_ref);
void removeNode(Node **node_ref);
void removeList(List **list_ref);

void rearrangeList(List *list, Node *node);
const Product *accessProductById(List *list, int id);

void printProduct(Product *product);
void printList(const List *list);
void printProductIds(const List *list);

#endif
