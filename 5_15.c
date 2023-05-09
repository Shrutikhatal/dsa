#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to swap two nodes
void swap(struct Node* a, struct Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform Bubble sort on the Doubly Linked List
void bubbleSort(struct Node* head)
{
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to insert a node at the end of the Doubly Linked List
void insertEnd(struct Node** head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the Doubly Linked List
void display(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function for testing the implementation
int main()
{
    struct Node* head = NULL;
    insertEnd(&head, 5);
    insertEnd(&head, 20);
    insertEnd(&head, 4);
    insertEnd(&head, 3);
    insertEnd(&head, 30);

    printf("Original list:\n");
    display(head);

    bubbleSort(head);

    printf("Sorted list:\n");
    display(head);

    return 0;
}
