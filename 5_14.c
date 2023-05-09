#include <stdio.h>
#include <stdlib.h>

/* Linked list node structure */
struct node {
    int data;
    struct node *next;
};

/* Function to insert a node at the beginning of a linked list */
void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to sort a linked list using insertion sort */
void insertionSort(struct node **head_ref) {
    struct node *sorted = NULL;
    struct node *current = *head_ref;

    while (current != NULL) {
        struct node *next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
}

/* Function to print a linked list */
void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    struct node *head = NULL;

    /* Insert elements into linked list */
    push(&head, 6);
    push(&head, 2);
    push(&head, 8);
    push(&head, 3);
    push(&head, 1);

    printf("Unsorted list: ");
    printList(head);

    /* Sort the linked list using insertion sort */
    insertionSort(&head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
