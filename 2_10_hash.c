#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
    int id;
    char name[50];
    int age;
} Employee;

typedef struct Node {
    Employee emp;
    struct Node* next;
} Node;

typedef struct Table {
    Node* entries[TABLE_SIZE];
} Table;

int hash(int age) {
    int square = age * age;
    int num_digits = 0;
    int temp = square;

    while (temp > 0) {
        num_digits++;
        temp /= 10;
    }

    int mid = (num_digits - 2) / 2;
    int start = square / (int) pow(10, mid);
    int index = start % TABLE_SIZE;

    return index;
}

void init(Table* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
}

void insert(Table* table, Employee emp) {
    int index = hash(emp.age);

    Node* new_node = malloc(sizeof(Node));
    new_node->emp = emp;
    new_node->next = NULL;

    if (table->entries[index] == NULL) {
        table->entries[index] = new_node;
    }
    else {
        Node* curr = table->entries[index];
        while (curr->next != NULL && curr->emp.age != emp.age) {
            curr = curr->next;
        }
        if (curr->emp.age == emp.age) {
            curr->emp = emp;
            free(new_node);
        }
        else {
            curr->next = new_node;
        }
    }
}

void display(Table table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        Node* curr = table.entries[i];
        while (curr != NULL) {
            printf("\t(%d, %s, %d)\n", curr->emp.id, curr->emp.name, curr->emp.age);
            curr = curr->next;
        }
    }
}

void replace(Table* table, Employee emp) {
    int index = hash(emp.age);

    Node* new_node = malloc(sizeof(Node));
    new_node->emp = emp;
    new_node->next = NULL;

    if (table->entries[index] == NULL) {
        printf("Employee not found.\n");
        free(new_node);
    }
    else {
        Node* curr = table->entries[index];
        while (curr != NULL && curr->emp.age != emp.age) {
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Employee not found.\n");
            free(new_node);
        }
        else {
            new_node->next = curr->next;
            *curr = *new_node;
            free(new_node);
        }
    }
}

Employee* search(Table table, int age) {
    int index = hash(age);

    Node* curr = table.entries[index];
    while (curr != NULL && curr->emp.age != age) {
        curr = curr->next;
    }
    if (curr == NULL) {
        return NULL;
    }
    else {
        return &curr->emp;
    }
}

int main() {
    Table table;
    init(&table);

    Employee emp1 = { 1, "John", 25 };
    insert(&table, emp1);
Employee emp2 = { 2, "Alice", 32 };
insert(&table, emp2);

Employee emp3 = { 3, "Bob", 45 };
insert(&table, emp3);

printf("Original table:\n");
display(table);

Employee emp4 = { 2, "Emily", 27 };
replace(&table, emp4);

printf("Table after replacement:\n");
display(table);

int search_age = 25;
Employee* found_emp = search(table, search_age);
if (found_emp == NULL) {
    printf("No employee found with age %d.\n", search_age);
}
else {
    printf("Employee with age %d found: (%d, %s, %d)\n", search_age, found_emp->id, found_emp->name, found_emp->age);
}

search_age = 30;
found_emp = search(table, search_age);
if (found_emp == NULL) {
    printf("No employee found with age %d.\n", search_age);
}
else {
    printf("Employee with age %d found: (%d, %s, %d)\n", search_age, found_emp->id, found_emp->name, found_emp->age);
}

return 0;}
