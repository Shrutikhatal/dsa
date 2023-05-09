#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to add element to queue
void enqueue(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    newNode->prev = rear;
    rear = newNode;
}

// Function to delete element from queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front->next;
        front->prev = NULL;
        free(temp);
    }
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    Node* temp = front;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    
    dequeue();
    dequeue();
    display();
    
    return 0;
}
