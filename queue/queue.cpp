#include <cstdlib>
#include <iostream>

struct Queue {
	int front;
	int rear;
	int size;
	int capacity;
	int *array;
};

// Creates a queue of X capacity with a size of 0
struct Queue* CreateQueue(int capacity) {
	struct Queue* queue = (struct Queue*) std::malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)std::malloc(queue->capacity * sizeof(int));
	return queue;
}

// Returns true if the queue is full
bool IsFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// Returns true if the queue is empty
bool IsEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// Add an item to the queue
void Enqueue(struct Queue* queue, int item) {
	if (IsFull(queue)) {
		return;
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size++;
	std::cout << "\n" << item << " added to the queue.";
}

// Returns the item in the front of the queue
int Dequeue(struct Queue* queue) {
	if (IsEmpty(queue)) {
		return INT_MIN;
	}
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}

// Return the front of the queue
int front(struct Queue* queue) {
	if (IsEmpty(queue)) {
		return INT_MIN;
	}
	return queue->array[queue->front];
}

// Return the rear of the queue
int Rear(struct Queue* queue) {
	if (IsEmpty(queue)) {
		return INT_MIN;
	}
	return queue->array[queue->rear];
}

int Size(struct Queue* queue) {
	return queue->size;
}

void Status(struct Queue* queue) {
	std::cout << "\nQueue Status - capacity:" << queue->capacity << " | size:" << queue->size;
	if (IsEmpty(queue)) {
		std::cout << "\nQueue is empty";
	}
	else {
		int index = queue->front;
		std::cout << "\n\t(Front) -> -> -> (Rear)\n\t";
		while (index <= queue->rear) {
			std::cout << "  " << queue->array[index] << " | ";
			index++;
		}
	}
}
int main() {
	struct Queue* queue = CreateQueue(10);
	std::cout << "\nQueue created\n";
	std::cout << std::endl;
	Status(queue);
	std::cout << "\n\nAdding items to the queue ...";
	Enqueue(queue, 5);
	Enqueue(queue, 10);
	Enqueue(queue, 15);
	Enqueue(queue, 20);
	Enqueue(queue, 25);
	std::cout << std::endl;
	Status(queue);

	std::cout << "\n\nThe front of the queue is " << queue->array[queue->front];
	std::cout << "\n\nThe rear of the queue is " << queue->array[queue->rear];

	std::cout << "\n\nDequeueing " << Dequeue(queue);
	std::cout << "\n\nDequeueing " << Dequeue(queue);
	std::cout << std::endl;
	Status(queue);
	std::cout << std::endl;
	system("pause");
	return 0;
}


