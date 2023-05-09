#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }

    dq->front = newNode;
    printf("%d inserted at front.\n", data);
}

void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }

    dq->rear = newNode;
    printf("%d inserted at rear.\n", data);
}

void deleteFront(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }

    printf("%d deleted from front.\n", temp->data);
    free(temp);
}

void deleteRear(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }

    printf("%d deleted from rear.\n", temp->data);
    free(temp);
}

void display(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    struct Node* temp = dq->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Deque* dq = createDeque();

    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertRear(dq, 30);

    display(dq);

    deleteFront(dq);
    deleteRear(dq);
    deleteFront(dq);
    deleteRear(dq);

    display(dq);

    deleteFront(dq);

    display(dq);

    return 0;
}
