#include <stdio.h>
#define MAX_SIZE 5

int cqueue[MAX_SIZE], front = -1, rear = -1;

void insertFront(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    cqueue[front] = element;
    printf("Element %d inserted at front\n", element);
}

void insertRear(int element) {
    if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    cqueue[rear] = element;
    printf("Element %d inserted at rear\n", element);
}

void deleteFront() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %d deleted from front\n", cqueue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %d deleted from rear\n", cqueue[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", cqueue[i]);
        }
    } else {
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", cqueue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, element;
    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                  deleteRear();
                  break;
                  case 5:
                  display();
                  break;
                  default:
                  printf("wrong choice");
        }
                  
        }
        return 0;
}

