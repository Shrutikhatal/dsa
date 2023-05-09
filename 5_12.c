#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global variable for top of stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    newNode->prev = NULL;
    if (top != NULL) {
        top->prev = newNode;
    }
    top = newNode;
    printf("%d pushed onto the stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d popped from the stack\n", top->data);
    struct Node* temp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(temp);
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements of stack are:\n");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Push elements onto the stack
    push(10);
    push(20);
    push(30);

    // Display the stack
    display();

    // Pop an element from the stack
    pop();

    // Display the stack
    display();

    return 0;
}
