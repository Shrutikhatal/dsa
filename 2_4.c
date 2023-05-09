#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Faculty {
    char name[50];
    char department[50];
    char position[50];
    struct Faculty* next;
} Faculty;

Faculty* hash_table[TABLE_SIZE];

int hash(char* key) {
    return atoi(key) % TABLE_SIZE;
}

void insert(char* name, char* department, char* position) {
    Faculty* faculty = (Faculty*) malloc(sizeof(Faculty));
    strcpy(faculty->name, name);
    strcpy(faculty->department, department);
    strcpy(faculty->position, position);
    faculty->next = NULL;

    int index = hash(name);
    if (hash_table[index] == NULL) {
        hash_table[index] = faculty;
    } else {
        Faculty* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = faculty;
    }
}

void search(char* name) {
    int index = hash(name);
    Faculty* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nDepartment: %s\nPosition: %s\n", current->name, current->department, current->position);
            return;
        }
        current = current->next;
    }
    printf("Faculty not found.\n");
}

int main() {
    insert("John Smith", "Computer Science", "Professor");
    insert("Jane Doe", "Mathematics", "Assistant Professor");
    insert("Bob Johnson", "Physics", "Associate Professor");

    search("John Smith");
    search("Jane Doe");
    search("Bob Johnson");
    search("Alice Lee");

    return 0;
}
