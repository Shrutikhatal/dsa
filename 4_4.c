#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    char name[20];
} Passenger;

typedef struct {
    Passenger items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1 && q->front == 0) || (q->front == q->rear + 1);
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Passenger p) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = p;
    printf("%s added to the queue.\n", p.name);
}

void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%s removed from the queue.\n", q->items[q->front].name);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}

void displayFront(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%s is at the front of the queue.\n", q->items[q->front].name);
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue passenger\n");
        printf("2. Dequeue passenger\n");
        printf("3. Display front passenger\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Passenger p;
                printf("Enter passenger name: ");
                scanf("%s", p.name);
                enqueue(&q, p);
                break;
            }
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayFront(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    printf("Number of passengers left in the queue: %d\n", (q.rear - q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE + 1);
    return 0;
}
