#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX_SIZE - 1) {
        printf("Error: Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue underflow\n");
        return;
    }
    front++;
}

void replace(int oldItem, int newItem) {
    int i;
    for (i = front; i <= rear; i++) {
        if (queue[i] == oldItem) {
            queue[i] = newItem;
            break;
        }
    }
    if (i > rear) {
        printf("%d not found in queue\n", oldItem);
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("Queue before replacement: ");
    display();

    replace(2, 6);
    replace(7, 8);
    replace(4, 9);

    printf("Queue after replacement: ");
    display();

    return 0;
}
