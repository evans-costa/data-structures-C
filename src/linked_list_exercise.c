#include "linked_list_exercise.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  struct _node *prev;
  struct _node *next;
  int count;
  Product *product;
} Node;

typedef struct _list {
  Node *begin;
  Node *end;
  size_t size;
  int access_qty;
} List;

Product *createProduct(int id, const char *name, float price) {
  Product *product = (Product *)calloc(1, sizeof(Product));
  product->id = id;
  strcpy(product->name, name);
  product->price = price;

  return product;
}

Node *createNode(int id, const char *name, float price) {
  Node *node = (Node *)calloc(1, sizeof(Node));
  node->prev = node->next = NULL;
  node->count = 0;
  node->product = createProduct(id, name, price);

  return node;
}

List *createList() {
  List *list = (List *)calloc(1, sizeof(List));
  list->begin = list->end = NULL;
  list->size = 0;
  list->access_qty = 0;

  return list;
}

bool listIsEmpty(const List *list) { return list->size == 0; }

void addAtEnd(List *list, int id, const char *name, float price) {
  Node *node = createNode(id, name, price);
  node->prev = list->end;

  if (listIsEmpty(list)) {
    list->begin = node;
  } else {
    list->end->next = node;
  }

  list->end = node;
  list->size++;
}

void printProduct(Product *product) {
  printf("%d, %s, %.2f\n", product->id, product->name, product->price);
}

void printList(const List *list) {
  Node *node = list->begin;

  printf("\nList -> ");

  while (node) {
    printf("%d - Access no. %d -> ", node->product->id, node->count);
    node = node->next;
  }
  printf("NULL\n");

  printf("Size of list: %lu\n\n", list->size);
}

void removeProduct(Product **product_ref) {
  free(*product_ref);
  *product_ref = NULL;
}

void removeNode(Node **node_ref) {
  Node *node = *node_ref;
  removeProduct(&node->product);
  free(node);
  *node_ref = NULL;
}

void removeList(List **list_ref) {
  List *list = *list_ref;

  Node *current = list->begin;
  Node *previous = NULL;

  while (current) {
    previous = current;
    current = current->next;
    removeNode(&previous);
  }

  free(list);
  *list_ref = NULL;
}

void rearrangeList(List *list, Node *node) {

  if (list->begin != node) {
    Node *previous = node->prev;

    while (previous != NULL && previous->count <= node->count) {
      node->prev = previous->prev;
      previous->prev = node;
      previous->next = node->next;
      node->next = previous;

      if (node->prev == NULL) {
        list->begin = node;
      } else {
        node->prev->next = node;
      }

      if (previous->next == NULL) {
        list->end = previous;
      } else {
        previous->next->prev = previous;
      }

      previous = node->prev;
    }
  }
}

const Product *accessProductById(List *list, int id) {
  Product *product = NULL;

  if (!listIsEmpty(list)) {
    Node *node = list->begin;
    int cost = 1;

    while (node && node->product->id != id) {
      cost++;
      node = node->next;
    }

    if (node) {
      list->access_qty += cost;
      node->count++;
      product = node->product;
      
      rearrangeList(list, node);
    }
  }

  return product;
}

void printProductIds(const List *list) {
  Node *node = list->begin;

  printf("List = (");
  
  while (node) {
    printf("%d", node->product->id);

    if (node != list->end) {
      printf(", ");
    }

    node = node->next;
  }

  printf(")\n");
  printf("Total cost = %d\n", list->access_qty);
}
