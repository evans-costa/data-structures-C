#include "linked_list.h"
#include <stdio.h>

int main() {
    LinkedList *list = createLinkedList();

    addFirst(list, 5);
    addFirst(list, 4);
    addFirst(list, 2);
    addFirst(list, 10);
    addLast(list, 42);

    printLinkedList(list);

    printf("First element = %d\n", firstElement(list));
    printf("Last element = %d\n", lastElement(list));
    printf("Element at index = %d\n", getElement(list, 3)); 

    printf("Size: %d\n", sizeLinkedList(list));
    (list == NULL) ? printf("List is empty!\n") : printf("List has elements\n");    
   
    removeLinkedList(&list);
    (list == NULL) ? printf("List is empty!\n") : printf("List has elements\n");    
   

    return 0;
}
