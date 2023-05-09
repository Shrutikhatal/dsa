#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Student {
    int roll_no;
    int computer_no;
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

typedef struct Table {
    Node* entries[TABLE_SIZE];
} Table;

int hash(int roll_no) {
    return (roll_no % 10) + 1;
}

void insert(Table* table, Student student) {
    int index = hash(student.roll_no) - 1;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = student;
    node->next = table->entries[index];
    table->entries[index] = node;
}

void display(Table table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        Node* current = table.entries[i];
        while (current != NULL) {
            printf("\t%d -> Computer %d\n", current->data.roll_no, current->data.computer_no);
            current = current->next;
        }
    }
}

void allocate_computers(Table* table, Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        insert(table, students[i]);
    }
}

void allocate_new_computers(Table* table, Student students[], int num_students) {
    int i = 0;
    while (i < num_students) {
        int index = hash(students[i].roll_no) - 1;
        if (table->entries[index] == NULL) {
            insert(table, students[i]);
            i++;
        }
        else {
            Node* current = table->entries[index];
            while (current->next != NULL) {
                current = current->next;
            }
            Node* node = (Node*)malloc(sizeof(Node));
            node->data = students[i];
            node->next = NULL;
            current->next = node;
            i++;
        }
    }
}

int main() {
    Student students1[] = {
        { 1, 21 },
        { 2, 22 },
        { 3, 23 },
        { 4, 24 },
        { 5, 25 },
        { 6, 26 },
        { 7, 27 },
        { 8, 28 },
        { 9, 29 },
        { 10, 30 }
    };
    int num_students1 = sizeof(students1) / sizeof(Student);

    Table table;
    for (int i = 0; i < TABLE_SIZE; i++) {
        table.entries[i] = NULL;
    }

    printf("Initial allocation of computers:\n");
    allocate_computers(&table, students1, num_students1);
    display(table);

    Student students2[] = {
        { 11, -1 },
        { 12, -1 },
        { 13, -1 }
    };
    int num_students2 = sizeof(students2) / sizeof(Student);

    printf("\nNew allocation of computers:\n");
    allocate_new_computers(&table, students2, num_students2);
    display(table);

    return 0;
}

