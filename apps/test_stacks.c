#include "stacks.h"

int main() {
  Stack *stack = createStack(5);

  push(stack, 10);
  push(stack, 3);
  push(stack, 4);
  push(stack, 50);
  push(stack, 32);

  peek(stack);
  
  printStack(stack);

  pop(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  pop(stack);

  peek(stack);
}
