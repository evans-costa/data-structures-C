#ifndef STACKS_H
#define STACKS_H

#include <stddef.h>
#include <stdbool.h>

typedef struct _stack Stack;

Stack *createStack(long capacity);

void push(Stack *stack, int val);
int pop (Stack *stack);
int peek(const Stack *stack);
long size(const Stack *stack);

void printStack(const Stack *stack);

void removeStack(Stack **stack_ref);

bool isStackEmpty(const Stack *stack);
bool isStackFull(const Stack *stack);

#endif
