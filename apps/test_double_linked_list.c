#include "double_linked_list.h"
#include <stdio.h>

int main() {
    DoubleLinkedList *list = createDoubleLinkedList();

    addNodeAtBegin(list, 2);

    printDoubleLinkedList(list);

    printReverseDoubleLinkedList(list);
    
    removeNode(list, 2);

    printDoubleLinkedList(list);

    return 0;
}
