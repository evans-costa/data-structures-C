#include "linked_list_exercise.h"

#include <stdio.h>
#include <string.h>

int main() {
  List *list = createList();
  char command[12];

  scanf("%s", command);

  while (strcmp(command, "stop") != 0) {

    if (strcmp(command, "add") == 0) {
      int id;
      char name[64];
      float price;
      scanf("%d %s %f", &id, name, &price);

      addAtEnd(list, id, name, price);

    } else if (strcmp(command, "access") == 0) {
      int id;
      scanf("%d", &id);

      const Product *product = accessProductById(list, id);

      if (product == NULL) {
        printf("Product Id no. %d not found!\n", id);
      } else {
        printf("Id: %d, Product: %s, Price: %.2f\n", product->id, product->name,
               product->price);
      }
    }
    scanf("%s", command);
  } 

  printList(list);
  printProductIds(list);
  removeList(&list);

  return 0;
}
