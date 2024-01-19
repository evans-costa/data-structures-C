#include "double_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
 

typedef struct _node {
    int val;
    struct _node *prev;
    struct _node *next;
} Node;

typedef struct _double_linked_list {
    Node *begin;
    Node *end;
    size_t size;
} DoubleLinkedList;

Node *createNode(int val) {
    Node *node = (Node*) calloc(1, sizeof(Node));

    node->val = val;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

DoubleLinkedList *createDoubleLinkedList() {
    DoubleLinkedList *list = (DoubleLinkedList*) calloc(1, sizeof(DoubleLinkedList));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

bool doubleLinkedListIsEmpty(const DoubleLinkedList *list) {
    return list->size == 0;
}

void addNodeAtBegin(DoubleLinkedList *list, int val) {
    Node *newNode = createNode(val);
    newNode->next = list->begin;

    if (doubleLinkedListIsEmpty(list)) {
        list->end = newNode;
    } else {
        list->begin->prev = newNode;
    }

    list->begin = newNode;
    list->size++;
}

void addNodeAtEnd(DoubleLinkedList *list, int val) {
    Node *newNode = createNode(val);

    if(doubleLinkedListIsEmpty(list)) {
        list->begin = newNode;
    } else {
        list->end->next = newNode;
        newNode->prev = list->end;
    }
    
    list->end = newNode;   
    list->size++;
}

void printDoubleLinkedList(const DoubleLinkedList *list) {
    Node *node = list->begin;
    
    printf("Double Linked List -> ");

    while(node) {
        printf("%d -> ", node->val);
        node = node->next;
    }

    printf("NULL\n");
    printf("Size: %lu\n", list->size);
}

void printReverseDoubleLinkedList(const DoubleLinkedList *list) {
    Node *node = list->end;
    
    printf("Double Linked List Reversed -> ");

    while(node) {
        printf("%d -> ", node->val);
        node = node->prev;
    }

    printf("NULL\n");
    printf("Size: %lu\n", list->size);
}

void removeNode(DoubleLinkedList *list, int val) {
    if (!doubleLinkedListIsEmpty(list)) {
        Node *node = list->begin;

        while(node->val != val) {
            node = node->next;
        }

        if (list->size == 1) {
            list->begin = list->end = NULL;

        } else {
            
            if (node->prev == NULL) {
                list->begin = node->next;
                list->begin->prev = NULL;
            } else if (node->next == NULL) {
                list->end = node->prev;
                list->end->next = NULL;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }

        free(node);
        node = NULL;
        list->size--;
    }
}

void removeDoubleLinkedList(DoubleLinkedList **list_ref) {
    DoubleLinkedList *list = *list_ref;

    Node *node = list->begin;
    Node *aux = NULL;

    while(node) {
        aux = node;
        node = node->next;
        free(aux);
    }

    free(list);
    *list_ref = NULL;
}



