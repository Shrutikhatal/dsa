#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (pq->front == NULL || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;

        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Entity with data: %d and priority: %d enqueued.\n", data, priority);
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    struct Node* temp = pq->front;
    pq->front = pq->front->next;
    printf("Entity with data: %d and priority: %d dequeued.\n", temp->data, temp->priority);
    free(temp);
}

void display(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority queue elements: \n");
    struct Node* temp = pq->front;

    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();

    // Simulating the lift usage
    enqueue(pq, 1, 2);  // Student
    enqueue(pq, 2, 3);  // Staff
    enqueue(pq, 3, 1);  // Guest
    enqueue(pq, 4, 3);  // Staff
    enqueue(pq, 5, 1);  // Guest
    enqueue(pq, 6, 1);  // Guest

    display(pq);

    // Lift operation
    dequeue(pq);  // Guest with highest priority
    dequeue(pq);  // Guest with next highest priority
    dequeue(pq);  // Student

    display(pq);

    // More lift operations
    enqueue(pq, 7, 4);  // Staff with higher priority
    enqueue(pq, 8, 2);  // Student with higher priority

    display(pq);

    // Lift operation
    dequeue(pq);  // Staff with highest priority

    display(pq);

    free(pq);

    return 0;
}
