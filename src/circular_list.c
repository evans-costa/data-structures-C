#include "circular_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _circular_list {
  Node *begin;
  Node *end;
  int size;
} CircularList;

Node *createCircularNode(int val) {
  Node *node = (Node *)calloc(1, sizeof(Node));
  node->val = val;
  node->prev = node;
  node->next = node;

  return node;
}

CircularList *createCircularList() {
  CircularList *list = (CircularList *)calloc(1, sizeof(CircularList));
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;

  return list;
}

void addFirstCircularList(CircularList *list, int val) {
  Node *node = createCircularNode(val);

  if (circularListIsEmpty(list)) {
    list->end = node;
  } else {
    node->next = list->begin;
    list->begin->prev = node;
    node->prev = list->end;
    list->end->next = node;
  }

  list->begin = node;
  list->size++;
}

void addLastCircularList(CircularList *list, int val) {
  Node *node = createCircularNode(val);

  if (circularListIsEmpty(list)) {
    list->begin = node;
  } else {
    list->end->next = node;
    node->prev = list->end;
    list->begin->prev = node;
    node->next = list->begin;
  }

  list->end = node;
  list->size++;
}

void printCircularList(const CircularList *list) {

  if (circularListIsEmpty(list)) {
    printf("List is Empty");
  } else {
    Node *node = list->begin;

    printf("List: ");

    for (int i = 0; i < list->size; i++) {
      printf("%d -> ", node->val);
      node = node->next;
    }

    printf("\nNext value of last element = %d\n", list->end->next->val);
    printf("Previous value of first element = %d\n", list->begin->prev->val);
    printf("Size = %d\n", list->size);
  }
}

void printInvertedCircularList(const CircularList *list) {
  if (circularListIsEmpty(list)) {
    printf("List is Empty");
  } else {
    Node *node = list->end;

    printf("List: ");

    for (int i = 0; i < list->size; i++) {
      printf("%d -> ", node->val);
      node = node->prev;
    }

    printf("\nNext value of last element = %d\n", list->end->next->val);
    printf("Previous value of first element = %d\n", list->begin->prev->val);
    printf("Size = %d\n", list->size);
  }
}

void removeCircularNodeByValue(CircularList *list, int val) {
  if (!circularListIsEmpty(list)) {
    Node *current = list->begin;

    if (list->size == 1) {

      list->begin = list->end = NULL;
    
    } else {

      while (current->val != val) {
        current = current->next;
      }

      if (current == list->begin) {

        list->begin = current->next;
        list->end->next = list->begin;
      
      } else {

        Node *previous = current->prev;
        
        if (current == list->end) {
          list->end = previous;
        }

        previous->next = current->next;
        current->next = previous;
      }

      list->begin->prev = list->end;
    }

    removeCircularNode(&current);
    list->size--;
  }
}

void removeCircularNode(Node **node_ref) {
  Node *node = *node_ref;
  free(node);
  *node_ref = NULL;
}

void removeCircularList(CircularList **list_ref) {
  CircularList *list = *list_ref;
  Node *current = list->begin;
  Node *previous = NULL;

  while (current != list->end) {
    previous = current;
    current = current->next;
    removeCircularNode(&previous);
  }

  removeCircularNode(&current);
  free(list);
  *list_ref = NULL;
}

bool circularListIsEmpty(const CircularList *list) { return list->size == 0; }
