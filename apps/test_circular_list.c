#include "circular_list.h"

int main() {
  CircularList *list = createCircularList();

  addLastCircularList(list, 7);
  addLastCircularList(list, 5);
  addLastCircularList(list, 4);
  addLastCircularList(list, 2);
  addLastCircularList(list, 10);

  removeCircularNodeByValue(list, 10);
  printCircularList(list);

  printInvertedCircularList(list);

  return 0;
}
