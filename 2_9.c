#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTY 10

typedef struct Faculty {
    int id;
    char name[50];
    char department[50];
} Faculty;

typedef struct Node {
    Faculty faculty;
    struct Node* next;
} Node;

void insert(Node** hash_table, Faculty faculty, int n) {
    int index = faculty.id % n;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->faculty = faculty;
    new_node->next = NULL;

    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void search(Node** hash_table, int id, int n) {
    int index = id % n;
    Node* current = hash_table[index];
    while (current != NULL) {
        if (current->faculty.id == id) {
            printf("Faculty found!\n");
            printf("ID: %d\nName: %s\nDepartment: %s\n", current->faculty.id, current->faculty.name, current->faculty.department);
            return;
        }
        current = current->next;
    }
    printf("Faculty not found.\n");
}

int main() {
    int n = 7;
    Node** hash_table = (Node**) malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        hash_table[i] = NULL;
    }

    Faculty faculty[MAX_FACULTY] = {
        {101, "John Doe", "Computer Science"},
        {201, "Jane Smith", "Electrical Engineering"},
        {301, "Bob Johnson", "Mechanical Engineering"},
        {102, "Alice Williams", "Mathematics"},
        {202, "Tom Brown", "Physics"},
        {302, "Samantha Lee", "Chemical Engineering"},
        {103, "David Davis", "English"},
        {203, "Emily Wang", "Biology"},
        {303, "James Chen", "Statistics"},
        {104, "Sarah Kim", "History"}
    };

    for (int i = 0; i < MAX_FACULTY; i++) {
        insert(hash_table, faculty[i], n);
    }

    search(hash_table, 201, n); // search for faculty with ID 201
    search(hash_table, 105, n); // search for faculty with ID 105

    for (int i = 0; i < n; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);

    return 0;
}
