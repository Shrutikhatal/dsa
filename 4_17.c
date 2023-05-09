#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        struct Node* temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void simulateGame(int n, int m) {
    struct Node* head = NULL;

    for (int i = 1; i <= n; i++) {
        append(&head, i);
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while (head->next != head) {
        int count = 1;

        while (count != m) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    printf("The soldier who will go out for help: %d\n", head->data);
    free(head);
}

int main() {
    int n, m;

    printf("Enter the number of soldiers: ");
    scanf("%d", &n);

    printf("Enter the value of m: ");
    scanf("%d", &m);

    simulateGame(n, m);

    return 0;
}
