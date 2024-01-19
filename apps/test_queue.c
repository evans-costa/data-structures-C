#include "queue.h"

int main() {
	Queue *queue = createQueue(5);

	enqueue(queue, 40);
	enqueue(queue, 20);
	enqueue(queue, 6);

	printQueue(queue);

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	printQueue(queue);

	removeQueue(&queue);

  return 0;
}
