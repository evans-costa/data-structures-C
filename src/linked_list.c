#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _node {
    int val;
    struct _node *next;
} Node;

typedef struct _linked_list {
    Node *begin;
    Node *end;
    int size;
} LinkedList;

Node *createNode(int val) {
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *) calloc(1, sizeof(LinkedList));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

bool linkedListIsEmpty(const LinkedList *list) {
   return (list->size == 0);
} 

void addFirst(LinkedList *list, int val) {
    Node *newNode = createNode(val);
    newNode->next = list->begin;

    if (linkedListIsEmpty(list)) {
        list->end = newNode;
    }
            
    list->begin = newNode;
    list->size++;
}

void addLast(LinkedList *list, int val) {
    Node *newNode = createNode(val);

    if (linkedListIsEmpty(list)) {
       list->begin = list->end = newNode;
    }

    else {
        list->end->next = newNode;
        list->end = list->end->next; 
    }  
    
    list->size++;
}

int sizeLinkedList(const LinkedList *list) {
    return list->size;
}

int firstElement(const LinkedList *list) {
    if (linkedListIsEmpty(list)) {
        fprintf(stderr, "List is empty");
        exit(EXIT_FAILURE);
    }

    return list->begin->val;
}

int lastElement(const LinkedList *list) {
    if (linkedListIsEmpty(list)) {
        fprintf(stderr, "List is empty");
        exit(EXIT_FAILURE);
    }

    return list->end->val;
}

int getElement(const LinkedList *list, int index) {
    if (linkedListIsEmpty(list)) {
        fprintf(stderr, "List is empty");
        exit(EXIT_FAILURE);
    }

	if (index < 0) {
		fprintf(stderr, "Negative index");
		exit(EXIT_FAILURE);
	}
    
    if (index < list->size) {
        int i = 0;
        Node *node = list->begin;

        for (i = 0; i < index; i++) {
            node = node->next;
        }

        return node->val;
    }

    return fprintf(stderr, "Invalid index");
}

void removeNode(LinkedList *list, int val) {
    if (!linkedListIsEmpty(list)) {
        Node *prev = NULL;
        Node *pos = list->begin;
        
        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        if (pos != NULL) {
            if (list->end == pos) {
                list->end = prev;
            }

            if (list->begin == pos) {
                list->begin = list->begin->next;
            }
            else {
                prev->next = pos->next;
            }

            free(pos);
            list->size--;
        }    
    }
}

void removeLinkedList(LinkedList **list) {
    LinkedList *list_ref = *list;

	Node *current = list_ref->begin;
    Node *aux = NULL;

    while(current != NULL) {
        aux = current;
        current = current->next;
        free(aux);
    }

    free(list_ref);

    *list = NULL;
}

void printLinkedList(const LinkedList *list) {
    Node *node = list->begin;

    printf("List -> ");

    while(node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }

    printf("NULL\n");
}
