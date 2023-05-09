#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* merge(struct Node* list1, struct Node* list2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (head == NULL) {
                head = list1;
                tail = list1;
            }
            else {
                tail->next = list1;
                list1->prev = tail;
                tail = list1;
            }
            list1 = list1->next;
        }
        else {
            if (head == NULL) {
                head = list2;
                tail = list2;
            }
            else {
                tail->next = list2;
                list2->prev = tail;
                tail = list2;
            }
            list2 = list2->next;
        }
    }
    
    if (list1 == NULL) {
        if (head == NULL) {
            head = list2;
        }
        else {
            tail->next = list2;
            list2->prev = tail;
        }
    }
    else {
        if (head == NULL) {
            head = list1;
        }
        else {
            tail->next = list1;
            list1->prev = tail;
        }
    }
    
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    // Add elements to list1
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 1;
    node->prev = NULL;
    node->next = NULL;
    list1 = node;
    
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 3;
    node->prev = list1;
    node->next = NULL;
    list1->next = node;
    
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 5;
    node->prev = list1->next;
    node->next = NULL;
    list1->next->next = node;
    
    // Add elements to list2
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 2;
    node->prev = NULL;
    node->next = NULL;
    list2 = node;
    
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 4;
    node->prev = list2;
    node->next = NULL;
    list2->next = node;
    
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 6;
    node->prev = list2->next;
    node->next = NULL;
    list2->next->next = node;
    
    // Merge and display the two lists
    struct Node* mergedList = merge(list1, list2);
    display(mergedList);
    
    return 0;
}
