#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {
    int *data;
    long capacity;
    int size;
    long begin;
    long end;
} Queue;

Queue *createQueue(long capacity) {
    Queue *queue = (Queue *)calloc(1, sizeof(Queue));

    queue->capacity = capacity;
    queue->data = (int *)calloc(capacity, sizeof(int));
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;

    return queue;
}

bool isQueueEmpty(const Queue *queue) { 
	return queue->size == 0; 
}

bool isQueueFull(const Queue *queue) { 
	return queue->size == queue->capacity; 
}

void enqueue(Queue *queue, int val) {
    if (isQueueFull(queue)) {
    	fprintf(stderr, "Error in enqueue\n");
        fprintf(stderr, "The queue is full!\n");
        exit(EXIT_FAILURE);
    }

    queue->data[queue->end] = val;
    queue->end = (queue->end + 1) % queue->capacity;
	queue->size++;
}

int dequeue(Queue *queue) {
	if (isQueueEmpty(queue)) {
    	fprintf(stderr, "Error in dequeue\n");
        fprintf(stderr, "The queue is empty!\n");
        exit(EXIT_FAILURE);
    }

	int val = queue->data[queue->begin];
	queue->begin = (queue->begin + 1) % queue->capacity;
	queue->size--;

	return val;
}

long sizeQueue(const Queue *queue) { 
	return queue->size; 
}

int peekQueue(const Queue *queue) {
    if (isQueueFull(queue)) {
        fprintf(stderr, "Error in enqueue\n");
        fprintf(stderr, "The queue is full!\n");
        exit(EXIT_FAILURE);
    }

    return queue->data[queue->begin];
}

void printQueue(const Queue *queue) {
	printf("Capacity = %ld\n", queue->capacity);
	printf("Size = %d\n", queue->size);
	printf("Begin of queue = %ld\n", queue->begin);
	printf("End of queue = %ld\n\n", queue->end);

	long i, j;

	for (i = 0, j = queue->begin; i < queue->size; i++, j = (j + 1) % queue->capacity) {
		printf("%d, ", queue->data[j]);
	}

	printf("\n\n");
}

void removeQueue(Queue **queue_ref) {
    Queue *queue = *queue_ref;

    free(queue->data);
    free(queue);

    *queue_ref = NULL;
}
