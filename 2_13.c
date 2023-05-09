#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTY 5
#define HASH_SIZE 7

typedef struct Faculty {
    int id;
    char name[50];
} Faculty;

typedef struct Node {
    Faculty faculty;
    struct Node* next;
} Node;

int hash_divide(int key, int size) {
    return key % size;
}

void insert(Node* hash_table, Faculty faculty, int size) {
    int index = hash_divide(faculty.id, size);
    Node* current = &hash_table[index];
    while (current->next != NULL && current->faculty.id != faculty.id) {
        current = current->next;
    }
    if (current->faculty.id == faculty.id) {
        printf("Faculty with id %d already exists, replacing...\n", faculty.id);
        current->faculty = faculty;
    } else {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->faculty = faculty;
        new_node->next = NULL;
        current->next = new_node;
        printf("Faculty with id %d inserted at index %d\n", faculty.id, index);
    }
}

void search(Node* hash_table, int key, int size) {
    int index = hash_divide(key, size);
    Node* current = &hash_table[index];
    while (current != NULL) {
        if (current->faculty.id == key) {
            printf("Faculty with id %d found at index %d.\n", key, index);
            printf("Name: %s\n", current->faculty.name);
            return;
        }
        current = current->next;
    }
    printf("Faculty with id %d not found.\n", key);
}

void print(Node* hash_table, int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        Node* current = &hash_table[i];
        while (current != NULL) {
            printf("%d (%s) -> ", current->faculty.id, current->faculty.name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* hash_table = (Node*) malloc(HASH_SIZE * sizeof(Node));
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i].faculty.id = -1;
        hash_table[i].next = NULL;
    }

    Faculty faculties[MAX_FACULTY] = {
        {101, "John Doe"},
        {201, "Jane Smith"},
        {102, "Mike Johnson"},
        {301, "Sarah Lee"},
        {401, "David Kim"}
    };

    for (int i = 0; i < MAX_FACULTY; i++) {
        insert(hash_table, faculties[i], HASH_SIZE);
    }

    printf("\n");
    print(hash_table, HASH_SIZE);

    printf("\nSearching for faculty with id 102:\n");
    search(hash_table, 102, HASH_SIZE);

    printf("\nSearching for faculty with id 501:\n");
    search(hash_table, 501, HASH_SIZE);

    return 0;
}

