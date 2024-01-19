#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct _queue Queue;

Queue *createQueue(long capacity);

void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);

int peekQueue(const Queue *queue);
long sizeQueue(const Queue *queue);

bool isQueueEmpty(const Queue *queue);
bool isQueueFull(const Queue *queue);

void printQueue(const Queue *queue);

void removeQueue(Queue **queue_ref);

#endif 
