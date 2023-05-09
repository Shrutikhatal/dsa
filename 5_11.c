#include<stdio.h>
#include<stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of a doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to append one doubly linked list to another at the start
void appendAtStart(struct Node** firstList, struct Node** secondList) {
    if (*firstList == NULL) {
        *firstList = *secondList;
        return;
    }

    if (*secondList == NULL) {
        return;
    }

    (*firstList)->prev = (*secondList);
    (*secondList)->next = (*firstList);
    (*secondList) = NULL;
}

// Function to append one doubly linked list to another at the end
void appendAtEnd(struct Node** firstList, struct Node** secondList) {
    if (*firstList == NULL) {
        *firstList = *secondList;
        return;
    }

    if (*secondList == NULL) {
        return;
    }

    struct Node* temp = *firstList;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = *secondList;
    (*secondList)->prev = temp;
    (*secondList) = NULL;
}

// Main function to test the program
int main() {
    struct Node* firstList = NULL;
    struct Node* secondList = NULL;

    // Adding elements to the first linked list
    insertEnd(&firstList, 1);
    insertEnd(&firstList, 2);
    insertEnd(&firstList, 3);
    printf("First list: ");
    display(firstList);

    // Adding elements to the second linked list
    insertEnd(&secondList, 4);
    insertEnd(&secondList, 5);
    insertEnd(&secondList, 6);
    printf("Second list: ");
    display(secondList);

    // Appending the second linked list to the first linked list at the start
    appendAtStart(&firstList, &secondList);
    printf("After appending second list to first list at start: ");
    display(firstList);

    // Adding elements to the second linked list again
    insertEnd(&secondList, 4);
    insertEnd(&secondList, 5);
    insertEnd(&secondList, 6);

    // Appending the second linked list to the first linked list at the end
    appendAtEnd(&firstList, &secondList);
    printf("After appending second list to first list at end: ");
    display(firstList);

    return 0;
}
