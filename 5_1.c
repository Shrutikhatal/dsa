#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to split linked list into front and back halves
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
    struct Node* slowPtr = source; // pointer to move one node at a time
    struct Node* fastPtr = source->next; // pointer to move two nodes at a time

    // Move fastPtr to the end and slowPtr to the middle of the list
    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    // Split the list into two halves at slowPtr
    *frontRef = source;
    *backRef = slowPtr->next;
    slowPtr->next = NULL;
}

// Function to insert a new node at the beginning of the list
void push(struct Node** headRef, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to print the list
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver function to test above functions
int main()
{
    struct Node* head = NULL;
    struct Node* front = NULL;
    struct Node* back = NULL;

    // Insert elements into linked list
    push(&head, 11);
    push(&head, 7);
    push(&head, 5);
    push(&head, 3);
    push(&head, 2);

    printf("Original list: ");
    printList(head);

    // Split the list into front and back halves
    FrontBackSplit(head, &front, &back);

    printf("Front half: ");
    printList(front);

    printf("Back half: ");
    printList(back);

    return 0;
}
