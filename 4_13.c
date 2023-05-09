#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue1[SIZE], queue2[SIZE];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void addq(int queue[], int *front, int *rear, int item) {
    if (*rear == SIZE-1) {
        printf("Queue overflow\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = *rear + 1;
    queue[*rear] = item;
}

int delq(int queue[], int *front, int *rear) {
    int item;
    if (*front == -1 || *front > *rear) {
        printf("Queue underflow\n");
        return -1;
    }
    item = queue[*front];
    *front = *front + 1;
    return item;
}

void display(int queue[], int front, int rear) {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    while(1) {
        printf("Enter your choice:\n1. Add to queue 1\n2. Add to queue 2\n3. Delete from queue 1\n4. Delete from queue 2\n5. Display queue 1\n6. Display queue 2\n7. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter item to be added to queue 1: ");
                scanf("%d", &item);
                addq(queue1, &front1, &rear1, item);
                break;
            case 2:
                printf("Enter item to be added to queue 2: ");
                scanf("%d", &item);
                addq(queue2, &front2, &rear2, item);
                break;
            case 3:
                item = delq(queue1, &front1, &rear1);
                if (item != -1) {
                    printf("Deleted item from queue 1: %d\n", item);
                }
                break;
            case 4:
                item = delq(queue2, &front2, &rear2);
                if (item != -1) {
                    printf("Deleted item from queue 2: %d\n", item);
                }
                break;
            case 5:
                display(queue1, front1, rear1);
                break;
            case 6:
                display(queue2, front2, rear2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
