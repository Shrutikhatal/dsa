#include <stdio.h>
#include <stdlib.h>

// Node definition for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to remove duplicates from sorted singly linked list
void RemoveDuplicates(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Test the implementation
int main() {
    // Create a sorted linked list with duplicates
    struct Node* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(6);
    head->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next = newNode(8);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Remove duplicates
    RemoveDuplicates(head);

    // Print the list after removing duplicates
    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
