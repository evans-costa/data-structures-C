#include "stacks.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _stack {
  int *data;
  long capacity;
  long top;
} Stack;

Stack *createStack(long capacity) {
  Stack *stack = (Stack*) calloc (1, sizeof(Stack));
  
  stack->capacity = capacity;
  stack->top = -1;
  stack->data = (int*) calloc(stack->capacity, sizeof(int));

  return stack;
}

bool isStackEmpty(const Stack *stack) {
  return stack->top == -1;
}

bool isStackFull(const Stack *stack) {
  return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int val) {
  if (isStackFull(stack)) {
    fprintf(stderr, "Error in 'push'\n");
    fprintf(stderr, "The stack is full!\n");
    exit(EXIT_FAILURE);
  } 

  stack->data[++stack->top] = val;
}

int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    fprintf(stderr, "Error in 'pop'\n");
    fprintf(stderr, "The stack is empty!\n");
    exit(EXIT_FAILURE);
  } 
  
  int val = stack->data[stack->top--];

  return val;
}

int peek(const Stack *stack) {
  if (isStackEmpty(stack)) {
    fprintf(stderr, "Error in 'peek'\n");
    fprintf(stderr, "The stack is empty!\n");
    exit(EXIT_FAILURE);
  } 
  
  return stack->data[stack->top];
}

long size(const Stack *stack) {
  return stack->top + 1;
}

void printStack(const Stack *stack) {
  printf("Capacity: %ld\n", stack->capacity);
  printf("Top of Stack: %d\n", stack->data[stack->top]);

  for (long i = 0; i <= stack->top; i++) {
    printf("%d, ", stack->data[i]);
  }

  puts("");
}

void removeStack(Stack **stack_ref) {
  Stack *stack = *stack_ref;
  
  free(stack->data);
  free(stack);

  *stack_ref = NULL;
}



